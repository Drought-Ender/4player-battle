.include "macros.inc"
.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8049A6C0, local
	.asciz "P2DScreen.cpp"
.endobj lbl_8049A6C0
.balign 4
.obj lbl_8049A6D0, local
	.asciz "P2Assert"
.endobj lbl_8049A6D0

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj __vt__Q29P2DScreen10Mgr_tuning, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q29P2DScreen10Mgr_tuningFv
	.4byte getTypeID__9J2DScreenCFv
	.4byte move__7J2DPaneFff
	.4byte add__7J2DPaneFff
	.4byte resize__7J2DPaneFff
	.4byte setCullBack__7J2DPaneFb
	.4byte setCullBack__7J2DPaneF11_GXCullMode
	.4byte setAlpha__7J2DPaneFUc
	.4byte setConnectParent__7J2DPaneFb
	.4byte calcMtx__9J2DScreenFv
	.4byte update__Q29P2DScreen3MgrFv
	.4byte drawSelf__7J2DPaneFff
	.4byte drawSelf__9J2DScreenFffPA3_A4_f
	.4byte search__9J2DScreenFUx
	.4byte searchUserInfo__9J2DScreenFUx
	.4byte makeMatrix__7J2DPaneFff
	.4byte makeMatrix__7J2DPaneFffff
	.4byte isUsed__9J2DScreenFPC7ResTIMG
	.4byte isUsed__9J2DScreenFPC7ResFONT
	.4byte clearAnmTransform__9J2DScreenFv
	.4byte rewriteAlpha__7J2DPaneFv
	.4byte setAnimation__9J2DScreenFP10J2DAnmBase
	.4byte setAnimation__9J2DScreenFP15J2DAnmTransform
	.4byte setAnimation__9J2DScreenFP11J2DAnmColor
	.4byte setAnimation__9J2DScreenFP16J2DAnmTexPattern
	.4byte setAnimation__9J2DScreenFP19J2DAnmTextureSRTKey
	.4byte setAnimation__9J2DScreenFP15J2DAnmTevRegKey
	.4byte setAnimation__9J2DScreenFP20J2DAnmVisibilityFull
	.4byte setAnimation__9J2DScreenFP14J2DAnmVtxColor
	.4byte animationTransform__7J2DPaneFPC15J2DAnmTransform
	.4byte setVisibileAnimation__7J2DPaneFP20J2DAnmVisibilityFull
	.4byte setAnimationVF__9J2DScreenFP20J2DAnmVisibilityFull
	.4byte setVtxColorAnimation__7J2DPaneFP14J2DAnmVtxColor
	.4byte setAnimationVC__9J2DScreenFP14J2DAnmVtxColor
	.4byte animationPane__7J2DPaneFPC15J2DAnmTransform
	.4byte createPane__9J2DScreenFRC18J2DScrnBlockHeaderP20JSURandomInputStreamP7J2DPaneUl
	.4byte createPane__9J2DScreenFRC18J2DScrnBlockHeaderP20JSURandomInputStreamP7J2DPaneUlP10JKRArchive
	.4byte draw__Q29P2DScreen10Mgr_tuningFR8GraphicsR14J2DGrafContext
