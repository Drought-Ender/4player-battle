.include "macros.inc"
.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_80484850, local
	.float 0.4
	.float 0.55
	.float 1.0
.endobj lbl_80484850
.obj lbl_8048485C, local
	.float 0.2
	.float 0.35
	.float 0.5
.endobj lbl_8048485C

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj __vt__Q24Game10RumbleNode, weak
	.4byte 0
	.4byte 0
	.4byte __dt__Q24Game10RumbleNodeFv
	.4byte getChildCount__5CNodeFv
.endobj __vt__Q24Game10RumbleNode

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_8051A968, local
	.float 0.0
.endobj lbl_8051A968
.obj lbl_8051A96C, local
	.float 1.0
.endobj lbl_8051A96C
.obj lbl_8051A970, local
	.float 3.0
.endobj lbl_8051A970
.obj lbl_8051A974, local
	.float 30.0
.endobj lbl_8051A974

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q24Game10ContRumbleFii, global
/* 80252B20 0024FA60  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80252B24 0024FA64  7C 08 02 A6 */	mflr r0
/* 80252B28 0024FA68  90 01 00 44 */	stw r0, 0x44(r1)
/* 80252B2C 0024FA6C  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 80252B30 0024FA70  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 80252B34 0024FA74  BF 21 00 14 */	stmw r25, 0x14(r1)
/* 80252B38 0024FA78  7C 7E 1B 78 */	mr r30, r3
/* 80252B3C 0024FA7C  38 00 00 01 */	li r0, 1
/* 80252B40 0024FA80  98 03 00 00 */	stb r0, 0(r3)
/* 80252B44 0024FA84  7C BF 2B 78 */	mr r31, r5
/* 80252B48 0024FA88  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 80252B4C 0024FA8C  38 60 00 30 */	li r3, 0x30
/* 80252B50 0024FA90  90 9E 00 04 */	stw r4, 4(r30)
/* 80252B54 0024FA94  D0 1E 00 08 */	stfs f0, 8(r30)
/* 80252B58 0024FA98  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 80252B5C 0024FA9C  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 80252B60 0024FAA0  4B DD 13 45 */	bl __nw__FUl
/* 80252B64 0024FAA4  7C 7B 1B 79 */	or. r27, r3, r3
/* 80252B68 0024FAA8  41 82 00 38 */	beq .L_80252BA0
/* 80252B6C 0024FAAC  48 1B E8 25 */	bl __ct__5CNodeFv
/* 80252B70 0024FAB0  3C 80 80 4C */	lis r4, __vt__Q24Game10RumbleNode@ha
/* 80252B74 0024FAB4  38 60 FF FF */	li r3, -1
/* 80252B78 0024FAB8  38 04 1B E8 */	addi r0, r4, __vt__Q24Game10RumbleNode@l
/* 80252B7C 0024FABC  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 80252B80 0024FAC0  90 1B 00 00 */	stw r0, 0(r27)
/* 80252B84 0024FAC4  38 00 00 00 */	li r0, 0
/* 80252B88 0024FAC8  90 7B 00 18 */	stw r3, 0x18(r27)
/* 80252B8C 0024FACC  D0 1B 00 1C */	stfs f0, 0x1c(r27)
/* 80252B90 0024FAD0  D0 1B 00 20 */	stfs f0, 0x20(r27)
/* 80252B94 0024FAD4  D0 1B 00 24 */	stfs f0, 0x24(r27)
/* 80252B98 0024FAD8  D0 1B 00 28 */	stfs f0, 0x28(r27)
/* 80252B9C 0024FADC  90 1B 00 2C */	stw r0, 0x2c(r27)
.L_80252BA0:
/* 80252BA0 0024FAE0  93 7E 00 14 */	stw r27, 0x14(r30)
/* 80252BA4 0024FAE4  38 60 00 30 */	li r3, 0x30
/* 80252BA8 0024FAE8  4B DD 12 FD */	bl __nw__FUl
/* 80252BAC 0024FAEC  7C 7B 1B 79 */	or. r27, r3, r3
/* 80252BB0 0024FAF0  41 82 00 38 */	beq .L_80252BE8
/* 80252BB4 0024FAF4  48 1B E7 DD */	bl __ct__5CNodeFv
/* 80252BB8 0024FAF8  3C 80 80 4C */	lis r4, __vt__Q24Game10RumbleNode@ha
/* 80252BBC 0024FAFC  38 60 FF FF */	li r3, -1
/* 80252BC0 0024FB00  38 04 1B E8 */	addi r0, r4, __vt__Q24Game10RumbleNode@l
/* 80252BC4 0024FB04  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 80252BC8 0024FB08  90 1B 00 00 */	stw r0, 0(r27)
/* 80252BCC 0024FB0C  38 00 00 00 */	li r0, 0
/* 80252BD0 0024FB10  90 7B 00 18 */	stw r3, 0x18(r27)
/* 80252BD4 0024FB14  D0 1B 00 1C */	stfs f0, 0x1c(r27)
/* 80252BD8 0024FB18  D0 1B 00 20 */	stfs f0, 0x20(r27)
/* 80252BDC 0024FB1C  D0 1B 00 24 */	stfs f0, 0x24(r27)
/* 80252BE0 0024FB20  D0 1B 00 28 */	stfs f0, 0x28(r27)
/* 80252BE4 0024FB24  90 1B 00 2C */	stw r0, 0x2c(r27)
.L_80252BE8:
/* 80252BE8 0024FB28  3C 60 80 4C */	lis r3, __vt__Q24Game10RumbleNode@ha
/* 80252BEC 0024FB2C  93 7E 00 18 */	stw r27, 0x18(r30)
/* 80252BF0 0024FB30  C3 E2 C6 08 */	lfs f31, lbl_8051A968@sda21(r2)
/* 80252BF4 0024FB34  3B 63 1B E8 */	addi r27, r3, __vt__Q24Game10RumbleNode@l
/* 80252BF8 0024FB38  3B 20 00 00 */	li r25, 0
/* 80252BFC 0024FB3C  3B 80 FF FF */	li r28, -1
/* 80252C00 0024FB40  3B A0 00 00 */	li r29, 0
/* 80252C04 0024FB44  48 00 00 44 */	b .L_80252C48
.L_80252C08:
/* 80252C08 0024FB48  38 60 00 30 */	li r3, 0x30
/* 80252C0C 0024FB4C  4B DD 12 99 */	bl __nw__FUl
/* 80252C10 0024FB50  7C 7A 1B 79 */	or. r26, r3, r3
/* 80252C14 0024FB54  41 82 00 24 */	beq .L_80252C38
/* 80252C18 0024FB58  48 1B E7 79 */	bl __ct__5CNodeFv
/* 80252C1C 0024FB5C  93 7A 00 00 */	stw r27, 0(r26)
/* 80252C20 0024FB60  93 9A 00 18 */	stw r28, 0x18(r26)
/* 80252C24 0024FB64  D3 FA 00 1C */	stfs f31, 0x1c(r26)
/* 80252C28 0024FB68  D3 FA 00 20 */	stfs f31, 0x20(r26)
/* 80252C2C 0024FB6C  D3 FA 00 24 */	stfs f31, 0x24(r26)
/* 80252C30 0024FB70  D3 FA 00 28 */	stfs f31, 0x28(r26)
/* 80252C34 0024FB74  93 BA 00 2C */	stw r29, 0x2c(r26)
.L_80252C38:
/* 80252C38 0024FB78  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 80252C3C 0024FB7C  7F 44 D3 78 */	mr r4, r26
/* 80252C40 0024FB80  48 1B E7 C9 */	bl add__5CNodeFP5CNode
/* 80252C44 0024FB84  3B 39 00 01 */	addi r25, r25, 1
.L_80252C48:
/* 80252C48 0024FB88  7C 19 F8 00 */	cmpw r25, r31
/* 80252C4C 0024FB8C  41 80 FF BC */	blt .L_80252C08
/* 80252C50 0024FB90  38 00 00 00 */	li r0, 0
/* 80252C54 0024FB94  7F C3 F3 78 */	mr r3, r30
/* 80252C58 0024FB98  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 80252C5C 0024FB9C  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 80252C60 0024FBA0  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 80252C64 0024FBA4  BB 21 00 14 */	lmw r25, 0x14(r1)
/* 80252C68 0024FBA8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80252C6C 0024FBAC  7C 08 03 A6 */	mtlr r0
/* 80252C70 0024FBB0  38 21 00 40 */	addi r1, r1, 0x40
/* 80252C74 0024FBB4  4E 80 00 20 */	blr 
.endfn __ct__Q24Game10ContRumbleFii

