#include "JSystem/JKernel/JKRDvdRipper.h"
#include "Dolphin/dvd.h"
#include "Dolphin/os.h"
#include "Dolphin/stl.h"
#include "Dolphin/vi.h"
#include "JSystem/JKernel/JKRAram.h"
#include "JSystem/JKernel/JKRDecomp.h"
#include "Drought/Encryption.h"
#include "JSystem/JKernel/JKRFile.h"
#include "types.h"

static u8* firstSrcData();
static u8* nextSrcData(u8* p1);
static int decompSZS_subroutine(u8*, u8*);

static u8* szpBuf;
static u8* szpEnd;
static u8* refBuf;
static u8* refEnd;
static u8* refCurrent;
static u32 srcOffset;
static u32 transLeft;
static u8* srcLimit;
static JKRDvdFile* srcFile;
static u32 fileOffset;
static u32 readCount;
static u32 maxDest;
static bool isInitMutex;
static u32* tsPtr;
static u32 tsArea;

JSUList<JKRDMCommand> JKRDvdRipper::sDvdAsyncList;
static OSMutex decompMutex;

bool JKRDvdRipper::errorRetry    = true;
int JKRDvdRipper::sSZSBufferSize = 0x400;

/*
 * --INFO--
 * Address:	8001F188
 * Size:	0000B4
 */
void* JKRDvdRipper::loadToMainRAM(const char* path, u8* p2, JKRExpandSwitch expSwitch, u32 p4, JKRHeap* heap, EAllocDirection allocDir,
                                  u32 p7, int* p8, u32* p9)
{
	JKRDvdFile file;
	if (!file.open(path)) {
		return nullptr;
	}
	return loadToMainRAM(&file, p2, expSwitch, p4, heap, allocDir, p7, p8, p9);
}

/*
 * --INFO--
 * Address:	8001F23C
 * Size:	0000B4
 */
void* JKRDvdRipper::loadToMainRAM(long inode, u8* p2, JKRExpandSwitch expSwitch, u32 p4, JKRHeap* heap, EAllocDirection allocDir, u32 p7,
                                  int* p8, u32* p9)
{
	JKRDvdFile file;
	if (!file.open(inode)) {
		return nullptr;
	}
	return loadToMainRAM(&file, p2, expSwitch, p4, heap, allocDir, p7, p8, p9);
}

/*
 * --INFO--
 * Address:	8001F2F0
 * Size:	0004AC
 * loadToMainRAM__12JKRDvdRipperFP10JKRDvdFilePUc15JKRExpandSwitchUlP7JKRHeapQ212JKRDvdRipper15EAllocDirectionUlPiPUl
 */