.endobj __vt__Q29P2DScreen10Mgr_tuning
.obj __vt__Q29P2DScreen3Mgr, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q29P2DScreen3MgrFv
	.4byte getTypeID__9J2DScreenCFv
	.4byte move__7J2DPaneFff
	.4byte add__7J2DPaneFff
	.4byte resize__7J2DPaneFff
	.4byte setCullBack__7J2DPaneFb
	.4byte setCullBack__7J2DPaneF11_GXCullMode
	.4byte setAlpha__7J2DPaneFUc
	.4byte setConnectParent__7J2DPaneFb
	.4byte calcMtx__9J2DScreenFv
	.4byte update__Q29P2DScreen3MgrFv
	.4byte drawSelf__7J2DPaneFff
	.4byte drawSelf__9J2DScreenFffPA3_A4_f
	.4byte search__9J2DScreenFUx
	.4byte searchUserInfo__9J2DScreenFUx
	.4byte makeMatrix__7J2DPaneFff
	.4byte makeMatrix__7J2DPaneFffff
	.4byte isUsed__9J2DScreenFPC7ResTIMG
	.4byte isUsed__9J2DScreenFPC7ResFONT
	.4byte clearAnmTransform__9J2DScreenFv
	.4byte rewriteAlpha__7J2DPaneFv
	.4byte setAnimation__9J2DScreenFP10J2DAnmBase
	.4byte setAnimation__9J2DScreenFP15J2DAnmTransform
	.4byte setAnimation__9J2DScreenFP11J2DAnmColor
	.4byte setAnimation__9J2DScreenFP16J2DAnmTexPattern
	.4byte setAnimation__9J2DScreenFP19J2DAnmTextureSRTKey
	.4byte setAnimation__9J2DScreenFP15J2DAnmTevRegKey
	.4byte setAnimation__9J2DScreenFP20J2DAnmVisibilityFull
	.4byte setAnimation__9J2DScreenFP14J2DAnmVtxColor
	.4byte animationTransform__7J2DPaneFPC15J2DAnmTransform
	.4byte setVisibileAnimation__7J2DPaneFP20J2DAnmVisibilityFull
	.4byte setAnimationVF__9J2DScreenFP20J2DAnmVisibilityFull
	.4byte setVtxColorAnimation__7J2DPaneFP14J2DAnmVtxColor
	.4byte setAnimationVC__9J2DScreenFP14J2DAnmVtxColor
	.4byte animationPane__7J2DPaneFPC15J2DAnmTransform
	.4byte createPane__9J2DScreenFRC18J2DScrnBlockHeaderP20JSURandomInputStreamP7J2DPaneUl
	.4byte createPane__9J2DScreenFRC18J2DScrnBlockHeaderP20JSURandomInputStreamP7J2DPaneUlP10JKRArchive
	.4byte draw__Q29P2DScreen3MgrFR8GraphicsR14J2DGrafContext
.endobj __vt__Q29P2DScreen3Mgr

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_80520790, local
	.float 0.0
.endobj lbl_80520790
.obj mstTuningScaleX__Q29P2DScreen10Mgr_tuning, global
	.float 0.95
.endobj mstTuningScaleX__Q29P2DScreen10Mgr_tuning
.obj mstTuningScaleY__Q29P2DScreen10Mgr_tuning, global
	.float 0.95
.endobj mstTuningScaleY__Q29P2DScreen10Mgr_tuning
.obj mstTuningTransX__Q29P2DScreen10Mgr_tuning, global
	.float -15.2
.endobj mstTuningTransX__Q29P2DScreen10Mgr_tuning
.obj mstTuningTransY__Q29P2DScreen10Mgr_tuning, global
	.float -15.2
.endobj mstTuningTransY__Q29P2DScreen10Mgr_tuning
.obj lbl_805207A4, local
	.float 0.95
.endobj lbl_805207A4
.obj lbl_805207A8, local
	.float -15.2
.endobj lbl_805207A8
.obj lbl_805207AC, local
	.float 0.5
.endobj lbl_805207AC
.balign 8
.obj lbl_805207B0, local
	.8byte 0x4330000000000000
.endobj lbl_805207B0

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q29P2DScreen3MgrFv, global
/* 80434AC0 00431A00  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80434AC4 00431A04  7C 08 02 A6 */	mflr r0
/* 80434AC8 00431A08  90 01 00 14 */	stw r0, 0x14(r1)
/* 80434ACC 00431A0C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80434AD0 00431A10  7C 7F 1B 78 */	mr r31, r3
/* 80434AD4 00431A14  93 C1 00 08 */	stw r30, 8(r1)
/* 80434AD8 00431A18  4B C0 A9 9D */	bl __ct__9J2DScreenFv
/* 80434ADC 00431A1C  3C 60 80 4F */	lis r3, __vt__Q29P2DScreen3Mgr@ha
/* 80434AE0 00431A20  3B DF 01 18 */	addi r30, r31, 0x118
/* 80434AE4 00431A24  38 03 C5 A0 */	addi r0, r3, __vt__Q29P2DScreen3Mgr@l
/* 80434AE8 00431A28  90 1F 00 00 */	stw r0, 0(r31)
/* 80434AEC 00431A2C  7F C3 F3 78 */	mr r3, r30
/* 80434AF0 00431A30  4B FD C8 A1 */	bl __ct__5CNodeFv
/* 80434AF4 00431A34  3C 60 80 4D */	lis r3, __vt__Q29P2DScreen4Node@ha
/* 80434AF8 00431A38  38 00 00 00 */	li r0, 0
/* 80434AFC 00431A3C  38 83 7B 0C */	addi r4, r3, __vt__Q29P2DScreen4Node@l
/* 80434B00 00431A40  7F E3 FB 78 */	mr r3, r31
/* 80434B04 00431A44  90 9E 00 00 */	stw r4, 0(r30)
/* 80434B08 00431A48  90 1E 00 18 */	stw r0, 0x18(r30)
/* 80434B0C 00431A4C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80434B10 00431A50  83 C1 00 08 */	lwz r30, 8(r1)
/* 80434B14 00431A54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80434B18 00431A58  7C 08 03 A6 */	mtlr r0
/* 80434B1C 00431A5C  38 21 00 10 */	addi r1, r1, 0x10
/* 80434B20 00431A60  4E 80 00 20 */	blr 
.endfn __ct__Q29P2DScreen3MgrFv