.fn init__Q24Game10ContRumbleFv, global
/* 80252C78 0024FBB8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80252C7C 0024FBBC  7C 08 02 A6 */	mflr r0
/* 80252C80 0024FBC0  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 80252C84 0024FBC4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80252C88 0024FBC8  38 00 00 01 */	li r0, 1
/* 80252C8C 0024FBCC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80252C90 0024FBD0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80252C94 0024FBD4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80252C98 0024FBD8  7C 7D 1B 78 */	mr r29, r3
/* 80252C9C 0024FBDC  98 03 00 00 */	stb r0, 0(r3)
/* 80252CA0 0024FBE0  D0 03 00 08 */	stfs f0, 8(r3)
/* 80252CA4 0024FBE4  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80252CA8 0024FBE8  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 80252CAC 0024FBEC  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80252CB0 0024FBF0  83 C3 00 10 */	lwz r30, 0x10(r3)
/* 80252CB4 0024FBF4  48 00 00 20 */	b .L_80252CD4
.L_80252CB8:
/* 80252CB8 0024FBF8  83 FE 00 04 */	lwz r31, 4(r30)
/* 80252CBC 0024FBFC  7F C3 F3 78 */	mr r3, r30
/* 80252CC0 0024FC00  48 1B E9 11 */	bl del__5CNodeFv
/* 80252CC4 0024FC04  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 80252CC8 0024FC08  7F C4 F3 78 */	mr r4, r30
/* 80252CCC 0024FC0C  48 1B E7 3D */	bl add__5CNodeFP5CNode
/* 80252CD0 0024FC10  7F FE FB 78 */	mr r30, r31
.L_80252CD4:
/* 80252CD4 0024FC14  28 1E 00 00 */	cmplwi r30, 0
/* 80252CD8 0024FC18  40 82 FF E0 */	bne .L_80252CB8
/* 80252CDC 0024FC1C  80 7D 00 04 */	lwz r3, 4(r29)
/* 80252CE0 0024FC20  38 80 00 02 */	li r4, 2
/* 80252CE4 0024FC24  4B EA 17 49 */	bl PADControlMotor
/* 80252CE8 0024FC28  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80252CEC 0024FC2C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80252CF0 0024FC30  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80252CF4 0024FC34  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80252CF8 0024FC38  7C 08 03 A6 */	mtlr r0
/* 80252CFC 0024FC3C  38 21 00 20 */	addi r1, r1, 0x20
/* 80252D00 0024FC40  4E 80 00 20 */	blr 
.endfn init__Q24Game10ContRumbleFv

