.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_carryInfoMgr_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8047B268, local
	.asciz "carryInfoMgr.cpp"
.endobj lbl_8047B268
.balign 4
.obj lbl_8047B27C, local
	.asciz "Illegal useType %d\n"
.endobj lbl_8047B27C
.balign 4
.obj lbl_8047B290, local
	.asciz "/user/Yamashita/arc/gameTex.szs"
.endobj lbl_8047B290
.balign 4
.obj lbl_8047B2B0, local
	.asciz "item_0_9.bti"
.endobj lbl_8047B2B0

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST
.obj "sColorTableNumerator__26@unnamed@carryInfoMgr_cpp@", local
	.4byte 0x1E1EFFFF
	.4byte 0xFF0000FF
	.4byte 0xEAEA00FF
	.4byte 0x4C0F8AFF
	.4byte 0xFFFFFFFF
	.4byte 0x669999FF
	.4byte 0x66D3D3FF
.endobj "sColorTableNumerator__26@unnamed@carryInfoMgr_cpp@"
.obj "sColorTableDenominator__26@unnamed@carryInfoMgr_cpp@", local
	.4byte 0x1E1EFFFF
	.4byte 0xFF0000FF
	.4byte 0xEAEA00FF
	.4byte 0x4C0F8AFF
	.4byte 0xFFFFFFFF
	.4byte 0x669999FF
	.4byte 0x70D8D8FF
.endobj "sColorTableDenominator__26@unnamed@carryInfoMgr_cpp@"
.obj __vt__12CarryInfoMgr, global
	.4byte 0
	.4byte 0
	.4byte __dt__12CarryInfoMgrFv
	.4byte loadResource__12CarryInfoMgrFv
	.4byte update__12CarryInfoMgrFv
	.4byte draw__12CarryInfoMgrFR8Graphics
	.4byte regist__12CarryInfoMgrFP14CarryInfoOwner
	.4byte scratch__12CarryInfoMgrFP14CarryInfoOwner
.endobj __vt__12CarryInfoMgr
.obj __vt__11InfoMgrBase, weak
	.4byte 0
	.4byte 0
	.4byte __dt__11InfoMgrBaseFv
	.4byte 0
	.4byte 0
	.4byte 0
.endobj __vt__11InfoMgrBase
.obj "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>", weak
	.4byte 0
	.4byte 0
	.4byte "__dt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv"
	.4byte "init__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv"
	.4byte "update__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv"
	.4byte "draw__46InfoListBase<14CarryInfoOwner,13CarryInfoList>FR8Graphics"
	.4byte 0
.endobj "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"
.obj "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>", weak
	.4byte 0
	.4byte 0
	.4byte "__dt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv"
	.4byte 0
	.4byte "update__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv"
	.4byte "draw__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FR8Graphics"
	.4byte "regist__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner"
	.4byte "scratch__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner"
.endobj "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"
.obj __vt__14CarryInfoOwner, weak
	.4byte 0
	.4byte 0
	.4byte 0
.endobj __vt__14CarryInfoOwner
.obj __vt__13PokoInfoOwner, global
	.4byte 0
	.4byte 0
	.4byte getCarryInfoParam__13PokoInfoOwnerFR14CarryInfoParam
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__13PokoInfoOwnerFv"
	.4byte getChildCount__5CNodeFv
	.4byte __dt__13PokoInfoOwnerFv
.endobj __vt__13PokoInfoOwner
.obj __vt__13CarryInfoList, global
	.4byte 0
	.4byte 0
	.4byte __dt__13CarryInfoListFv
	.4byte init__13CarryInfoListFv
	.4byte update__13CarryInfoListFv
	.4byte draw__13CarryInfoListFR8Graphics
	.4byte isFinish__13CarryInfoListFv
.endobj __vt__13CarryInfoList

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj gu32NAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gu32NAN___Q24Game5P2JST
.obj gfNAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gfNAN___Q24Game5P2JST
.obj carryInfoMgr, global
	.skip 0x4
.endobj carryInfoMgr

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_80517B60, local
	.float 0.0
.endobj lbl_80517B60
.obj lbl_80517B64, local
	.float 0.04
.endobj lbl_80517B64
.obj lbl_80517B68, local
	.float 0.88
.endobj lbl_80517B68
.obj lbl_80517B6C, local
	.float 1.0
.endobj lbl_80517B6C
.obj lbl_80517B70, local
	.float 255.0
.endobj lbl_80517B70
.obj lbl_80517B74, local
	.float 0.5
.endobj lbl_80517B74
.obj lbl_80517B78, local
	.float 0.9
.endobj lbl_80517B78
.obj lbl_80517B7C, local
	.float 0.75
.endobj lbl_80517B7C
.obj lbl_80517B80, local
	.float 1.1
.endobj lbl_80517B80
.obj lbl_80517B84, local
	.float 7.7000003
.endobj lbl_80517B84
.obj lbl_80517B88, local
	.float -10.150001
.endobj lbl_80517B88
.obj lbl_80517B8C, local
	.float 10.150001
.endobj lbl_80517B8C
.obj lbl_80517B90, local
	.float -7.7000003
.endobj lbl_80517B90
.obj lbl_80517B94, local # tau
	.float 6.2831855
.endobj lbl_80517B94
.obj lbl_80517B98, local
	.float 0.03125
.endobj lbl_80517B98
.obj lbl_80517B9C, local
	.float -325.9493
.endobj lbl_80517B9C
.obj lbl_80517BA0, local
	.float 325.9493
.endobj lbl_80517BA0
.obj lbl_80517BA4, local
	.float 155.0
.endobj lbl_80517BA4
.obj lbl_80517BA8, local
	.float 59.0
.endobj lbl_80517BA8
.obj lbl_80517BAC, local
	.float 7.0
.endobj lbl_80517BAC
.obj lbl_80517BB0, local
	.float 3.0
.endobj lbl_80517BB0
.balign 8
.obj lbl_80517BB8, local
	.8byte 0x4330000080000000
.endobj lbl_80517BB8
.balign 8
.obj lbl_80517BC0, local
	.8byte 0x4330000000000000
.endobj lbl_80517BC0
.obj lbl_80517BC8, local
	.float 5.6
.endobj lbl_80517BC8
.obj lbl_80517BCC, local
	.float 2.0
.endobj lbl_80517BCC
.obj lbl_80517BD0, local
	.float 12.599999
.endobj lbl_80517BD0
.obj lbl_80517BD4, local
	.float 6.0
.endobj lbl_80517BD4
.obj lbl_80517BD8, local
	.float 0.083333336
.endobj lbl_80517BD8
.obj lbl_80517BDC, local
	.float 25.0
.endobj lbl_80517BDC
.obj lbl_80517BE0, local
	.float 1.5
.endobj lbl_80517BE0
.balign 4
.obj lbl_80517BE4, local
	.asciz ""
.endobj lbl_80517BE4
.balign 4
.obj lbl_80517BE8, local
	.float 50.0
.endobj lbl_80517BE8

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn disappear__9CarryInfoFv, global
/* 8011AFD0 00117F10  38 00 00 01 */	li r0, 1
/* 8011AFD4 00117F14  98 03 00 0C */	stb r0, 0xc(r3)
/* 8011AFD8 00117F18  4E 80 00 20 */	blr 
.endfn disappear__9CarryInfoFv

.fn update__9CarryInfoFRC14CarryInfoParam, global
/* 8011AFDC 00117F1C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011AFE0 00117F20  88 A3 00 0C */	lbz r5, 0xc(r3)
/* 8011AFE4 00117F24  28 05 00 02 */	cmplwi r5, 2
/* 8011AFE8 00117F28  41 82 02 50 */	beq .L_8011B238
/* 8011AFEC 00117F2C  80 04 00 00 */	lwz r0, 0(r4)
/* 8011AFF0 00117F30  2C 00 00 01 */	cmpwi r0, 1
/* 8011AFF4 00117F34  41 82 01 34 */	beq .L_8011B128
/* 8011AFF8 00117F38  40 80 02 40 */	bge .L_8011B238
/* 8011AFFC 00117F3C  2C 00 00 00 */	cmpwi r0, 0
/* 8011B000 00117F40  40 80 00 08 */	bge .L_8011B008
/* 8011B004 00117F44  48 00 02 34 */	b .L_8011B238
.L_8011B008:
/* 8011B008 00117F48  2C 05 00 01 */	cmpwi r5, 1
/* 8011B00C 00117F4C  41 82 00 54 */	beq .L_8011B060
/* 8011B010 00117F50  40 80 00 B0 */	bge .L_8011B0C0
/* 8011B014 00117F54  2C 05 00 00 */	cmpwi r5, 0
/* 8011B018 00117F58  40 80 00 08 */	bge .L_8011B020
/* 8011B01C 00117F5C  48 00 00 A4 */	b .L_8011B0C0
.L_8011B020:
/* 8011B020 00117F60  C0 44 00 10 */	lfs f2, 0x10(r4)
/* 8011B024 00117F64  C0 03 00 04 */	lfs f0, 4(r3)
/* 8011B028 00117F68  C0 22 98 04 */	lfs f1, lbl_80517B64@sda21(r2)
/* 8011B02C 00117F6C  EC 02 00 28 */	fsubs f0, f2, f0
/* 8011B030 00117F70  C0 63 00 00 */	lfs f3, 0(r3)
/* 8011B034 00117F74  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011B038 00117F78  EC 03 00 2A */	fadds f0, f3, f0
/* 8011B03C 00117F7C  D0 03 00 00 */	stfs f0, 0(r3)
/* 8011B040 00117F80  C0 23 00 04 */	lfs f1, 4(r3)
/* 8011B044 00117F84  C0 03 00 00 */	lfs f0, 0(r3)
/* 8011B048 00117F88  EC 01 00 2A */	fadds f0, f1, f0
/* 8011B04C 00117F8C  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011B050 00117F90  C0 03 00 04 */	lfs f0, 4(r3)
/* 8011B054 00117F94  EC 00 10 24 */	fdivs f0, f0, f2
/* 8011B058 00117F98  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011B05C 00117F9C  48 00 00 64 */	b .L_8011B0C0
.L_8011B060:
/* 8011B060 00117FA0  C0 03 00 04 */	lfs f0, 4(r3)
/* 8011B064 00117FA4  C0 42 98 04 */	lfs f2, lbl_80517B64@sda21(r2)
/* 8011B068 00117FA8  FC 20 00 50 */	fneg f1, f0
/* 8011B06C 00117FAC  C0 63 00 00 */	lfs f3, 0(r3)
/* 8011B070 00117FB0  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011B074 00117FB4  EC 22 00 72 */	fmuls f1, f2, f1
/* 8011B078 00117FB8  EC 23 08 2A */	fadds f1, f3, f1
/* 8011B07C 00117FBC  D0 23 00 00 */	stfs f1, 0(r3)
/* 8011B080 00117FC0  C0 43 00 04 */	lfs f2, 4(r3)
/* 8011B084 00117FC4  C0 23 00 00 */	lfs f1, 0(r3)
/* 8011B088 00117FC8  EC 22 08 2A */	fadds f1, f2, f1
/* 8011B08C 00117FCC  D0 23 00 04 */	stfs f1, 4(r3)
/* 8011B090 00117FD0  C0 23 00 04 */	lfs f1, 4(r3)
/* 8011B094 00117FD4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011B098 00117FD8  40 80 00 1C */	bge .L_8011B0B4
/* 8011B09C 00117FDC  D0 03 00 00 */	stfs f0, 0(r3)
/* 8011B0A0 00117FE0  38 00 00 02 */	li r0, 2
/* 8011B0A4 00117FE4  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011B0A8 00117FE8  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011B0AC 00117FEC  98 03 00 0C */	stb r0, 0xc(r3)
/* 8011B0B0 00117FF0  48 00 00 10 */	b .L_8011B0C0
.L_8011B0B4:
/* 8011B0B4 00117FF4  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8011B0B8 00117FF8  EC 01 00 24 */	fdivs f0, f1, f0
/* 8011B0BC 00117FFC  D0 03 00 08 */	stfs f0, 8(r3)
.L_8011B0C0:
/* 8011B0C0 00118000  C0 23 00 00 */	lfs f1, 0(r3)
/* 8011B0C4 00118004  C0 02 98 08 */	lfs f0, lbl_80517B68@sda21(r2)
/* 8011B0C8 00118008  C0 42 98 0C */	lfs f2, lbl_80517B6C@sda21(r2)
/* 8011B0CC 0011800C  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011B0D0 00118010  D0 03 00 00 */	stfs f0, 0(r3)
/* 8011B0D4 00118014  C0 03 00 08 */	lfs f0, 8(r3)
/* 8011B0D8 00118018  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 8011B0DC 0011801C  40 81 00 08 */	ble .L_8011B0E4
/* 8011B0E0 00118020  48 00 00 08 */	b .L_8011B0E8
.L_8011B0E4:
/* 8011B0E4 00118024  FC 40 00 90 */	fmr f2, f0
.L_8011B0E8:
/* 8011B0E8 00118028  C0 22 98 10 */	lfs f1, lbl_80517B70@sda21(r2)
/* 8011B0EC 0011802C  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011B0F0 00118030  EC 21 00 B2 */	fmuls f1, f1, f2
/* 8011B0F4 00118034  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011B0F8 00118038  4C 41 13 82 */	cror 2, 1, 2
/* 8011B0FC 0011803C  40 82 00 10 */	bne .L_8011B10C
/* 8011B100 00118040  C0 02 98 14 */	lfs f0, lbl_80517B74@sda21(r2)
/* 8011B104 00118044  EC 00 08 2A */	fadds f0, f0, f1
/* 8011B108 00118048  48 00 00 0C */	b .L_8011B114
.L_8011B10C:
/* 8011B10C 0011804C  C0 02 98 14 */	lfs f0, lbl_80517B74@sda21(r2)
/* 8011B110 00118050  EC 01 00 28 */	fsubs f0, f1, f0
.L_8011B114:
/* 8011B114 00118054  FC 00 00 1E */	fctiwz f0, f0
/* 8011B118 00118058  D8 01 00 08 */	stfd f0, 8(r1)
/* 8011B11C 0011805C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8011B120 00118060  98 03 00 0D */	stb r0, 0xd(r3)
/* 8011B124 00118064  48 00 01 14 */	b .L_8011B238
.L_8011B128:
/* 8011B128 00118068  88 A3 00 0E */	lbz r5, 0xe(r3)
/* 8011B12C 0011806C  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 8011B130 00118070  38 05 00 01 */	addi r0, r5, 1
/* 8011B134 00118074  98 03 00 0E */	stb r0, 0xe(r3)
/* 8011B138 00118078  C0 03 00 04 */	lfs f0, 4(r3)
/* 8011B13C 0011807C  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8011B140 00118080  40 80 00 1C */	bge .L_8011B15C
/* 8011B144 00118084  EC 01 00 28 */	fsubs f0, f1, f0
/* 8011B148 00118088  C0 22 98 04 */	lfs f1, lbl_80517B64@sda21(r2)
/* 8011B14C 0011808C  C0 43 00 00 */	lfs f2, 0(r3)
/* 8011B150 00118090  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011B154 00118094  EC 02 00 2A */	fadds f0, f2, f0
/* 8011B158 00118098  D0 03 00 00 */	stfs f0, 0(r3)
.L_8011B15C:
/* 8011B15C 0011809C  C0 23 00 04 */	lfs f1, 4(r3)
/* 8011B160 001180A0  C0 03 00 00 */	lfs f0, 0(r3)
/* 8011B164 001180A4  C0 42 98 18 */	lfs f2, lbl_80517B78@sda21(r2)
/* 8011B168 001180A8  EC 61 00 2A */	fadds f3, f1, f0
/* 8011B16C 001180AC  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 8011B170 001180B0  C0 02 98 0C */	lfs f0, lbl_80517B6C@sda21(r2)
/* 8011B174 001180B4  D0 63 00 04 */	stfs f3, 4(r3)
/* 8011B178 001180B8  C0 63 00 00 */	lfs f3, 0(r3)
/* 8011B17C 001180BC  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8011B180 001180C0  D0 43 00 00 */	stfs f2, 0(r3)
/* 8011B184 001180C4  C0 43 00 04 */	lfs f2, 4(r3)
/* 8011B188 001180C8  EC 22 08 24 */	fdivs f1, f2, f1
/* 8011B18C 001180CC  D0 23 00 08 */	stfs f1, 8(r3)
/* 8011B190 001180D0  C0 23 00 08 */	lfs f1, 8(r3)
/* 8011B194 001180D4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011B198 001180D8  40 81 00 08 */	ble .L_8011B1A0
/* 8011B19C 001180DC  D0 03 00 08 */	stfs f0, 8(r3)
.L_8011B1A0:
/* 8011B1A0 001180E0  88 03 00 0C */	lbz r0, 0xc(r3)
/* 8011B1A4 001180E4  2C 00 00 01 */	cmpwi r0, 1
/* 8011B1A8 001180E8  41 82 00 58 */	beq .L_8011B200
/* 8011B1AC 001180EC  40 80 00 8C */	bge .L_8011B238
/* 8011B1B0 001180F0  2C 00 00 00 */	cmpwi r0, 0
/* 8011B1B4 001180F4  40 80 00 08 */	bge .L_8011B1BC
/* 8011B1B8 001180F8  48 00 00 80 */	b .L_8011B238
.L_8011B1BC:
/* 8011B1BC 001180FC  C0 42 98 10 */	lfs f2, lbl_80517B70@sda21(r2)
/* 8011B1C0 00118100  C0 23 00 08 */	lfs f1, 8(r3)
/* 8011B1C4 00118104  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011B1C8 00118108  EC 22 00 72 */	fmuls f1, f2, f1
/* 8011B1CC 0011810C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011B1D0 00118110  4C 41 13 82 */	cror 2, 1, 2
/* 8011B1D4 00118114  40 82 00 10 */	bne .L_8011B1E4
/* 8011B1D8 00118118  C0 02 98 14 */	lfs f0, lbl_80517B74@sda21(r2)
/* 8011B1DC 0011811C  EC 00 08 2A */	fadds f0, f0, f1
/* 8011B1E0 00118120  48 00 00 0C */	b .L_8011B1EC
.L_8011B1E4:
/* 8011B1E4 00118124  C0 02 98 14 */	lfs f0, lbl_80517B74@sda21(r2)
/* 8011B1E8 00118128  EC 01 00 28 */	fsubs f0, f1, f0
.L_8011B1EC:
/* 8011B1EC 0011812C  FC 00 00 1E */	fctiwz f0, f0
/* 8011B1F0 00118130  D8 01 00 08 */	stfd f0, 8(r1)
/* 8011B1F4 00118134  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8011B1F8 00118138  98 03 00 0D */	stb r0, 0xd(r3)
/* 8011B1FC 0011813C  48 00 00 3C */	b .L_8011B238
.L_8011B200:
/* 8011B200 00118140  88 83 00 0D */	lbz r4, 0xd(r3)
/* 8011B204 00118144  28 04 00 08 */	cmplwi r4, 8
/* 8011B208 00118148  40 81 00 10 */	ble .L_8011B218
/* 8011B20C 0011814C  38 04 FF F8 */	addi r0, r4, -8
/* 8011B210 00118150  98 03 00 0D */	stb r0, 0xd(r3)
/* 8011B214 00118154  48 00 00 24 */	b .L_8011B238
.L_8011B218:
/* 8011B218 00118158  38 00 00 00 */	li r0, 0
/* 8011B21C 0011815C  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011B220 00118160  98 03 00 0D */	stb r0, 0xd(r3)
/* 8011B224 00118164  38 00 00 02 */	li r0, 2
/* 8011B228 00118168  D0 03 00 00 */	stfs f0, 0(r3)
/* 8011B22C 0011816C  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011B230 00118170  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011B234 00118174  98 03 00 0C */	stb r0, 0xc(r3)
.L_8011B238:
/* 8011B238 00118178  38 21 00 10 */	addi r1, r1, 0x10
/* 8011B23C 0011817C  4E 80 00 20 */	blr 
.endfn update__9CarryInfoFRC14CarryInfoParam

