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
.obj lbl_804C14AC, local
	.4byte .L_80237714
	.4byte .L_802370B0
	.4byte .L_802370DC
	.4byte .L_802371E4
	.4byte .L_80237258
	.4byte .L_802372BC
	.4byte .L_80237598
	.4byte .L_802375D0
	.4byte .L_80237488
	.4byte .L_802374C0
	.4byte .L_802376B0
.endobj lbl_804C14AC
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

.fn loadResource__Q34Game6VsGame7CardMgrFv, global
/* 802356AC 002325EC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 802356B0 002325F0  7C 08 02 A6 */	mflr r0
/* 802356B4 002325F4  3C 80 80 48 */	lis r4, lbl_80483AD0@ha
/* 802356B8 002325F8  38 A0 00 00 */	li r5, 0
/* 802356BC 002325FC  90 01 00 34 */	stw r0, 0x34(r1)
/* 802356C0 00232600  38 C0 00 01 */	li r6, 1
/* 802356C4 00232604  BF 01 00 10 */	stmw r24, 0x10(r1)
/* 802356C8 00232608  3B E4 3A D0 */	addi r31, r4, lbl_80483AD0@l
/* 802356CC 0023260C  7C 7D 1B 78 */	mr r29, r3
/* 802356D0 00232610  38 80 00 01 */	li r4, 1
/* 802356D4 00232614  38 7F 01 60 */	addi r3, r31, 0x160
/* 802356D8 00232618  4B DE 5A 59 */	bl mount__10JKRArchiveFPCcQ210JKRArchive10EMountModeP7JKRHeapQ210JKRArchive15EMountDirection
/* 802356DC 0023261C  7C 7E 1B 79 */	or. r30, r3, r3
/* 802356E0 00232620  40 82 00 18 */	bne .L_802356F8
/* 802356E4 00232624  38 7F 01 7C */	addi r3, r31, 0x17c
/* 802356E8 00232628  38 BF 01 8C */	addi r5, r31, 0x18c
/* 802356EC 0023262C  38 80 01 02 */	li r4, 0x102
/* 802356F0 00232630  4C C6 31 82 */	crclr 6
/* 802356F4 00232634  4B DF 4F 4D */	bl panic_f__12JUTExceptionFPCciPCce
.L_802356F8:
/* 802356F8 00232638  38 00 00 0C */	li r0, 0xc
/* 802356FC 0023263C  90 1D 00 00 */	stw r0, 0(r29)
/* 80235700 00232640  80 1D 00 00 */	lwz r0, 0(r29)
/* 80235704 00232644  54 03 10 3A */	slwi r3, r0, 2
/* 80235708 00232648  4B DE E8 A5 */	bl __nwa__FUl
/* 8023570C 0023264C  3C 80 80 4C */	lis r4, "tex_names__Q34Game6VsGame23@unnamed@vsCardMgr_cpp@"@ha
/* 80235710 00232650  90 7D 00 04 */	stw r3, 4(r29)
/* 80235714 00232654  3B 64 14 7C */	addi r27, r4, "tex_names__Q34Game6VsGame23@unnamed@vsCardMgr_cpp@"@l
/* 80235718 00232658  3B 20 00 00 */	li r25, 0
/* 8023571C 0023265C  3B 40 00 00 */	li r26, 0
/* 80235720 00232660  48 00 00 84 */	b .L_802357A4
.L_80235724:
/* 80235724 00232664  7F C3 F3 78 */	mr r3, r30
/* 80235728 00232668  80 9B 00 00 */	lwz r4, 0(r27)
/* 8023572C 0023266C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80235730 00232670  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80235734 00232674  7D 89 03 A6 */	mtctr r12
/* 80235738 00232678  4E 80 04 21 */	bctrl 
/* 8023573C 0023267C  7C 78 1B 79 */	or. r24, r3, r3
/* 80235740 00232680  41 82 00 40 */	beq .L_80235780
/* 80235744 00232684  38 60 00 40 */	li r3, 0x40
/* 80235748 00232688  4B DE E7 5D */	bl __nw__FUl
/* 8023574C 0023268C  7C 7C 1B 79 */	or. r28, r3, r3
/* 80235750 00232690  41 82 00 24 */	beq .L_80235774
/* 80235754 00232694  38 00 00 00 */	li r0, 0
/* 80235758 00232698  7F 04 C3 78 */	mr r4, r24
/* 8023575C 0023269C  90 1C 00 28 */	stw r0, 0x28(r28)
/* 80235760 002326A0  38 A0 00 00 */	li r5, 0
/* 80235764 002326A4  4B DF D9 21 */	bl storeTIMG__10JUTTextureFPC7ResTIMGUc
/* 80235768 002326A8  88 1C 00 3B */	lbz r0, 0x3b(r28)
/* 8023576C 002326AC  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 80235770 002326B0  98 1C 00 3B */	stb r0, 0x3b(r28)
.L_80235774:
/* 80235774 002326B4  80 7D 00 04 */	lwz r3, 4(r29)
/* 80235778 002326B8  7F 83 D1 2E */	stwx r28, r3, r26
/* 8023577C 002326BC  48 00 00 1C */	b .L_80235798
.L_80235780:
/* 80235780 002326C0  80 DB 00 00 */	lwz r6, 0(r27)
/* 80235784 002326C4  38 7F 01 7C */	addi r3, r31, 0x17c
/* 80235788 002326C8  38 BF 01 A8 */	addi r5, r31, 0x1a8
/* 8023578C 002326CC  38 80 01 0D */	li r4, 0x10d
/* 80235790 002326D0  4C C6 31 82 */	crclr 6
/* 80235794 002326D4  4B DF 4E AD */	bl panic_f__12JUTExceptionFPCciPCce
.L_80235798:
/* 80235798 002326D8  3B 7B 00 04 */	addi r27, r27, 4
/* 8023579C 002326DC  3B 5A 00 04 */	addi r26, r26, 4
/* 802357A0 002326E0  3B 39 00 01 */	addi r25, r25, 1
.L_802357A4:
/* 802357A4 002326E4  80 1D 00 00 */	lwz r0, 0(r29)
/* 802357A8 002326E8  7C 19 00 00 */	cmpw r25, r0
/* 802357AC 002326EC  41 80 FF 78 */	blt .L_80235724
/* 802357B0 002326F0  7F C3 F3 78 */	mr r3, r30
/* 802357B4 002326F4  38 9F 01 B8 */	addi r4, r31, 0x1b8
/* 802357B8 002326F8  81 9E 00 00 */	lwz r12, 0(r30)
/* 802357BC 002326FC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 802357C0 00232700  7D 89 03 A6 */	mtctr r12
/* 802357C4 00232704  4E 80 04 21 */	bctrl 
/* 802357C8 00232708  7C 78 1B 79 */	or. r24, r3, r3
/* 802357CC 0023270C  40 82 00 18 */	bne .L_802357E4
/* 802357D0 00232710  38 7F 01 7C */	addi r3, r31, 0x17c
/* 802357D4 00232714  38 BF 01 B8 */	addi r5, r31, 0x1b8
/* 802357D8 00232718  38 80 01 12 */	li r4, 0x112
/* 802357DC 0023271C  4C C6 31 82 */	crclr 6
/* 802357E0 00232720  4B DF 4E 61 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802357E4:
/* 802357E4 00232724  38 60 00 40 */	li r3, 0x40
/* 802357E8 00232728  4B DE E6 BD */	bl __nw__FUl
/* 802357EC 0023272C  7C 7C 1B 79 */	or. r28, r3, r3
/* 802357F0 00232730  41 82 00 24 */	beq .L_80235814
/* 802357F4 00232734  38 00 00 00 */	li r0, 0
/* 802357F8 00232738  7F 04 C3 78 */	mr r4, r24
/* 802357FC 0023273C  90 1C 00 28 */	stw r0, 0x28(r28)
/* 80235800 00232740  38 A0 00 00 */	li r5, 0
/* 80235804 00232744  4B DF D8 81 */	bl storeTIMG__10JUTTextureFPC7ResTIMGUc
/* 80235808 00232748  88 1C 00 3B */	lbz r0, 0x3b(r28)
/* 8023580C 0023274C  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 80235810 00232750  98 1C 00 3B */	stb r0, 0x3b(r28)
.L_80235814:
/* 80235814 00232754  93 9D 00 08 */	stw r28, 8(r29)
/* 80235818 00232758  7F C3 F3 78 */	mr r3, r30
/* 8023581C 0023275C  38 9F 01 C4 */	addi r4, r31, 0x1c4
/* 80235820 00232760  81 9E 00 00 */	lwz r12, 0(r30)
/* 80235824 00232764  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80235828 00232768  7D 89 03 A6 */	mtctr r12
/* 8023582C 0023276C  4E 80 04 21 */	bctrl 
/* 80235830 00232770  7C 78 1B 79 */	or. r24, r3, r3
/* 80235834 00232774  40 82 00 18 */	bne .L_8023584C
/* 80235838 00232778  38 7F 01 7C */	addi r3, r31, 0x17c
/* 8023583C 0023277C  38 BF 01 C4 */	addi r5, r31, 0x1c4
/* 80235840 00232780  38 80 01 17 */	li r4, 0x117
/* 80235844 00232784  4C C6 31 82 */	crclr 6
/* 80235848 00232788  4B DF 4D F9 */	bl panic_f__12JUTExceptionFPCciPCce
.L_8023584C:
/* 8023584C 0023278C  38 60 00 40 */	li r3, 0x40
/* 80235850 00232790  4B DE E6 55 */	bl __nw__FUl
/* 80235854 00232794  7C 7C 1B 79 */	or. r28, r3, r3
/* 80235858 00232798  41 82 00 24 */	beq .L_8023587C
/* 8023585C 0023279C  38 00 00 00 */	li r0, 0
/* 80235860 002327A0  7F 04 C3 78 */	mr r4, r24
/* 80235864 002327A4  90 1C 00 28 */	stw r0, 0x28(r28)
/* 80235868 002327A8  38 A0 00 00 */	li r5, 0
/* 8023586C 002327AC  4B DF D8 19 */	bl storeTIMG__10JUTTextureFPC7ResTIMGUc
/* 80235870 002327B0  88 1C 00 3B */	lbz r0, 0x3b(r28)
/* 80235874 002327B4  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 80235878 002327B8  98 1C 00 3B */	stb r0, 0x3b(r28)
.L_8023587C:
/* 8023587C 002327BC  93 9D 00 0C */	stw r28, 0xc(r29)
/* 80235880 002327C0  7F C3 F3 78 */	mr r3, r30
/* 80235884 002327C4  38 9F 01 D0 */	addi r4, r31, 0x1d0
/* 80235888 002327C8  81 9E 00 00 */	lwz r12, 0(r30)
/* 8023588C 002327CC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80235890 002327D0  7D 89 03 A6 */	mtctr r12
/* 80235894 002327D4  4E 80 04 21 */	bctrl 
/* 80235898 002327D8  7C 78 1B 79 */	or. r24, r3, r3
/* 8023589C 002327DC  40 82 00 18 */	bne .L_802358B4
/* 802358A0 002327E0  38 7F 01 7C */	addi r3, r31, 0x17c
/* 802358A4 002327E4  38 BF 01 D0 */	addi r5, r31, 0x1d0
/* 802358A8 002327E8  38 80 01 1C */	li r4, 0x11c
/* 802358AC 002327EC  4C C6 31 82 */	crclr 6
/* 802358B0 002327F0  4B DF 4D 91 */	bl panic_f__12JUTExceptionFPCciPCce
.L_802358B4:
/* 802358B4 002327F4  38 60 00 40 */	li r3, 0x40
/* 802358B8 002327F8  4B DE E5 ED */	bl __nw__FUl
/* 802358BC 002327FC  7C 7C 1B 79 */	or. r28, r3, r3
/* 802358C0 00232800  41 82 00 24 */	beq .L_802358E4
/* 802358C4 00232804  38 00 00 00 */	li r0, 0
/* 802358C8 00232808  7F 04 C3 78 */	mr r4, r24
/* 802358CC 0023280C  90 1C 00 28 */	stw r0, 0x28(r28)
/* 802358D0 00232810  38 A0 00 00 */	li r5, 0
/* 802358D4 00232814  4B DF D7 B1 */	bl storeTIMG__10JUTTextureFPC7ResTIMGUc
/* 802358D8 00232818  88 1C 00 3B */	lbz r0, 0x3b(r28)
/* 802358DC 0023281C  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 802358E0 00232820  98 1C 00 3B */	stb r0, 0x3b(r28)
.L_802358E4:
/* 802358E4 00232824  93 9D 00 10 */	stw r28, 0x10(r29)
/* 802358E8 00232828  7F C3 F3 78 */	mr r3, r30
/* 802358EC 0023282C  38 82 C0 B0 */	addi r4, r2, lbl_8051A410@sda21
/* 802358F0 00232830  81 9E 00 00 */	lwz r12, 0(r30)
/* 802358F4 00232834  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 802358F8 00232838  7D 89 03 A6 */	mtctr r12
/* 802358FC 0023283C  4E 80 04 21 */	bctrl 
/* 80235900 00232840  7C 78 1B 79 */	or. r24, r3, r3
/* 80235904 00232844  40 82 00 18 */	bne .L_8023591C
/* 80235908 00232848  38 7F 01 7C */	addi r3, r31, 0x17c
/* 8023590C 0023284C  38 80 01 21 */	li r4, 0x121
/* 80235910 00232850  38 A2 C0 B0 */	addi r5, r2, lbl_8051A410@sda21
/* 80235914 00232854  4C C6 31 82 */	crclr 6
/* 80235918 00232858  4B DF 4D 29 */	bl panic_f__12JUTExceptionFPCciPCce
.L_8023591C:
/* 8023591C 0023285C  38 60 00 40 */	li r3, 0x40
/* 80235920 00232860  4B DE E5 85 */	bl __nw__FUl
/* 80235924 00232864  7C 7E 1B 79 */	or. r30, r3, r3
/* 80235928 00232868  41 82 00 24 */	beq .L_8023594C
/* 8023592C 0023286C  38 00 00 00 */	li r0, 0
/* 80235930 00232870  7F 04 C3 78 */	mr r4, r24
/* 80235934 00232874  90 1E 00 28 */	stw r0, 0x28(r30)
/* 80235938 00232878  38 A0 00 00 */	li r5, 0
/* 8023593C 0023287C  4B DF D7 49 */	bl storeTIMG__10JUTTextureFPC7ResTIMGUc
/* 80235940 00232880  88 1E 00 3B */	lbz r0, 0x3b(r30)
/* 80235944 00232884  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 80235948 00232888  98 1E 00 3B */	stb r0, 0x3b(r30)
.L_8023594C:
/* 8023594C 0023288C  93 DD 00 14 */	stw r30, 0x14(r29)
/* 80235950 00232890  BB 01 00 10 */	lmw r24, 0x10(r1)
/* 80235954 00232894  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80235958 00232898  7C 08 03 A6 */	mtlr r0
/* 8023595C 0023289C  38 21 00 30 */	addi r1, r1, 0x30
/* 80235960 002328A0  4E 80 00 20 */	blr 
.endfn loadResource__Q34Game6VsGame7CardMgrFv


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

