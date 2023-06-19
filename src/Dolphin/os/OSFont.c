#include "Dolphin/os.h"
#include "Dolphin/vi.h"
#include "Dolphin/hw_regs.h"

// outside functions
BOOL __OSReadROM(void* buffer, s32 length, s32 offset);

static OSFontHeader* FontData; // type unsure
static u32* SheetImage;        // type unsure
static u16* WidthTable;        // type unsure
static u16* CharsInSheet;      // type unsure

// clang-format off
static u16 HankakuToCode[] 
	= { 0x20C, 0x20D, 0x20E, 0x20F, 0x210, 0x211, 0x212, 0x213, 0x214, 0x215,
		0x216, 0x217, 0x218, 0x219, 0x21A, 0x21B, 0x21C, 0x21D, 0x21E, 0x21F,
		0x220, 0x221, 0x222, 0x223, 0x224, 0x225, 0x226, 0x227, 0x228, 0x229,
		0x22A, 0x22B, 0x22C, 0x22D, 0x22E, 0x22F, 0x230, 0x231, 0x232, 0x233,
		0x234, 0x235, 0x236, 0x237, 0x238, 0x239, 0x23A, 0x23B, 0x23C, 0x23D,
		0x23E, 0x23F, 0x240, 0x241, 0x242, 0x243, 0x244, 0x245, 0x246, 0x247,
		0x248, 0x249, 0x24A, 0x24B, 0x24C, 0x24D, 0x24E, 0x24F, 0x250, 0x251, 
		0x252, 0x253, 0x254, 0x255, 0x256, 0x257, 0x258, 0x259, 0x25A, 0x25B,
		0x25C, 0x25D, 0x25E, 0x25F, 0x260, 0x261, 0x262, 0x263, 0x264, 0x265,
		0x266, 0x267, 0x268, 0x269, 0x26A, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 
		0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 
		0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 
		0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x26B,
		0x26C, 0x26D, 0x26E, 0x26F, 0x270, 0x271, 0x272, 0x273, 0x274, 0x275,
		0x276, 0x277, 0x278, 0x279, 0x27A, 0x27B, 0x27C, 0x27D, 0x27E, 0x27F, 
		0x280, 0x281, 0x282, 0x283, 0x284, 0x285, 0x286, 0x287, 0x288, 0x289, 
		0x28A, 0x28B, 0x28C, 0x28D, 0x28E, 0x28F, 0x290, 0x291, 0x292, 0x293, 
		0x294, 0x295, 0x296, 0x297, 0x298, 0x299, 0x29A, 0x29B, 0x29C, 0x29D, 
		0x29E, 0x29F, 0x2A0, 0x2A1, 0x2A2, 0x2A3, 0x2A4, 0x2A5, 0x2A6, 0x2A7,
		0x2A8, 0x2A9  };