.fn draw__9CarryInfoFR8GraphicsR14CarryInfoParam, global
/* 8011B240 00118180  94 21 FE B0 */	stwu r1, -0x150(r1)
/* 8011B244 00118184  7C 08 02 A6 */	mflr r0
/* 8011B248 00118188  90 01 01 54 */	stw r0, 0x154(r1)
/* 8011B24C 0011818C  DB E1 01 40 */	stfd f31, 0x140(r1)
/* 8011B250 00118190  F3 E1 01 48 */	psq_st f31, 328(r1), 0, qr0
/* 8011B254 00118194  DB C1 01 30 */	stfd f30, 0x130(r1)
/* 8011B258 00118198  F3 C1 01 38 */	psq_st f30, 312(r1), 0, qr0
/* 8011B25C 0011819C  DB A1 01 20 */	stfd f29, 0x120(r1)
/* 8011B260 001181A0  F3 A1 01 28 */	psq_st f29, 296(r1), 0, qr0
/* 8011B264 001181A4  DB 81 01 10 */	stfd f28, 0x110(r1)
/* 8011B268 001181A8  F3 81 01 18 */	psq_st f28, 280(r1), 0, qr0
/* 8011B26C 001181AC  BF 61 00 FC */	stmw r27, 0xfc(r1)
/* 8011B270 001181B0  7C 7D 1B 78 */	mr r29, r3
/* 8011B274 001181B4  7C 9E 23 78 */	mr r30, r4
/* 8011B278 001181B8  88 03 00 0C */	lbz r0, 0xc(r3)
/* 8011B27C 001181BC  7C BF 2B 78 */	mr r31, r5
/* 8011B280 001181C0  28 00 00 02 */	cmplwi r0, 2
/* 8011B284 001181C4  41 82 04 34 */	beq .L_8011B6B8
/* 8011B288 001181C8  83 7E 02 5C */	lwz r27, 0x25c(r30)
/* 8011B28C 001181CC  38 80 00 01 */	li r4, 1
/* 8011B290 001181D0  7F 63 DB 78 */	mr r3, r27
/* 8011B294 001181D4  48 30 9E C9 */	bl getMatrix__8ViewportFb
/* 8011B298 001181D8  C0 03 00 00 */	lfs f0, 0(r3)
/* 8011B29C 001181DC  38 80 00 01 */	li r4, 1
/* 8011B2A0 001181E0  C0 3D 00 08 */	lfs f1, 8(r29)
/* 8011B2A4 001181E4  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2A8 001181E8  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8011B2AC 001181EC  C0 03 00 04 */	lfs f0, 4(r3)
/* 8011B2B0 001181F0  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2B4 001181F4  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 8011B2B8 001181F8  C0 03 00 08 */	lfs f0, 8(r3)
/* 8011B2BC 001181FC  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2C0 00118200  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 8011B2C4 00118204  C0 03 00 10 */	lfs f0, 0x10(r3)
/* 8011B2C8 00118208  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2CC 0011820C  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8011B2D0 00118210  C0 03 00 14 */	lfs f0, 0x14(r3)
/* 8011B2D4 00118214  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2D8 00118218  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 8011B2DC 0011821C  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 8011B2E0 00118220  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2E4 00118224  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8011B2E8 00118228  C0 03 00 20 */	lfs f0, 0x20(r3)
/* 8011B2EC 0011822C  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2F0 00118230  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8011B2F4 00118234  C0 03 00 24 */	lfs f0, 0x24(r3)
/* 8011B2F8 00118238  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B2FC 0011823C  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 8011B300 00118240  C0 03 00 28 */	lfs f0, 0x28(r3)
/* 8011B304 00118244  7F 63 DB 78 */	mr r3, r27
/* 8011B308 00118248  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B30C 0011824C  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 8011B310 00118250  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8011B314 00118254  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8011B318 00118258  C0 3F 00 08 */	lfs f1, 8(r31)
/* 8011B31C 0011825C  C0 1D 00 04 */	lfs f0, 4(r29)
/* 8011B320 00118260  EC 01 00 2A */	fadds f0, f1, f0
/* 8011B324 00118264  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8011B328 00118268  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8011B32C 0011826C  D0 01 00 44 */	stfs f0, 0x44(r1)
/* 8011B330 00118270  48 30 9E 2D */	bl getMatrix__8ViewportFb
/* 8011B334 00118274  38 81 00 18 */	addi r4, r1, 0x18
/* 8011B338 00118278  38 A1 00 48 */	addi r5, r1, 0x48
/* 8011B33C 0011827C  4B FC EF C5 */	bl PSMTXConcat
/* 8011B340 00118280  38 61 00 48 */	addi r3, r1, 0x48
/* 8011B344 00118284  38 80 00 00 */	li r4, 0
/* 8011B348 00118288  4B FC E2 31 */	bl GXLoadPosMtxImm
/* 8011B34C 0011828C  80 DF 00 00 */	lwz r6, 0(r31)
/* 8011B350 00118290  2C 06 00 01 */	cmpwi r6, 1
/* 8011B354 00118294  41 82 01 04 */	beq .L_8011B458
/* 8011B358 00118298  40 80 03 44 */	bge .L_8011B69C
/* 8011B35C 0011829C  2C 06 00 00 */	cmpwi r6, 0
/* 8011B360 001182A0  40 80 00 08 */	bge .L_8011B368
/* 8011B364 001182A4  48 00 03 38 */	b .L_8011B69C
.L_8011B368:
/* 8011B368 001182A8  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 8011B36C 001182AC  2C 00 00 00 */	cmpwi r0, 0
/* 8011B370 001182B0  40 82 00 18 */	bne .L_8011B388
/* 8011B374 001182B4  C3 A2 98 1C */	lfs f29, lbl_80517B7C@sda21(r2)
/* 8011B378 001182B8  C3 82 98 20 */	lfs f28, lbl_80517B80@sda21(r2)
/* 8011B37C 001182BC  C3 E2 98 24 */	lfs f31, lbl_80517B84@sda21(r2)
/* 8011B380 001182C0  C3 C2 98 28 */	lfs f30, lbl_80517B88@sda21(r2)
/* 8011B384 001182C4  48 00 00 14 */	b .L_8011B398
.L_8011B388:
/* 8011B388 001182C8  C3 A2 98 20 */	lfs f29, lbl_80517B80@sda21(r2)
/* 8011B38C 001182CC  C3 82 98 1C */	lfs f28, lbl_80517B7C@sda21(r2)
/* 8011B390 001182D0  C3 E2 98 2C */	lfs f31, lbl_80517B8C@sda21(r2)
/* 8011B394 001182D4  C3 C2 98 30 */	lfs f30, lbl_80517B90@sda21(r2)
.L_8011B398:
/* 8011B398 001182D8  88 1F 00 15 */	lbz r0, 0x15(r31)
/* 8011B39C 001182DC  3C 80 80 4B */	lis r4, "sColorTableNumerator__26@unnamed@carryInfoMgr_cpp@"@ha
/* 8011B3A0 001182E0  3C 60 80 4B */	lis r3, "sColorTableDenominator__26@unnamed@carryInfoMgr_cpp@"@ha
/* 8011B3A4 001182E4  89 5D 00 0D */	lbz r10, 0xd(r29)
/* 8011B3A8 001182E8  54 05 10 3A */	slwi r5, r0, 2
/* 8011B3AC 001182EC  38 04 C3 2C */	addi r0, r4, "sColorTableNumerator__26@unnamed@carryInfoMgr_cpp@"@l
/* 8011B3B0 001182F0  7C 80 2A 14 */	add r4, r0, r5
/* 8011B3B4 001182F4  38 03 C3 48 */	addi r0, r3, "sColorTableDenominator__26@unnamed@carryInfoMgr_cpp@"@l
/* 8011B3B8 001182F8  7C A0 2A 14 */	add r5, r0, r5
/* 8011B3BC 001182FC  C0 22 98 00 */	lfs f1, lbl_80517B60@sda21(r2)
/* 8011B3C0 00118300  89 24 00 02 */	lbz r9, 2(r4)
/* 8011B3C4 00118304  7F A3 EB 78 */	mr r3, r29
/* 8011B3C8 00118308  89 04 00 01 */	lbz r8, 1(r4)
/* 8011B3CC 0011830C  FC 40 08 90 */	fmr f2, f1
/* 8011B3D0 00118310  88 E4 00 00 */	lbz r7, 0(r4)
/* 8011B3D4 00118314  7F C4 F3 78 */	mr r4, r30
/* 8011B3D8 00118318  89 85 00 02 */	lbz r12, 2(r5)
/* 8011B3DC 0011831C  38 C1 00 14 */	addi r6, r1, 0x14
/* 8011B3E0 00118320  89 65 00 01 */	lbz r11, 1(r5)
/* 8011B3E4 00118324  88 05 00 00 */	lbz r0, 0(r5)
/* 8011B3E8 00118328  38 A0 00 0A */	li r5, 0xa
/* 8011B3EC 0011832C  98 E1 00 14 */	stb r7, 0x14(r1)
/* 8011B3F0 00118330  C0 62 98 0C */	lfs f3, lbl_80517B6C@sda21(r2)
/* 8011B3F4 00118334  99 01 00 15 */	stb r8, 0x15(r1)
/* 8011B3F8 00118338  99 21 00 16 */	stb r9, 0x16(r1)
/* 8011B3FC 0011833C  99 41 00 17 */	stb r10, 0x17(r1)
/* 8011B400 00118340  98 01 00 10 */	stb r0, 0x10(r1)
/* 8011B404 00118344  99 61 00 11 */	stb r11, 0x11(r1)
/* 8011B408 00118348  99 81 00 12 */	stb r12, 0x12(r1)
/* 8011B40C 0011834C  99 41 00 13 */	stb r10, 0x13(r1)
/* 8011B410 00118350  48 00 06 05 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B414 00118354  FC 40 F8 90 */	fmr f2, f31
/* 8011B418 00118358  C0 22 98 00 */	lfs f1, lbl_80517B60@sda21(r2)
/* 8011B41C 0011835C  FC 60 E8 90 */	fmr f3, f29
/* 8011B420 00118360  A0 BF 00 16 */	lhz r5, 0x16(r31)
/* 8011B424 00118364  7F A3 EB 78 */	mr r3, r29
/* 8011B428 00118368  7F C4 F3 78 */	mr r4, r30
/* 8011B42C 0011836C  38 C1 00 14 */	addi r6, r1, 0x14
/* 8011B430 00118370  48 00 02 BD */	bl drawNumber__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B434 00118374  FC 40 F0 90 */	fmr f2, f30
/* 8011B438 00118378  C0 22 98 00 */	lfs f1, lbl_80517B60@sda21(r2)
/* 8011B43C 0011837C  FC 60 E0 90 */	fmr f3, f28
/* 8011B440 00118380  A0 BF 00 18 */	lhz r5, 0x18(r31)
/* 8011B444 00118384  7F A3 EB 78 */	mr r3, r29
/* 8011B448 00118388  7F C4 F3 78 */	mr r4, r30
/* 8011B44C 0011838C  38 C1 00 10 */	addi r6, r1, 0x10
/* 8011B450 00118390  48 00 02 9D */	bl drawNumber__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B454 00118394  48 00 02 64 */	b .L_8011B6B8
.L_8011B458:
/* 8011B458 00118398  88 7D 00 0E */	lbz r3, 0xe(r29)
/* 8011B45C 0011839C  3C 00 43 30 */	lis r0, 0x4330
/* 8011B460 001183A0  90 01 00 78 */	stw r0, 0x78(r1)
/* 8011B464 001183A4  54 60 D8 08 */	slwi r0, r3, 0x1b
/* 8011B468 001183A8  54 63 0F FE */	srwi r3, r3, 0x1f
/* 8011B46C 001183AC  7C 03 00 50 */	subf r0, r3, r0
/* 8011B470 001183B0  C8 A2 98 58 */	lfd f5, lbl_80517BB8@sda21(r2)
/* 8011B474 001183B4  54 00 28 3E */	rotlwi r0, r0, 5
/* 8011B478 001183B8  C0 C2 98 34 */	lfs f6, lbl_80517B94@sda21(r2)
/* 8011B47C 001183BC  7C 00 1A 14 */	add r0, r0, r3
/* 8011B480 001183C0  C0 42 98 38 */	lfs f2, lbl_80517B98@sda21(r2)
/* 8011B484 001183C4  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8011B488 001183C8  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011B48C 001183CC  90 01 00 7C */	stw r0, 0x7c(r1)
/* 8011B490 001183D0  C0 62 98 14 */	lfs f3, lbl_80517B74@sda21(r2)
/* 8011B494 001183D4  C8 81 00 78 */	lfd f4, 0x78(r1)
/* 8011B498 001183D8  C0 22 98 0C */	lfs f1, lbl_80517B6C@sda21(r2)
/* 8011B49C 001183DC  EC 84 28 28 */	fsubs f4, f4, f5
/* 8011B4A0 001183E0  EC 86 01 32 */	fmuls f4, f6, f4
/* 8011B4A4 001183E4  EC 44 00 B2 */	fmuls f2, f4, f2
/* 8011B4A8 001183E8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8011B4AC 001183EC  40 80 00 30 */	bge .L_8011B4DC
/* 8011B4B0 001183F0  C0 02 98 3C */	lfs f0, lbl_80517B9C@sda21(r2)
/* 8011B4B4 001183F4  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 8011B4B8 001183F8  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 8011B4BC 001183FC  EC 02 00 32 */	fmuls f0, f2, f0
/* 8011B4C0 00118400  FC 00 00 1E */	fctiwz f0, f0
/* 8011B4C4 00118404  D8 01 00 80 */	stfd f0, 0x80(r1)
/* 8011B4C8 00118408  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8011B4CC 0011840C  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8011B4D0 00118410  7C 03 04 2E */	lfsx f0, r3, r0
/* 8011B4D4 00118414  FC 00 00 50 */	fneg f0, f0
/* 8011B4D8 00118418  48 00 00 28 */	b .L_8011B500
.L_8011B4DC:
/* 8011B4DC 0011841C  C0 02 98 40 */	lfs f0, lbl_80517BA0@sda21(r2)
/* 8011B4E0 00118420  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 8011B4E4 00118424  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 8011B4E8 00118428  EC 02 00 32 */	fmuls f0, f2, f0
/* 8011B4EC 0011842C  FC 00 00 1E */	fctiwz f0, f0
/* 8011B4F0 00118430  D8 01 00 88 */	stfd f0, 0x88(r1)
/* 8011B4F4 00118434  80 01 00 8C */	lwz r0, 0x8c(r1)
/* 8011B4F8 00118438  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8011B4FC 0011843C  7C 03 04 2E */	lfsx f0, r3, r0
.L_8011B500:
/* 8011B500 00118440  8B 7D 00 0D */	lbz r27, 0xd(r29)
/* 8011B504 00118444  3C A0 43 30 */	lis r5, 0x4330
/* 8011B508 00118448  38 E0 00 7F */	li r7, 0x7f
/* 8011B50C 0011844C  39 40 00 0B */	li r10, 0xb
/* 8011B510 00118450  39 20 00 00 */	li r9, 0
/* 8011B514 00118454  57 60 06 3E */	clrlwi r0, r27, 0x18
/* 8011B518 00118458  90 E1 00 94 */	stw r7, 0x94(r1)
/* 8011B51C 0011845C  EC 41 00 2A */	fadds f2, f1, f0
/* 8011B520 00118460  3B 80 00 FF */	li r28, 0xff
/* 8011B524 00118464  39 80 00 8A */	li r12, 0x8a
/* 8011B528 00118468  90 A1 00 90 */	stw r5, 0x90(r1)
/* 8011B52C 0011846C  39 60 00 15 */	li r11, 0x15
/* 8011B530 00118470  C8 02 98 60 */	lfd f0, lbl_80517BC0@sda21(r2)
/* 8011B534 00118474  C8 21 00 90 */	lfd f1, 0x90(r1)
/* 8011B538 00118478  EC 83 00 B2 */	fmuls f4, f3, f2
/* 8011B53C 0011847C  91 41 00 AC */	stw r10, 0xac(r1)
/* 8011B540 00118480  7F A3 EB 78 */	mr r3, r29
/* 8011B544 00118484  EC 41 00 28 */	fsubs f2, f1, f0
/* 8011B548 00118488  C0 62 98 10 */	lfs f3, lbl_80517B70@sda21(r2)
/* 8011B54C 0011848C  90 A1 00 A8 */	stw r5, 0xa8(r1)
/* 8011B550 00118490  C0 A2 98 44 */	lfs f5, lbl_80517BA4@sda21(r2)
/* 8011B554 00118494  7F C4 F3 78 */	mr r4, r30
/* 8011B558 00118498  C8 21 00 A8 */	lfd f1, 0xa8(r1)
/* 8011B55C 0011849C  91 21 00 C4 */	stw r9, 0xc4(r1)
/* 8011B560 001184A0  ED 43 10 28 */	fsubs f10, f3, f2
/* 8011B564 001184A4  EC 61 00 28 */	fsubs f3, f1, f0
/* 8011B568 001184A8  C0 E2 98 48 */	lfs f7, lbl_80517BA8@sda21(r2)
/* 8011B56C 001184AC  90 A1 00 C0 */	stw r5, 0xc0(r1)
/* 8011B570 001184B0  38 C1 00 0C */	addi r6, r1, 0xc
/* 8011B574 001184B4  C0 22 98 4C */	lfs f1, lbl_80517BAC@sda21(r2)
/* 8011B578 001184B8  C8 41 00 C0 */	lfd f2, 0xc0(r1)
/* 8011B57C 001184BC  93 61 00 DC */	stw r27, 0xdc(r1)
/* 8011B580 001184C0  ED 25 18 28 */	fsubs f9, f5, f3
/* 8011B584 001184C4  EC C2 00 28 */	fsubs f6, f2, f0
/* 8011B588 001184C8  C0 42 98 00 */	lfs f2, lbl_80517B60@sda21(r2)
/* 8011B58C 001184CC  90 A1 00 D8 */	stw r5, 0xd8(r1)
/* 8011B590 001184D0  C0 62 98 0C */	lfs f3, lbl_80517B6C@sda21(r2)
/* 8011B594 001184D4  C8 A1 00 D8 */	lfd f5, 0xd8(r1)
/* 8011B598 001184D8  EC E7 30 28 */	fsubs f7, f7, f6
/* 8011B59C 001184DC  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 8011B5A0 001184E0  EC C5 00 28 */	fsubs f6, f5, f0
/* 8011B5A4 001184E4  90 A1 00 E0 */	stw r5, 0xe0(r1)
/* 8011B5A8 001184E8  C8 A1 00 E0 */	lfd f5, 0xe0(r1)
/* 8011B5AC 001184EC  90 E1 00 9C */	stw r7, 0x9c(r1)
/* 8011B5B0 001184F0  EC A5 00 28 */	fsubs f5, f5, f0
/* 8011B5B4 001184F4  90 A1 00 98 */	stw r5, 0x98(r1)
/* 8011B5B8 001184F8  C9 01 00 98 */	lfd f8, 0x98(r1)
/* 8011B5BC 001184FC  EC C6 28 28 */	fsubs f6, f6, f5
/* 8011B5C0 00118500  91 41 00 B4 */	stw r10, 0xb4(r1)
/* 8011B5C4 00118504  ED 08 00 28 */	fsubs f8, f8, f0
/* 8011B5C8 00118508  90 A1 00 B0 */	stw r5, 0xb0(r1)
/* 8011B5CC 0011850C  C8 A1 00 B0 */	lfd f5, 0xb0(r1)
/* 8011B5D0 00118510  ED 44 42 BA */	fmadds f10, f4, f10, f8
/* 8011B5D4 00118514  91 21 00 CC */	stw r9, 0xcc(r1)
/* 8011B5D8 00118518  ED 05 00 28 */	fsubs f8, f5, f0
/* 8011B5DC 0011851C  90 A1 00 C8 */	stw r5, 0xc8(r1)
/* 8011B5E0 00118520  FD 40 50 1E */	fctiwz f10, f10
/* 8011B5E4 00118524  C8 A1 00 C8 */	lfd f5, 0xc8(r1)
/* 8011B5E8 00118528  ED 04 42 7A */	fmadds f8, f4, f9, f8
/* 8011B5EC 0011852C  D9 41 00 A0 */	stfd f10, 0xa0(r1)
/* 8011B5F0 00118530  EC A5 00 28 */	fsubs f5, f5, f0
/* 8011B5F4 00118534  FD 00 40 1E */	fctiwz f8, f8
/* 8011B5F8 00118538  90 01 00 EC */	stw r0, 0xec(r1)
/* 8011B5FC 0011853C  81 01 00 A4 */	lwz r8, 0xa4(r1)
/* 8011B600 00118540  90 A1 00 E8 */	stw r5, 0xe8(r1)
/* 8011B604 00118544  EC E4 29 FA */	fmadds f7, f4, f7, f5
/* 8011B608 00118548  C8 A1 00 E8 */	lfd f5, 0xe8(r1)
/* 8011B60C 0011854C  FC E0 38 1E */	fctiwz f7, f7
/* 8011B610 00118550  D9 01 00 B8 */	stfd f8, 0xb8(r1)
/* 8011B614 00118554  EC 05 00 28 */	fsubs f0, f5, f0
/* 8011B618 00118558  98 E1 00 08 */	stb r7, 8(r1)
/* 8011B61C 0011855C  80 E1 00 BC */	lwz r7, 0xbc(r1)
/* 8011B620 00118560  EC 04 01 BA */	fmadds f0, f4, f6, f0
/* 8011B624 00118564  D8 E1 00 D0 */	stfd f7, 0xd0(r1)
/* 8011B628 00118568  99 41 00 09 */	stb r10, 9(r1)
/* 8011B62C 0011856C  FC 00 00 1E */	fctiwz f0, f0
/* 8011B630 00118570  80 A1 00 D4 */	lwz r5, 0xd4(r1)
/* 8011B634 00118574  99 21 00 0A */	stb r9, 0xa(r1)
/* 8011B638 00118578  D8 01 00 F0 */	stfd f0, 0xf0(r1)
/* 8011B63C 0011857C  9B 61 00 0B */	stb r27, 0xb(r1)
/* 8011B640 00118580  80 01 00 F4 */	lwz r0, 0xf4(r1)
/* 8011B644 00118584  9B 81 00 0C */	stb r28, 0xc(r1)
/* 8011B648 00118588  99 81 00 0D */	stb r12, 0xd(r1)
/* 8011B64C 0011858C  99 61 00 0E */	stb r11, 0xe(r1)
/* 8011B650 00118590  9B 61 00 0F */	stb r27, 0xf(r1)
/* 8011B654 00118594  99 01 00 08 */	stb r8, 8(r1)
/* 8011B658 00118598  98 E1 00 09 */	stb r7, 9(r1)
/* 8011B65C 0011859C  98 A1 00 0A */	stb r5, 0xa(r1)
/* 8011B660 001185A0  98 01 00 0B */	stb r0, 0xb(r1)
/* 8011B664 001185A4  80 BF 00 20 */	lwz r5, 0x20(r31)
/* 8011B668 001185A8  48 00 00 85 */	bl drawNumber__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B66C 001185AC  FC 20 08 50 */	fneg f1, f1
/* 8011B670 001185B0  C0 62 98 14 */	lfs f3, lbl_80517B74@sda21(r2)
/* 8011B674 001185B4  C0 02 98 50 */	lfs f0, lbl_80517BB0@sda21(r2)
/* 8011B678 001185B8  7F A3 EB 78 */	mr r3, r29
/* 8011B67C 001185BC  C0 42 98 00 */	lfs f2, lbl_80517B60@sda21(r2)
/* 8011B680 001185C0  7F C4 F3 78 */	mr r4, r30
/* 8011B684 001185C4  EC 23 00 78 */	fmsubs f1, f3, f1, f0
/* 8011B688 001185C8  C0 62 98 0C */	lfs f3, lbl_80517B6C@sda21(r2)
/* 8011B68C 001185CC  38 C1 00 08 */	addi r6, r1, 8
/* 8011B690 001185D0  38 A0 00 0B */	li r5, 0xb
/* 8011B694 001185D4  48 00 03 81 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B698 001185D8  48 00 00 20 */	b .L_8011B6B8
.L_8011B69C:
/* 8011B69C 001185DC  3C 60 80 48 */	lis r3, lbl_8047B268@ha
/* 8011B6A0 001185E0  3C 80 80 48 */	lis r4, lbl_8047B27C@ha
/* 8011B6A4 001185E4  38 A4 B2 7C */	addi r5, r4, lbl_8047B27C@l
/* 8011B6A8 001185E8  38 63 B2 68 */	addi r3, r3, lbl_8047B268@l
/* 8011B6AC 001185EC  38 80 01 93 */	li r4, 0x193
/* 8011B6B0 001185F0  4C C6 31 82 */	crclr 6
/* 8011B6B4 001185F4  4B F0 EF 8D */	bl panic_f__12JUTExceptionFPCciPCce
.L_8011B6B8:
/* 8011B6B8 001185F8  E3 E1 01 48 */	psq_l f31, 328(r1), 0, qr0
/* 8011B6BC 001185FC  CB E1 01 40 */	lfd f31, 0x140(r1)
/* 8011B6C0 00118600  E3 C1 01 38 */	psq_l f30, 312(r1), 0, qr0
/* 8011B6C4 00118604  CB C1 01 30 */	lfd f30, 0x130(r1)
/* 8011B6C8 00118608  E3 A1 01 28 */	psq_l f29, 296(r1), 0, qr0
/* 8011B6CC 0011860C  CB A1 01 20 */	lfd f29, 0x120(r1)
/* 8011B6D0 00118610  E3 81 01 18 */	psq_l f28, 280(r1), 0, qr0
/* 8011B6D4 00118614  CB 81 01 10 */	lfd f28, 0x110(r1)
/* 8011B6D8 00118618  BB 61 00 FC */	lmw r27, 0xfc(r1)
/* 8011B6DC 0011861C  80 01 01 54 */	lwz r0, 0x154(r1)
/* 8011B6E0 00118620  7C 08 03 A6 */	mtlr r0
/* 8011B6E4 00118624  38 21 01 50 */	addi r1, r1, 0x150
/* 8011B6E8 00118628  4E 80 00 20 */	blr 
.endfn draw__9CarryInfoFR8GraphicsR14CarryInfoParam

