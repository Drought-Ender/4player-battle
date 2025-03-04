#ifndef _JSYSTEM_J3D_J3DTYPES_H
#define _JSYSTEM_J3D_J3DTYPES_H

#include "Dolphin/gx.h"
#include "Dolphin/vec.h"
#include "JSystem/J3D/J3DGXColor.h"
#include "JSystem/JGeometry.h"
#include "JSystem/JMath.h"
#include "types.h"

// TODO: Make a bitmask enum
/**
 * @fabricatedName
 */
typedef u32 J3DModelLoaderFlags;
#define J3DMLF_MtxCalc_SoftImage          0x00000001
#define J3DMLF_MtxCalc_Maya               0x00000002
#define J3DMLF_UseConcatViewShapeMatrices 0x00000010

enum JBlockType {
	JBT_ColorAmbientOn = 'CLAB',
	JBT_ColorNull      = 'CLNL',
	JBT_ColorLightOff  = 'CLOF',
	JBT_ColorLightOn   = 'CLON',
	JBT_IndFull        = 'IBLF',
	JBT_IndNull        = 'IBLN',
	JBT_PETexEdge      = 'PEED',
	JBT_PEFogOff       = 'PEFG',
	JBT_PEFull         = 'PEFL',
	JBT_PENull         = 'PENL',
	JBT_PEOpa          = 'PEOP',
	JBT_PEXlu          = 'PEXL',
	JBT_TexGen4        = 'TGB4',
	JBT_TexGenBasic    = 'TGBC',
	JBT_TexGenNull     = 'TGNL',
	JBT_TexGenPatched  = 'TGPT',
	JBT_Tev16          = 'TV16',
	JBT_Tev1           = 'TVB1',
	JBT_Tev2           = 'TVB2',
	JBT_Tev4           = 'TVB4',
	JBT_Tev8           = 'TVB8',
	JBT_TevNull        = 'TVNL',
	JBT_TevPatched     = 'TVPT'
};

enum J3DModelLoaderFlagTypes {
	J3DMLF_None = 0x00000000,

	J3DMLF_MtxSoftImageCalc = 0x00000001,
	J3DMLF_MtxMayaCalc      = 0x00000002,
	J3DMLF_MtxBasicCalc     = 0x00000004,
	J3DMLF_04               = 0x00000008,
	J3DMLF_MtxTypeMask
	= J3DMLF_MtxSoftImageCalc | J3DMLF_MtxMayaCalc | J3DMLF_MtxBasicCalc | J3DMLF_04, // 0 - 2 (0 = Basic, 1 = SoftImage, 2 = Maya)

	J3DMLF_UseImmediateMtx          = 0x00000010,
	J3DMLF_UsePostTexMtx            = 0x00000020,
	J3DMLF_07                       = 0x00000040,
	J3DMLF_08                       = 0x00000080,
	J3DMLF_NoMatrixTransform        = 0x00000100,
	J3DMLF_10                       = 0x00000200,
	J3DMLF_11                       = 0x00000400,
	J3DMLF_12                       = 0x00000800,
	J3DMLF_13                       = 0x00001000,
	J3DMLF_DoBdlMaterialCalc        = 0x00002000,
	J3DMLF_15                       = 0x00004000,
	J3DMLF_16                       = 0x00008000,
	J3DMLF_TevNumShift              = 0x00010000,
	J3DMLF_18                       = 0x00020000,
	J3DMLF_UseSingleSharedDL        = 0x00040000,
	J3DMLF_20                       = 0x00080000,
	J3DMLF_21                       = 0x00100000,
	J3DMLF_UseUniqueMaterials       = 0x00200000,
	J3DMLF_23                       = 0x00400000,
	J3DMLF_24                       = 0x00800000,
	J3DMLF_Material_UseIndirect     = 0x01000000,
	J3DMLF_26                       = 0x02000000,
	J3DMLF_27                       = 0x04000000,
	J3DMLF_Material_TexGen_Block4   = 0x08000000,
	J3DMLF_Material_PE_Full         = 0x10000000,
	J3DMLF_Material_PE_FogOff       = 0x20000000,
	J3DMLF_Material_Color_LightOn   = 0x40000000,
	J3DMLF_Material_Color_AmbientOn = 0x80000000
};

