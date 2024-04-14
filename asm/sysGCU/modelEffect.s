.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
	.4byte __sinit_modelEffect_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8049AC20, local
	.asciz "modelEffect.cpp"
.endobj lbl_8049AC20
.balign 4
.obj lbl_8049AC30, local
	.asciz "P2Assert"
.endobj lbl_8049AC30

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST
.balign 4
.obj __vt__11ModelEffect, global
	.4byte 0
	.4byte 0
	.4byte constructor__11ModelEffectFv
	.4byte doAnimation__11ModelEffectFv
	.4byte doEntry__11ModelEffectFv
	.4byte doSetView__11ModelEffectFi
	.4byte doViewCalc__11ModelEffectFv
	.4byte changeMaterial__11ModelEffectFv
	.4byte 0
	.4byte useCylinderLOD__11ModelEffectFv
	.4byte getLODCylinder__11ModelEffectFRQ23Sys8Cylinder
	.4byte doSimulation__11ModelEffectFf
	.4byte doDirectDraw__11ModelEffectFR8Graphics
.endobj __vt__11ModelEffect

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj gu32NAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gu32NAN___Q24Game5P2JST
.balign 4
.obj gfNAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gfNAN___Q24Game5P2JST

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn entry__15ModelEffectDataFv, global
/* 8043D49C 0043A3DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043D4A0 0043A3E0  7C 08 02 A6 */	mflr r0
/* 8043D4A4 0043A3E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043D4A8 0043A3E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8043D4AC 0043A3EC  7C 7F 1B 78 */	mr r31, r3
/* 8043D4B0 0043A3F0  81 83 00 00 */	lwz r12, 0(r3)
/* 8043D4B4 0043A3F4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8043D4B8 0043A3F8  7D 89 03 A6 */	mtctr r12
/* 8043D4BC 0043A3FC  4E 80 04 21 */	bctrl 
/* 8043D4C0 0043A400  80 0D 9A 18 */	lwz r0, particleMgr@sda21(r13)
/* 8043D4C4 0043A404  28 00 00 00 */	cmplwi r0, 0
/* 8043D4C8 0043A408  40 82 00 20 */	bne .L_8043D4E8
/* 8043D4CC 0043A40C  3C 60 80 4A */	lis r3, lbl_8049AC20@ha
/* 8043D4D0 0043A410  3C A0 80 4A */	lis r5, lbl_8049AC30@ha
/* 8043D4D4 0043A414  38 63 AC 20 */	addi r3, r3, lbl_8049AC20@l
/* 8043D4D8 0043A418  38 80 00 2C */	li r4, 0x2c
/* 8043D4DC 0043A41C  38 A5 AC 30 */	addi r5, r5, lbl_8049AC30@l
/* 8043D4E0 0043A420  4C C6 31 82 */	crclr 6
/* 8043D4E4 0043A424  4B BE D1 5D */	bl panic_f__12JUTExceptionFPCciPCce
.L_8043D4E8:
/* 8043D4E8 0043A428  80 6D 9A 18 */	lwz r3, particleMgr@sda21(r13)
/* 8043D4EC 0043A42C  7F E4 FB 78 */	mr r4, r31
/* 8043D4F0 0043A430  48 00 01 25 */	bl entryModelEffect__11ParticleMgrFP15ModelEffectData
/* 8043D4F4 0043A434  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043D4F8 0043A438  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8043D4FC 0043A43C  7C 08 03 A6 */	mtlr r0
/* 8043D500 0043A440  38 21 00 10 */	addi r1, r1, 0x10
/* 8043D504 0043A444  4E 80 00 20 */	blr 
.endfn entry__15ModelEffectDataFv