.fn drawNumber__9CarryInfoFR8GraphicsffiR6Color4f, global
/* 8011B6EC 0011862C  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 8011B6F0 00118630  7C 08 02 A6 */	mflr r0
/* 8011B6F4 00118634  90 01 00 74 */	stw r0, 0x74(r1)
/* 8011B6F8 00118638  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 8011B6FC 0011863C  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 8011B700 00118640  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 8011B704 00118644  F3 C1 00 58 */	psq_st f30, 88(r1), 0, qr0
/* 8011B708 00118648  DB A1 00 40 */	stfd f29, 0x40(r1)
/* 8011B70C 0011864C  F3 A1 00 48 */	psq_st f29, 72(r1), 0, qr0
/* 8011B710 00118650  DB 81 00 30 */	stfd f28, 0x30(r1)
/* 8011B714 00118654  F3 81 00 38 */	psq_st f28, 56(r1), 0, qr0
/* 8011B718 00118658  DB 61 00 20 */	stfd f27, 0x20(r1)
/* 8011B71C 0011865C  F3 61 00 28 */	psq_st f27, 40(r1), 0, qr0
/* 8011B720 00118660  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011B724 00118664  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011B728 00118668  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011B72C 0011866C  93 81 00 10 */	stw r28, 0x10(r1)
/* 8011B730 00118670  7C BE 2B 78 */	mr r30, r5
/* 8011B734 00118674  FF 60 08 90 */	fmr f27, f1
/* 8011B738 00118678  FF 80 10 90 */	fmr f28, f2
/* 8011B73C 0011867C  2C 1E 00 0A */	cmpwi r30, 0xa
/* 8011B740 00118680  FF A0 18 90 */	fmr f29, f3
/* 8011B744 00118684  7C 7C 1B 78 */	mr r28, r3
/* 8011B748 00118688  7C 9D 23 78 */	mr r29, r4
/* 8011B74C 0011868C  7C DF 33 78 */	mr r31, r6
/* 8011B750 00118690  40 80 00 14 */	bge .L_8011B764
/* 8011B754 00118694  48 00 02 C1 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B758 00118698  C0 02 98 4C */	lfs f0, lbl_80517BAC@sda21(r2)
/* 8011B75C 0011869C  EC 20 07 72 */	fmuls f1, f0, f29
/* 8011B760 001186A0  48 00 02 6C */	b .L_8011B9CC
.L_8011B764:
/* 8011B764 001186A4  2C 1E 00 64 */	cmpwi r30, 0x64
/* 8011B768 001186A8  40 80 00 7C */	bge .L_8011B7E4
/* 8011B76C 001186AC  3C A0 66 66 */	lis r5, 0x66666667@ha
/* 8011B770 001186B0  C0 02 98 68 */	lfs f0, lbl_80517BC8@sda21(r2)
/* 8011B774 001186B4  38 05 66 67 */	addi r0, r5, 0x66666667@l
/* 8011B778 001186B8  7C 00 F0 96 */	mulhw r0, r0, r30
/* 8011B77C 001186BC  EF E0 07 72 */	fmuls f31, f0, f29
/* 8011B780 001186C0  EC 3B F8 28 */	fsubs f1, f27, f31
/* 8011B784 001186C4  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B788 001186C8  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B78C 001186CC  7C A0 2A 14 */	add r5, r0, r5
/* 8011B790 001186D0  48 00 02 85 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B794 001186D4  3C 60 66 66 */	lis r3, 0x66666667@ha
/* 8011B798 001186D8  FC 40 E0 90 */	fmr f2, f28
/* 8011B79C 001186DC  38 03 66 67 */	addi r0, r3, 0x66666667@l
/* 8011B7A0 001186E0  FC 60 E8 90 */	fmr f3, f29
/* 8011B7A4 001186E4  7C 00 F0 96 */	mulhw r0, r0, r30
/* 8011B7A8 001186E8  EC 3B F8 2A */	fadds f1, f27, f31
/* 8011B7AC 001186EC  7F 83 E3 78 */	mr r3, r28
/* 8011B7B0 001186F0  7F A4 EB 78 */	mr r4, r29
/* 8011B7B4 001186F4  7F E6 FB 78 */	mr r6, r31
/* 8011B7B8 001186F8  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B7BC 001186FC  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B7C0 00118700  7C 00 2A 14 */	add r0, r0, r5
/* 8011B7C4 00118704  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8011B7C8 00118708  7C A0 F0 50 */	subf r5, r0, r30
/* 8011B7CC 0011870C  48 00 02 49 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B7D0 00118710  C0 02 98 4C */	lfs f0, lbl_80517BAC@sda21(r2)
/* 8011B7D4 00118714  C0 22 98 6C */	lfs f1, lbl_80517BCC@sda21(r2)
/* 8011B7D8 00118718  EC 00 07 72 */	fmuls f0, f0, f29
/* 8011B7DC 0011871C  EC 21 07 FA */	fmadds f1, f1, f31, f0
/* 8011B7E0 00118720  48 00 01 EC */	b .L_8011B9CC
.L_8011B7E4:
/* 8011B7E4 00118724  2C 1E 03 E8 */	cmpwi r30, 0x3e8
/* 8011B7E8 00118728  40 80 00 C8 */	bge .L_8011B8B0
/* 8011B7EC 0011872C  3C A0 51 EC */	lis r5, 0x51EB851F@ha
/* 8011B7F0 00118730  C0 02 98 70 */	lfs f0, lbl_80517BD0@sda21(r2)
/* 8011B7F4 00118734  38 05 85 1F */	addi r0, r5, 0x51EB851F@l
/* 8011B7F8 00118738  7C 00 F0 96 */	mulhw r0, r0, r30
/* 8011B7FC 0011873C  EF E0 07 72 */	fmuls f31, f0, f29
/* 8011B800 00118740  EC 3B F8 28 */	fsubs f1, f27, f31
/* 8011B804 00118744  7C 00 2E 70 */	srawi r0, r0, 5
/* 8011B808 00118748  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B80C 0011874C  7C A0 2A 14 */	add r5, r0, r5
/* 8011B810 00118750  48 00 02 05 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B814 00118754  3C 60 66 66 */	lis r3, 0x66666667@ha
/* 8011B818 00118758  FC 20 D8 90 */	fmr f1, f27
/* 8011B81C 0011875C  39 03 66 67 */	addi r8, r3, 0x66666667@l
/* 8011B820 00118760  FC 40 E0 90 */	fmr f2, f28
/* 8011B824 00118764  7C 08 F0 96 */	mulhw r0, r8, r30
/* 8011B828 00118768  FC 60 E8 90 */	fmr f3, f29
/* 8011B82C 0011876C  7F 83 E3 78 */	mr r3, r28
/* 8011B830 00118770  7F A4 EB 78 */	mr r4, r29
/* 8011B834 00118774  7F E6 FB 78 */	mr r6, r31
/* 8011B838 00118778  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B83C 0011877C  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B840 00118780  7C E0 2A 14 */	add r7, r0, r5
/* 8011B844 00118784  7C 08 38 96 */	mulhw r0, r8, r7
/* 8011B848 00118788  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B84C 0011878C  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B850 00118790  7C 00 2A 14 */	add r0, r0, r5
/* 8011B854 00118794  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8011B858 00118798  7C A0 38 50 */	subf r5, r0, r7
/* 8011B85C 0011879C  48 00 01 B9 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B860 001187A0  3C 60 66 66 */	lis r3, 0x66666667@ha
/* 8011B864 001187A4  FC 40 E0 90 */	fmr f2, f28
/* 8011B868 001187A8  38 03 66 67 */	addi r0, r3, 0x66666667@l
/* 8011B86C 001187AC  FC 60 E8 90 */	fmr f3, f29
/* 8011B870 001187B0  7C 00 F0 96 */	mulhw r0, r0, r30
/* 8011B874 001187B4  EC 3B F8 2A */	fadds f1, f27, f31
/* 8011B878 001187B8  7F 83 E3 78 */	mr r3, r28
/* 8011B87C 001187BC  7F A4 EB 78 */	mr r4, r29
/* 8011B880 001187C0  7F E6 FB 78 */	mr r6, r31
/* 8011B884 001187C4  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B888 001187C8  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B88C 001187CC  7C 00 2A 14 */	add r0, r0, r5
/* 8011B890 001187D0  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8011B894 001187D4  7C A0 F0 50 */	subf r5, r0, r30
/* 8011B898 001187D8  48 00 01 7D */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B89C 001187DC  C0 02 98 4C */	lfs f0, lbl_80517BAC@sda21(r2)
/* 8011B8A0 001187E0  C0 22 98 6C */	lfs f1, lbl_80517BCC@sda21(r2)
/* 8011B8A4 001187E4  EC 00 07 72 */	fmuls f0, f0, f29
/* 8011B8A8 001187E8  EC 21 07 FA */	fmadds f1, f1, f31, f0
/* 8011B8AC 001187EC  48 00 01 20 */	b .L_8011B9CC
.L_8011B8B0:
/* 8011B8B0 001187F0  C0 22 98 68 */	lfs f1, lbl_80517BC8@sda21(r2)
/* 8011B8B4 001187F4  3C A0 10 62 */	lis r5, 0x10624DD3@ha
/* 8011B8B8 001187F8  38 05 4D D3 */	addi r0, r5, 0x10624DD3@l
/* 8011B8BC 001187FC  C0 02 98 50 */	lfs f0, lbl_80517BB0@sda21(r2)
/* 8011B8C0 00118800  EF C1 07 72 */	fmuls f30, f1, f29
/* 8011B8C4 00118804  7C 00 F0 96 */	mulhw r0, r0, r30
/* 8011B8C8 00118808  EF E0 07 B2 */	fmuls f31, f0, f30
/* 8011B8CC 0011880C  7C 00 36 70 */	srawi r0, r0, 6
/* 8011B8D0 00118810  EC 3B F8 28 */	fsubs f1, f27, f31
/* 8011B8D4 00118814  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B8D8 00118818  7C A0 2A 14 */	add r5, r0, r5
/* 8011B8DC 0011881C  48 00 01 39 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B8E0 00118820  3C 80 51 EC */	lis r4, 0x51EB851F@ha
/* 8011B8E4 00118824  3C 60 66 66 */	lis r3, 0x66666667@ha
/* 8011B8E8 00118828  38 04 85 1F */	addi r0, r4, 0x51EB851F@l
/* 8011B8EC 0011882C  FC 40 E0 90 */	fmr f2, f28
/* 8011B8F0 00118830  7C A0 F0 96 */	mulhw r5, r0, r30
/* 8011B8F4 00118834  38 03 66 67 */	addi r0, r3, 0x66666667@l
/* 8011B8F8 00118838  FC 60 E8 90 */	fmr f3, f29
/* 8011B8FC 0011883C  7F 83 E3 78 */	mr r3, r28
/* 8011B900 00118840  EC 3B F0 28 */	fsubs f1, f27, f30
/* 8011B904 00118844  7F A4 EB 78 */	mr r4, r29
/* 8011B908 00118848  7C A5 2E 70 */	srawi r5, r5, 5
/* 8011B90C 0011884C  7F E6 FB 78 */	mr r6, r31
/* 8011B910 00118850  54 A7 0F FE */	srwi r7, r5, 0x1f
/* 8011B914 00118854  7C E5 3A 14 */	add r7, r5, r7
/* 8011B918 00118858  7C 00 38 96 */	mulhw r0, r0, r7
/* 8011B91C 0011885C  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B920 00118860  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B924 00118864  7C 00 2A 14 */	add r0, r0, r5
/* 8011B928 00118868  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8011B92C 0011886C  7C A0 38 50 */	subf r5, r0, r7
/* 8011B930 00118870  48 00 00 E5 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B934 00118874  3C 60 66 66 */	lis r3, 0x66666667@ha
/* 8011B938 00118878  FC 40 E0 90 */	fmr f2, f28
/* 8011B93C 0011887C  39 03 66 67 */	addi r8, r3, 0x66666667@l
/* 8011B940 00118880  FC 60 E8 90 */	fmr f3, f29
/* 8011B944 00118884  7C 08 F0 96 */	mulhw r0, r8, r30
/* 8011B948 00118888  EC 3B F0 2A */	fadds f1, f27, f30
/* 8011B94C 0011888C  7F 83 E3 78 */	mr r3, r28
/* 8011B950 00118890  7F A4 EB 78 */	mr r4, r29
/* 8011B954 00118894  7F E6 FB 78 */	mr r6, r31
/* 8011B958 00118898  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B95C 0011889C  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B960 001188A0  7C E0 2A 14 */	add r7, r0, r5
/* 8011B964 001188A4  7C 08 38 96 */	mulhw r0, r8, r7
/* 8011B968 001188A8  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B96C 001188AC  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B970 001188B0  7C 00 2A 14 */	add r0, r0, r5
/* 8011B974 001188B4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8011B978 001188B8  7C A0 38 50 */	subf r5, r0, r7
/* 8011B97C 001188BC  48 00 00 99 */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B980 001188C0  3C 60 66 66 */	lis r3, 0x66666667@ha
/* 8011B984 001188C4  FC 40 E0 90 */	fmr f2, f28
/* 8011B988 001188C8  38 03 66 67 */	addi r0, r3, 0x66666667@l
/* 8011B98C 001188CC  FC 60 E8 90 */	fmr f3, f29
/* 8011B990 001188D0  7C 00 F0 96 */	mulhw r0, r0, r30
/* 8011B994 001188D4  EC 3B F8 2A */	fadds f1, f27, f31
/* 8011B998 001188D8  7F 83 E3 78 */	mr r3, r28
/* 8011B99C 001188DC  7F A4 EB 78 */	mr r4, r29
/* 8011B9A0 001188E0  7F E6 FB 78 */	mr r6, r31
/* 8011B9A4 001188E4  7C 00 16 70 */	srawi r0, r0, 2
/* 8011B9A8 001188E8  54 05 0F FE */	srwi r5, r0, 0x1f
/* 8011B9AC 001188EC  7C 00 2A 14 */	add r0, r0, r5
/* 8011B9B0 001188F0  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8011B9B4 001188F4  7C A0 F0 50 */	subf r5, r0, r30
/* 8011B9B8 001188F8  48 00 00 5D */	bl drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f
/* 8011B9BC 001188FC  C0 02 98 4C */	lfs f0, lbl_80517BAC@sda21(r2)
/* 8011B9C0 00118900  C0 22 98 74 */	lfs f1, lbl_80517BD4@sda21(r2)
/* 8011B9C4 00118904  EC 00 07 72 */	fmuls f0, f0, f29
/* 8011B9C8 00118908  EC 21 07 BA */	fmadds f1, f1, f30, f0
.L_8011B9CC:
/* 8011B9CC 0011890C  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 8011B9D0 00118910  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 8011B9D4 00118914  E3 C1 00 58 */	psq_l f30, 88(r1), 0, qr0
/* 8011B9D8 00118918  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 8011B9DC 0011891C  E3 A1 00 48 */	psq_l f29, 72(r1), 0, qr0
/* 8011B9E0 00118920  CB A1 00 40 */	lfd f29, 0x40(r1)
/* 8011B9E4 00118924  E3 81 00 38 */	psq_l f28, 56(r1), 0, qr0
/* 8011B9E8 00118928  CB 81 00 30 */	lfd f28, 0x30(r1)
/* 8011B9EC 0011892C  E3 61 00 28 */	psq_l f27, 40(r1), 0, qr0
/* 8011B9F0 00118930  CB 61 00 20 */	lfd f27, 0x20(r1)
/* 8011B9F4 00118934  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011B9F8 00118938  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011B9FC 0011893C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011BA00 00118940  80 01 00 74 */	lwz r0, 0x74(r1)
/* 8011BA04 00118944  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8011BA08 00118948  7C 08 03 A6 */	mtlr r0
/* 8011BA0C 0011894C  38 21 00 70 */	addi r1, r1, 0x70
/* 8011BA10 00118950  4E 80 00 20 */	blr 
.endfn drawNumber__9CarryInfoFR8GraphicsffiR6Color4f