enum J3DModelFlags {
	J3DMODEL_Unk1              = 0x1,
	J3DMODEL_UseDefaultJ3D     = 0x2,
	J3DMODEL_SkinPosCpu        = 0x4,
	J3DMODEL_SkinNrmCpu        = 0x8,
	J3DMODEL_LevelOfDetail     = 0x10,
	J3DMODEL_Unk6              = 0x20,
	J3DMODEL_Unk7              = 0x40,
	J3DMODEL_Unk8              = 0x80,
	J3DMODEL_Unk9              = 0x100,
	J3DMODEL_Unk10             = 0x200,
	J3DMODEL_Unk11             = 0x400,
	J3DMODEL_Unk12             = 0x800,
	J3DMODEL_Unk13             = 0x1000,
	J3DMODEL_Unk14             = 0x2000,
	J3DMODEL_Unk15             = 0x4000,
	J3DMODEL_Unk16             = 0x8000,
	J3DMODEL_Unk17             = 0x10000,
	J3DMODEL_CreateNewDL       = 0x20000,
	J3DMODEL_UseSingleSharedDL = 0x40000,
	J3DMODEL_ShareDL           = 0x80000,
	J3DMODEL_Unk21             = 0x100000,
	J3DMODEL_Unk22             = 0x200000,
	J3DMODEL_Unk23             = 0x400000,
	J3DMODEL_Unk24             = 0x800000,
	J3DMODEL_Unk25             = 0x1000000,
	J3DMODEL_Unk26             = 0x2000000,
	J3DMODEL_Unk27             = 0x4000000,
	J3DMODEL_Unk28             = 0x8000000,
	J3DMODEL_Unk29             = 0x10000000,
	J3DMODEL_Unk30             = 0x20000000,
	J3DMODEL_Unk31             = 0x40000000,
	J3DMODEL_Unk32             = 0x80000000,
};

/*
 * J3DModelDiffFlags is an enumeration that defines different flags for 3D model differences.
 * Each flag represents a different aspect of the model that can be different.
 *
 * J3DMDF_DiffMatColor:     This flag is set if the material color is different. It corresponds to the 1st bit.
 * J3DMDF_DiffLight:        This flag is set if the light settings are different. It corresponds to the 2nd bit.
 * J3DMDF_DiffTexGen:       This flag is set if the TexCoordGen is different. It corresponds to the 13th bit.
 * J3DMDF_Unknown:          This flag is reserved for a flag that isn't yet understood. It corresponds to the 18th bit.
 * J3DMDF_DiffColorReg:     This flag is set if the color registers (TEV) are different. It corresponds to the 25th bit.
 * J3DMDF_DiffKonstColor:   This flag is set if the Konst colors are different. It corresponds to the 26th bit.
 * J3DMDF_DiffTevOrderFull: This flag is set if the full TevOrder (TexMap and TexCoordIdx) is different. It corresponds to the 27th bit.
 * J3DMDF_DiffIndTevStage:  This flag is set if the indirect TevStages are different. It corresponds to the 28th bit.
 * J3DMDF_DiffFog:          This flag is set if the fog settings are different. It corresponds to the 29th bit.
 * J3DMDF_DiffBlend:        This flag is set if the blend settings are different. It corresponds to the 30th bit.
 *
 * The CREATE_DIFF_FLAG macro is used to create a u32 value with specific flags set.
 * It takes four parameters: lightObjNum, texGenNum, texCoordNum, and tevStageNum. Each parameter is expected to be a 4-bit value.
 * The parameters are shifted to their respective positions in the u32 value and combined using the bitwise OR operator.
 *
 * lightObjNum: This value is shifted to bits 4 - 7.
 * texGenNum:   This value is shifted to bits 8 - 11.
 * texCoordNum:    This value is shifted to bits 16 - 19.
 * tevStageNum: This value is shifted to bits 20 - 23.
 */

enum J3DModelDiffFlags {
	J3DMDF_DiffMatColor = 0x00000001, // Diff material color
	J3DMDF_DiffLight    = 0x00000002, // Diff light settings
	J3DMDF_DiffTexGen   = 0x00001000, // Diff TexCoordGen