.fn update__Q24Game10ContRumbleFv, global
/* 80252D04 0024FC44  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80252D08 0024FC48  7C 08 02 A6 */	mflr r0
/* 80252D0C 0024FC4C  90 01 00 44 */	stw r0, 0x44(r1)
/* 80252D10 0024FC50  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 80252D14 0024FC54  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 80252D18 0024FC58  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 80252D1C 0024FC5C  F3 C1 00 28 */	psq_st f30, 40(r1), 0, qr0
/* 80252D20 0024FC60  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80252D24 0024FC64  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80252D28 0024FC68  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80252D2C 0024FC6C  7C 7D 1B 78 */	mr r29, r3
/* 80252D30 0024FC70  C3 C2 C6 08 */	lfs f30, lbl_8051A968@sda21(r2)
/* 80252D34 0024FC74  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80252D38 0024FC78  FF E0 F0 90 */	fmr f31, f30
/* 80252D3C 0024FC7C  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80252D40 0024FC80  48 00 01 5C */	b .L_80252E9C
.L_80252D44:
/* 80252D44 0024FC84  83 E3 00 04 */	lwz r31, 4(r3)
/* 80252D48 0024FC88  7C 7E 1B 78 */	mr r30, r3
/* 80252D4C 0024FC8C  D3 E3 00 1C */	stfs f31, 0x1c(r3)
/* 80252D50 0024FC90  80 C3 00 2C */	lwz r6, 0x2c(r3)
/* 80252D54 0024FC94  28 06 00 00 */	cmplwi r6, 0
/* 80252D58 0024FC98  41 82 00 A0 */	beq .L_80252DF8
/* 80252D5C 0024FC9C  80 66 00 00 */	lwz r3, 0(r6)
/* 80252D60 0024FCA0  38 80 00 00 */	li r4, 0
/* 80252D64 0024FCA4  7C 85 23 78 */	mr r5, r4
/* 80252D68 0024FCA8  34 03 FF FF */	addic. r0, r3, -1
/* 80252D6C 0024FCAC  7C 09 03 A6 */	mtctr r0
/* 80252D70 0024FCB0  40 81 00 74 */	ble .L_80252DE4
.L_80252D74:
/* 80252D74 0024FCB4  80 66 00 04 */	lwz r3, 4(r6)
/* 80252D78 0024FCB8  38 04 00 01 */	addi r0, r4, 1
/* 80252D7C 0024FCBC  C0 3E 00 24 */	lfs f1, 0x24(r30)
/* 80252D80 0024FCC0  7C 03 2C 2E */	lfsx f0, r3, r5
/* 80252D84 0024FCC4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80252D88 0024FCC8  4C 41 13 82 */	cror 2, 1, 2
/* 80252D8C 0024FCCC  40 82 00 4C */	bne .L_80252DD8
/* 80252D90 0024FCD0  54 00 10 3A */	slwi r0, r0, 2
/* 80252D94 0024FCD4  7C 63 04 2E */	lfsx f3, r3, r0
/* 80252D98 0024FCD8  FC 01 18 40 */	fcmpo cr0, f1, f3
/* 80252D9C 0024FCDC  40 80 00 3C */	bge .L_80252DD8
/* 80252DA0 0024FCE0  54 85 10 3A */	slwi r5, r4, 2
/* 80252DA4 0024FCE4  80 86 00 08 */	lwz r4, 8(r6)
/* 80252DA8 0024FCE8  7C A3 2C 2E */	lfsx f5, r3, r5
/* 80252DAC 0024FCEC  C0 42 C6 0C */	lfs f2, lbl_8051A96C@sda21(r2)
/* 80252DB0 0024FCF0  EC 81 28 28 */	fsubs f4, f1, f5
/* 80252DB4 0024FCF4  7C 04 04 2E */	lfsx f0, r4, r0
/* 80252DB8 0024FCF8  EC 63 28 28 */	fsubs f3, f3, f5
/* 80252DBC 0024FCFC  7C 24 2C 2E */	lfsx f1, r4, r5
/* 80252DC0 0024FD00  EC 64 18 24 */	fdivs f3, f4, f3
/* 80252DC4 0024FD04  EC 42 18 28 */	fsubs f2, f2, f3
/* 80252DC8 0024FD08  EC 03 00 32 */	fmuls f0, f3, f0
/* 80252DCC 0024FD0C  EC 02 00 7A */	fmadds f0, f2, f1, f0
/* 80252DD0 0024FD10  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 80252DD4 0024FD14  48 00 00 10 */	b .L_80252DE4
.L_80252DD8:
/* 80252DD8 0024FD18  38 A5 00 04 */	addi r5, r5, 4
/* 80252DDC 0024FD1C  38 84 00 01 */	addi r4, r4, 1
/* 80252DE0 0024FD20  42 00 FF 94 */	bdnz .L_80252D74
.L_80252DE4:
/* 80252DE4 0024FD24  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 80252DE8 0024FD28  C0 1E 00 20 */	lfs f0, 0x20(r30)
/* 80252DEC 0024FD2C  EC 01 00 32 */	fmuls f0, f1, f0
/* 80252DF0 0024FD30  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 80252DF4 0024FD34  48 00 00 0C */	b .L_80252E00
.L_80252DF8:
/* 80252DF8 0024FD38  C0 03 00 20 */	lfs f0, 0x20(r3)
/* 80252DFC 0024FD3C  D0 03 00 1C */	stfs f0, 0x1c(r3)
.L_80252E00:
/* 80252E00 0024FD40  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 80252E04 0024FD44  C0 3E 00 24 */	lfs f1, 0x24(r30)
/* 80252E08 0024FD48  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 80252E0C 0024FD4C  EC 01 00 2A */	fadds f0, f1, f0
/* 80252E10 0024FD50  D0 1E 00 24 */	stfs f0, 0x24(r30)
/* 80252E14 0024FD54  C0 1E 00 1C */	lfs f0, 0x1c(r30)
/* 80252E18 0024FD58  FC 1E 00 40 */	fcmpo cr0, f30, f0
/* 80252E1C 0024FD5C  40 80 00 08 */	bge .L_80252E24
/* 80252E20 0024FD60  FF C0 00 90 */	fmr f30, f0
.L_80252E24:
/* 80252E24 0024FD64  80 9E 00 2C */	lwz r4, 0x2c(r30)
/* 80252E28 0024FD68  28 04 00 00 */	cmplwi r4, 0
/* 80252E2C 0024FD6C  41 82 00 34 */	beq .L_80252E60
/* 80252E30 0024FD70  80 04 00 00 */	lwz r0, 0(r4)
/* 80252E34 0024FD74  2C 00 00 00 */	cmpwi r0, 0
/* 80252E38 0024FD78  40 81 00 40 */	ble .L_80252E78
/* 80252E3C 0024FD7C  54 03 10 3A */	slwi r3, r0, 2
/* 80252E40 0024FD80  80 84 00 04 */	lwz r4, 4(r4)
/* 80252E44 0024FD84  38 03 FF FC */	addi r0, r3, -4
/* 80252E48 0024FD88  C0 3E 00 24 */	lfs f1, 0x24(r30)
/* 80252E4C 0024FD8C  7C 04 04 2E */	lfsx f0, r4, r0
/* 80252E50 0024FD90  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80252E54 0024FD94  40 80 00 24 */	bge .L_80252E78
/* 80252E58 0024FD98  38 00 00 00 */	li r0, 0
/* 80252E5C 0024FD9C  48 00 00 20 */	b .L_80252E7C
.L_80252E60:
/* 80252E60 0024FDA0  C0 3E 00 24 */	lfs f1, 0x24(r30)
/* 80252E64 0024FDA4  C0 1E 00 28 */	lfs f0, 0x28(r30)
/* 80252E68 0024FDA8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80252E6C 0024FDAC  40 80 00 0C */	bge .L_80252E78
/* 80252E70 0024FDB0  38 00 00 00 */	li r0, 0
/* 80252E74 0024FDB4  48 00 00 08 */	b .L_80252E7C
.L_80252E78:
/* 80252E78 0024FDB8  38 00 00 01 */	li r0, 1
.L_80252E7C:
/* 80252E7C 0024FDBC  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 80252E80 0024FDC0  41 82 00 18 */	beq .L_80252E98
/* 80252E84 0024FDC4  7F C3 F3 78 */	mr r3, r30
/* 80252E88 0024FDC8  48 1B E7 49 */	bl del__5CNodeFv
/* 80252E8C 0024FDCC  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 80252E90 0024FDD0  7F C4 F3 78 */	mr r4, r30
/* 80252E94 0024FDD4  48 1B E5 75 */	bl add__5CNodeFP5CNode
.L_80252E98:
/* 80252E98 0024FDD8  7F E3 FB 78 */	mr r3, r31
.L_80252E9C:
/* 80252E9C 0024FDDC  28 03 00 00 */	cmplwi r3, 0
/* 80252EA0 0024FDE0  40 82 FE A4 */	bne .L_80252D44
/* 80252EA4 0024FDE4  C0 62 C6 08 */	lfs f3, lbl_8051A968@sda21(r2)
/* 80252EA8 0024FDE8  FC 1E 18 40 */	fcmpo cr0, f30, f3
/* 80252EAC 0024FDEC  40 81 00 78 */	ble .L_80252F24
/* 80252EB0 0024FDF0  C0 3D 00 08 */	lfs f1, 8(r29)
/* 80252EB4 0024FDF4  C0 02 C6 0C */	lfs f0, lbl_8051A96C@sda21(r2)
/* 80252EB8 0024FDF8  EC 21 F0 2A */	fadds f1, f1, f30
/* 80252EBC 0024FDFC  D0 3D 00 08 */	stfs f1, 8(r29)
/* 80252EC0 0024FE00  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 80252EC4 0024FE04  C0 5D 00 0C */	lfs f2, 0xc(r29)
/* 80252EC8 0024FE08  C0 23 00 54 */	lfs f1, 0x54(r3)
/* 80252ECC 0024FE0C  EC 22 08 2A */	fadds f1, f2, f1
/* 80252ED0 0024FE10  D0 3D 00 0C */	stfs f1, 0xc(r29)
/* 80252ED4 0024FE14  D0 7D 00 10 */	stfs f3, 0x10(r29)
/* 80252ED8 0024FE18  C0 3D 00 08 */	lfs f1, 8(r29)
/* 80252EDC 0024FE1C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80252EE0 0024FE20  40 80 00 20 */	bge .L_80252F00
/* 80252EE4 0024FE24  88 1D 00 00 */	lbz r0, 0(r29)
/* 80252EE8 0024FE28  28 00 00 00 */	cmplwi r0, 0
/* 80252EEC 0024FE2C  41 82 00 7C */	beq .L_80252F68
/* 80252EF0 0024FE30  80 7D 00 04 */	lwz r3, 4(r29)
/* 80252EF4 0024FE34  38 80 00 00 */	li r4, 0
/* 80252EF8 0024FE38  4B EA 15 35 */	bl PADControlMotor
/* 80252EFC 0024FE3C  48 00 00 6C */	b .L_80252F68
.L_80252F00:
/* 80252F00 0024FE40  EC 01 00 28 */	fsubs f0, f1, f0
/* 80252F04 0024FE44  D0 1D 00 08 */	stfs f0, 8(r29)
/* 80252F08 0024FE48  88 1D 00 00 */	lbz r0, 0(r29)
/* 80252F0C 0024FE4C  28 00 00 00 */	cmplwi r0, 0
/* 80252F10 0024FE50  41 82 00 58 */	beq .L_80252F68
/* 80252F14 0024FE54  80 7D 00 04 */	lwz r3, 4(r29)
/* 80252F18 0024FE58  38 80 00 01 */	li r4, 1
/* 80252F1C 0024FE5C  4B EA 15 11 */	bl PADControlMotor
/* 80252F20 0024FE60  48 00 00 48 */	b .L_80252F68
.L_80252F24:
/* 80252F24 0024FE64  D0 7D 00 08 */	stfs f3, 8(r29)
/* 80252F28 0024FE68  C0 02 C6 10 */	lfs f0, lbl_8051A970@sda21(r2)
/* 80252F2C 0024FE6C  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 80252F30 0024FE70  C0 5D 00 10 */	lfs f2, 0x10(r29)
/* 80252F34 0024FE74  C0 23 00 54 */	lfs f1, 0x54(r3)
/* 80252F38 0024FE78  EC 22 08 2A */	fadds f1, f2, f1
/* 80252F3C 0024FE7C  D0 3D 00 10 */	stfs f1, 0x10(r29)
/* 80252F40 0024FE80  C0 3D 00 10 */	lfs f1, 0x10(r29)
/* 80252F44 0024FE84  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80252F48 0024FE88  40 81 00 08 */	ble .L_80252F50
/* 80252F4C 0024FE8C  D0 7D 00 0C */	stfs f3, 0xc(r29)
.L_80252F50:
/* 80252F50 0024FE90  88 1D 00 00 */	lbz r0, 0(r29)
/* 80252F54 0024FE94  28 00 00 00 */	cmplwi r0, 0
/* 80252F58 0024FE98  41 82 00 10 */	beq .L_80252F68
/* 80252F5C 0024FE9C  80 7D 00 04 */	lwz r3, 4(r29)
/* 80252F60 0024FEA0  38 80 00 02 */	li r4, 2
/* 80252F64 0024FEA4  4B EA 14 C9 */	bl PADControlMotor
.L_80252F68:
/* 80252F68 0024FEA8  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 80252F6C 0024FEAC  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 80252F70 0024FEB0  E3 C1 00 28 */	psq_l f30, 40(r1), 0, qr0
/* 80252F74 0024FEB4  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 80252F78 0024FEB8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80252F7C 0024FEBC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80252F80 0024FEC0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80252F84 0024FEC4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80252F88 0024FEC8  7C 08 03 A6 */	mtlr r0
/* 80252F8C 0024FECC  38 21 00 40 */	addi r1, r1, 0x40
/* 80252F90 0024FED0  4E 80 00 20 */	blr 
.endfn update__Q24Game10ContRumbleFv