.fn allocModelData__15ModelEffectDataFi, global
/* 8043D508 0043A448  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043D50C 0043A44C  7C 08 02 A6 */	mflr r0
/* 8043D510 0043A450  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043D514 0043A454  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8043D518 0043A458  7C 9F 23 78 */	mr r31, r4
/* 8043D51C 0043A45C  93 C1 00 08 */	stw r30, 8(r1)
/* 8043D520 0043A460  7C 7E 1B 78 */	mr r30, r3
/* 8043D524 0043A464  93 E3 00 18 */	stw r31, 0x18(r3)
/* 8043D528 0043A468  80 03 00 18 */	lwz r0, 0x18(r3)
/* 8043D52C 0043A46C  54 03 10 3A */	slwi r3, r0, 2
/* 8043D530 0043A470  4B BE 6A 7D */	bl __nwa__FUl
/* 8043D534 0043A474  2C 1F 00 00 */	cmpwi r31, 0
/* 8043D538 0043A478  90 7E 00 1C */	stw r3, 0x1c(r30)
/* 8043D53C 0043A47C  39 80 00 00 */	li r12, 0
/* 8043D540 0043A480  40 81 00 BC */	ble .L_8043D5FC
/* 8043D544 0043A484  2C 1F 00 08 */	cmpwi r31, 8
/* 8043D548 0043A488  38 7F FF F8 */	addi r3, r31, -8
/* 8043D54C 0043A48C  40 81 00 88 */	ble .L_8043D5D4
/* 8043D550 0043A490  38 03 00 07 */	addi r0, r3, 7
/* 8043D554 0043A494  39 60 00 00 */	li r11, 0
/* 8043D558 0043A498  54 00 E8 FE */	srwi r0, r0, 3
/* 8043D55C 0043A49C  7C 09 03 A6 */	mtctr r0
/* 8043D560 0043A4A0  2C 03 00 00 */	cmpwi r3, 0
/* 8043D564 0043A4A4  40 81 00 70 */	ble .L_8043D5D4
.L_8043D568:
/* 8043D568 0043A4A8  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8043D56C 0043A4AC  39 40 00 00 */	li r10, 0
/* 8043D570 0043A4B0  39 0B 00 04 */	addi r8, r11, 4
/* 8043D574 0043A4B4  38 EB 00 08 */	addi r7, r11, 8
/* 8043D578 0043A4B8  7D 43 59 2E */	stwx r10, r3, r11
/* 8043D57C 0043A4BC  38 CB 00 0C */	addi r6, r11, 0xc
/* 8043D580 0043A4C0  38 AB 00 10 */	addi r5, r11, 0x10
/* 8043D584 0043A4C4  38 8B 00 14 */	addi r4, r11, 0x14
/* 8043D588 0043A4C8  81 3E 00 1C */	lwz r9, 0x1c(r30)
/* 8043D58C 0043A4CC  38 6B 00 18 */	addi r3, r11, 0x18
/* 8043D590 0043A4D0  38 0B 00 1C */	addi r0, r11, 0x1c
/* 8043D594 0043A4D4  39 6B 00 20 */	addi r11, r11, 0x20
/* 8043D598 0043A4D8  7D 49 41 2E */	stwx r10, r9, r8
/* 8043D59C 0043A4DC  39 8C 00 08 */	addi r12, r12, 8
/* 8043D5A0 0043A4E0  81 1E 00 1C */	lwz r8, 0x1c(r30)
/* 8043D5A4 0043A4E4  7D 48 39 2E */	stwx r10, r8, r7
/* 8043D5A8 0043A4E8  80 FE 00 1C */	lwz r7, 0x1c(r30)
/* 8043D5AC 0043A4EC  7D 47 31 2E */	stwx r10, r7, r6
/* 8043D5B0 0043A4F0  80 DE 00 1C */	lwz r6, 0x1c(r30)
/* 8043D5B4 0043A4F4  7D 46 29 2E */	stwx r10, r6, r5
/* 8043D5B8 0043A4F8  80 BE 00 1C */	lwz r5, 0x1c(r30)
/* 8043D5BC 0043A4FC  7D 45 21 2E */	stwx r10, r5, r4
/* 8043D5C0 0043A500  80 9E 00 1C */	lwz r4, 0x1c(r30)
/* 8043D5C4 0043A504  7D 44 19 2E */	stwx r10, r4, r3
/* 8043D5C8 0043A508  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8043D5CC 0043A50C  7D 43 01 2E */	stwx r10, r3, r0
/* 8043D5D0 0043A510  42 00 FF 98 */	bdnz .L_8043D568
.L_8043D5D4:
/* 8043D5D4 0043A514  7C 0C F8 50 */	subf r0, r12, r31
/* 8043D5D8 0043A518  55 85 10 3A */	slwi r5, r12, 2
/* 8043D5DC 0043A51C  38 80 00 00 */	li r4, 0
/* 8043D5E0 0043A520  7C 09 03 A6 */	mtctr r0
/* 8043D5E4 0043A524  7C 0C F8 00 */	cmpw r12, r31
/* 8043D5E8 0043A528  40 80 00 14 */	bge .L_8043D5FC
.L_8043D5EC:
/* 8043D5EC 0043A52C  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8043D5F0 0043A530  7C 83 29 2E */	stwx r4, r3, r5
/* 8043D5F4 0043A534  38 A5 00 04 */	addi r5, r5, 4
/* 8043D5F8 0043A538  42 00 FF F4 */	bdnz .L_8043D5EC
.L_8043D5FC:
/* 8043D5FC 0043A53C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043D600 0043A540  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8043D604 0043A544  83 C1 00 08 */	lwz r30, 8(r1)
/* 8043D608 0043A548  7C 08 03 A6 */	mtlr r0
/* 8043D60C 0043A54C  38 21 00 10 */	addi r1, r1, 0x10
/* 8043D610 0043A550  4E 80 00 20 */	blr 
.endfn allocModelData__15ModelEffectDataFi

