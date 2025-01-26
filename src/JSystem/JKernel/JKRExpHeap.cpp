// modifications originally by https://github.com/Mr-Brocoli
#include "Dolphin/os.h"
#include "JSystem/JSupport.h"
#include "JSystem/JUtility/JUTConsole.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "types.h"

#include "JSystem/JUtility/JUTException.h"

#define SAFETY

// #define IS_IT_IN 0x800000
static u8* isItIn = nullptr;

/**
 * @note Address: 0x8001FE48
 * @note Size: 0x80
 */
JKRExpHeap* JKRExpHeap::createRoot(int maxHeaps, bool errorFlag)
{
	JKRExpHeap* heap = nullptr;

	// Check if root heap already exists
	if (!sRootHeap) {
		void* memory;
		u32 memorySize;

		// Initialize the arena with the given maxHeaps
		initArena((char**)&memory, &memorySize, maxHeaps);

		size_t bitmapSize = 0;
		if (false) {
			// Align memory to the next 16-byte boundary
			isItIn = (u8*)((u32)memory + 0xF & ~0xF);
			// Adjust memory for bitmap space (1/64th of total memory size)
			bitmapSize = memorySize / 32;
		}

		memory = (void*)((char*)memory + bitmapSize);
		memorySize -= bitmapSize;
		for (int i = 0; i != bitmapSize; i++) {
			*(char*)((int)memory + i) = 0;
		}

		// Align memory and size to 16-byte boundaries
		memory     = (void*)((u32)memory + 0xF & ~0xF);
		memorySize = memorySize & ~0xF;

		// Calculate the starting address for the heap and aligned heap size
		u8* start       = (u8*)memory + ((sizeof(JKRExpHeap) + 0xF) & ~0xF);
		u32 alignedSize = memorySize - ((sizeof(JKRExpHeap) + 0xF) & ~0xF);

		// Create the heap in the aligned memory space
		heap = new (memory) JKRExpHeap(start, alignedSize, nullptr, errorFlag);

		// Set the root heap
		sRootHeap = heap;
	}

	// Mark the root heap as initialized
	heap->_6E = true;
	return heap;
}

/**
 * @note Address: 0x8001FEC8
 * @note Size: 0xE4
 */
JKRExpHeap* JKRExpHeap::create(u32 size, JKRHeap* parent, bool errorFlag)
{
	JKRExpHeap* newHeap;
	if (!parent) {
		parent = sRootHeap;
	}

	if (size == 0xffffffff) {
		size = parent->getMaxAllocatableSize(0x10);
	}

	u32 alignedSize = ALIGN_PREV(size, 0x10);
	u32 expHeapSize = ALIGN_NEXT(sizeof(JKRExpHeap), 0x10);
	// if (alignedSize < 0xa0)
	//	return nullptr;

	u8* memory  = (u8*)JKRAllocFromHeap(parent, alignedSize, 0x10);
	u8* dataPtr = memory + expHeapSize;
	if (!memory) {
		return nullptr;
	}
	newHeap = new (memory) JKRExpHeap(dataPtr, alignedSize - expHeapSize, parent, errorFlag);
	if (newHeap == nullptr) {
		JKRFree(memory);
		return nullptr;
	};
	newHeap->_6E = false;

	return newHeap;
}

/**
 * @note Address: 0x8001FFAC
 * @note Size: 0x84
 */
void JKRExpHeap::do_destroy()
{
	if (!_6E) {
		JKRHeap* heap = mTree.getParent()->getObject();
		if (heap) {
			this->~JKRExpHeap();
			JKRFreeToHeap(heap, this);
		}
	} else {
		this->~JKRExpHeap();
	}
}

/**
 * @note Address: 0x80020030
 * @note Size: 0x98
 * __ct
 */
JKRExpHeap::JKRExpHeap(void* p1, u32 p2, JKRHeap* p3, bool p4)
    : JKRHeap(p1, p2, p3, p4)
{
	mCurrentAllocMode       = 0;
	mCurrentGroupID         = 0xFF;
	mFree                   = (void*)((int)p1 + 4);
	*(int*)((int)mFree - 4) = p2;
	*(int*)mFree            = 0;
	mSizeCheck              = -1;
}