static u16 ZenkakuToCode[] 
	= { 0x000, 0x001, 0x002, 0x003, 0x004, 0x005, 0x006, 0x007, 0x008, 0x009,
		0x00A, 0x00B, 0x00C, 0x00D, 0x00E, 0x00F, 0x010, 0x011, 0x012, 0x013,
		0x014, 0x015, 0x016, 0x017, 0x018, 0x019, 0x01A, 0x01B, 0x01C, 0x01D,
		0x01E, 0x01F, 0x020, 0x021, 0x022, 0x023, 0x024, 0x025, 0x026, 0x027,
		0x028, 0x029, 0x02A, 0x02B, 0x02C, 0x02D, 0x02E, 0x02F, 0x030, 0x031, 
		0x032, 0x033, 0x034, 0x035, 0x036, 0x037, 0x038, 0x039, 0x03A, 0x03B, 
		0x03C, 0x03D, 0x03E, 0x03F, 0x040, 0x041, 0x042, 0x043, 0x044, 0x045,
		0x046, 0x047, 0x048, 0x049, 0x04A, 0x04B, 0x04C, 0x04D, 0x04E, 0x04F,
		0x050, 0x051, 0x052, 0x053, 0x054, 0x055, 0x056, 0x057, 0x058, 0x059,
		0x05A, 0x05B, 0x05C, 0x05D, 0x05E, 0x05F, 0x060, 0x061, 0x062, 0x063,
		0x064, 0x065, 0x066, 0x067, 0x068, 0x069, 0x06A, 0x06B, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x06C,
		0x06D, 0x06E, 0x06F, 0x070, 0x071, 0x072, 0x073, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x074, 0x075, 0x076, 0x077, 0x078,
		0x079, 0x07A, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x07B, 0x07C, 0x07D, 0x07E, 0x07F, 0x080, 0x081,
		0x082, 0x083, 0x084, 0x085, 0x086, 0x087, 0x088, 0x089, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x08A, 0x08B, 0x08C, 0x08D, 0x08E,
		0x08F, 0x090, 0x091, 0x000, 0x000, 0x000, 0x000, 0x092, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x093, 0x094, 0x095, 0x096, 0x097, 0x098, 0x099,
		0x09A, 0x09B, 0x09C, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x09D, 0x09E, 0x09F, 0x0A0, 0x0A1, 0x0A2, 0x0A3, 0x0A4, 0x0A5, 0x0A6,
		0x0A7, 0x0A8, 0x0A9, 0x0AA, 0x0AB, 0x0AC, 0x0AD, 0x0AE, 0x0AF, 0x0B0,
		0x0B1, 0x0B2, 0x0B3, 0x0B4, 0x0B5, 0x0B6, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x0B7, 0x0B8, 0x0B9, 0x0BA, 0x0BB, 0x0BC, 0x0BD, 0x0BE,
		0x0BF, 0x0C0, 0x0C1, 0x0C2, 0x0C3, 0x0C4, 0x0C5, 0x0C6, 0x0C7, 0x0C8,
		0x0C9, 0x0CA, 0x0CB, 0x0CC, 0x0CD, 0x0CE, 0x0CF, 0x0D0, 0x000, 0x000, 
		0x000, 0x000, 0x0D1, 0x0D2, 0x0D3, 0x0D4, 0x0D5, 0x0D6, 0x0D7, 0x0D8,
		0x0D9, 0x0DA, 0x0DB, 0x0DC, 0x0DD, 0x0DE, 0x0DF, 0x0E0, 0x0E1, 0x0E2, 
		0x0E3, 0x0E4, 0x0E5, 0x0E6, 0x0E7, 0x0E8, 0x0E9, 0x0EA, 0x0EB, 0x0EC,
		0x0ED, 0x0EE, 0x0EF, 0x0F0, 0x0F1, 0x0F2, 0x0F3, 0x0F4, 0x0F5, 0x0F6,
		0x0F7, 0x0F8, 0x0F9, 0x0FA, 0x0FB, 0x0FC, 0x0FD, 0x0FE, 0x0FF, 
		0x100, 0x101, 0x102, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 0x109,
		0x10A, 0x10B, 0x10C, 0x10D, 0x10E, 0x10F, 0x110, 0x111, 0x112, 0x113,
		0x114, 0x115, 0x116, 0x117, 0x118, 0x119, 0x11A, 0x11B, 0x11C, 0x11D,
		0x11E, 0x11F, 0x120, 0x121, 0x122, 0x123, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x124, 0x125, 0x126, 
		0x127, 0x128, 0x129, 0x12A, 0x12B, 0x12C, 0x12D, 0x12E, 0x12F, 0x130, 
		0x131, 0x132, 0x133, 0x134, 0x135, 0x136, 0x137, 0x138, 0x139, 0x13A, 
		0x13B, 0x13C, 0x13D, 0x13E, 0x13F, 0x140, 0x141, 0x142, 0x143, 0x144, 
		0x145, 0x146, 0x147, 0x148, 0x149, 0x14A, 0x14B, 0x14C, 0x14D, 0x14E, 
		0x14F, 0x150, 0x151, 0x152, 0x153, 0x154, 0x155, 0x156, 0x157, 0x158, 
		0x159, 0x15A, 0x15B, 0x15C, 0x15D, 0x15E, 0x15F, 0x160, 0x161, 0x162, 
		0x163, 0x164, 0x165, 0x166, 0x167, 0x168, 0x169, 0x16A, 0x16B, 0x16C,
		0x16D, 0x16E, 0x16F, 0x170, 0x171, 0x172, 0x173, 0x174, 0x175, 0x176, 
		0x177, 0x178, 0x179, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x17A, 0x17B, 0x17C, 0x17D, 0x17E, 0x17F, 0x180, 0x181, 0x182, 
		0x183, 0x184, 0x185, 0x186, 0x187, 0x188, 0x189, 0x18A, 0x18B, 0x18C, 
		0x18D, 0x18E, 0x18F, 0x190, 0x191, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x192, 0x193, 0x194, 0x195, 0x196, 0x197, 0x198, 
		0x199, 0x19A, 0x19B, 0x19C, 0x19D, 0x19E, 0x19F, 0x1A0, 0x1A1, 0x1A2,
		0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1A8, 0x1A9, 0x000, 0x000, 0x000,  
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x1AA, 0x1AB, 0x1AC, 0x1AD, 0x1AE, 
		0x1AF, 0x1B0, 0x1B1, 0x1B2, 0x1B3, 0x1B4, 0x1B5, 0x1B6, 0x1B7, 0x1B8, 
		0x1B9, 0x1BA, 0x1BB, 0x1BC, 0x1BD, 0x1BE, 0x1BF, 0x1C0, 0x1C1, 0x1C2, 
		0x1C3, 0x1C4, 0x1C5, 0x1C6, 0x1C7, 0x1C8, 0x1C9, 0x1CA, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x1CB, 0x1CC, 0x1CD, 0x1CE, 0x1CF, 0x1D0, 0x1D1, 
		0x1D2, 0x1D3, 0x1D4, 0x1D5, 0x1D6, 0x1D7, 0x1D8, 0x1D9, 0x1DA, 0x1DB,
		0x1DC, 0x1DD, 0x1DE, 0x1DF, 0x1E0, 0x1E1, 0x1E2, 0x1E3, 0x1E4, 0x1E5, 
		0x1E6, 0x1E7, 0x1E8, 0x1E9, 0x1EA, 0x1EB, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x1EC,
		0x1ED, 0x1EE, 0x1EF, 0x1F0, 0x1F1, 0x1F2, 0x1F3, 0x1F4, 0x1F5, 0x1F6,
		0x1F7, 0x1F8, 0x1F9, 0x1FA, 0x1FB, 0x1FC, 0x1FD, 0x1FE, 0x1FF, 
		0x200, 0x201, 0x202, 0x203, 0x204, 0x205, 0x206, 0x207, 0x208, 0x209,
		0x20A, 0x20B, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x20C, 0x20D, 0x20E, 0x20F, 0x210, 0x211, 0x212, 
		0x213, 0x214, 0x215, 0x216, 0x217, 0x218, 0x219, 0x21A, 0x21B, 0x21C, 
		0x21D, 0x21E, 0x21F, 0x220, 0x221, 0x222, 0x223, 0x224, 0x225, 0x226,
		0x227, 0x228, 0x229, 0x22A, 0x22B, 0x22C, 0x22D, 0x22E, 0x22F, 0x230, 
		0x231, 0x232, 0x233, 0x234, 0x235, 0x236, 0x237, 0x238, 0x239, 0x23A, 
		0x23B, 0x23C, 0x23D, 0x23E, 0x23F, 0x240, 0x241, 0x242, 0x243, 0x244, 
		0x245, 0x246, 0x247, 0x248, 0x249, 0x24A, 0x24B, 0x24C, 0x24D, 0x24E, 
		0x24F, 0x250, 0x251, 0x252, 0x253, 0x254, 0x255, 0x256, 0x257, 0x258, 
		0x259, 0x25A, 0x25B, 0x25C, 0x25D, 0x25E, 0x25F, 0x260, 0x261, 0x262, 
		0x263, 0x264, 0x265, 0x266, 0x267, 0x268, 0x269, 0x26A, 0x26B, 0x26C, 
		0x26D, 0x26E, 0x26F, 0x270, 0x271, 0x272, 0x273, 0x274, 0x275, 0x276, 
		0x277, 0x278, 0x279, 0x27A, 0x27B, 0x27C, 0x27D, 0x27E, 0x27F, 0x280, 
		0x281, 0x282, 0x283, 0x284, 0x285, 0x286, 0x287, 0x288, 0x289, 0x28A, 
		0x28B, 0x28C, 0x28D, 0x28E, 0x28F, 0x290, 0x291, 0x292, 0x293, 0x294,
		0x295, 0x296, 0x297, 0x298, 0x299, 0x29A, 0x29B, 0x29C, 0x29D, 0x29E, 
		0x29F, 0x2A0, 0x2A1, 0x2A2, 0x2A3, 0x2A4, 0x2A5, 0x2A6, 0x2A7, 0x2A8, 
		0x2A9, 0x2AA, 0x2AB, 0x2AC, 0x2AD, 0x2AE, 0x2AF, 0x2B0, 0x2B1, 0x2B2, 
		0x2B3, 0x2B4, 0x2B5, 0x2B6, 0x2B7, 0x2B8, 0x2B9, 0x2BA, 0x2BB, 0x2BC, 
		0x2BD, 0x2BE, 0x2BF, 0x2C0, 0x2C1, 0x2C2, 0x2C3, 0x2C4, 0x2C5, 0x2C6, 
		0x2C7, 0x2C8, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
		0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x2C9, 0x2CA, 0x2CB, 0x2CC, 0x2CD, 0x2CE, 0x2CF, 0x2D0, 0x2D1, 0x2D2,
		0x2D3, 0x2D4, 0x2D5, 0x2D6, 0x2D7, 0x2D8, 0x2D9, 0x2DA, 0x2DB, 0x2DC,
		0x2DD, 0x2DE, 0x2DF, 0x2E0, 0x2E1, 0x2E2, 0x2E3, 0x2E4, 0x2E5, 0x2E6,
		0x000, 0x2E7, 0x2E8, 0x2E9, 0x2EA, 0x2EB, 0x2EC, 0x2ED, 0x2EE, 0x2EF,
		0x2F0, 0x2F1, 0x2F2, 0x2F3, 0x2F4, 0x2F5, 0x2F6, 0x2F7, 0x2F8, 0x2F9,
		0x2FA, 0x2FB, 0x2FC, 0x2FD, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
		0x000, 0x000, 0x2FE, 0x2FF, 
		0x300, 0x301, 0x302, 0x303, 0x304, 0x305, 0x306, 0x307, 0x308, 0x309,
		0x30A, 0x30B, 0x30C, 0x30D, 0x30E, 0x30F, 0x310, 0x311, 0x312, 0x313,
		0x314, 0x315, 0x316, 0x317, 0x318, 0x319, 0x31A, 0x31B, 0x000 };