	J3DMDF_TexCoord0 = 0x000010000, // TexCoord0
	J3DMDF_TexCoord1 = 0x000020000, // TexCoord1
	J3DMDF_TexCoord2 = 0x000030000, // TexCoord2
	J3DMDF_TexCoord3 = 0x000040000, // TexCoord3
	J3DMDF_TexCoord4 = 0x000050000, // TexCoord4
	J3DMDF_TexCoord5 = 0x000060000, // TexCoord5
	J3DMDF_TexCoord6 = 0x000070000, // TexCoord6
	J3DMDF_TexCoord7 = 0x000080000, // TexCoord7

	J3DMDF_DiffColorReg         = 0x01000000, // Diff color registers (TEV)
	J3DMDF_DiffKonstColor       = 0x02000000, // Diff Konst colors
	J3DMDF_DiffTexCoordScale    = 0x04000000, // Diff TexCoord scales
	J3DMDF_DiffTevStageIndirect = 0x08000000, // Diff indirect TevStages
	J3DMDF_DiffFog              = 0x10000000, // Diff fog settings
	J3DMDF_DiffBlend            = 0x20000000  // Diff blend settings
};


#define CREATE_DIFF_FLAG(lightObjNum, texGenNum, texCoordNum, tevStageNum) \
	(((lightObjNum & 0xf) << 4) | ((texGenNum & 0xf) << 8) | ((texCoordNum & 0xf) << 16) | ((tevStageNum & 0xf) << 20))


enum J3DErrType { JET_Success = 0, JET_NoMatAnm, JET_LockedModelData, JET_NullBinRes, JET_OutOfMemory, JET_InvalidArg, JET_InvalidData };

struct J3DAlphaComp {
	u16 _00; // _00
	u8 _02;  // _02
	u8 _03;  // _03
};

struct J3DBlendInfo {
	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
	u8 _03; // _03
};

extern const J3DBlendInfo j3dDefaultBlendInfo;

struct J3DBlend {
	/** @fabricated */
	inline J3DBlend()
	    : _00(j3dDefaultBlendInfo._00)
	    , _01(j3dDefaultBlendInfo._01)
	    , _02(j3dDefaultBlendInfo._02)
	    , _03(j3dDefaultBlendInfo._03)
	{
	}

	/** @fabricated */
	inline J3DBlend(const J3DBlendInfo& info)
	    : _00(info._00)
	    , _01(info._01)
	    , _02(info._02)
	    , _03(info._03)
	{
	}

	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
	u8 _03; // _03
};

struct J3DZModeInfo {
	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
	u8 _03; // _03 - unknown/padding
};

extern const u16 j3dDefaultZModeID;

struct J3DZMode {
	/** @fabricated */
	J3DZMode()
	    : _00(j3dDefaultZModeID)
	{
	}

	/** @fabricated */
	J3DZMode(const J3DZModeInfo& info)
	    : _00(info._01 * 2 + info._00 * 0x10 + info._02)
	{
	}
	u16 _00; // _00
};

struct J3DColorChan {
	J3DColorChan();

	u16 _00;
};

// IDK what the structure of this is meant to be
struct J3DIndTevStageInfo {
	u8 _00 : 2;
};

extern const J3DIndTevStageInfo j3dDefaultIndTevStageInfo[12];

struct J3DIndTevStage {
	J3DIndTevStage();

	u32 _00 : 10;
	// u32 _01 : 1;
	// u32 _02 : 1;
	// u32 _03 : 1;
	// u32 _04 : 1;
	// u32 _05 : 1;
	// u32 _06 : 1;
	// u32 _07 : 1;
	// u32 _08 : 1;
	// u32 _09 : 1;
	// u32 _0A : 1;
	u32 _0B : 1;
	u32 _0C : 1;
	u32 _0D : 3;
	u32 _10 : 3;
	u32 _13 : 4;
	u32 _17 : 2;
	u32 _19 : 3;
	u32 _1C : 2;
	u32 _1E : 2;
};

struct J3DLightObj {
	JGeometry::TVec3f mPosition;  // _00
	JGeometry::TVec3f mDirection; // _0C
	_GXColor _18;                 // _18
	f32 _1C;                      // _1C
	f32 _20;                      // _20
	f32 _24;                      // _24
	f32 _28;                      // _28
	f32 _2C;                      // _2C
	f32 _30;                      // _30

