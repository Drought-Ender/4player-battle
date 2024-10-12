.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_creatureLOD_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_804807C8, local
	.asciz "creatureLOD.cpp"
.endobj lbl_804807C8
.balign 4
.obj lbl_804807D8, local
	.asciz "P2Assert"
.endobj lbl_804807D8
.balign 4
.obj lbl_804807E4, local
	.4byte lbl_80519758
	.4byte lbl_80519760
	.4byte lbl_80519764
.endobj lbl_804807E4
.balign 4
.obj lbl_804807F0, local
	.asciz "[%s%s %s %s]"
.endobj lbl_804807F0

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj gu32NAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gu32NAN___Q24Game5P2JST
.obj gfNAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gfNAN___Q24Game5P2JST
.obj drawInfo__Q24Game5AILOD, global
	.skip 0x1
.endobj drawInfo__Q24Game5AILOD

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_80519750, local
	.float 0.07
.endobj lbl_80519750
.balign 4
.obj lbl_80519754, local
	.float 0.02
.endobj lbl_80519754
.balign 4
.obj lbl_80519758, local
	.asciz "near"
.endobj lbl_80519758
.balign 4
.obj lbl_80519760, local
	.asciz "mid"
.endobj lbl_80519760
.balign 4
.obj lbl_80519764, local
	.asciz "far"
.endobj lbl_80519764
.balign 4
.obj lbl_80519768, local
	.float 1.0
.endobj lbl_80519768
.balign 4
.obj lbl_8051976C, local
	.asciz "p"
.endobj lbl_8051976C
.balign 4
.obj lbl_80519770, local
	.asciz "_"
.endobj lbl_80519770
.balign 4
.obj lbl_80519774, local
	.asciz "v"
.endobj lbl_80519774
.balign 4
.obj lbl_80519778, local
	.asciz "x"
.endobj lbl_80519778
.balign 4
.obj lbl_8051977C, local
	.float 15.0
.endobj lbl_8051977C
.balign 4
.obj lbl_80519780, local
	.asciz "<%f>"
.endobj lbl_80519780

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q24Game9AILODParmFv, global
/* 801D7808 001D4748  C0 22 B3 F0 */	lfs f1, lbl_80519750@sda21(r2)
/* 801D780C 001D474C  38 00 00 00 */	li r0, 0
/* 801D7810 001D4750  C0 02 B3 F4 */	lfs f0, lbl_80519754@sda21(r2)
/* 801D7814 001D4754  D0 23 00 00 */	stfs f1, 0(r3)
/* 801D7818 001D4758  D0 03 00 04 */	stfs f0, 4(r3)
/* 801D781C 001D475C  98 03 00 08 */	stb r0, 8(r3)
/* 801D7820 001D4760  4E 80 00 20 */	blr 
.endfn __ct__Q24Game9AILODParmFv

.fn __ct__Q24Game5AILODFv, global
/* 801D7824 001D4764  38 80 00 00 */	li r4, 0
/* 801D7828 001D4768  38 00 00 10 */	li r0, 0x10
/* 801D782C 001D476C  98 83 00 00 */	stb r4, 0(r3)
/* 801D7830 001D4770  98 83 00 01 */	stb r4, 1(r3)
/* 801D7834 001D4774  98 03 00 00 */	stb r0, 0(r3)
/* 801D7838 001D4778  4E 80 00 20 */	blr 
.endfn __ct__Q24Game5AILODFv