// clang-format on

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
BOOL IsSjisLeadByte(u8 letter)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
BOOL IsSjisTrailByte(u8 letter) { return (letter >= 0x40 && letter <= 0xFC && letter != 0x7F); }

/*
 * --INFO--
 * Address:	800EDD98
 * Size:	00019C
 */
int GetFontCode(u16 code)
{
	int preCode;
	int lastByte;

	if (OSGetFontEncode() == OS_FONT_ENCODE_SJIS) {
		if (code >= 0x20 && code <= 0xDF) {
			return HankakuToCode[code - 0x20];
		}

		if (code > 0x889E && code <= 0x9872) {
			preCode  = ((code >> 8) - 0x88) * 188;
			lastByte = code & 0xFF;

			if (!IsSjisTrailByte(lastByte)) {
				return 0;
			}

			lastByte -= 0x40;

			if (lastByte >= 0x40) {
				lastByte--;
			}

			return (preCode + lastByte + 0x2BE);
		}

		if (code >= 0x8140 && code < 0x879E) {
			preCode  = ((code >> 8) - 0x81) * 188;
			lastByte = code & 0xFF;

			if (!IsSjisTrailByte(lastByte)) {
				return 0;
			}

			lastByte -= 0x40;

			if (lastByte >= 0x40) {
				lastByte--;
			}

			return ZenkakuToCode[preCode + lastByte];
		}

	} else if (code > 0x20 && code <= 0xFF) {
		return code - 0x20;
	}

	return 0;
}

