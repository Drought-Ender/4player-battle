.include "macros.inc"

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
lbl_805197CC:
	.4byte 0x00000000
lbl_805197E0:
	.4byte 0xBF800000
lbl_805197E4:
	.float 1.0

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.global makeTrMatrix__Q34Game12ItemPikihead4ItemFv
makeTrMatrix__Q34Game12ItemPikihead4ItemFv:
/* 801D9EFC 001D6E3C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801D9F00 001D6E40  7C 08 02 A6 */	mflr r0
/* 801D9F04 001D6E44  90 01 00 14 */	stw r0, 0x14(r1)
/* 801D9F08 001D6E48  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801D9F0C 001D6E4C  7C 7F 1B 78 */	mr r31, r3
/* 801D9F10 001D6E50  48 00 28 F5 */	bl "getStateID__Q24Game89FSMItem<Q34Game12ItemPikihead4Item,Q34Game12ItemPikihead3FSM,Q34Game12ItemPikihead5State>Fv"
/* 801D9F14 001D6E54  2C 03 00 00 */	cmpwi r3, 0
/* 801D9F18 001D6E58  40 82 01 C8 */	bne .L_801DA0E0
/* 801D9F1C 001D6E5C  C0 FF 01 90 */	lfs f7, 0x190(r31)
/* 801D9F20 001D6E60  C0 7F 01 94 */	lfs f3, 0x194(r31)
/* 801D9F24 001D6E64  EC 07 01 F2 */	fmuls f0, f7, f7
/* 801D9F28 001D6E68  C0 9F 01 98 */	lfs f4, 0x198(r31)
/* 801D9F2C 001D6E6C  EC 43 00 F2 */	fmuls f2, f3, f3
/* 801D9F30 001D6E70  C0 22 B4 6C */	lfs f1, lbl_805197CC@sda21(r2)
/* 801D9F34 001D6E74  EC A4 01 32 */	fmuls f5, f4, f4
/* 801D9F38 001D6E78  EC 00 10 2A */	fadds f0, f0, f2
/* 801D9F3C 001D6E7C  EC 05 00 2A */	fadds f0, f5, f0
/* 801D9F40 001D6E80  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 801D9F44 001D6E84  40 81 00 20 */	ble .L_801D9F64
/* 801D9F48 001D6E88  EC 07 11 FA */	fmadds f0, f7, f7, f2
/* 801D9F4C 001D6E8C  EC 05 00 2A */	fadds f0, f5, f0
/* 801D9F50 001D6E90  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 801D9F54 001D6E94  40 81 00 14 */	ble .L_801D9F68
/* 801D9F58 001D6E98  FC 20 00 34 */	frsqrte f1, f0
/* 801D9F5C 001D6E9C  EC 01 00 32 */	fmuls f0, f1, f0
/* 801D9F60 001D6EA0  48 00 00 08 */	b .L_801D9F68
.L_801D9F64:
/* 801D9F64 001D6EA4  FC 00 08 90 */	fmr f0, f1
.L_801D9F68:
/* 801D9F68 001D6EA8  C0 22 B4 6C */	lfs f1, lbl_805197CC@sda21(r2)
/* 801D9F6C 001D6EAC  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 801D9F70 001D6EB0  40 81 01 70 */	ble .L_801DA0E0
/* 801D9F74 001D6EB4  EC 03 00 F2 */	fmuls f0, f3, f3
/* 801D9F78 001D6EB8  EC 44 01 32 */	fmuls f2, f4, f4
/* 801D9F7C 001D6EBC  EC 07 01 FA */	fmadds f0, f7, f7, f0
/* 801D9F80 001D6EC0  EC 42 00 2A */	fadds f2, f2, f0
/* 801D9F84 001D6EC4  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 801D9F88 001D6EC8  40 81 00 14 */	ble .L_801D9F9C
/* 801D9F8C 001D6ECC  40 81 00 14 */	ble .L_801D9FA0
/* 801D9F90 001D6ED0  FC 00 10 34 */	frsqrte f0, f2
/* 801D9F94 001D6ED4  EC 40 00 B2 */	fmuls f2, f0, f2
/* 801D9F98 001D6ED8  48 00 00 08 */	b .L_801D9FA0
.L_801D9F9C:
/* 801D9F9C 001D6EDC  FC 40 08 90 */	fmr f2, f1
.L_801D9FA0:
/* 801D9FA0 001D6EE0  C0 02 B4 6C */	lfs f0, lbl_805197CC@sda21(r2)
/* 801D9FA4 001D6EE4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 801D9FA8 001D6EE8  40 81 00 18 */	ble .L_801D9FC0
/* 801D9FAC 001D6EEC  C0 02 B4 84 */	lfs f0, lbl_805197E4@sda21(r2)
/* 801D9FB0 001D6EF0  EC 00 10 24 */	fdivs f0, f0, f2
/* 801D9FB4 001D6EF4  EC E7 00 32 */	fmuls f7, f7, f0
/* 801D9FB8 001D6EF8  EC 63 00 32 */	fmuls f3, f3, f0
/* 801D9FBC 001D6EFC  EC 84 00 32 */	fmuls f4, f4, f0
.L_801D9FC0:
/* 801D9FC0 001D6F00  C0 02 B4 80 */	lfs f0, lbl_805197E0@sda21(r2)
/* 801D9FC4 001D6F04  C0 C2 B4 6C */	lfs f6, lbl_805197CC@sda21(r2)
/* 801D9FC8 001D6F08  EC 84 00 32 */	fmuls f4, f4, f0
/* 801D9FCC 001D6F0C  C0 A2 B4 84 */	lfs f5, lbl_805197E4@sda21(r2)
/* 801D9FD0 001D6F10  EC 63 00 32 */	fmuls f3, f3, f0
/* 801D9FD4 001D6F14  EC 47 00 32 */	fmuls f2, f7, f0
/* 801D9FD8 001D6F18  EC E4 01 B2 */	fmuls f7, f4, f6
/* 801D9FDC 001D6F1C  EC 23 01 B2 */	fmuls f1, f3, f6
/* 801D9FE0 001D6F20  EC 02 39 7C */	fnmsubs f0, f2, f5, f7
/* 801D9FE4 001D6F24  ED 23 39 78 */	fmsubs f9, f3, f5, f7
/* 801D9FE8 001D6F28  EC 22 09 B8 */	fmsubs f1, f2, f6, f1
/* 801D9FEC 001D6F2C  EC A0 00 32 */	fmuls f5, f0, f0
/* 801D9FF0 001D6F30  EC E1 00 72 */	fmuls f7, f1, f1
/* 801D9FF4 001D6F34  EC A9 2A 7A */	fmadds f5, f9, f9, f5
/* 801D9FF8 001D6F38  EC E7 28 2A */	fadds f7, f7, f5
/* 801D9FFC 001D6F3C  FC 07 30 40 */	fcmpo cr0, f7, f6
/* 801DA000 001D6F40  40 81 00 14 */	ble .L_801DA014
/* 801DA004 001D6F44  40 81 00 14 */	ble .L_801DA018
/* 801DA008 001D6F48  FC A0 38 34 */	frsqrte f5, f7
/* 801DA00C 001D6F4C  EC E5 01 F2 */	fmuls f7, f5, f7
/* 801DA010 001D6F50  48 00 00 08 */	b .L_801DA018
.L_801DA014:
/* 801DA014 001D6F54  FC E0 30 90 */	fmr f7, f6
.L_801DA018:
/* 801DA018 001D6F58  C0 A2 B4 6C */	lfs f5, lbl_805197CC@sda21(r2)
/* 801DA01C 001D6F5C  FC 07 28 40 */	fcmpo cr0, f7, f5
/* 801DA020 001D6F60  40 81 00 18 */	ble .L_801DA038
/* 801DA024 001D6F64  C0 A2 B4 84 */	lfs f5, lbl_805197E4@sda21(r2)
/* 801DA028 001D6F68  EC A5 38 24 */	fdivs f5, f5, f7
/* 801DA02C 001D6F6C  ED 29 01 72 */	fmuls f9, f9, f5
/* 801DA030 001D6F70  EC 00 01 72 */	fmuls f0, f0, f5
/* 801DA034 001D6F74  EC 21 01 72 */	fmuls f1, f1, f5
.L_801DA038:
/* 801DA038 001D6F78  EC E9 01 32 */	fmuls f7, f9, f4
/* 801DA03C 001D6F7C  C0 A2 B4 6C */	lfs f5, lbl_805197CC@sda21(r2)
/* 801DA040 001D6F80  ED 01 00 F2 */	fmuls f8, f1, f3
/* 801DA044 001D6F84  EC C0 00 B2 */	fmuls f6, f0, f2
/* 801DA048 001D6F88  ED 41 38 B8 */	fmsubs f10, f1, f2, f7
/* 801DA04C 001D6F8C  ED 00 41 38 */	fmsubs f8, f0, f4, f8
/* 801DA050 001D6F90  ED 69 30 F8 */	fmsubs f11, f9, f3, f6
/* 801DA054 001D6F94  EC CA 02 B2 */	fmuls f6, f10, f10
/* 801DA058 001D6F98  EC EB 02 F2 */	fmuls f7, f11, f11
/* 801DA05C 001D6F9C  EC C8 32 3A */	fmadds f6, f8, f8, f6
/* 801DA060 001D6FA0  EC C7 30 2A */	fadds f6, f7, f6
/* 801DA064 001D6FA4  FC 06 28 40 */	fcmpo cr0, f6, f5
/* 801DA068 001D6FA8  40 81 00 14 */	ble .L_801DA07C
/* 801DA06C 001D6FAC  40 81 00 14 */	ble .L_801DA080
/* 801DA070 001D6FB0  FC A0 30 34 */	frsqrte f5, f6
/* 801DA074 001D6FB4  EC C5 01 B2 */	fmuls f6, f5, f6
/* 801DA078 001D6FB8  48 00 00 08 */	b .L_801DA080
.L_801DA07C:
/* 801DA07C 001D6FBC  FC C0 28 90 */	fmr f6, f5
.L_801DA080:
/* 801DA080 001D6FC0  C0 A2 B4 6C */	lfs f5, lbl_805197CC@sda21(r2)
/* 801DA084 001D6FC4  FC 06 28 40 */	fcmpo cr0, f6, f5
/* 801DA088 001D6FC8  40 81 00 18 */	ble .L_801DA0A0
/* 801DA08C 001D6FCC  C0 A2 B4 84 */	lfs f5, lbl_805197E4@sda21(r2)
/* 801DA090 001D6FD0  EC A5 30 24 */	fdivs f5, f5, f6
/* 801DA094 001D6FD4  ED 08 01 72 */	fmuls f8, f8, f5
/* 801DA098 001D6FD8  ED 4A 01 72 */	fmuls f10, f10, f5
/* 801DA09C 001D6FDC  ED 6B 01 72 */	fmuls f11, f11, f5
.L_801DA0A0:
/* 801DA0A0 001D6FE0  D1 3F 01 38 */	stfs f9, 0x138(r31)
/* 801DA0A4 001D6FE4  D0 1F 01 48 */	stfs f0, 0x148(r31)
/* 801DA0A8 001D6FE8  D0 3F 01 58 */	stfs f1, 0x158(r31)
/* 801DA0AC 001D6FEC  D0 5F 01 3C */	stfs f2, 0x13c(r31)
/* 801DA0B0 001D6FF0  D0 7F 01 4C */	stfs f3, 0x14c(r31)
/* 801DA0B4 001D6FF4  D0 9F 01 5C */	stfs f4, 0x15c(r31)
/* 801DA0B8 001D6FF8  D1 1F 01 40 */	stfs f8, 0x140(r31)
/* 801DA0BC 001D6FFC  D1 5F 01 50 */	stfs f10, 0x150(r31)
/* 801DA0C0 001D7000  D1 7F 01 60 */	stfs f11, 0x160(r31)
/* 801DA0C4 001D7004  C0 1F 01 9C */	lfs f0, 0x19c(r31)
/* 801DA0C8 001D7008  D0 1F 01 44 */	stfs f0, 0x144(r31)
/* 801DA0CC 001D700C  C0 1F 01 A0 */	lfs f0, 0x1a0(r31)
/* 801DA0D0 001D7010  D0 1F 01 54 */	stfs f0, 0x154(r31)
/* 801DA0D4 001D7014  C0 1F 01 A4 */	lfs f0, 0x1a4(r31)
/* 801DA0D8 001D7018  D0 1F 01 64 */	stfs f0, 0x164(r31)
/* 801DA0DC 001D701C  48 00 00 0C */	b .L_801DA0E8
.L_801DA0E0:
/* 801DA0E0 001D7020  7F E3 FB 78 */	mr r3, r31
/* 801DA0E4 001D7024  4B FF 23 A1 */	bl makeTrMatrix__Q24Game8BaseItemFv
.L_801DA0E8:
/* 801DA0E8 001D7028  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801DA0EC 001D702C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801DA0F0 001D7030  7C 08 03 A6 */	mtlr r0
/* 801DA0F4 001D7034  38 21 00 10 */	addi r1, r1, 0x10
/* 801DA0F8 001D7038  4E 80 00 20 */	blr 