.fn update__Q44Game6VsGame7CardMgr11SlotMachineFv, global
/* 80237060 00233FA0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80237064 00233FA4  7C 08 02 A6 */	mflr r0
/* 80237068 00233FA8  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023706C 00233FAC  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80237070 00233FB0  F3 E1 00 28 */	psq_st f31, 40(r1), 0, qr0
/* 80237074 00233FB4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80237078 00233FB8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023707C 00233FBC  7C 7F 1B 78 */	mr r31, r3
/* 80237080 00233FC0  48 00 07 99 */	bl updateAppear__Q44Game6VsGame7CardMgr11SlotMachineFv
/* 80237084 00233FC4  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80237088 00233FC8  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8023708C 00233FCC  28 00 00 0A */	cmplwi r0, 0xa
/* 80237090 00233FD0  C3 E3 00 54 */	lfs f31, 0x54(r3)
/* 80237094 00233FD4  41 81 06 80 */	bgt .L_80237714
/* 80237098 00233FD8  3C 60 80 4C */	lis r3, lbl_804C14AC@ha
/* 8023709C 00233FDC  54 00 10 3A */	slwi r0, r0, 2
/* 802370A0 00233FE0  38 63 14 AC */	addi r3, r3, lbl_804C14AC@l
/* 802370A4 00233FE4  7C 03 00 2E */	lwzx r0, r3, r0
/* 802370A8 00233FE8  7C 09 03 A6 */	mtctr r0
/* 802370AC 00233FEC  4E 80 04 20 */	bctr 
.L_802370B0:
/* 802370B0 00233FF0  C0 22 C1 1C */	lfs f1, lbl_8051A47C@sda21(r2)
/* 802370B4 00233FF4  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 802370B8 00233FF8  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 802370BC 00233FFC  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 802370C0 00234000  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802370C4 00234004  40 80 06 50 */	bge .L_80237714
/* 802370C8 00234008  38 00 00 02 */	li r0, 2
/* 802370CC 0023400C  C0 02 C0 F4 */	lfs f0, lbl_8051A454@sda21(r2)
/* 802370D0 00234010  90 1F 00 20 */	stw r0, 0x20(r31)
/* 802370D4 00234014  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 802370D8 00234018  48 00 06 3C */	b .L_80237714
.L_802370DC:
/* 802370DC 0023401C  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 802370E0 00234020  2C 00 00 01 */	cmpwi r0, 1
/* 802370E4 00234024  41 80 00 10 */	blt .L_802370F4
/* 802370E8 00234028  C0 02 C1 24 */	lfs f0, lbl_8051A484@sda21(r2)
/* 802370EC 0023402C  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 802370F0 00234030  48 00 00 0C */	b .L_802370FC
.L_802370F4:
/* 802370F4 00234034  C0 02 C1 1C */	lfs f0, lbl_8051A47C@sda21(r2)
/* 802370F8 00234038  D0 1F 00 14 */	stfs f0, 0x14(r31)
.L_802370FC:
/* 802370FC 0023403C  3C 60 80 51 */	lis r3, gGameConfig__4Game@ha
/* 80237100 00234040  38 63 41 FC */	addi r3, r3, gGameConfig__4Game@l
/* 80237104 00234044  80 03 01 B8 */	lwz r0, 0x1b8(r3)
/* 80237108 00234048  2C 00 00 01 */	cmpwi r0, 1
/* 8023710C 0023404C  40 82 00 14 */	bne .L_80237120
/* 80237110 00234050  C0 3F 00 14 */	lfs f1, 0x14(r31)
/* 80237114 00234054  C0 02 C1 28 */	lfs f0, lbl_8051A488@sda21(r2)
/* 80237118 00234058  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023711C 0023405C  D0 1F 00 14 */	stfs f0, 0x14(r31)
.L_80237120:
/* 80237120 00234060  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 80237124 00234064  C0 02 C1 24 */	lfs f0, lbl_8051A484@sda21(r2)
/* 80237128 00234068  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023712C 0023406C  40 80 05 E8 */	bge .L_80237714
/* 80237130 00234070  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 80237134 00234074  38 00 00 03 */	li r0, 3
/* 80237138 00234078  90 1F 00 20 */	stw r0, 0x20(r31)
/* 8023713C 0023407C  80 03 01 B8 */	lwz r0, 0x1b8(r3)
/* 80237140 00234080  2C 00 00 00 */	cmpwi r0, 0
/* 80237144 00234084  40 82 00 54 */	bne .L_80237198
/* 80237148 00234088  4B E9 24 59 */	bl rand
/* 8023714C 0023408C  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80237150 00234090  3C 00 43 30 */	lis r0, 0x4330
/* 80237154 00234094  90 61 00 0C */	stw r3, 0xc(r1)
/* 80237158 00234098  C8 62 C0 88 */	lfd f3, lbl_8051A3E8@sda21(r2)
/* 8023715C 0023409C  90 01 00 08 */	stw r0, 8(r1)
/* 80237160 002340A0  C0 42 C0 80 */	lfs f2, lbl_8051A3E0@sda21(r2)
/* 80237164 002340A4  C8 01 00 08 */	lfd f0, 8(r1)
/* 80237168 002340A8  C0 22 C1 00 */	lfs f1, lbl_8051A460@sda21(r2)
/* 8023716C 002340AC  EC 60 18 28 */	fsubs f3, f0, f3
/* 80237170 002340B0  C0 02 C1 0C */	lfs f0, lbl_8051A46C@sda21(r2)
/* 80237174 002340B4  EC 43 10 24 */	fdivs f2, f3, f2
/* 80237178 002340B8  EC 01 00 BA */	fmadds f0, f1, f2, f0
/* 8023717C 002340BC  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 80237180 002340C0  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80237184 002340C4  2C 00 00 01 */	cmpwi r0, 1
/* 80237188 002340C8  41 80 05 8C */	blt .L_80237714
/* 8023718C 002340CC  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237190 002340D0  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 80237194 002340D4  48 00 05 80 */	b .L_80237714
.L_80237198:
/* 80237198 002340D8  C0 3F 00 54 */	lfs f1, 0x54(r31)
/* 8023719C 002340DC  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 802371A0 002340E0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802371A4 002340E4  40 81 05 70 */	ble .L_80237714
/* 802371A8 002340E8  4B E9 23 F9 */	bl rand
/* 802371AC 002340EC  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802371B0 002340F0  3C 00 43 30 */	lis r0, 0x4330
/* 802371B4 002340F4  90 61 00 0C */	stw r3, 0xc(r1)
/* 802371B8 002340F8  C8 62 C0 88 */	lfd f3, lbl_8051A3E8@sda21(r2)
/* 802371BC 002340FC  90 01 00 08 */	stw r0, 8(r1)
/* 802371C0 00234100  C0 42 C0 80 */	lfs f2, lbl_8051A3E0@sda21(r2)
/* 802371C4 00234104  C8 01 00 08 */	lfd f0, 8(r1)
/* 802371C8 00234108  C0 22 C1 00 */	lfs f1, lbl_8051A460@sda21(r2)
/* 802371CC 0023410C  EC 60 18 28 */	fsubs f3, f0, f3
/* 802371D0 00234110  C0 02 C1 2C */	lfs f0, lbl_8051A48C@sda21(r2)
/* 802371D4 00234114  EC 43 10 24 */	fdivs f2, f3, f2
/* 802371D8 00234118  EC 01 00 BA */	fmadds f0, f1, f2, f0
/* 802371DC 0023411C  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 802371E0 00234120  48 00 05 34 */	b .L_80237714
.L_802371E4:
/* 802371E4 00234124  C0 02 C1 24 */	lfs f0, lbl_8051A484@sda21(r2)
/* 802371E8 00234128  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 802371EC 0023412C  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 802371F0 00234130  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 802371F4 00234134  C0 1F 00 54 */	lfs f0, 0x54(r31)
/* 802371F8 00234138  EC 00 F8 28 */	fsubs f0, f0, f31
/* 802371FC 0023413C  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 80237200 00234140  C0 1F 00 54 */	lfs f0, 0x54(r31)
/* 80237204 00234144  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80237208 00234148  4C 40 13 82 */	cror 2, 0, 2
/* 8023720C 0023414C  40 82 05 08 */	bne .L_80237714
/* 80237210 00234150  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 80237214 00234154  3C 60 2A AB */	lis r3, 0x2AAAAAAB@ha
/* 80237218 00234158  38 03 AA AB */	addi r0, r3, 0x2AAAAAAB@l
/* 8023721C 0023415C  80 BF 00 04 */	lwz r5, 4(r31)
/* 80237220 00234160  38 84 00 0D */	addi r4, r4, 0xd
/* 80237224 00234164  7C 00 20 96 */	mulhw r0, r0, r4
/* 80237228 00234168  7C 00 0E 70 */	srawi r0, r0, 1
/* 8023722C 0023416C  54 03 0F FE */	srwi r3, r0, 0x1f
/* 80237230 00234170  7C 00 1A 14 */	add r0, r0, r3
/* 80237234 00234174  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80237238 00234178  7C 00 20 50 */	subf r0, r0, r4
/* 8023723C 0023417C  7C 05 00 00 */	cmpw r5, r0
/* 80237240 00234180  40 82 04 D4 */	bne .L_80237714
/* 80237244 00234184  38 00 00 04 */	li r0, 4
/* 80237248 00234188  C0 02 C0 E8 */	lfs f0, lbl_8051A448@sda21(r2)
/* 8023724C 0023418C  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80237250 00234190  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 80237254 00234194  48 00 04 C0 */	b .L_80237714
.L_80237258:
/* 80237258 00234198  C0 02 C0 E8 */	lfs f0, lbl_8051A448@sda21(r2)
/* 8023725C 0023419C  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 80237260 002341A0  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80237264 002341A4  2C 00 00 01 */	cmpwi r0, 1
/* 80237268 002341A8  41 80 00 2C */	blt .L_80237294
/* 8023726C 002341AC  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 80237270 002341B0  C0 02 C1 30 */	lfs f0, lbl_8051A490@sda21(r2)
/* 80237274 002341B4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237278 002341B8  40 81 04 9C */	ble .L_80237714
/* 8023727C 002341BC  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237280 002341C0  38 00 00 05 */	li r0, 5
/* 80237284 002341C4  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 80237288 002341C8  90 1F 00 20 */	stw r0, 0x20(r31)
/* 8023728C 002341CC  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 80237290 002341D0  48 00 04 84 */	b .L_80237714
.L_80237294:
/* 80237294 002341D4  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 80237298 002341D8  C0 02 C1 30 */	lfs f0, lbl_8051A490@sda21(r2)
/* 8023729C 002341DC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802372A0 002341E0  40 81 04 74 */	ble .L_80237714
/* 802372A4 002341E4  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 802372A8 002341E8  38 00 00 05 */	li r0, 5
/* 802372AC 002341EC  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 802372B0 002341F0  90 1F 00 20 */	stw r0, 0x20(r31)
/* 802372B4 002341F4  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 802372B8 002341F8  48 00 04 5C */	b .L_80237714
.L_802372BC:
/* 802372BC 002341FC  C0 3F 00 2C */	lfs f1, 0x2c(r31)
/* 802372C0 00234200  C0 02 C1 28 */	lfs f0, lbl_8051A488@sda21(r2)
/* 802372C4 00234204  EC 21 F8 2A */	fadds f1, f1, f31
/* 802372C8 00234208  D0 3F 00 2C */	stfs f1, 0x2c(r31)
/* 802372CC 0023420C  C0 3F 00 2C */	lfs f1, 0x2c(r31)
/* 802372D0 00234210  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802372D4 00234214  4C 41 13 82 */	cror 2, 1, 2
/* 802372D8 00234218  40 82 00 B8 */	bne .L_80237390
/* 802372DC 0023421C  80 7F 00 04 */	lwz r3, 4(r31)
/* 802372E0 00234220  3C 00 43 30 */	lis r0, 0x4330
/* 802372E4 00234224  90 01 00 08 */	stw r0, 8(r1)
/* 802372E8 00234228  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 802372EC 0023422C  C8 42 C0 88 */	lfd f2, lbl_8051A3E8@sda21(r2)
/* 802372F0 00234230  90 01 00 0C */	stw r0, 0xc(r1)
/* 802372F4 00234234  C0 7F 00 0C */	lfs f3, 0xc(r31)
/* 802372F8 00234238  C8 21 00 08 */	lfd f1, 8(r1)
/* 802372FC 0023423C  C0 02 C1 20 */	lfs f0, lbl_8051A480@sda21(r2)
/* 80237300 00234240  EC 21 10 28 */	fsubs f1, f1, f2
/* 80237304 00234244  EC 23 08 28 */	fsubs f1, f3, f1
/* 80237308 00234248  FC 20 0A 10 */	fabs f1, f1
/* 8023730C 0023424C  FC 20 08 18 */	frsp f1, f1
/* 80237310 00234250  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237314 00234254  40 80 00 7C */	bge .L_80237390
/* 80237318 00234258  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 8023731C 0023425C  3C 60 2A AB */	lis r3, 0x2AAAAAAB@ha
/* 80237320 00234260  38 83 AA AB */	addi r4, r3, 0x2AAAAAAB@l
/* 80237324 00234264  38 00 00 0A */	li r0, 0xa
/* 80237328 00234268  D0 3F 00 6C */	stfs f1, 0x6c(r31)
/* 8023732C 0023426C  7F E3 FB 78 */	mr r3, r31
/* 80237330 00234270  C0 02 C1 10 */	lfs f0, lbl_8051A470@sda21(r2)
/* 80237334 00234274  D0 3F 00 68 */	stfs f1, 0x68(r31)
/* 80237338 00234278  80 BF 00 04 */	lwz r5, 4(r31)
/* 8023733C 0023427C  38 C5 00 0B */	addi r6, r5, 0xb
/* 80237340 00234280  7C 84 30 96 */	mulhw r4, r4, r6
/* 80237344 00234284  7C 84 0E 70 */	srawi r4, r4, 1
/* 80237348 00234288  54 85 0F FE */	srwi r5, r4, 0x1f
/* 8023734C 0023428C  7C 84 2A 14 */	add r4, r4, r5
/* 80237350 00234290  1C 84 00 0C */	mulli r4, r4, 0xc
/* 80237354 00234294  7C 84 30 50 */	subf r4, r4, r6
/* 80237358 00234298  90 9F 00 24 */	stw r4, 0x24(r31)
/* 8023735C 0023429C  D0 3F 00 2C */	stfs f1, 0x2c(r31)
/* 80237360 002342A0  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 80237364 002342A4  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 80237368 002342A8  90 1F 00 20 */	stw r0, 0x20(r31)
/* 8023736C 002342AC  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 80237370 002342B0  90 1F 00 4C */	stw r0, 0x4c(r31)
/* 80237374 002342B4  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 80237378 002342B8  48 00 17 95 */	bl startZoomIn__Q44Game6VsGame7CardMgr11SlotMachineFv
/* 8023737C 002342BC  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 80237380 002342C0  38 80 18 00 */	li r4, 0x1800
/* 80237384 002342C4  38 A0 00 00 */	li r5, 0
/* 80237388 002342C8  48 10 12 A9 */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
/* 8023738C 002342CC  48 00 03 88 */	b .L_80237714
.L_80237390:
/* 80237390 002342D0  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 80237394 002342D4  3C 00 43 30 */	lis r0, 0x4330
/* 80237398 002342D8  3C 60 2A AB */	lis r3, 0x2AAAAAAB@ha
/* 8023739C 002342DC  90 01 00 08 */	stw r0, 8(r1)
/* 802373A0 002342E0  38 84 00 0D */	addi r4, r4, 0xd
/* 802373A4 002342E4  C8 62 C0 88 */	lfd f3, lbl_8051A3E8@sda21(r2)
/* 802373A8 002342E8  38 63 AA AB */	addi r3, r3, 0x2AAAAAAB@l
/* 802373AC 002342EC  90 01 00 10 */	stw r0, 0x10(r1)
/* 802373B0 002342F0  7C 03 20 96 */	mulhw r0, r3, r4
/* 802373B4 002342F4  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 802373B8 002342F8  7C 00 0E 70 */	srawi r0, r0, 1
/* 802373BC 002342FC  54 03 0F FE */	srwi r3, r0, 0x1f
/* 802373C0 00234300  7C 00 1A 14 */	add r0, r0, r3
/* 802373C4 00234304  1C 00 00 0C */	mulli r0, r0, 0xc
/* 802373C8 00234308  7C 60 20 50 */	subf r3, r0, r4
/* 802373CC 0023430C  38 03 00 0C */	addi r0, r3, 0xc
/* 802373D0 00234310  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 802373D4 00234314  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 802373D8 00234318  90 61 00 0C */	stw r3, 0xc(r1)
/* 802373DC 0023431C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802373E0 00234320  C8 21 00 08 */	lfd f1, 8(r1)
/* 802373E4 00234324  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 802373E8 00234328  EC 21 18 28 */	fsubs f1, f1, f3
/* 802373EC 0023432C  EC 00 18 28 */	fsubs f0, f0, f3
/* 802373F0 00234330  EC 21 10 28 */	fsubs f1, f1, f2
/* 802373F4 00234334  EC 00 10 28 */	fsubs f0, f0, f2
/* 802373F8 00234338  FC 20 0A 10 */	fabs f1, f1
/* 802373FC 0023433C  FC 00 02 10 */	fabs f0, f0
/* 80237400 00234340  FC 20 08 18 */	frsp f1, f1
/* 80237404 00234344  FC 00 00 18 */	frsp f0, f0
/* 80237408 00234348  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8023740C 0023434C  40 80 00 08 */	bge .L_80237414
/* 80237410 00234350  FC 20 00 90 */	fmr f1, f0
.L_80237414:
/* 80237414 00234354  C0 02 C1 20 */	lfs f0, lbl_8051A480@sda21(r2)
/* 80237418 00234358  38 00 00 00 */	li r0, 0
/* 8023741C 0023435C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237420 00234360  40 80 00 18 */	bge .L_80237438
/* 80237424 00234364  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237428 00234368  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023742C 0023436C  4C 41 13 82 */	cror 2, 1, 2
/* 80237430 00234370  40 82 00 08 */	bne .L_80237438
/* 80237434 00234374  38 00 00 01 */	li r0, 1
.L_80237438:
/* 80237438 00234378  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8023743C 0023437C  41 82 02 D8 */	beq .L_80237714
/* 80237440 00234380  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 80237444 00234384  38 00 00 0A */	li r0, 0xa
/* 80237448 00234388  C0 02 C1 10 */	lfs f0, lbl_8051A470@sda21(r2)
/* 8023744C 0023438C  7F E3 FB 78 */	mr r3, r31
/* 80237450 00234390  D0 3F 00 6C */	stfs f1, 0x6c(r31)
/* 80237454 00234394  D0 3F 00 68 */	stfs f1, 0x68(r31)
/* 80237458 00234398  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8023745C 0023439C  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 80237460 002343A0  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80237464 002343A4  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 80237468 002343A8  90 1F 00 4C */	stw r0, 0x4c(r31)
/* 8023746C 002343AC  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 80237470 002343B0  48 00 16 9D */	bl startZoomIn__Q44Game6VsGame7CardMgr11SlotMachineFv
/* 80237474 002343B4  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 80237478 002343B8  38 80 18 00 */	li r4, 0x1800
/* 8023747C 002343BC  38 A0 00 00 */	li r5, 0
/* 80237480 002343C0  48 10 11 B1 */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
/* 80237484 002343C4  48 00 02 90 */	b .L_80237714
.L_80237488:
/* 80237488 002343C8  C0 3F 00 54 */	lfs f1, 0x54(r31)
/* 8023748C 002343CC  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237490 002343D0  EC 21 F8 28 */	fsubs f1, f1, f31
/* 80237494 002343D4  D0 3F 00 54 */	stfs f1, 0x54(r31)
/* 80237498 002343D8  C0 3F 00 54 */	lfs f1, 0x54(r31)
/* 8023749C 002343DC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802374A0 002343E0  4C 40 13 82 */	cror 2, 0, 2
/* 802374A4 002343E4  40 82 02 70 */	bne .L_80237714
/* 802374A8 002343E8  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 802374AC 002343EC  38 00 00 09 */	li r0, 9
/* 802374B0 002343F0  C0 02 C1 1C */	lfs f0, lbl_8051A47C@sda21(r2)
/* 802374B4 002343F4  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 802374B8 002343F8  90 1F 00 20 */	stw r0, 0x20(r31)
/* 802374BC 002343FC  48 00 02 58 */	b .L_80237714
.L_802374C0:
/* 802374C0 00234400  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 802374C4 00234404  3C 00 43 30 */	lis r0, 0x4330
/* 802374C8 00234408  3C 60 2A AB */	lis r3, 0x2AAAAAAB@ha
/* 802374CC 0023440C  90 01 00 10 */	stw r0, 0x10(r1)
/* 802374D0 00234410  38 84 00 0D */	addi r4, r4, 0xd
/* 802374D4 00234414  C8 62 C0 88 */	lfd f3, lbl_8051A3E8@sda21(r2)
/* 802374D8 00234418  38 63 AA AB */	addi r3, r3, 0x2AAAAAAB@l
/* 802374DC 0023441C  90 01 00 08 */	stw r0, 8(r1)
/* 802374E0 00234420  7C 03 20 96 */	mulhw r0, r3, r4
/* 802374E4 00234424  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 802374E8 00234428  7C 00 0E 70 */	srawi r0, r0, 1
/* 802374EC 0023442C  54 03 0F FE */	srwi r3, r0, 0x1f
/* 802374F0 00234430  7C 00 1A 14 */	add r0, r0, r3
/* 802374F4 00234434  1C 00 00 0C */	mulli r0, r0, 0xc
/* 802374F8 00234438  7C 60 20 50 */	subf r3, r0, r4
/* 802374FC 0023443C  38 03 00 0C */	addi r0, r3, 0xc
/* 80237500 00234440  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80237504 00234444  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80237508 00234448  90 61 00 14 */	stw r3, 0x14(r1)
/* 8023750C 0023444C  90 01 00 0C */	stw r0, 0xc(r1)
/* 80237510 00234450  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80237514 00234454  C8 01 00 08 */	lfd f0, 8(r1)
/* 80237518 00234458  EC 21 18 28 */	fsubs f1, f1, f3
/* 8023751C 0023445C  EC 00 18 28 */	fsubs f0, f0, f3
/* 80237520 00234460  EC 21 10 28 */	fsubs f1, f1, f2
/* 80237524 00234464  EC 00 10 28 */	fsubs f0, f0, f2
/* 80237528 00234468  FC 20 0A 10 */	fabs f1, f1
/* 8023752C 0023446C  FC 00 02 10 */	fabs f0, f0
/* 80237530 00234470  FC 20 08 18 */	frsp f1, f1
/* 80237534 00234474  FC 00 00 18 */	frsp f0, f0
/* 80237538 00234478  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8023753C 0023447C  40 80 00 08 */	bge .L_80237544
/* 80237540 00234480  FC 20 00 90 */	fmr f1, f0
.L_80237544:
/* 80237544 00234484  C0 02 C1 20 */	lfs f0, lbl_8051A480@sda21(r2)
/* 80237548 00234488  38 00 00 00 */	li r0, 0
/* 8023754C 0023448C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237550 00234490  40 80 00 18 */	bge .L_80237568
/* 80237554 00234494  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237558 00234498  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023755C 0023449C  4C 41 13 82 */	cror 2, 1, 2
/* 80237560 002344A0  40 82 00 08 */	bne .L_80237568
/* 80237564 002344A4  38 00 00 01 */	li r0, 1
.L_80237568:
/* 80237568 002344A8  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8023756C 002344AC  41 82 01 A8 */	beq .L_80237714
/* 80237570 002344B0  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237574 002344B4  38 00 00 0A */	li r0, 0xa
/* 80237578 002344B8  38 80 18 00 */	li r4, 0x1800
/* 8023757C 002344BC  38 A0 00 00 */	li r5, 0
/* 80237580 002344C0  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 80237584 002344C4  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 80237588 002344C8  90 1F 00 20 */	stw r0, 0x20(r31)
/* 8023758C 002344CC  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 80237590 002344D0  48 10 10 A1 */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
/* 80237594 002344D4  48 00 01 80 */	b .L_80237714
.L_80237598:
/* 80237598 002344D8  C0 3F 00 54 */	lfs f1, 0x54(r31)
/* 8023759C 002344DC  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 802375A0 002344E0  EC 21 F8 28 */	fsubs f1, f1, f31
/* 802375A4 002344E4  D0 3F 00 54 */	stfs f1, 0x54(r31)
/* 802375A8 002344E8  C0 3F 00 54 */	lfs f1, 0x54(r31)
/* 802375AC 002344EC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802375B0 002344F0  4C 40 13 82 */	cror 2, 0, 2
/* 802375B4 002344F4  40 82 01 60 */	bne .L_80237714
/* 802375B8 002344F8  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 802375BC 002344FC  38 00 00 07 */	li r0, 7
/* 802375C0 00234500  C0 02 C0 E8 */	lfs f0, lbl_8051A448@sda21(r2)
/* 802375C4 00234504  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 802375C8 00234508  90 1F 00 20 */	stw r0, 0x20(r31)
/* 802375CC 0023450C  48 00 01 48 */	b .L_80237714
.L_802375D0:
/* 802375D0 00234510  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 802375D4 00234514  3C 00 43 30 */	lis r0, 0x4330
/* 802375D8 00234518  3C 60 2A AB */	lis r3, 0x2AAAAAAB@ha
/* 802375DC 0023451C  90 01 00 10 */	stw r0, 0x10(r1)
/* 802375E0 00234520  38 84 00 0D */	addi r4, r4, 0xd
/* 802375E4 00234524  C8 62 C0 88 */	lfd f3, lbl_8051A3E8@sda21(r2)
/* 802375E8 00234528  38 63 AA AB */	addi r3, r3, 0x2AAAAAAB@l
/* 802375EC 0023452C  90 01 00 08 */	stw r0, 8(r1)
/* 802375F0 00234530  7C 03 20 96 */	mulhw r0, r3, r4
/* 802375F4 00234534  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 802375F8 00234538  7C 00 0E 70 */	srawi r0, r0, 1
/* 802375FC 0023453C  54 03 0F FE */	srwi r3, r0, 0x1f
/* 80237600 00234540  7C 00 1A 14 */	add r0, r0, r3
/* 80237604 00234544  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80237608 00234548  7C 60 20 50 */	subf r3, r0, r4
/* 8023760C 0023454C  38 03 00 0C */	addi r0, r3, 0xc
/* 80237610 00234550  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80237614 00234554  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80237618 00234558  90 61 00 14 */	stw r3, 0x14(r1)
/* 8023761C 0023455C  90 01 00 0C */	stw r0, 0xc(r1)
/* 80237620 00234560  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80237624 00234564  C8 01 00 08 */	lfd f0, 8(r1)
/* 80237628 00234568  EC 21 18 28 */	fsubs f1, f1, f3
/* 8023762C 0023456C  EC 00 18 28 */	fsubs f0, f0, f3
/* 80237630 00234570  EC 21 10 28 */	fsubs f1, f1, f2
/* 80237634 00234574  EC 00 10 28 */	fsubs f0, f0, f2
/* 80237638 00234578  FC 20 0A 10 */	fabs f1, f1
/* 8023763C 0023457C  FC 00 02 10 */	fabs f0, f0
/* 80237640 00234580  FC 20 08 18 */	frsp f1, f1
/* 80237644 00234584  FC 00 00 18 */	frsp f0, f0
/* 80237648 00234588  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8023764C 0023458C  40 80 00 08 */	bge .L_80237654
/* 80237650 00234590  FC 20 00 90 */	fmr f1, f0
.L_80237654:
/* 80237654 00234594  C0 02 C1 20 */	lfs f0, lbl_8051A480@sda21(r2)
/* 80237658 00234598  38 00 00 00 */	li r0, 0
/* 8023765C 0023459C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237660 002345A0  40 80 00 18 */	bge .L_80237678
/* 80237664 002345A4  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237668 002345A8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023766C 002345AC  4C 41 13 82 */	cror 2, 1, 2
/* 80237670 002345B0  40 82 00 08 */	bne .L_80237678
/* 80237674 002345B4  38 00 00 01 */	li r0, 1
.L_80237678:
/* 80237678 002345B8  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8023767C 002345BC  41 82 00 98 */	beq .L_80237714
/* 80237680 002345C0  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 80237684 002345C4  38 00 00 0A */	li r0, 0xa
/* 80237688 002345C8  C0 02 C1 34 */	lfs f0, lbl_8051A494@sda21(r2)
/* 8023768C 002345CC  38 80 18 00 */	li r4, 0x1800
/* 80237690 002345D0  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 80237694 002345D4  38 A0 00 00 */	li r5, 0
/* 80237698 002345D8  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 8023769C 002345DC  90 1F 00 20 */	stw r0, 0x20(r31)
/* 802376A0 002345E0  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 802376A4 002345E4  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 802376A8 002345E8  48 10 0F 89 */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
/* 802376AC 002345EC  48 00 00 68 */	b .L_80237714
.L_802376B0:
/* 802376B0 002345F0  38 00 00 01 */	li r0, 1
/* 802376B4 002345F4  3C 60 80 51 */	lis r3, gGameConfig__4Game@ha
/* 802376B8 002345F8  98 1F 00 51 */	stb r0, 0x51(r31)
/* 802376BC 002345FC  38 63 41 FC */	addi r3, r3, gGameConfig__4Game@l
/* 802376C0 00234600  C0 42 C0 78 */	lfs f2, lbl_8051A3D8@sda21(r2)
/* 802376C4 00234604  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 802376C8 00234608  90 1F 00 58 */	stw r0, 0x58(r31)
/* 802376CC 0023460C  D0 5F 00 10 */	stfs f2, 0x10(r31)
/* 802376D0 00234610  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 802376D4 00234614  80 03 01 B8 */	lwz r0, 0x1b8(r3)
/* 802376D8 00234618  2C 00 00 01 */	cmpwi r0, 1
/* 802376DC 0023461C  40 82 00 38 */	bne .L_80237714
/* 802376E0 00234620  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 802376E4 00234624  C0 3F 00 54 */	lfs f1, 0x54(r31)
/* 802376E8 00234628  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 802376EC 0023462C  EC 01 00 28 */	fsubs f0, f1, f0
/* 802376F0 00234630  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 802376F4 00234634  C0 1F 00 54 */	lfs f0, 0x54(r31)
/* 802376F8 00234638  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 802376FC 0023463C  4C 40 13 82 */	cror 2, 0, 2
/* 80237700 00234640  40 82 00 14 */	bne .L_80237714
/* 80237704 00234644  80 7F 00 60 */	lwz r3, 0x60(r31)
/* 80237708 00234648  38 A0 00 00 */	li r5, 0
/* 8023770C 0023464C  80 9F 00 5C */	lwz r4, 0x5c(r31)
/* 80237710 00234650  4B FF E3 71 */	bl usePlayerCard__Q34Game6VsGame7CardMgrFiPQ34Game6VsGame7TekiMgr
.L_80237714:
/* 80237714 00234654  C0 5F 00 10 */	lfs f2, 0x10(r31)
/* 80237718 00234658  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8023771C 0023465C  C0 02 C0 E8 */	lfs f0, lbl_8051A448@sda21(r2)
/* 80237720 00234660  EC 22 0F FA */	fmadds f1, f2, f31, f1
/* 80237724 00234664  D0 3F 00 00 */	stfs f1, 0(r31)
/* 80237728 00234668  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8023772C 0023466C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237730 00234670  40 81 00 0C */	ble .L_8023773C
/* 80237734 00234674  EC 01 00 28 */	fsubs f0, f1, f0
/* 80237738 00234678  D0 1F 00 00 */	stfs f0, 0(r31)
.L_8023773C:
/* 8023773C 0023467C  C0 3F 00 00 */	lfs f1, 0(r31)
/* 80237740 00234680  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 80237744 00234684  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80237748 00234688  40 80 00 10 */	bge .L_80237758
/* 8023774C 0023468C  C0 02 C0 E8 */	lfs f0, lbl_8051A448@sda21(r2)
/* 80237750 00234690  EC 01 00 2A */	fadds f0, f1, f0
/* 80237754 00234694  D0 1F 00 00 */	stfs f0, 0(r31)
.L_80237758:
/* 80237758 00234698  C0 5F 00 14 */	lfs f2, 0x14(r31)
/* 8023775C 0023469C  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 80237760 002346A0  C0 02 C1 38 */	lfs f0, lbl_8051A498@sda21(r2)
/* 80237764 002346A4  EC 22 0F FA */	fmadds f1, f2, f31, f1
/* 80237768 002346A8  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8023776C 002346AC  83 DF 00 04 */	lwz r30, 4(r31)
/* 80237770 002346B0  93 DF 00 08 */	stw r30, 8(r31)
/* 80237774 002346B4  C0 3F 00 00 */	lfs f1, 0(r31)
/* 80237778 002346B8  EC 21 00 2A */	fadds f1, f1, f0
/* 8023777C 002346BC  48 1D A4 55 */	bl roundAng__Ff
/* 80237780 002346C0  C0 02 C1 38 */	lfs f0, lbl_8051A498@sda21(r2)
/* 80237784 002346C4  EC 01 00 24 */	fdivs f0, f1, f0
/* 80237788 002346C8  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8023778C 002346CC  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 80237790 002346D0  FC 00 00 1E */	fctiwz f0, f0
/* 80237794 002346D4  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 80237798 002346D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023779C 002346DC  90 1F 00 04 */	stw r0, 4(r31)
/* 802377A0 002346E0  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 802377A4 002346E4  2C 00 00 0A */	cmpwi r0, 0xa
/* 802377A8 002346E8  41 82 00 50 */	beq .L_802377F8
/* 802377AC 002346EC  2C 00 00 00 */	cmpwi r0, 0
/* 802377B0 002346F0  41 82 00 48 */	beq .L_802377F8
/* 802377B4 002346F4  80 7F 00 60 */	lwz r3, 0x60(r31)
/* 802377B8 002346F8  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 802377BC 002346FC  C0 03 01 04 */	lfs f0, 0x104(r3)
/* 802377C0 00234700  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802377C4 00234704  40 81 00 18 */	ble .L_802377DC
/* 802377C8 00234708  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 802377CC 0023470C  38 80 10 3B */	li r4, 0x103b
/* 802377D0 00234710  38 A0 00 00 */	li r5, 0
/* 802377D4 00234714  48 10 0E 5D */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
/* 802377D8 00234718  48 00 00 20 */	b .L_802377F8
.L_802377DC:
/* 802377DC 0023471C  80 1F 00 04 */	lwz r0, 4(r31)
/* 802377E0 00234720  7C 1E 00 00 */	cmpw r30, r0
/* 802377E4 00234724  41 82 00 14 */	beq .L_802377F8
/* 802377E8 00234728  80 6D 98 58 */	lwz r3, spSysIF__8PSSystem@sda21(r13)
/* 802377EC 0023472C  38 80 18 02 */	li r4, 0x1802
/* 802377F0 00234730  38 A0 00 00 */	li r5, 0
/* 802377F4 00234734  48 10 0E 3D */	bl playSystemSe__Q28PSSystem5SysIFFUlUl
.L_802377F8:
/* 802377F8 00234738  E3 E1 00 28 */	psq_l f31, 40(r1), 0, qr0
/* 802377FC 0023473C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80237800 00234740  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80237804 00234744  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80237808 00234748  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023780C 0023474C  7C 08 03 A6 */	mtlr r0
/* 80237810 00234750  38 21 00 30 */	addi r1, r1, 0x30
/* 80237814 00234754  4E 80 00 20 */	blr 
.endfn update__Q44Game6VsGame7CardMgr11SlotMachineFv

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

