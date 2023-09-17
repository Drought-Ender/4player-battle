.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_vsCardMgr_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_80483AD0, local
	.skip 0xC
.endobj lbl_80483AD0
.balign 4
.obj lbl_80483ADC, local
	.asciz "vsCardMgr"
.endobj lbl_80483ADC
.balign 4
.obj lbl_80483AE8, local
	.asciz "pikmin_5.bti"
.endobj lbl_80483AE8
.balign 4
.obj lbl_80483AF8, local
	.asciz "pikmin_10.bti"
.endobj lbl_80483AF8
.balign 4
.obj lbl_80483B08, local
	.asciz "all_flower.bti"
.endobj lbl_80483B08
.balign 4
.obj lbl_80483B18, local
	.asciz "pikmin_xlu.bti"
.endobj lbl_80483B18
.balign 4
.obj lbl_80483B28, local
	.asciz "dope_black.bti"
.endobj lbl_80483B28
.balign 4
.obj lbl_80483B38, local
	.asciz "dope_red.bti"
.endobj lbl_80483B38
.balign 4
.obj lbl_80483B48, local
	.asciz "reset_bedama.bti"
.endobj lbl_80483B48
.balign 4
.obj lbl_80483B5C, local
	.asciz "teki_hanachirashi"
.endobj lbl_80483B5C
.balign 4
.obj lbl_80483B70, local
	.asciz "teki_sarai.bti"
.endobj lbl_80483B70
.balign 4
.obj lbl_80483B80, local
	.asciz "teki_rock.bti"
.endobj lbl_80483B80
.balign 4
.obj lbl_80483B90, local
	.asciz "teki_tank.bti"
.endobj lbl_80483B90
.balign 4
.obj "cardData__Q34Game6VsGame23@unnamed@vsCardMgr_cpp@", local
	.4byte lbl_80483AE8
	.4byte 0x00000001
	.4byte lbl_80483AF8
	.4byte 0x00000001
	.4byte lbl_80483B08
	.4byte 0x00000001
	.4byte lbl_80483B18
	.4byte 0x00000001
	.4byte lbl_80483B28
	.4byte 0x00000001
	.4byte lbl_80483B38
	.4byte 0x00000001
	.4byte lbl_80483B48
	.4byte 0x00000001
	.4byte lbl_80483B5C
	.4byte 0x00000001
	.4byte lbl_80483B70
	.4byte 0x00000001
	.4byte lbl_80483B80
	.4byte 0x00000001
	.4byte lbl_80483B90
	.4byte 0x00000001
	.4byte 0x00000000
	.4byte 0x00000000
.endobj "cardData__Q34Game6VsGame23@unnamed@vsCardMgr_cpp@"
.balign 4
.obj lbl_80483C00, local
	.asciz "teki_hanachirashi.bti"
.endobj lbl_80483C00
.balign 4
.obj lbl_80483C18, local
	.asciz "teki_bombotakara.bti"
.endobj lbl_80483C18
.balign 4
.obj lbl_80483C30, local
	.asciz "user/Kando/vstex/arc.szs"
.endobj lbl_80483C30
.balign 4
.obj lbl_80483C4C, local
	.asciz "vsCardMgr.cpp"
.endobj lbl_80483C4C
.balign 4
.obj lbl_80483C5C, local
	.asciz "vstex/arc.szs not found !\n"
.endobj lbl_80483C5C
.balign 4
.obj lbl_80483C78, local
	.asciz "%s not found !\n"
.endobj lbl_80483C78
.balign 4
.obj lbl_80483C88, local
	.asciz "press_y.bti"
.endobj lbl_80483C88
.balign 4
.obj lbl_80483C94, local
	.asciz "lamp_on.bti"
.endobj lbl_80483C94
.balign 4
.obj lbl_80483CA0, local
	.asciz "lamp_off.bti"
.endobj lbl_80483CA0
.balign 4
.obj lbl_80483CB0, local
	.asciz "P2Assert"
.endobj lbl_80483CB0
.balign 4
.obj lbl_80483CBC, local
	.asciz "ArgScaleColorColor"
.endobj lbl_80483CBC

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST
.obj "tex_names__Q34Game6VsGame23@unnamed@vsCardMgr_cpp@", local
	.4byte lbl_80483AE8
	.4byte lbl_80483AF8
	.4byte lbl_80483B08
	.4byte lbl_80483B18
	.4byte lbl_80483B28
	.4byte lbl_80483B38
	.4byte lbl_80483B48
	.4byte lbl_80483C00
	.4byte lbl_80483B70
	.4byte lbl_80483B80
	.4byte lbl_80483C18
	.4byte lbl_80483B90
.endobj "tex_names__Q34Game6VsGame23@unnamed@vsCardMgr_cpp@"
.obj __vt__Q25efx2d5TBase, weak
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte setGroup__Q25efx2d5TBaseFUc
.endobj __vt__Q25efx2d5TBase
.obj __vt__Q25efx2d7TBaseIF, weak
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.endobj __vt__Q25efx2d7TBaseIF
.obj __vt__Q25efx2d18ArgScaleColorColor, weak
	.4byte 0
	.4byte 0
	.4byte getName__Q25efx2d18ArgScaleColorColorFv
.endobj __vt__Q25efx2d18ArgScaleColorColor
.obj __vt__Q25efx2d3Arg, weak
	.4byte 0
	.4byte 0
	.4byte getName__Q25efx2d3ArgFv
.endobj __vt__Q25efx2d3Arg
.obj __vt__Q23efx8TPkGlow2, weak
	.4byte 0
	.4byte 0
	.4byte create__Q23efx8TSimple2FPQ23efx3Arg
	.4byte forceKill__Q23efx8TSimple2Fv
	.4byte fade__Q23efx8TSimple2Fv
.endobj __vt__Q23efx8TPkGlow2

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj gu32NAN___Q24Game5P2JST, local
	.skip 4
.endobj gu32NAN___Q24Game5P2JST
.obj gfNAN___Q24Game5P2JST, local
	.skip 4
.endobj gfNAN___Q24Game5P2JST

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_8051A3D8, local
	.float 0.0
.endobj lbl_8051A3D8
.obj lbl_8051A3DC, local
	.float -99.9
.endobj lbl_8051A3DC
.obj lbl_8051A3E0, local
	.float 32768.0
.endobj lbl_8051A3E0
.obj lbl_8051A3E4, local
	.float 12.0
.endobj lbl_8051A3E4
.balign 8
.obj lbl_8051A3E8, local
	.8byte 0x4330000080000000
.endobj lbl_8051A3E8
.obj lbl_8051A3F0, local
	.float 40.0
.endobj lbl_8051A3F0
.balign 4
.obj lbl_8051A3F4, local
	.asciz "test"
.endobj lbl_8051A3F4
.balign 4
.obj lbl_8051A3FC, local
	.float -1.0
.endobj lbl_8051A3FC
.obj lbl_8051A400, local
	.float 555.0
.endobj lbl_8051A400
.obj lbl_8051A404, local
	.float -250.0
.endobj lbl_8051A404
.obj lbl_8051A408, local
	.float 4500.0
.endobj lbl_8051A408
.obj lbl_8051A40C, local
	.float 0.98
.endobj lbl_8051A40C
.balign 4
.obj lbl_8051A410, local
	.asciz "hl.bti"
.endobj lbl_8051A410
.balign 4
.obj lbl_8051A418, local
	.float 515.0
.endobj lbl_8051A418
.obj lbl_8051A41C, local
	.float 115.0
.endobj lbl_8051A41C
.obj lbl_8051A420, local
	.float 315.0
.endobj lbl_8051A420
.obj lbl_8051A424, local
	.float 80.0
.endobj lbl_8051A424
.obj lbl_8051A428, local
	.float 22.4
.endobj lbl_8051A428
.obj lbl_8051A42C, local
	.float 2.0
.endobj lbl_8051A42C
.obj lbl_8051A430, local
	.float 8.0
.endobj lbl_8051A430
.obj lbl_8051A434, local
	.float 60.0
.endobj lbl_8051A434
.obj lbl_8051A438, local
	.float 30.0
.endobj lbl_8051A438
.obj lbl_8051A43C, local
	.float 0.5
.endobj lbl_8051A43C
.obj lbl_8051A440, local
	.float 50.0
.endobj lbl_8051A440
.obj lbl_8051A444, local
	.float 100.0
.endobj lbl_8051A444
.obj lbl_8051A448, local # tau
	.float 6.2831855
.endobj lbl_8051A448
.obj lbl_8051A44C, local
	.float 325.9493
.endobj lbl_8051A44C
.obj lbl_8051A450, local
	.float -325.9493
.endobj lbl_8051A450
.obj lbl_8051A454, local
	.float 1.0
.endobj lbl_8051A454
.obj lbl_8051A458, local
	.float 90.0
.endobj lbl_8051A458
.obj lbl_8051A45C, local
	.float 150.0
.endobj lbl_8051A45C
.obj lbl_8051A460, local
	.float 0.4
.endobj lbl_8051A460
.obj lbl_8051A464, local
	.float 5.0
.endobj lbl_8051A464
.obj lbl_8051A468, local
	.float 0.2
.endobj lbl_8051A468
.obj lbl_8051A46C, local
	.float 0.7
.endobj lbl_8051A46C
.obj lbl_8051A470, local
	.float 0.8
.endobj lbl_8051A470
.obj lbl_8051A474, local
	.float 4.0
.endobj lbl_8051A474
.obj lbl_8051A478, local
	.float 1.2566371
.endobj lbl_8051A478
.obj lbl_8051A47C, local # -tau
	.float -6.2831855
.endobj lbl_8051A47C
.obj lbl_8051A480, local
	.float 0.07
.endobj lbl_8051A480
.obj lbl_8051A484, local
	.float -12.566371
.endobj lbl_8051A484
.obj lbl_8051A488, local
	.float 3.0
.endobj lbl_8051A488
.obj lbl_8051A48C, local
	.float 2.7
.endobj lbl_8051A48C
.obj lbl_8051A490, local
	.float -1.3823009
.endobj lbl_8051A490
.obj lbl_8051A494, local
	.float 1.2
.endobj lbl_8051A494
.obj lbl_8051A498, local
	.float 0.5235988
.endobj lbl_8051A498
.obj lbl_8051A49C, local
	.float 300.0
.endobj lbl_8051A49C
.obj lbl_8051A4A0, local
	.float 20.0
.endobj lbl_8051A4A0
.obj lbl_8051A4A4, local
	.float 0.03125
.endobj lbl_8051A4A4
.obj lbl_8051A4A8, local
	.4byte 0x14141480
.endobj lbl_8051A4A8
.obj lbl_8051A4AC, local
	.4byte 0xFFFFFFCA
.endobj lbl_8051A4AC
.obj lbl_8051A4B0, local
	.4byte 0xFFFFFFFF
.endobj lbl_8051A4B0
.obj lbl_8051A4B4, local
	.4byte 0xFFFFFFFF
.endobj lbl_8051A4B4
.obj lbl_8051A4B8, local
	.float 0.2617994
.endobj lbl_8051A4B8
.balign 4
.obj lbl_8051A4BC, local
	.asciz "%d"
.endobj lbl_8051A4BC
.balign 8
.obj lbl_8051A4C0, local
	.double 127.5
.endobj lbl_8051A4C0
.obj lbl_8051A4C8, local
	.float 0.35
.endobj lbl_8051A4C8
.obj lbl_8051A4CC, local
	.float -15.0
.endobj lbl_8051A4CC
.obj lbl_8051A4D0, local
	.float -7.0
.endobj lbl_8051A4D0
.obj lbl_8051A4D4, local
	.float -24.0
.endobj lbl_8051A4D4
.obj lbl_8051A4D8, local
	.float 16.0
.endobj lbl_8051A4D8
.obj lbl_8051A4DC, local
	.float 10.0
.endobj lbl_8051A4DC
.obj lbl_8051A4E0, local # pi
	.float 3.1415927
.endobj lbl_8051A4E0
.obj lbl_8051A4E4, local
	.float 0.0055555557
.endobj lbl_8051A4E4
.obj lbl_8051A4E8, local
	.float 360.0
.endobj lbl_8051A4E8
.balign 4
.obj lbl_8051A4EC, local
	.asciz "Arg"