.fn setController__Q24Game10ContRumbleFb, global
/* 80252F94 0024FED4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80252F98 0024FED8  7C 08 02 A6 */	mflr r0
/* 80252F9C 0024FEDC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80252FA0 0024FEE0  54 80 06 3F */	clrlwi. r0, r4, 0x18
/* 80252FA4 0024FEE4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80252FA8 0024FEE8  7C 9F 23 78 */	mr r31, r4
/* 80252FAC 0024FEEC  93 C1 00 08 */	stw r30, 8(r1)
/* 80252FB0 0024FEF0  7C 7E 1B 78 */	mr r30, r3
/* 80252FB4 0024FEF4  40 82 00 1C */	bne .L_80252FD0
/* 80252FB8 0024FEF8  88 1E 00 00 */	lbz r0, 0(r30)
/* 80252FBC 0024FEFC  28 00 00 00 */	cmplwi r0, 0
/* 80252FC0 0024FF00  41 82 00 10 */	beq .L_80252FD0
/* 80252FC4 0024FF04  80 7E 00 04 */	lwz r3, 4(r30)
/* 80252FC8 0024FF08  38 80 00 02 */	li r4, 2
/* 80252FCC 0024FF0C  4B EA 14 61 */	bl PADControlMotor
.L_80252FD0:
/* 80252FD0 0024FF10  9B FE 00 00 */	stb r31, 0(r30)
/* 80252FD4 0024FF14  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80252FD8 0024FF18  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80252FDC 0024FF1C  83 C1 00 08 */	lwz r30, 8(r1)
/* 80252FE0 0024FF20  7C 08 03 A6 */	mtlr r0
/* 80252FE4 0024FF24  38 21 00 10 */	addi r1, r1, 0x10
/* 80252FE8 0024FF28  4E 80 00 20 */	blr 
.endfn setController__Q24Game10ContRumbleFb