/**
 * @note Address: 0x800200C8
 * @note Size: 0x68
 */
JKRExpHeap::~JKRExpHeap() { dispose(); }

int getBruhSize(void* mem)
{
	int* bruh = (int*)((int)mem - 4);
	if (*bruh < 0) {
		bruh += *bruh;
	}
	return *bruh - 4; // the -4 is because the bruh itself takes up 4 bytes
}

int* getBruh(void* mem)
{

	int* bruh = (int*)((int)mem - 4); /* bruh offset (obviously...) */
	if (*bruh < 0) {
		bruh += *bruh;
	}
	return bruh;
}

void mergeBruh(JKRExpHeap* h, void* mem)
{

	/* If the bruh below us is free, take em up to town*/

onetwobucklemyshoe:

	int* nextBruh = getBruh(mem);
	nextBruh += (*nextBruh / 4);

	void* sus  = h->mFree;
	void* prev = nullptr;
	while (sus) {
		int* x = getBruh(sus);
		if (x == nextBruh) {
			if (prev) {
				*(void**)prev = *(void**)sus;
			} else {
				h->mFree = *(void**)sus;
			}
			*getBruh(mem) += *x;
			break;
		}
		prev = sus;
		sus  = *(void**)sus;
	}

	/*Start the process over with whoever's behind us, if anyone*/
	sus = h->mFree;
	while (sus) {
		int* prevBruh = getBruh(sus);
		prevBruh += (*prevBruh / 4);
		if (prevBruh == getBruh(mem)) {
			mem  = sus;
			prev = nullptr;
			goto onetwobucklemyshoe;
		}
		sus = *(void**)sus;
	}
}

void sizeCheck(JKRExpHeap* h)
{
	// Size check is disabled...
	if (h->mSizeCheck == -1) {
		return;
	}

	int sizema = h->do_getTotalFreeSize();
	if (h->mSizeCheck != sizema) {
		OSPanic("Sizema != sizeCheck", 69, "BRUH");
		PPCHalt();
	}
}

void sizeSet(JKRExpHeap* h)
{
	// h->mSizeCheck = h->do_getTotalFreeSize();
}

/**
 * @note Address: 0x80020130
 * @note Size: 0x11C
 * TODO: Needs JUTWarningConsole_f, probably changes to conditions
 */
void* JKRExpHeap::do_alloc(u32 byteCount, int align)
{

	lock();
	/* Apparently it's sometimes 0 lol */
	if (align < 0)
		align = -align;

	if (align < 4)
		align = 0x4;

	if (byteCount < 4)
		byteCount = 4;

	byteCount += 4; // SUS
	int weNeed = ALIGN_NEXT(byteCount, 4);

	void* mem = nullptr;

	/* Get most closest to our size node... */
	int bestFit    = 0x7FFFFFFF; // int max
	void* sus      = mFree;
	void* prevBest = nullptr;
	void* prevSus  = nullptr;
	while (sus) {
		int* x = getBruh(sus);
		int y  = ALIGN_NEXT((int)x + 4, align) - (int)x - 4;

		if (*x >= (weNeed + y) && *x <= bestFit) {
			bestFit  = *x;
			mem      = sus;
			prevBest = prevSus;
		}
		prevSus = sus;
		sus     = *(void**)sus;
	}

	/* If we found our 'closest', unlink it from mFree */
	if (mem) {
		if (prevBest == nullptr) {
			mFree = *(void**)mem;
		} else {
			*(void**)prevBest = *(void**)mem;
		}

		int* trueBruh = getBruh(mem);
		mem           = (void*)ALIGN_NEXT((int)trueBruh + 4, align);
		int* bruh     = (int*)((int)mem - 4);
		*bruh         = -(((int)bruh - (int)trueBruh) / 4);
		weNeed -= *bruh * 4;

		*trueBruh = weNeed;

		if ((bestFit - weNeed) >= 32) {
			trueBruh[weNeed / 4]     = bestFit - weNeed;
			trueBruh[weNeed / 4 + 1] = (int)mFree;
			mFree                    = (void*)&trueBruh[weNeed / 4 + 1];
		} else {
			// We take up this much memory now...
			*trueBruh += (bestFit - weNeed);
		}

		if (isItIn) {
			u32 offset = (u32)mem - (u32)sRootHeap->mStartAddress;

			// Calculate the byte index and bit index
			u32 byteIndex = offset / 32;
			u32 bitIndex  = ((offset / 4) % 8);

			// Set the corresponding bit in the bitmap
			isItIn[byteIndex] |= (1 << bitIndex);
		}
	}


	unlock();

	sizeSet(this);

	if (!mem) {
		// OSPanic("NO MEM", 69, "SKBIDIID");
		// PPCHalt();
	}

	return mem;
}