.fn drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f, global
/* 8011BA14 00118954  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 8011BA18 00118958  7C 08 02 A6 */	mflr r0
/* 8011BA1C 0011895C  90 01 00 84 */	stw r0, 0x84(r1)
/* 8011BA20 00118960  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 8011BA24 00118964  F3 E1 00 78 */	psq_st f31, 120(r1), 0, qr0
/* 8011BA28 00118968  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 8011BA2C 0011896C  F3 C1 00 68 */	psq_st f30, 104(r1), 0, qr0
/* 8011BA30 00118970  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 8011BA34 00118974  F3 A1 00 58 */	psq_st f29, 88(r1), 0, qr0
/* 8011BA38 00118978  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 8011BA3C 0011897C  F3 81 00 48 */	psq_st f28, 72(r1), 0, qr0
/* 8011BA40 00118980  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 8011BA44 00118984  F3 61 00 38 */	psq_st f27, 56(r1), 0, qr0
/* 8011BA48 00118988  DB 41 00 20 */	stfd f26, 0x20(r1)
/* 8011BA4C 0011898C  F3 41 00 28 */	psq_st f26, 40(r1), 0, qr0
/* 8011BA50 00118990  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011BA54 00118994  6C A3 80 00 */	xoris r3, r5, 0x8000
/* 8011BA58 00118998  3C 00 43 30 */	lis r0, 0x4330
/* 8011BA5C 0011899C  90 61 00 0C */	stw r3, 0xc(r1)
/* 8011BA60 001189A0  7C DF 33 78 */	mr r31, r6
/* 8011BA64 001189A4  C0 02 98 4C */	lfs f0, lbl_80517BAC@sda21(r2)
/* 8011BA68 001189A8  38 60 00 98 */	li r3, 0x98
/* 8011BA6C 001189AC  90 01 00 08 */	stw r0, 8(r1)
/* 8011BA70 001189B0  38 80 00 00 */	li r4, 0
/* 8011BA74 001189B4  C8 82 98 58 */	lfd f4, lbl_80517BB8@sda21(r2)
/* 8011BA78 001189B8  EC A0 00 F2 */	fmuls f5, f0, f3
/* 8011BA7C 001189BC  C8 01 00 08 */	lfd f0, 8(r1)
/* 8011BA80 001189C0  38 A0 00 04 */	li r5, 4
/* 8011BA84 001189C4  C0 62 98 78 */	lfs f3, lbl_80517BD8@sda21(r2)
/* 8011BA88 001189C8  EC 00 20 28 */	fsubs f0, f0, f4
/* 8011BA8C 001189CC  EF E1 28 28 */	fsubs f31, f1, f5
/* 8011BA90 001189D0  EF C1 28 2A */	fadds f30, f1, f5
/* 8011BA94 001189D4  EF 63 00 32 */	fmuls f27, f3, f0
/* 8011BA98 001189D8  EF A2 28 28 */	fsubs f29, f2, f5
/* 8011BA9C 001189DC  EF 82 28 2A */	fadds f28, f2, f5
/* 8011BAA0 001189E0  EF 5B 18 2A */	fadds f26, f27, f3
/* 8011BAA4 001189E4  4B FC 9E E5 */	bl GXBegin
/* 8011BAA8 001189E8  3C C0 CC 01 */	lis r6, 0xCC008000@ha
/* 8011BAAC 001189EC  C0 22 98 00 */	lfs f1, lbl_80517B60@sda21(r2)
/* 8011BAB0 001189F0  D3 E6 80 00 */	stfs f31, 0xCC008000@l(r6)
/* 8011BAB4 001189F4  C0 02 98 0C */	lfs f0, lbl_80517B6C@sda21(r2)
/* 8011BAB8 001189F8  D3 A6 80 00 */	stfs f29, 0xCC008000@l(r6)
/* 8011BABC 001189FC  D0 26 80 00 */	stfs f1, 0xCC008000@l(r6)
/* 8011BAC0 00118A00  88 BF 00 03 */	lbz r5, 3(r31)
/* 8011BAC4 00118A04  88 9F 00 02 */	lbz r4, 2(r31)
/* 8011BAC8 00118A08  88 7F 00 01 */	lbz r3, 1(r31)
/* 8011BACC 00118A0C  88 1F 00 00 */	lbz r0, 0(r31)
/* 8011BAD0 00118A10  98 06 80 00 */	stb r0, 0xCC008000@l(r6)
/* 8011BAD4 00118A14  98 66 80 00 */	stb r3, 0xCC008000@l(r6)
/* 8011BAD8 00118A18  98 86 80 00 */	stb r4, 0xCC008000@l(r6)
/* 8011BADC 00118A1C  98 A6 80 00 */	stb r5, 0xCC008000@l(r6)
/* 8011BAE0 00118A20  D3 66 80 00 */	stfs f27, 0xCC008000@l(r6)
/* 8011BAE4 00118A24  D0 06 80 00 */	stfs f0, 0xCC008000@l(r6)
/* 8011BAE8 00118A28  D3 C6 80 00 */	stfs f30, 0xCC008000@l(r6)
/* 8011BAEC 00118A2C  D3 A6 80 00 */	stfs f29, 0xCC008000@l(r6)
/* 8011BAF0 00118A30  D0 26 80 00 */	stfs f1, 0xCC008000@l(r6)
/* 8011BAF4 00118A34  88 BF 00 03 */	lbz r5, 3(r31)
/* 8011BAF8 00118A38  88 9F 00 02 */	lbz r4, 2(r31)
/* 8011BAFC 00118A3C  88 7F 00 01 */	lbz r3, 1(r31)
/* 8011BB00 00118A40  88 1F 00 00 */	lbz r0, 0(r31)
/* 8011BB04 00118A44  98 06 80 00 */	stb r0, 0xCC008000@l(r6)
/* 8011BB08 00118A48  98 66 80 00 */	stb r3, 0xCC008000@l(r6)
/* 8011BB0C 00118A4C  98 86 80 00 */	stb r4, 0xCC008000@l(r6)
/* 8011BB10 00118A50  98 A6 80 00 */	stb r5, 0xCC008000@l(r6)
/* 8011BB14 00118A54  D3 46 80 00 */	stfs f26, 0xCC008000@l(r6)
/* 8011BB18 00118A58  D0 06 80 00 */	stfs f0, 0xCC008000@l(r6)
/* 8011BB1C 00118A5C  D3 E6 80 00 */	stfs f31, 0xCC008000@l(r6)
/* 8011BB20 00118A60  D3 86 80 00 */	stfs f28, 0xCC008000@l(r6)
/* 8011BB24 00118A64  D0 26 80 00 */	stfs f1, 0xCC008000@l(r6)
/* 8011BB28 00118A68  88 BF 00 03 */	lbz r5, 3(r31)
/* 8011BB2C 00118A6C  88 9F 00 02 */	lbz r4, 2(r31)
/* 8011BB30 00118A70  88 7F 00 01 */	lbz r3, 1(r31)
/* 8011BB34 00118A74  88 1F 00 00 */	lbz r0, 0(r31)
/* 8011BB38 00118A78  98 06 80 00 */	stb r0, 0xCC008000@l(r6)
/* 8011BB3C 00118A7C  98 66 80 00 */	stb r3, 0xCC008000@l(r6)
/* 8011BB40 00118A80  98 86 80 00 */	stb r4, 0xCC008000@l(r6)
/* 8011BB44 00118A84  98 A6 80 00 */	stb r5, 0xCC008000@l(r6)
/* 8011BB48 00118A88  D3 66 80 00 */	stfs f27, 0xCC008000@l(r6)
/* 8011BB4C 00118A8C  D0 26 80 00 */	stfs f1, 0xCC008000@l(r6)
/* 8011BB50 00118A90  D3 C6 80 00 */	stfs f30, 0xCC008000@l(r6)
/* 8011BB54 00118A94  D3 86 80 00 */	stfs f28, 0xCC008000@l(r6)
/* 8011BB58 00118A98  D0 26 80 00 */	stfs f1, 0xCC008000@l(r6)
/* 8011BB5C 00118A9C  88 BF 00 03 */	lbz r5, 3(r31)
/* 8011BB60 00118AA0  88 9F 00 02 */	lbz r4, 2(r31)
/* 8011BB64 00118AA4  88 7F 00 01 */	lbz r3, 1(r31)
/* 8011BB68 00118AA8  88 1F 00 00 */	lbz r0, 0(r31)
/* 8011BB6C 00118AAC  98 06 80 00 */	stb r0, 0xCC008000@l(r6)
/* 8011BB70 00118AB0  98 66 80 00 */	stb r3, 0xCC008000@l(r6)
/* 8011BB74 00118AB4  98 86 80 00 */	stb r4, 0xCC008000@l(r6)
/* 8011BB78 00118AB8  98 A6 80 00 */	stb r5, 0xCC008000@l(r6)
/* 8011BB7C 00118ABC  D3 46 80 00 */	stfs f26, 0xCC008000@l(r6)
/* 8011BB80 00118AC0  D0 26 80 00 */	stfs f1, 0xCC008000@l(r6)
/* 8011BB84 00118AC4  E3 E1 00 78 */	psq_l f31, 120(r1), 0, qr0
/* 8011BB88 00118AC8  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 8011BB8C 00118ACC  E3 C1 00 68 */	psq_l f30, 104(r1), 0, qr0
/* 8011BB90 00118AD0  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 8011BB94 00118AD4  E3 A1 00 58 */	psq_l f29, 88(r1), 0, qr0
/* 8011BB98 00118AD8  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 8011BB9C 00118ADC  E3 81 00 48 */	psq_l f28, 72(r1), 0, qr0
/* 8011BBA0 00118AE0  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 8011BBA4 00118AE4  E3 61 00 38 */	psq_l f27, 56(r1), 0, qr0
/* 8011BBA8 00118AE8  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 8011BBAC 00118AEC  E3 41 00 28 */	psq_l f26, 40(r1), 0, qr0
/* 8011BBB0 00118AF0  CB 41 00 20 */	lfd f26, 0x20(r1)
/* 8011BBB4 00118AF4  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8011BBB8 00118AF8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011BBBC 00118AFC  7C 08 03 A6 */	mtlr r0
/* 8011BBC0 00118B00  38 21 00 80 */	addi r1, r1, 0x80
/* 8011BBC4 00118B04  4E 80 00 20 */	blr 
.endfn drawNumberPrim__9CarryInfoFR8GraphicsffiR6Color4f

.fn init__13CarryInfoListFv, global
/* 8011BBC8 00118B08  4E 80 00 20 */	blr 
.endfn init__13CarryInfoListFv

.fn update__13CarryInfoListFv, global
/* 8011BBCC 00118B0C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011BBD0 00118B10  7C 08 02 A6 */	mflr r0
/* 8011BBD4 00118B14  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011BBD8 00118B18  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011BBDC 00118B1C  7C 7F 1B 78 */	mr r31, r3
/* 8011BBE0 00118B20  38 9F 00 24 */	addi r4, r31, 0x24
/* 8011BBE4 00118B24  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8011BBE8 00118B28  81 83 00 00 */	lwz r12, 0(r3)
/* 8011BBEC 00118B2C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011BBF0 00118B30  7D 89 03 A6 */	mtctr r12
/* 8011BBF4 00118B34  4E 80 04 21 */	bctrl 
/* 8011BBF8 00118B38  38 7F 00 48 */	addi r3, r31, 0x48
/* 8011BBFC 00118B3C  38 9F 00 24 */	addi r4, r31, 0x24
/* 8011BC00 00118B40  4B FF F3 DD */	bl update__9CarryInfoFRC14CarryInfoParam
/* 8011BC04 00118B44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011BC08 00118B48  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011BC0C 00118B4C  7C 08 03 A6 */	mtlr r0
/* 8011BC10 00118B50  38 21 00 10 */	addi r1, r1, 0x10
/* 8011BC14 00118B54  4E 80 00 20 */	blr 
.endfn update__13CarryInfoListFv

.fn draw__13CarryInfoListFR8Graphics, global
/* 8011BC18 00118B58  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011BC1C 00118B5C  7C 08 02 A6 */	mflr r0
/* 8011BC20 00118B60  7C 65 1B 78 */	mr r5, r3
/* 8011BC24 00118B64  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011BC28 00118B68  38 65 00 48 */	addi r3, r5, 0x48
/* 8011BC2C 00118B6C  38 A5 00 24 */	addi r5, r5, 0x24
/* 8011BC30 00118B70  4B FF F6 11 */	bl draw__9CarryInfoFR8GraphicsR14CarryInfoParam
/* 8011BC34 00118B74  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011BC38 00118B78  7C 08 03 A6 */	mtlr r0
/* 8011BC3C 00118B7C  38 21 00 10 */	addi r1, r1, 0x10
/* 8011BC40 00118B80  4E 80 00 20 */	blr 
.endfn draw__13CarryInfoListFR8Graphics

.fn getCarryInfoParam__13PokoInfoOwnerFR14CarryInfoParam, global
/* 8011BC44 00118B84  38 00 00 01 */	li r0, 1
/* 8011BC48 00118B88  C0 02 98 7C */	lfs f0, lbl_80517BDC@sda21(r2)
/* 8011BC4C 00118B8C  90 04 00 00 */	stw r0, 0(r4)
/* 8011BC50 00118B90  38 00 00 04 */	li r0, 4
/* 8011BC54 00118B94  C0 23 00 24 */	lfs f1, 0x24(r3)
/* 8011BC58 00118B98  D0 24 00 04 */	stfs f1, 4(r4)
/* 8011BC5C 00118B9C  C0 23 00 28 */	lfs f1, 0x28(r3)
/* 8011BC60 00118BA0  D0 24 00 08 */	stfs f1, 8(r4)
/* 8011BC64 00118BA4  C0 23 00 2C */	lfs f1, 0x2c(r3)
/* 8011BC68 00118BA8  D0 24 00 0C */	stfs f1, 0xc(r4)
/* 8011BC6C 00118BAC  D0 04 00 10 */	stfs f0, 0x10(r4)
/* 8011BC70 00118BB0  98 04 00 15 */	stb r0, 0x15(r4)
/* 8011BC74 00118BB4  80 03 00 30 */	lwz r0, 0x30(r3)
/* 8011BC78 00118BB8  90 04 00 20 */	stw r0, 0x20(r4)
/* 8011BC7C 00118BBC  4E 80 00 20 */	blr 
.endfn getCarryInfoParam__13PokoInfoOwnerFR14CarryInfoParam

.fn isFinish__13CarryInfoListFv, weak
/* 8011BC80 00118BC0  88 03 00 54 */	lbz r0, 0x54(r3)
/* 8011BC84 00118BC4  20 00 00 02 */	subfic r0, r0, 2
/* 8011BC88 00118BC8  7C 00 00 34 */	cntlzw r0, r0
/* 8011BC8C 00118BCC  54 03 D9 7E */	srwi r3, r0, 5
/* 8011BC90 00118BD0  4E 80 00 20 */	blr 
.endfn isFinish__13CarryInfoListFv

.fn __ct__12CarryInfoMgrFi, global
/* 8011BC94 00118BD4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011BC98 00118BD8  7C 08 02 A6 */	mflr r0
/* 8011BC9C 00118BDC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011BCA0 00118BE0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011BCA4 00118BE4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011BCA8 00118BE8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011BCAC 00118BEC  7C 7D 1B 78 */	mr r29, r3
/* 8011BCB0 00118BF0  48 00 0C C5 */	bl "__ct__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fi"
/* 8011BCB4 00118BF4  3C 80 80 4B */	lis r4, __vt__12CarryInfoMgr@ha
/* 8011BCB8 00118BF8  38 7D 00 BC */	addi r3, r29, 0xbc
/* 8011BCBC 00118BFC  38 04 C3 64 */	addi r0, r4, __vt__12CarryInfoMgr@l
/* 8011BCC0 00118C00  90 1D 00 00 */	stw r0, 0(r29)
/* 8011BCC4 00118C04  48 2F 56 CD */	bl __ct__5CNodeFv
/* 8011BCC8 00118C08  38 7D 00 D4 */	addi r3, r29, 0xd4
/* 8011BCCC 00118C0C  48 2F 56 C5 */	bl __ct__5CNodeFv
/* 8011BCD0 00118C10  38 00 00 00 */	li r0, 0
/* 8011BCD4 00118C14  38 60 01 14 */	li r3, 0x114
/* 8011BCD8 00118C18  90 1D 00 CC */	stw r0, 0xcc(r29)
/* 8011BCDC 00118C1C  90 1D 00 C8 */	stw r0, 0xc8(r29)
/* 8011BCE0 00118C20  90 1D 00 C4 */	stw r0, 0xc4(r29)
/* 8011BCE4 00118C24  90 1D 00 C0 */	stw r0, 0xc0(r29)
/* 8011BCE8 00118C28  90 1D 00 E4 */	stw r0, 0xe4(r29)
/* 8011BCEC 00118C2C  90 1D 00 E0 */	stw r0, 0xe0(r29)
/* 8011BCF0 00118C30  90 1D 00 DC */	stw r0, 0xdc(r29)
/* 8011BCF4 00118C34  90 1D 00 D8 */	stw r0, 0xd8(r29)
/* 8011BCF8 00118C38  4B F0 82 B5 */	bl __nwa__FUl
/* 8011BCFC 00118C3C  3C 80 80 12 */	lis r4, __ct__13PokoInfoOwnerFv@ha
/* 8011BD00 00118C40  3C A0 80 12 */	lis r5, __dt__13PokoInfoOwnerFv@ha
/* 8011BD04 00118C44  38 84 BD D4 */	addi r4, r4, __ct__13PokoInfoOwnerFv@l
/* 8011BD08 00118C48  38 C0 00 34 */	li r6, 0x34
/* 8011BD0C 00118C4C  38 A5 BD 68 */	addi r5, r5, __dt__13PokoInfoOwnerFv@l
/* 8011BD10 00118C50  38 E0 00 05 */	li r7, 5
/* 8011BD14 00118C54  4B FA 5C DD */	bl __construct_new_array
/* 8011BD18 00118C58  3B C0 00 00 */	li r30, 0
/* 8011BD1C 00118C5C  7C 7F 1B 78 */	mr r31, r3
.L_8011BD20:
/* 8011BD20 00118C60  28 1F 00 00 */	cmplwi r31, 0
/* 8011BD24 00118C64  7F E4 FB 78 */	mr r4, r31
/* 8011BD28 00118C68  41 82 00 08 */	beq .L_8011BD30
/* 8011BD2C 00118C6C  38 9F 00 04 */	addi r4, r31, 4
.L_8011BD30:
/* 8011BD30 00118C70  38 7D 00 D4 */	addi r3, r29, 0xd4
/* 8011BD34 00118C74  48 2F 56 D5 */	bl add__5CNodeFP5CNode
/* 8011BD38 00118C78  3B DE 00 01 */	addi r30, r30, 1
/* 8011BD3C 00118C7C  3B FF 00 34 */	addi r31, r31, 0x34
/* 8011BD40 00118C80  28 1E 00 05 */	cmplwi r30, 5
/* 8011BD44 00118C84  41 80 FF DC */	blt .L_8011BD20
/* 8011BD48 00118C88  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011BD4C 00118C8C  7F A3 EB 78 */	mr r3, r29
/* 8011BD50 00118C90  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011BD54 00118C94  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011BD58 00118C98  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011BD5C 00118C9C  7C 08 03 A6 */	mtlr r0
/* 8011BD60 00118CA0  38 21 00 20 */	addi r1, r1, 0x20
/* 8011BD64 00118CA4  4E 80 00 20 */	blr 
.endfn __ct__12CarryInfoMgrFi