.fn entryModelEffect__11ParticleMgrFP15ModelEffectData, global
/* 8043D614 0043A554  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043D618 0043A558  7C 08 02 A6 */	mflr r0
/* 8043D61C 0043A55C  38 63 00 60 */	addi r3, r3, 0x60
/* 8043D620 0043A560  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043D624 0043A564  4B FD 3D E5 */	bl add__5CNodeFP5CNode
/* 8043D628 0043A568  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043D62C 0043A56C  7C 08 03 A6 */	mtlr r0
/* 8043D630 0043A570  38 21 00 10 */	addi r1, r1, 0x10
/* 8043D634 0043A574  4E 80 00 20 */	blr 
.endfn entryModelEffect__11ParticleMgrFP15ModelEffectData

.fn createModelEffect__11ParticleMgrFP20ModelEffectCreateArg, global
/* 8043D638 0043A578  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8043D63C 0043A57C  7C 08 02 A6 */	mflr r0
/* 8043D640 0043A580  90 01 00 24 */	stw r0, 0x24(r1)
/* 8043D644 0043A584  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8043D648 0043A588  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8043D64C 0043A58C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8043D650 0043A590  7C 7D 1B 78 */	mr r29, r3
/* 8043D654 0043A594  93 81 00 10 */	stw r28, 0x10(r1)
/* 8043D658 0043A598  7C 9C 23 78 */	mr r28, r4
/* 8043D65C 0043A59C  7F 83 E3 78 */	mr r3, r28
/* 8043D660 0043A5A0  81 9C 00 00 */	lwz r12, 0(r28)
/* 8043D664 0043A5A4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8043D668 0043A5A8  7D 89 03 A6 */	mtctr r12
/* 8043D66C 0043A5AC  4E 80 04 21 */	bctrl 
/* 8043D670 0043A5B0  83 BD 00 70 */	lwz r29, 0x70(r29)
/* 8043D674 0043A5B4  7C 9E 23 78 */	mr r30, r4
/* 8043D678 0043A5B8  7C 7F 1B 78 */	mr r31, r3
/* 8043D67C 0043A5BC  48 00 00 30 */	b .L_8043D6AC
.L_8043D680:
/* 8043D680 0043A5C0  7F A3 EB 78 */	mr r3, r29
/* 8043D684 0043A5C4  81 9D 00 00 */	lwz r12, 0(r29)
/* 8043D688 0043A5C8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8043D68C 0043A5CC  7D 89 03 A6 */	mtctr r12
/* 8043D690 0043A5D0  4E 80 04 21 */	bctrl 
/* 8043D694 0043A5D4  7F C4 22 78 */	xor r4, r30, r4
/* 8043D698 0043A5D8  7F E0 1A 78 */	xor r0, r31, r3
/* 8043D69C 0043A5DC  7C 80 03 79 */	or. r0, r4, r0
/* 8043D6A0 0043A5E0  40 82 00 08 */	bne .L_8043D6A8
/* 8043D6A4 0043A5E4  48 00 00 14 */	b .L_8043D6B8
.L_8043D6A8:
/* 8043D6A8 0043A5E8  83 BD 00 04 */	lwz r29, 4(r29)
.L_8043D6AC:
/* 8043D6AC 0043A5EC  28 1D 00 00 */	cmplwi r29, 0
/* 8043D6B0 0043A5F0  40 82 FF D0 */	bne .L_8043D680
/* 8043D6B4 0043A5F4  3B A0 00 00 */	li r29, 0
.L_8043D6B8:
/* 8043D6B8 0043A5F8  28 1D 00 00 */	cmplwi r29, 0
/* 8043D6BC 0043A5FC  41 82 00 74 */	beq .L_8043D730
/* 8043D6C0 0043A600  7F A3 EB 78 */	mr r3, r29
/* 8043D6C4 0043A604  7F 84 E3 78 */	mr r4, r28
/* 8043D6C8 0043A608  81 9D 00 00 */	lwz r12, 0(r29)
/* 8043D6CC 0043A60C  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8043D6D0 0043A610  7D 89 03 A6 */	mtctr r12
/* 8043D6D4 0043A614  4E 80 04 21 */	bctrl 
/* 8043D6D8 0043A618  7C 7D 1B 79 */	or. r29, r3, r3
/* 8043D6DC 0043A61C  41 82 00 4C */	beq .L_8043D728
/* 8043D6E0 0043A620  38 60 00 1C */	li r3, 0x1c
/* 8043D6E4 0043A624  4B BE 67 C1 */	bl __nw__FUl
/* 8043D6E8 0043A628  7C 7E 1B 79 */	or. r30, r3, r3
/* 8043D6EC 0043A62C  41 82 00 18 */	beq .L_8043D704
/* 8043D6F0 0043A630  4B FD 3C A1 */	bl __ct__5CNodeFv
/* 8043D6F4 0043A634  3C 60 80 4E */	lis r3, "__vt__26TObjectNode<11ModelEffect>"@ha
/* 8043D6F8 0043A638  38 03 76 D8 */	addi r0, r3, "__vt__26TObjectNode<11ModelEffect>"@l
/* 8043D6FC 0043A63C  90 1E 00 00 */	stw r0, 0(r30)
/* 8043D700 0043A640  93 BE 00 18 */	stw r29, 0x18(r30)
.L_8043D704:
/* 8043D704 0043A644  80 6D 9A 18 */	lwz r3, particleMgr@sda21(r13)
/* 8043D708 0043A648  7F C4 F3 78 */	mr r4, r30
/* 8043D70C 0043A64C  38 63 00 3C */	addi r3, r3, 0x3c
/* 8043D710 0043A650  4B FD 3C F9 */	bl add__5CNodeFP5CNode
/* 8043D714 0043A654  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8043D718 0043A658  81 83 00 00 */	lwz r12, 0(r3)
/* 8043D71C 0043A65C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8043D720 0043A660  7D 89 03 A6 */	mtctr r12
/* 8043D724 0043A664  4E 80 04 21 */	bctrl 
.L_8043D728:
/* 8043D728 0043A668  7F A3 EB 78 */	mr r3, r29
/* 8043D72C 0043A66C  48 00 00 08 */	b .L_8043D734
.L_8043D730:
/* 8043D730 0043A670  38 60 00 00 */	li r3, 0
.L_8043D734:
/* 8043D734 0043A674  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8043D738 0043A678  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8043D73C 0043A67C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8043D740 0043A680  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8043D744 0043A684  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8043D748 0043A688  7C 08 03 A6 */	mtlr r0
/* 8043D74C 0043A68C  38 21 00 20 */	addi r1, r1, 0x20
/* 8043D750 0043A690  4E 80 00 20 */	blr 
.endfn createModelEffect__11ParticleMgrFP20ModelEffectCreateArg