/*
 * --INFO--
 * Address:	800EDF34
 * Size:	000174
 */
void Decode(u8* in, u8* out)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  addi      r6, r3, 0x10
	  li        r10, 0
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  lwz       r31, 0x4(r3)
	  lwz       r11, 0x8(r3)
	  lwz       r12, 0xC(r3)

	.loc_0x28:
	  cmplwi    r30, 0
	  bne-      .loc_0x3C
	  lwz       r29, 0x0(r6)
	  li        r30, 0x20
	  addi      r6, r6, 0x4

	.loc_0x3C:
	  rlwinm.   r0,r29,0,0,0
	  beq-      .loc_0x60
	  mr        r0, r12
	  lbzx      r5, r3, r0
	  mr        r0, r10
	  addi      r10, r10, 0x1
	  stbx      r5, r4, r0
	  addi      r12, r12, 0x1
	  b         .loc_0x150

	.loc_0x60:
	  add       r7, r3, r11
	  lbz       r5, 0x0(r7)
	  addi      r11, r11, 0x2
	  lbz       r0, 0x1(r7)
	  rlwimi    r0,r5,8,16,23
	  srawi.    r5, r0, 0xC
	  rlwinm    r0,r0,0,20,31
	  sub       r9, r10, r0
	  bne-      .loc_0x98
	  mr        r0, r12
	  lbzx      r5, r3, r0
	  addi      r12, r12, 0x1
	  addi      r0, r5, 0x12
	  b         .loc_0x9C

	.loc_0x98:
	  addi      r0, r5, 0x2

	.loc_0x9C:
	  cmpwi     r0, 0
	  mr        r5, r0
	  add       r7, r4, r10
	  ble-      .loc_0x150
	  rlwinm.   r0,r5,29,3,31
	  mtctr     r0
	  beq-      .loc_0x130

	.loc_0xB8:
	  subi      r8, r9, 0x1
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0
	  addi      r10, r10, 0x8
	  stb       r0, 0x0(r7)
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0x1
	  stb       r0, 0x1(r7)
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0x2
	  stb       r0, 0x2(r7)
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0x3
	  stb       r0, 0x3(r7)
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0x4
	  stb       r0, 0x4(r7)
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0x5
	  stb       r0, 0x5(r7)
	  lbzx      r0, r4, r8
	  addi      r8, r9, 0x6
	  addi      r9, r9, 0x8
	  stb       r0, 0x6(r7)
	  lbzx      r0, r4, r8
	  stb       r0, 0x7(r7)
	  addi      r7, r7, 0x8
	  bdnz+     .loc_0xB8
	  andi.     r5, r5, 0x7
	  beq-      .loc_0x150

	.loc_0x130:
	  mtctr     r5

	.loc_0x134:
	  subi      r8, r9, 0x1
	  lbzx      r0, r4, r8
	  addi      r10, r10, 0x1
	  addi      r9, r9, 0x1
	  stb       r0, 0x0(r7)
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x134

	.loc_0x150:
	  cmpw      r10, r31
	  rlwinm    r29,r29,1,0,30
	  subi      r30, r30, 0x1
	  blt+      .loc_0x28
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
u32 GetFontSize(u8* in)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EE0A8
 * Size:	000058
 */