.endobj lbl_8051A4EC

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q44Game6VsGame7CardMgr11SlotMachineFv, weak
/* 80235654 00232594  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80235658 00232598  7C 08 02 A6 */	mflr r0
/* 8023565C 0023259C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80235660 002325A0  38 00 00 00 */	li r0, 0
/* 80235664 002325A4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80235668 002325A8  7C 7F 1B 78 */	mr r31, r3
/* 8023566C 002325AC  90 03 00 60 */	stw r0, 0x60(r3)
/* 80235670 002325B0  48 00 13 59 */	bl clear__Q44Game6VsGame7CardMgr11SlotMachineFv
/* 80235674 002325B4  38 00 00 00 */	li r0, 0
/* 80235678 002325B8  3C 60 00 01 */	lis r3, 0x0000FFFF@ha
/* 8023567C 002325BC  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 80235680 002325C0  38 03 FF FF */	addi r0, r3, 0x0000FFFF@l
/* 80235684 002325C4  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80235688 002325C8  7F E3 FB 78 */	mr r3, r31
/* 8023568C 002325CC  90 1F 00 64 */	stw r0, 0x64(r31)
/* 80235690 002325D0  D0 1F 00 68 */	stfs f0, 0x68(r31)
/* 80235694 002325D4  D0 1F 00 6C */	stfs f0, 0x6c(r31)
/* 80235698 002325D8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023569C 002325DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802356A0 002325E0  7C 08 03 A6 */	mtlr r0
/* 802356A4 002325E4  38 21 00 10 */	addi r1, r1, 0x10
/* 802356A8 002325E8  4E 80 00 20 */	blr 
.endfn __ct__Q44Game6VsGame7CardMgr11SlotMachineFv

.fn clear__Q44Game6VsGame7CardMgr11SlotMachineFv, global
/* 802369C8 00233908  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 802369CC 0023390C  3C 80 00 01 */	lis r4, 0x0000FFFF@ha
/* 802369D0 00233910  38 A0 00 00 */	li r5, 0
/* 802369D4 00233914  C0 02 C0 E4 */	lfs f0, lbl_8051A444@sda21(r2)
/* 802369D8 00233918  D0 23 00 54 */	stfs f1, 0x54(r3)
/* 802369DC 0023391C  38 84 FF FF */	addi r4, r4, 0x0000FFFF@l
/* 802369E0 00233920  38 00 00 03 */	li r0, 3
/* 802369E4 00233924  90 A3 00 20 */	stw r5, 0x20(r3)
/* 802369E8 00233928  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 802369EC 0023392C  D0 23 00 00 */	stfs f1, 0(r3)
/* 802369F0 00233930  D0 23 00 10 */	stfs f1, 0x10(r3)
/* 802369F4 00233934  90 A3 00 08 */	stw r5, 8(r3)
/* 802369F8 00233938  90 A3 00 04 */	stw r5, 4(r3)
/* 802369FC 0023393C  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 80236A00 00233940  90 83 00 4C */	stw r4, 0x4c(r3)
/* 80236A04 00233944  90 83 00 58 */	stw r4, 0x58(r3)
/* 80236A08 00233948  D0 03 00 34 */	stfs f0, 0x34(r3)
/* 80236A0C 0023394C  90 03 00 30 */	stw r0, 0x30(r3)
/* 80236A10 00233950  90 A3 00 38 */	stw r5, 0x38(r3)
/* 80236A14 00233954  90 A3 00 1C */	stw r5, 0x1c(r3)
/* 80236A18 00233958  98 A3 00 51 */	stb r5, 0x51(r3)
/* 80236A1C 0023395C  4E 80 00 20 */	blr 
.endfn clear__Q44Game6VsGame7CardMgr11SlotMachineFv

.fn startStop__Q44Game6VsGame7CardMgr11SlotMachineFv, global
/* 80237010 00233F50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80237014 00233F54  7C 08 02 A6 */	mflr r0
/* 80237018 00233F58  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 8023701C 00233F5C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80237020 00233F60  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80237024 00233F64  7C 7F 1B 78 */	mr r31, r3
/* 80237028 00233F68  C0 23 00 54 */	lfs f1, 0x54(r3)
/* 8023702C 00233F6C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237030 00233F70  40 81 00 14 */	ble .L_80237044
/* 80237034 00233F74  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 80237038 00233F78  38 80 18 00 */	li r4, 0x1800
/* 8023703C 00233F7C  38 A0 00 00 */	li r5, 0
/* 80237040 00233F80  48 10 15 F1 */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
.L_80237044:
/* 80237044 00233F84  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237048 00233F88  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 8023704C 00233F8C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80237050 00233F90  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80237054 00233F94  7C 08 03 A6 */	mtlr r0
/* 80237058 00233F98  38 21 00 10 */	addi r1, r1, 0x10
/* 8023705C 00233F9C  4E 80 00 20 */	blr 
.endfn startStop__Q44Game6VsGame7CardMgr11SlotMachineFv

.fn updateAppear__Q44Game6VsGame7CardMgr11SlotMachineFv, global
/* 80237818 00234758  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023781C 0023475C  7C 08 02 A6 */	mflr r0
/* 80237820 00234760  90 01 00 14 */	stw r0, 0x14(r1)
/* 80237824 00234764  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80237828 00234768  7C 7F 1B 78 */	mr r31, r3
/* 8023782C 0023476C  80 03 00 30 */	lwz r0, 0x30(r3)
/* 80237830 00234770  2C 00 00 02 */	cmpwi r0, 2
/* 80237834 00234774  41 82 00 6C */	beq .L_802378A0
/* 80237838 00234778  40 80 00 14 */	bge .L_8023784C
/* 8023783C 0023477C  2C 00 00 00 */	cmpwi r0, 0
/* 80237840 00234780  41 82 00 18 */	beq .L_80237858
/* 80237844 00234784  40 80 00 50 */	bge .L_80237894
/* 80237848 00234788  48 00 01 0C */	b .L_80237954
.L_8023784C:
/* 8023784C 0023478C  2C 00 00 04 */	cmpwi r0, 4
/* 80237850 00234790  40 80 01 04 */	bge .L_80237954
/* 80237854 00234794  48 00 00 AC */	b .L_80237900
.L_80237858:
/* 80237858 00234798  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8023785C 0023479C  C0 62 C1 3C */	lfs f3, lbl_8051A49C@sda21(r2)
/* 80237860 002347A0  C0 43 00 54 */	lfs f2, 0x54(r3)
/* 80237864 002347A4  C0 3F 00 34 */	lfs f1, 0x34(r31)
/* 80237868 002347A8  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 8023786C 002347AC  EC 23 08 BC */	fnmsubs f1, f3, f2, f1
/* 80237870 002347B0  D0 3F 00 34 */	stfs f1, 0x34(r31)
/* 80237874 002347B4  C0 3F 00 34 */	lfs f1, 0x34(r31)
/* 80237878 002347B8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023787C 002347BC  4C 40 13 82 */	cror 2, 0, 2
/* 80237880 002347C0  40 82 00 D4 */	bne .L_80237954
/* 80237884 002347C4  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 80237888 002347C8  38 00 00 01 */	li r0, 1
/* 8023788C 002347CC  90 1F 00 30 */	stw r0, 0x30(r31)
/* 80237890 002347D0  48 00 00 C4 */	b .L_80237954
.L_80237894:
/* 80237894 002347D4  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237898 002347D8  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 8023789C 002347DC  48 00 00 B8 */	b .L_80237954
.L_802378A0:
/* 802378A0 002347E0  80 8D 9A EC */	lwz r4, sys@sda21(r13)
/* 802378A4 002347E4  C0 62 C1 3C */	lfs f3, lbl_8051A49C@sda21(r2)
/* 802378A8 002347E8  C0 44 00 54 */	lfs f2, 0x54(r4)
/* 802378AC 002347EC  C0 3F 00 34 */	lfs f1, 0x34(r31)
/* 802378B0 002347F0  C0 02 C0 FC */	lfs f0, lbl_8051A45C@sda21(r2)
/* 802378B4 002347F4  EC 23 08 BA */	fmadds f1, f3, f2, f1
/* 802378B8 002347F8  D0 3F 00 34 */	stfs f1, 0x34(r31)
/* 802378BC 002347FC  C0 3F 00 34 */	lfs f1, 0x34(r31)
/* 802378C0 00234800  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802378C4 00234804  4C 41 13 82 */	cror 2, 1, 2
/* 802378C8 00234808  40 82 00 8C */	bne .L_80237954
/* 802378CC 0023480C  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 802378D0 00234810  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 802378D4 00234814  2C 04 00 00 */	cmpwi r4, 0
/* 802378D8 00234818  40 81 00 1C */	ble .L_802378F4
/* 802378DC 0023481C  38 04 FF FF */	addi r0, r4, -1
/* 802378E0 00234820  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 802378E4 00234824  4B FF F1 3D */	bl start__Q44Game6VsGame7CardMgr11SlotMachineFv
/* 802378E8 00234828  38 00 00 00 */	li r0, 0
/* 802378EC 0023482C  98 1F 00 18 */	stb r0, 0x18(r31)
/* 802378F0 00234830  48 00 00 64 */	b .L_80237954
.L_802378F4:
/* 802378F4 00234834  38 00 00 03 */	li r0, 3
/* 802378F8 00234838  90 1F 00 30 */	stw r0, 0x30(r31)
/* 802378FC 0023483C  48 00 00 58 */	b .L_80237954
.L_80237900:
/* 80237900 00234840  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 80237904 00234844  3C 60 00 01 */	lis r3, 0x0000FFFF@ha
/* 80237908 00234848  38 80 00 00 */	li r4, 0
/* 8023790C 0023484C  C0 02 C0 E4 */	lfs f0, lbl_8051A444@sda21(r2)
/* 80237910 00234850  D0 3F 00 54 */	stfs f1, 0x54(r31)
/* 80237914 00234854  38 63 FF FF */	addi r3, r3, 0x0000FFFF@l
/* 80237918 00234858  38 00 00 03 */	li r0, 3
/* 8023791C 0023485C  90 9F 00 20 */	stw r4, 0x20(r31)
/* 80237920 00234860  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 80237924 00234864  D0 3F 00 00 */	stfs f1, 0(r31)
/* 80237928 00234868  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8023792C 0023486C  90 9F 00 08 */	stw r4, 8(r31)
/* 80237930 00234870  90 9F 00 04 */	stw r4, 4(r31)
/* 80237934 00234874  D0 3F 00 0C */	stfs f1, 0xc(r31)
/* 80237938 00234878  90 7F 00 4C */	stw r3, 0x4c(r31)
/* 8023793C 0023487C  90 7F 00 58 */	stw r3, 0x58(r31)
/* 80237940 00234880  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 80237944 00234884  90 1F 00 30 */	stw r0, 0x30(r31)
/* 80237948 00234888  90 9F 00 38 */	stw r4, 0x38(r31)
/* 8023794C 0023488C  90 9F 00 1C */	stw r4, 0x1c(r31)
/* 80237950 00234890  98 9F 00 51 */	stb r4, 0x51(r31)
.L_80237954:
/* 80237954 00234894  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80237958 00234898  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023795C 0023489C  7C 08 03 A6 */	mtlr r0
/* 80237960 002348A0  38 21 00 10 */	addi r1, r1, 0x10
/* 80237964 002348A4  4E 80 00 20 */	blr 
.endfn updateAppear__Q44Game6VsGame7CardMgr11SlotMachineFv