.fn getLODCylinder__11ModelEffectFRQ23Sys8Cylinder, weak
/* 8043D8FC 0043A83C  4E 80 00 20 */	blr 
.endfn getLODCylinder__11ModelEffectFRQ23Sys8Cylinder

.fn useCylinderLOD__11ModelEffectFv, weak
/* 8043D900 0043A840  38 60 00 00 */	li r3, 0
/* 8043D904 0043A844  4E 80 00 20 */	blr 
.endfn useCylinderLOD__11ModelEffectFv

.fn changeMaterial__11ModelEffectFv, weak
/* 8043D9A0 0043A8E0  4E 80 00 20 */	blr 
.endfn changeMaterial__11ModelEffectFv

.fn doSetView__11ModelEffectFi, global
/* 8043D9A4 0043A8E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043D9A8 0043A8E8  7C 08 02 A6 */	mflr r0
/* 8043D9AC 0043A8EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043D9B0 0043A8F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8043D9B4 0043A8F4  7C 9F 23 78 */	mr r31, r4
/* 8043D9B8 0043A8F8  93 C1 00 08 */	stw r30, 8(r1)
/* 8043D9BC 0043A8FC  7C 7E 1B 78 */	mr r30, r3
/* 8043D9C0 0043A900  80 63 00 04 */	lwz r3, 4(r3)
/* 8043D9C4 0043A904  48 00 16 FD */	bl setCurrentViewNo__Q28SysShape5ModelFUl
/* 8043D9C8 0043A908  7C 7E FA 14 */	add r3, r30, r31
/* 8043D9CC 0043A90C  88 03 00 38 */	lbz r0, 0x38(r3)
/* 8043D9D0 0043A910  28 00 00 00 */	cmplwi r0, 0
/* 8043D9D4 0043A914  41 82 00 1C */	beq .L_8043D9F0
/* 8043D9D8 0043A918  80 7E 00 04 */	lwz r3, 4(r30)
/* 8043D9DC 0043A91C  81 83 00 00 */	lwz r12, 0(r3)
/* 8043D9E0 0043A920  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8043D9E4 0043A924  7D 89 03 A6 */	mtctr r12
/* 8043D9E8 0043A928  4E 80 04 21 */	bctrl 
/* 8043D9EC 0043A92C  48 00 00 18 */	b .L_8043DA04
.L_8043D9F0:
/* 8043D9F0 0043A930  80 7E 00 04 */	lwz r3, 4(r30)
/* 8043D9F4 0043A934  81 83 00 00 */	lwz r12, 0(r3)
/* 8043D9F8 0043A938  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8043D9FC 0043A93C  7D 89 03 A6 */	mtctr r12
/* 8043DA00 0043A940  4E 80 04 21 */	bctrl 
.L_8043DA04:
/* 8043DA04 0043A944  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043DA08 0043A948  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8043DA0C 0043A94C  83 C1 00 08 */	lwz r30, 8(r1)
/* 8043DA10 0043A950  7C 08 03 A6 */	mtlr r0
/* 8043DA14 0043A954  38 21 00 10 */	addi r1, r1, 0x10
/* 8043DA18 0043A958  4E 80 00 20 */	blr 
.endfn doSetView__11ModelEffectFi