	void load(u32) const;
};

struct J3DTevOrderInfo {
	// inline GXTexCoordID getTexCoordID() const { return (GXTexCoordID)mData[0]; }
	// inline GXTexMapID getTexMapID() const { return (GXTexMapID)mData[1]; }
	// inline u8 getChannelID() const { return mData[2]; }
	u8 mData[3]; // _00

	// inline GXTexCoordID getTexCoordID() const { return (GXTexCoordID)mTexCoordID; }
	// inline GXTexMapID getTexMapID() const { return (GXTexMapID)mTexMapID; }
	// inline u8 getChannelID() const { return mChannelID; }

	// u8 mTexCoordID; // _00
	// u8 mTexMapID;   // _01
	// u8 mChannelID;  // _02

	// u8 _03;          // _03 - unknown/padding
};

extern const J3DTevOrderInfo j3dDefaultTevOrderInfoNull;

struct J3DTevOrder {
	J3DTevOrder()
	// : mData(j3dDefaultTevOrderInfoNull.mData)
	// : mTexCoordID(j3dDefaultTevOrderInfoNull.mTexCoordID)
	// , mTexMapID(j3dDefaultTevOrderInfoNull.mTexMapID)
	// , mChannelID(j3dDefaultTevOrderInfoNull.mChannelID)
	{
		// for (int i = 0; i < 3; i++) {
		// 	mData[i] = j3dDefaultTevOrderInfoNull.mData[i];
		// }
		const J3DTevOrderInfo& info = j3dDefaultTevOrderInfoNull;
		mTexCoordID                 = info.mData[0];
		mTexMapID                   = info.mData[1];
		mChannelID                  = info.mData[2];
		// mTexCoordID                = info.mTexCoordID;
		// mTexMapID                  = info.mTexMapID;
		// mChannelID                 = info.mChannelID;
		// setTexCoordID(info.getTexCoordID());
		// setTexMapID(info.getTexMapID());
		// setChannelID(info.getChannelID());

		// *this = static_cast<const J3DTevOrder>(j3dDefaultTevOrderInfoNull);
		// setTexCoordID(j3dDefaultTevOrderInfoNull.getTexCoordID());
		// setTexMapID(j3dDefaultTevOrderInfoNull.getTexMapID());
		// setChannelID(j3dDefaultTevOrderInfoNull.getChannelID());
	}

	/** @fabricated */
	inline J3DTevOrder(const J3DTevOrderInfo& info)
	    // : mTexCoordID(info.mTexCoordID)
	    // , mTexMapID(info.mTexMapID)
	    // , mChannelID(info.mChannelID)
	    : mTexCoordID(info.mData[0])
	    , mTexMapID(info.mData[1])
	    , mChannelID(info.mData[2])
	{
		// for (int i = 0; i < 3; i++) {
		// 	mData[i] = info.mData[i];
		// }
	}

	/** @fabricated */
	inline J3DTevOrder& operator=(const J3DTevOrder& other)
	{
		mTexCoordID = other.mTexCoordID;
		mTexMapID   = other.mTexMapID;
		mChannelID  = other.mChannelID;
		// for (int i = 0; i < 3; i++) {
		// 	mData[i] = other.mData[i];
		// }
		return *this;
	}

	inline void setTexCoordID(GXTexCoordID id) { mTexCoordID = id; }
	inline void setTexMapID(GXTexMapID id) { mTexMapID = id; }
	inline void setChannelID(u8 id) { mChannelID = id; }

	u8 mTexCoordID; // _00
	u8 mTexMapID;   // _01
	u8 mChannelID;  // _02
	u8 _03;

	// inline void setTexCoordID(GXTexCoordID id) { mData[0] = id; }
	// inline void setTexMapID(GXTexMapID id) { mData[1] = id; }
	// inline void setChannelID(u8 id) { mData[2] = id; }

	// u8 mData[3]; // _00
};

// TODO: Determine if this needs packing pragmas to make it exactly 1 bytes
/**
 * @size{0x1}
 */
struct J3DTevSwapModeTable {
	J3DTevSwapModeTable();

	u8 _00;
};