.fn addCallBack__Q29P2DScreen3MgrFUxPQ29P2DScreen4Node, global
/* 80434B24 00431A64  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80434B28 00431A68  7C 08 02 A6 */	mflr r0
/* 80434B2C 00431A6C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80434B30 00431A70  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80434B34 00431A74  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80434B38 00431A78  7C FE 3B 79 */	or. r30, r7, r7
/* 80434B3C 00431A7C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80434B40 00431A80  7C 7D 1B 78 */	mr r29, r3
/* 80434B44 00431A84  90 A1 00 08 */	stw r5, 8(r1)
/* 80434B48 00431A88  90 C1 00 0C */	stw r6, 0xc(r1)
/* 80434B4C 00431A8C  40 82 00 20 */	bne .L_80434B6C
/* 80434B50 00431A90  3C 60 80 4A */	lis r3, lbl_8049A6C0@ha
/* 80434B54 00431A94  3C A0 80 4A */	lis r5, lbl_8049A6D0@ha
/* 80434B58 00431A98  38 63 A6 C0 */	addi r3, r3, lbl_8049A6C0@l
/* 80434B5C 00431A9C  38 80 00 49 */	li r4, 0x49
/* 80434B60 00431AA0  38 A5 A6 D0 */	addi r5, r5, lbl_8049A6D0@l
/* 80434B64 00431AA4  4C C6 31 82 */	crclr 6
/* 80434B68 00431AA8  4B BF 5A D9 */	bl panic_f__12JUTExceptionFPCciPCce
.L_80434B6C:
/* 80434B6C 00431AAC  7F A3 EB 78 */	mr r3, r29
/* 80434B70 00431AB0  80 A1 00 08 */	lwz r5, 8(r1)
/* 80434B74 00431AB4  81 9D 00 00 */	lwz r12, 0(r29)
/* 80434B78 00431AB8  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 80434B7C 00431ABC  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80434B80 00431AC0  7D 89 03 A6 */	mtctr r12
/* 80434B84 00431AC4  4E 80 04 21 */	bctrl 
/* 80434B88 00431AC8  7C 7F 1B 79 */	or. r31, r3, r3
/* 80434B8C 00431ACC  41 82 00 2C */	beq .L_80434BB8
/* 80434B90 00431AD0  93 FE 00 18 */	stw r31, 0x18(r30)
/* 80434B94 00431AD4  7F C3 F3 78 */	mr r3, r30
/* 80434B98 00431AD8  81 9E 00 00 */	lwz r12, 0(r30)
/* 80434B9C 00431ADC  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80434BA0 00431AE0  7D 89 03 A6 */	mtctr r12
/* 80434BA4 00431AE4  4E 80 04 21 */	bctrl 
/* 80434BA8 00431AE8  7F C4 F3 78 */	mr r4, r30
/* 80434BAC 00431AEC  38 7D 01 18 */	addi r3, r29, 0x118
/* 80434BB0 00431AF0  4B FD C8 59 */	bl add__5CNodeFP5CNode
/* 80434BB4 00431AF4  48 00 00 88 */	b .L_80434C3C
.L_80434BB8:
/* 80434BB8 00431AF8  88 61 00 08 */	lbz r3, 8(r1)
/* 80434BBC 00431AFC  38 00 00 3F */	li r0, 0x3f
/* 80434BC0 00431B00  7C 63 07 75 */	extsb. r3, r3
/* 80434BC4 00431B04  40 82 00 08 */	bne .L_80434BCC
/* 80434BC8 00431B08  98 01 00 08 */	stb r0, 8(r1)
.L_80434BCC:
/* 80434BCC 00431B0C  88 61 00 09 */	lbz r3, 9(r1)
/* 80434BD0 00431B10  7C 63 07 75 */	extsb. r3, r3
/* 80434BD4 00431B14  40 82 00 08 */	bne .L_80434BDC
/* 80434BD8 00431B18  98 01 00 09 */	stb r0, 9(r1)
.L_80434BDC:
/* 80434BDC 00431B1C  88 61 00 0A */	lbz r3, 0xa(r1)
/* 80434BE0 00431B20  7C 63 07 75 */	extsb. r3, r3
/* 80434BE4 00431B24  40 82 00 08 */	bne .L_80434BEC
/* 80434BE8 00431B28  98 01 00 0A */	stb r0, 0xa(r1)
.L_80434BEC:
/* 80434BEC 00431B2C  88 61 00 0B */	lbz r3, 0xb(r1)
/* 80434BF0 00431B30  7C 63 07 75 */	extsb. r3, r3
/* 80434BF4 00431B34  40 82 00 08 */	bne .L_80434BFC
/* 80434BF8 00431B38  98 01 00 0B */	stb r0, 0xb(r1)
.L_80434BFC:
/* 80434BFC 00431B3C  88 61 00 0C */	lbz r3, 0xc(r1)
/* 80434C00 00431B40  7C 63 07 75 */	extsb. r3, r3
/* 80434C04 00431B44  40 82 00 08 */	bne .L_80434C0C
/* 80434C08 00431B48  98 01 00 0C */	stb r0, 0xc(r1)
.L_80434C0C:
/* 80434C0C 00431B4C  88 61 00 0D */	lbz r3, 0xd(r1)
/* 80434C10 00431B50  7C 63 07 75 */	extsb. r3, r3
/* 80434C14 00431B54  40 82 00 08 */	bne .L_80434C1C
/* 80434C18 00431B58  98 01 00 0D */	stb r0, 0xd(r1)
.L_80434C1C:
/* 80434C1C 00431B5C  88 61 00 0E */	lbz r3, 0xe(r1)
/* 80434C20 00431B60  7C 63 07 75 */	extsb. r3, r3
/* 80434C24 00431B64  40 82 00 08 */	bne .L_80434C2C
/* 80434C28 00431B68  98 01 00 0E */	stb r0, 0xe(r1)
.L_80434C2C:
/* 80434C2C 00431B6C  88 61 00 0F */	lbz r3, 0xf(r1)
/* 80434C30 00431B70  7C 63 07 75 */	extsb. r3, r3
/* 80434C34 00431B74  40 82 00 08 */	bne .L_80434C3C
/* 80434C38 00431B78  98 01 00 0F */	stb r0, 0xf(r1)
.L_80434C3C:
/* 80434C3C 00431B7C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80434C40 00431B80  7F E3 FB 78 */	mr r3, r31
/* 80434C44 00431B84  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80434C48 00431B88  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80434C4C 00431B8C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80434C50 00431B90  7C 08 03 A6 */	mtlr r0
/* 80434C54 00431B94  38 21 00 20 */	addi r1, r1, 0x20
/* 80434C58 00431B98  4E 80 00 20 */	blr 
.endfn addCallBack__Q29P2DScreen3MgrFUxPQ29P2DScreen4Node