.fn __dt__13PokoInfoOwnerFv, weak
/* 8011BD68 00118CA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011BD6C 00118CAC  7C 08 02 A6 */	mflr r0
/* 8011BD70 00118CB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011BD74 00118CB4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011BD78 00118CB8  7C 9F 23 78 */	mr r31, r4
/* 8011BD7C 00118CBC  93 C1 00 08 */	stw r30, 8(r1)
/* 8011BD80 00118CC0  7C 7E 1B 79 */	or. r30, r3, r3
/* 8011BD84 00118CC4  41 82 00 34 */	beq .L_8011BDB8
/* 8011BD88 00118CC8  3C 80 80 4B */	lis r4, __vt__13PokoInfoOwner@ha
/* 8011BD8C 00118CCC  38 7E 00 04 */	addi r3, r30, 4
/* 8011BD90 00118CD0  38 A4 C3 E4 */	addi r5, r4, __vt__13PokoInfoOwner@l
/* 8011BD94 00118CD4  38 80 00 00 */	li r4, 0
/* 8011BD98 00118CD8  90 BE 00 00 */	stw r5, 0(r30)
/* 8011BD9C 00118CDC  38 05 00 0C */	addi r0, r5, 0xc
/* 8011BDA0 00118CE0  90 1E 00 04 */	stw r0, 4(r30)
/* 8011BDA4 00118CE4  48 2F 57 E5 */	bl __dt__5CNodeFv
/* 8011BDA8 00118CE8  7F E0 07 35 */	extsh. r0, r31
/* 8011BDAC 00118CEC  40 81 00 0C */	ble .L_8011BDB8
/* 8011BDB0 00118CF0  7F C3 F3 78 */	mr r3, r30
/* 8011BDB4 00118CF4  4B F0 83 01 */	bl __dl__FPv
.L_8011BDB8:
/* 8011BDB8 00118CF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011BDBC 00118CFC  7F C3 F3 78 */	mr r3, r30
/* 8011BDC0 00118D00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011BDC4 00118D04  83 C1 00 08 */	lwz r30, 8(r1)
/* 8011BDC8 00118D08  7C 08 03 A6 */	mtlr r0
/* 8011BDCC 00118D0C  38 21 00 10 */	addi r1, r1, 0x10
/* 8011BDD0 00118D10  4E 80 00 20 */	blr 
.endfn __dt__13PokoInfoOwnerFv

.fn __ct__13PokoInfoOwnerFv, weak
/* 8011BDD4 00118D14  3C 80 80 4B */	lis r4, __vt__14CarryInfoOwner@ha
/* 8011BDD8 00118D18  3C A0 80 4B */	lis r5, __vt__13PokoInfoOwner@ha
/* 8011BDDC 00118D1C  38 04 C3 D8 */	addi r0, r4, __vt__14CarryInfoOwner@l
/* 8011BDE0 00118D20  3C C0 80 4F */	lis r6, __vt__5CNode@ha
/* 8011BDE4 00118D24  90 03 00 00 */	stw r0, 0(r3)
/* 8011BDE8 00118D28  38 06 B5 28 */	addi r0, r6, __vt__5CNode@l
/* 8011BDEC 00118D2C  38 E0 00 00 */	li r7, 0
/* 8011BDF0 00118D30  38 C2 98 84 */	addi r6, r2, lbl_80517BE4@sda21
/* 8011BDF4 00118D34  90 03 00 04 */	stw r0, 4(r3)
/* 8011BDF8 00118D38  38 A5 C3 E4 */	addi r5, r5, __vt__13PokoInfoOwner@l
/* 8011BDFC 00118D3C  38 05 00 0C */	addi r0, r5, 0xc
/* 8011BE00 00118D40  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011BE04 00118D44  90 E3 00 14 */	stw r7, 0x14(r3)
/* 8011BE08 00118D48  3C 80 80 51 */	lis r4, "zero__10Vector3<f>"@ha
/* 8011BE0C 00118D4C  90 E3 00 10 */	stw r7, 0x10(r3)
/* 8011BE10 00118D50  90 E3 00 0C */	stw r7, 0xc(r3)
/* 8011BE14 00118D54  90 E3 00 08 */	stw r7, 8(r3)
/* 8011BE18 00118D58  90 C3 00 18 */	stw r6, 0x18(r3)
/* 8011BE1C 00118D5C  90 A3 00 00 */	stw r5, 0(r3)
/* 8011BE20 00118D60  90 03 00 04 */	stw r0, 4(r3)
/* 8011BE24 00118D64  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8011BE28 00118D68  90 E3 00 20 */	stw r7, 0x20(r3)
/* 8011BE2C 00118D6C  C4 04 41 E4 */	lfsu f0, "zero__10Vector3<f>"@l(r4)
/* 8011BE30 00118D70  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8011BE34 00118D74  C0 04 00 04 */	lfs f0, 4(r4)
/* 8011BE38 00118D78  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8011BE3C 00118D7C  C0 04 00 08 */	lfs f0, 8(r4)
/* 8011BE40 00118D80  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 8011BE44 00118D84  90 E3 00 30 */	stw r7, 0x30(r3)
/* 8011BE48 00118D88  4E 80 00 20 */	blr 
.endfn __ct__13PokoInfoOwnerFv

.fn "__dt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv", weak
/* 8011BE4C 00118D8C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011BE50 00118D90  7C 08 02 A6 */	mflr r0
/* 8011BE54 00118D94  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011BE58 00118D98  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011BE5C 00118D9C  7C 9F 23 78 */	mr r31, r4
/* 8011BE60 00118DA0  93 C1 00 08 */	stw r30, 8(r1)
/* 8011BE64 00118DA4  7C 7E 1B 79 */	or. r30, r3, r3
/* 8011BE68 00118DA8  41 82 01 04 */	beq .L_8011BF6C
/* 8011BE6C 00118DAC  3C 60 80 4B */	lis r3, "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011BE70 00118DB0  34 1E 00 5C */	addic. r0, r30, 0x5c
/* 8011BE74 00118DB4  38 03 C3 B8 */	addi r0, r3, "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011BE78 00118DB8  90 1E 00 00 */	stw r0, 0(r30)
/* 8011BE7C 00118DBC  41 82 00 64 */	beq .L_8011BEE0
/* 8011BE80 00118DC0  3C 60 80 4B */	lis r3, __vt__13CarryInfoList@ha
/* 8011BE84 00118DC4  34 1E 00 5C */	addic. r0, r30, 0x5c
/* 8011BE88 00118DC8  38 03 C4 04 */	addi r0, r3, __vt__13CarryInfoList@l
/* 8011BE8C 00118DCC  90 1E 00 5C */	stw r0, 0x5c(r30)
/* 8011BE90 00118DD0  41 82 00 50 */	beq .L_8011BEE0
/* 8011BE94 00118DD4  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011BE98 00118DD8  38 03 C3 9C */	addi r0, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011BE9C 00118DDC  90 1E 00 5C */	stw r0, 0x5c(r30)
/* 8011BEA0 00118DE0  80 7E 00 74 */	lwz r3, 0x74(r30)
/* 8011BEA4 00118DE4  28 03 00 00 */	cmplwi r3, 0
/* 8011BEA8 00118DE8  41 82 00 0C */	beq .L_8011BEB4
/* 8011BEAC 00118DEC  80 1E 00 78 */	lwz r0, 0x78(r30)
/* 8011BEB0 00118DF0  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011BEB4:
/* 8011BEB4 00118DF4  80 7E 00 78 */	lwz r3, 0x78(r30)
/* 8011BEB8 00118DF8  28 03 00 00 */	cmplwi r3, 0
/* 8011BEBC 00118DFC  41 82 00 0C */	beq .L_8011BEC8
/* 8011BEC0 00118E00  80 1E 00 74 */	lwz r0, 0x74(r30)
/* 8011BEC4 00118E04  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011BEC8:
/* 8011BEC8 00118E08  38 00 00 00 */	li r0, 0
/* 8011BECC 00118E0C  38 7E 00 5C */	addi r3, r30, 0x5c
/* 8011BED0 00118E10  90 1E 00 78 */	stw r0, 0x78(r30)
/* 8011BED4 00118E14  38 80 00 00 */	li r4, 0
/* 8011BED8 00118E18  90 1E 00 74 */	stw r0, 0x74(r30)
/* 8011BEDC 00118E1C  4B F0 11 59 */	bl __dt__11JKRDisposerFv
.L_8011BEE0:
/* 8011BEE0 00118E20  34 1E 00 04 */	addic. r0, r30, 4
/* 8011BEE4 00118E24  41 82 00 64 */	beq .L_8011BF48
/* 8011BEE8 00118E28  3C 60 80 4B */	lis r3, __vt__13CarryInfoList@ha
/* 8011BEEC 00118E2C  34 1E 00 04 */	addic. r0, r30, 4
/* 8011BEF0 00118E30  38 03 C4 04 */	addi r0, r3, __vt__13CarryInfoList@l
/* 8011BEF4 00118E34  90 1E 00 04 */	stw r0, 4(r30)
/* 8011BEF8 00118E38  41 82 00 50 */	beq .L_8011BF48
/* 8011BEFC 00118E3C  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011BF00 00118E40  38 03 C3 9C */	addi r0, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011BF04 00118E44  90 1E 00 04 */	stw r0, 4(r30)
/* 8011BF08 00118E48  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8011BF0C 00118E4C  28 03 00 00 */	cmplwi r3, 0
/* 8011BF10 00118E50  41 82 00 0C */	beq .L_8011BF1C
/* 8011BF14 00118E54  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 8011BF18 00118E58  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011BF1C:
/* 8011BF1C 00118E5C  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8011BF20 00118E60  28 03 00 00 */	cmplwi r3, 0
/* 8011BF24 00118E64  41 82 00 0C */	beq .L_8011BF30
/* 8011BF28 00118E68  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 8011BF2C 00118E6C  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011BF30:
/* 8011BF30 00118E70  38 00 00 00 */	li r0, 0
/* 8011BF34 00118E74  38 7E 00 04 */	addi r3, r30, 4
/* 8011BF38 00118E78  90 1E 00 20 */	stw r0, 0x20(r30)
/* 8011BF3C 00118E7C  38 80 00 00 */	li r4, 0
/* 8011BF40 00118E80  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011BF44 00118E84  4B F0 10 F1 */	bl __dt__11JKRDisposerFv
.L_8011BF48:
/* 8011BF48 00118E88  28 1E 00 00 */	cmplwi r30, 0
/* 8011BF4C 00118E8C  41 82 00 10 */	beq .L_8011BF5C
/* 8011BF50 00118E90  3C 60 80 4B */	lis r3, __vt__11InfoMgrBase@ha
/* 8011BF54 00118E94  38 03 C3 84 */	addi r0, r3, __vt__11InfoMgrBase@l
/* 8011BF58 00118E98  90 1E 00 00 */	stw r0, 0(r30)
.L_8011BF5C:
/* 8011BF5C 00118E9C  7F E0 07 35 */	extsh. r0, r31
/* 8011BF60 00118EA0  40 81 00 0C */	ble .L_8011BF6C
/* 8011BF64 00118EA4  7F C3 F3 78 */	mr r3, r30
/* 8011BF68 00118EA8  4B F0 81 4D */	bl __dl__FPv
.L_8011BF6C:
/* 8011BF6C 00118EAC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011BF70 00118EB0  7F C3 F3 78 */	mr r3, r30
/* 8011BF74 00118EB4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011BF78 00118EB8  83 C1 00 08 */	lwz r30, 8(r1)
/* 8011BF7C 00118EBC  7C 08 03 A6 */	mtlr r0
/* 8011BF80 00118EC0  38 21 00 10 */	addi r1, r1, 0x10
/* 8011BF84 00118EC4  4E 80 00 20 */	blr 
.endfn "__dt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv"

.fn __dt__12CarryInfoMgrFv, global
/* 8011BF88 00118EC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011BF8C 00118ECC  7C 08 02 A6 */	mflr r0
/* 8011BF90 00118ED0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011BF94 00118ED4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011BF98 00118ED8  7C 9F 23 78 */	mr r31, r4
/* 8011BF9C 00118EDC  93 C1 00 08 */	stw r30, 8(r1)
/* 8011BFA0 00118EE0  7C 7E 1B 79 */	or. r30, r3, r3
/* 8011BFA4 00118EE4  41 82 01 38 */	beq .L_8011C0DC
/* 8011BFA8 00118EE8  3C 60 80 4B */	lis r3, __vt__12CarryInfoMgr@ha
/* 8011BFAC 00118EEC  38 00 00 00 */	li r0, 0
/* 8011BFB0 00118EF0  38 83 C3 64 */	addi r4, r3, __vt__12CarryInfoMgr@l
/* 8011BFB4 00118EF4  38 7E 00 D4 */	addi r3, r30, 0xd4
/* 8011BFB8 00118EF8  90 9E 00 00 */	stw r4, 0(r30)
/* 8011BFBC 00118EFC  38 80 FF FF */	li r4, -1
/* 8011BFC0 00118F00  90 0D 92 18 */	stw r0, carryInfoMgr@sda21(r13)
/* 8011BFC4 00118F04  48 2F 55 C5 */	bl __dt__5CNodeFv
/* 8011BFC8 00118F08  38 7E 00 BC */	addi r3, r30, 0xbc
/* 8011BFCC 00118F0C  38 80 FF FF */	li r4, -1
/* 8011BFD0 00118F10  48 2F 55 B9 */	bl __dt__5CNodeFv
/* 8011BFD4 00118F14  28 1E 00 00 */	cmplwi r30, 0
/* 8011BFD8 00118F18  41 82 00 F4 */	beq .L_8011C0CC
/* 8011BFDC 00118F1C  3C 60 80 4B */	lis r3, "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011BFE0 00118F20  34 1E 00 5C */	addic. r0, r30, 0x5c
/* 8011BFE4 00118F24  38 03 C3 B8 */	addi r0, r3, "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011BFE8 00118F28  90 1E 00 00 */	stw r0, 0(r30)
/* 8011BFEC 00118F2C  41 82 00 64 */	beq .L_8011C050
/* 8011BFF0 00118F30  3C 60 80 4B */	lis r3, __vt__13CarryInfoList@ha
/* 8011BFF4 00118F34  34 1E 00 5C */	addic. r0, r30, 0x5c
/* 8011BFF8 00118F38  38 03 C4 04 */	addi r0, r3, __vt__13CarryInfoList@l
/* 8011BFFC 00118F3C  90 1E 00 5C */	stw r0, 0x5c(r30)
/* 8011C000 00118F40  41 82 00 50 */	beq .L_8011C050
/* 8011C004 00118F44  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011C008 00118F48  38 03 C3 9C */	addi r0, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011C00C 00118F4C  90 1E 00 5C */	stw r0, 0x5c(r30)
/* 8011C010 00118F50  80 7E 00 74 */	lwz r3, 0x74(r30)
/* 8011C014 00118F54  28 03 00 00 */	cmplwi r3, 0
/* 8011C018 00118F58  41 82 00 0C */	beq .L_8011C024
/* 8011C01C 00118F5C  80 1E 00 78 */	lwz r0, 0x78(r30)
/* 8011C020 00118F60  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011C024:
/* 8011C024 00118F64  80 7E 00 78 */	lwz r3, 0x78(r30)
/* 8011C028 00118F68  28 03 00 00 */	cmplwi r3, 0
/* 8011C02C 00118F6C  41 82 00 0C */	beq .L_8011C038
/* 8011C030 00118F70  80 1E 00 74 */	lwz r0, 0x74(r30)
/* 8011C034 00118F74  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011C038:
/* 8011C038 00118F78  38 00 00 00 */	li r0, 0
/* 8011C03C 00118F7C  38 7E 00 5C */	addi r3, r30, 0x5c
/* 8011C040 00118F80  90 1E 00 78 */	stw r0, 0x78(r30)
/* 8011C044 00118F84  38 80 00 00 */	li r4, 0
/* 8011C048 00118F88  90 1E 00 74 */	stw r0, 0x74(r30)
/* 8011C04C 00118F8C  4B F0 0F E9 */	bl __dt__11JKRDisposerFv
.L_8011C050:
/* 8011C050 00118F90  34 1E 00 04 */	addic. r0, r30, 4
/* 8011C054 00118F94  41 82 00 64 */	beq .L_8011C0B8
/* 8011C058 00118F98  3C 60 80 4B */	lis r3, __vt__13CarryInfoList@ha
/* 8011C05C 00118F9C  34 1E 00 04 */	addic. r0, r30, 4
/* 8011C060 00118FA0  38 03 C4 04 */	addi r0, r3, __vt__13CarryInfoList@l
/* 8011C064 00118FA4  90 1E 00 04 */	stw r0, 4(r30)
/* 8011C068 00118FA8  41 82 00 50 */	beq .L_8011C0B8
/* 8011C06C 00118FAC  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011C070 00118FB0  38 03 C3 9C */	addi r0, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011C074 00118FB4  90 1E 00 04 */	stw r0, 4(r30)
/* 8011C078 00118FB8  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8011C07C 00118FBC  28 03 00 00 */	cmplwi r3, 0
/* 8011C080 00118FC0  41 82 00 0C */	beq .L_8011C08C
/* 8011C084 00118FC4  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 8011C088 00118FC8  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011C08C:
/* 8011C08C 00118FCC  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8011C090 00118FD0  28 03 00 00 */	cmplwi r3, 0
/* 8011C094 00118FD4  41 82 00 0C */	beq .L_8011C0A0
/* 8011C098 00118FD8  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 8011C09C 00118FDC  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011C0A0:
/* 8011C0A0 00118FE0  38 00 00 00 */	li r0, 0
/* 8011C0A4 00118FE4  38 7E 00 04 */	addi r3, r30, 4
/* 8011C0A8 00118FE8  90 1E 00 20 */	stw r0, 0x20(r30)
/* 8011C0AC 00118FEC  38 80 00 00 */	li r4, 0
/* 8011C0B0 00118FF0  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011C0B4 00118FF4  4B F0 0F 81 */	bl __dt__11JKRDisposerFv
.L_8011C0B8:
/* 8011C0B8 00118FF8  28 1E 00 00 */	cmplwi r30, 0
/* 8011C0BC 00118FFC  41 82 00 10 */	beq .L_8011C0CC
/* 8011C0C0 00119000  3C 60 80 4B */	lis r3, __vt__11InfoMgrBase@ha
/* 8011C0C4 00119004  38 03 C3 84 */	addi r0, r3, __vt__11InfoMgrBase@l
/* 8011C0C8 00119008  90 1E 00 00 */	stw r0, 0(r30)
.L_8011C0CC:
/* 8011C0CC 0011900C  7F E0 07 35 */	extsh. r0, r31
/* 8011C0D0 00119010  40 81 00 0C */	ble .L_8011C0DC
/* 8011C0D4 00119014  7F C3 F3 78 */	mr r3, r30
/* 8011C0D8 00119018  4B F0 7F DD */	bl __dl__FPv
.L_8011C0DC:
/* 8011C0DC 0011901C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C0E0 00119020  7F C3 F3 78 */	mr r3, r30
/* 8011C0E4 00119024  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C0E8 00119028  83 C1 00 08 */	lwz r30, 8(r1)
/* 8011C0EC 0011902C  7C 08 03 A6 */	mtlr r0
/* 8011C0F0 00119030  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C0F4 00119034  4E 80 00 20 */	blr 
.endfn __dt__12CarryInfoMgrFv