.fn startRumble__Q24Game10ContRumbleFif, global
/* 80252FEC 0024FF2C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80252FF0 0024FF30  7C 08 02 A6 */	mflr r0
/* 80252FF4 0024FF34  90 01 00 24 */	stw r0, 0x24(r1)
/* 80252FF8 0024FF38  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80252FFC 0024FF3C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80253000 0024FF40  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80253004 0024FF44  7C 9D 23 78 */	mr r29, r4
/* 80253008 0024FF48  93 81 00 10 */	stw r28, 0x10(r1)
/* 8025300C 0024FF4C  7C 7C 1B 78 */	mr r28, r3
/* 80253010 0024FF50  D0 21 00 08 */	stfs f1, 8(r1)
/* 80253014 0024FF54  80 63 00 18 */	lwz r3, 0x18(r3)
/* 80253018 0024FF58  80 03 00 10 */	lwz r0, 0x10(r3)
/* 8025301C 0024FF5C  28 00 00 00 */	cmplwi r0, 0
/* 80253020 0024FF60  41 82 00 B0 */	beq .L_802530D0
/* 80253024 0024FF64  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 80253028 0024FF68  28 03 00 00 */	cmplwi r3, 0
/* 8025302C 0024FF6C  41 82 00 A4 */	beq .L_802530D0
/* 80253030 0024FF70  C0 3C 00 0C */	lfs f1, 0xc(r28)
/* 80253034 0024FF74  C0 02 C6 14 */	lfs f0, lbl_8051A974@sda21(r2)
/* 80253038 0024FF78  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8025303C 0024FF7C  40 80 00 94 */	bge .L_802530D0
/* 80253040 0024FF80  48 00 E3 99 */	bl getRumbleData__Q24Game13RumbleDataMgrFi
/* 80253044 0024FF84  80 9C 00 18 */	lwz r4, 0x18(r28)
/* 80253048 0024FF88  7C 7F 1B 78 */	mr r31, r3
/* 8025304C 0024FF8C  83 C4 00 10 */	lwz r30, 0x10(r4)
/* 80253050 0024FF90  7F C3 F3 78 */	mr r3, r30
/* 80253054 0024FF94  48 1B E5 7D */	bl del__5CNodeFv
/* 80253058 0024FF98  28 1F 00 00 */	cmplwi r31, 0
/* 8025305C 0024FF9C  41 82 00 28 */	beq .L_80253084
/* 80253060 0024FFA0  C0 21 00 08 */	lfs f1, 8(r1)
/* 80253064 0024FFA4  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 80253068 0024FFA8  93 BE 00 18 */	stw r29, 0x18(r30)
/* 8025306C 0024FFAC  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 80253070 0024FFB0  D0 3E 00 20 */	stfs f1, 0x20(r30)
/* 80253074 0024FFB4  D0 1E 00 24 */	stfs f0, 0x24(r30)
/* 80253078 0024FFB8  D0 1E 00 28 */	stfs f0, 0x28(r30)
/* 8025307C 0024FFBC  93 FE 00 2C */	stw r31, 0x2c(r30)
/* 80253080 0024FFC0  48 00 00 44 */	b .L_802530C4
.L_80253084:
/* 80253084 0024FFC4  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 80253088 0024FFC8  7F 83 E3 78 */	mr r3, r28
# /* 8025308C 0024FFCC  7F A4 EB 78 */	mr r4, r29
li r4, 0
/* 80253090 0024FFD0  38 A1 00 08 */	addi r5, r1, 8
/* 80253094 0024FFD4  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 80253098 0024FFD8  38 C1 00 0C */	addi r6, r1, 0xc
/* 8025309C 0024FFDC  48 00 01 6D */	bl getRumbleParameter__Q24Game10ContRumbleFiRfRf
/* 802530A0 0024FFE0  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 802530A4 0024FFE4  C0 21 00 08 */	lfs f1, 8(r1)
/* 802530A8 0024FFE8  C0 02 C6 08 */	lfs f0, lbl_8051A968@sda21(r2)
/* 802530AC 0024FFEC  93 BE 00 18 */	stw r29, 0x18(r30)
/* 802530B0 0024FFF0  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 802530B4 0024FFF4  D0 3E 00 20 */	stfs f1, 0x20(r30)
/* 802530B8 0024FFF8  D0 1E 00 24 */	stfs f0, 0x24(r30)
/* 802530BC 0024FFFC  D0 5E 00 28 */	stfs f2, 0x28(r30)
/* 802530C0 00250000  93 FE 00 2C */	stw r31, 0x2c(r30)
.L_802530C4:
/* 802530C4 00250004  80 7C 00 14 */	lwz r3, 0x14(r28)
/* 802530C8 00250008  7F C4 F3 78 */	mr r4, r30
/* 802530CC 0025000C  48 1B E3 3D */	bl add__5CNodeFP5CNode
.L_802530D0:
/* 802530D0 00250010  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802530D4 00250014  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802530D8 00250018  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802530DC 0025001C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802530E0 00250020  83 81 00 10 */	lwz r28, 0x10(r1)
/* 802530E4 00250024  7C 08 03 A6 */	mtlr r0
/* 802530E8 00250028  38 21 00 20 */	addi r1, r1, 0x20
/* 802530EC 0025002C  4E 80 00 20 */	blr 
.endfn startRumble__Q24Game10ContRumbleFif