/**
 * @note Address: 0x8002024C
 * @note Size: 0x254
 */
void* JKRExpHeap::allocFromHead(u32 size, int align) { return do_alloc(size, align); }

/**
 * @note Address: 0x800204A0
 * @note Size: 0xE4
 */
void* JKRExpHeap::allocFromHead(u32 size) { return do_alloc(size, 4); }
/**
 * @note Address: 0x80020584
 * @note Size: 0x158
 */
void* JKRExpHeap::allocFromTail(u32 size, int align) { return do_alloc(size, align); }

/**
 * @note Address: 0x800206DC
 * @note Size: 0xE0
 */
void* JKRExpHeap::allocFromTail(u32 size) { return do_alloc(size, 4); }

/**
 * @note Address: 0x800207BC
 * @note Size: 0x74
 */
void JKRExpHeap::do_free(void* p1)
{

	sizeCheck(this);

	lock();


#ifdef SAFETY

	if (p1 < mStartAddress || p1 > mEndAddress) {
		OSReport("BAD FREE: %p outside of bound!\n", p1);
		unlock();
		return;
	}

	// This is so dumb...

	int* b      = (int*)mStartAddress;
	int* myb    = getBruh(p1);
	int* debugb = b;
	while (b >= (int*)mStartAddress && b < (int*)mEndAddress) {
		if (b == myb)
			goto weregood;
		debugb = b;
		b += (*b / 4);
	}

#endif

	OSReport("BAD FREE: %p %p (%p)\n", p1, debugb, myb);
	if ((u32)myb > 0x80000000) {
		OSReport("BAD FREE: bruh %u\n", *myb);
	}
	// PPCHalt();
	return;


	// OSReport("dealloc %p\n", p1);
	// if ((u32)p1 > 0x80000000) {
	// 	OSReport("dealloc *%p\n", *(void**)p1);
	// 	if (*(u32*)p1 > 0x80000000 && *(u32*)p1 < 0x80700000) {
	// 		OSReport("dealloc **%p\n", **(void***)p1);
	// 	}
	// }


	unlock();
	return;

weregood:

	/* Set the p1 to its bruh + 4 now that it doesn't
	* have to be memory aligned, might be faster
	  for later calculations, idk? */
	p1          = (void*)((int)getBruh(p1) + 4);
	*(void**)p1 = mFree;

	// Why squidward, why
	memset((u8*)p1 + 4, 0, getBruhSize(p1) - 4);

	mFree = p1;
	mergeBruh(this, p1);

	unlock();

	sizeSet(this);
}

/**
 * @note Address: 0x80020830
 * @note Size: 0x94
 */
int JKRExpHeap::freeGroup(u8 groupID)
{

	lock();

	OSReport("Free group unsupported!\n");

	unlock();

	return true;
}

/**
 * @note Address: 0x800208C4
 * @note Size: 0x7C
 */
void JKRExpHeap::do_freeAll()
{
	lock();
	JKRHeap::callAllDisposer();
	mFree                   = (void*)((int)mStartAddress + 4);
	*(int*)((int)mFree - 4) = mHeapSize;
	*(int*)mFree            = 0;
	mSizeCheck              = -1;
	unlock();
	sizeSet(this);
}

/**
 * @note Address: 0x80020940
 * @note Size: 0x90
 */
void JKRExpHeap::do_freeTail()
{
	// lock();
	OSPanic("IDK", 69, "IDK");
	// unlock();
}

/**
 * @note Address: 0x800209D0
 * @note Size: 0x4
 */
void JKRExpHeap::do_fillFreeArea() { }

/**
 * @note Address: 0x800209D4
 * @note Size: 0x58
 */