.fn "appearPoko__12CarryInfoMgrFRC10Vector3<f>i", global
/* 8011C0F8 00119038  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011C0FC 0011903C  7C 08 02 A6 */	mflr r0
/* 8011C100 00119040  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011C104 00119044  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 8011C108 00119048  7C 7B 1B 78 */	mr r27, r3
/* 8011C10C 0011904C  7C 9C 23 78 */	mr r28, r4
/* 8011C110 00119050  7C BD 2B 78 */	mr r29, r5
/* 8011C114 00119054  83 C3 00 E4 */	lwz r30, 0xe4(r3)
/* 8011C118 00119058  28 1E 00 00 */	cmplwi r30, 0
/* 8011C11C 0011905C  41 82 00 08 */	beq .L_8011C124
/* 8011C120 00119060  3B DE FF FC */	addi r30, r30, -4
.L_8011C124:
/* 8011C124 00119064  28 1E 00 00 */	cmplwi r30, 0
/* 8011C128 00119068  41 82 00 7C */	beq .L_8011C1A4
/* 8011C12C 0011906C  7F 63 DB 78 */	mr r3, r27
/* 8011C130 00119070  7F C4 F3 78 */	mr r4, r30
/* 8011C134 00119074  81 9B 00 00 */	lwz r12, 0(r27)
/* 8011C138 00119078  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8011C13C 0011907C  7D 89 03 A6 */	mtctr r12
/* 8011C140 00119080  4E 80 04 21 */	bctrl 
/* 8011C144 00119084  7C 7F 1B 79 */	or. r31, r3, r3
/* 8011C148 00119088  41 82 00 5C */	beq .L_8011C1A4
/* 8011C14C 0011908C  38 7E 00 04 */	addi r3, r30, 4
/* 8011C150 00119090  48 2F 54 81 */	bl del__5CNodeFv
/* 8011C154 00119094  28 1E 00 00 */	cmplwi r30, 0
/* 8011C158 00119098  7F C4 F3 78 */	mr r4, r30
/* 8011C15C 0011909C  41 82 00 08 */	beq .L_8011C164
/* 8011C160 001190A0  38 9E 00 04 */	addi r4, r30, 4
.L_8011C164:
/* 8011C164 001190A4  38 7B 00 BC */	addi r3, r27, 0xbc
/* 8011C168 001190A8  48 2F 52 59 */	bl addHead__5CNodeFP5CNode
/* 8011C16C 001190AC  93 FE 00 20 */	stw r31, 0x20(r30)
/* 8011C170 001190B0  38 00 00 00 */	li r0, 0
/* 8011C174 001190B4  C0 3C 00 00 */	lfs f1, 0(r28)
/* 8011C178 001190B8  C0 1C 00 04 */	lfs f0, 4(r28)
/* 8011C17C 001190BC  D0 3E 00 24 */	stfs f1, 0x24(r30)
/* 8011C180 001190C0  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8011C184 001190C4  D0 1E 00 28 */	stfs f0, 0x28(r30)
/* 8011C188 001190C8  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011C18C 001190CC  D0 3E 00 2C */	stfs f1, 0x2c(r30)
/* 8011C190 001190D0  93 BE 00 30 */	stw r29, 0x30(r30)
/* 8011C194 001190D4  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8011C198 001190D8  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8011C19C 001190DC  98 03 00 54 */	stb r0, 0x54(r3)
/* 8011C1A0 001190E0  98 03 00 56 */	stb r0, 0x56(r3)
.L_8011C1A4:
/* 8011C1A4 001190E4  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 8011C1A8 001190E8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011C1AC 001190EC  7C 08 03 A6 */	mtlr r0
/* 8011C1B0 001190F0  38 21 00 20 */	addi r1, r1, 0x20
/* 8011C1B4 001190F4  4E 80 00 20 */	blr 
.endfn "appearPoko__12CarryInfoMgrFRC10Vector3<f>i"

.fn regist__12CarryInfoMgrFP14CarryInfoOwner, weak
/* 8011C1B8 001190F8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C1BC 001190FC  7C 08 02 A6 */	mflr r0
/* 8011C1C0 00119100  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C1C4 00119104  48 00 07 3D */	bl "regist__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner"
/* 8011C1C8 00119108  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C1CC 0011910C  7C 08 03 A6 */	mtlr r0
/* 8011C1D0 00119110  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C1D4 00119114  4E 80 00 20 */	blr 
.endfn regist__12CarryInfoMgrFP14CarryInfoOwner

.fn appear__12CarryInfoMgrFP14CarryInfoOwner, global
/* 8011C1D8 00119118  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C1DC 0011911C  7C 08 02 A6 */	mflr r0
/* 8011C1E0 00119120  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C1E4 00119124  81 83 00 00 */	lwz r12, 0(r3)
/* 8011C1E8 00119128  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8011C1EC 0011912C  7D 89 03 A6 */	mtctr r12
/* 8011C1F0 00119130  4E 80 04 21 */	bctrl 
/* 8011C1F4 00119134  28 03 00 00 */	cmplwi r3, 0
/* 8011C1F8 00119138  41 82 00 10 */	beq .L_8011C208
/* 8011C1FC 0011913C  38 00 00 00 */	li r0, 0
/* 8011C200 00119140  98 03 00 54 */	stb r0, 0x54(r3)
/* 8011C204 00119144  98 03 00 56 */	stb r0, 0x56(r3)
.L_8011C208:
/* 8011C208 00119148  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C20C 0011914C  7C 08 03 A6 */	mtlr r0
/* 8011C210 00119150  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C214 00119154  4E 80 00 20 */	blr 
.endfn appear__12CarryInfoMgrFP14CarryInfoOwner

.fn loadResource__12CarryInfoMgrFv, global
/* 8011C218 00119158  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011C21C 0011915C  7C 08 02 A6 */	mflr r0
/* 8011C220 00119160  3C 80 80 48 */	lis r4, lbl_8047B290@ha
/* 8011C224 00119164  38 A0 00 00 */	li r5, 0
/* 8011C228 00119168  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011C22C 0011916C  38 C0 00 01 */	li r6, 1
/* 8011C230 00119170  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011C234 00119174  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011C238 00119178  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011C23C 0011917C  7C 7D 1B 78 */	mr r29, r3
/* 8011C240 00119180  38 64 B2 90 */	addi r3, r4, lbl_8047B290@l
/* 8011C244 00119184  38 80 00 01 */	li r4, 1
/* 8011C248 00119188  4B EF EE E9 */	bl mount__10JKRArchiveFPCcQ210JKRArchive10EMountModeP7JKRHeapQ210JKRArchive15EMountDirection
/* 8011C24C 0011918C  3C A0 80 48 */	lis r5, lbl_8047B2B0@ha
/* 8011C250 00119190  7C 64 1B 78 */	mr r4, r3
/* 8011C254 00119194  38 65 B2 B0 */	addi r3, r5, lbl_8047B2B0@l
/* 8011C258 00119198  4B F0 6D C1 */	bl getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader
/* 8011C25C 0011919C  7C 7E 1B 78 */	mr r30, r3
/* 8011C260 001191A0  38 60 00 40 */	li r3, 0x40
/* 8011C264 001191A4  4B F0 7C 41 */	bl __nw__FUl
/* 8011C268 001191A8  7C 7F 1B 79 */	or. r31, r3, r3
/* 8011C26C 001191AC  41 82 00 24 */	beq .L_8011C290
/* 8011C270 001191B0  38 00 00 00 */	li r0, 0
/* 8011C274 001191B4  7F C4 F3 78 */	mr r4, r30
/* 8011C278 001191B8  90 1F 00 28 */	stw r0, 0x28(r31)
/* 8011C27C 001191BC  38 A0 00 00 */	li r5, 0
/* 8011C280 001191C0  4B F1 6E 05 */	bl storeTIMG__10JUTTextureFPC7ResTIMGUc
/* 8011C284 001191C4  88 1F 00 3B */	lbz r0, 0x3b(r31)
/* 8011C288 001191C8  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 8011C28C 001191CC  98 1F 00 3B */	stb r0, 0x3b(r31)
.L_8011C290:
/* 8011C290 001191D0  93 FD 00 B8 */	stw r31, 0xb8(r29)
/* 8011C294 001191D4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011C298 001191D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011C29C 001191DC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011C2A0 001191E0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011C2A4 001191E4  7C 08 03 A6 */	mtlr r0
/* 8011C2A8 001191E8  38 21 00 20 */	addi r1, r1, 0x20
/* 8011C2AC 001191EC  4E 80 00 20 */	blr 
.endfn loadResource__12CarryInfoMgrFv

.fn draw__12CarryInfoMgrFR8Graphics, global
/* 8011C2B0 001191F0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8011C2B4 001191F4  7C 08 02 A6 */	mflr r0
/* 8011C2B8 001191F8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8011C2BC 001191FC  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8011C2C0 00119200  7C 9F 23 78 */	mr r31, r4
/* 8011C2C4 00119204  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8011C2C8 00119208  7C 7E 1B 78 */	mr r30, r3
/* 8011C2CC 0011920C  80 AD 9B 54 */	lwz r5, moviePlayer__4Game@sda21(r13)
/* 8011C2D0 00119210  28 05 00 00 */	cmplwi r5, 0
/* 8011C2D4 00119214  41 82 00 10 */	beq .L_8011C2E4
/* 8011C2D8 00119218  80 05 01 F0 */	lwz r0, 0x1f0(r5)
/* 8011C2DC 0011921C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8011C2E0 00119220  40 82 01 50 */	bne .L_8011C430
.L_8011C2E4:
/* 8011C2E4 00119224  48 30 BC 21 */	bl clearInitGX__8GraphicsFv
/* 8011C2E8 00119228  38 60 00 01 */	li r3, 1
/* 8011C2EC 0011922C  4B FC AB 79 */	bl GXSetNumChans
/* 8011C2F0 00119230  38 60 00 00 */	li r3, 0
/* 8011C2F4 00119234  4B FC C0 85 */	bl GXSetTevDirect
/* 8011C2F8 00119238  38 60 00 01 */	li r3, 1
/* 8011C2FC 0011923C  4B FC C8 BD */	bl GXSetNumTevStages
/* 8011C300 00119240  38 60 00 00 */	li r3, 0
/* 8011C304 00119244  38 80 00 00 */	li r4, 0
/* 8011C308 00119248  4B FC C1 75 */	bl GXSetTevOp
/* 8011C30C 0011924C  38 60 00 00 */	li r3, 0
/* 8011C310 00119250  38 80 00 00 */	li r4, 0
/* 8011C314 00119254  38 A0 00 00 */	li r5, 0
/* 8011C318 00119258  38 C0 00 04 */	li r6, 4
/* 8011C31C 0011925C  4B FC C7 01 */	bl GXSetTevOrder
/* 8011C320 00119260  38 60 00 04 */	li r3, 4
/* 8011C324 00119264  38 80 00 00 */	li r4, 0
/* 8011C328 00119268  38 A0 00 00 */	li r5, 0
/* 8011C32C 0011926C  38 C0 00 01 */	li r6, 1
/* 8011C330 00119270  38 E0 00 00 */	li r7, 0
/* 8011C334 00119274  39 00 00 00 */	li r8, 0
/* 8011C338 00119278  39 20 00 02 */	li r9, 2
/* 8011C33C 0011927C  4B FC AB 65 */	bl GXSetChanCtrl
/* 8011C340 00119280  4B FC 83 91 */	bl GXClearVtxDesc
/* 8011C344 00119284  38 60 00 09 */	li r3, 9
/* 8011C348 00119288  38 80 00 01 */	li r4, 1
/* 8011C34C 0011928C  4B FC 7F 39 */	bl GXSetVtxDesc
/* 8011C350 00119290  38 60 00 0B */	li r3, 0xb
/* 8011C354 00119294  38 80 00 01 */	li r4, 1
/* 8011C358 00119298  4B FC 7F 2D */	bl GXSetVtxDesc
/* 8011C35C 0011929C  38 60 00 0D */	li r3, 0xd
/* 8011C360 001192A0  38 80 00 01 */	li r4, 1
/* 8011C364 001192A4  4B FC 7F 21 */	bl GXSetVtxDesc
/* 8011C368 001192A8  38 60 00 00 */	li r3, 0
/* 8011C36C 001192AC  38 80 00 09 */	li r4, 9
/* 8011C370 001192B0  38 A0 00 01 */	li r5, 1
/* 8011C374 001192B4  38 C0 00 04 */	li r6, 4
/* 8011C378 001192B8  38 E0 00 00 */	li r7, 0
/* 8011C37C 001192BC  4B FC 83 8D */	bl GXSetVtxAttrFmt
/* 8011C380 001192C0  38 60 00 00 */	li r3, 0
/* 8011C384 001192C4  38 80 00 0B */	li r4, 0xb
/* 8011C388 001192C8  38 A0 00 01 */	li r5, 1
/* 8011C38C 001192CC  38 C0 00 05 */	li r6, 5
/* 8011C390 001192D0  38 E0 00 00 */	li r7, 0
/* 8011C394 001192D4  4B FC 83 75 */	bl GXSetVtxAttrFmt
/* 8011C398 001192D8  38 60 00 00 */	li r3, 0
/* 8011C39C 001192DC  38 80 00 0D */	li r4, 0xd
/* 8011C3A0 001192E0  38 A0 00 01 */	li r5, 1
/* 8011C3A4 001192E4  38 C0 00 04 */	li r6, 4
/* 8011C3A8 001192E8  38 E0 00 00 */	li r7, 0
/* 8011C3AC 001192EC  4B FC 83 5D */	bl GXSetVtxAttrFmt
/* 8011C3B0 001192F0  38 60 00 01 */	li r3, 1
/* 8011C3B4 001192F4  38 80 00 04 */	li r4, 4
/* 8011C3B8 001192F8  38 A0 00 05 */	li r5, 5
/* 8011C3BC 001192FC  38 C0 00 0F */	li r6, 0xf
/* 8011C3C0 00119300  4B FC CD 19 */	bl GXSetBlendMode
/* 8011C3C4 00119304  38 60 00 00 */	li r3, 0
/* 8011C3C8 00119308  38 80 00 01 */	li r4, 1
/* 8011C3CC 0011930C  38 A0 00 00 */	li r5, 0
/* 8011C3D0 00119310  4B FC CD B5 */	bl GXSetZMode
/* 8011C3D4 00119314  38 60 00 00 */	li r3, 0
/* 8011C3D8 00119318  4B FC D2 41 */	bl GXSetCurrentMtx
/* 8011C3DC 0011931C  38 60 00 01 */	li r3, 1
/* 8011C3E0 00119320  4B FC 8B BD */	bl GXSetNumTexGens
/* 8011C3E4 00119324  38 60 00 00 */	li r3, 0
/* 8011C3E8 00119328  38 80 00 01 */	li r4, 1
/* 8011C3EC 0011932C  38 A0 00 0C */	li r5, 0xc
/* 8011C3F0 00119330  38 C0 00 3C */	li r6, 0x3c
/* 8011C3F4 00119334  38 E0 00 00 */	li r7, 0
/* 8011C3F8 00119338  39 00 00 7D */	li r8, 0x7d
/* 8011C3FC 0011933C  4B FC 89 21 */	bl GXSetTexCoordGen2
/* 8011C400 00119340  38 61 00 08 */	addi r3, r1, 8
/* 8011C404 00119344  4B FC DE 9D */	bl PSMTXIdentity
/* 8011C408 00119348  38 61 00 08 */	addi r3, r1, 8
/* 8011C40C 0011934C  38 80 00 1E */	li r4, 0x1e
/* 8011C410 00119350  38 A0 00 01 */	li r5, 1
/* 8011C414 00119354  4B FC D2 39 */	bl GXLoadTexMtxImm
/* 8011C418 00119358  80 7E 00 B8 */	lwz r3, 0xb8(r30)
/* 8011C41C 0011935C  38 80 00 00 */	li r4, 0
/* 8011C420 00119360  4B F1 72 11 */	bl load__10JUTTextureF11_GXTexMapID
/* 8011C424 00119364  7F C3 F3 78 */	mr r3, r30
/* 8011C428 00119368  7F E4 FB 78 */	mr r4, r31
/* 8011C42C 0011936C  48 00 03 D5 */	bl "draw__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FR8Graphics"
.L_8011C430:
/* 8011C430 00119370  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8011C434 00119374  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8011C438 00119378  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 8011C43C 0011937C  7C 08 03 A6 */	mtlr r0
/* 8011C440 00119380  38 21 00 40 */	addi r1, r1, 0x40
/* 8011C444 00119384  4E 80 00 20 */	blr 
.endfn draw__12CarryInfoMgrFR8Graphics

.fn update__12CarryInfoMgrFv, global
/* 8011C448 00119388  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C44C 0011938C  7C 08 02 A6 */	mflr r0
/* 8011C450 00119390  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C454 00119394  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C458 00119398  7C 7F 1B 78 */	mr r31, r3
/* 8011C45C 0011939C  48 00 00 21 */	bl updatePokoInfoOwners__12CarryInfoMgrFv
/* 8011C460 001193A0  7F E3 FB 78 */	mr r3, r31
/* 8011C464 001193A4  48 00 03 11 */	bl "update__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv"
/* 8011C468 001193A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C46C 001193AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C470 001193B0  7C 08 03 A6 */	mtlr r0
/* 8011C474 001193B4  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C478 001193B8  4E 80 00 20 */	blr 
.endfn update__12CarryInfoMgrFv

.fn updatePokoInfoOwners__12CarryInfoMgrFv, global
/* 8011C47C 001193BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011C480 001193C0  7C 08 02 A6 */	mflr r0
/* 8011C484 001193C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011C488 001193C8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011C48C 001193CC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011C490 001193D0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011C494 001193D4  93 81 00 10 */	stw r28, 0x10(r1)
/* 8011C498 001193D8  7C 7C 1B 78 */	mr r28, r3
/* 8011C49C 001193DC  80 63 00 CC */	lwz r3, 0xcc(r3)
/* 8011C4A0 001193E0  28 03 00 00 */	cmplwi r3, 0
/* 8011C4A4 001193E4  41 82 00 08 */	beq .L_8011C4AC
/* 8011C4A8 001193E8  38 63 FF FC */	addi r3, r3, -4
.L_8011C4AC:
/* 8011C4AC 001193EC  7C 7E 1B 78 */	mr r30, r3
/* 8011C4B0 001193F0  48 00 00 AC */	b .L_8011C55C
.L_8011C4B4:
/* 8011C4B4 001193F4  80 9E 00 08 */	lwz r4, 8(r30)
/* 8011C4B8 001193F8  28 04 00 00 */	cmplwi r4, 0
/* 8011C4BC 001193FC  41 82 00 08 */	beq .L_8011C4C4
/* 8011C4C0 00119400  38 84 FF FC */	addi r4, r4, -4
.L_8011C4C4:
/* 8011C4C4 00119404  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8011C4C8 00119408  7C 9D 23 78 */	mr r29, r4
/* 8011C4CC 0011940C  3B E0 00 00 */	li r31, 0
/* 8011C4D0 00119410  81 83 00 00 */	lwz r12, 0(r3)
/* 8011C4D4 00119414  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8011C4D8 00119418  7D 89 03 A6 */	mtctr r12
/* 8011C4DC 0011941C  4E 80 04 21 */	bctrl 
/* 8011C4E0 00119420  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8011C4E4 00119424  40 82 00 14 */	bne .L_8011C4F8
/* 8011C4E8 00119428  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8011C4EC 0011942C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8011C4F0 00119430  7C 00 F0 40 */	cmplw r0, r30
/* 8011C4F4 00119434  41 82 00 0C */	beq .L_8011C500
.L_8011C4F8:
/* 8011C4F8 00119438  3B E0 00 01 */	li r31, 1
/* 8011C4FC 0011943C  48 00 00 34 */	b .L_8011C530
.L_8011C500:
/* 8011C500 00119440  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8011C504 00119444  C0 5E 00 1C */	lfs f2, 0x1c(r30)
/* 8011C508 00119448  C0 23 00 54 */	lfs f1, 0x54(r3)
/* 8011C50C 0011944C  C0 02 98 80 */	lfs f0, lbl_80517BE0@sda21(r2)
/* 8011C510 00119450  EC 22 08 2A */	fadds f1, f2, f1
/* 8011C514 00119454  D0 3E 00 1C */	stfs f1, 0x1c(r30)
/* 8011C518 00119458  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 8011C51C 0011945C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011C520 00119460  40 81 00 10 */	ble .L_8011C530
/* 8011C524 00119464  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8011C528 00119468  38 00 00 01 */	li r0, 1
/* 8011C52C 0011946C  98 03 00 54 */	stb r0, 0x54(r3)
.L_8011C530:
/* 8011C530 00119470  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 8011C534 00119474  41 82 00 24 */	beq .L_8011C558
/* 8011C538 00119478  38 7E 00 04 */	addi r3, r30, 4
/* 8011C53C 0011947C  48 2F 50 95 */	bl del__5CNodeFv
/* 8011C540 00119480  28 1E 00 00 */	cmplwi r30, 0
/* 8011C544 00119484  7F C4 F3 78 */	mr r4, r30
/* 8011C548 00119488  41 82 00 08 */	beq .L_8011C550
/* 8011C54C 0011948C  38 9E 00 04 */	addi r4, r30, 4
.L_8011C550:
/* 8011C550 00119490  38 7C 00 D4 */	addi r3, r28, 0xd4
/* 8011C554 00119494  48 2F 4E B5 */	bl add__5CNodeFP5CNode
.L_8011C558:
/* 8011C558 00119498  7F BE EB 78 */	mr r30, r29
.L_8011C55C:
/* 8011C55C 0011949C  28 1E 00 00 */	cmplwi r30, 0
/* 8011C560 001194A0  40 82 FF 54 */	bne .L_8011C4B4
/* 8011C564 001194A4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011C568 001194A8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011C56C 001194AC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011C570 001194B0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011C574 001194B4  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8011C578 001194B8  7C 08 03 A6 */	mtlr r0
/* 8011C57C 001194BC  38 21 00 20 */	addi r1, r1, 0x20
/* 8011C580 001194C0  4E 80 00 20 */	blr 
.endfn updatePokoInfoOwners__12CarryInfoMgrFv