.fn "drawSlot__Q34Game6VsGame7CardMgrFR8GraphicsR10Vector3<f>RQ44Game6VsGame7CardMgr11SlotMachine", global
/* 80237CBC 00234BFC  94 21 FD D0 */	stwu r1, -0x230(r1)
/* 80237CC0 00234C00  7C 08 02 A6 */	mflr r0
/* 80237CC4 00234C04  90 01 02 34 */	stw r0, 0x234(r1)
/* 80237CC8 00234C08  DB E1 02 20 */	stfd f31, 0x220(r1)
/* 80237CCC 00234C0C  F3 E1 02 28 */	psq_st f31, 552(r1), 0, qr0
/* 80237CD0 00234C10  DB C1 02 10 */	stfd f30, 0x210(r1)
/* 80237CD4 00234C14  F3 C1 02 18 */	psq_st f30, 536(r1), 0, qr0
/* 80237CD8 00234C18  DB A1 02 00 */	stfd f29, 0x200(r1)
/* 80237CDC 00234C1C  F3 A1 02 08 */	psq_st f29, 520(r1), 0, qr0
/* 80237CE0 00234C20  DB 81 01 F0 */	stfd f28, 0x1f0(r1)
/* 80237CE4 00234C24  F3 81 01 F8 */	psq_st f28, 504(r1), 0, qr0
/* 80237CE8 00234C28  DB 61 01 E0 */	stfd f27, 0x1e0(r1)
/* 80237CEC 00234C2C  F3 61 01 E8 */	psq_st f27, 488(r1), 0, qr0
/* 80237CF0 00234C30  DB 41 01 D0 */	stfd f26, 0x1d0(r1)
/* 80237CF4 00234C34  F3 41 01 D8 */	psq_st f26, 472(r1), 0, qr0
/* 80237CF8 00234C38  DB 21 01 C0 */	stfd f25, 0x1c0(r1)
/* 80237CFC 00234C3C  F3 21 01 C8 */	psq_st f25, 456(r1), 0, qr0
/* 80237D00 00234C40  DB 01 01 B0 */	stfd f24, 0x1b0(r1)
/* 80237D04 00234C44  F3 01 01 B8 */	psq_st f24, 440(r1), 0, qr0
/* 80237D08 00234C48  DA E1 01 A0 */	stfd f23, 0x1a0(r1)
/* 80237D0C 00234C4C  F2 E1 01 A8 */	psq_st f23, 424(r1), 0, qr0
/* 80237D10 00234C50  DA C1 01 90 */	stfd f22, 0x190(r1)
/* 80237D14 00234C54  F2 C1 01 98 */	psq_st f22, 408(r1), 0, qr0
/* 80237D18 00234C58  DA A1 01 80 */	stfd f21, 0x180(r1)
/* 80237D1C 00234C5C  F2 A1 01 88 */	psq_st f21, 392(r1), 0, qr0
/* 80237D20 00234C60  DA 81 01 70 */	stfd f20, 0x170(r1)
/* 80237D24 00234C64  F2 81 01 78 */	psq_st f20, 376(r1), 0, qr0
/* 80237D28 00234C68  DA 61 01 60 */	stfd f19, 0x160(r1)
/* 80237D2C 00234C6C  F2 61 01 68 */	psq_st f19, 360(r1), 0, qr0
/* 80237D30 00234C70  DA 41 01 50 */	stfd f18, 0x150(r1)
/* 80237D34 00234C74  F2 41 01 58 */	psq_st f18, 344(r1), 0, qr0
/* 80237D38 00234C78  DA 21 01 40 */	stfd f17, 0x140(r1)
/* 80237D3C 00234C7C  F2 21 01 48 */	psq_st f17, 328(r1), 0, qr0
/* 80237D40 00234C80  DA 01 01 30 */	stfd f16, 0x130(r1)
/* 80237D44 00234C84  F2 01 01 38 */	psq_st f16, 312(r1), 0, qr0
/* 80237D48 00234C88  D9 E1 01 20 */	stfd f15, 0x120(r1)
/* 80237D4C 00234C8C  F1 E1 01 28 */	psq_st f15, 296(r1), 0, qr0
/* 80237D50 00234C90  BE A1 00 F4 */	stmw r21, 0xf4(r1)
/* 80237D54 00234C94  7C B6 2B 78 */	mr r22, r5
/* 80237D58 00234C98  7C 98 23 78 */	mr r24, r4
/* 80237D5C 00234C9C  C0 25 00 00 */	lfs f1, 0(r5)
/* 80237D60 00234CA0  7C 75 1B 78 */	mr r21, r3
/* 80237D64 00234CA4  7C D7 33 78 */	mr r23, r6
/* 80237D68 00234CA8  7F 03 C3 78 */	mr r3, r24
/* 80237D6C 00234CAC  D0 21 00 44 */	stfs f1, 0x44(r1)
/* 80237D70 00234CB0  38 80 00 00 */	li r4, 0
/* 80237D74 00234CB4  C0 05 00 04 */	lfs f0, 4(r5)
/* 80237D78 00234CB8  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 80237D7C 00234CBC  C0 05 00 08 */	lfs f0, 8(r5)
/* 80237D80 00234CC0  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 80237D84 00234CC4  C0 06 00 34 */	lfs f0, 0x34(r6)
/* 80237D88 00234CC8  EC 01 00 2A */	fadds f0, f1, f0
/* 80237D8C 00234CCC  D0 01 00 44 */	stfs f0, 0x44(r1)
/* 80237D90 00234CD0  C1 E6 00 00 */	lfs f15, 0(r6)
/* 80237D94 00234CD4  48 1E DA 89 */	bl initPrimDraw__8GraphicsFP7Matrixf
/* 80237D98 00234CD8  38 A0 00 FA */	li r5, 0xfa
/* 80237D9C 00234CDC  38 00 00 FF */	li r0, 0xff
/* 80237DA0 00234CE0  98 B8 00 84 */	stb r5, 0x84(r24)
/* 80237DA4 00234CE4  38 60 00 28 */	li r3, 0x28
/* 80237DA8 00234CE8  38 80 00 00 */	li r4, 0
/* 80237DAC 00234CEC  98 B8 00 85 */	stb r5, 0x85(r24)
/* 80237DB0 00234CF0  98 B8 00 86 */	stb r5, 0x86(r24)
/* 80237DB4 00234CF4  98 18 00 87 */	stb r0, 0x87(r24)
/* 80237DB8 00234CF8  4B EA DD 29 */	bl GXSetLineWidth
/* 80237DBC 00234CFC  38 78 00 BC */	addi r3, r24, 0xbc
/* 80237DC0 00234D00  81 98 00 BC */	lwz r12, 0xbc(r24)
/* 80237DC4 00234D04  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80237DC8 00234D08  7D 89 03 A6 */	mtctr r12
/* 80237DCC 00234D0C  4E 80 04 21 */	bctrl 
/* 80237DD0 00234D10  C0 22 C1 58 */	lfs f1, lbl_8051A4B8@sda21(r2)
/* 80237DD4 00234D14  3B 58 01 3C */	addi r26, r24, 0x13c
/* 80237DD8 00234D18  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237DDC 00234D1C  38 61 00 80 */	addi r3, r1, 0x80
/* 80237DE0 00234D20  EC 2F 08 2A */	fadds f1, f15, f1
/* 80237DE4 00234D24  38 81 00 44 */	addi r4, r1, 0x44
/* 80237DE8 00234D28  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 80237DEC 00234D2C  38 A1 00 38 */	addi r5, r1, 0x38
/* 80237DF0 00234D30  D0 21 00 38 */	stfs f1, 0x38(r1)
/* 80237DF4 00234D34  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 80237DF8 00234D38  48 1F 0A 91 */	bl "makeTR__7MatrixfFR10Vector3<f>R10Vector3<f>"
/* 80237DFC 00234D3C  7F 43 D3 78 */	mr r3, r26
/* 80237E00 00234D40  38 81 00 80 */	addi r4, r1, 0x80
/* 80237E04 00234D44  38 A1 00 B0 */	addi r5, r1, 0xb0
/* 80237E08 00234D48  4B EB 24 F9 */	bl PSMTXConcat
/* 80237E0C 00234D4C  38 61 00 B0 */	addi r3, r1, 0xb0
/* 80237E10 00234D50  38 80 00 00 */	li r4, 0
/* 80237E14 00234D54  4B EB 17 65 */	bl GXLoadPosMtxImm
/* 80237E18 00234D58  38 61 00 B0 */	addi r3, r1, 0xb0
/* 80237E1C 00234D5C  38 80 00 00 */	li r4, 0
/* 80237E20 00234D60  4B EB 17 A9 */	bl GXLoadNrmMtxImm
/* 80237E24 00234D64  38 60 00 01 */	li r3, 1
/* 80237E28 00234D68  4B EB 0D 91 */	bl GXSetNumTevStages
/* 80237E2C 00234D6C  38 60 00 00 */	li r3, 0
/* 80237E30 00234D70  38 80 00 0F */	li r4, 0xf
/* 80237E34 00234D74  38 A0 00 08 */	li r5, 8
/* 80237E38 00234D78  38 C0 00 0A */	li r6, 0xa
/* 80237E3C 00234D7C  38 E0 00 0F */	li r7, 0xf
/* 80237E40 00234D80  4B EB 06 C9 */	bl GXSetTevColorIn
/* 80237E44 00234D84  38 60 00 00 */	li r3, 0
/* 80237E48 00234D88  38 80 00 00 */	li r4, 0
/* 80237E4C 00234D8C  38 A0 00 00 */	li r5, 0
/* 80237E50 00234D90  38 C0 00 00 */	li r6, 0
/* 80237E54 00234D94  38 E0 00 01 */	li r7, 1
/* 80237E58 00234D98  39 00 00 00 */	li r8, 0
/* 80237E5C 00234D9C  4B EB 07 35 */	bl GXSetTevColorOp
/* 80237E60 00234DA0  38 60 00 00 */	li r3, 0
/* 80237E64 00234DA4  38 80 00 07 */	li r4, 7
/* 80237E68 00234DA8  38 A0 00 04 */	li r5, 4
/* 80237E6C 00234DAC  38 C0 00 05 */	li r6, 5
/* 80237E70 00234DB0  38 E0 00 07 */	li r7, 7
/* 80237E74 00234DB4  4B EB 06 D9 */	bl GXSetTevAlphaIn
/* 80237E78 00234DB8  38 60 00 00 */	li r3, 0
/* 80237E7C 00234DBC  38 80 00 00 */	li r4, 0
/* 80237E80 00234DC0  38 A0 00 00 */	li r5, 0
/* 80237E84 00234DC4  38 C0 00 00 */	li r6, 0
/* 80237E88 00234DC8  38 E0 00 01 */	li r7, 1
/* 80237E8C 00234DCC  39 00 00 00 */	li r8, 0
/* 80237E90 00234DD0  4B EB 07 69 */	bl GXSetTevAlphaOp
/* 80237E94 00234DD4  38 60 00 00 */	li r3, 0
/* 80237E98 00234DD8  38 80 00 00 */	li r4, 0
/* 80237E9C 00234DDC  38 A0 00 00 */	li r5, 0
/* 80237EA0 00234DE0  38 C0 00 04 */	li r6, 4
/* 80237EA4 00234DE4  4B EB 0B 79 */	bl GXSetTevOrder
/* 80237EA8 00234DE8  38 60 00 01 */	li r3, 1
/* 80237EAC 00234DEC  4B EA EF B9 */	bl GXSetNumChans
/* 80237EB0 00234DF0  38 60 00 00 */	li r3, 0
/* 80237EB4 00234DF4  38 80 00 01 */	li r4, 1
/* 80237EB8 00234DF8  38 A0 00 00 */	li r5, 0
/* 80237EBC 00234DFC  38 C0 00 00 */	li r6, 0
/* 80237EC0 00234E00  38 E0 00 01 */	li r7, 1
/* 80237EC4 00234E04  39 00 00 02 */	li r8, 2
/* 80237EC8 00234E08  39 20 00 01 */	li r9, 1
/* 80237ECC 00234E0C  4B EA EF D5 */	bl GXSetChanCtrl
/* 80237ED0 00234E10  38 60 00 02 */	li r3, 2
/* 80237ED4 00234E14  38 80 00 00 */	li r4, 0
/* 80237ED8 00234E18  38 A0 00 00 */	li r5, 0
/* 80237EDC 00234E1C  38 C0 00 00 */	li r6, 0
/* 80237EE0 00234E20  38 E0 00 01 */	li r7, 1
/* 80237EE4 00234E24  39 00 00 00 */	li r8, 0
/* 80237EE8 00234E28  39 20 00 02 */	li r9, 2
/* 80237EEC 00234E2C  4B EA EF B5 */	bl GXSetChanCtrl
/* 80237EF0 00234E30  80 02 C1 48 */	lwz r0, lbl_8051A4A8@sda21(r2)
/* 80237EF4 00234E34  38 81 00 18 */	addi r4, r1, 0x18
/* 80237EF8 00234E38  38 60 00 04 */	li r3, 4
/* 80237EFC 00234E3C  90 01 00 18 */	stw r0, 0x18(r1)
/* 80237F00 00234E40  4B EA ED 85 */	bl GXSetChanAmbColor
/* 80237F04 00234E44  80 02 C1 4C */	lwz r0, lbl_8051A4AC@sda21(r2)
/* 80237F08 00234E48  38 81 00 14 */	addi r4, r1, 0x14
/* 80237F0C 00234E4C  38 60 00 04 */	li r3, 4
/* 80237F10 00234E50  90 01 00 14 */	stw r0, 0x14(r1)
/* 80237F14 00234E54  4B EA EE 61 */	bl GXSetChanMatColor
/* 80237F18 00234E58  80 75 01 08 */	lwz r3, 0x108(r21)
/* 80237F1C 00234E5C  81 83 00 00 */	lwz r12, 0(r3)
/* 80237F20 00234E60  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80237F24 00234E64  7D 89 03 A6 */	mtctr r12
/* 80237F28 00234E68  4E 80 04 21 */	bctrl 
/* 80237F2C 00234E6C  80 75 01 08 */	lwz r3, 0x108(r21)
/* 80237F30 00234E70  7F 44 D3 78 */	mr r4, r26
/* 80237F34 00234E74  81 83 00 00 */	lwz r12, 0(r3)
/* 80237F38 00234E78  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80237F3C 00234E7C  7D 89 03 A6 */	mtctr r12
/* 80237F40 00234E80  4E 80 04 21 */	bctrl 
/* 80237F44 00234E84  4B EA C7 8D */	bl GXClearVtxDesc
/* 80237F48 00234E88  38 60 00 09 */	li r3, 9
/* 80237F4C 00234E8C  38 80 00 01 */	li r4, 1
/* 80237F50 00234E90  4B EA C3 35 */	bl GXSetVtxDesc
/* 80237F54 00234E94  38 60 00 0A */	li r3, 0xa
/* 80237F58 00234E98  38 80 00 01 */	li r4, 1
/* 80237F5C 00234E9C  4B EA C3 29 */	bl GXSetVtxDesc
/* 80237F60 00234EA0  38 60 00 0D */	li r3, 0xd
/* 80237F64 00234EA4  38 80 00 01 */	li r4, 1
/* 80237F68 00234EA8  4B EA C3 1D */	bl GXSetVtxDesc
/* 80237F6C 00234EAC  38 60 00 00 */	li r3, 0
/* 80237F70 00234EB0  38 80 00 09 */	li r4, 9
/* 80237F74 00234EB4  38 A0 00 01 */	li r5, 1
/* 80237F78 00234EB8  38 C0 00 04 */	li r6, 4
/* 80237F7C 00234EBC  38 E0 00 00 */	li r7, 0
/* 80237F80 00234EC0  4B EA C7 89 */	bl GXSetVtxAttrFmt
/* 80237F84 00234EC4  38 60 00 00 */	li r3, 0
/* 80237F88 00234EC8  38 80 00 0A */	li r4, 0xa
/* 80237F8C 00234ECC  38 A0 00 00 */	li r5, 0
/* 80237F90 00234ED0  38 C0 00 04 */	li r6, 4
/* 80237F94 00234ED4  38 E0 00 00 */	li r7, 0
/* 80237F98 00234ED8  4B EA C7 71 */	bl GXSetVtxAttrFmt
/* 80237F9C 00234EDC  38 60 00 00 */	li r3, 0
/* 80237FA0 00234EE0  38 80 00 0D */	li r4, 0xd
/* 80237FA4 00234EE4  38 A0 00 01 */	li r5, 1
/* 80237FA8 00234EE8  38 C0 00 04 */	li r6, 4
/* 80237FAC 00234EEC  38 E0 00 00 */	li r7, 0
/* 80237FB0 00234EF0  4B EA C7 59 */	bl GXSetVtxAttrFmt
/* 80237FB4 00234EF4  38 60 00 01 */	li r3, 1
/* 80237FB8 00234EF8  38 80 00 04 */	li r4, 4
/* 80237FBC 00234EFC  38 A0 00 05 */	li r5, 5
/* 80237FC0 00234F00  38 C0 00 0F */	li r6, 0xf
/* 80237FC4 00234F04  4B EB 11 15 */	bl GXSetBlendMode
/* 80237FC8 00234F08  38 60 00 01 */	li r3, 1
/* 80237FCC 00234F0C  4B EB 11 61 */	bl GXSetColorUpdate
/* 80237FD0 00234F10  38 60 00 00 */	li r3, 0
/* 80237FD4 00234F14  38 80 00 01 */	li r4, 1
/* 80237FD8 00234F18  38 A0 00 00 */	li r5, 0
/* 80237FDC 00234F1C  4B EB 11 A9 */	bl GXSetZMode
/* 80237FE0 00234F20  38 60 00 01 */	li r3, 1
/* 80237FE4 00234F24  38 80 00 01 */	li r4, 1
/* 80237FE8 00234F28  38 A0 00 01 */	li r5, 1
/* 80237FEC 00234F2C  4B EB 11 99 */	bl GXSetZMode
/* 80237FF0 00234F30  38 60 00 00 */	li r3, 0
/* 80237FF4 00234F34  4B EB 16 25 */	bl GXSetCurrentMtx
/* 80237FF8 00234F38  38 60 00 01 */	li r3, 1
/* 80237FFC 00234F3C  4B EA CF A1 */	bl GXSetNumTexGens
/* 80238000 00234F40  38 60 00 00 */	li r3, 0
/* 80238004 00234F44  38 80 00 01 */	li r4, 1
/* 80238008 00234F48  38 A0 00 0C */	li r5, 0xc
/* 8023800C 00234F4C  38 C0 00 3C */	li r6, 0x3c
/* 80238010 00234F50  38 E0 00 00 */	li r7, 0
/* 80238014 00234F54  39 00 00 7D */	li r8, 0x7d
/* 80238018 00234F58  4B EA CD 05 */	bl GXSetTexCoordGen2
/* 8023801C 00234F5C  38 60 00 02 */	li r3, 2
/* 80238020 00234F60  4B EA DB 89 */	bl GXSetCullMode
/* 80238024 00234F64  3B 80 00 00 */	li r28, 0
/* 80238028 00234F68  CB 62 C0 88 */	lfd f27, lbl_8051A3E8@sda21(r2)
/* 8023802C 00234F6C  C3 82 C1 44 */	lfs f28, lbl_8051A4A4@sda21(r2)
/* 80238030 00234F70  7F 9B E3 78 */	mr r27, r28
/* 80238034 00234F74  C3 C2 C0 78 */	lfs f30, lbl_8051A3D8@sda21(r2)
/* 80238038 00234F78  3B 20 00 00 */	li r25, 0
/* 8023803C 00234F7C  C3 A2 C0 F4 */	lfs f29, lbl_8051A454@sda21(r2)
/* 80238040 00234F80  3F C0 43 30 */	lis r30, 0x4330
/* 80238044 00234F84  3F E0 CC 01 */	lis r31, 0xcc01
.L_80238048:
/* 80238048 00234F88  80 75 00 04 */	lwz r3, 4(r21)
/* 8023804C 00234F8C  38 80 00 00 */	li r4, 0
/* 80238050 00234F90  7C 63 E0 2E */	lwzx r3, r3, r28
/* 80238054 00234F94  4B DF B5 DD */	bl load__10JUTTextureF11_GXTexMapID
/* 80238058 00234F98  3B 00 00 00 */	li r24, 0
/* 8023805C 00234F9C  7F 7D DB 78 */	mr r29, r27
.L_80238060:
/* 80238060 00234FA0  38 18 00 01 */	addi r0, r24, 1
/* 80238064 00234FA4  93 C1 00 E0 */	stw r30, 0xe0(r1)
/* 80238068 00234FA8  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8023806C 00234FAC  38 60 00 98 */	li r3, 0x98
/* 80238070 00234FB0  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 80238074 00234FB4  38 80 00 00 */	li r4, 0
/* 80238078 00234FB8  38 A0 00 04 */	li r5, 4
/* 8023807C 00234FBC  C8 01 00 E0 */	lfd f0, 0xe0(r1)
/* 80238080 00234FC0  EC 00 D8 28 */	fsubs f0, f0, f27
/* 80238084 00234FC4  EF E0 07 32 */	fmuls f31, f0, f28
/* 80238088 00234FC8  4B EA D9 01 */	bl GXBegin
/* 8023808C 00234FCC  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 80238090 00234FD0  38 DD 00 01 */	addi r6, r29, 1
/* 80238094 00234FD4  80 95 00 FC */	lwz r4, 0xfc(r21)
/* 80238098 00234FD8  38 BD 00 02 */	addi r5, r29, 2
/* 8023809C 00234FDC  7C 1D 1B D6 */	divw r0, r29, r3
/* 802380A0 00234FE0  7C 00 19 D6 */	mullw r0, r0, r3
/* 802380A4 00234FE4  7C 00 E8 50 */	subf r0, r0, r29
/* 802380A8 00234FE8  1C 00 00 0C */	mulli r0, r0, 0xc
/* 802380AC 00234FEC  7C 64 02 14 */	add r3, r4, r0
/* 802380B0 00234FF0  C0 43 00 08 */	lfs f2, 8(r3)
/* 802380B4 00234FF4  C0 23 00 04 */	lfs f1, 4(r3)
/* 802380B8 00234FF8  C0 03 00 00 */	lfs f0, 0(r3)
/* 802380BC 00234FFC  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 802380C0 00235000  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 802380C4 00235004  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 802380C8 00235008  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 802380CC 0023500C  80 95 01 00 */	lwz r4, 0x100(r21)
/* 802380D0 00235010  7C 1D 1B D6 */	divw r0, r29, r3
/* 802380D4 00235014  7C 00 19 D6 */	mullw r0, r0, r3
/* 802380D8 00235018  7C 00 E8 50 */	subf r0, r0, r29
/* 802380DC 0023501C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 802380E0 00235020  7C 64 02 14 */	add r3, r4, r0
/* 802380E4 00235024  C0 43 00 08 */	lfs f2, 8(r3)
/* 802380E8 00235028  C0 23 00 04 */	lfs f1, 4(r3)
/* 802380EC 0023502C  C0 03 00 00 */	lfs f0, 0(r3)
/* 802380F0 00235030  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 802380F4 00235034  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 802380F8 00235038  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 802380FC 0023503C  D3 DF 80 00 */	stfs f30, 0xCC008000@l(r31)
/* 80238100 00235040  D3 FF 80 00 */	stfs f31, 0xCC008000@l(r31)
/* 80238104 00235044  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 80238108 00235048  80 95 00 FC */	lwz r4, 0xfc(r21)
/* 8023810C 0023504C  7C 06 1B D6 */	divw r0, r6, r3
/* 80238110 00235050  7C 00 19 D6 */	mullw r0, r0, r3
/* 80238114 00235054  7C 00 30 50 */	subf r0, r0, r6
/* 80238118 00235058  1C 00 00 0C */	mulli r0, r0, 0xc
/* 8023811C 0023505C  7C 64 02 14 */	add r3, r4, r0
/* 80238120 00235060  C0 43 00 08 */	lfs f2, 8(r3)
/* 80238124 00235064  C0 23 00 04 */	lfs f1, 4(r3)
/* 80238128 00235068  C0 03 00 00 */	lfs f0, 0(r3)
/* 8023812C 0023506C  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 80238130 00235070  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 80238134 00235074  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 80238138 00235078  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 8023813C 0023507C  80 95 01 00 */	lwz r4, 0x100(r21)
/* 80238140 00235080  7C 06 1B D6 */	divw r0, r6, r3
/* 80238144 00235084  7C 00 19 D6 */	mullw r0, r0, r3
/* 80238148 00235088  7C 00 30 50 */	subf r0, r0, r6
/* 8023814C 0023508C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80238150 00235090  7C 64 02 14 */	add r3, r4, r0
/* 80238154 00235094  C0 43 00 08 */	lfs f2, 8(r3)
/* 80238158 00235098  C0 23 00 04 */	lfs f1, 4(r3)
/* 8023815C 0023509C  C0 03 00 00 */	lfs f0, 0(r3)
/* 80238160 002350A0  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 80238164 002350A4  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 80238168 002350A8  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 8023816C 002350AC  D3 BF 80 00 */	stfs f29, 0xCC008000@l(r31)
/* 80238170 002350B0  D3 FF 80 00 */	stfs f31, 0xCC008000@l(r31)
/* 80238174 002350B4  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 80238178 002350B8  80 95 00 FC */	lwz r4, 0xfc(r21)
/* 8023817C 002350BC  7C 05 1B D6 */	divw r0, r5, r3
/* 80238180 002350C0  7C 00 19 D6 */	mullw r0, r0, r3
/* 80238184 002350C4  7C 00 28 50 */	subf r0, r0, r5
/* 80238188 002350C8  1C 00 00 0C */	mulli r0, r0, 0xc
/* 8023818C 002350CC  7C 64 02 14 */	add r3, r4, r0
/* 80238190 002350D0  C0 43 00 08 */	lfs f2, 8(r3)
/* 80238194 002350D4  C0 23 00 04 */	lfs f1, 4(r3)
/* 80238198 002350D8  C0 03 00 00 */	lfs f0, 0(r3)
/* 8023819C 002350DC  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 802381A0 002350E0  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 802381A4 002350E4  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 802381A8 002350E8  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 802381AC 002350EC  80 95 01 00 */	lwz r4, 0x100(r21)
/* 802381B0 002350F0  7C 05 1B D6 */	divw r0, r5, r3
/* 802381B4 002350F4  7C 00 19 D6 */	mullw r0, r0, r3
/* 802381B8 002350F8  7C 00 28 50 */	subf r0, r0, r5
/* 802381BC 002350FC  1C 00 00 0C */	mulli r0, r0, 0xc
/* 802381C0 00235100  7C 64 02 14 */	add r3, r4, r0
/* 802381C4 00235104  C0 63 00 08 */	lfs f3, 8(r3)
/* 802381C8 00235108  38 BD 00 03 */	addi r5, r29, 3
/* 802381CC 0023510C  C0 43 00 04 */	lfs f2, 4(r3)
/* 802381D0 00235110  3B 18 00 01 */	addi r24, r24, 1
/* 802381D4 00235114  C0 03 00 00 */	lfs f0, 0(r3)
/* 802381D8 00235118  EC 3F E0 2A */	fadds f1, f31, f28
/* 802381DC 0023511C  2C 18 00 20 */	cmpwi r24, 0x20
/* 802381E0 00235120  3B BD 00 02 */	addi r29, r29, 2
/* 802381E4 00235124  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 802381E8 00235128  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 802381EC 0023512C  D0 7F 80 00 */	stfs f3, 0xCC008000@l(r31)
/* 802381F0 00235130  D3 DF 80 00 */	stfs f30, 0xCC008000@l(r31)
/* 802381F4 00235134  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 802381F8 00235138  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 802381FC 0023513C  80 95 00 FC */	lwz r4, 0xfc(r21)
/* 80238200 00235140  7C 05 1B D6 */	divw r0, r5, r3
/* 80238204 00235144  7C 00 19 D6 */	mullw r0, r0, r3
/* 80238208 00235148  7C 00 28 50 */	subf r0, r0, r5
/* 8023820C 0023514C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80238210 00235150  7C 64 02 14 */	add r3, r4, r0
/* 80238214 00235154  C0 63 00 08 */	lfs f3, 8(r3)
/* 80238218 00235158  C0 43 00 04 */	lfs f2, 4(r3)
/* 8023821C 0023515C  C0 03 00 00 */	lfs f0, 0(r3)
/* 80238220 00235160  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 80238224 00235164  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 80238228 00235168  D0 7F 80 00 */	stfs f3, 0xCC008000@l(r31)
/* 8023822C 0023516C  80 75 00 F8 */	lwz r3, 0xf8(r21)
/* 80238230 00235170  80 95 01 00 */	lwz r4, 0x100(r21)
/* 80238234 00235174  7C 05 1B D6 */	divw r0, r5, r3
/* 80238238 00235178  7C 00 19 D6 */	mullw r0, r0, r3
/* 8023823C 0023517C  7C 00 28 50 */	subf r0, r0, r5
/* 80238240 00235180  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80238244 00235184  7C 64 02 14 */	add r3, r4, r0
/* 80238248 00235188  C0 63 00 08 */	lfs f3, 8(r3)
/* 8023824C 0023518C  C0 43 00 04 */	lfs f2, 4(r3)
/* 80238250 00235190  C0 03 00 00 */	lfs f0, 0(r3)
/* 80238254 00235194  D0 1F 80 00 */	stfs f0, 0xCC008000@l(r31)
/* 80238258 00235198  D0 5F 80 00 */	stfs f2, 0xCC008000@l(r31)
/* 8023825C 0023519C  D0 7F 80 00 */	stfs f3, 0xCC008000@l(r31)
/* 80238260 002351A0  D3 BF 80 00 */	stfs f29, 0xCC008000@l(r31)
/* 80238264 002351A4  D0 3F 80 00 */	stfs f1, 0xCC008000@l(r31)
/* 80238268 002351A8  41 80 FD F8 */	blt .L_80238060
/* 8023826C 002351AC  3B 39 00 01 */	addi r25, r25, 1
/* 80238270 002351B0  3B 7B 00 40 */	addi r27, r27, 0x40
lwz r3, CardCount__Q24Game6VsGame@sda21(r13)
/* 80238274 002351B4  2C 19 00 0C */	cmpw r25, r3
/* 80238278 002351B8  3B 9C 00 04 */	addi r28, r28, 4
/* 8023827C 002351BC  41 80 FD CC */	blt .L_80238048
/* 80238280 002351C0  80 17 00 38 */	lwz r0, 0x38(r23)
/* 80238284 002351C4  2C 00 00 01 */	cmpwi r0, 1
/* 80238288 002351C8  40 82 00 10 */	bne .L_80238298
/* 8023828C 002351CC  7E E3 BB 78 */	mr r3, r23
/* 80238290 002351D0  48 00 08 C5 */	bl updateZoomIn__Q44Game6VsGame7CardMgr11SlotMachineFv
/* 80238294 002351D4  48 00 00 14 */	b .L_802382A8
.L_80238298:
/* 80238298 002351D8  2C 00 00 02 */	cmpwi r0, 2
/* 8023829C 002351DC  40 82 00 0C */	bne .L_802382A8
/* 802382A0 002351E0  7E E3 BB 78 */	mr r3, r23
/* 802382A4 002351E4  48 00 0A A1 */	bl updateZoomUse__Q44Game6VsGame7CardMgr11SlotMachineFv
.L_802382A8:
/* 802382A8 002351E8  80 17 00 38 */	lwz r0, 0x38(r23)
/* 802382AC 002351EC  2C 00 00 00 */	cmpwi r0, 0
/* 802382B0 002351F0  41 82 06 24 */	beq .L_802388D4
/* 802382B4 002351F4  88 17 00 51 */	lbz r0, 0x51(r23)
/* 802382B8 002351F8  28 00 00 00 */	cmplwi r0, 0
/* 802382BC 002351FC  41 82 06 18 */	beq .L_802388D4
/* 802382C0 00235200  3C 60 80 51 */	lis r3, gGameConfig__4Game@ha
/* 802382C4 00235204  C0 41 00 44 */	lfs f2, 0x44(r1)
/* 802382C8 00235208  3B E3 41 FC */	addi r31, r3, gGameConfig__4Game@l
/* 802382CC 0023520C  C0 21 00 48 */	lfs f1, 0x48(r1)
/* 802382D0 00235210  80 1F 01 B8 */	lwz r0, 0x1b8(r31)
/* 802382D4 00235214  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 802382D8 00235218  2C 00 00 00 */	cmpwi r0, 0
/* 802382DC 0023521C  D0 41 00 2C */	stfs f2, 0x2c(r1)
/* 802382E0 00235220  D0 21 00 30 */	stfs f1, 0x30(r1)
/* 802382E4 00235224  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 802382E8 00235228  41 82 00 2C */	beq .L_80238314
/* 802382EC 0023522C  C0 56 00 00 */	lfs f2, 0(r22)
/* 802382F0 00235230  C0 22 C0 DC */	lfs f1, lbl_8051A43C@sda21(r2)
/* 802382F4 00235234  D0 41 00 2C */	stfs f2, 0x2c(r1)
/* 802382F8 00235238  C0 16 00 04 */	lfs f0, 4(r22)
/* 802382FC 0023523C  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 80238300 00235240  C0 16 00 08 */	lfs f0, 8(r22)
/* 80238304 00235244  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 80238308 00235248  C0 17 00 34 */	lfs f0, 0x34(r23)
/* 8023830C 0023524C  EC 01 10 3A */	fmadds f0, f1, f0, f2
/* 80238310 00235250  D0 01 00 2C */	stfs f0, 0x2c(r1)
.L_80238314:
/* 80238314 00235254  80 02 C1 50 */	lwz r0, lbl_8051A4B0@sda21(r2)
/* 80238318 00235258  38 81 00 10 */	addi r4, r1, 0x10
/* 8023831C 0023525C  38 60 00 04 */	li r3, 4
/* 80238320 00235260  90 01 00 10 */	stw r0, 0x10(r1)
/* 80238324 00235264  4B EA EA 51 */	bl GXSetChanMatColor
/* 80238328 00235268  38 60 00 00 */	li r3, 0
/* 8023832C 0023526C  38 80 00 01 */	li r4, 1
/* 80238330 00235270  38 A0 00 00 */	li r5, 0
/* 80238334 00235274  4B EB 0E 51 */	bl GXSetZMode
/* 80238338 00235278  C0 37 00 40 */	lfs f1, 0x40(r23)
/* 8023833C 0023527C  38 61 00 50 */	addi r3, r1, 0x50
/* 80238340 00235280  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80238344 00235284  38 81 00 2C */	addi r4, r1, 0x2c
/* 80238348 00235288  D0 21 00 28 */	stfs f1, 0x28(r1)
/* 8023834C 0023528C  38 A1 00 20 */	addi r5, r1, 0x20
/* 80238350 00235290  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 80238354 00235294  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 80238358 00235298  48 1F 05 31 */	bl "makeTR__7MatrixfFR10Vector3<f>R10Vector3<f>"
/* 8023835C 0023529C  7F 43 D3 78 */	mr r3, r26
/* 80238360 002352A0  38 81 00 50 */	addi r4, r1, 0x50
/* 80238364 002352A4  38 A1 00 B0 */	addi r5, r1, 0xb0
/* 80238368 002352A8  4B EB 1F 99 */	bl PSMTXConcat
/* 8023836C 002352AC  38 61 00 B0 */	addi r3, r1, 0xb0
/* 80238370 002352B0  38 80 00 00 */	li r4, 0
/* 80238374 002352B4  4B EB 12 05 */	bl GXLoadPosMtxImm
/* 80238378 002352B8  38 61 00 B0 */	addi r3, r1, 0xb0
/* 8023837C 002352BC  38 80 00 00 */	li r4, 0
/* 80238380 002352C0  4B EB 12 49 */	bl GXLoadNrmMtxImm
/* 80238384 002352C4  80 D7 00 4C */	lwz r6, 0x4c(r23)
/* 80238388 002352C8  38 00 00 00 */	li r0, 0
.L_802383C0:
/* 802383C0 00235300  80 17 00 4C */	lwz r0, 0x4c(r23)
/* 802383C4 00235304  38 80 00 00 */	li r4, 0
/* 802383C8 00235308  80 75 00 04 */	lwz r3, 4(r21)
/* 802383CC 0023530C  54 00 10 3A */	slwi r0, r0, 2
/* 802383D0 00235310  7C 63 00 2E */	lwzx r3, r3, r0
/* 802383D4 00235314  4B DF B2 5D */	bl load__10JUTTextureF11_GXTexMapID
/* 802383D8 00235318  38 60 00 00 */	li r3, 0
/* 802383DC 0023531C  38 80 00 00 */	li r4, 0
/* 802383E0 00235320  4B EB 00 9D */	bl GXSetTevOp
/* 802383E4 00235324  38 60 00 02 */	li r3, 2
/* 802383E8 00235328  4B EB 07 D1 */	bl GXSetNumTevStages
/* 802383EC 0023532C  38 60 00 00 */	li r3, 0
/* 802383F0 00235330  38 80 00 00 */	li r4, 0
/* 802383F4 00235334  38 A0 00 00 */	li r5, 0
/* 802383F8 00235338  38 C0 00 04 */	li r6, 4
/* 802383FC 0023533C  4B EB 06 21 */	bl GXSetTevOrder
/* 80238400 00235340  38 60 00 01 */	li r3, 1
/* 80238404 00235344  38 80 00 01 */	li r4, 1
/* 80238408 00235348  38 A0 00 01 */	li r5, 1
/* 8023840C 0023534C  38 C0 00 04 */	li r6, 4
/* 80238410 00235350  4B EB 06 0D */	bl GXSetTevOrder
/* 80238414 00235354  80 75 00 14 */	lwz r3, 0x14(r21)
/* 80238418 00235358  38 80 00 01 */	li r4, 1
/* 8023841C 0023535C  4B DF B2 15 */	bl load__10JUTTextureF11_GXTexMapID
/* 80238420 00235360  38 60 00 02 */	li r3, 2
/* 80238424 00235364  4B EA CB 79 */	bl GXSetNumTexGens
/* 80238428 00235368  38 60 00 00 */	li r3, 0
/* 8023842C 0023536C  38 80 00 01 */	li r4, 1
/* 80238430 00235370  38 A0 00 04 */	li r5, 4
/* 80238434 00235374  38 C0 00 3C */	li r6, 0x3c
/* 80238438 00235378  38 E0 00 00 */	li r7, 0
/* 8023843C 0023537C  39 00 00 7D */	li r8, 0x7d
/* 80238440 00235380  4B EA C8 DD */	bl GXSetTexCoordGen2
/* 80238444 00235384  38 60 00 01 */	li r3, 1
/* 80238448 00235388  38 80 00 01 */	li r4, 1
/* 8023844C 0023538C  38 A0 00 05 */	li r5, 5
/* 80238450 00235390  38 C0 00 3C */	li r6, 0x3c
/* 80238454 00235394  38 E0 00 00 */	li r7, 0
/* 80238458 00235398  39 00 00 7D */	li r8, 0x7d
/* 8023845C 0023539C  4B EA C8 C1 */	bl GXSetTexCoordGen2
/* 80238460 002353A0  4B EA C2 71 */	bl GXClearVtxDesc
/* 80238464 002353A4  38 60 00 09 */	li r3, 9
/* 80238468 002353A8  38 80 00 01 */	li r4, 1
/* 8023846C 002353AC  4B EA BE 19 */	bl GXSetVtxDesc
/* 80238470 002353B0  38 60 00 0A */	li r3, 0xa
/* 80238474 002353B4  38 80 00 01 */	li r4, 1
/* 80238478 002353B8  4B EA BE 0D */	bl GXSetVtxDesc
/* 8023847C 002353BC  38 60 00 0D */	li r3, 0xd
/* 80238480 002353C0  38 80 00 01 */	li r4, 1
/* 80238484 002353C4  4B EA BE 01 */	bl GXSetVtxDesc
/* 80238488 002353C8  38 60 00 0E */	li r3, 0xe
/* 8023848C 002353CC  38 80 00 01 */	li r4, 1
/* 80238490 002353D0  4B EA BD F5 */	bl GXSetVtxDesc
/* 80238494 002353D4  38 60 00 00 */	li r3, 0
/* 80238498 002353D8  38 80 00 09 */	li r4, 9
/* 8023849C 002353DC  38 A0 00 01 */	li r5, 1
/* 802384A0 002353E0  38 C0 00 04 */	li r6, 4
/* 802384A4 002353E4  38 E0 00 00 */	li r7, 0
/* 802384A8 002353E8  4B EA C2 61 */	bl GXSetVtxAttrFmt
/* 802384AC 002353EC  38 60 00 00 */	li r3, 0
/* 802384B0 002353F0  38 80 00 0A */	li r4, 0xa
/* 802384B4 002353F4  38 A0 00 00 */	li r5, 0
/* 802384B8 002353F8  38 C0 00 04 */	li r6, 4
/* 802384BC 002353FC  38 E0 00 00 */	li r7, 0
/* 802384C0 00235400  4B EA C2 49 */	bl GXSetVtxAttrFmt
/* 802384C4 00235404  38 60 00 00 */	li r3, 0
/* 802384C8 00235408  38 80 00 0D */	li r4, 0xd
/* 802384CC 0023540C  38 A0 00 01 */	li r5, 1
/* 802384D0 00235410  38 C0 00 04 */	li r6, 4
/* 802384D4 00235414  38 E0 00 00 */	li r7, 0
/* 802384D8 00235418  4B EA C2 31 */	bl GXSetVtxAttrFmt
/* 802384DC 0023541C  38 60 00 00 */	li r3, 0
/* 802384E0 00235420  38 80 00 0E */	li r4, 0xe
/* 802384E4 00235424  38 A0 00 01 */	li r5, 1
/* 802384E8 00235428  38 C0 00 04 */	li r6, 4
/* 802384EC 0023542C  38 E0 00 00 */	li r7, 0
/* 802384F0 00235430  4B EA C2 19 */	bl GXSetVtxAttrFmt
/* 802384F4 00235434  38 60 00 01 */	li r3, 1
/* 802384F8 00235438  38 80 00 0F */	li r4, 0xf
/* 802384FC 0023543C  38 A0 00 08 */	li r5, 8
/* 80238500 00235440  38 C0 00 02 */	li r6, 2
/* 80238504 00235444  38 E0 00 00 */	li r7, 0
/* 80238508 00235448  4B EB 00 01 */	bl GXSetTevColorIn
/* 8023850C 0023544C  38 60 00 01 */	li r3, 1
/* 80238510 00235450  38 80 00 00 */	li r4, 0
/* 80238514 00235454  38 A0 00 00 */	li r5, 0
/* 80238518 00235458  38 C0 00 00 */	li r6, 0
/* 8023851C 0023545C  38 E0 00 01 */	li r7, 1
/* 80238520 00235460  39 00 00 00 */	li r8, 0
/* 80238524 00235464  4B EB 00 6D */	bl GXSetTevColorOp
/* 80238528 00235468  38 60 00 01 */	li r3, 1
/* 8023852C 0023546C  38 80 00 07 */	li r4, 7
/* 80238530 00235470  38 A0 00 07 */	li r5, 7
/* 80238534 00235474  38 C0 00 07 */	li r6, 7
/* 80238538 00235478  38 E0 00 00 */	li r7, 0
/* 8023853C 0023547C  4B EB 00 11 */	bl GXSetTevAlphaIn
/* 80238540 00235480  38 60 00 01 */	li r3, 1
/* 80238544 00235484  38 80 00 00 */	li r4, 0
/* 80238548 00235488  38 A0 00 00 */	li r5, 0
/* 8023854C 0023548C  38 C0 00 00 */	li r6, 0
/* 80238550 00235490  38 E0 00 01 */	li r7, 1
/* 80238554 00235494  39 00 00 00 */	li r8, 0
/* 80238558 00235498  4B EB 00 A1 */	bl GXSetTevAlphaOp
/* 8023855C 0023549C  C0 42 C0 E8 */	lfs f2, lbl_8051A448@sda21(r2)
/* 80238560 002354A0  C0 37 00 6C */	lfs f1, 0x6c(r23)
/* 80238564 002354A4  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80238568 002354A8  EC 42 00 72 */	fmuls f2, f2, f1
/* 8023856C 002354AC  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80238570 002354B0  40 80 00 08 */	bge .L_80238578
/* 80238574 002354B4  FC 40 10 50 */	fneg f2, f2
.L_80238578:
/* 80238578 002354B8  C0 02 C0 EC */	lfs f0, lbl_8051A44C@sda21(r2)
/* 8023857C 002354BC  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 80238580 002354C0  38 A3 71 A0 */	addi r5, r3, sincosTable___5JMath@l
/* 80238584 002354C4  C0 22 C0 F4 */	lfs f1, lbl_8051A454@sda21(r2)
/* 80238588 002354C8  EC 02 00 32 */	fmuls f0, f2, f0
/* 8023858C 002354CC  C8 42 C1 60 */	lfd f2, lbl_8051A4C0@sda21(r2)
/* 80238590 002354D0  38 81 00 0C */	addi r4, r1, 0xc
/* 80238594 002354D4  38 60 00 01 */	li r3, 1
/* 80238598 002354D8  FC 00 00 1E */	fctiwz f0, f0
/* 8023859C 002354DC  D8 01 00 E0 */	stfd f0, 0xe0(r1)
/* 802385A0 002354E0  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 802385A4 002354E4  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 802385A8 002354E8  7C A5 02 14 */	add r5, r5, r0
/* 802385AC 002354EC  C0 05 00 04 */	lfs f0, 4(r5)
/* 802385B0 002354F0  EC 01 00 28 */	fsubs f0, f1, f0
/* 802385B4 002354F4  FC 02 00 32 */	fmul f0, f2, f0
/* 802385B8 002354F8  FC 00 00 18 */	frsp f0, f0
/* 802385BC 002354FC  FC 00 00 1E */	fctiwz f0, f0
/* 802385C0 00235500  D8 01 00 E8 */	stfd f0, 0xe8(r1)
/* 802385C4 00235504  80 01 00 EC */	lwz r0, 0xec(r1)
/* 802385C8 00235508  98 01 00 1F */	stb r0, 0x1f(r1)
/* 802385CC 0023550C  98 01 00 1D */	stb r0, 0x1d(r1)
/* 802385D0 00235510  98 01 00 1E */	stb r0, 0x1e(r1)
/* 802385D4 00235514  98 01 00 1C */	stb r0, 0x1c(r1)
/* 802385D8 00235518  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 802385DC 0023551C  90 01 00 0C */	stw r0, 0xc(r1)
/* 802385E0 00235520  4B EB 00 81 */	bl GXSetTevColor
/* 802385E4 00235524  C0 37 00 68 */	lfs f1, 0x68(r23)
/* 802385E8 00235528  C0 02 C0 F4 */	lfs f0, lbl_8051A454@sda21(r2)
/* 802385EC 0023552C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802385F0 00235530  40 81 00 0C */	ble .L_802385FC
/* 802385F4 00235534  EC 01 00 28 */	fsubs f0, f1, f0
/* 802385F8 00235538  D0 17 00 68 */	stfs f0, 0x68(r23)
.L_802385FC:
/* 802385FC 0023553C  C0 37 00 6C */	lfs f1, 0x6c(r23)
/* 80238600 00235540  C0 02 C0 F4 */	lfs f0, lbl_8051A454@sda21(r2)
/* 80238604 00235544  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80238608 00235548  40 81 00 0C */	ble .L_80238614
/* 8023860C 0023554C  EC 01 00 28 */	fsubs f0, f1, f0
/* 80238610 00235550  D0 17 00 6C */	stfs f0, 0x6c(r23)
.L_80238614:
/* 80238614 00235554  80 AD 9A EC */	lwz r5, sys@sda21(r13)
/* 80238618 00235558  38 60 00 98 */	li r3, 0x98
/* 8023861C 0023555C  C0 37 00 68 */	lfs f1, 0x68(r23)
/* 80238620 00235560  38 80 00 00 */	li r4, 0
/* 80238624 00235564  C0 05 00 54 */	lfs f0, 0x54(r5)
/* 80238628 00235568  38 A0 00 04 */	li r5, 4
/* 8023862C 0023556C  C0 42 C0 DC */	lfs f2, lbl_8051A43C@sda21(r2)
/* 80238630 00235570  EC 01 00 2A */	fadds f0, f1, f0
/* 80238634 00235574  D0 17 00 68 */	stfs f0, 0x68(r23)
/* 80238638 00235578  80 CD 9A EC */	lwz r6, sys@sda21(r13)
/* 8023863C 0023557C  C0 17 00 6C */	lfs f0, 0x6c(r23)
/* 80238640 00235580  C0 26 00 54 */	lfs f1, 0x54(r6)
/* 80238644 00235584  EC 02 00 7A */	fmadds f0, f2, f1, f0
/* 80238648 00235588  D0 17 00 6C */	stfs f0, 0x6c(r23)
/* 8023864C 0023558C  C2 17 00 44 */	lfs f16, 0x44(r23)
/* 80238650 00235590  FD E0 80 50 */	fneg f15, f16
/* 80238654 00235594  4B EA D3 35 */	bl GXBegin
/* 80238658 00235598  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 8023865C 0023559C  C0 42 C0 78 */	lfs f2, lbl_8051A3D8@sda21(r2)
/* 80238660 002355A0  D1 E4 80 00 */	stfs f15, 0xCC008000@l(r4)
/* 80238664 002355A4  38 60 00 01 */	li r3, 1
/* 80238668 002355A8  C0 22 C0 F4 */	lfs f1, lbl_8051A454@sda21(r2)
/* 8023866C 002355AC  D1 E4 80 00 */	stfs f15, 0xCC008000@l(r4)
/* 80238670 002355B0  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238674 002355B4  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238678 002355B8  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 8023867C 002355BC  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 80238680 002355C0  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238684 002355C4  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238688 002355C8  C0 17 00 68 */	lfs f0, 0x68(r23)
/* 8023868C 002355CC  D0 04 80 00 */	stfs f0, 0xCC008000@l(r4)
/* 80238690 002355D0  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238694 002355D4  D2 04 80 00 */	stfs f16, 0xCC008000@l(r4)
/* 80238698 002355D8  D1 E4 80 00 */	stfs f15, 0xCC008000@l(r4)
/* 8023869C 002355DC  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386A0 002355E0  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386A4 002355E4  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386A8 002355E8  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 802386AC 002355EC  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 802386B0 002355F0  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386B4 002355F4  C0 17 00 68 */	lfs f0, 0x68(r23)
/* 802386B8 002355F8  EC 01 00 2A */	fadds f0, f1, f0
/* 802386BC 002355FC  D0 04 80 00 */	stfs f0, 0xCC008000@l(r4)
/* 802386C0 00235600  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386C4 00235604  D1 E4 80 00 */	stfs f15, 0xCC008000@l(r4)
/* 802386C8 00235608  D2 04 80 00 */	stfs f16, 0xCC008000@l(r4)
/* 802386CC 0023560C  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386D0 00235610  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386D4 00235614  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386D8 00235618  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 802386DC 0023561C  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386E0 00235620  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 802386E4 00235624  C0 17 00 68 */	lfs f0, 0x68(r23)
/* 802386E8 00235628  D0 04 80 00 */	stfs f0, 0xCC008000@l(r4)
/* 802386EC 0023562C  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 802386F0 00235630  D2 04 80 00 */	stfs f16, 0xCC008000@l(r4)
/* 802386F4 00235634  D2 04 80 00 */	stfs f16, 0xCC008000@l(r4)
/* 802386F8 00235638  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 802386FC 0023563C  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238700 00235640  D0 44 80 00 */	stfs f2, 0xCC008000@l(r4)
/* 80238704 00235644  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 80238708 00235648  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 8023870C 0023564C  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 80238710 00235650  C0 17 00 68 */	lfs f0, 0x68(r23)
/* 80238714 00235654  EC 01 00 2A */	fadds f0, f1, f0
/* 80238718 00235658  D0 04 80 00 */	stfs f0, 0xCC008000@l(r4)
/* 8023871C 0023565C  D0 24 80 00 */	stfs f1, 0xCC008000@l(r4)
/* 80238720 00235660  4B EB 04 99 */	bl GXSetNumTevStages
/* 80238724 00235664  38 60 00 01 */	li r3, 1
/* 80238728 00235668  4B EA C8 75 */	bl GXSetNumTexGens
/* 8023872C 0023566C  4B EA BF A5 */	bl GXClearVtxDesc
/* 80238730 00235670  38 60 00 09 */	li r3, 9
/* 80238734 00235674  38 80 00 01 */	li r4, 1
/* 80238738 00235678  4B EA BB 4D */	bl GXSetVtxDesc
/* 8023873C 0023567C  38 60 00 0A */	li r3, 0xa
/* 80238740 00235680  38 80 00 01 */	li r4, 1
/* 80238744 00235684  4B EA BB 41 */	bl GXSetVtxDesc
/* 80238748 00235688  38 60 00 0D */	li r3, 0xd
/* 8023874C 0023568C  38 80 00 01 */	li r4, 1
/* 80238750 00235690  4B EA BB 35 */	bl GXSetVtxDesc
/* 80238754 00235694  38 60 00 00 */	li r3, 0
/* 80238758 00235698  38 80 00 09 */	li r4, 9
/* 8023875C 0023569C  38 A0 00 01 */	li r5, 1
/* 80238760 002356A0  38 C0 00 04 */	li r6, 4
/* 80238764 002356A4  38 E0 00 00 */	li r7, 0
/* 80238768 002356A8  4B EA BF A1 */	bl GXSetVtxAttrFmt
/* 8023876C 002356AC  38 60 00 00 */	li r3, 0
/* 80238770 002356B0  38 80 00 0A */	li r4, 0xa
/* 80238774 002356B4  38 A0 00 00 */	li r5, 0
/* 80238778 002356B8  38 C0 00 04 */	li r6, 4
/* 8023877C 002356BC  38 E0 00 00 */	li r7, 0
/* 80238780 002356C0  4B EA BF 89 */	bl GXSetVtxAttrFmt
/* 80238784 002356C4  38 60 00 00 */	li r3, 0
/* 80238788 002356C8  38 80 00 0D */	li r4, 0xd
/* 8023878C 002356CC  38 A0 00 01 */	li r5, 1
/* 80238790 002356D0  38 C0 00 04 */	li r6, 4
/* 80238794 002356D4  38 E0 00 00 */	li r7, 0
/* 80238798 002356D8  4B EA BF 71 */	bl GXSetVtxAttrFmt
/* 8023879C 002356DC  80 1F 01 B8 */	lwz r0, 0x1b8(r31)
/* 802387A0 002356E0  2C 00 00 00 */	cmpwi r0, 0
/* 802387A4 002356E4  40 82 01 30 */	bne .L_802388D4
/* 802387A8 002356E8  80 17 00 38 */	lwz r0, 0x38(r23)
/* 802387AC 002356EC  2C 00 00 00 */	cmpwi r0, 0
/* 802387B0 002356F0  41 82 01 24 */	beq .L_802388D4
/* 802387B4 002356F4  88 17 00 51 */	lbz r0, 0x51(r23)
/* 802387B8 002356F8  28 00 00 00 */	cmplwi r0, 0
/* 802387BC 002356FC  41 82 01 18 */	beq .L_802388D4
/* 802387C0 00235700  80 75 00 08 */	lwz r3, 8(r21)
/* 802387C4 00235704  38 80 00 00 */	li r4, 0
/* 802387C8 00235708  4B DF AE 69 */	bl load__10JUTTextureF11_GXTexMapID
/* 802387CC 0023570C  C0 22 C0 CC */	lfs f1, lbl_8051A42C@sda21(r2)
/* 802387D0 00235710  38 60 00 98 */	li r3, 0x98
/* 802387D4 00235714  C0 17 00 48 */	lfs f0, 0x48(r23)
/* 802387D8 00235718  38 80 00 00 */	li r4, 0
/* 802387DC 0023571C  C3 A2 C0 78 */	lfs f29, lbl_8051A3D8@sda21(r2)
/* 802387E0 00235720  38 A0 00 04 */	li r5, 4
/* 802387E4 00235724  EC C1 00 32 */	fmuls f6, f1, f0
/* 802387E8 00235728  C0 22 C1 68 */	lfs f1, lbl_8051A4C8@sda21(r2)
/* 802387EC 0023572C  C0 42 C1 70 */	lfs f2, lbl_8051A4D0@sda21(r2)
/* 802387F0 00235730  FF E0 E8 90 */	fmr f31, f29
/* 802387F4 00235734  FC 00 E8 90 */	fmr f0, f29
/* 802387F8 00235738  C0 62 C1 6C */	lfs f3, lbl_8051A4CC@sda21(r2)
/* 802387FC 0023573C  EC A1 01 B2 */	fmuls f5, f1, f6
/* 80238800 00235740  C0 22 C1 74 */	lfs f1, lbl_8051A4D4@sda21(r2)
/* 80238804 00235744  FF 20 E8 90 */	fmr f25, f29
/* 80238808 00235748  FE E0 E8 90 */	fmr f23, f29
/* 8023880C 0023574C  FC 80 28 50 */	fneg f4, f5
/* 80238810 00235750  EF 45 18 2A */	fadds f26, f5, f3
/* 80238814 00235754  FC A0 30 50 */	fneg f5, f6
/* 80238818 00235758  EC 64 18 2A */	fadds f3, f4, f3
/* 8023881C 0023575C  FF 00 D0 90 */	fmr f24, f26
/* 80238820 00235760  EF 65 10 2A */	fadds f27, f5, f2
/* 80238824 00235764  EF 83 08 2A */	fadds f28, f3, f1
/* 80238828 00235768  EF BD E8 2A */	fadds f29, f29, f29
/* 8023882C 0023576C  EF C6 10 2A */	fadds f30, f6, f2
/* 80238830 00235770  EF FF 00 2A */	fadds f31, f31, f0
/* 80238834 00235774  EF 5A 08 2A */	fadds f26, f26, f1
/* 80238838 00235778  EF 39 00 2A */	fadds f25, f25, f0
/* 8023883C 0023577C  EF 18 08 2A */	fadds f24, f24, f1
/* 80238840 00235780  EE F7 00 2A */	fadds f23, f23, f0
/* 80238844 00235784  4B EA D1 45 */	bl GXBegin
/* 80238848 00235788  3C 60 CC 01 */	lis r3, 0xCC008000@ha
/* 8023884C 0023578C  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 80238850 00235790  D3 63 80 00 */	stfs f27, 0xCC008000@l(r3)
/* 80238854 00235794  C0 02 C0 F4 */	lfs f0, lbl_8051A454@sda21(r2)
/* 80238858 00235798  D3 83 80 00 */	stfs f28, 0xCC008000@l(r3)
/* 8023885C 0023579C  D3 A3 80 00 */	stfs f29, 0xCC008000@l(r3)
/* 80238860 002357A0  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238864 002357A4  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238868 002357A8  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 8023886C 002357AC  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238870 002357B0  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238874 002357B4  D3 C3 80 00 */	stfs f30, 0xCC008000@l(r3)
/* 80238878 002357B8  D3 83 80 00 */	stfs f28, 0xCC008000@l(r3)
/* 8023887C 002357BC  D3 E3 80 00 */	stfs f31, 0xCC008000@l(r3)
/* 80238880 002357C0  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238884 002357C4  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238888 002357C8  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 8023888C 002357CC  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 80238890 002357D0  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 80238894 002357D4  D3 63 80 00 */	stfs f27, 0xCC008000@l(r3)
/* 80238898 002357D8  D3 43 80 00 */	stfs f26, 0xCC008000@l(r3)
/* 8023889C 002357DC  D3 23 80 00 */	stfs f25, 0xCC008000@l(r3)
/* 802388A0 002357E0  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 802388A4 002357E4  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 802388A8 002357E8  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 802388AC 002357EC  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 802388B0 002357F0  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 802388B4 002357F4  D3 C3 80 00 */	stfs f30, 0xCC008000@l(r3)
/* 802388B8 002357F8  D3 03 80 00 */	stfs f24, 0xCC008000@l(r3)
/* 802388BC 002357FC  D2 E3 80 00 */	stfs f23, 0xCC008000@l(r3)
/* 802388C0 00235800  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 802388C4 00235804  D0 23 80 00 */	stfs f1, 0xCC008000@l(r3)
/* 802388C8 00235808  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 802388CC 0023580C  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
/* 802388D0 00235810  D0 03 80 00 */	stfs f0, 0xCC008000@l(r3)
.L_802388D4:
/* 802388D4 00235814  80 02 C1 54 */	lwz r0, lbl_8051A4B4@sda21(r2)
/* 802388D8 00235818  38 81 00 08 */	addi r4, r1, 8
/* 802388DC 0023581C  38 60 00 04 */	li r3, 4
/* 802388E0 00235820  90 01 00 08 */	stw r0, 8(r1)
/* 802388E4 00235824  4B EA E4 91 */	bl GXSetChanMatColor
/* 802388E8 00235828  38 60 00 00 */	li r3, 0
/* 802388EC 0023582C  38 80 00 01 */	li r4, 1
/* 802388F0 00235830  38 A0 00 00 */	li r5, 0
/* 802388F4 00235834  4B EB 08 91 */	bl GXSetZMode
/* 802388F8 00235838  7F 43 D3 78 */	mr r3, r26
/* 802388FC 0023583C  38 80 00 00 */	li r4, 0
/* 80238900 00235840  4B EB 0C 79 */	bl GXLoadPosMtxImm
/* 80238904 00235844  7F 43 D3 78 */	mr r3, r26
/* 80238908 00235848  38 80 00 00 */	li r4, 0
/* 8023890C 0023584C  4B EB 0C BD */	bl GXLoadNrmMtxImm
/* 80238910 00235850  80 17 00 5C */	lwz r0, 0x5c(r23)
/* 80238914 00235854  2C 00 00 00 */	cmpwi r0, 0
/* 80238918 00235858  40 82 00 14 */	bne .L_8023892C
/* 8023891C 0023585C  C0 42 C0 B8 */	lfs f2, lbl_8051A418@sda21(r2)
/* 80238920 00235860  C0 62 C0 BC */	lfs f3, lbl_8051A41C@sda21(r2)
/* 80238924 00235864  C2 E2 C0 78 */	lfs f23, lbl_8051A3D8@sda21(r2)
/* 80238928 00235868  48 00 00 10 */	b .L_80238938
.L_8023892C:
/* 8023892C 0023586C  C0 42 C0 B8 */	lfs f2, lbl_8051A418@sda21(r2)
/* 80238930 00235870  C0 62 C0 C0 */	lfs f3, lbl_8051A420@sda21(r2)
/* 80238934 00235874  C2 E2 C0 78 */	lfs f23, lbl_8051A3D8@sda21(r2)
.L_80238938:
lfs f2,  0(r22)
lfs f3,  4(r22)
lfs f23, lbl_8051A3D8@sda21(r2)
/* 80238938 00235878  C0 02 C0 C8 */	lfs f0, lbl_8051A428@sda21(r2)
/* 8023893C 0023587C  3B 00 00 00 */	li r24, 0
/* 80238940 00235880  C0 22 C0 C4 */	lfs f1, lbl_8051A424@sda21(r2)
/* 80238944 00235884  3E C0 CC 01 */	lis r22, 0xcc01
/* 80238948 00235888  EF 02 00 28 */	fsubs f24, f2, f0
/* 8023894C 0023588C  C0 02 C0 D0 */	lfs f0, lbl_8051A430@sda21(r2)
/* 80238950 00235890  C3 A2 C0 78 */	lfs f29, lbl_8051A3D8@sda21(r2)
/* 80238954 00235894  EF 23 08 28 */	fsubs f25, f3, f1
/* 80238958 00235898  FD E0 00 50 */	fneg f15, f0
/* 8023895C 0023589C  C3 C2 C0 F4 */	lfs f30, lbl_8051A454@sda21(r2)
/* 80238960 002358A0  EF 18 E8 2A */	fadds f24, f24, f29
/* 80238964 002358A4  C3 E2 C1 78 */	lfs f31, lbl_8051A4D8@sda21(r2)
/* 80238968 002358A8  EF 6F C8 2A */	fadds f27, f15, f25
.L_8023896C:
/* 8023896C 002358AC  80 17 00 1C */	lwz r0, 0x1c(r23)
/* 80238970 002358B0  80 75 00 10 */	lwz r3, 0x10(r21)
/* 80238974 002358B4  7C 18 00 00 */	cmpw r24, r0
/* 80238978 002358B8  40 80 00 08 */	bge .L_80238980
/* 8023897C 002358BC  80 75 00 0C */	lwz r3, 0xc(r21)
.L_80238980:
/* 80238980 002358C0  38 80 00 00 */	li r4, 0
/* 80238984 002358C4  4B DF AC AD */	bl load__10JUTTextureF11_GXTexMapID
/* 80238988 002358C8  C3 82 C0 78 */	lfs f28, lbl_8051A3D8@sda21(r2)
/* 8023898C 002358CC  EF 4F C0 2A */	fadds f26, f15, f24
/* 80238990 002358D0  C2 C2 C0 D0 */	lfs f22, lbl_8051A430@sda21(r2)
/* 80238994 002358D4  38 60 00 98 */	li r3, 0x98
/* 80238998 002358D8  FE A0 E0 90 */	fmr f21, f28
/* 8023899C 002358DC  38 80 00 00 */	li r4, 0
/* 802389A0 002358E0  FE 80 B0 90 */	fmr f20, f22
/* 802389A4 002358E4  FE 60 E0 90 */	fmr f19, f28
/* 802389A8 002358E8  38 A0 00 04 */	li r5, 4
/* 802389AC 002358EC  FE 00 E0 90 */	fmr f16, f28
/* 802389B0 002358F0  FE 40 B0 90 */	fmr f18, f22
/* 802389B4 002358F4  FE 20 B0 90 */	fmr f17, f22
/* 802389B8 002358F8  EF 9C B8 2A */	fadds f28, f28, f23
/* 802389BC 002358FC  EE D6 C0 2A */	fadds f22, f22, f24
/* 802389C0 00235900  EE B5 B8 2A */	fadds f21, f21, f23
/* 802389C4 00235904  EE 94 C8 2A */	fadds f20, f20, f25
/* 802389C8 00235908  EE 73 B8 2A */	fadds f19, f19, f23
/* 802389CC 0023590C  EE 52 C0 2A */	fadds f18, f18, f24
/* 802389D0 00235910  EE 31 C8 2A */	fadds f17, f17, f25
/* 802389D4 00235914  EE 10 B8 2A */	fadds f16, f16, f23
/* 802389D8 00235918  4B EA CF B1 */	bl GXBegin
/* 802389DC 0023591C  D3 56 80 00 */	stfs f26, 0xCC008000@l(r22)
/* 802389E0 00235920  3B 18 00 01 */	addi r24, r24, 1
/* 802389E4 00235924  2C 18 00 04 */	cmpwi r24, 4
/* 802389E8 00235928  EF 18 F8 2A */	fadds f24, f24, f31
/* 802389EC 0023592C  D3 76 80 00 */	stfs f27, 0xCC008000@l(r22)
/* 802389F0 00235930  D3 96 80 00 */	stfs f28, 0xCC008000@l(r22)
/* 802389F4 00235934  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 802389F8 00235938  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 802389FC 0023593C  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A00 00235940  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A04 00235944  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A08 00235948  D2 D6 80 00 */	stfs f22, 0xCC008000@l(r22)
/* 80238A0C 0023594C  D3 76 80 00 */	stfs f27, 0xCC008000@l(r22)
/* 80238A10 00235950  D2 B6 80 00 */	stfs f21, 0xCC008000@l(r22)
/* 80238A14 00235954  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A18 00235958  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A1C 0023595C  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A20 00235960  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A24 00235964  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A28 00235968  D3 56 80 00 */	stfs f26, 0xCC008000@l(r22)
/* 80238A2C 0023596C  D2 96 80 00 */	stfs f20, 0xCC008000@l(r22)
/* 80238A30 00235970  D2 76 80 00 */	stfs f19, 0xCC008000@l(r22)
/* 80238A34 00235974  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A38 00235978  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A3C 0023597C  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A40 00235980  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A44 00235984  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A48 00235988  D2 56 80 00 */	stfs f18, 0xCC008000@l(r22)
/* 80238A4C 0023598C  D2 36 80 00 */	stfs f17, 0xCC008000@l(r22)
/* 80238A50 00235990  D2 16 80 00 */	stfs f16, 0xCC008000@l(r22)
/* 80238A54 00235994  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A58 00235998  D3 B6 80 00 */	stfs f29, 0xCC008000@l(r22)
/* 80238A5C 0023599C  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A60 002359A0  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A64 002359A4  D3 D6 80 00 */	stfs f30, 0xCC008000@l(r22)
/* 80238A68 002359A8  41 80 FF 04 */	blt .L_8023896C
/* 80238A6C 002359AC  E3 E1 02 28 */	psq_l f31, 552(r1), 0, qr0
/* 80238A70 002359B0  CB E1 02 20 */	lfd f31, 0x220(r1)
/* 80238A74 002359B4  E3 C1 02 18 */	psq_l f30, 536(r1), 0, qr0
/* 80238A78 002359B8  CB C1 02 10 */	lfd f30, 0x210(r1)
/* 80238A7C 002359BC  E3 A1 02 08 */	psq_l f29, 520(r1), 0, qr0
/* 80238A80 002359C0  CB A1 02 00 */	lfd f29, 0x200(r1)
/* 80238A84 002359C4  E3 81 01 F8 */	psq_l f28, 504(r1), 0, qr0
/* 80238A88 002359C8  CB 81 01 F0 */	lfd f28, 0x1f0(r1)
/* 80238A8C 002359CC  E3 61 01 E8 */	psq_l f27, 488(r1), 0, qr0
/* 80238A90 002359D0  CB 61 01 E0 */	lfd f27, 0x1e0(r1)
/* 80238A94 002359D4  E3 41 01 D8 */	psq_l f26, 472(r1), 0, qr0
/* 80238A98 002359D8  CB 41 01 D0 */	lfd f26, 0x1d0(r1)
/* 80238A9C 002359DC  E3 21 01 C8 */	psq_l f25, 456(r1), 0, qr0
/* 80238AA0 002359E0  CB 21 01 C0 */	lfd f25, 0x1c0(r1)
/* 80238AA4 002359E4  E3 01 01 B8 */	psq_l f24, 440(r1), 0, qr0
/* 80238AA8 002359E8  CB 01 01 B0 */	lfd f24, 0x1b0(r1)
/* 80238AAC 002359EC  E2 E1 01 A8 */	psq_l f23, 424(r1), 0, qr0
/* 80238AB0 002359F0  CA E1 01 A0 */	lfd f23, 0x1a0(r1)
/* 80238AB4 002359F4  E2 C1 01 98 */	psq_l f22, 408(r1), 0, qr0
/* 80238AB8 002359F8  CA C1 01 90 */	lfd f22, 0x190(r1)
/* 80238ABC 002359FC  E2 A1 01 88 */	psq_l f21, 392(r1), 0, qr0
/* 80238AC0 00235A00  CA A1 01 80 */	lfd f21, 0x180(r1)
/* 80238AC4 00235A04  E2 81 01 78 */	psq_l f20, 376(r1), 0, qr0
/* 80238AC8 00235A08  CA 81 01 70 */	lfd f20, 0x170(r1)
/* 80238ACC 00235A0C  E2 61 01 68 */	psq_l f19, 360(r1), 0, qr0
/* 80238AD0 00235A10  CA 61 01 60 */	lfd f19, 0x160(r1)
/* 80238AD4 00235A14  E2 41 01 58 */	psq_l f18, 344(r1), 0, qr0
/* 80238AD8 00235A18  CA 41 01 50 */	lfd f18, 0x150(r1)
/* 80238ADC 00235A1C  E2 21 01 48 */	psq_l f17, 328(r1), 0, qr0
/* 80238AE0 00235A20  CA 21 01 40 */	lfd f17, 0x140(r1)
/* 80238AE4 00235A24  E2 01 01 38 */	psq_l f16, 312(r1), 0, qr0
/* 80238AE8 00235A28  CA 01 01 30 */	lfd f16, 0x130(r1)
/* 80238AEC 00235A2C  E1 E1 01 28 */	psq_l f15, 296(r1), 0, qr0
/* 80238AF0 00235A30  C9 E1 01 20 */	lfd f15, 0x120(r1)
/* 80238AF4 00235A34  BA A1 00 F4 */	lmw r21, 0xf4(r1)
/* 80238AF8 00235A38  80 01 02 34 */	lwz r0, 0x234(r1)
/* 80238AFC 00235A3C  7C 08 03 A6 */	mtlr r0
/* 80238B00 00235A40  38 21 02 30 */	addi r1, r1, 0x230
/* 80238B04 00235A44  4E 80 00 20 */	blr 
.endfn "drawSlot__Q34Game6VsGame7CardMgrFR8GraphicsR10Vector3<f>RQ44Game6VsGame7CardMgr11SlotMachine"

