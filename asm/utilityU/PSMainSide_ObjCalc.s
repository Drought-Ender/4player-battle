.include "macros.inc"
.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8049E1C8, local
	.asciz "PSMainSide_ObjCalc.cpp"
.endobj lbl_8049E1C8
.balign 4
.obj lbl_8049E1E0, local
	.asciz "P2Assert"
.endobj lbl_8049E1E0
.balign 4
.obj lbl_8049E1EC, local
	.4byte 0x82A082E8
	.4byte 0x82A682C8
	.4byte 0x82A28350
	.4byte 0x815B8358
    .asciz "1"
.endobj lbl_8049E1EC
.balign 4
.obj lbl_8049E200, local
	.4byte 0x82A082E8
	.4byte 0x82A682C8
	.4byte 0x82A28350
	.4byte 0x815B8358
    .asciz "2"
.endobj lbl_8049E200

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj __vt__Q23PSM14ObjCalc_2PGame, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q23PSM14ObjCalc_2PGameFv
	.4byte getPlayerNo__Q23PSM14ObjCalc_2PGameFPQ23PSM8Creature
	.4byte getPlayerNo__Q23PSM14ObjCalc_2PGameFR3Vec
	.4byte setMode__Q23PSM11ObjCalcBaseFQ33PSM11ObjCalcBase4Mode
	.4byte is1PGame__Q23PSM14ObjCalc_2PGameFv
.endobj __vt__Q23PSM14ObjCalc_2PGame
.obj __vt__Q23PSM18ObjCalc_SingleGame, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q23PSM18ObjCalc_SingleGameFv
	.4byte getPlayerNo__Q23PSM18ObjCalc_SingleGameFPQ23PSM8Creature
	.4byte getPlayerNo__Q23PSM18ObjCalc_SingleGameFR3Vec
	.4byte setMode__Q23PSM11ObjCalcBaseFQ33PSM11ObjCalcBase4Mode
	.4byte is1PGame__Q23PSM11ObjCalcBaseFv
.endobj __vt__Q23PSM18ObjCalc_SingleGame

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_80520E28, local
	.float 100000.0
	.float 1000000.0
.endobj lbl_80520E28

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn newInstance_SingleGame__Q23PSM18ObjCalc_SingleGameFv, global
/* 804728A4 0046F7E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 804728A8 0046F7E8  7C 08 02 A6 */	mflr r0
/* 804728AC 0046F7EC  38 60 00 0C */	li r3, 0xc
/* 804728B0 0046F7F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 804728B4 0046F7F4  4B BB 15 F1 */	bl __nw__FUl
/* 804728B8 0046F7F8  28 03 00 00 */	cmplwi r3, 0
/* 804728BC 0046F7FC  41 82 00 38 */	beq .L_804728F4
/* 804728C0 0046F800  3C 80 80 4F */	lis r4, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@ha
/* 804728C4 0046F804  3C A0 80 4F */	lis r5, __vt__Q23PSM11ObjCalcBase@ha
/* 804728C8 0046F808  38 04 F5 5C */	addi r0, r4, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@l
/* 804728CC 0046F80C  3C 80 80 4F */	lis r4, __vt__Q23PSM18ObjCalc_SingleGame@ha
/* 804728D0 0046F810  90 03 00 00 */	stw r0, 0(r3)
/* 804728D4 0046F814  38 C5 F5 68 */	addi r6, r5, __vt__Q23PSM11ObjCalcBase@l
/* 804728D8 0046F818  38 A0 00 00 */	li r5, 0
/* 804728DC 0046F81C  38 04 FB EC */	addi r0, r4, __vt__Q23PSM18ObjCalc_SingleGame@l
/* 804728E0 0046F820  90 6D 91 B4 */	stw r3, "sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13)
/* 804728E4 0046F824  90 C3 00 00 */	stw r6, 0(r3)
/* 804728E8 0046F828  90 A3 00 04 */	stw r5, 4(r3)
/* 804728EC 0046F82C  90 03 00 00 */	stw r0, 0(r3)
/* 804728F0 0046F830  98 A3 00 08 */	stb r5, 8(r3)
.L_804728F4:
/* 804728F4 0046F834  80 01 00 14 */	lwz r0, 0x14(r1)
/* 804728F8 0046F838  7C 08 03 A6 */	mtlr r0
/* 804728FC 0046F83C  38 21 00 10 */	addi r1, r1, 0x10
/* 80472900 0046F840  4E 80 00 20 */	blr 
.endfn newInstance_SingleGame__Q23PSM18ObjCalc_SingleGameFv