.fn rumbleStop__Q24Game10ContRumbleFv, global
/* 802530F0 00250030  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802530F4 00250034  7C 08 02 A6 */	mflr r0
/* 802530F8 00250038  90 01 00 24 */	stw r0, 0x24(r1)
/* 802530FC 0025003C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80253100 00250040  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80253104 00250044  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80253108 00250048  93 81 00 10 */	stw r28, 0x10(r1)
/* 8025310C 0025004C  7C 7C 1B 78 */	mr r28, r3
/* 80253110 00250050  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80253114 00250054  83 E3 00 10 */	lwz r31, 0x10(r3)
/* 80253118 00250058  7F FD FB 78 */	mr r29, r31
/* 8025311C 0025005C  48 00 00 20 */	b .L_8025313C
.L_80253120:
/* 80253120 00250060  83 DD 00 04 */	lwz r30, 4(r29)
/* 80253124 00250064  7F A3 EB 78 */	mr r3, r29
/* 80253128 00250068  48 1B E4 A9 */	bl del__5CNodeFv
/* 8025312C 0025006C  80 7C 00 18 */	lwz r3, 0x18(r28)
/* 80253130 00250070  7F A4 EB 78 */	mr r4, r29
/* 80253134 00250074  48 1B E2 D5 */	bl add__5CNodeFP5CNode
/* 80253138 00250078  7F DD F3 78 */	mr r29, r30
.L_8025313C:
/* 8025313C 0025007C  28 1D 00 00 */	cmplwi r29, 0
/* 80253140 00250080  40 82 FF E0 */	bne .L_80253120
/* 80253144 00250084  28 1F 00 00 */	cmplwi r31, 0
/* 80253148 00250088  41 82 00 10 */	beq .L_80253158
/* 8025314C 0025008C  80 7C 00 04 */	lwz r3, 4(r28)
/* 80253150 00250090  38 80 00 02 */	li r4, 2
/* 80253154 00250094  4B EA 12 D9 */	bl PADControlMotor
.L_80253158:
/* 80253158 00250098  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8025315C 0025009C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80253160 002500A0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80253164 002500A4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80253168 002500A8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8025316C 002500AC  7C 08 03 A6 */	mtlr r0
/* 80253170 002500B0  38 21 00 20 */	addi r1, r1, 0x20
/* 80253174 002500B4  4E 80 00 20 */	blr 
.endfn rumbleStop__Q24Game10ContRumbleFv