struct J3DTevStage {
	J3DTevStage();
	J3DTevStage(const struct J3DTevStageInfo&);

	/** @fabricated */
	inline J3DTevStage& operator=(const J3DTevStage& other)
	{
		_01 = other._01;
		_02 = other._02;
		_03 = other._03;
		_05 = other._05;
		_06 = other._06;
		_07 = other._07;
		return *this;
	}

	void setTevStageInfo(const J3DTevStageInfo&);

	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
	u8 _03; // _03
	u8 _04; // _04
	u8 _05; // _05
	u8 _06; // _06
	u8 _07; // _07
};

struct J3DDefaultTexCoordInfo {
	u8 mTexGenType; // _00
	u8 mTexGenSrc;  // _01
	u8 mTexGenMtx;  // _02
	u8 mPadding;    // _03
};

struct J3DTexCoordInfo {
	u8 mTexGenType; // _00
	u8 mTexGenSrc;  // _01
	u8 mTexGenMtx;  // _02
};

extern const J3DDefaultTexCoordInfo j3dDefaultTexCoordInfo[8];

// TODO: Determine if this needs packing pragmas to make it exactly 6 bytes
/**
 * @size{0x6}
 */
struct J3DTexCoord {
	inline J3DTexCoord()
	    : _00(j3dDefaultTexCoordInfo[0].mTexGenType)
	    , _01(j3dDefaultTexCoordInfo[0].mTexGenSrc)
	    , _02(j3dDefaultTexCoordInfo[0].mTexGenMtx)
	    , _04(_02)
	{
	}

	inline J3DTexCoord(const J3DTexCoordInfo& info)
	    : _00(info.mTexGenType)
	    , _01(info.mTexGenSrc)
	    , _02(info.mTexGenMtx)
	    , _04(_02)
	{
	}

	u8 _00;  // _00
	u8 _01;  // _01
	u8 _02;  // _02
	u16 _04; // _04
};

struct J3DTextureSRTInfo {
	f32 mScaleX;       // _00
	f32 mScaleY;       // _04
	s16 mRotation;     // _08
	f32 mTranslationX; // _0C
	f32 mTranslationY; // _10
};

struct J3DTransformInfo {
	JGeometry::TVec3f mScale;        // _00
	JGeometry::TVec3<s16> mRotation; // _0C
	JGeometry::TVec3f mTranslation;  // _14
};

extern const J3DTransformInfo j3dDefaultTransformInfo;

struct J3DNBTScaleInfo {
	u8 _00;                // _00
	JGeometry::TVec3f _04; // _04

	// f32 _08; // _08
	// f32 _0C; // _0C
};

extern const J3DNBTScaleInfo j3dDefaultNBTScaleInfo;

struct J3DNBTScale {
	inline J3DNBTScale()
	    : _00(j3dDefaultNBTScaleInfo._00)
	    , _04(j3dDefaultNBTScaleInfo._04)
	{
		// _04.x = j3dDefaultNBTScaleInfo._04;
		// _04.y = j3dDefaultNBTScaleInfo._08;
		// _04.z = j3dDefaultNBTScaleInfo._0C;
	}

	/** @fabricated */
	inline J3DNBTScale(const J3DNBTScaleInfo& info)
	    : _00(info._00)
	    , _04(info._04)
	{
		// _04.x = info._04;
		// _04.y = info._08;
		// _04.z = info._0C;
	}

	u8 _00; // _00
	JGeometry::TVec3f _04;
};
void loadNBTScale(J3DNBTScale&);

void loadTexCoordGens(u32, J3DTexCoord*);

enum J3DTexDiffFlag { TexDiff_0 = 0, TexDiff_1 };

enum J3DDeformAttachFlag { DeformAttach_0 = 0, DeformAttach_1 = 1 };

extern const GXColor j3dDefaultColInfo;
extern const u32 j3dDefaultAmbInfo;
extern const u8 j3dDefaultColorChanNum;
// extern const J3DGXColor j3dDefaultTevColor;
// extern const J3DGXColorS10 j3dDefaultTevKColor;
extern const GXColorS10 j3dDefaultTevColor;
extern const GXColor j3dDefaultTevKColor;

extern const u8 j3dDefaultTevSwapTableID;

#endif