.fn scratch__12CarryInfoMgrFP14CarryInfoOwner, weak
/* 8011C584 001194C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C588 001194C8  7C 08 02 A6 */	mflr r0
/* 8011C58C 001194CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C590 001194D0  48 00 01 A1 */	bl "scratch__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner"
/* 8011C594 001194D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C598 001194D8  7C 08 03 A6 */	mtlr r0
/* 8011C59C 001194DC  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C5A0 001194E0  4E 80 00 20 */	blr 
.endfn scratch__12CarryInfoMgrFP14CarryInfoOwner

.fn __dt__11InfoMgrBaseFv, weak
/* 8011C5A4 001194E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C5A8 001194E8  7C 08 02 A6 */	mflr r0
/* 8011C5AC 001194EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C5B0 001194F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C5B4 001194F4  7C 7F 1B 79 */	or. r31, r3, r3
/* 8011C5B8 001194F8  41 82 00 1C */	beq .L_8011C5D4
/* 8011C5BC 001194FC  3C A0 80 4B */	lis r5, __vt__11InfoMgrBase@ha
/* 8011C5C0 00119500  7C 80 07 35 */	extsh. r0, r4
/* 8011C5C4 00119504  38 05 C3 84 */	addi r0, r5, __vt__11InfoMgrBase@l
/* 8011C5C8 00119508  90 1F 00 00 */	stw r0, 0(r31)
/* 8011C5CC 0011950C  40 81 00 08 */	ble .L_8011C5D4
/* 8011C5D0 00119510  4B F0 7A E5 */	bl __dl__FPv
.L_8011C5D4:
/* 8011C5D4 00119514  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C5D8 00119518  7F E3 FB 78 */	mr r3, r31
/* 8011C5DC 0011951C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C5E0 00119520  7C 08 03 A6 */	mtlr r0
/* 8011C5E4 00119524  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C5E8 00119528  4E 80 00 20 */	blr 
.endfn __dt__11InfoMgrBaseFv

.fn "init__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv", weak
/* 8011C5EC 0011952C  4E 80 00 20 */	blr 
.endfn "init__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv"

.fn "__dt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv", weak
/* 8011C5F0 00119530  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C5F4 00119534  7C 08 02 A6 */	mflr r0
/* 8011C5F8 00119538  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C5FC 0011953C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C600 00119540  7C 9F 23 78 */	mr r31, r4
/* 8011C604 00119544  93 C1 00 08 */	stw r30, 8(r1)
/* 8011C608 00119548  7C 7E 1B 79 */	or. r30, r3, r3
/* 8011C60C 0011954C  41 82 00 60 */	beq .L_8011C66C
/* 8011C610 00119550  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011C614 00119554  38 03 C3 9C */	addi r0, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011C618 00119558  90 1E 00 00 */	stw r0, 0(r30)
/* 8011C61C 0011955C  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8011C620 00119560  28 03 00 00 */	cmplwi r3, 0
/* 8011C624 00119564  41 82 00 0C */	beq .L_8011C630
/* 8011C628 00119568  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 8011C62C 0011956C  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011C630:
/* 8011C630 00119570  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8011C634 00119574  28 03 00 00 */	cmplwi r3, 0
/* 8011C638 00119578  41 82 00 0C */	beq .L_8011C644
/* 8011C63C 0011957C  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 8011C640 00119580  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011C644:
/* 8011C644 00119584  38 00 00 00 */	li r0, 0
/* 8011C648 00119588  7F C3 F3 78 */	mr r3, r30
/* 8011C64C 0011958C  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011C650 00119590  38 80 00 00 */	li r4, 0
/* 8011C654 00119594  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8011C658 00119598  4B F0 09 DD */	bl __dt__11JKRDisposerFv
/* 8011C65C 0011959C  7F E0 07 35 */	extsh. r0, r31
/* 8011C660 001195A0  40 81 00 0C */	ble .L_8011C66C
/* 8011C664 001195A4  7F C3 F3 78 */	mr r3, r30
/* 8011C668 001195A8  4B F0 7A 4D */	bl __dl__FPv
.L_8011C66C:
/* 8011C66C 001195AC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C670 001195B0  7F C3 F3 78 */	mr r3, r30
/* 8011C674 001195B4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C678 001195B8  83 C1 00 08 */	lwz r30, 8(r1)
/* 8011C67C 001195BC  7C 08 03 A6 */	mtlr r0
/* 8011C680 001195C0  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C684 001195C4  4E 80 00 20 */	blr 
.endfn "__dt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv"

.fn __dt__13CarryInfoListFv, weak
/* 8011C688 001195C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C68C 001195CC  7C 08 02 A6 */	mflr r0
/* 8011C690 001195D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C694 001195D4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C698 001195D8  7C 9F 23 78 */	mr r31, r4
/* 8011C69C 001195DC  93 C1 00 08 */	stw r30, 8(r1)
/* 8011C6A0 001195E0  7C 7E 1B 79 */	or. r30, r3, r3
/* 8011C6A4 001195E4  41 82 00 70 */	beq .L_8011C714
/* 8011C6A8 001195E8  3C 60 80 4B */	lis r3, __vt__13CarryInfoList@ha
/* 8011C6AC 001195EC  38 03 C4 04 */	addi r0, r3, __vt__13CarryInfoList@l
/* 8011C6B0 001195F0  90 1E 00 00 */	stw r0, 0(r30)
/* 8011C6B4 001195F4  41 82 00 50 */	beq .L_8011C704
/* 8011C6B8 001195F8  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011C6BC 001195FC  38 03 C3 9C */	addi r0, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011C6C0 00119600  90 1E 00 00 */	stw r0, 0(r30)
/* 8011C6C4 00119604  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8011C6C8 00119608  28 03 00 00 */	cmplwi r3, 0
/* 8011C6CC 0011960C  41 82 00 0C */	beq .L_8011C6D8
/* 8011C6D0 00119610  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 8011C6D4 00119614  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011C6D8:
/* 8011C6D8 00119618  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8011C6DC 0011961C  28 03 00 00 */	cmplwi r3, 0
/* 8011C6E0 00119620  41 82 00 0C */	beq .L_8011C6EC
/* 8011C6E4 00119624  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 8011C6E8 00119628  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011C6EC:
/* 8011C6EC 0011962C  38 00 00 00 */	li r0, 0
/* 8011C6F0 00119630  7F C3 F3 78 */	mr r3, r30
/* 8011C6F4 00119634  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011C6F8 00119638  38 80 00 00 */	li r4, 0
/* 8011C6FC 0011963C  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8011C700 00119640  4B F0 09 35 */	bl __dt__11JKRDisposerFv
.L_8011C704:
/* 8011C704 00119644  7F E0 07 35 */	extsh. r0, r31
/* 8011C708 00119648  40 81 00 0C */	ble .L_8011C714
/* 8011C70C 0011964C  7F C3 F3 78 */	mr r3, r30
/* 8011C710 00119650  4B F0 79 A5 */	bl __dl__FPv
.L_8011C714:
/* 8011C714 00119654  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C718 00119658  7F C3 F3 78 */	mr r3, r30
/* 8011C71C 0011965C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C720 00119660  83 C1 00 08 */	lwz r30, 8(r1)
/* 8011C724 00119664  7C 08 03 A6 */	mtlr r0
/* 8011C728 00119668  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C72C 0011966C  4E 80 00 20 */	blr 
.endfn __dt__13CarryInfoListFv

.fn "scratch__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner", weak
/* 8011C730 00119670  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C734 00119674  7C 08 02 A6 */	mflr r0
/* 8011C738 00119678  7C 85 23 78 */	mr r5, r4
/* 8011C73C 0011967C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C740 00119680  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C744 00119684  7C 7F 1B 78 */	mr r31, r3
/* 8011C748 00119688  80 83 00 20 */	lwz r4, 0x20(r3)
/* 8011C74C 0011968C  48 00 01 1D */	bl "search__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoListP14CarryInfoOwner"
/* 8011C750 00119690  7C 64 1B 79 */	or. r4, r3, r3
/* 8011C754 00119694  41 82 00 0C */	beq .L_8011C760
/* 8011C758 00119698  7F E3 FB 78 */	mr r3, r31
/* 8011C75C 0011969C  48 00 01 41 */	bl "addInactiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList"
.L_8011C760:
/* 8011C760 001196A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C764 001196A4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C768 001196A8  7C 08 03 A6 */	mtlr r0
/* 8011C76C 001196AC  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C770 001196B0  4E 80 00 20 */	blr 
.endfn "scratch__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner"

.fn "update__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv", weak
/* 8011C774 001196B4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011C778 001196B8  7C 08 02 A6 */	mflr r0
/* 8011C77C 001196BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011C780 001196C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011C784 001196C4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011C788 001196C8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011C78C 001196CC  7C 7D 1B 78 */	mr r29, r3
/* 8011C790 001196D0  83 E3 00 20 */	lwz r31, 0x20(r3)
/* 8011C794 001196D4  48 00 00 48 */	b .L_8011C7DC
.L_8011C798:
/* 8011C798 001196D8  7F E3 FB 78 */	mr r3, r31
/* 8011C79C 001196DC  83 DF 00 1C */	lwz r30, 0x1c(r31)
/* 8011C7A0 001196E0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011C7A4 001196E4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8011C7A8 001196E8  7D 89 03 A6 */	mtctr r12
/* 8011C7AC 001196EC  4E 80 04 21 */	bctrl 
/* 8011C7B0 001196F0  7F E3 FB 78 */	mr r3, r31
/* 8011C7B4 001196F4  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011C7B8 001196F8  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8011C7BC 001196FC  7D 89 03 A6 */	mtctr r12
/* 8011C7C0 00119700  4E 80 04 21 */	bctrl 
/* 8011C7C4 00119704  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8011C7C8 00119708  41 82 00 10 */	beq .L_8011C7D8
/* 8011C7CC 0011970C  7F A3 EB 78 */	mr r3, r29
/* 8011C7D0 00119710  7F E4 FB 78 */	mr r4, r31
/* 8011C7D4 00119714  48 00 00 C9 */	bl "addInactiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList"
.L_8011C7D8:
/* 8011C7D8 00119718  7F DF F3 78 */	mr r31, r30
.L_8011C7DC:
/* 8011C7DC 0011971C  28 1F 00 00 */	cmplwi r31, 0
/* 8011C7E0 00119720  40 82 FF B8 */	bne .L_8011C798
/* 8011C7E4 00119724  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011C7E8 00119728  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011C7EC 0011972C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011C7F0 00119730  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011C7F4 00119734  7C 08 03 A6 */	mtlr r0
/* 8011C7F8 00119738  38 21 00 20 */	addi r1, r1, 0x20
/* 8011C7FC 0011973C  4E 80 00 20 */	blr 
.endfn "update__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fv"

.fn "draw__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FR8Graphics", weak
/* 8011C800 00119740  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C804 00119744  7C 08 02 A6 */	mflr r0
/* 8011C808 00119748  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C80C 0011974C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C810 00119750  93 C1 00 08 */	stw r30, 8(r1)
/* 8011C814 00119754  7C 9E 23 78 */	mr r30, r4
/* 8011C818 00119758  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8011C81C 0011975C  28 00 00 00 */	cmplwi r0, 0
/* 8011C820 00119760  41 82 00 30 */	beq .L_8011C850
/* 8011C824 00119764  7C 1F 03 78 */	mr r31, r0
/* 8011C828 00119768  48 00 00 20 */	b .L_8011C848
.L_8011C82C:
/* 8011C82C 0011976C  7F E3 FB 78 */	mr r3, r31
/* 8011C830 00119770  7F C4 F3 78 */	mr r4, r30
/* 8011C834 00119774  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011C838 00119778  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8011C83C 0011977C  7D 89 03 A6 */	mtctr r12
/* 8011C840 00119780  4E 80 04 21 */	bctrl 
/* 8011C844 00119784  83 FF 00 1C */	lwz r31, 0x1c(r31)
.L_8011C848:
/* 8011C848 00119788  28 1F 00 00 */	cmplwi r31, 0
/* 8011C84C 0011978C  40 82 FF E0 */	bne .L_8011C82C
.L_8011C850:
/* 8011C850 00119790  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C854 00119794  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C858 00119798  83 C1 00 08 */	lwz r30, 8(r1)
/* 8011C85C 0011979C  7C 08 03 A6 */	mtlr r0
/* 8011C860 001197A0  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C864 001197A4  4E 80 00 20 */	blr 
.endfn "draw__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FR8Graphics"

.fn "search__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoListP14CarryInfoOwner", weak
/* 8011C868 001197A8  48 00 00 1C */	b .L_8011C884
.L_8011C86C:
/* 8011C86C 001197AC  80 04 00 20 */	lwz r0, 0x20(r4)
/* 8011C870 001197B0  7C 00 28 40 */	cmplw r0, r5
/* 8011C874 001197B4  40 82 00 0C */	bne .L_8011C880
/* 8011C878 001197B8  7C 83 23 78 */	mr r3, r4
/* 8011C87C 001197BC  4E 80 00 20 */	blr 
.L_8011C880:
/* 8011C880 001197C0  80 84 00 1C */	lwz r4, 0x1c(r4)
.L_8011C884:
/* 8011C884 001197C4  28 04 00 00 */	cmplwi r4, 0
/* 8011C888 001197C8  40 82 FF E4 */	bne .L_8011C86C
/* 8011C88C 001197CC  38 60 00 00 */	li r3, 0
/* 8011C890 001197D0  4E 80 00 20 */	blr 
.endfn "search__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoListP14CarryInfoOwner"

.fn "update__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv", weak
/* 8011C894 001197D4  4E 80 00 20 */	blr 
.endfn "update__46InfoListBase<14CarryInfoOwner,13CarryInfoList>Fv"

.fn "draw__46InfoListBase<14CarryInfoOwner,13CarryInfoList>FR8Graphics", weak
/* 8011C898 001197D8  4E 80 00 20 */	blr 
.endfn "draw__46InfoListBase<14CarryInfoOwner,13CarryInfoList>FR8Graphics"

.fn "addInactiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList", weak
/* 8011C89C 001197DC  38 00 00 00 */	li r0, 0
/* 8011C8A0 001197E0  90 04 00 20 */	stw r0, 0x20(r4)
/* 8011C8A4 001197E4  80 A4 00 18 */	lwz r5, 0x18(r4)
/* 8011C8A8 001197E8  28 05 00 00 */	cmplwi r5, 0
/* 8011C8AC 001197EC  41 82 00 0C */	beq .L_8011C8B8
/* 8011C8B0 001197F0  80 04 00 1C */	lwz r0, 0x1c(r4)
/* 8011C8B4 001197F4  90 05 00 1C */	stw r0, 0x1c(r5)
.L_8011C8B8:
/* 8011C8B8 001197F8  80 A4 00 1C */	lwz r5, 0x1c(r4)
/* 8011C8BC 001197FC  28 05 00 00 */	cmplwi r5, 0
/* 8011C8C0 00119800  41 82 00 0C */	beq .L_8011C8CC
/* 8011C8C4 00119804  80 04 00 18 */	lwz r0, 0x18(r4)
/* 8011C8C8 00119808  90 05 00 18 */	stw r0, 0x18(r5)
.L_8011C8CC:
/* 8011C8CC 0011980C  38 A0 00 00 */	li r5, 0
/* 8011C8D0 00119810  38 03 00 5C */	addi r0, r3, 0x5c
/* 8011C8D4 00119814  90 A4 00 1C */	stw r5, 0x1c(r4)
/* 8011C8D8 00119818  90 A4 00 18 */	stw r5, 0x18(r4)
/* 8011C8DC 0011981C  90 04 00 18 */	stw r0, 0x18(r4)
/* 8011C8E0 00119820  80 03 00 78 */	lwz r0, 0x78(r3)
/* 8011C8E4 00119824  90 04 00 1C */	stw r0, 0x1c(r4)
/* 8011C8E8 00119828  80 A3 00 78 */	lwz r5, 0x78(r3)
/* 8011C8EC 0011982C  28 05 00 00 */	cmplwi r5, 0
/* 8011C8F0 00119830  41 82 00 08 */	beq .L_8011C8F8
/* 8011C8F4 00119834  90 85 00 18 */	stw r4, 0x18(r5)
.L_8011C8F8:
/* 8011C8F8 00119838  90 83 00 78 */	stw r4, 0x78(r3)
/* 8011C8FC 0011983C  4E 80 00 20 */	blr 
.endfn "addInactiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList"

.fn "regist__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner", weak
/* 8011C900 00119840  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011C904 00119844  7C 08 02 A6 */	mflr r0
/* 8011C908 00119848  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011C90C 0011984C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011C910 00119850  80 A3 00 20 */	lwz r5, 0x20(r3)
/* 8011C914 00119854  48 00 00 18 */	b .L_8011C92C
.L_8011C918:
/* 8011C918 00119858  80 05 00 20 */	lwz r0, 0x20(r5)
/* 8011C91C 0011985C  7C 00 20 40 */	cmplw r0, r4
/* 8011C920 00119860  40 82 00 08 */	bne .L_8011C928
/* 8011C924 00119864  48 00 00 14 */	b .L_8011C938
.L_8011C928:
/* 8011C928 00119868  80 A5 00 1C */	lwz r5, 0x1c(r5)
.L_8011C92C:
/* 8011C92C 0011986C  28 05 00 00 */	cmplwi r5, 0
/* 8011C930 00119870  40 82 FF E8 */	bne .L_8011C918
/* 8011C934 00119874  38 A0 00 00 */	li r5, 0
.L_8011C938:
/* 8011C938 00119878  28 05 00 00 */	cmplwi r5, 0
/* 8011C93C 0011987C  7C BF 2B 78 */	mr r31, r5
/* 8011C940 00119880  40 82 00 08 */	bne .L_8011C948
/* 8011C944 00119884  83 E3 00 78 */	lwz r31, 0x78(r3)
.L_8011C948:
/* 8011C948 00119888  28 1F 00 00 */	cmplwi r31, 0
/* 8011C94C 0011988C  41 82 00 10 */	beq .L_8011C95C
/* 8011C950 00119890  90 9F 00 20 */	stw r4, 0x20(r31)
/* 8011C954 00119894  7F E4 FB 78 */	mr r4, r31
/* 8011C958 00119898  48 00 02 FD */	bl "addActiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList"
.L_8011C95C:
/* 8011C95C 0011989C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011C960 001198A0  7F E3 FB 78 */	mr r3, r31
/* 8011C964 001198A4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011C968 001198A8  7C 08 03 A6 */	mtlr r0
/* 8011C96C 001198AC  38 21 00 10 */	addi r1, r1, 0x10
/* 8011C970 001198B0  4E 80 00 20 */	blr 
.endfn "regist__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP14CarryInfoOwner"