.fn initDraw__Q34Game6VsGame7CardMgrFv, global
/* 80237968 002348A8  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 8023796C 002348AC  7C 08 02 A6 */	mflr r0
/* 80237970 002348B0  90 01 00 74 */	stw r0, 0x74(r1)
/* 80237974 002348B4  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 80237978 002348B8  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 8023797C 002348BC  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80237980 002348C0  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80237984 002348C4  7C 7F 1B 78 */	mr r31, r3
/* 80237988 002348C8  38 00 03 00 */	li r0, 0x300
/* 8023798C 002348CC  90 03 00 F8 */	stw r0, 0xf8(r3)
/* 80237990 002348D0  83 C3 00 F8 */	lwz r30, 0xf8(r3)
/* 80237994 002348D4  1C 7E 00 0C */	mulli r3, r30, 0xc
/* 80237998 002348D8  38 63 00 10 */	addi r3, r3, 0x10
/* 8023799C 002348DC  4B DE C6 11 */	bl __nwa__FUl
/* 802379A0 002348E0  3C 80 80 12 */	lis r4, "__ct__10Vector3<f>Fv"@ha
/* 802379A4 002348E4  7F C7 F3 78 */	mr r7, r30
/* 802379A8 002348E8  38 84 F3 48 */	addi r4, r4, "__ct__10Vector3<f>Fv"@l
/* 802379AC 002348EC  38 A0 00 00 */	li r5, 0
/* 802379B0 002348F0  38 C0 00 0C */	li r6, 0xc
/* 802379B4 002348F4  4B E8 A0 3D */	bl __construct_new_array
/* 802379B8 002348F8  90 7F 00 FC */	stw r3, 0xfc(r31)
/* 802379BC 002348FC  83 DF 00 F8 */	lwz r30, 0xf8(r31)
/* 802379C0 00234900  1C 7E 00 0C */	mulli r3, r30, 0xc
/* 802379C4 00234904  38 63 00 10 */	addi r3, r3, 0x10
/* 802379C8 00234908  4B DE C5 E5 */	bl __nwa__FUl
/* 802379CC 0023490C  3C 80 80 12 */	lis r4, "__ct__10Vector3<f>Fv"@ha
/* 802379D0 00234910  7F C7 F3 78 */	mr r7, r30
/* 802379D4 00234914  38 84 F3 48 */	addi r4, r4, "__ct__10Vector3<f>Fv"@l
/* 802379D8 00234918  38 A0 00 00 */	li r5, 0
/* 802379DC 0023491C  38 C0 00 0C */	li r6, 0xc
/* 802379E0 00234920  4B E8 A0 11 */	bl __construct_new_array
/* 802379E4 00234924  C0 42 C0 DC */	lfs f2, lbl_8051A43C@sda21(r2)
/* 802379E8 00234928  C0 22 C1 38 */	lfs f1, lbl_8051A498@sda21(r2)
/* 802379EC 0023492C  C0 02 C0 78 */	lfs f0, lbl_8051A3D8@sda21(r2)
/* 802379F0 00234930  EC 22 00 72 */	fmuls f1, f2, f1
/* 802379F4 00234934  90 7F 01 00 */	stw r3, 0x100(r31)
/* 802379F8 00234938  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802379FC 0023493C  40 80 00 30 */	bge .L_80237A2C
/* 80237A00 00234940  C0 02 C0 F0 */	lfs f0, lbl_8051A450@sda21(r2)
/* 80237A04 00234944  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 80237A08 00234948  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 80237A0C 0023494C  EC 01 00 32 */	fmuls f0, f1, f0
/* 80237A10 00234950  FC 00 00 1E */	fctiwz f0, f0
/* 80237A14 00234954  D8 01 00 08 */	stfd f0, 8(r1)
/* 80237A18 00234958  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80237A1C 0023495C  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 80237A20 00234960  7C 03 04 2E */	lfsx f0, r3, r0
/* 80237A24 00234964  FC 00 00 50 */	fneg f0, f0
/* 80237A28 00234968  48 00 00 28 */	b .L_80237A50
.L_80237A2C:
/* 80237A2C 0023496C  C0 02 C0 EC */	lfs f0, lbl_8051A44C@sda21(r2)
/* 80237A30 00234970  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 80237A34 00234974  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 80237A38 00234978  EC 01 00 32 */	fmuls f0, f1, f0
/* 80237A3C 0023497C  FC 00 00 1E */	fctiwz f0, f0
/* 80237A40 00234980  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 80237A44 00234984  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80237A48 00234988  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 80237A4C 0023498C  7C 03 04 2E */	lfsx f0, r3, r0
.L_80237A50:
/* 80237A50 00234990  C0 C2 C1 40 */	lfs f6, lbl_8051A4A0@sda21(r2)
/* 80237A54 00234994  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 80237A58 00234998  38 03 71 A0 */	addi r0, r3, sincosTable___5JMath@l
/* 80237A5C 0023499C  38 C0 01 80 */	li r6, 0x180
/* 80237A60 002349A0  ED 06 00 24 */	fdivs f8, f6, f0
/* 80237A64 002349A4  C0 A2 C0 E8 */	lfs f5, lbl_8051A448@sda21(r2)
/* 80237A68 002349A8  C8 82 C0 88 */	lfd f4, lbl_8051A3E8@sda21(r2)
/* 80237A6C 002349AC  38 A0 00 00 */	li r5, 0
/* 80237A70 002349B0  C0 62 C0 84 */	lfs f3, lbl_8051A3E4@sda21(r2)
/* 80237A74 002349B4  38 80 00 00 */	li r4, 0
/* 80237A78 002349B8  FC E0 30 50 */	fneg f7, f6
/* 80237A7C 002349BC  C0 42 C1 44 */	lfs f2, lbl_8051A4A4@sda21(r2)
/* 80237A80 002349C0  C0 22 C0 78 */	lfs f1, lbl_8051A3D8@sda21(r2)
/* 80237A84 002349C4  38 E0 00 0C */	li r7, 0xc
/* 80237A88 002349C8  C0 02 C0 EC */	lfs f0, lbl_8051A44C@sda21(r2)
/* 80237A8C 002349CC  3C 60 43 30 */	lis r3, 0x4330
/* 80237A90 002349D0  7C C9 03 A6 */	mtctr r6
.L_80237A94:
/* 80237A94 002349D4  6C A6 80 00 */	xoris r6, r5, 0x8000
/* 80237A98 002349D8  90 61 00 10 */	stw r3, 0x10(r1)
/* 80237A9C 002349DC  90 C1 00 14 */	stw r6, 0x14(r1)
/* 80237AA0 002349E0  C9 21 00 10 */	lfd f9, 0x10(r1)
/* 80237AA4 002349E4  ED 29 20 28 */	fsubs f9, f9, f4
/* 80237AA8 002349E8  ED 25 02 72 */	fmuls f9, f5, f9
/* 80237AAC 002349EC  ED 29 18 24 */	fdivs f9, f9, f3
/* 80237AB0 002349F0  ED 29 00 B2 */	fmuls f9, f9, f2
/* 80237AB4 002349F4  FD 40 48 90 */	fmr f10, f9
/* 80237AB8 002349F8  FC 09 08 40 */	fcmpo cr0, f9, f1
/* 80237ABC 002349FC  40 80 00 08 */	bge .L_80237AC4
/* 80237AC0 00234A00  FD 40 48 50 */	fneg f10, f9
.L_80237AC4:
/* 80237AC4 00234A04  ED 4A 00 32 */	fmuls f10, f10, f0
/* 80237AC8 00234A08  FC 09 08 40 */	fcmpo cr0, f9, f1
/* 80237ACC 00234A0C  FD 40 50 1E */	fctiwz f10, f10
/* 80237AD0 00234A10  D9 41 00 08 */	stfd f10, 8(r1)
/* 80237AD4 00234A14  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 80237AD8 00234A18  54 C6 1C B8 */	rlwinm r6, r6, 3, 0x12, 0x1c
/* 80237ADC 00234A1C  7C C0 32 14 */	add r6, r0, r6
/* 80237AE0 00234A20  C1 46 00 04 */	lfs f10, 4(r6)
/* 80237AE4 00234A24  EF E8 02 B2 */	fmuls f31, f8, f10
/* 80237AE8 00234A28  40 80 00 30 */	bge .L_80237B18
/* 80237AEC 00234A2C  C1 42 C0 F0 */	lfs f10, lbl_8051A450@sda21(r2)
/* 80237AF0 00234A30  3C C0 80 50 */	lis r6, sincosTable___5JMath@ha
/* 80237AF4 00234A34  38 C6 71 A0 */	addi r6, r6, sincosTable___5JMath@l
/* 80237AF8 00234A38  ED 49 02 B2 */	fmuls f10, f9, f10
/* 80237AFC 00234A3C  FD 40 50 1E */	fctiwz f10, f10
/* 80237B00 00234A40  D9 41 00 18 */	stfd f10, 0x18(r1)
/* 80237B04 00234A44  81 01 00 1C */	lwz r8, 0x1c(r1)
/* 80237B08 00234A48  55 08 1C B8 */	rlwinm r8, r8, 3, 0x12, 0x1c
/* 80237B0C 00234A4C  7D 46 44 2E */	lfsx f10, r6, r8
/* 80237B10 00234A50  FD 40 50 50 */	fneg f10, f10
/* 80237B14 00234A54  48 00 00 24 */	b .L_80237B38
.L_80237B18:
/* 80237B18 00234A58  ED 49 00 32 */	fmuls f10, f9, f0
/* 80237B1C 00234A5C  3C C0 80 50 */	lis r6, sincosTable___5JMath@ha
/* 80237B20 00234A60  38 C6 71 A0 */	addi r6, r6, sincosTable___5JMath@l
/* 80237B24 00234A64  FD 40 50 1E */	fctiwz f10, f10
/* 80237B28 00234A68  D9 41 00 20 */	stfd f10, 0x20(r1)
/* 80237B2C 00234A6C  81 01 00 24 */	lwz r8, 0x24(r1)
/* 80237B30 00234A70  55 08 1C B8 */	rlwinm r8, r8, 3, 0x12, 0x1c
/* 80237B34 00234A74  7D 46 44 2E */	lfsx f10, r6, r8
.L_80237B38:
/* 80237B38 00234A78  80 DF 00 FC */	lwz r6, 0xfc(r31)
/* 80237B3C 00234A7C  ED A8 02 B2 */	fmuls f13, f8, f10
/* 80237B40 00234A80  FD 40 48 90 */	fmr f10, f9
/* 80237B44 00234A84  7C C6 22 14 */	add r6, r6, r4
/* 80237B48 00234A88  FC 09 08 40 */	fcmpo cr0, f9, f1
/* 80237B4C 00234A8C  D0 E6 00 00 */	stfs f7, 0(r6)
/* 80237B50 00234A90  D1 A6 00 04 */	stfs f13, 4(r6)
/* 80237B54 00234A94  D3 E6 00 08 */	stfs f31, 8(r6)
/* 80237B58 00234A98  40 80 00 08 */	bge .L_80237B60
/* 80237B5C 00234A9C  FD 40 48 50 */	fneg f10, f9
.L_80237B60:
/* 80237B60 00234AA0  ED 4A 00 32 */	fmuls f10, f10, f0
/* 80237B64 00234AA4  FC 09 08 40 */	fcmpo cr0, f9, f1
/* 80237B68 00234AA8  FD 40 50 1E */	fctiwz f10, f10
/* 80237B6C 00234AAC  D9 41 00 28 */	stfd f10, 0x28(r1)
/* 80237B70 00234AB0  80 C1 00 2C */	lwz r6, 0x2c(r1)
/* 80237B74 00234AB4  54 C6 1C B8 */	rlwinm r6, r6, 3, 0x12, 0x1c
/* 80237B78 00234AB8  7C C0 32 14 */	add r6, r0, r6
/* 80237B7C 00234ABC  C1 66 00 04 */	lfs f11, 4(r6)
/* 80237B80 00234AC0  40 80 00 30 */	bge .L_80237BB0
/* 80237B84 00234AC4  C1 42 C0 F0 */	lfs f10, lbl_8051A450@sda21(r2)
/* 80237B88 00234AC8  3C C0 80 50 */	lis r6, sincosTable___5JMath@ha
/* 80237B8C 00234ACC  38 C6 71 A0 */	addi r6, r6, sincosTable___5JMath@l
/* 80237B90 00234AD0  ED 49 02 B2 */	fmuls f10, f9, f10
/* 80237B94 00234AD4  FD 40 50 1E */	fctiwz f10, f10
/* 80237B98 00234AD8  D9 41 00 30 */	stfd f10, 0x30(r1)
/* 80237B9C 00234ADC  81 01 00 34 */	lwz r8, 0x34(r1)
/* 80237BA0 00234AE0  55 08 1C B8 */	rlwinm r8, r8, 3, 0x12, 0x1c
/* 80237BA4 00234AE4  7D 46 44 2E */	lfsx f10, r6, r8
/* 80237BA8 00234AE8  FD 40 50 50 */	fneg f10, f10
/* 80237BAC 00234AEC  48 00 00 24 */	b .L_80237BD0
.L_80237BB0:
/* 80237BB0 00234AF0  ED 49 00 32 */	fmuls f10, f9, f0
/* 80237BB4 00234AF4  3C C0 80 50 */	lis r6, sincosTable___5JMath@ha
/* 80237BB8 00234AF8  38 C6 71 A0 */	addi r6, r6, sincosTable___5JMath@l
/* 80237BBC 00234AFC  FD 40 50 1E */	fctiwz f10, f10
/* 80237BC0 00234B00  D9 41 00 38 */	stfd f10, 0x38(r1)
/* 80237BC4 00234B04  81 01 00 3C */	lwz r8, 0x3c(r1)
/* 80237BC8 00234B08  55 08 1C B8 */	rlwinm r8, r8, 3, 0x12, 0x1c
/* 80237BCC 00234B0C  7D 46 44 2E */	lfsx f10, r6, r8
.L_80237BD0:
/* 80237BD0 00234B10  80 DF 01 00 */	lwz r6, 0x100(r31)
/* 80237BD4 00234B14  FD 80 48 90 */	fmr f12, f9
/* 80237BD8 00234B18  FC 09 08 40 */	fcmpo cr0, f9, f1
/* 80237BDC 00234B1C  7C C6 22 14 */	add r6, r6, r4
/* 80237BE0 00234B20  D0 26 00 00 */	stfs f1, 0(r6)
/* 80237BE4 00234B24  D1 46 00 04 */	stfs f10, 4(r6)
/* 80237BE8 00234B28  D1 66 00 08 */	stfs f11, 8(r6)
/* 80237BEC 00234B2C  80 DF 00 FC */	lwz r6, 0xfc(r31)
/* 80237BF0 00234B30  7C C6 3A 14 */	add r6, r6, r7
/* 80237BF4 00234B34  D0 C6 00 00 */	stfs f6, 0(r6)
/* 80237BF8 00234B38  D1 A6 00 04 */	stfs f13, 4(r6)
/* 80237BFC 00234B3C  D3 E6 00 08 */	stfs f31, 8(r6)
/* 80237C00 00234B40  40 80 00 08 */	bge .L_80237C08
/* 80237C04 00234B44  FD 80 48 50 */	fneg f12, f9
.L_80237C08:
/* 80237C08 00234B48  ED 4C 00 32 */	fmuls f10, f12, f0
/* 80237C0C 00234B4C  FC 09 08 40 */	fcmpo cr0, f9, f1
/* 80237C10 00234B50  FD 40 50 1E */	fctiwz f10, f10
/* 80237C14 00234B54  D9 41 00 40 */	stfd f10, 0x40(r1)
/* 80237C18 00234B58  80 C1 00 44 */	lwz r6, 0x44(r1)
/* 80237C1C 00234B5C  54 C6 1C B8 */	rlwinm r6, r6, 3, 0x12, 0x1c
/* 80237C20 00234B60  7C C0 32 14 */	add r6, r0, r6
/* 80237C24 00234B64  C1 66 00 04 */	lfs f11, 4(r6)
/* 80237C28 00234B68  40 80 00 30 */	bge .L_80237C58
/* 80237C2C 00234B6C  C1 42 C0 F0 */	lfs f10, lbl_8051A450@sda21(r2)
/* 80237C30 00234B70  3C C0 80 50 */	lis r6, sincosTable___5JMath@ha
/* 80237C34 00234B74  38 C6 71 A0 */	addi r6, r6, sincosTable___5JMath@l
/* 80237C38 00234B78  ED 29 02 B2 */	fmuls f9, f9, f10
/* 80237C3C 00234B7C  FD 20 48 1E */	fctiwz f9, f9
/* 80237C40 00234B80  D9 21 00 48 */	stfd f9, 0x48(r1)
/* 80237C44 00234B84  81 01 00 4C */	lwz r8, 0x4c(r1)
/* 80237C48 00234B88  55 08 1C B8 */	rlwinm r8, r8, 3, 0x12, 0x1c
/* 80237C4C 00234B8C  7D 26 44 2E */	lfsx f9, r6, r8
/* 80237C50 00234B90  FD 20 48 50 */	fneg f9, f9
/* 80237C54 00234B94  48 00 00 24 */	b .L_80237C78
.L_80237C58:
/* 80237C58 00234B98  ED 29 00 32 */	fmuls f9, f9, f0
/* 80237C5C 00234B9C  3C C0 80 50 */	lis r6, sincosTable___5JMath@ha
/* 80237C60 00234BA0  38 C6 71 A0 */	addi r6, r6, sincosTable___5JMath@l
/* 80237C64 00234BA4  FD 20 48 1E */	fctiwz f9, f9
/* 80237C68 00234BA8  D9 21 00 50 */	stfd f9, 0x50(r1)
/* 80237C6C 00234BAC  81 01 00 54 */	lwz r8, 0x54(r1)
/* 80237C70 00234BB0  55 08 1C B8 */	rlwinm r8, r8, 3, 0x12, 0x1c
/* 80237C74 00234BB4  7D 26 44 2E */	lfsx f9, r6, r8
.L_80237C78:
/* 80237C78 00234BB8  80 DF 01 00 */	lwz r6, 0x100(r31)
/* 80237C7C 00234BBC  38 84 00 18 */	addi r4, r4, 0x18
/* 80237C80 00234BC0  38 A5 00 01 */	addi r5, r5, 1
/* 80237C84 00234BC4  7C C6 3A 14 */	add r6, r6, r7
/* 80237C88 00234BC8  38 E7 00 18 */	addi r7, r7, 0x18
/* 80237C8C 00234BCC  D0 26 00 00 */	stfs f1, 0(r6)
/* 80237C90 00234BD0  D1 26 00 04 */	stfs f9, 4(r6)
/* 80237C94 00234BD4  D1 66 00 08 */	stfs f11, 8(r6)
/* 80237C98 00234BD8  42 00 FD FC */	bdnz .L_80237A94
/* 80237C9C 00234BDC  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 80237CA0 00234BE0  80 01 00 74 */	lwz r0, 0x74(r1)
/* 80237CA4 00234BE4  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 80237CA8 00234BE8  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80237CAC 00234BEC  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80237CB0 00234BF0  7C 08 03 A6 */	mtlr r0
/* 80237CB4 00234BF4  38 21 00 70 */	addi r1, r1, 0x70
/* 80237CB8 00234BF8  4E 80 00 20 */	blr 
.endfn initDraw__Q34Game6VsGame7CardMgrFv

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
/* 80238274 002351B4  2C 19 00 0C */	cmpwi r25, 0xc
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
/* 8023838C 002352CC  2C 06 00 00 */	cmpwi r6, 0
/* 80238390 002352D0  41 80 00 10 */	blt .L_802383A0
/* 80238394 002352D4  2C 06 00 0C */	cmpwi r6, 0xc
/* 80238398 002352D8  40 80 00 08 */	bge .L_802383A0
/* 8023839C 002352DC  38 00 00 01 */	li r0, 1
.L_802383A0:
/* 802383A0 002352E0  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 802383A4 002352E4  40 82 00 1C */	bne .L_802383C0
/* 802383A8 002352E8  3C 60 80 48 */	lis r3, lbl_80483C4C@ha
/* 802383AC 002352EC  38 80 07 1A */	li r4, 0x71a
/* 802383B0 002352F0  38 63 3C 4C */	addi r3, r3, lbl_80483C4C@l
/* 802383B4 002352F4  38 A2 C1 5C */	addi r5, r2, lbl_8051A4BC@sda21
/* 802383B8 002352F8  4C C6 31 82 */	crclr 6
/* 802383BC 002352FC  4B DF 22 85 */	bl panic_f__12JUTExceptionFPCciPCce
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
/* 80238B0C 00235A4C  C0 22 C1 40 */	lfs f1, lbl_8051A4A0@sda21(r2)
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
/* 80238B3C 00235A7C  C0 02 C0 D8 */	lfs f0, lbl_8051A438@sda21(r2)
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