u16 OSGetFontEncode()
{
	static vu16 fontEncode = OS_FONT_ENCODE_NULL;

	if (fontEncode > 1) {
		switch (__OSTVMode) {
		case VI_NTSC:
			fontEncode = (__VIRegs[VI_DTV_STAT] & 2) ? OS_FONT_ENCODE_SJIS : OS_FONT_ENCODE_ANSI;
			break;

		case VI_PAL:
		case VI_MPAL:
		case VI_DEBUG:
		case VI_DEBUG_PAL:
		case VI_EURGB60:
		default:
			fontEncode = OS_FONT_ENCODE_ANSI;
		}
	}

	return fontEncode;
	/*
	.loc_0x0:
	  lhz       r3, -0x7C90(r13)
	  cmplwi    r3, 0x1
	  blelr-
	  lis       r3, 0x8000
	  lwz       r0, 0xCC(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x24
	  blt-      .loc_0x48
	  b         .loc_0x48

	.loc_0x24:
	  lis       r3, 0xCC00
	  lhz       r0, 0x206E(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x3C
	  li        r0, 0x1
	  b         .loc_0x40

	.loc_0x3C:
	  li        r0, 0

	.loc_0x40:
	  sth       r0, -0x7C90(r13)
	  b         .loc_0x50

	.loc_0x48:
	  li        r0, 0
	  sth       r0, -0x7C90(r13)

	.loc_0x50:
	  lhz       r3, -0x7C90(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE100
 * Size:	00008C
 */
void ReadROM(void* string, int len, int offset)
{
	int inc;
	while (len > 0) {
		if (len <= 0x100) {
			inc = len;
		} else {
			inc = 0x100;
		}

		len -= inc;

		while (!__OSReadROM(string, inc, offset)) {
			;
		}

		offset += inc;
		(u8*)string += inc;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
u32 ReadFont(void* img, u16 encode, void* fontInfo)
{
	SheetImage = fontInfo;
	if (OSGetFontEncode() == encode) {
		ReadROM(img, OS_FONT_ROM_SIZE_SJIS, 0x1AFF00);
	} else {
		ReadROM(img, OS_FONT_ROM_SIZE_ANSI, 0x1FCF00);
	}

	if (((u8*)img)[0] == 'Y' && ((u8*)img)[1] == 'a' && ((u8*)img)[2] == 'y') {
		return ((u32*)img)[1];
	}

	return 0;
}

/*
 * --INFO--
 * Address:	800EE18C
 * Size:	000334
 */
u32 OSLoadFont(void* fontInfo, void* temp)
{
	if (ReadFont(temp, OS_FONT_ENCODE_SJIS, nullptr)) {
		Decode(temp, fontInfo);
		FontData = fontInfo;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x34(r1)
	  addi      r29, r3, 0
	  stw       r0, -0x708C(r13)
	  bl        -0x10C
	  rlwinm    r0,r3,0,16,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x54
	  lis       r4, 0x5
	  lis       r5, 0x1B
	  addi      r3, r30, 0
	  subi      r4, r4, 0x3000
	  subi      r5, r5, 0x100
	  bl        -0xD8
	  b         .loc_0x68

	.loc_0x54:
	  lis       r4, 0x20
	  addi      r3, r30, 0
	  subi      r5, r4, 0x3100
	  li        r4, 0x3000
	  bl        -0xF0

	.loc_0x68:
	  lbz       r0, 0x0(r30)
	  cmplwi    r0, 0x59
	  bne-      .loc_0x94
	  lbz       r0, 0x1(r30)
	  cmplwi    r0, 0x61
	  bne-      .loc_0x94
	  lbz       r0, 0x2(r30)
	  cmplwi    r0, 0x79
	  bne-      .loc_0x94
	  lwz       r31, 0x4(r30)
	  b         .loc_0x98

	.loc_0x94:
	  li        r31, 0

	.loc_0x98:
	  cmplwi    r31, 0
	  beq-      .loc_0x314
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0x300
	  stw       r29, -0x7090(r13)
	  lhz       r4, -0x7C90(r13)
	  lhz       r0, 0x22(r29)
	  cmplwi    r4, 0x1
	  add       r0, r29, r0
	  stw       r0, -0x7088(r13)
	  lhz       r3, 0x1A(r29)
	  lhz       r0, 0x1C(r29)
	  mullw     r0, r3, r0
	  stw       r0, -0x7084(r13)
	  bgt-      .loc_0xDC
	  b         .loc_0x124

	.loc_0xDC:
	  lis       r3, 0x8000
	  lwz       r0, 0xCC(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xF4
	  blt-      .loc_0x118
	  b         .loc_0x118

	.loc_0xF4:
	  lis       r3, 0xCC00
	  lhz       r0, 0x206E(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x10C
	  li        r0, 0x1
	  b         .loc_0x110

	.loc_0x10C:
	  li        r0, 0

	.loc_0x110:
	  sth       r0, -0x7C90(r13)
	  b         .loc_0x120

	.loc_0x118:
	  li        r0, 0
	  sth       r0, -0x7C90(r13)

	.loc_0x120:
	  lhz       r4, -0x7C90(r13)

	.loc_0x124:
	  rlwinm    r0,r4,0,16,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x314
	  lwz       r4, -0x6C10(r2)
	  li        r3, 0x54
	  lwz       r0, -0x6C0C(r2)
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  bl        -0x538
	  lwz       r5, -0x7084(r13)
	  lwz       r12, -0x7090(r13)
	  divw      r10, r3, r5
	  lhz       r6, 0x1C(r1)
	  lhz       r0, 0x1E(r12)
	  lwz       r4, 0x14(r12)
	  lwz       r11, 0x24(r12)
	  mullw     r8, r10, r5
	  lhz       r9, 0x1A(r12)
	  lhz       r5, 0x12(r12)
	  lhz       r7, 0x10(r12)
	  sub       r30, r3, r8
	  divw      r8, r30, r9
	  mullw     r3, r8, r9
	  mullw     r5, r8, r5
	  srawi     r0, r0, 0x3
	  sub       r3, r30, r3
	  addze     r0, r0
	  rlwinm    r0,r0,5,0,26
	  srawi     r9, r0, 0x1
	  mullw     r10, r10, r4
	  mullw     r3, r3, r7
	  addze     r9, r9
	  addi      r0, r5, 0x4
	  srawi     r4, r0, 0x3
	  addze     r4, r4
	  srawi     r8, r3, 0x3
	  addze     r8, r8
	  srawi     r7, r0, 0x3
	  addze     r7, r7
	  rlwinm    r7,r7,3,0,28
	  subc      r7, r0, r7
	  srawi     r0, r3, 0x3
	  addze     r0, r0
	  rlwinm    r0,r0,3,0,28
	  subc      r0, r3, r0
	  srawi     r3, r0, 0x2
	  mullw     r0, r9, r4
	  add       r4, r12, r11
	  rlwinm    r9,r10,31,1,31
	  add       r4, r4, r9
	  add       r9, r4, r0
	  rlwinm    r0,r8,4,0,27
	  add       r9, r9, r0
	  rlwinm    r7,r7,1,0,30
	  add       r9, r9, r7
	  addze     r3, r3
	  add       r9, r9, r3
	  sth       r6, 0x0(r9)
	  addi      r10, r5, 0x5
	  addi      r9, r5, 0x6
	  lwz       r7, -0x7090(r13)
	  addi      r6, r5, 0x7
	  lhz       r5, 0x1E(r1)
	  lhz       r7, 0x1E(r7)
	  srawi     r7, r7, 0x3
	  addze     r7, r7
	  rlwinm    r7,r7,5,0,26
	  srawi     r8, r7, 0x1
	  addze     r8, r8
	  srawi     r7, r10, 0x3
	  addze     r7, r7
	  mullw     r8, r8, r7
	  srawi     r7, r10, 0x3
	  addze     r7, r7
	  rlwinm    r7,r7,3,0,28
	  add       r8, r4, r8
	  subc      r7, r10, r7
	  add       r8, r8, r0
	  rlwinm    r7,r7,1,0,30
	  add       r8, r8, r7
	  add       r8, r8, r3
	  sth       r5, 0x0(r8)
	  lwz       r7, -0x7090(r13)
	  lhz       r5, 0x20(r1)
	  lhz       r7, 0x1E(r7)
	  srawi     r7, r7, 0x3
	  addze     r7, r7
	  rlwinm    r7,r7,5,0,26
	  srawi     r8, r7, 0x1
	  addze     r8, r8
	  srawi     r7, r9, 0x3
	  addze     r7, r7
	  mullw     r8, r8, r7
	  srawi     r7, r9, 0x3
	  addze     r7, r7
	  rlwinm    r7,r7,3,0,28
	  add       r8, r4, r8
	  subc      r7, r9, r7
	  add       r8, r8, r0
	  rlwinm    r7,r7,1,0,30
	  add       r8, r8, r7
	  add       r8, r8, r3
	  sth       r5, 0x0(r8)
	  lwz       r5, -0x7090(r13)
	  lhz       r5, 0x1E(r5)
	  srawi     r5, r5, 0x3
	  addze     r5, r5
	  rlwinm    r5,r5,5,0,26
	  srawi     r7, r5, 0x1
	  addze     r7, r7
	  srawi     r5, r6, 0x3
	  addze     r5, r5
	  mullw     r5, r7, r5
	  add       r7, r4, r5
	  srawi     r5, r6, 0x3
	  lhz       r4, 0x22(r1)
	  addze     r5, r5
	  rlwinm    r5,r5,3,0,28
	  subc      r5, r6, r5
	  add       r7, r7, r0
	  rlwinm    r0,r5,1,0,30
	  add       r7, r7, r0
	  add       r7, r7, r3
	  sth       r4, 0x0(r7)

	.loc_0x314:
	  mr        r3, r31
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE4C0
 * Size:	0003B0
 */
void ExpandFontSheet(OSFontHeader* fontInfo, u8* source, u8* dest)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r6, -0x7090(r13)
	  lhz       r0, 0x18(r6)
	  addi      r5, r6, 0x2C
	  cmplwi    r0, 0
	  bne-      .loc_0x1D8
	  lwz       r0, 0x28(r6)
	  srawi     r6, r0, 0x1
	  addze     r6, r6
	  subi      r0, r6, 0x1
	  mr.       r10, r0
	  rlwinm    r0,r0,1,0,30
	  add       r8, r4, r0
	  addi      r6, r10, 0x1
	  blt-      .loc_0x390
	  rlwinm.   r0,r6,30,2,31
	  mtctr     r0
	  beq-      .loc_0x180

	.loc_0x50:
	  add       r9, r3, r10
	  lbz       r0, 0x0(r9)
	  subi      r10, r10, 0x1
	  rlwinm    r7,r0,26,30,31
	  rlwinm    r0,r0,28,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x0(r9)
	  add       r9, r3, r10
	  subi      r10, r10, 0x1
	  rlwinm    r7,r0,30,30,31
	  rlwinm    r0,r0,0,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x0(r9)
	  rlwinm    r7,r0,26,30,31
	  rlwinm    r0,r0,28,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, -0x2(r8)
	  lbz       r0, 0x0(r9)
	  add       r9, r3, r10
	  subi      r10, r10, 0x1
	  rlwinm    r7,r0,30,30,31
	  rlwinm    r0,r0,0,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, -0x1(r8)
	  lbz       r0, 0x0(r9)
	  rlwinm    r7,r0,26,30,31
	  rlwinm    r0,r0,28,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, -0x4(r8)
	  lbz       r0, 0x0(r9)
	  add       r9, r3, r10
	  subi      r10, r10, 0x1
	  rlwinm    r7,r0,30,30,31
	  rlwinm    r0,r0,0,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, -0x3(r8)
	  lbz       r0, 0x0(r9)
	  rlwinm    r7,r0,26,30,31
	  rlwinm    r0,r0,28,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, -0x6(r8)
	  lbz       r0, 0x0(r9)
	  rlwinm    r7,r0,30,30,31
	  rlwinm    r0,r0,0,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, -0x5(r8)
	  subi      r8, r8, 0x8
	  bdnz+     .loc_0x50
	  andi.     r6, r6, 0x3
	  beq-      .loc_0x390

	.loc_0x180:
	  mtctr     r6

	.loc_0x184:
	  add       r9, r3, r10
	  lbz       r0, 0x0(r9)
	  subi      r10, r10, 0x1
	  rlwinm    r7,r0,26,30,31
	  rlwinm    r0,r0,28,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x0(r9)
	  rlwinm    r7,r0,30,30,31
	  rlwinm    r0,r0,0,30,31
	  lbzx      r7, r5, r7
	  lbzx      r0, r5, r0
	  rlwinm    r0,r0,0,28,31
	  rlwimi    r0,r7,0,24,27
	  stb       r0, 0x1(r8)
	  subi      r8, r8, 0x2
	  bdnz+     .loc_0x184
	  b         .loc_0x390

	.loc_0x1D8:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x390
	  lwz       r0, 0x28(r6)
	  srawi     r6, r0, 0x2
	  addze     r6, r6
	  subic.    r9, r6, 0x1
	  rlwinm    r0,r9,2,0,29
	  add       r7, r4, r0
	  addi      r6, r9, 0x1
	  blt-      .loc_0x390
	  rlwinm.   r0,r6,30,2,31
	  mtctr     r0
	  beq-      .loc_0x33C

	.loc_0x20C:
	  add       r8, r3, r9
	  lbz       r0, 0x0(r8)
	  subi      r9, r9, 0x1
	  rlwinm    r0,r0,26,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x0(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,28,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x1(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,30,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x2(r7)
	  lbz       r0, 0x0(r8)
	  add       r8, r3, r9
	  subi      r9, r9, 0x1
	  rlwinm    r0,r0,0,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x3(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,26,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x4(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,28,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x3(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,30,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x2(r7)
	  lbz       r0, 0x0(r8)
	  add       r8, r3, r9
	  subi      r9, r9, 0x1
	  rlwinm    r0,r0,0,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x1(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,26,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x8(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,28,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x7(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,30,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x6(r7)
	  lbz       r0, 0x0(r8)
	  add       r8, r3, r9
	  subi      r9, r9, 0x1
	  rlwinm    r0,r0,0,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x5(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,26,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0xC(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,28,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0xB(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,30,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0xA(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,30,31
	  lbzx      r0, r5, r0
	  stb       r0, -0x9(r7)
	  subi      r7, r7, 0x10
	  bdnz+     .loc_0x20C
	  andi.     r6, r6, 0x3
	  beq-      .loc_0x390

	.loc_0x33C:
	  mtctr     r6

	.loc_0x340:
	  add       r8, r3, r9
	  lbz       r0, 0x0(r8)
	  subi      r9, r9, 0x1
	  rlwinm    r0,r0,26,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x0(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,28,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x1(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,30,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x2(r7)
	  lbz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,30,31
	  lbzx      r0, r5, r0
	  stb       r0, 0x3(r7)
	  subi      r7, r7, 0x4
	  bdnz+     .loc_0x340

	.loc_0x390:
	  lwz       r5, -0x7090(r13)
	  mr        r3, r4
	  lwz       r4, 0x28(r5)
	  bl        -0x2114
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE870
 * Size:	0000E0
 */
BOOL OSInitFont(OSFontHeader* fontInfo)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lhz       r0, -0x7C90(r13)
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x1C
	  b         .loc_0x64

	.loc_0x1C:
	  lis       r4, 0x8000
	  lwz       r0, 0xCC(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x34
	  blt-      .loc_0x58
	  b         .loc_0x58

	.loc_0x34:
	  lis       r4, 0xCC00
	  lhz       r0, 0x206E(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x4C
	  li        r0, 0x1
	  b         .loc_0x50

	.loc_0x4C:
	  li        r0, 0

	.loc_0x50:
	  sth       r0, -0x7C90(r13)
	  b         .loc_0x60

	.loc_0x58:
	  li        r0, 0
	  sth       r0, -0x7C90(r13)

	.loc_0x60:
	  lhz       r0, -0x7C90(r13)

	.loc_0x64:
	  rlwinm    r0,r0,0,16,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x7C
	  addis     r4, r3, 0xD
	  addi      r4, r4, 0x3F00
	  b         .loc_0x84

	.loc_0x7C:
	  addis     r4, r3, 0x2
	  subi      r4, r4, 0x2EE0

	.loc_0x84:
	  rlwinm    r4,r4,0,0,26
	  bl        -0x76C
	  cmplwi    r3, 0
	  bne-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0xD0

	.loc_0x9C:
	  lwz       r5, -0x7090(r13)
	  lwz       r0, 0x24(r5)
	  add       r0, r5, r0
	  stw       r0, -0x708C(r13)
	  lwz       r3, -0x708C(r13)
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  stw       r0, -0x708C(r13)
	  lwz       r0, 0x24(r5)
	  lwz       r4, -0x708C(r13)
	  add       r3, r5, r0
	  bl        -0x478
	  li        r3, 0x1

	.loc_0xD0:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE950
 * Size:	0001A8
 */
char* OSGetFontTexture(char* string, void** image, s32* x, s32* y, s32* width)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  addi      r31, r7, 0
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r3, r0
	  bne-      .loc_0x44
	  li        r0, 0
	  stw       r0, 0x0(r28)
	  mr        r3, r27
	  b         .loc_0x194

	.loc_0x44:
	  lhz       r0, -0x7C90(r13)
	  addi      r27, r27, 0x1
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x58
	  b         .loc_0xA0

	.loc_0x58:
	  lis       r4, 0x8000
	  lwz       r0, 0xCC(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x70
	  blt-      .loc_0x94
	  b         .loc_0x94

	.loc_0x70:
	  lis       r4, 0xCC00
	  lhz       r0, 0x206E(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x88
	  li        r0, 0x1
	  b         .loc_0x8C

	.loc_0x88:
	  li        r0, 0

	.loc_0x8C:
	  sth       r0, -0x7C90(r13)
	  b         .loc_0x9C

	.loc_0x94:
	  li        r0, 0
	  sth       r0, -0x7C90(r13)

	.loc_0x9C:
	  lhz       r0, -0x7C90(r13)

	.loc_0xA0:
	  rlwinm    r0,r0,0,16,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x11C
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x81
	  li        r4, 0x1
	  li        r5, 0
	  blt-      .loc_0xCC
	  cmplwi    r0, 0x9F
	  bgt-      .loc_0xCC
	  mr        r5, r4

	.loc_0xCC:
	  cmpwi     r5, 0
	  bne-      .loc_0xFC
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0xE0
	  li        r5, 0
	  blt-      .loc_0xF0
	  cmplwi    r0, 0xFC
	  bgt-      .loc_0xF0
	  li        r5, 0x1

	.loc_0xF0:
	  cmpwi     r5, 0
	  bne-      .loc_0xFC
	  li        r4, 0

	.loc_0xFC:
	  cmpwi     r4, 0
	  beq-      .loc_0x11C
	  lbz       r4, 0x0(r27)
	  extsb.    r0, r4
	  beq-      .loc_0x11C
	  rlwinm    r0,r3,8,8,23
	  or        r3, r0, r4
	  addi      r27, r27, 0x1

	.loc_0x11C:
	  bl        -0xCD4
	  lwz       r0, -0x7084(r13)
	  cmplwi    r31, 0
	  lwz       r4, -0x7090(r13)
	  divw      r6, r3, r0
	  lwz       r5, -0x708C(r13)
	  lwz       r0, 0x14(r4)
	  mullw     r0, r0, r6
	  add       r0, r5, r0
	  stw       r0, 0x0(r28)
	  lwz       r0, -0x7084(r13)
	  lwz       r5, -0x7090(r13)
	  mullw     r4, r6, r0
	  lhz       r6, 0x1A(r5)
	  lhz       r0, 0x10(r5)
	  sub       r5, r3, r4
	  divw      r7, r5, r6
	  mullw     r4, r7, r6
	  sub       r4, r5, r4
	  mullw     r0, r4, r0
	  stw       r0, 0x0(r29)
	  lwz       r4, -0x7090(r13)
	  lhz       r0, 0x12(r4)
	  mullw     r0, r7, r0
	  stw       r0, 0x0(r30)
	  beq-      .loc_0x190
	  lwz       r4, -0x7088(r13)
	  lbzx      r0, r4, r3
	  stw       r0, 0x0(r31)

	.loc_0x190:
	  mr        r3, r27

	.loc_0x194:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EEAF8
 * Size:	000140
 */
char* OSGetFontWidth(char* string, s32* width)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r3, r0
	  bne-      .loc_0x34
	  mr        r3, r30
	  b         .loc_0x128

	.loc_0x34:
	  lhz       r0, -0x7C90(r13)
	  addi      r30, r30, 0x1
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x48
	  b         .loc_0x90

	.loc_0x48:
	  lis       r4, 0x8000
	  lwz       r0, 0xCC(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x60
	  blt-      .loc_0x84
	  b         .loc_0x84

	.loc_0x60:
	  lis       r4, 0xCC00
	  lhz       r0, 0x206E(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x78
	  li        r0, 0x1
	  b         .loc_0x7C

	.loc_0x78:
	  li        r0, 0

	.loc_0x7C:
	  sth       r0, -0x7C90(r13)
	  b         .loc_0x8C

	.loc_0x84:
	  li        r0, 0
	  sth       r0, -0x7C90(r13)

	.loc_0x8C:
	  lhz       r0, -0x7C90(r13)

	.loc_0x90:
	  rlwinm    r0,r0,0,16,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x10C
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x81
	  li        r4, 0x1
	  li        r5, 0
	  blt-      .loc_0xBC
	  cmplwi    r0, 0x9F
	  bgt-      .loc_0xBC
	  mr        r5, r4

	.loc_0xBC:
	  cmpwi     r5, 0
	  bne-      .loc_0xEC
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0xE0
	  li        r5, 0
	  blt-      .loc_0xE0
	  cmplwi    r0, 0xFC
	  bgt-      .loc_0xE0
	  li        r5, 0x1

	.loc_0xE0:
	  cmpwi     r5, 0
	  bne-      .loc_0xEC
	  li        r4, 0

	.loc_0xEC:
	  cmpwi     r4, 0
	  beq-      .loc_0x10C
	  lbz       r4, 0x0(r30)
	  extsb.    r0, r4
	  beq-      .loc_0x10C
	  rlwinm    r0,r3,8,8,23
	  or        r3, r0, r4
	  addi      r30, r30, 0x1

	.loc_0x10C:
	  cmplwi    r31, 0
	  beq-      .loc_0x124
	  bl        -0xE74
	  lwz       r4, -0x7088(r13)
	  lbzx      r0, r4, r3
	  stw       r0, 0x0(r31)

	.loc_0x124:
	  mr        r3, r30

	.loc_0x128:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