.fn getPlayerNo__Q23PSM18ObjCalc_SingleGameFPQ23PSM8Creature, global
/* 80472904 0046F844  88 63 00 08 */	lbz r3, 8(r3)
/* 80472908 0046F848  4E 80 00 20 */	blr 
.endfn getPlayerNo__Q23PSM18ObjCalc_SingleGameFPQ23PSM8Creature

.fn getPlayerNo__Q23PSM18ObjCalc_SingleGameFR3Vec, global
/* 8047290C 0046F84C  88 63 00 08 */	lbz r3, 8(r3)
/* 80472910 0046F850  4E 80 00 20 */	blr 
.endfn getPlayerNo__Q23PSM18ObjCalc_SingleGameFR3Vec

.fn newInstance_2PGame__Q23PSM14ObjCalc_2PGameFv, global
/* 80472914 0046F854  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80472918 0046F858  7C 08 02 A6 */	mflr r0
/* 8047291C 0046F85C  38 60 00 08 */	li r3, 8
/* 80472920 0046F860  90 01 00 14 */	stw r0, 0x14(r1)
/* 80472924 0046F864  4B BB 15 81 */	bl __nw__FUl
/* 80472928 0046F868  28 03 00 00 */	cmplwi r3, 0
/* 8047292C 0046F86C  41 82 00 34 */	beq .L_80472960
/* 80472930 0046F870  3C 80 80 4F */	lis r4, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@ha
/* 80472934 0046F874  3C A0 80 4F */	lis r5, __vt__Q23PSM11ObjCalcBase@ha
/* 80472938 0046F878  38 04 F5 5C */	addi r0, r4, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@l
/* 8047293C 0046F87C  3C 80 80 4F */	lis r4, __vt__Q23PSM14ObjCalc_2PGame@ha
/* 80472940 0046F880  90 03 00 00 */	stw r0, 0(r3)
/* 80472944 0046F884  38 C5 F5 68 */	addi r6, r5, __vt__Q23PSM11ObjCalcBase@l
/* 80472948 0046F888  38 A0 00 00 */	li r5, 0
/* 8047294C 0046F88C  38 04 FB D0 */	addi r0, r4, __vt__Q23PSM14ObjCalc_2PGame@l
/* 80472950 0046F890  90 6D 91 B4 */	stw r3, "sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13)
/* 80472954 0046F894  90 C3 00 00 */	stw r6, 0(r3)
/* 80472958 0046F898  90 A3 00 04 */	stw r5, 4(r3)
/* 8047295C 0046F89C  90 03 00 00 */	stw r0, 0(r3)
.L_80472960:
/* 80472960 0046F8A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80472964 0046F8A4  7C 08 03 A6 */	mtlr r0
/* 80472968 0046F8A8  38 21 00 10 */	addi r1, r1, 0x10
/* 8047296C 0046F8AC  4E 80 00 20 */	blr 
.endfn newInstance_2PGame__Q23PSM14ObjCalc_2PGameFv