.fn doViewCalc__11ModelEffectFv, global
/* 8043DA1C 0043A95C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043DA20 0043A960  7C 08 02 A6 */	mflr r0
/* 8043DA24 0043A964  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043DA28 0043A968  80 63 00 04 */	lwz r3, 4(r3)
/* 8043DA2C 0043A96C  48 00 16 2D */	bl viewCalc__Q28SysShape5ModelFv
/* 8043DA30 0043A970  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043DA34 0043A974  7C 08 03 A6 */	mtlr r0
/* 8043DA38 0043A978  38 21 00 10 */	addi r1, r1, 0x10
/* 8043DA3C 0043A97C  4E 80 00 20 */	blr 
.endfn doViewCalc__11ModelEffectFv

.fn doAnimation__11ParticleMgrFv, global
/* 8043DA40 0043A980  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043DA44 0043A984  7C 08 02 A6 */	mflr r0
/* 8043DA48 0043A988  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043DA4C 0043A98C  85 83 00 1C */	lwzu r12, 0x1c(r3)
/* 8043DA50 0043A990  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 8043DA54 0043A994  7D 89 03 A6 */	mtctr r12
/* 8043DA58 0043A998  4E 80 04 21 */	bctrl 
/* 8043DA5C 0043A99C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043DA60 0043A9A0  7C 08 03 A6 */	mtlr r0
/* 8043DA64 0043A9A4  38 21 00 10 */	addi r1, r1, 0x10
/* 8043DA68 0043A9A8  4E 80 00 20 */	blr 
.endfn doAnimation__11ParticleMgrFv