.global changeMaterial__Q34Game12ItemPikihead4ItemFv
changeMaterial__Q34Game12ItemPikihead4ItemFv:
/* 801DA23C 001D717C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801DA240 001D7180  7C 08 02 A6 */	mflr r0
/* 801DA244 001D7184  90 01 00 24 */	stw r0, 0x24(r1)
/* 801DA248 001D7188  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801DA24C 001D718C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801DA250 001D7190  7C 7E 1B 78 */	mr r30, r3
/* 801DA254 001D7194  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801DA258 001D7198  93 81 00 10 */	stw r28, 0x10(r1)
/* 801DA25C 001D719C  80 63 01 74 */	lwz r3, 0x174(r3)
/* 801DA260 001D71A0  80 63 00 08 */	lwz r3, 8(r3)
/* 801DA264 001D71A4  80 63 00 04 */	lwz r3, 4(r3)
/* 801DA268 001D71A8  80 63 00 60 */	lwz r3, 0x60(r3)
/* 801DA26C 001D71AC  80 C3 00 00 */	lwz r6, 0(r3)
/* 801DA270 001D71B0  28 06 00 00 */	cmplwi r6, 0
/* 801DA274 001D71B4  41 82 00 54 */	beq .L_801DA2C8
/* 801DA278 001D71B8  A0 9E 01 F4 */	lhz r4, 0x1f4(r30)
/* 801DA27C 001D71BC  3C 60 80 51 */	lis r3, pikiColors__Q24Game4Piki@ha
/* 801DA280 001D71C0  38 03 22 8C */	addi r0, r3, pikiColors__Q24Game4Piki@l
/* 801DA284 001D71C4  38 A1 00 08 */	addi r5, r1, 8
/* 801DA288 001D71C8  54 83 10 3A */	slwi r3, r4, 2
/* 801DA28C 001D71CC  38 80 00 00 */	li r4, 0
/* 801DA290 001D71D0  7D 20 1A 14 */	add r9, r0, r3
/* 801DA294 001D71D4  88 69 00 01 */	lbz r3, 1(r9)
/* 801DA298 001D71D8  88 E9 00 02 */	lbz r7, 2(r9)
/* 801DA29C 001D71DC  89 09 00 03 */	lbz r8, 3(r9)
/* 801DA2A0 001D71E0  88 09 00 00 */	lbz r0, 0(r9)
/* 801DA2A4 001D71E4  B0 61 00 0A */	sth r3, 0xa(r1)
/* 801DA2A8 001D71E8  B0 01 00 08 */	sth r0, 8(r1)
/* 801DA2AC 001D71EC  B0 E1 00 0C */	sth r7, 0xc(r1)
/* 801DA2B0 001D71F0  B1 01 00 0E */	sth r8, 0xe(r1)
/* 801DA2B4 001D71F4  80 66 00 2C */	lwz r3, 0x2c(r6)
/* 801DA2B8 001D71F8  81 83 00 00 */	lwz r12, 0(r3)
/* 801DA2BC 001D71FC  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 801DA2C0 001D7200  7D 89 03 A6 */	mtctr r12
/* 801DA2C4 001D7204  4E 80 04 21 */	bctrl 
.L_801DA2C8:
/* 801DA2C8 001D7208  80 7E 01 74 */	lwz r3, 0x174(r30)
/* 801DA2CC 001D720C  80 63 00 08 */	lwz r3, 8(r3)
/* 801DA2D0 001D7210  81 83 00 00 */	lwz r12, 0(r3)
/* 801DA2D4 001D7214  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801DA2D8 001D7218  7D 89 03 A6 */	mtctr r12
/* 801DA2DC 001D721C  4E 80 04 21 */	bctrl 
/* 801DA2E0 001D7220  3B E0 00 00 */	li r31, 0
/* 801DA2E4 001D7224  48 00 00 68 */	b .L_801DA34C
.L_801DA2E8:
/* 801DA2E8 001D7228  80 65 00 C0 */	lwz r3, 0xc0(r5)
/* 801DA2EC 001D722C  57 E0 32 B2 */	rlwinm r0, r31, 6, 0xa, 0x19
/* 801DA2F0 001D7230  57 FC 04 3E */	clrlwi r28, r31, 0x10
/* 801DA2F4 001D7234  7F A3 02 14 */	add r29, r3, r0
/* 801DA2F8 001D7238  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 801DA2FC 001D723C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 801DA300 001D7240  28 00 00 00 */	cmplwi r0, 0
/* 801DA304 001D7244  41 82 00 44 */	beq .L_801DA348
/* 801DA308 001D7248  7F A3 EB 78 */	mr r3, r29
/* 801DA30C 001D724C  4B E8 5B 09 */	bl beginDiff__12J3DMatPacketFv
/* 801DA310 001D7250  80 7E 01 74 */	lwz r3, 0x174(r30)
/* 801DA314 001D7254  57 80 10 3A */	slwi r0, r28, 2
/* 801DA318 001D7258  3C 80 01 00 */	lis r4, 0x100
/* 801DA31C 001D725C  80 63 00 08 */	lwz r3, 8(r3)
/* 801DA320 001D7260  80 63 00 04 */	lwz r3, 4(r3)
/* 801DA324 001D7264  80 63 00 60 */	lwz r3, 0x60(r3)
/* 801DA328 001D7268  7C 63 00 2E */	lwzx r3, r3, r0
/* 801DA32C 001D726C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 801DA330 001D7270  81 83 00 00 */	lwz r12, 0(r3)
/* 801DA334 001D7274  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801DA338 001D7278  7D 89 03 A6 */	mtctr r12
/* 801DA33C 001D727C  4E 80 04 21 */	bctrl 
/* 801DA340 001D7280  7F A3 EB 78 */	mr r3, r29
/* 801DA344 001D7284  4B E8 5B 35 */	bl endDiff__12J3DMatPacketFv
.L_801DA348:
/* 801DA348 001D7288  3B FF 00 01 */	addi r31, r31, 1
.L_801DA34C:
/* 801DA34C 001D728C  80 9E 01 74 */	lwz r4, 0x174(r30)
/* 801DA350 001D7290  57 E3 04 3E */	clrlwi r3, r31, 0x10
/* 801DA354 001D7294  80 A4 00 08 */	lwz r5, 8(r4)
/* 801DA358 001D7298  80 85 00 04 */	lwz r4, 4(r5)
/* 801DA35C 001D729C  A0 04 00 5C */	lhz r0, 0x5c(r4)
/* 801DA360 001D72A0  7C 03 00 40 */	cmplw r3, r0
/* 801DA364 001D72A4  41 80 FF 84 */	blt .L_801DA2E8
/* 801DA368 001D72A8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801DA36C 001D72AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801DA370 001D72B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801DA374 001D72B4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801DA378 001D72B8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 801DA37C 001D72BC  7C 08 03 A6 */	mtlr r0
/* 801DA380 001D72C0  38 21 00 20 */	addi r1, r1, 0x20
/* 801DA384 001D72C4  4E 80 00 20 */	blr 