.fn getPlayerNo__Q23PSM14ObjCalc_2PGameFPQ23PSM8Creature, global
/* 80472D2C 0046FC6C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80472D30 0046FC70  7C 08 02 A6 */	mflr r0
/* 80472D34 0046FC74  90 01 00 24 */	stw r0, 0x24(r1)
/* 80472D38 0046FC78  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80472D3C 0046FC7C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80472D40 0046FC80  7C 9E 23 79 */	or. r30, r4, r4
/* 80472D44 0046FC84  3C 80 80 4A */	lis r4, lbl_8049E1C8@ha
/* 80472D48 0046FC88  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80472D4C 0046FC8C  7C 7D 1B 78 */	mr r29, r3
/* 80472D50 0046FC90  3B E4 E1 C8 */	addi r31, r4, lbl_8049E1C8@l
/* 80472D54 0046FC94  40 82 00 18 */	bne .L_80472D6C
/* 80472D58 0046FC98  38 7F 00 00 */	addi r3, r31, 0
/* 80472D5C 0046FC9C  38 BF 00 18 */	addi r5, r31, 0x18
/* 80472D60 0046FCA0  38 80 00 57 */	li r4, 0x57
/* 80472D64 0046FCA4  4C C6 31 82 */	crclr 6
/* 80472D68 0046FCA8  4B BB 78 D9 */	bl panic_f__12JUTExceptionFPCciPCce
.L_80472D6C:
/* 80472D6C 0046FCAC  80 1D 00 04 */	lwz r0, 4(r29)
/* 80472D70 0046FCB0  2C 00 00 01 */	cmpwi r0, 1
/* 80472D74 0046FCB4  41 82 00 14 */	beq .L_80472D88
/* 80472D78 0046FCB8  40 80 00 34 */	bge .L_80472DAC
/* 80472D7C 0046FCBC  2C 00 00 00 */	cmpwi r0, 0
/* 80472D80 0046FCC0  40 80 00 10 */	bge .L_80472D90
/* 80472D84 0046FCC4  48 00 00 28 */	b .L_80472DAC
.L_80472D88:
/* 80472D88 0046FCC8  38 60 00 00 */	li r3, 0
/* 80472D8C 0046FCCC  48 00 00 4C */	b .L_80472DD8
.L_80472D90:
/* 80472D90 0046FCD0  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 80472D94 0046FCD4  81 83 00 00 */	lwz r12, 0(r3)
/* 80472D98 0046FCD8  81 8C 00 FC */	lwz r12, 0xfc(r12)
/* 80472D9C 0046FCDC  7D 89 03 A6 */	mtctr r12
/* 80472DA0 0046FCE0  4E 80 04 21 */	bctrl 
/* 80472DA4 0046FCE4  88 63 00 01 */	lbz r3, 1(r3)
/* 80472DA8 0046FCE8  48 00 00 30 */	b .L_80472DD8
.L_80472DAC:
/* 80472DAC 0046FCEC  38 7F 00 00 */	addi r3, r31, 0
/* 80472DB0 0046FCF0  38 BF 00 24 */	addi r5, r31, 0x24
/* 80472DB4 0046FCF4  38 80 00 7D */	li r4, 0x7d
/* 80472DB8 0046FCF8  4C C6 31 82 */	crclr 6
/* 80472DBC 0046FCFC  4B BB 78 85 */	bl panic_f__12JUTExceptionFPCciPCce
/* 80472DC0 0046FD00  38 7F 00 00 */	addi r3, r31, 0
/* 80472DC4 0046FD04  38 BF 00 38 */	addi r5, r31, 0x38
/* 80472DC8 0046FD08  38 80 00 80 */	li r4, 0x80
/* 80472DCC 0046FD0C  4C C6 31 82 */	crclr 6
/* 80472DD0 0046FD10  4B BB 78 71 */	bl panic_f__12JUTExceptionFPCciPCce
/* 80472DD4 0046FD14  38 60 00 00 */	li r3, 0
.L_80472DD8:
/* 80472DD8 0046FD18  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80472DDC 0046FD1C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80472DE0 0046FD20  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80472DE4 0046FD24  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80472DE8 0046FD28  7C 08 03 A6 */	mtlr r0
/* 80472DEC 0046FD2C  38 21 00 20 */	addi r1, r1, 0x20
/* 80472DF0 0046FD30  4E 80 00 20 */	blr 
.endfn getPlayerNo__Q23PSM14ObjCalc_2PGameFPQ23PSM8Creature