.fn update__8LightObjFv, weak
/* 80238B08 00235A48  4E 80 00 20 */	blr 
.endfn update__8LightObjFv

.fn startZoomIn__Q44Game6VsGame7CardMgr11SlotMachineFv, global
/* 80238B0C 00235A4C  C0 22 C1 40 */	lfs f1, CardSize__Q24Game6VsGame@sda21(r13)
/* 80238B10 00235A50  38 80 00 01 */	li r4, 1
/* 80238B14 00235A54  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80238B18 00235A58  38 00 00 00 */	li r0, 0
/* 80238B1C 00235A5C  D0 23 00 44 */	stfs f1, 0x44(r3)
/* 80238B20 00235A60  D0 03 00 40 */	stfs f0, 0x40(r3)
/* 80238B24 00235A64  90 83 00 38 */	stw r4, 0x38(r3)
/* 80238B28 00235A68  D0 03 00 3C */	stfs f0, 0x3c(r3)
/* 80238B2C 00235A6C  98 03 00 50 */	stb r0, 0x50(r3)
/* 80238B30 00235A70  4E 80 00 20 */	blr 
.endfn startZoomIn__Q44Game6VsGame7CardMgr11SlotMachineFv

.fn startZoomUse__Q44Game6VsGame7CardMgr11SlotMachineFv, global
/* 80238B34 00235A74  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 80238B38 00235A78  38 00 00 02 */	li r0, 2
/* 80238B3C 00235A7C  C0 02 C0 D8 */	lfs f0, CardBounce__Q24Game6VsGame@sda21(r13)
/* 80238B40 00235A80  D0 23 00 40 */	stfs f1, 0x40(r3)
/* 80238B44 00235A84  90 03 00 38 */	stw r0, 0x38(r3)
/* 80238B48 00235A88  D0 23 00 3C */	stfs f1, 0x3c(r3)
/* 80238B4C 00235A8C  D0 03 00 48 */	stfs f0, 0x48(r3)
/* 80238B50 00235A90  4E 80 00 20 */	blr 
.endfn startZoomUse__Q44Game6VsGame7CardMgr11SlotMachineFv