.fn addCallBackPane__Q29P2DScreen3MgrFP7J2DPanePQ29P2DScreen4Node, global
/* 80434C5C 00431B9C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80434C60 00431BA0  7C 08 02 A6 */	mflr r0
/* 80434C64 00431BA4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80434C68 00431BA8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80434C6C 00431BAC  7C BF 2B 79 */	or. r31, r5, r5
/* 80434C70 00431BB0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80434C74 00431BB4  7C 9E 23 78 */	mr r30, r4
/* 80434C78 00431BB8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80434C7C 00431BBC  7C 7D 1B 78 */	mr r29, r3
/* 80434C80 00431BC0  40 82 00 20 */	bne .L_80434CA0
/* 80434C84 00431BC4  3C 60 80 4A */	lis r3, lbl_8049A6C0@ha
/* 80434C88 00431BC8  3C A0 80 4A */	lis r5, lbl_8049A6D0@ha
/* 80434C8C 00431BCC  38 63 A6 C0 */	addi r3, r3, lbl_8049A6C0@l
/* 80434C90 00431BD0  38 80 00 61 */	li r4, 0x61
/* 80434C94 00431BD4  38 A5 A6 D0 */	addi r5, r5, lbl_8049A6D0@l
/* 80434C98 00431BD8  4C C6 31 82 */	crclr 6
/* 80434C9C 00431BDC  4B BF 59 A5 */	bl panic_f__12JUTExceptionFPCciPCce
.L_80434CA0:
/* 80434CA0 00431BE0  93 DF 00 18 */	stw r30, 0x18(r31)
/* 80434CA4 00431BE4  7F E3 FB 78 */	mr r3, r31
/* 80434CA8 00431BE8  81 9F 00 00 */	lwz r12, 0(r31)
/* 80434CAC 00431BEC  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80434CB0 00431BF0  7D 89 03 A6 */	mtctr r12
/* 80434CB4 00431BF4  4E 80 04 21 */	bctrl 
/* 80434CB8 00431BF8  7F E4 FB 78 */	mr r4, r31
/* 80434CBC 00431BFC  38 7D 01 18 */	addi r3, r29, 0x118
/* 80434CC0 00431C00  4B FD C7 49 */	bl add__5CNodeFP5CNode
/* 80434CC4 00431C04  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80434CC8 00431C08  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80434CCC 00431C0C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80434CD0 00431C10  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80434CD4 00431C14  7C 08 03 A6 */	mtlr r0
/* 80434CD8 00431C18  38 21 00 20 */	addi r1, r1, 0x20
/* 80434CDC 00431C1C  4E 80 00 20 */	blr 
.endfn addCallBackPane__Q29P2DScreen3MgrFP7J2DPanePQ29P2DScreen4Node