.fn "drawLODInfo__Q24Game8CreatureFR8GraphicsR10Vector3<f>", global
/* 801D7BE4 001D4B24  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 801D7BE8 001D4B28  7C 08 02 A6 */	mflr r0
/* 801D7BEC 001D4B2C  90 01 00 64 */	stw r0, 0x64(r1)
/* 801D7BF0 001D4B30  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 801D7BF4 001D4B34  7C BF 2B 78 */	mr r31, r5
/* 801D7BF8 001D4B38  93 C1 00 58 */	stw r30, 0x58(r1)
/* 801D7BFC 001D4B3C  7C 9E 23 78 */	mr r30, r4
/* 801D7C00 001D4B40  93 A1 00 54 */	stw r29, 0x54(r1)
/* 801D7C04 001D4B44  7C 7D 1B 78 */	mr r29, r3
/* 801D7C08 001D4B48  93 81 00 50 */	stw r28, 0x50(r1)
/* 801D7C0C 001D4B4C  88 0D 94 60 */	lbz r0, drawInfo__Q24Game5AILOD@sda21(r13)
/* 801D7C10 001D4B50  28 00 00 00 */	cmplwi r0, 0
/* 801D7C14 001D4B54  41 82 02 08 */	beq .L_801D7E1C
/* 801D7C18 001D4B58  80 6D 89 D8 */	lwz r3, systemFont__9JFWSystem@sda21(r13)
/* 801D7C1C 001D4B5C  38 C0 00 00 */	li r6, 0
/* 801D7C20 001D4B60  38 00 00 FF */	li r0, 0xff
/* 801D7C24 001D4B64  38 A0 00 66 */	li r5, 0x66
/* 801D7C28 001D4B68  C0 02 B4 08 */	lfs f0, lbl_80519768@sda21(r2)
/* 801D7C2C 001D4B6C  38 80 00 99 */	li r4, 0x99
/* 801D7C30 001D4B70  90 61 00 30 */	stw r3, 0x30(r1)
/* 801D7C34 001D4B74  7F C3 F3 78 */	mr r3, r30
/* 801D7C38 001D4B78  90 C1 00 34 */	stw r6, 0x34(r1)
/* 801D7C3C 001D4B7C  90 C1 00 38 */	stw r6, 0x38(r1)
/* 801D7C40 001D4B80  90 C1 00 3C */	stw r6, 0x3c(r1)
/* 801D7C44 001D4B84  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 801D7C48 001D4B88  98 A1 00 44 */	stb r5, 0x44(r1)
/* 801D7C4C 001D4B8C  98 81 00 45 */	stb r4, 0x45(r1)
/* 801D7C50 001D4B90  98 01 00 46 */	stb r0, 0x46(r1)
/* 801D7C54 001D4B94  98 01 00 47 */	stb r0, 0x47(r1)
/* 801D7C58 001D4B98  98 C1 00 48 */	stb r6, 0x48(r1)
/* 801D7C5C 001D4B9C  98 A1 00 49 */	stb r5, 0x49(r1)
/* 801D7C60 001D4BA0  98 01 00 4A */	stb r0, 0x4a(r1)
/* 801D7C64 001D4BA4  98 01 00 4B */	stb r0, 0x4b(r1)
/* 801D7C68 001D4BA8  80 9E 02 5C */	lwz r4, 0x25c(r30)
/* 801D7C6C 001D4BAC  48 24 FC 3D */	bl initPerspPrintf__8GraphicsFP8Viewport
/* 801D7C70 001D4BB0  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 801D7C74 001D4BB4  3C 60 80 48 */	lis r3, lbl_804807E4@ha
/* 801D7C78 001D4BB8  84 A3 07 E4 */	lwzu r5, lbl_804807E4@l(r3)
/* 801D7C7C 001D4BBC  54 00 07 BE */	clrlwi r0, r0, 0x1e
/* 801D7C80 001D4BC0  80 83 00 04 */	lwz r4, 4(r3)
/* 801D7C84 001D4BC4  2C 00 00 01 */	cmpwi r0, 1
/* 801D7C88 001D4BC8  80 63 00 08 */	lwz r3, 8(r3)
/* 801D7C8C 001D4BCC  90 A1 00 24 */	stw r5, 0x24(r1)
/* 801D7C90 001D4BD0  90 81 00 28 */	stw r4, 0x28(r1)
/* 801D7C94 001D4BD4  90 61 00 2C */	stw r3, 0x2c(r1)
/* 801D7C98 001D4BD8  41 82 00 54 */	beq .L_801D7CEC
/* 801D7C9C 001D4BDC  40 80 00 10 */	bge .L_801D7CAC
/* 801D7CA0 001D4BE0  2C 00 00 00 */	cmpwi r0, 0
/* 801D7CA4 001D4BE4  40 80 00 14 */	bge .L_801D7CB8
/* 801D7CA8 001D4BE8  48 00 00 A4 */	b .L_801D7D4C
.L_801D7CAC:
/* 801D7CAC 001D4BEC  2C 00 00 03 */	cmpwi r0, 3
/* 801D7CB0 001D4BF0  40 80 00 9C */	bge .L_801D7D4C
/* 801D7CB4 001D4BF4  48 00 00 68 */	b .L_801D7D1C
.L_801D7CB8:
/* 801D7CB8 001D4BF8  38 80 00 FF */	li r4, 0xff
/* 801D7CBC 001D4BFC  38 60 00 C8 */	li r3, 0xc8
/* 801D7CC0 001D4C00  38 C0 00 00 */	li r6, 0
/* 801D7CC4 001D4C04  38 A0 00 0A */	li r5, 0xa
/* 801D7CC8 001D4C08  98 C1 00 44 */	stb r6, 0x44(r1)
/* 801D7CCC 001D4C0C  98 A1 00 45 */	stb r5, 0x45(r1)
/* 801D7CD0 001D4C10  98 81 00 46 */	stb r4, 0x46(r1)
/* 801D7CD4 001D4C14  98 81 00 47 */	stb r4, 0x47(r1)
/* 801D7CD8 001D4C18  98 61 00 48 */	stb r3, 0x48(r1)
/* 801D7CDC 001D4C1C  98 61 00 49 */	stb r3, 0x49(r1)
/* 801D7CE0 001D4C20  98 61 00 4A */	stb r3, 0x4a(r1)
/* 801D7CE4 001D4C24  98 81 00 4B */	stb r4, 0x4b(r1)
/* 801D7CE8 001D4C28  48 00 00 64 */	b .L_801D7D4C
.L_801D7CEC:
/* 801D7CEC 001D4C2C  38 A0 00 C8 */	li r5, 0xc8
/* 801D7CF0 001D4C30  38 60 00 FF */	li r3, 0xff
/* 801D7CF4 001D4C34  38 80 00 00 */	li r4, 0
/* 801D7CF8 001D4C38  98 A1 00 44 */	stb r5, 0x44(r1)
/* 801D7CFC 001D4C3C  98 A1 00 45 */	stb r5, 0x45(r1)
/* 801D7D00 001D4C40  98 81 00 46 */	stb r4, 0x46(r1)
/* 801D7D04 001D4C44  98 61 00 47 */	stb r3, 0x47(r1)
/* 801D7D08 001D4C48  98 A1 00 48 */	stb r5, 0x48(r1)
/* 801D7D0C 001D4C4C  98 A1 00 49 */	stb r5, 0x49(r1)
/* 801D7D10 001D4C50  98 A1 00 4A */	stb r5, 0x4a(r1)
/* 801D7D14 001D4C54  98 61 00 4B */	stb r3, 0x4b(r1)
/* 801D7D18 001D4C58  48 00 00 34 */	b .L_801D7D4C
.L_801D7D1C:
/* 801D7D1C 001D4C5C  38 C0 00 FF */	li r6, 0xff
/* 801D7D20 001D4C60  38 60 00 C8 */	li r3, 0xc8
/* 801D7D24 001D4C64  38 A0 00 0A */	li r5, 0xa
/* 801D7D28 001D4C68  38 80 00 00 */	li r4, 0
/* 801D7D2C 001D4C6C  98 C1 00 44 */	stb r6, 0x44(r1)
/* 801D7D30 001D4C70  98 A1 00 45 */	stb r5, 0x45(r1)
/* 801D7D34 001D4C74  98 81 00 46 */	stb r4, 0x46(r1)
/* 801D7D38 001D4C78  98 C1 00 47 */	stb r6, 0x47(r1)
/* 801D7D3C 001D4C7C  98 61 00 48 */	stb r3, 0x48(r1)
/* 801D7D40 001D4C80  98 61 00 49 */	stb r3, 0x49(r1)
/* 801D7D44 001D4C84  98 61 00 4A */	stb r3, 0x4a(r1)
/* 801D7D48 001D4C88  98 C1 00 4B */	stb r6, 0x4b(r1)
.L_801D7D4C:
/* 801D7D4C 001D4C8C  88 9D 00 D8 */	lbz r4, 0xd8(r29)
/* 801D7D50 001D4C90  39 22 B4 10 */	addi r9, r2, lbl_80519770@sda21
/* 801D7D54 001D4C94  54 83 07 39 */	rlwinm. r3, r4, 0, 0x1c, 0x1c
/* 801D7D58 001D4C98  41 82 00 08 */	beq .L_801D7D60
/* 801D7D5C 001D4C9C  39 22 B4 0C */	addi r9, r2, lbl_8051976C@sda21
.L_801D7D60:
/* 801D7D60 001D4CA0  54 83 06 B5 */	rlwinm. r3, r4, 0, 0x1a, 0x1a
/* 801D7D64 001D4CA4  39 02 B4 18 */	addi r8, r2, lbl_80519778@sda21
/* 801D7D68 001D4CA8  41 82 00 08 */	beq .L_801D7D70
/* 801D7D6C 001D4CAC  39 02 B4 14 */	addi r8, r2, lbl_80519774@sda21
.L_801D7D70:
/* 801D7D70 001D4CB0  54 83 06 F7 */	rlwinm. r3, r4, 0, 0x1b, 0x1b
/* 801D7D74 001D4CB4  3C 80 80 48 */	lis r4, lbl_804807F0@ha
/* 801D7D78 001D4CB8  38 C4 07 F0 */	addi r6, r4, lbl_804807F0@l
/* 801D7D7C 001D4CBC  7F E5 FB 78 */	mr r5, r31
/* 801D7D80 001D4CC0  7F C3 F3 78 */	mr r3, r30
/* 801D7D84 001D4CC4  38 81 00 30 */	addi r4, r1, 0x30
/* 801D7D88 001D4CC8  38 E2 B4 18 */	addi r7, r2, lbl_80519778@sda21
/* 801D7D8C 001D4CCC  41 82 00 08 */	beq .L_801D7D94
/* 801D7D90 001D4CD0  38 E2 B4 14 */	addi r7, r2, lbl_80519774@sda21
.L_801D7D94:
/* 801D7D94 001D4CD4  54 00 10 3A */	slwi r0, r0, 2
/* 801D7D98 001D4CD8  39 41 00 24 */	addi r10, r1, 0x24
/* 801D7D9C 001D4CDC  7D 4A 00 2E */	lwzx r10, r10, r0
/* 801D7DA0 001D4CE0  4C C6 31 82 */	crclr 6
/* 801D7DA4 001D4CE4  48 24 FD 39 */	bl "perspPrintf__8GraphicsFR15PerspPrintfInfoR10Vector3<f>Pce"
/* 801D7DA8 001D4CE8  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 801D7DAC 001D4CEC  38 80 00 00 */	li r4, 0
/* 801D7DB0 001D4CF0  80 63 00 24 */	lwz r3, 0x24(r3)
/* 801D7DB4 001D4CF4  48 24 D8 3D */	bl getViewport__8GraphicsFi
/* 801D7DB8 001D4CF8  83 83 00 44 */	lwz r28, 0x44(r3)
/* 801D7DBC 001D4CFC  7F A3 EB 78 */	mr r3, r29
/* 801D7DC0 001D4D00  C0 3F 00 00 */	lfs f1, 0(r31)
/* 801D7DC4 001D4D04  38 81 00 08 */	addi r4, r1, 8
/* 801D7DC8 001D4D08  C0 02 B4 1C */	lfs f0, lbl_8051977C@sda21(r2)
/* 801D7DCC 001D4D0C  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 801D7DD0 001D4D10  C0 3F 00 04 */	lfs f1, 4(r31)
/* 801D7DD4 001D4D14  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 801D7DD8 001D4D18  EC 01 00 2A */	fadds f0, f1, f0
/* 801D7DDC 001D4D1C  C0 3F 00 08 */	lfs f1, 8(r31)
/* 801D7DE0 001D4D20  D0 21 00 20 */	stfs f1, 0x20(r1)
/* 801D7DE4 001D4D24  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 801D7DE8 001D4D28  81 9D 00 00 */	lwz r12, 0(r29)
/* 801D7DEC 001D4D2C  81 8C 01 40 */	lwz r12, 0x140(r12)
/* 801D7DF0 001D4D30  7D 89 03 A6 */	mtctr r12
/* 801D7DF4 001D4D34  4E 80 04 21 */	bctrl 
/* 801D7DF8 001D4D38  7F 83 E3 78 */	mr r3, r28
/* 801D7DFC 001D4D3C  38 81 00 08 */	addi r4, r1, 8
/* 801D7E00 001D4D40  48 24 32 F9 */	bl calcScreenSize__6CameraFRQ23Sys6Sphere
/* 801D7E04 001D4D44  7F C3 F3 78 */	mr r3, r30
/* 801D7E08 001D4D48  38 81 00 30 */	addi r4, r1, 0x30
/* 801D7E0C 001D4D4C  38 A1 00 18 */	addi r5, r1, 0x18
/* 801D7E10 001D4D50  38 C2 B4 20 */	addi r6, r2, lbl_80519780@sda21
/* 801D7E14 001D4D54  4C C6 32 42 */	crset 6
/* 801D7E18 001D4D58  48 24 FC C5 */	bl "perspPrintf__8GraphicsFR15PerspPrintfInfoR10Vector3<f>Pce"
.L_801D7E1C:
/* 801D7E1C 001D4D5C  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801D7E20 001D4D60  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 801D7E24 001D4D64  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 801D7E28 001D4D68  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 801D7E2C 001D4D6C  83 81 00 50 */	lwz r28, 0x50(r1)
/* 801D7E30 001D4D70  7C 08 03 A6 */	mtlr r0
/* 801D7E34 001D4D74  38 21 00 60 */	addi r1, r1, 0x60
/* 801D7E38 001D4D78  4E 80 00 20 */	blr 
.endfn "drawLODInfo__Q24Game8CreatureFR8GraphicsR10Vector3<f>"

.fn __sinit_creatureLOD_cpp, local
/* 801D7E3C 001D4D7C  3C 80 80 51 */	lis r4, __float_nan@ha
/* 801D7E40 001D4D80  38 00 FF FF */	li r0, -1
/* 801D7E44 001D4D84  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 801D7E48 001D4D88  3C 60 80 4C */	lis r3, govNAN___Q24Game5P2JST@ha
/* 801D7E4C 001D4D8C  90 0D 94 58 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 801D7E50 001D4D90  D4 03 86 10 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 801D7E54 001D4D94  D0 0D 94 5C */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 801D7E58 001D4D98  D0 03 00 04 */	stfs f0, 4(r3)
/* 801D7E5C 001D4D9C  D0 03 00 08 */	stfs f0, 8(r3)
/* 801D7E60 001D4DA0  4E 80 00 20 */	blr 
.endfn __sinit_creatureLOD_cpp