.fn rumbleStop__Q24Game10ContRumbleFi, global
/* 80253178 002500B8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8025317C 002500BC  7C 08 02 A6 */	mflr r0
/* 80253180 002500C0  90 01 00 24 */	stw r0, 0x24(r1)
/* 80253184 002500C4  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 80253188 002500C8  7C 7B 1B 78 */	mr r27, r3
/* 8025318C 002500CC  7C 9C 23 78 */	mr r28, r4
/* 80253190 002500D0  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80253194 002500D4  83 E3 00 10 */	lwz r31, 0x10(r3)
/* 80253198 002500D8  7F FD FB 78 */	mr r29, r31
/* 8025319C 002500DC  48 00 00 2C */	b .L_802531C8
.L_802531A0:
/* 802531A0 002500E0  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 802531A4 002500E4  83 DD 00 04 */	lwz r30, 4(r29)
/* 802531A8 002500E8  7C 00 E0 00 */	cmpw r0, r28
/* 802531AC 002500EC  40 82 00 18 */	bne .L_802531C4
/* 802531B0 002500F0  7F A3 EB 78 */	mr r3, r29
/* 802531B4 002500F4  48 1B E4 1D */	bl del__5CNodeFv
/* 802531B8 002500F8  80 7B 00 18 */	lwz r3, 0x18(r27)
/* 802531BC 002500FC  7F A4 EB 78 */	mr r4, r29
/* 802531C0 00250100  48 1B E2 49 */	bl add__5CNodeFP5CNode
.L_802531C4:
/* 802531C4 00250104  7F DD F3 78 */	mr r29, r30
.L_802531C8:
/* 802531C8 00250108  28 1D 00 00 */	cmplwi r29, 0
/* 802531CC 0025010C  40 82 FF D4 */	bne .L_802531A0
/* 802531D0 00250110  28 1F 00 00 */	cmplwi r31, 0
/* 802531D4 00250114  41 82 00 20 */	beq .L_802531F4
/* 802531D8 00250118  80 7B 00 14 */	lwz r3, 0x14(r27)
/* 802531DC 0025011C  80 03 00 10 */	lwz r0, 0x10(r3)
/* 802531E0 00250120  28 00 00 00 */	cmplwi r0, 0
/* 802531E4 00250124  41 82 00 10 */	beq .L_802531F4
/* 802531E8 00250128  80 7B 00 04 */	lwz r3, 4(r27)
/* 802531EC 0025012C  38 80 00 02 */	li r4, 2
/* 802531F0 00250130  4B EA 12 3D */	bl PADControlMotor
.L_802531F4:
/* 802531F4 00250134  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 802531F8 00250138  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802531FC 0025013C  7C 08 03 A6 */	mtlr r0
/* 80253200 00250140  38 21 00 20 */	addi r1, r1, 0x20
/* 80253204 00250144  4E 80 00 20 */	blr 
.endfn rumbleStop__Q24Game10ContRumbleFi