.fn doEntry__11ParticleMgrFv, global
/* 8043DA6C 0043A9AC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043DA70 0043A9B0  7C 08 02 A6 */	mflr r0
/* 8043DA74 0043A9B4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043DA78 0043A9B8  85 83 00 1C */	lwzu r12, 0x1c(r3)
/* 8043DA7C 0043A9BC  81 8C 00 68 */	lwz r12, 0x68(r12)
/* 8043DA80 0043A9C0  7D 89 03 A6 */	mtctr r12
/* 8043DA84 0043A9C4  4E 80 04 21 */	bctrl 
/* 8043DA88 0043A9C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043DA8C 0043A9CC  7C 08 03 A6 */	mtlr r0
/* 8043DA90 0043A9D0  38 21 00 10 */	addi r1, r1, 0x10
/* 8043DA94 0043A9D4  4E 80 00 20 */	blr 
.endfn doEntry__11ParticleMgrFv

.fn doSetView__11ParticleMgrFi, global
/* 8043DA98 0043A9D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043DA9C 0043A9DC  7C 08 02 A6 */	mflr r0
/* 8043DAA0 0043A9E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043DAA4 0043A9E4  85 83 00 1C */	lwzu r12, 0x1c(r3)
/* 8043DAA8 0043A9E8  81 8C 00 6C */	lwz r12, 0x6c(r12)
/* 8043DAAC 0043A9EC  7D 89 03 A6 */	mtctr r12
/* 8043DAB0 0043A9F0  4E 80 04 21 */	bctrl 
/* 8043DAB4 0043A9F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043DAB8 0043A9F8  7C 08 03 A6 */	mtlr r0
/* 8043DABC 0043A9FC  38 21 00 10 */	addi r1, r1, 0x10
/* 8043DAC0 0043AA00  4E 80 00 20 */	blr 
.endfn doSetView__11ParticleMgrFi

.fn doViewCalc__11ParticleMgrFv, global
/* 8043DAC4 0043AA04  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8043DAC8 0043AA08  7C 08 02 A6 */	mflr r0
/* 8043DACC 0043AA0C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8043DAD0 0043AA10  85 83 00 1C */	lwzu r12, 0x1c(r3)
/* 8043DAD4 0043AA14  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8043DAD8 0043AA18  7D 89 03 A6 */	mtctr r12
/* 8043DADC 0043AA1C  4E 80 04 21 */	bctrl 
/* 8043DAE0 0043AA20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8043DAE4 0043AA24  7C 08 03 A6 */	mtlr r0
/* 8043DAE8 0043AA28  38 21 00 10 */	addi r1, r1, 0x10
/* 8043DAEC 0043AA2C  4E 80 00 20 */	blr 
.endfn doViewCalc__11ParticleMgrFv

.fn __sinit_modelEffect_cpp, local
/* 8043DAF0 0043AA30  3C 80 80 51 */	lis r4, __float_nan@ha
/* 8043DAF4 0043AA34  38 00 FF FF */	li r0, -1
/* 8043DAF8 0043AA38  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 8043DAFC 0043AA3C  3C 60 80 4F */	lis r3, govNAN___Q24Game5P2JST@ha
/* 8043DB00 0043AA40  90 0D 9B E0 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 8043DB04 0043AA44  D4 03 CB A0 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 8043DB08 0043AA48  D0 0D 9B E4 */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 8043DB0C 0043AA4C  D0 03 00 04 */	stfs f0, 4(r3)
/* 8043DB10 0043AA50  D0 03 00 08 */	stfs f0, 8(r3)
/* 8043DB14 0043AA54  4E 80 00 20 */	blr 
.endfn __sinit_modelEffect_cpp