.fn __dt__Q23PSM18ObjCalc_SingleGameFv, weak
/* 80472DF4 0046FD34  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80472DF8 0046FD38  7C 08 02 A6 */	mflr r0
/* 80472DFC 0046FD3C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80472E00 0046FD40  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80472E04 0046FD44  7C 7F 1B 79 */	or. r31, r3, r3
/* 80472E08 0046FD48  41 82 00 48 */	beq .L_80472E50
/* 80472E0C 0046FD4C  3C 60 80 4F */	lis r3, __vt__Q23PSM18ObjCalc_SingleGame@ha
/* 80472E10 0046FD50  38 03 FB EC */	addi r0, r3, __vt__Q23PSM18ObjCalc_SingleGame@l
/* 80472E14 0046FD54  90 1F 00 00 */	stw r0, 0(r31)
/* 80472E18 0046FD58  41 82 00 28 */	beq .L_80472E40
/* 80472E1C 0046FD5C  3C 60 80 4F */	lis r3, __vt__Q23PSM11ObjCalcBase@ha
/* 80472E20 0046FD60  38 03 F5 68 */	addi r0, r3, __vt__Q23PSM11ObjCalcBase@l
/* 80472E24 0046FD64  90 1F 00 00 */	stw r0, 0(r31)
/* 80472E28 0046FD68  41 82 00 18 */	beq .L_80472E40
/* 80472E2C 0046FD6C  3C 60 80 4F */	lis r3, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@ha
/* 80472E30 0046FD70  38 00 00 00 */	li r0, 0
/* 80472E34 0046FD74  38 63 F5 5C */	addi r3, r3, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@l
/* 80472E38 0046FD78  90 7F 00 00 */	stw r3, 0(r31)
/* 80472E3C 0046FD7C  90 0D 91 B4 */	stw r0, "sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13)
.L_80472E40:
/* 80472E40 0046FD80  7C 80 07 35 */	extsh. r0, r4
/* 80472E44 0046FD84  40 81 00 0C */	ble .L_80472E50
/* 80472E48 0046FD88  7F E3 FB 78 */	mr r3, r31
/* 80472E4C 0046FD8C  4B BB 12 69 */	bl __dl__FPv
.L_80472E50:
/* 80472E50 0046FD90  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80472E54 0046FD94  7F E3 FB 78 */	mr r3, r31
/* 80472E58 0046FD98  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80472E5C 0046FD9C  7C 08 03 A6 */	mtlr r0
/* 80472E60 0046FDA0  38 21 00 10 */	addi r1, r1, 0x10
/* 80472E64 0046FDA4  4E 80 00 20 */	blr 
.endfn __dt__Q23PSM18ObjCalc_SingleGameFv

.fn __dt__Q23PSM14ObjCalc_2PGameFv, weak
/* 80472E68 0046FDA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80472E6C 0046FDAC  7C 08 02 A6 */	mflr r0
/* 80472E70 0046FDB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80472E74 0046FDB4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80472E78 0046FDB8  7C 7F 1B 79 */	or. r31, r3, r3
/* 80472E7C 0046FDBC  41 82 00 48 */	beq .L_80472EC4
/* 80472E80 0046FDC0  3C 60 80 4F */	lis r3, __vt__Q23PSM14ObjCalc_2PGame@ha
/* 80472E84 0046FDC4  38 03 FB D0 */	addi r0, r3, __vt__Q23PSM14ObjCalc_2PGame@l
/* 80472E88 0046FDC8  90 1F 00 00 */	stw r0, 0(r31)
/* 80472E8C 0046FDCC  41 82 00 28 */	beq .L_80472EB4
/* 80472E90 0046FDD0  3C 60 80 4F */	lis r3, __vt__Q23PSM11ObjCalcBase@ha
/* 80472E94 0046FDD4  38 03 F5 68 */	addi r0, r3, __vt__Q23PSM11ObjCalcBase@l
/* 80472E98 0046FDD8  90 1F 00 00 */	stw r0, 0(r31)
/* 80472E9C 0046FDDC  41 82 00 18 */	beq .L_80472EB4
/* 80472EA0 0046FDE0  3C 60 80 4F */	lis r3, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@ha
/* 80472EA4 0046FDE4  38 00 00 00 */	li r0, 0
/* 80472EA8 0046FDE8  38 63 F5 5C */	addi r3, r3, "__vt__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@l
/* 80472EAC 0046FDEC  90 7F 00 00 */	stw r3, 0(r31)
/* 80472EB0 0046FDF0  90 0D 91 B4 */	stw r0, "sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13)
.L_80472EB4:
/* 80472EB4 0046FDF4  7C 80 07 35 */	extsh. r0, r4
/* 80472EB8 0046FDF8  40 81 00 0C */	ble .L_80472EC4
/* 80472EBC 0046FDFC  7F E3 FB 78 */	mr r3, r31
/* 80472EC0 0046FE00  4B BB 11 F5 */	bl __dl__FPv
.L_80472EC4:
/* 80472EC4 0046FE04  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80472EC8 0046FE08  7F E3 FB 78 */	mr r3, r31
/* 80472ECC 0046FE0C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80472ED0 0046FE10  7C 08 03 A6 */	mtlr r0
/* 80472ED4 0046FE14  38 21 00 10 */	addi r1, r1, 0x10
/* 80472ED8 0046FE18  4E 80 00 20 */	blr 
.endfn __dt__Q23PSM14ObjCalc_2PGameFv

.fn is1PGame__Q23PSM14ObjCalc_2PGameFv, weak
/* 80472EDC 0046FE1C  38 60 00 00 */	li r3, 0
/* 80472EE0 0046FE20  4E 80 00 20 */	blr 
.endfn is1PGame__Q23PSM14ObjCalc_2PGameFv