.fn getRumbleParameter__Q24Game10ContRumbleFiRfRf, global
/* 80253208 00250148  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8025320C 0025014C  3C 60 55 55 */	lis r3, 0x55555556@ha
/* 80253210 00250150  3C E0 80 48 */	lis r7, lbl_80484850@ha
/* 80253214 00250154  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80253218 00250158  3B E4 FF F8 */	addi r31, r4, -8
/* 8025321C 0025015C  39 47 48 50 */	addi r10, r7, lbl_80484850@l
/* 80253220 00250160  38 03 55 56 */	addi r0, r3, 0x55555556@l
/* 80253224 00250164  7C E0 F8 96 */	mulhw r7, r0, r31
/* 80253228 00250168  81 2A 00 00 */	lwz r9, 0(r10)
/* 8025322C 0025016C  81 8A 00 04 */	lwz r12, 4(r10)
/* 80253230 00250170  3C 80 80 48 */	lis r4, lbl_8048485C@ha
/* 80253234 00250174  81 6A 00 08 */	lwz r11, 8(r10)
/* 80253238 00250178  38 61 00 08 */	addi r3, r1, 8
/* 8025323C 0025017C  39 04 48 5C */	addi r8, r4, lbl_8048485C@l
/* 80253240 00250180  54 E0 0F FE */	srwi r0, r7, 0x1f
/* 80253244 00250184  7C E7 02 14 */	add r7, r7, r0
/* 80253248 00250188  91 21 00 14 */	stw r9, 0x14(r1)
/* 8025324C 0025018C  1C 07 00 03 */	mulli r0, r7, 3
/* 80253250 00250190  81 48 00 00 */	lwz r10, 0(r8)
/* 80253254 00250194  81 28 00 04 */	lwz r9, 4(r8)
/* 80253258 00250198  38 81 00 14 */	addi r4, r1, 0x14
/* 8025325C 0025019C  81 08 00 08 */	lwz r8, 8(r8)
/* 80253260 002501A0  54 E7 10 3A */	slwi r7, r7, 2
/* 80253264 002501A4  7C 00 F8 50 */	subf r0, r0, r31
/* 80253268 002501A8  91 81 00 18 */	stw r12, 0x18(r1)
/* 8025326C 002501AC  C0 25 00 00 */	lfs f1, 0(r5)
/* 80253270 002501B0  54 00 10 3A */	slwi r0, r0, 2
/* 80253274 002501B4  91 61 00 1C */	stw r11, 0x1c(r1)
/* 80253278 002501B8  7C 04 3C 2E */	lfsx f0, r4, r7
/* 8025327C 002501BC  91 41 00 08 */	stw r10, 8(r1)
/* 80253280 002501C0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80253284 002501C4  91 21 00 0C */	stw r9, 0xc(r1)
/* 80253288 002501C8  91 01 00 10 */	stw r8, 0x10(r1)
/* 8025328C 002501CC  D0 05 00 00 */	stfs f0, 0(r5)
/* 80253290 002501D0  7C 03 04 2E */	lfsx f0, r3, r0
/* 80253294 002501D4  D0 06 00 00 */	stfs f0, 0(r6)
/* 80253298 002501D8  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8025329C 002501DC  38 21 00 30 */	addi r1, r1, 0x30
/* 802532A0 002501E0  4E 80 00 20 */	blr 
.endfn getRumbleParameter__Q24Game10ContRumbleFiRfRf

.fn __dt__Q24Game10RumbleNodeFv, weak
/* 802532A4 002501E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802532A8 002501E8  7C 08 02 A6 */	mflr r0
/* 802532AC 002501EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802532B0 002501F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802532B4 002501F4  7C 9F 23 78 */	mr r31, r4
/* 802532B8 002501F8  93 C1 00 08 */	stw r30, 8(r1)
/* 802532BC 002501FC  7C 7E 1B 79 */	or. r30, r3, r3
/* 802532C0 00250200  41 82 00 28 */	beq .L_802532E8
/* 802532C4 00250204  3C A0 80 4C */	lis r5, __vt__Q24Game10RumbleNode@ha
/* 802532C8 00250208  38 80 00 00 */	li r4, 0
/* 802532CC 0025020C  38 05 1B E8 */	addi r0, r5, __vt__Q24Game10RumbleNode@l
/* 802532D0 00250210  90 1E 00 00 */	stw r0, 0(r30)
/* 802532D4 00250214  48 1B E2 B5 */	bl __dt__5CNodeFv
/* 802532D8 00250218  7F E0 07 35 */	extsh. r0, r31
/* 802532DC 0025021C  40 81 00 0C */	ble .L_802532E8
/* 802532E0 00250220  7F C3 F3 78 */	mr r3, r30
/* 802532E4 00250224  4B DD 0D D1 */	bl __dl__FPv
.L_802532E8:
/* 802532E8 00250228  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802532EC 0025022C  7F C3 F3 78 */	mr r3, r30
/* 802532F0 00250230  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802532F4 00250234  83 C1 00 08 */	lwz r30, 8(r1)
/* 802532F8 00250238  7C 08 03 A6 */	mtlr r0
/* 802532FC 0025023C  38 21 00 10 */	addi r1, r1, 0x10
/* 80253300 00250240  4E 80 00 20 */	blr 
.endfn __dt__Q24Game10RumbleNodeFv