void* JKRDvdRipper::loadToMainRAM(JKRDvdFile* jkrDvdFile, u8* file, JKRExpandSwitch expandSwitch, u32 fileSize, JKRHeap* heap,
                                  EAllocDirection allocDirection, u32 startOffset, int* fileCompression, u32* newSize)
{
	bool hasAllocated          = false;
	JKRCompression compression = COMPRESSION_None;
	u32 expandSize;
	u8* mem             = nullptr;
	s32 fileSizeAligned = ALIGN_NEXT(jkrDvdFile->getFileSize(), 32);

	if (expandSwitch == Switch_1) {
		u8 buffer[0x40];
		u8* bufPtr = (u8*)ALIGN_NEXT((u32)buffer, 32);
		while (true) {
			int readBytes = DVDReadPrio(jkrDvdFile->getFileInfo(), bufPtr, 0x20, 0, 2);
			if (readBytes >= 0) {
				break;
			}

			if (readBytes == -3 || !errorRetry) {
				return nullptr;
			}

			VIWaitForRetrace();
		}

		DCInvalidateRange(bufPtr, 0x20);

		compression = JKRCheckCompressed(bufPtr);
		expandSize  = JKRDecompExpandSize(bufPtr);
	}

	if (fileCompression) {
		*fileCompression = (int)compression;
	}

	if (expandSwitch == Switch_1 && compression != COMPRESSION_None) {
		if (fileSize != 0 && expandSize > fileSize) {
			expandSize = fileSize;
		}

		if (!file) {
			file         = (u8*)JKRAllocFromHeap(heap, expandSize, allocDirection == ALLOC_DIR_TOP ? 32 : -32);
			hasAllocated = true;
		}

		if (!file) {
			return nullptr;
		}

		if (compression == COMPRESSION_YAY0) {
			mem = (u8*)JKRAllocFromHeap((heap), fileSizeAligned, 32);
			if (!mem) {
				if (hasAllocated == true) {
					JKRFree(file);
					return nullptr;
				}
			}
		}

	} else {
		if (!file) {
			u32 size = fileSizeAligned - startOffset;
			if ((fileSize != 0) && (size > fileSize))
				size = fileSize;

			file         = (u8*)JKRAllocFromHeap(heap, size, allocDirection == ALLOC_DIR_TOP ? 32 : -32);
			hasAllocated = true;
		}
		if (!file)
			return nullptr;
	}

	if (compression == COMPRESSION_None) {
		JKRCompression compression2 = COMPRESSION_None; // maybe for a sub archive?

		if (startOffset != 0) {
			u8 buffer[0x40];
			u8* bufPtr = (u8*)ALIGN_NEXT((u32)buffer, 32);
			while (true) {
				int readBytes = DVDReadPrio(jkrDvdFile->getFileInfo(), bufPtr, 32, (s32)startOffset, 2);
				if (readBytes >= 0) {
					break;
				}

				if (readBytes == -3 || !errorRetry) {
					if (hasAllocated == true) {
						JKRFree(file);
					}

					return nullptr;
				}

				VIWaitForRetrace();
			}

			DCInvalidateRange(bufPtr, 32);
			compression2 = JKRCheckCompressed(bufPtr);
		}

		if ((compression2 == COMPRESSION_None || expandSwitch == Switch_2) || expandSwitch == Switch_0) {
			s32 size = fileSizeAligned - startOffset;
			if (fileSize != 0 && fileSize < size) {
				size = fileSize; // probably a ternary
			}

			while (true) {
				int readBytes = DVDReadPrio(jkrDvdFile->getFileInfo(), file, size, (s32)startOffset, 2);
				if (readBytes >= 0) {
					break;
				}

				if (readBytes == -3 || !errorRetry) {
					if (hasAllocated == true) {
						JKRFree(file);
					}

					return nullptr;
				}

				VIWaitForRetrace();
			}

			bool b;
			void* fileNew = Drought::DecryptFile(file, b);

			if (b) {
				DCInvalidateRange(file, 32);
				size -= 32;
			}

			if (newSize) {
				*newSize = size;
			}
			return fileNew;

		} else if (compression2 == COMPRESSION_YAZ0) {
			JKRDecompressFromDVD(jkrDvdFile, file, fileSizeAligned, fileSize, 0, startOffset, newSize);

		} else {
			OSErrorLine(322, "Sorry, not prepared for SZP resource\n");
		}

		return file;

	} else if (compression == COMPRESSION_YAY0) {
		if (startOffset != 0) {
			OSErrorLine(332, ":::Not support SZP with offset read");
		}

		while (true) {
			int readBytes = DVDReadPrio(jkrDvdFile->getFileInfo(), mem, fileSizeAligned, 0, 2);
			if (readBytes >= 0) {
				break;
			}

			if (readBytes == -3 || !errorRetry) {
				if (hasAllocated == true) {
					JKRFree(file);
				}

				JKRFree(mem);
				return nullptr;
			}

			VIWaitForRetrace();
		}

		DCInvalidateRange(mem, fileSizeAligned);
		JKRDecompress(mem, file, expandSize, startOffset);
		JKRFree(mem);
		if (newSize) {
			*newSize = expandSize;
		}

		return file;

	} else if (compression == COMPRESSION_YAZ0) {
		if (JKRDecompressFromDVD(jkrDvdFile, file, fileSizeAligned, expandSize, startOffset, 0, newSize) != (u32)0) {
			if (hasAllocated) {
				JKRFree(file);
			}
			file = nullptr;
		}
		return file;

	} else if (hasAllocated) {
		JKRFree(file);
		file = nullptr;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	8001F79C
 * Size:	000174
 */
int JKRDecompressFromDVD(JKRDvdFile* file, void* p2, u32 p3, u32 inMaxDest, u32 inFileOffset, u32 inSrcOffset, u32* inTsPtr)
{
	int interrupts = OSDisableInterrupts();
	if (!isInitMutex) {
		OSInitMutex(&decompMutex);
		isInitMutex = true;
	}
	OSRestoreInterrupts(interrupts);

	OSLockMutex(&decompMutex);
	int bufSize = JKRDvdRipper::getSZSBufferSize();
	szpBuf      = (u8*)JKRAllocFromSysHeap(bufSize, -0x20);
	szpEnd      = szpBuf + bufSize;

	if (inFileOffset) {
		refBuf     = (u8*)JKRAllocFromSysHeap(0x1120, -4);
		refEnd     = refBuf + 0x1120;
		refCurrent = refBuf;

	} else {
		refBuf = nullptr;
	}

	srcFile    = file;
	srcOffset  = inSrcOffset;
	transLeft  = p3 - inSrcOffset;
	fileOffset = inFileOffset;
	readCount  = 0;
	maxDest    = inMaxDest;

	if (!inTsPtr) {
		tsPtr = &tsArea;
	} else {
		tsPtr = inTsPtr;
	}

	*tsPtr     = 0;
	u8* data   = firstSrcData();
	u32 result = (data) ? decompSZS_subroutine(data, (u8*)p2) : -1;

	JKRFree(szpBuf);
	if (refBuf) {
		JKRFree(refBuf);
	}

	DCStoreRangeNoSync(p2, *tsPtr);
	OSUnlockMutex(&decompMutex);

	return result;
}

/*
 * --INFO--
 * Address:	8001F910
 * Size:	0002B8
 */
static int decompSZS_subroutine(u8* src, u8* dest)
{
	u8* endPtr;
	int currCodeByte  = 0;
	int validBitCount = 0;
	u32 ts            = 0;

	if (src[0] != 'Y' || src[1] != 'a' || src[2] != 'z' || src[3] != '0') {
		return -1;
	}

	SYaz0Header* header = (SYaz0Header*)src;
	endPtr              = dest + (header->mLength - fileOffset);

	if (endPtr > dest + maxDest) {
		endPtr = dest + maxDest;
	}

	src += 0x10;
	do {
		if (validBitCount == 0) {
			if ((src > srcLimit) && transLeft) {
				src = nextSrcData(src);
				if (!src) {
					return -1;
				}
			}

			currCodeByte  = *src;
			validBitCount = 8;
			src++;
		}

		if (currCodeByte & 0x80) {
			if (fileOffset != 0) {
				if (readCount >= fileOffset) {
					*dest = *src;
					dest++;
					ts++;

					if (dest == endPtr) {
						break;
					}
				}

				*(refCurrent++) = *src;

				if (refCurrent == refEnd) {
					refCurrent = refBuf;
				}

				src++;

			} else {
				*dest = *src;
				dest++;
				src++;
				ts++;

				if (dest == endPtr) {
					break;
				}
			}

			readCount++;

		} else {
			u32 dist     = src[1] | (src[0] & 0x0f) << 8;
			int numBytes = src[0] >> 4;
			src += 2;
			u8* copySource;
			if (fileOffset) {
				copySource = refCurrent - dist - 1;

				if (copySource < refBuf) {
					copySource += refEnd - refBuf;
				}

			} else {
				copySource = dest - dist - 1;
			}

			if (numBytes == 0) {
				numBytes = *src + 0x12;
				src += 1;
			} else {
				numBytes += 2;
			}

			if (fileOffset) {
				do {
					if (readCount >= fileOffset) {
						*dest = *copySource;
						dest++;
						ts++;

						if (dest == endPtr) {
							break;
						}
					}

					*(refCurrent++) = *copySource;

					if (refCurrent == refEnd) {
						refCurrent = refBuf;
					}

					copySource++;

					if (copySource == refEnd) {
						copySource = refBuf;
					}

					readCount++;
					numBytes--;

				} while (numBytes != 0);

			} else {
				do {
					*dest = *copySource;
					dest++;
					ts++;

					if (dest == endPtr) {
						break;
					}

					readCount++;
					numBytes--;
					copySource++;

				} while (numBytes != 0);
			}
		}

		currCodeByte <<= 1;
		validBitCount--;

	} while (dest < endPtr);

	*tsPtr = ts;
	return 0;
}

/*
 * --INFO--
 * Address:	8001FBC8
 * Size:	0000D4
 */
static u8* firstSrcData()
{
	srcLimit      = szpEnd - 0x19;
	u8* buf       = szpBuf;
	u32 max       = (szpEnd - szpBuf);
	u32 transSize = MIN(transLeft, max);

	while (true) {
		int result = DVDReadPrio(srcFile->getFileInfo(), buf, transSize, srcOffset, 2);
		if (0 <= result) {
			break;
		}
		if (result == -3 || !JKRDvdRipper::isErrorRetry()) {
			return nullptr;
		}
		VIWaitForRetrace();
	}

	DCInvalidateRange(buf, transSize);
	srcOffset += transSize;
	transLeft -= transSize;
	return buf;
}

/*
 * --INFO--
 * Address:	8001FC9C
 * Size:	00010C
 */
static u8* nextSrcData(u8* src)
{
	u32 limit = szpEnd - src;
	u8* buf;
	if (IS_NOT_ALIGNED(limit, 0x20)) {
		buf = szpBuf + 0x20 - (limit & (0x20 - 1));
	} else {
		buf = szpBuf;
	}

	memcpy(buf, src, limit);
	u32 transSize = (u32)(szpEnd - (buf + limit));
	if (transSize > transLeft)
		transSize = transLeft;

	while (true) {
		s32 result = DVDReadPrio(srcFile->getFileInfo(), (buf + limit), transSize, srcOffset, 2);
		if (result >= 0) {
			break;
		}
		// bug: supposed to call isErrorRetry, but didn't
		if (result == -3 || !JKRDvdRipper::isErrorRetry) {
			return nullptr;
		}

		VIWaitForRetrace();
	}

	DCInvalidateRange((buf + limit), transSize);
	srcOffset += transSize;
	transLeft -= transSize;
	if (transLeft == 0) {
		srcLimit = transSize + (buf + limit);
	}

	return buf;
}