.fn update__Q29P2DScreen3MgrFv, global
/* 80434CE0 00431C20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80434CE4 00431C24  7C 08 02 A6 */	mflr r0
/* 80434CE8 00431C28  90 01 00 14 */	stw r0, 0x14(r1)
/* 80434CEC 00431C2C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80434CF0 00431C30  83 E3 01 28 */	lwz r31, 0x128(r3)
/* 80434CF4 00431C34  48 00 00 1C */	b .L_80434D10
.L_80434CF8:
/* 80434CF8 00431C38  7F E3 FB 78 */	mr r3, r31
/* 80434CFC 00431C3C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80434D00 00431C40  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80434D04 00431C44  7D 89 03 A6 */	mtctr r12
/* 80434D08 00431C48  4E 80 04 21 */	bctrl 
/* 80434D0C 00431C4C  83 FF 00 04 */	lwz r31, 4(r31)
.L_80434D10:
/* 80434D10 00431C50  28 1F 00 00 */	cmplwi r31, 0
/* 80434D14 00431C54  40 82 FF E4 */	bne .L_80434CF8
/* 80434D18 00431C58  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80434D1C 00431C5C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80434D20 00431C60  7C 08 03 A6 */	mtlr r0
/* 80434D24 00431C64  38 21 00 10 */	addi r1, r1, 0x10
/* 80434D28 00431C68  4E 80 00 20 */	blr 
.endfn update__Q29P2DScreen3MgrFv

.fn draw__Q29P2DScreen3MgrFR8GraphicsR14J2DGrafContext, global
/* 80434D2C 00431C6C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80434D30 00431C70  7C 08 02 A6 */	mflr r0
/* 80434D34 00431C74  C0 22 24 30 */	lfs f1, lbl_80520790@sda21(r2)
/* 80434D38 00431C78  90 01 00 24 */	stw r0, 0x24(r1)
/* 80434D3C 00431C7C  FC 40 08 90 */	fmr f2, f1
/* 80434D40 00431C80  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80434D44 00431C84  7C 7F 1B 78 */	mr r31, r3
/* 80434D48 00431C88  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80434D4C 00431C8C  7C BE 2B 78 */	mr r30, r5
/* 80434D50 00431C90  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80434D54 00431C94  7C 9D 23 78 */	mr r29, r4
/* 80434D58 00431C98  7F C4 F3 78 */	mr r4, r30
/* 80434D5C 00431C9C  4B C0 B5 51 */	bl draw__9J2DScreenFffPC14J2DGrafContext
/* 80434D60 00431CA0  83 FF 01 28 */	lwz r31, 0x128(r31)
/* 80434D64 00431CA4  48 00 00 24 */	b .L_80434D88
.L_80434D68:
/* 80434D68 00431CA8  7F E3 FB 78 */	mr r3, r31
/* 80434D6C 00431CAC  7F A4 EB 78 */	mr r4, r29
/* 80434D70 00431CB0  81 9F 00 00 */	lwz r12, 0(r31)
/* 80434D74 00431CB4  7F C5 F3 78 */	mr r5, r30
/* 80434D78 00431CB8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80434D7C 00431CBC  7D 89 03 A6 */	mtctr r12
/* 80434D80 00431CC0  4E 80 04 21 */	bctrl 
/* 80434D84 00431CC4  83 FF 00 04 */	lwz r31, 4(r31)
.L_80434D88:
/* 80434D88 00431CC8  28 1F 00 00 */	cmplwi r31, 0
/* 80434D8C 00431CCC  40 82 FF DC */	bne .L_80434D68
/* 80434D90 00431CD0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80434D94 00431CD4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80434D98 00431CD8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80434D9C 00431CDC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80434DA0 00431CE0  7C 08 03 A6 */	mtlr r0
/* 80434DA4 00431CE4  38 21 00 20 */	addi r1, r1, 0x20
/* 80434DA8 00431CE8  4E 80 00 20 */	blr 
.endfn draw__Q29P2DScreen3MgrFR8GraphicsR14J2DGrafContext