.fn setGroup__Q25efx2d5TBaseFUc, weak
/* 80238E6C 00235DAC  98 83 00 05 */	stb r4, 5(r3)
/* 80238E70 00235DB0  4E 80 00 20 */	blr 
.endfn setGroup__Q25efx2d5TBaseFUc

.fn getName__Q25efx2d18ArgScaleColorColorFv, weak
/* 80238E74 00235DB4  3C 60 80 48 */	lis r3, lbl_80483CBC@ha
/* 80238E78 00235DB8  38 63 3C BC */	addi r3, r3, lbl_80483CBC@l
/* 80238E7C 00235DBC  4E 80 00 20 */	blr 
.endfn getName__Q25efx2d18ArgScaleColorColorFv

.fn getName__Q25efx2d3ArgFv, weak
/* 80238E80 00235DC0  38 62 C1 8C */	addi r3, r2, lbl_8051A4EC@sda21
/* 80238E84 00235DC4  4E 80 00 20 */	blr 
.endfn getName__Q25efx2d3ArgFv

.fn __sinit_vsCardMgr_cpp, local
/* 80238E88 00235DC8  3C 80 80 51 */	lis r4, __float_nan@ha
/* 80238E8C 00235DCC  38 00 FF FF */	li r0, -1
/* 80238E90 00235DD0  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 80238E94 00235DD4  3C 60 80 4C */	lis r3, govNAN___Q24Game5P2JST@ha
/* 80238E98 00235DD8  90 0D 96 28 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 80238E9C 00235DDC  D4 03 14 70 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 80238EA0 00235DE0  D0 0D 96 2C */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 80238EA4 00235DE4  D0 03 00 04 */	stfs f0, 4(r3)
/* 80238EA8 00235DE8  D0 03 00 08 */	stfs f0, 8(r3)
/* 80238EAC 00235DEC  4E 80 00 20 */	blr 
.endfn __sinit_vsCardMgr_cpp