.fn "__ct__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fi", weak
/* 8011C974 001198B4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011C978 001198B8  7C 08 02 A6 */	mflr r0
/* 8011C97C 001198BC  3C A0 80 4B */	lis r5, __vt__11InfoMgrBase@ha
/* 8011C980 001198C0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011C984 001198C4  38 05 C3 84 */	addi r0, r5, __vt__11InfoMgrBase@l
/* 8011C988 001198C8  BF 41 00 08 */	stmw r26, 8(r1)
/* 8011C98C 001198CC  7C 7C 1B 78 */	mr r28, r3
/* 8011C990 001198D0  3C 60 80 4B */	lis r3, "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011C994 001198D4  7C 9E 23 78 */	mr r30, r4
/* 8011C998 001198D8  3B 5C 00 04 */	addi r26, r28, 4
/* 8011C99C 001198DC  90 1C 00 00 */	stw r0, 0(r28)
/* 8011C9A0 001198E0  38 03 C3 B8 */	addi r0, r3, "__vt__41InfoMgr<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011C9A4 001198E4  7F 43 D3 78 */	mr r3, r26
/* 8011C9A8 001198E8  90 1C 00 00 */	stw r0, 0(r28)
/* 8011C9AC 001198EC  4B F0 06 21 */	bl __ct__11JKRDisposerFv
/* 8011C9B0 001198F0  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011C9B4 001198F4  38 00 00 00 */	li r0, 0
/* 8011C9B8 001198F8  38 83 C3 9C */	addi r4, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011C9BC 001198FC  7F 43 D3 78 */	mr r3, r26
/* 8011C9C0 00119900  90 9A 00 00 */	stw r4, 0(r26)
/* 8011C9C4 00119904  90 1A 00 20 */	stw r0, 0x20(r26)
/* 8011C9C8 00119908  90 1A 00 1C */	stw r0, 0x1c(r26)
/* 8011C9CC 0011990C  90 1A 00 18 */	stw r0, 0x18(r26)
/* 8011C9D0 00119910  81 9A 00 00 */	lwz r12, 0(r26)
/* 8011C9D4 00119914  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8011C9D8 00119918  7D 89 03 A6 */	mtctr r12
/* 8011C9DC 0011991C  4E 80 04 21 */	bctrl 
/* 8011C9E0 00119920  3C 60 80 4B */	lis r3, __vt__13CarryInfoList@ha
/* 8011C9E4 00119924  38 A0 00 00 */	li r5, 0
/* 8011C9E8 00119928  38 03 C4 04 */	addi r0, r3, __vt__13CarryInfoList@l
/* 8011C9EC 0011992C  C0 22 98 88 */	lfs f1, lbl_80517BE8@sda21(r2)
/* 8011C9F0 00119930  90 1A 00 00 */	stw r0, 0(r26)
/* 8011C9F4 00119934  3C 60 80 51 */	lis r3, "zero__10Vector3<f>"@ha
/* 8011C9F8 00119938  3B E3 41 E4 */	addi r31, r3, "zero__10Vector3<f>"@l
/* 8011C9FC 0011993C  3B 7C 00 5C */	addi r27, r28, 0x5c
/* 8011CA00 00119940  90 BA 00 24 */	stw r5, 0x24(r26)
/* 8011CA04 00119944  38 80 00 06 */	li r4, 6
/* 8011CA08 00119948  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011CA0C 0011994C  38 00 00 02 */	li r0, 2
/* 8011CA10 00119950  C0 5F 00 00 */	lfs f2, 0(r31)
/* 8011CA14 00119954  7F 63 DB 78 */	mr r3, r27
/* 8011CA18 00119958  D0 5A 00 28 */	stfs f2, 0x28(r26)
/* 8011CA1C 0011995C  C0 5F 00 04 */	lfs f2, 4(r31)
/* 8011CA20 00119960  D0 5A 00 2C */	stfs f2, 0x2c(r26)
/* 8011CA24 00119964  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8011CA28 00119968  D0 5A 00 30 */	stfs f2, 0x30(r26)
/* 8011CA2C 0011996C  D0 3A 00 34 */	stfs f1, 0x34(r26)
/* 8011CA30 00119970  98 BA 00 38 */	stb r5, 0x38(r26)
/* 8011CA34 00119974  98 9A 00 39 */	stb r4, 0x39(r26)
/* 8011CA38 00119978  B0 BA 00 3A */	sth r5, 0x3a(r26)
/* 8011CA3C 0011997C  B0 BA 00 3C */	sth r5, 0x3c(r26)
/* 8011CA40 00119980  90 BA 00 40 */	stw r5, 0x40(r26)
/* 8011CA44 00119984  90 BA 00 44 */	stw r5, 0x44(r26)
/* 8011CA48 00119988  D0 1A 00 48 */	stfs f0, 0x48(r26)
/* 8011CA4C 0011998C  D0 1A 00 4C */	stfs f0, 0x4c(r26)
/* 8011CA50 00119990  98 1A 00 54 */	stb r0, 0x54(r26)
/* 8011CA54 00119994  98 BA 00 55 */	stb r5, 0x55(r26)
/* 8011CA58 00119998  98 BA 00 56 */	stb r5, 0x56(r26)
/* 8011CA5C 0011999C  4B F0 05 71 */	bl __ct__11JKRDisposerFv
/* 8011CA60 001199A0  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011CA64 001199A4  38 00 00 00 */	li r0, 0
/* 8011CA68 001199A8  38 83 C3 9C */	addi r4, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011CA6C 001199AC  7F 63 DB 78 */	mr r3, r27
/* 8011CA70 001199B0  90 9B 00 00 */	stw r4, 0(r27)
/* 8011CA74 001199B4  90 1B 00 20 */	stw r0, 0x20(r27)
/* 8011CA78 001199B8  90 1B 00 1C */	stw r0, 0x1c(r27)
/* 8011CA7C 001199BC  90 1B 00 18 */	stw r0, 0x18(r27)
/* 8011CA80 001199C0  81 9B 00 00 */	lwz r12, 0(r27)
/* 8011CA84 001199C4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8011CA88 001199C8  7D 89 03 A6 */	mtctr r12
/* 8011CA8C 001199CC  4E 80 04 21 */	bctrl 
/* 8011CA90 001199D0  3C 80 80 4B */	lis r4, __vt__13CarryInfoList@ha
/* 8011CA94 001199D4  38 A0 00 00 */	li r5, 0
/* 8011CA98 001199D8  38 04 C4 04 */	addi r0, r4, __vt__13CarryInfoList@l
/* 8011CA9C 001199DC  3C 60 80 51 */	lis r3, "zero__10Vector3<f>"@ha
/* 8011CAA0 001199E0  90 1B 00 00 */	stw r0, 0(r27)
/* 8011CAA4 001199E4  38 83 41 E4 */	addi r4, r3, "zero__10Vector3<f>"@l
/* 8011CAA8 001199E8  C0 22 98 88 */	lfs f1, lbl_80517BE8@sda21(r2)
/* 8011CAAC 001199EC  38 60 00 06 */	li r3, 6
/* 8011CAB0 001199F0  90 BB 00 24 */	stw r5, 0x24(r27)
/* 8011CAB4 001199F4  38 00 00 02 */	li r0, 2
/* 8011CAB8 001199F8  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011CABC 001199FC  7F 7A DB 78 */	mr r26, r27
/* 8011CAC0 00119A00  C0 44 00 00 */	lfs f2, 0(r4)
/* 8011CAC4 00119A04  3B A0 00 00 */	li r29, 0
/* 8011CAC8 00119A08  D0 5B 00 28 */	stfs f2, 0x28(r27)
/* 8011CACC 00119A0C  C0 5F 00 04 */	lfs f2, 4(r31)
/* 8011CAD0 00119A10  D0 5B 00 2C */	stfs f2, 0x2c(r27)
/* 8011CAD4 00119A14  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8011CAD8 00119A18  D0 5B 00 30 */	stfs f2, 0x30(r27)
/* 8011CADC 00119A1C  D0 3B 00 34 */	stfs f1, 0x34(r27)
/* 8011CAE0 00119A20  98 BB 00 38 */	stb r5, 0x38(r27)
/* 8011CAE4 00119A24  98 7B 00 39 */	stb r3, 0x39(r27)
/* 8011CAE8 00119A28  B0 BB 00 3A */	sth r5, 0x3a(r27)
/* 8011CAEC 00119A2C  B0 BB 00 3C */	sth r5, 0x3c(r27)
/* 8011CAF0 00119A30  90 BB 00 40 */	stw r5, 0x40(r27)
/* 8011CAF4 00119A34  90 BB 00 44 */	stw r5, 0x44(r27)
/* 8011CAF8 00119A38  D0 1B 00 48 */	stfs f0, 0x48(r27)
/* 8011CAFC 00119A3C  D0 1B 00 4C */	stfs f0, 0x4c(r27)
/* 8011CB00 00119A40  98 1B 00 54 */	stb r0, 0x54(r27)
/* 8011CB04 00119A44  98 BB 00 55 */	stb r5, 0x55(r27)
/* 8011CB08 00119A48  98 BB 00 56 */	stb r5, 0x56(r27)
/* 8011CB0C 00119A4C  93 DC 00 B4 */	stw r30, 0xb4(r28)
/* 8011CB10 00119A50  48 00 01 20 */	b .L_8011CC30
.L_8011CB14:
/* 8011CB14 00119A54  38 60 00 58 */	li r3, 0x58
/* 8011CB18 00119A58  4B F0 73 8D */	bl __nw__FUl
/* 8011CB1C 00119A5C  7C 7E 1B 79 */	or. r30, r3, r3
/* 8011CB20 00119A60  41 82 00 B0 */	beq .L_8011CBD0
/* 8011CB24 00119A64  7F DB F3 78 */	mr r27, r30
/* 8011CB28 00119A68  4B F0 04 A5 */	bl __ct__11JKRDisposerFv
/* 8011CB2C 00119A6C  3C 60 80 4B */	lis r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@ha
/* 8011CB30 00119A70  38 00 00 00 */	li r0, 0
/* 8011CB34 00119A74  38 83 C3 9C */	addi r4, r3, "__vt__46InfoListBase<14CarryInfoOwner,13CarryInfoList>"@l
/* 8011CB38 00119A78  7F 63 DB 78 */	mr r3, r27
/* 8011CB3C 00119A7C  90 9B 00 00 */	stw r4, 0(r27)
/* 8011CB40 00119A80  90 1B 00 20 */	stw r0, 0x20(r27)
/* 8011CB44 00119A84  90 1B 00 1C */	stw r0, 0x1c(r27)
/* 8011CB48 00119A88  90 1B 00 18 */	stw r0, 0x18(r27)
/* 8011CB4C 00119A8C  81 9B 00 00 */	lwz r12, 0(r27)
/* 8011CB50 00119A90  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8011CB54 00119A94  7D 89 03 A6 */	mtctr r12
/* 8011CB58 00119A98  4E 80 04 21 */	bctrl 
/* 8011CB5C 00119A9C  3C 80 80 4B */	lis r4, __vt__13CarryInfoList@ha
/* 8011CB60 00119AA0  3C 60 80 51 */	lis r3, "zero__10Vector3<f>"@ha
/* 8011CB64 00119AA4  38 04 C4 04 */	addi r0, r4, __vt__13CarryInfoList@l
/* 8011CB68 00119AA8  38 A0 00 00 */	li r5, 0
/* 8011CB6C 00119AAC  90 1E 00 00 */	stw r0, 0(r30)
/* 8011CB70 00119AB0  38 83 41 E4 */	addi r4, r3, "zero__10Vector3<f>"@l
/* 8011CB74 00119AB4  C0 22 98 88 */	lfs f1, lbl_80517BE8@sda21(r2)
/* 8011CB78 00119AB8  38 60 00 06 */	li r3, 6
/* 8011CB7C 00119ABC  90 BE 00 24 */	stw r5, 0x24(r30)
/* 8011CB80 00119AC0  38 00 00 02 */	li r0, 2
/* 8011CB84 00119AC4  C0 02 98 00 */	lfs f0, lbl_80517B60@sda21(r2)
/* 8011CB88 00119AC8  C0 44 00 00 */	lfs f2, 0(r4)
/* 8011CB8C 00119ACC  D0 5E 00 28 */	stfs f2, 0x28(r30)
/* 8011CB90 00119AD0  C0 5F 00 04 */	lfs f2, 4(r31)
/* 8011CB94 00119AD4  D0 5E 00 2C */	stfs f2, 0x2c(r30)
/* 8011CB98 00119AD8  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8011CB9C 00119ADC  D0 5E 00 30 */	stfs f2, 0x30(r30)
/* 8011CBA0 00119AE0  D0 3E 00 34 */	stfs f1, 0x34(r30)
/* 8011CBA4 00119AE4  98 BE 00 38 */	stb r5, 0x38(r30)
/* 8011CBA8 00119AE8  98 7E 00 39 */	stb r3, 0x39(r30)
/* 8011CBAC 00119AEC  B0 BE 00 3A */	sth r5, 0x3a(r30)
/* 8011CBB0 00119AF0  B0 BE 00 3C */	sth r5, 0x3c(r30)
/* 8011CBB4 00119AF4  90 BE 00 40 */	stw r5, 0x40(r30)
/* 8011CBB8 00119AF8  90 BE 00 44 */	stw r5, 0x44(r30)
/* 8011CBBC 00119AFC  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 8011CBC0 00119B00  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 8011CBC4 00119B04  98 1E 00 54 */	stb r0, 0x54(r30)
/* 8011CBC8 00119B08  98 BE 00 55 */	stb r5, 0x55(r30)
/* 8011CBCC 00119B0C  98 BE 00 56 */	stb r5, 0x56(r30)
.L_8011CBD0:
/* 8011CBD0 00119B10  38 00 00 00 */	li r0, 0
/* 8011CBD4 00119B14  90 1E 00 20 */	stw r0, 0x20(r30)
/* 8011CBD8 00119B18  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8011CBDC 00119B1C  28 03 00 00 */	cmplwi r3, 0
/* 8011CBE0 00119B20  41 82 00 0C */	beq .L_8011CBEC
/* 8011CBE4 00119B24  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 8011CBE8 00119B28  90 03 00 1C */	stw r0, 0x1c(r3)
.L_8011CBEC:
/* 8011CBEC 00119B2C  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8011CBF0 00119B30  28 03 00 00 */	cmplwi r3, 0
/* 8011CBF4 00119B34  41 82 00 0C */	beq .L_8011CC00
/* 8011CBF8 00119B38  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 8011CBFC 00119B3C  90 03 00 18 */	stw r0, 0x18(r3)
.L_8011CC00:
/* 8011CC00 00119B40  38 00 00 00 */	li r0, 0
/* 8011CC04 00119B44  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011CC08 00119B48  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8011CC0C 00119B4C  93 5E 00 18 */	stw r26, 0x18(r30)
/* 8011CC10 00119B50  80 1C 00 78 */	lwz r0, 0x78(r28)
/* 8011CC14 00119B54  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011CC18 00119B58  80 7C 00 78 */	lwz r3, 0x78(r28)
/* 8011CC1C 00119B5C  28 03 00 00 */	cmplwi r3, 0
/* 8011CC20 00119B60  41 82 00 08 */	beq .L_8011CC28
/* 8011CC24 00119B64  93 C3 00 18 */	stw r30, 0x18(r3)
.L_8011CC28:
/* 8011CC28 00119B68  93 DC 00 78 */	stw r30, 0x78(r28)
/* 8011CC2C 00119B6C  3B BD 00 01 */	addi r29, r29, 1
.L_8011CC30:
/* 8011CC30 00119B70  80 1C 00 B4 */	lwz r0, 0xb4(r28)
/* 8011CC34 00119B74  7C 1D 00 00 */	cmpw r29, r0
/* 8011CC38 00119B78  41 80 FE DC */	blt .L_8011CB14
/* 8011CC3C 00119B7C  7F 83 E3 78 */	mr r3, r28
/* 8011CC40 00119B80  BB 41 00 08 */	lmw r26, 8(r1)
/* 8011CC44 00119B84  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011CC48 00119B88  7C 08 03 A6 */	mtlr r0
/* 8011CC4C 00119B8C  38 21 00 20 */	addi r1, r1, 0x20
/* 8011CC50 00119B90  4E 80 00 20 */	blr 
.endfn "__ct__41InfoMgr<14CarryInfoOwner,13CarryInfoList>Fi"

.fn "addActiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList", weak
/* 8011CC54 00119B94  80 A4 00 18 */	lwz r5, 0x18(r4)
/* 8011CC58 00119B98  28 05 00 00 */	cmplwi r5, 0
/* 8011CC5C 00119B9C  41 82 00 0C */	beq .L_8011CC68
/* 8011CC60 00119BA0  80 04 00 1C */	lwz r0, 0x1c(r4)
/* 8011CC64 00119BA4  90 05 00 1C */	stw r0, 0x1c(r5)
.L_8011CC68:
/* 8011CC68 00119BA8  80 A4 00 1C */	lwz r5, 0x1c(r4)
/* 8011CC6C 00119BAC  28 05 00 00 */	cmplwi r5, 0
/* 8011CC70 00119BB0  41 82 00 0C */	beq .L_8011CC7C
/* 8011CC74 00119BB4  80 04 00 18 */	lwz r0, 0x18(r4)
/* 8011CC78 00119BB8  90 05 00 18 */	stw r0, 0x18(r5)
.L_8011CC7C:
/* 8011CC7C 00119BBC  38 A0 00 00 */	li r5, 0
/* 8011CC80 00119BC0  38 03 00 04 */	addi r0, r3, 4
/* 8011CC84 00119BC4  90 A4 00 1C */	stw r5, 0x1c(r4)
/* 8011CC88 00119BC8  90 A4 00 18 */	stw r5, 0x18(r4)
/* 8011CC8C 00119BCC  90 04 00 18 */	stw r0, 0x18(r4)
/* 8011CC90 00119BD0  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8011CC94 00119BD4  90 04 00 1C */	stw r0, 0x1c(r4)
/* 8011CC98 00119BD8  80 A3 00 20 */	lwz r5, 0x20(r3)
/* 8011CC9C 00119BDC  28 05 00 00 */	cmplwi r5, 0
/* 8011CCA0 00119BE0  41 82 00 08 */	beq .L_8011CCA8
/* 8011CCA4 00119BE4  90 85 00 18 */	stw r4, 0x18(r5)
.L_8011CCA8:
/* 8011CCA8 00119BE8  90 83 00 20 */	stw r4, 0x20(r3)
/* 8011CCAC 00119BEC  4E 80 00 20 */	blr 
.endfn "addActiveList__41InfoMgr<14CarryInfoOwner,13CarryInfoList>FP13CarryInfoList"

.fn __sinit_carryInfoMgr_cpp, local
/* 8011CCB0 00119BF0  3C 80 80 51 */	lis r4, __float_nan@ha
/* 8011CCB4 00119BF4  38 00 FF FF */	li r0, -1
/* 8011CCB8 00119BF8  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 8011CCBC 00119BFC  3C 60 80 4B */	lis r3, govNAN___Q24Game5P2JST@ha
/* 8011CCC0 00119C00  90 0D 92 10 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 8011CCC4 00119C04  D4 03 C3 20 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 8011CCC8 00119C08  D0 0D 92 14 */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 8011CCCC 00119C0C  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011CCD0 00119C10  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011CCD4 00119C14  4E 80 00 20 */	blr 
.endfn __sinit_carryInfoMgr_cpp

.fn "@4@__dt__13PokoInfoOwnerFv", weak
/* 8011CCD8 00119C18  38 63 FF FC */	addi r3, r3, -4
/* 8011CCDC 00119C1C  4B FF F0 8C */	b __dt__13PokoInfoOwnerFv
.endfn "@4@__dt__13PokoInfoOwnerFv"