.fn __ct__Q29P2DScreen10Mgr_tuningFv, global
/* 80434DAC 00431CEC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80434DB0 00431CF0  7C 08 02 A6 */	mflr r0
/* 80434DB4 00431CF4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80434DB8 00431CF8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80434DBC 00431CFC  7C 7F 1B 78 */	mr r31, r3
/* 80434DC0 00431D00  93 C1 00 08 */	stw r30, 8(r1)
/* 80434DC4 00431D04  4B C0 A6 B1 */	bl __ct__9J2DScreenFv
/* 80434DC8 00431D08  3C 60 80 4F */	lis r3, __vt__Q29P2DScreen3Mgr@ha
/* 80434DCC 00431D0C  3B DF 01 18 */	addi r30, r31, 0x118
/* 80434DD0 00431D10  38 03 C5 A0 */	addi r0, r3, __vt__Q29P2DScreen3Mgr@l
/* 80434DD4 00431D14  90 1F 00 00 */	stw r0, 0(r31)
/* 80434DD8 00431D18  7F C3 F3 78 */	mr r3, r30
/* 80434DDC 00431D1C  4B FD C5 B5 */	bl __ct__5CNodeFv
/* 80434DE0 00431D20  3C 80 80 4D */	lis r4, __vt__Q29P2DScreen4Node@ha
/* 80434DE4 00431D24  3C 60 80 4F */	lis r3, __vt__Q29P2DScreen10Mgr_tuning@ha
/* 80434DE8 00431D28  38 04 7B 0C */	addi r0, r4, __vt__Q29P2DScreen4Node@l
/* 80434DEC 00431D2C  38 80 00 00 */	li r4, 0
/* 80434DF0 00431D30  90 1E 00 00 */	stw r0, 0(r30)
/* 80434DF4 00431D34  38 03 C5 00 */	addi r0, r3, __vt__Q29P2DScreen10Mgr_tuning@l
/* 80434DF8 00431D38  C0 22 24 44 */	lfs f1, lbl_805207A4@sda21(r2)
/* 80434DFC 00431D3C  7F E3 FB 78 */	mr r3, r31
/* 80434E00 00431D40  90 9E 00 18 */	stw r4, 0x18(r30)
/* 80434E04 00431D44  C0 02 24 48 */	lfs f0, lbl_805207A8@sda21(r2)
/* 80434E08 00431D48  90 1F 00 00 */	stw r0, 0(r31)
/* 80434E0C 00431D4C  D0 3F 01 38 */	stfs f1, 0x138(r31)
/* 80434E10 00431D50  D0 3F 01 3C */	stfs f1, 0x13c(r31)
/* 80434E14 00431D54  D0 1F 01 40 */	stfs f0, 0x140(r31)
/* 80434E18 00431D58  D0 1F 01 44 */	stfs f0, 0x144(r31)
/* 80434E1C 00431D5C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80434E20 00431D60  83 C1 00 08 */	lwz r30, 8(r1)
/* 80434E24 00431D64  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80434E28 00431D68  7C 08 03 A6 */	mtlr r0
/* 80434E2C 00431D6C  38 21 00 10 */	addi r1, r1, 0x10
/* 80434E30 00431D70  4E 80 00 20 */	blr 
.endfn __ct__Q29P2DScreen10Mgr_tuningFv