u8 JKRExpHeap::do_changeGroupID(u8 groupID)
{
	lock();

	// if (groupID == 0xfe) {
	//	OSPanic("SKIBIDI BIDEN", 69, "BTHERE");
	//	PPCHalt();
	// }

	u8 oldGroupID   = mCurrentGroupID;
	mCurrentGroupID = groupID;
	unlock();
	return oldGroupID;
}

/**
 * @note Address: 0x80020A2C
 * @note Size: 0x1BC
 * Regswaps
 */
int JKRExpHeap::do_resize(void* ptr, u32 size)
{
	lock();
	int* bruh = getBruh(ptr);
	size += ((int)ptr - (int)bruh);
	int mum  = *bruh - size;
	*bruh    = size;
	int* car = (int*)((int)bruh + size);
	car[0]   = mum;
	car[1]   = (int)mFree;
	mFree    = (void*)&car[1];
	mergeBruh(this, mFree);
	unlock();
	sizeSet(this);
	return mum; // size moment
}

/**
 * @note Address: 0x80020BE8
 * @note Size: 0x88
 */
int JKRExpHeap::do_getSize(void* p1)
{
	lock();
	int size = getBruhSize(p1);
	unlock();
	return size; // hahaha
}

/**
 * Returns the max size of any free block of memory within this heap.
 *
 * @note Address: 0x80020C70
 * @note Size: 0x6C
 */
u32 JKRExpHeap::do_getFreeSize()
{
	lock();
	int maxSize = 0;
	void* sus   = mFree;
	while (sus) {
		int x = getBruhSize(sus);
		if (x > maxSize) {
			maxSize = x;
		}
		sus = *(void**)sus;
	}
	unlock();
	return maxSize;
}

/**
 * Returns the block with the max size of any free block of memory within this heap.
 *
 * @note Address: 0x80020CDC
 * @note Size: 0x74
 */
void* JKRExpHeap::do_getMaxFreeBlock()
{
	lock();
	int maxSize = 0;
	void* max   = nullptr;
	void* sus   = mFree;
	while (sus) {
		int x = getBruhSize(sus);
		if (x > maxSize) {
			max     = sus;
			maxSize = x;
		}
		sus = *(void**)sus;
	}
	unlock();
	return max;
}

/**
 * Returns the total space allocated to all free blocks of memory within this heap.
 *
 * @note Address: 0x80020D50
 * @note Size: 0x64
 */
u32 JKRExpHeap::do_getTotalFreeSize()
{
	lock();
	int freeSize = 0;
	void* sus    = mFree;
	while (sus) {
		freeSize += getBruhSize(sus);
		sus = *(void**)sus;
	}
	unlock();
	return freeSize;
}

/**
 * @note Address: 0x800211B4
 * @note Size: 0x1E0
 */
bool JKRExpHeap::check()
{
	lock();

	unlock();

	return true;
}

/**
 * @note Address: 0x80021394
 * @note Size: 0x1C8
 */
bool JKRExpHeap::dump()
{
	lock();

	unlock();

	return true;
}

/**
 * @note Address: 0x8002155C
 * @note Size: 0x1F8
 */
bool JKRExpHeap::dump_sort()
{
	lock();

	unlock();
	return true;
}

/**
 * @note Address: 0x8002188C
 * @note Size: 0xF4
 */
void JKRExpHeap::state_register(JKRHeap::TState* p, u32 param_1) const
{
	/* getState_(p); // not needed, however TP debug has it
	setState_u32ID_(p, param_1);
	if (param_1 <= 0xff) {
	    setState_uUsedSize_(p, getUsedSize(param_1));
	} else {
	    setState_uUsedSize_(p, getUsedSize_((JKRExpHeap*)this));
	}
	u32 checkCode = 0;
	setState_u32CheckCode_(p, checkCode); */
}

/**
 * @note Address: 0x80021980
 * @note Size: 0x30
 */
bool JKRExpHeap::state_compare(const JKRHeap::TState& r1, const JKRHeap::TState& r2) const
{
	bool result = true;
	if (r1.mCheckCode != r2.mCheckCode) {
		result = false;
	}
	if (r1.mUsedSize != r2.mUsedSize) {
		result = false;
	}
	return true;
}
