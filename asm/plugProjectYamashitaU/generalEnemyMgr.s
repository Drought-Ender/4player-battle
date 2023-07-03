.include "macros.inc"
.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8047AA70, local
	.asciz "enemyBase"
.endobj lbl_8047AA70
.balign 4
.obj lbl_8047AA7C, local # Shift-JIS
	.4byte 0x837D836C
	.4byte 0x815B8357
	.4byte 0x8383836D
	.4byte 0x815B8368
	.byte 0
.endobj lbl_8047AA7C
.balign 4
.obj lbl_8047AA90, local
	.asciz "GeneralEnemyMgr"
.endobj lbl_8047AA90
.balign 4
.obj lbl_8047AAA0, local # Shift-JIS
	.4byte 0x9347837D
	.4byte 0x836C815B
	.4byte 0x83578383
	.byte 0
.endobj lbl_8047AAA0
.balign 4
.obj lbl_8047AAB0, local
	.asciz "enemyHeap"
.endobj lbl_8047AAB0
.balign 4
.obj lbl_8047AABC, local
	.asciz "generalEnemyMgr.cpp"
.endobj lbl_8047AABC
.balign 4
.obj lbl_8047AAD0, local
	.asciz "P2Assert"
.endobj lbl_8047AAD0
.balign 4
.obj lbl_8047AADC, local
	.asciz "/enemy/parm/enemyParms.szs"
.endobj lbl_8047AADC
.balign 4
.obj lbl_8047AAF8, local
	.asciz "allocateEnemys"
.endobj lbl_8047AAF8
.balign 4
.obj lbl_8047AB08, local
	.asciz "EnemyKillArg"
.endobj lbl_8047AB08
.balign 4
.obj lbl_8047AB18, local
	.asciz "CreatureKillArg"
.endobj lbl_8047AB18

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj __vt__Q24Game15GeneralEnemyMgr, global
	.4byte 0
	.4byte 0
	.4byte doAnimation__Q24Game15GeneralEnemyMgrFv
	.4byte doEntry__Q24Game15GeneralEnemyMgrFv
	.4byte doSetView__Q24Game15GeneralEnemyMgrFi
	.4byte doViewCalc__Q24Game15GeneralEnemyMgrFv
	.4byte doSimulation__Q24Game15GeneralEnemyMgrFf
	.4byte doDirectDraw__Q24Game15GeneralEnemyMgrFR8Graphics
	.4byte doSimpleDraw__Q24Game15GeneralEnemyMgrFP8Viewport
	.4byte loadResources__16GenericObjectMgrFv
	.4byte resetMgr__16GenericObjectMgrFv
	.4byte pausable__16GenericObjectMgrFv
	.4byte frozenable__16GenericObjectMgrFv
	.4byte getMatrixLoadType__16GenericObjectMgrFv
	.4byte 0
	.4byte 0
	.4byte "@4@__dt__Q24Game15GeneralEnemyMgrFv"
	.4byte getChildCount__5CNodeFv
	.4byte __dt__Q24Game15GeneralEnemyMgrFv
.endobj __vt__Q24Game15GeneralEnemyMgr
.obj __vt__Q24Game12EnemyMgrNode, weak
	.4byte 0
	.4byte 0
	.4byte __dt__Q24Game12EnemyMgrNodeFv
	.4byte getChildCount__5CNodeFv
	.4byte 0
	.4byte 0
	.4byte "@24@doAnimation__Q24Game12EnemyMgrNodeFv"
	.4byte "@24@doEntry__Q24Game12EnemyMgrNodeFv"
	.4byte "@24@doSetView__Q24Game12EnemyMgrNodeFi"
	.4byte "@24@doViewCalc__Q24Game12EnemyMgrNodeFv"
	.4byte "@24@doSimulation__Q24Game12EnemyMgrNodeFf"
	.4byte "@24@doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics"
	.4byte "@24@doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport"
	.4byte loadResources__16GenericObjectMgrFv
	.4byte resetMgr__16GenericObjectMgrFv
	.4byte pausable__16GenericObjectMgrFv
	.4byte frozenable__16GenericObjectMgrFv
	.4byte "@24@getMatrixLoadType__Q24Game12EnemyMgrNodeFv"
	.4byte doAnimation__Q24Game12EnemyMgrNodeFv
	.4byte doEntry__Q24Game12EnemyMgrNodeFv
	.4byte doSetView__Q24Game12EnemyMgrNodeFi
	.4byte doViewCalc__Q24Game12EnemyMgrNodeFv
	.4byte doSimulation__Q24Game12EnemyMgrNodeFf
	.4byte doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics
	.4byte doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport
	.4byte killAll__Q24Game12EnemyMgrNodeFPQ24Game15CreatureKillArg
	.4byte setupSoundViewerAndBas__Q24Game12EnemyMgrNodeFv
	.4byte setDebugParm__Q24Game12EnemyMgrNodeFUl
	.4byte resetDebugParm__Q24Game12EnemyMgrNodeFUl
	.4byte startMovie__Q24Game12EnemyMgrNodeFv
	.4byte endMovie__Q24Game12EnemyMgrNodeFv
	.4byte getMatrixLoadType__Q24Game12EnemyMgrNodeFv
.endobj __vt__Q24Game12EnemyMgrNode
.obj __vt__16GenericObjectMgr, weak
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte doEntry__16GenericObjectMgrFv
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte doSimpleDraw__16GenericObjectMgrFP8Viewport
	.4byte loadResources__16GenericObjectMgrFv
	.4byte resetMgr__16GenericObjectMgrFv
	.4byte pausable__16GenericObjectMgrFv
	.4byte frozenable__16GenericObjectMgrFv
	.4byte getMatrixLoadType__16GenericObjectMgrFv
.endobj __vt__16GenericObjectMgr

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj generalEnemyMgr__4Game, global
	.skip 0x4
.endobj generalEnemyMgr__4Game
.obj mCullCount__Q24Game15GeneralEnemyMgr, global
	.skip 0x4
.endobj mCullCount__Q24Game15GeneralEnemyMgr
.obj mTotalCount__Q24Game15GeneralEnemyMgr, global
	.skip 0x4
.endobj mTotalCount__Q24Game15GeneralEnemyMgr

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_805179A0, local
	.asciz "doaTEKI"
.endobj lbl_805179A0
.balign 4
.obj lbl_805179A8, local
	.float 32768.0
.endobj lbl_805179A8
.balign 4
.obj lbl_805179AC, local # tau
	.float 6.2831855
.endobj lbl_805179AC
.obj lbl_805179B0, local
	.float 0.0
.endobj lbl_805179B0
.obj lbl_805179B4, local
	.float 325.9493
.endobj lbl_805179B4
.obj lbl_805179B8, local
	.float -325.9493
.endobj lbl_805179B8
.obj lbl_805179BC, local
	.float 3.0
.endobj lbl_805179BC
.obj lbl_805179C0, local
	.float 0.5
.endobj lbl_805179C0
.obj lbl_805179C4, local
	.float 7.0
.endobj lbl_805179C4
.balign 8
.obj lbl_805179C8, local
	.8byte 0x4330000080000000
.endobj lbl_805179C8

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q24Game15GeneralEnemyMgrFv, global
/* 8010CCE8 00109C28  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010CCEC 00109C2C  7C 08 02 A6 */	mflr r0
/* 8010CCF0 00109C30  3C 80 80 4B */	lis r4, __vt__16GenericObjectMgr@ha
/* 8010CCF4 00109C34  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010CCF8 00109C38  38 04 B5 F0 */	addi r0, r4, __vt__16GenericObjectMgr@l
/* 8010CCFC 00109C3C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010CD00 00109C40  93 C1 00 08 */	stw r30, 8(r1)
/* 8010CD04 00109C44  7C 7E 1B 78 */	mr r30, r3
/* 8010CD08 00109C48  3C 60 80 48 */	lis r3, lbl_8047AA70@ha
/* 8010CD0C 00109C4C  90 1E 00 00 */	stw r0, 0(r30)
/* 8010CD10 00109C50  3B E3 AA 70 */	addi r31, r3, lbl_8047AA70@l
/* 8010CD14 00109C54  38 7E 00 04 */	addi r3, r30, 4
/* 8010CD18 00109C58  48 30 46 79 */	bl __ct__5CNodeFv
/* 8010CD1C 00109C5C  3C 60 80 4B */	lis r3, __vt__Q24Game15GeneralEnemyMgr@ha
/* 8010CD20 00109C60  3C C0 80 4F */	lis r6, __vt__5CNode@ha
/* 8010CD24 00109C64  38 63 B5 24 */	addi r3, r3, __vt__Q24Game15GeneralEnemyMgr@l
/* 8010CD28 00109C68  3C 80 80 4B */	lis r4, __vt__16GenericObjectMgr@ha
/* 8010CD2C 00109C6C  90 7E 00 00 */	stw r3, 0(r30)
/* 8010CD30 00109C70  38 03 00 38 */	addi r0, r3, 0x38
/* 8010CD34 00109C74  3C 60 80 4B */	lis r3, __vt__Q24Game12EnemyMgrNode@ha
/* 8010CD38 00109C78  39 00 00 00 */	li r8, 0
/* 8010CD3C 00109C7C  90 1E 00 04 */	stw r0, 4(r30)
/* 8010CD40 00109C80  38 A3 B5 70 */	addi r5, r3, __vt__Q24Game12EnemyMgrNode@l
/* 8010CD44 00109C84  38 66 B5 28 */	addi r3, r6, __vt__5CNode@l
/* 8010CD48 00109C88  38 FF 00 0C */	addi r7, r31, 0xc
/* 8010CD4C 00109C8C  99 1E 00 1C */	stb r8, 0x1c(r30)
/* 8010CD50 00109C90  38 C4 B5 F0 */	addi r6, r4, __vt__16GenericObjectMgr@l
/* 8010CD54 00109C94  38 85 00 10 */	addi r4, r5, 0x10
/* 8010CD58 00109C98  38 00 FF FF */	li r0, -1
/* 8010CD5C 00109C9C  90 7E 00 20 */	stw r3, 0x20(r30)
/* 8010CD60 00109CA0  38 7E 00 58 */	addi r3, r30, 0x58
/* 8010CD64 00109CA4  91 1E 00 30 */	stw r8, 0x30(r30)
/* 8010CD68 00109CA8  91 1E 00 2C */	stw r8, 0x2c(r30)
/* 8010CD6C 00109CAC  91 1E 00 28 */	stw r8, 0x28(r30)
/* 8010CD70 00109CB0  91 1E 00 24 */	stw r8, 0x24(r30)
/* 8010CD74 00109CB4  90 FE 00 34 */	stw r7, 0x34(r30)
/* 8010CD78 00109CB8  90 DE 00 38 */	stw r6, 0x38(r30)
/* 8010CD7C 00109CBC  90 BE 00 20 */	stw r5, 0x20(r30)
/* 8010CD80 00109CC0  90 9E 00 38 */	stw r4, 0x38(r30)
/* 8010CD84 00109CC4  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 8010CD88 00109CC8  91 1E 00 40 */	stw r8, 0x40(r30)
/* 8010CD8C 00109CCC  91 1E 00 48 */	stw r8, 0x48(r30)
/* 8010CD90 00109CD0  91 1E 00 4C */	stw r8, 0x4c(r30)
/* 8010CD94 00109CD4  99 1E 00 54 */	stb r8, 0x54(r30)
/* 8010CD98 00109CD8  99 1E 00 55 */	stb r8, 0x55(r30)
/* 8010CD9C 00109CDC  99 1E 00 56 */	stb r8, 0x56(r30)
/* 8010CDA0 00109CE0  99 1E 00 57 */	stb r8, 0x57(r30)
/* 8010CDA4 00109CE4  48 01 AE 5D */	bl __ct__Q34Game10EnemyStone3MgrFv
/* 8010CDA8 00109CE8  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010CDAC 00109CEC  38 9F 00 20 */	addi r4, r31, 0x20
/* 8010CDB0 00109CF0  38 A0 00 00 */	li r5, 0
/* 8010CDB4 00109CF4  48 31 65 A9 */	bl heapStatusStart__6SystemFPcP7JKRHeap
/* 8010CDB8 00109CF8  38 1F 00 30 */	addi r0, r31, 0x30
/* 8010CDBC 00109CFC  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8010CDC0 00109D00  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010CDC4 00109D04  54 03 18 38 */	slwi r3, r0, 3
/* 8010CDC8 00109D08  4B F1 71 E5 */	bl __nwa__FUl
/* 8010CDCC 00109D0C  3C 80 80 4B */	lis r4, gEnemyInfo__4Game@ha
/* 8010CDD0 00109D10  38 A0 00 00 */	li r5, 0
/* 8010CDD4 00109D14  90 7E 00 48 */	stw r3, 0x48(r30)
/* 8010CDD8 00109D18  38 84 C5 38 */	addi r4, r4, gEnemyInfo__4Game@l
/* 8010CDDC 00109D1C  7C A6 2B 78 */	mr r6, r5
/* 8010CDE0 00109D20  48 00 00 20 */	b .L_8010CE00
.L_8010CDE4:
/* 8010CDE4 00109D24  88 04 00 04 */	lbz r0, 4(r4)
/* 8010CDE8 00109D28  38 84 00 34 */	addi r4, r4, 0x34
/* 8010CDEC 00109D2C  80 7E 00 48 */	lwz r3, 0x48(r30)
/* 8010CDF0 00109D30  38 A5 00 01 */	addi r5, r5, 1
/* 8010CDF4 00109D34  7C 00 07 74 */	extsb r0, r0
/* 8010CDF8 00109D38  7C 03 31 2E */	stwx r0, r3, r6
/* 8010CDFC 00109D3C  38 C6 00 08 */	addi r6, r6, 8
.L_8010CE00:
/* 8010CE00 00109D40  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010CE04 00109D44  7C 05 00 00 */	cmpw r5, r0
/* 8010CE08 00109D48  41 80 FF DC */	blt .L_8010CDE4
/* 8010CE0C 00109D4C  80 1E 00 48 */	lwz r0, 0x48(r30)
/* 8010CE10 00109D50  28 00 00 00 */	cmplwi r0, 0
/* 8010CE14 00109D54  41 82 00 34 */	beq .L_8010CE48
/* 8010CE18 00109D58  38 A0 00 00 */	li r5, 0
/* 8010CE1C 00109D5C  7C A6 2B 78 */	mr r6, r5
/* 8010CE20 00109D60  7C A4 2B 78 */	mr r4, r5
/* 8010CE24 00109D64  48 00 00 18 */	b .L_8010CE3C
.L_8010CE28:
/* 8010CE28 00109D68  80 7E 00 48 */	lwz r3, 0x48(r30)
/* 8010CE2C 00109D6C  38 06 00 04 */	addi r0, r6, 4
/* 8010CE30 00109D70  38 C6 00 08 */	addi r6, r6, 8
/* 8010CE34 00109D74  38 A5 00 01 */	addi r5, r5, 1
/* 8010CE38 00109D78  7C 83 01 AE */	stbx r4, r3, r0
.L_8010CE3C:
/* 8010CE3C 00109D7C  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010CE40 00109D80  7C 05 00 00 */	cmpw r5, r0
/* 8010CE44 00109D84  41 80 FF E4 */	blt .L_8010CE28
.L_8010CE48:
/* 8010CE48 00109D88  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010CE4C 00109D8C  38 9F 00 20 */	addi r4, r31, 0x20
/* 8010CE50 00109D90  48 31 65 15 */	bl heapStatusEnd__6SystemFPc
/* 8010CE54 00109D94  7F C3 F3 78 */	mr r3, r30
/* 8010CE58 00109D98  48 00 09 BD */	bl resetEnemyNum__Q24Game15GeneralEnemyMgrFv
/* 8010CE5C 00109D9C  38 00 00 00 */	li r0, 0
/* 8010CE60 00109DA0  7F C3 F3 78 */	mr r3, r30
/* 8010CE64 00109DA4  98 1E 00 54 */	stb r0, 0x54(r30)
/* 8010CE68 00109DA8  98 1E 00 55 */	stb r0, 0x55(r30)
/* 8010CE6C 00109DAC  98 1E 00 56 */	stb r0, 0x56(r30)
/* 8010CE70 00109DB0  98 1E 00 57 */	stb r0, 0x57(r30)
/* 8010CE74 00109DB4  80 1E 00 54 */	lwz r0, 0x54(r30)
/* 8010CE78 00109DB8  60 00 00 01 */	ori r0, r0, 1
/* 8010CE7C 00109DBC  90 1E 00 54 */	stw r0, 0x54(r30)
/* 8010CE80 00109DC0  80 1E 00 54 */	lwz r0, 0x54(r30)
/* 8010CE84 00109DC4  60 00 00 02 */	ori r0, r0, 2
/* 8010CE88 00109DC8  90 1E 00 54 */	stw r0, 0x54(r30)
/* 8010CE8C 00109DCC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010CE90 00109DD0  83 C1 00 08 */	lwz r30, 8(r1)
/* 8010CE94 00109DD4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010CE98 00109DD8  7C 08 03 A6 */	mtlr r0
/* 8010CE9C 00109DDC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010CEA0 00109DE0  4E 80 00 20 */	blr 
.endfn __ct__Q24Game15GeneralEnemyMgrFv

.fn __dt__Q24Game12EnemyMgrNodeFv, weak
/* 8010CEA4 00109DE4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010CEA8 00109DE8  7C 08 02 A6 */	mflr r0
/* 8010CEAC 00109DEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010CEB0 00109DF0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010CEB4 00109DF4  7C 9F 23 78 */	mr r31, r4
/* 8010CEB8 00109DF8  93 C1 00 08 */	stw r30, 8(r1)
/* 8010CEBC 00109DFC  7C 7E 1B 79 */	or. r30, r3, r3
/* 8010CEC0 00109E00  41 82 00 30 */	beq .L_8010CEF0
/* 8010CEC4 00109E04  3C A0 80 4B */	lis r5, __vt__Q24Game12EnemyMgrNode@ha
/* 8010CEC8 00109E08  38 80 00 00 */	li r4, 0
/* 8010CECC 00109E0C  38 A5 B5 70 */	addi r5, r5, __vt__Q24Game12EnemyMgrNode@l
/* 8010CED0 00109E10  90 BE 00 00 */	stw r5, 0(r30)
/* 8010CED4 00109E14  38 05 00 10 */	addi r0, r5, 0x10
/* 8010CED8 00109E18  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8010CEDC 00109E1C  48 30 46 AD */	bl __dt__5CNodeFv
/* 8010CEE0 00109E20  7F E0 07 35 */	extsh. r0, r31
/* 8010CEE4 00109E24  40 81 00 0C */	ble .L_8010CEF0
/* 8010CEE8 00109E28  7F C3 F3 78 */	mr r3, r30
/* 8010CEEC 00109E2C  4B F1 71 C9 */	bl __dl__FPv
.L_8010CEF0:
/* 8010CEF0 00109E30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010CEF4 00109E34  7F C3 F3 78 */	mr r3, r30
/* 8010CEF8 00109E38  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010CEFC 00109E3C  83 C1 00 08 */	lwz r30, 8(r1)
/* 8010CF00 00109E40  7C 08 03 A6 */	mtlr r0
/* 8010CF04 00109E44  38 21 00 10 */	addi r1, r1, 0x10
/* 8010CF08 00109E48  4E 80 00 20 */	blr 
.endfn __dt__Q24Game12EnemyMgrNodeFv

.fn killAll__Q24Game15GeneralEnemyMgrFv, global
/* 8010CF0C 00109E4C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010CF10 00109E50  7C 08 02 A6 */	mflr r0
/* 8010CF14 00109E54  3C 80 80 4B */	lis r4, __vt__Q24Game15CreatureKillArg@ha
/* 8010CF18 00109E58  38 A0 00 00 */	li r5, 0
/* 8010CF1C 00109E5C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010CF20 00109E60  38 04 A2 D0 */	addi r0, r4, __vt__Q24Game15CreatureKillArg@l
/* 8010CF24 00109E64  3C 80 80 4B */	lis r4, __vt__Q24Game12EnemyKillArg@ha
/* 8010CF28 00109E68  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010CF2C 00109E6C  38 84 A2 C4 */	addi r4, r4, __vt__Q24Game12EnemyKillArg@l
/* 8010CF30 00109E70  90 01 00 08 */	stw r0, 8(r1)
/* 8010CF34 00109E74  64 A0 70 00 */	oris r0, r5, 0x7000
/* 8010CF38 00109E78  90 A1 00 0C */	stw r5, 0xc(r1)
/* 8010CF3C 00109E7C  90 81 00 08 */	stw r4, 8(r1)
/* 8010CF40 00109E80  90 01 00 0C */	stw r0, 0xc(r1)
/* 8010CF44 00109E84  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010CF48 00109E88  48 00 00 20 */	b .L_8010CF68
.L_8010CF4C:
/* 8010CF4C 00109E8C  7F E3 FB 78 */	mr r3, r31
/* 8010CF50 00109E90  38 81 00 08 */	addi r4, r1, 8
/* 8010CF54 00109E94  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010CF58 00109E98  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 8010CF5C 00109E9C  7D 89 03 A6 */	mtctr r12
/* 8010CF60 00109EA0  4E 80 04 21 */	bctrl 
/* 8010CF64 00109EA4  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010CF68:
/* 8010CF68 00109EA8  28 1F 00 00 */	cmplwi r31, 0
/* 8010CF6C 00109EAC  40 82 FF E0 */	bne .L_8010CF4C
/* 8010CF70 00109EB0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010CF74 00109EB4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010CF78 00109EB8  7C 08 03 A6 */	mtlr r0
/* 8010CF7C 00109EBC  38 21 00 20 */	addi r1, r1, 0x20
/* 8010CF80 00109EC0  4E 80 00 20 */	blr 
.endfn killAll__Q24Game15GeneralEnemyMgrFv

.fn killAll__Q24Game12EnemyMgrNodeFPQ24Game15CreatureKillArg, weak
/* 8010CF84 00109EC4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010CF88 00109EC8  7C 08 02 A6 */	mflr r0
/* 8010CF8C 00109ECC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010CF90 00109ED0  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010CF94 00109ED4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010CF98 00109ED8  81 8C 00 7C */	lwz r12, 0x7c(r12)
/* 8010CF9C 00109EDC  7D 89 03 A6 */	mtctr r12
/* 8010CFA0 00109EE0  4E 80 04 21 */	bctrl 
/* 8010CFA4 00109EE4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010CFA8 00109EE8  7C 08 03 A6 */	mtlr r0
/* 8010CFAC 00109EEC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010CFB0 00109EF0  4E 80 00 20 */	blr 
.endfn killAll__Q24Game12EnemyMgrNodeFPQ24Game15CreatureKillArg

.fn setupSoundViewerAndBas__Q24Game15GeneralEnemyMgrFv, global
/* 8010CFB4 00109EF4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010CFB8 00109EF8  7C 08 02 A6 */	mflr r0
/* 8010CFBC 00109EFC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010CFC0 00109F00  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010CFC4 00109F04  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010CFC8 00109F08  48 00 00 1C */	b .L_8010CFE4
.L_8010CFCC:
/* 8010CFCC 00109F0C  7F E3 FB 78 */	mr r3, r31
/* 8010CFD0 00109F10  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010CFD4 00109F14  81 8C 00 68 */	lwz r12, 0x68(r12)
/* 8010CFD8 00109F18  7D 89 03 A6 */	mtctr r12
/* 8010CFDC 00109F1C  4E 80 04 21 */	bctrl 
/* 8010CFE0 00109F20  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010CFE4:
/* 8010CFE4 00109F24  28 1F 00 00 */	cmplwi r31, 0
/* 8010CFE8 00109F28  40 82 FF E4 */	bne .L_8010CFCC
/* 8010CFEC 00109F2C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010CFF0 00109F30  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010CFF4 00109F34  7C 08 03 A6 */	mtlr r0
/* 8010CFF8 00109F38  38 21 00 10 */	addi r1, r1, 0x10
/* 8010CFFC 00109F3C  4E 80 00 20 */	blr 
.endfn setupSoundViewerAndBas__Q24Game15GeneralEnemyMgrFv

.fn setupSoundViewerAndBas__Q24Game12EnemyMgrNodeFv, weak
/* 8010D000 00109F40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D004 00109F44  7C 08 02 A6 */	mflr r0
/* 8010D008 00109F48  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D00C 00109F4C  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D010 00109F50  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D014 00109F54  81 8C 00 80 */	lwz r12, 0x80(r12)
/* 8010D018 00109F58  7D 89 03 A6 */	mtctr r12
/* 8010D01C 00109F5C  4E 80 04 21 */	bctrl 
/* 8010D020 00109F60  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D024 00109F64  7C 08 03 A6 */	mtlr r0
/* 8010D028 00109F68  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D02C 00109F6C  4E 80 00 20 */	blr 
.endfn setupSoundViewerAndBas__Q24Game12EnemyMgrNodeFv

.fn doAnimation__Q24Game15GeneralEnemyMgrFv, global
/* 8010D030 00109F70  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D034 00109F74  7C 08 02 A6 */	mflr r0
/* 8010D038 00109F78  38 82 96 40 */	addi r4, r2, lbl_805179A0@sda21
/* 8010D03C 00109F7C  38 A0 00 01 */	li r5, 1
/* 8010D040 00109F80  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D044 00109F84  38 00 00 00 */	li r0, 0
/* 8010D048 00109F88  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010D04C 00109F8C  7C 7F 1B 78 */	mr r31, r3
/* 8010D050 00109F90  80 CD 9A EC */	lwz r6, sys@sda21(r13)
/* 8010D054 00109F94  90 0D 91 E4 */	stw r0, mCullCount__Q24Game15GeneralEnemyMgr@sda21(r13)
/* 8010D058 00109F98  90 0D 91 E8 */	stw r0, mTotalCount__Q24Game15GeneralEnemyMgr@sda21(r13)
/* 8010D05C 00109F9C  80 66 00 28 */	lwz r3, 0x28(r6)
/* 8010D060 00109FA0  48 31 DA 99 */	bl _start__9SysTimersFPcb
/* 8010D064 00109FA4  80 1F 00 54 */	lwz r0, 0x54(r31)
/* 8010D068 00109FA8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010D06C 00109FAC  41 82 00 2C */	beq .L_8010D098
/* 8010D070 00109FB0  83 FF 00 30 */	lwz r31, 0x30(r31)
/* 8010D074 00109FB4  48 00 00 1C */	b .L_8010D090
.L_8010D078:
/* 8010D078 00109FB8  7F E3 FB 78 */	mr r3, r31
/* 8010D07C 00109FBC  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D080 00109FC0  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 8010D084 00109FC4  7D 89 03 A6 */	mtctr r12
/* 8010D088 00109FC8  4E 80 04 21 */	bctrl 
/* 8010D08C 00109FCC  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D090:
/* 8010D090 00109FD0  28 1F 00 00 */	cmplwi r31, 0
/* 8010D094 00109FD4  40 82 FF E4 */	bne .L_8010D078
.L_8010D098:
/* 8010D098 00109FD8  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D09C 00109FDC  38 82 96 40 */	addi r4, r2, lbl_805179A0@sda21
/* 8010D0A0 00109FE0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8010D0A4 00109FE4  48 31 DA 59 */	bl _stop__9SysTimersFPc
/* 8010D0A8 00109FE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D0AC 00109FEC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010D0B0 00109FF0  7C 08 03 A6 */	mtlr r0
/* 8010D0B4 00109FF4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D0B8 00109FF8  4E 80 00 20 */	blr 
.endfn doAnimation__Q24Game15GeneralEnemyMgrFv

.fn doAnimation__Q24Game12EnemyMgrNodeFv, weak
/* 8010D0BC 00109FFC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D0C0 0010A000  7C 08 02 A6 */	mflr r0
/* 8010D0C4 0010A004  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D0C8 0010A008  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D0CC 0010A00C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D0D0 0010A010  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010D0D4 0010A014  7D 89 03 A6 */	mtctr r12
/* 8010D0D8 0010A018  4E 80 04 21 */	bctrl 
/* 8010D0DC 0010A01C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D0E0 0010A020  7C 08 03 A6 */	mtlr r0
/* 8010D0E4 0010A024  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D0E8 0010A028  4E 80 00 20 */	blr 
.endfn doAnimation__Q24Game12EnemyMgrNodeFv

.fn doEntry__Q24Game15GeneralEnemyMgrFv, global
/* 8010D0EC 0010A02C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D0F0 0010A030  7C 08 02 A6 */	mflr r0
/* 8010D0F4 0010A034  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D0F8 0010A038  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010D0FC 0010A03C  80 03 00 54 */	lwz r0, 0x54(r3)
/* 8010D100 0010A040  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8010D104 0010A044  41 82 00 2C */	beq .L_8010D130
/* 8010D108 0010A048  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010D10C 0010A04C  48 00 00 1C */	b .L_8010D128
.L_8010D110:
/* 8010D110 0010A050  7F E3 FB 78 */	mr r3, r31
/* 8010D114 0010A054  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D118 0010A058  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8010D11C 0010A05C  7D 89 03 A6 */	mtctr r12
/* 8010D120 0010A060  4E 80 04 21 */	bctrl 
/* 8010D124 0010A064  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D128:
/* 8010D128 0010A068  28 1F 00 00 */	cmplwi r31, 0
/* 8010D12C 0010A06C  40 82 FF E4 */	bne .L_8010D110
.L_8010D130:
/* 8010D130 0010A070  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D134 0010A074  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010D138 0010A078  7C 08 03 A6 */	mtlr r0
/* 8010D13C 0010A07C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D140 0010A080  4E 80 00 20 */	blr 
.endfn doEntry__Q24Game15GeneralEnemyMgrFv

.fn doEntry__Q24Game12EnemyMgrNodeFv, weak
/* 8010D144 0010A084  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D148 0010A088  7C 08 02 A6 */	mflr r0
/* 8010D14C 0010A08C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D150 0010A090  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D154 0010A094  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D158 0010A098  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8010D15C 0010A09C  7D 89 03 A6 */	mtctr r12
/* 8010D160 0010A0A0  4E 80 04 21 */	bctrl 
/* 8010D164 0010A0A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D168 0010A0A8  7C 08 03 A6 */	mtlr r0
/* 8010D16C 0010A0AC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D170 0010A0B0  4E 80 00 20 */	blr 
.endfn doEntry__Q24Game12EnemyMgrNodeFv

.fn doSetView__Q24Game15GeneralEnemyMgrFi, global
/* 8010D174 0010A0B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D178 0010A0B8  7C 08 02 A6 */	mflr r0
/* 8010D17C 0010A0BC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D180 0010A0C0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010D184 0010A0C4  93 C1 00 08 */	stw r30, 8(r1)
/* 8010D188 0010A0C8  7C 9E 23 78 */	mr r30, r4
/* 8010D18C 0010A0CC  80 03 00 54 */	lwz r0, 0x54(r3)
/* 8010D190 0010A0D0  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8010D194 0010A0D4  41 82 00 30 */	beq .L_8010D1C4
/* 8010D198 0010A0D8  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010D19C 0010A0DC  48 00 00 20 */	b .L_8010D1BC
.L_8010D1A0:
/* 8010D1A0 0010A0E0  7F E3 FB 78 */	mr r3, r31
/* 8010D1A4 0010A0E4  7F C4 F3 78 */	mr r4, r30
/* 8010D1A8 0010A0E8  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D1AC 0010A0EC  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 8010D1B0 0010A0F0  7D 89 03 A6 */	mtctr r12
/* 8010D1B4 0010A0F4  4E 80 04 21 */	bctrl 
/* 8010D1B8 0010A0F8  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D1BC:
/* 8010D1BC 0010A0FC  28 1F 00 00 */	cmplwi r31, 0
/* 8010D1C0 0010A100  40 82 FF E0 */	bne .L_8010D1A0
.L_8010D1C4:
/* 8010D1C4 0010A104  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D1C8 0010A108  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010D1CC 0010A10C  83 C1 00 08 */	lwz r30, 8(r1)
/* 8010D1D0 0010A110  7C 08 03 A6 */	mtlr r0
/* 8010D1D4 0010A114  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D1D8 0010A118  4E 80 00 20 */	blr 
.endfn doSetView__Q24Game15GeneralEnemyMgrFi

.fn doSetView__Q24Game12EnemyMgrNodeFi, weak
/* 8010D1DC 0010A11C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D1E0 0010A120  7C 08 02 A6 */	mflr r0
/* 8010D1E4 0010A124  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D1E8 0010A128  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D1EC 0010A12C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D1F0 0010A130  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010D1F4 0010A134  7D 89 03 A6 */	mtctr r12
/* 8010D1F8 0010A138  4E 80 04 21 */	bctrl 
/* 8010D1FC 0010A13C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D200 0010A140  7C 08 03 A6 */	mtlr r0
/* 8010D204 0010A144  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D208 0010A148  4E 80 00 20 */	blr 
.endfn doSetView__Q24Game12EnemyMgrNodeFi

.fn doViewCalc__Q24Game15GeneralEnemyMgrFv, global
/* 8010D20C 0010A14C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D210 0010A150  7C 08 02 A6 */	mflr r0
/* 8010D214 0010A154  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D218 0010A158  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010D21C 0010A15C  80 03 00 54 */	lwz r0, 0x54(r3)
/* 8010D220 0010A160  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8010D224 0010A164  41 82 00 2C */	beq .L_8010D250
/* 8010D228 0010A168  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010D22C 0010A16C  48 00 00 1C */	b .L_8010D248
.L_8010D230:
/* 8010D230 0010A170  7F E3 FB 78 */	mr r3, r31
/* 8010D234 0010A174  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D238 0010A178  81 8C 00 54 */	lwz r12, 0x54(r12)
/* 8010D23C 0010A17C  7D 89 03 A6 */	mtctr r12
/* 8010D240 0010A180  4E 80 04 21 */	bctrl 
/* 8010D244 0010A184  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D248:
/* 8010D248 0010A188  28 1F 00 00 */	cmplwi r31, 0
/* 8010D24C 0010A18C  40 82 FF E4 */	bne .L_8010D230
.L_8010D250:
/* 8010D250 0010A190  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D254 0010A194  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010D258 0010A198  7C 08 03 A6 */	mtlr r0
/* 8010D25C 0010A19C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D260 0010A1A0  4E 80 00 20 */	blr 
.endfn doViewCalc__Q24Game15GeneralEnemyMgrFv

.fn doViewCalc__Q24Game12EnemyMgrNodeFv, weak
/* 8010D264 0010A1A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D268 0010A1A8  7C 08 02 A6 */	mflr r0
/* 8010D26C 0010A1AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D270 0010A1B0  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D274 0010A1B4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D278 0010A1B8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010D27C 0010A1BC  7D 89 03 A6 */	mtctr r12
/* 8010D280 0010A1C0  4E 80 04 21 */	bctrl 
/* 8010D284 0010A1C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D288 0010A1C8  7C 08 03 A6 */	mtlr r0
/* 8010D28C 0010A1CC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D290 0010A1D0  4E 80 00 20 */	blr 
.endfn doViewCalc__Q24Game12EnemyMgrNodeFv

.fn doSimulation__Q24Game15GeneralEnemyMgrFf, global
/* 8010D294 0010A1D4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010D298 0010A1D8  7C 08 02 A6 */	mflr r0
/* 8010D29C 0010A1DC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010D2A0 0010A1E0  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 8010D2A4 0010A1E4  FF E0 08 90 */	fmr f31, f1
/* 8010D2A8 0010A1E8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8010D2AC 0010A1EC  80 03 00 54 */	lwz r0, 0x54(r3)
/* 8010D2B0 0010A1F0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010D2B4 0010A1F4  41 82 00 30 */	beq .L_8010D2E4
/* 8010D2B8 0010A1F8  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010D2BC 0010A1FC  48 00 00 20 */	b .L_8010D2DC
.L_8010D2C0:
/* 8010D2C0 0010A200  7F E3 FB 78 */	mr r3, r31
/* 8010D2C4 0010A204  FC 20 F8 90 */	fmr f1, f31
/* 8010D2C8 0010A208  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D2CC 0010A20C  81 8C 00 58 */	lwz r12, 0x58(r12)
/* 8010D2D0 0010A210  7D 89 03 A6 */	mtctr r12
/* 8010D2D4 0010A214  4E 80 04 21 */	bctrl 
/* 8010D2D8 0010A218  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D2DC:
/* 8010D2DC 0010A21C  28 1F 00 00 */	cmplwi r31, 0
/* 8010D2E0 0010A220  40 82 FF E0 */	bne .L_8010D2C0
.L_8010D2E4:
/* 8010D2E4 0010A224  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010D2E8 0010A228  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 8010D2EC 0010A22C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8010D2F0 0010A230  7C 08 03 A6 */	mtlr r0
/* 8010D2F4 0010A234  38 21 00 20 */	addi r1, r1, 0x20
/* 8010D2F8 0010A238  4E 80 00 20 */	blr 
.endfn doSimulation__Q24Game15GeneralEnemyMgrFf

.fn doSimulation__Q24Game12EnemyMgrNodeFf, weak
/* 8010D2FC 0010A23C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D300 0010A240  7C 08 02 A6 */	mflr r0
/* 8010D304 0010A244  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D308 0010A248  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D30C 0010A24C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D310 0010A250  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010D314 0010A254  7D 89 03 A6 */	mtctr r12
/* 8010D318 0010A258  4E 80 04 21 */	bctrl 
/* 8010D31C 0010A25C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D320 0010A260  7C 08 03 A6 */	mtlr r0
/* 8010D324 0010A264  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D328 0010A268  4E 80 00 20 */	blr 
.endfn doSimulation__Q24Game12EnemyMgrNodeFf

.fn doDirectDraw__Q24Game15GeneralEnemyMgrFR8Graphics, global
/* 8010D32C 0010A26C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D330 0010A270  7C 08 02 A6 */	mflr r0
/* 8010D334 0010A274  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D338 0010A278  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010D33C 0010A27C  93 C1 00 08 */	stw r30, 8(r1)
/* 8010D340 0010A280  7C 9E 23 78 */	mr r30, r4
/* 8010D344 0010A284  80 03 00 54 */	lwz r0, 0x54(r3)
/* 8010D348 0010A288  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8010D34C 0010A28C  41 82 00 30 */	beq .L_8010D37C
/* 8010D350 0010A290  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010D354 0010A294  48 00 00 20 */	b .L_8010D374
.L_8010D358:
/* 8010D358 0010A298  7F E3 FB 78 */	mr r3, r31
/* 8010D35C 0010A29C  7F C4 F3 78 */	mr r4, r30
/* 8010D360 0010A2A0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D364 0010A2A4  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 8010D368 0010A2A8  7D 89 03 A6 */	mtctr r12
/* 8010D36C 0010A2AC  4E 80 04 21 */	bctrl 
/* 8010D370 0010A2B0  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D374:
/* 8010D374 0010A2B4  28 1F 00 00 */	cmplwi r31, 0
/* 8010D378 0010A2B8  40 82 FF E0 */	bne .L_8010D358
.L_8010D37C:
/* 8010D37C 0010A2BC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D380 0010A2C0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010D384 0010A2C4  83 C1 00 08 */	lwz r30, 8(r1)
/* 8010D388 0010A2C8  7C 08 03 A6 */	mtlr r0
/* 8010D38C 0010A2CC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D390 0010A2D0  4E 80 00 20 */	blr 
.endfn doDirectDraw__Q24Game15GeneralEnemyMgrFR8Graphics

.fn doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics, weak
/* 8010D394 0010A2D4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D398 0010A2D8  7C 08 02 A6 */	mflr r0
/* 8010D39C 0010A2DC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D3A0 0010A2E0  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D3A4 0010A2E4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D3A8 0010A2E8  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010D3AC 0010A2EC  7D 89 03 A6 */	mtctr r12
/* 8010D3B0 0010A2F0  4E 80 04 21 */	bctrl 
/* 8010D3B4 0010A2F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D3B8 0010A2F8  7C 08 03 A6 */	mtlr r0
/* 8010D3BC 0010A2FC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D3C0 0010A300  4E 80 00 20 */	blr 
.endfn doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics

.fn doSimpleDraw__Q24Game15GeneralEnemyMgrFP8Viewport, global
/* 8010D3C4 0010A304  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010D3C8 0010A308  7C 08 02 A6 */	mflr r0
/* 8010D3CC 0010A30C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010D3D0 0010A310  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010D3D4 0010A314  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010D3D8 0010A318  7C 9E 23 78 */	mr r30, r4
/* 8010D3DC 0010A31C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010D3E0 0010A320  7C 7D 1B 78 */	mr r29, r3
/* 8010D3E4 0010A324  80 03 00 54 */	lwz r0, 0x54(r3)
/* 8010D3E8 0010A328  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8010D3EC 0010A32C  41 82 00 3C */	beq .L_8010D428
/* 8010D3F0 0010A330  83 FD 00 30 */	lwz r31, 0x30(r29)
/* 8010D3F4 0010A334  48 00 00 20 */	b .L_8010D414
.L_8010D3F8:
/* 8010D3F8 0010A338  7F E3 FB 78 */	mr r3, r31
/* 8010D3FC 0010A33C  7F C4 F3 78 */	mr r4, r30
/* 8010D400 0010A340  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010D404 0010A344  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 8010D408 0010A348  7D 89 03 A6 */	mtctr r12
/* 8010D40C 0010A34C  4E 80 04 21 */	bctrl 
/* 8010D410 0010A350  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010D414:
/* 8010D414 0010A354  28 1F 00 00 */	cmplwi r31, 0
/* 8010D418 0010A358  40 82 FF E0 */	bne .L_8010D3F8
/* 8010D41C 0010A35C  7F C4 F3 78 */	mr r4, r30
/* 8010D420 0010A360  38 7D 00 58 */	addi r3, r29, 0x58
/* 8010D424 0010A364  48 01 AB 81 */	bl draw__Q34Game10EnemyStone3MgrFP8Viewport
.L_8010D428:
/* 8010D428 0010A368  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010D42C 0010A36C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010D430 0010A370  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010D434 0010A374  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010D438 0010A378  7C 08 03 A6 */	mtlr r0
/* 8010D43C 0010A37C  38 21 00 20 */	addi r1, r1, 0x20
/* 8010D440 0010A380  4E 80 00 20 */	blr 
.endfn doSimpleDraw__Q24Game15GeneralEnemyMgrFP8Viewport

.fn doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport, weak
/* 8010D444 0010A384  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D448 0010A388  7C 08 02 A6 */	mflr r0
/* 8010D44C 0010A38C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D450 0010A390  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010D454 0010A394  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D458 0010A398  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8010D45C 0010A39C  7D 89 03 A6 */	mtctr r12
/* 8010D460 0010A3A0  4E 80 04 21 */	bctrl 
/* 8010D464 0010A3A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D468 0010A3A8  7C 08 03 A6 */	mtlr r0
/* 8010D46C 0010A3AC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D470 0010A3B0  4E 80 00 20 */	blr 
.endfn doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport

.fn getJ3DModelData__Q24Game15GeneralEnemyMgrFi, global
/* 8010D474 0010A3B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D478 0010A3B8  7C 08 02 A6 */	mflr r0
/* 8010D47C 0010A3BC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D480 0010A3C0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010D484 0010A3C4  3B E0 00 00 */	li r31, 0
/* 8010D488 0010A3C8  48 00 01 45 */	bl getIEnemyMgrBase__Q24Game15GeneralEnemyMgrFi
/* 8010D48C 0010A3CC  28 03 00 00 */	cmplwi r3, 0
/* 8010D490 0010A3D0  41 82 00 18 */	beq .L_8010D4A8
/* 8010D494 0010A3D4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D498 0010A3D8  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8010D49C 0010A3DC  7D 89 03 A6 */	mtctr r12
/* 8010D4A0 0010A3E0  4E 80 04 21 */	bctrl 
/* 8010D4A4 0010A3E4  7C 7F 1B 78 */	mr r31, r3
.L_8010D4A8:
/* 8010D4A8 0010A3E8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D4AC 0010A3EC  7F E3 FB 78 */	mr r3, r31
/* 8010D4B0 0010A3F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010D4B4 0010A3F4  7C 08 03 A6 */	mtlr r0
/* 8010D4B8 0010A3F8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D4BC 0010A3FC  4E 80 00 20 */	blr 
.endfn getJ3DModelData__Q24Game15GeneralEnemyMgrFi

.fn birth__Q24Game15GeneralEnemyMgrFiRQ24Game13EnemyBirthArg, global
/* 8010D4C0 0010A400  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010D4C4 0010A404  7C 08 02 A6 */	mflr r0
/* 8010D4C8 0010A408  3C C0 80 4B */	lis r6, gEnemyInfo__4Game@ha
/* 8010D4CC 0010A40C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010D4D0 0010A410  38 C6 C5 38 */	addi r6, r6, gEnemyInfo__4Game@l
/* 8010D4D4 0010A414  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010D4D8 0010A418  3B E0 00 00 */	li r31, 0
/* 8010D4DC 0010A41C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010D4E0 0010A420  7C BE 2B 78 */	mr r30, r5
/* 8010D4E4 0010A424  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010D4E8 0010A428  7C 9D 23 78 */	mr r29, r4
/* 8010D4EC 0010A42C  38 80 FF FF */	li r4, -1
/* 8010D4F0 0010A430  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010D4F4 0010A434  7C 09 03 A6 */	mtctr r0
/* 8010D4F8 0010A438  2C 00 00 00 */	cmpwi r0, 0
/* 8010D4FC 0010A43C  40 81 00 38 */	ble .L_8010D534
.L_8010D500:
/* 8010D500 0010A440  88 06 00 04 */	lbz r0, 4(r6)
/* 8010D504 0010A444  7C 00 07 74 */	extsb r0, r0
/* 8010D508 0010A448  7C 00 E8 00 */	cmpw r0, r29
/* 8010D50C 0010A44C  40 82 00 20 */	bne .L_8010D52C
/* 8010D510 0010A450  A0 06 00 08 */	lhz r0, 8(r6)
/* 8010D514 0010A454  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010D518 0010A458  41 82 00 0C */	beq .L_8010D524
/* 8010D51C 0010A45C  7F A4 EB 78 */	mr r4, r29
/* 8010D520 0010A460  48 00 00 0C */	b .L_8010D52C
.L_8010D524:
/* 8010D524 0010A464  88 86 00 05 */	lbz r4, 5(r6)
/* 8010D528 0010A468  7C 84 07 74 */	extsb r4, r4
.L_8010D52C:
/* 8010D52C 0010A46C  38 C6 00 34 */	addi r6, r6, 0x34
/* 8010D530 0010A470  42 00 FF D0 */	bdnz .L_8010D500
.L_8010D534:
/* 8010D534 0010A474  48 00 00 99 */	bl getIEnemyMgrBase__Q24Game15GeneralEnemyMgrFi
/* 8010D538 0010A478  28 03 00 00 */	cmplwi r3, 0
/* 8010D53C 0010A47C  41 82 00 20 */	beq .L_8010D55C
/* 8010D540 0010A480  93 BE 00 28 */	stw r29, 0x28(r30)
/* 8010D544 0010A484  7F C4 F3 78 */	mr r4, r30
/* 8010D548 0010A488  81 83 00 00 */	lwz r12, 0(r3)
/* 8010D54C 0010A48C  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8010D550 0010A490  7D 89 03 A6 */	mtctr r12
/* 8010D554 0010A494  4E 80 04 21 */	bctrl 
/* 8010D558 0010A498  7C 7F 1B 78 */	mr r31, r3
.L_8010D55C:
/* 8010D55C 0010A49C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010D560 0010A4A0  7F E3 FB 78 */	mr r3, r31
/* 8010D564 0010A4A4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010D568 0010A4A8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010D56C 0010A4AC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010D570 0010A4B0  7C 08 03 A6 */	mtlr r0
/* 8010D574 0010A4B4  38 21 00 20 */	addi r1, r1, 0x20
/* 8010D578 0010A4B8  4E 80 00 20 */	blr 
.endfn birth__Q24Game15GeneralEnemyMgrFiRQ24Game13EnemyBirthArg

.fn getEnemyName__Q24Game15GeneralEnemyMgrFii, global
/* 8010D57C 0010A4BC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D580 0010A4C0  7C 08 02 A6 */	mflr r0
/* 8010D584 0010A4C4  7C 83 23 78 */	mr r3, r4
/* 8010D588 0010A4C8  7C A4 2B 78 */	mr r4, r5
/* 8010D58C 0010A4CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D590 0010A4D0  48 01 5D 4D */	bl getEnemyName__Q24Game13EnemyInfoFuncFii
/* 8010D594 0010A4D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D598 0010A4D8  7C 08 03 A6 */	mtlr r0
/* 8010D59C 0010A4DC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D5A0 0010A4E0  4E 80 00 20 */	blr 
.endfn getEnemyName__Q24Game15GeneralEnemyMgrFii

.fn getEnemyID__Q24Game15GeneralEnemyMgrFPci, global
/* 8010D5A4 0010A4E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010D5A8 0010A4E8  7C 08 02 A6 */	mflr r0
/* 8010D5AC 0010A4EC  7C 83 23 78 */	mr r3, r4
/* 8010D5B0 0010A4F0  7C A4 2B 78 */	mr r4, r5
/* 8010D5B4 0010A4F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010D5B8 0010A4F8  48 01 5E B1 */	bl getEnemyID__Q24Game13EnemyInfoFuncFPci
/* 8010D5BC 0010A4FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010D5C0 0010A500  7C 08 03 A6 */	mtlr r0
/* 8010D5C4 0010A504  38 21 00 10 */	addi r1, r1, 0x10
/* 8010D5C8 0010A508  4E 80 00 20 */	blr 
.endfn getEnemyID__Q24Game15GeneralEnemyMgrFPci

.fn getIEnemyMgrBase__Q24Game15GeneralEnemyMgrFi, global
/* 8010D5CC 0010A50C  80 A3 00 30 */	lwz r5, 0x30(r3)
/* 8010D5D0 0010A510  38 60 00 00 */	li r3, 0
/* 8010D5D4 0010A514  48 00 00 18 */	b .L_8010D5EC
.L_8010D5D8:
/* 8010D5D8 0010A518  80 05 00 1C */	lwz r0, 0x1c(r5)
/* 8010D5DC 0010A51C  7C 00 20 00 */	cmpw r0, r4
/* 8010D5E0 0010A520  40 82 00 08 */	bne .L_8010D5E8
/* 8010D5E4 0010A524  80 65 00 20 */	lwz r3, 0x20(r5)
.L_8010D5E8:
/* 8010D5E8 0010A528  80 A5 00 04 */	lwz r5, 4(r5)
.L_8010D5EC:
/* 8010D5EC 0010A52C  28 05 00 00 */	cmplwi r5, 0
/* 8010D5F0 0010A530  40 82 FF E8 */	bne .L_8010D5D8
/* 8010D5F4 0010A534  4E 80 00 20 */	blr 
.endfn getIEnemyMgrBase__Q24Game15GeneralEnemyMgrFi

.fn allocateEnemys__Q24Game15GeneralEnemyMgrFUci, global
/* 8010D5F8 0010A538  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8010D5FC 0010A53C  7C 08 02 A6 */	mflr r0
/* 8010D600 0010A540  2C 05 00 00 */	cmpwi r5, 0
/* 8010D604 0010A544  3C C0 80 48 */	lis r6, lbl_8047AA70@ha
/* 8010D608 0010A548  90 01 00 64 */	stw r0, 0x64(r1)
/* 8010D60C 0010A54C  BF 21 00 44 */	stmw r25, 0x44(r1)
/* 8010D610 0010A550  7C 7D 1B 78 */	mr r29, r3
/* 8010D614 0010A554  7C 9E 23 78 */	mr r30, r4
/* 8010D618 0010A558  3B E6 AA 70 */	addi r31, r6, lbl_8047AA70@l
/* 8010D61C 0010A55C  40 80 00 68 */	bge .L_8010D684
/* 8010D620 0010A560  3C 60 00 20 */	lis r3, 0x00200800@ha
/* 8010D624 0010A564  38 03 08 00 */	addi r0, r3, 0x00200800@l
/* 8010D628 0010A568  90 1D 00 50 */	stw r0, 0x50(r29)
/* 8010D62C 0010A56C  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 8010D630 0010A570  28 03 00 00 */	cmplwi r3, 0
/* 8010D634 0010A574  41 82 00 54 */	beq .L_8010D688
/* 8010D638 0010A578  80 63 00 44 */	lwz r3, 0x44(r3)
/* 8010D63C 0010A57C  38 00 00 00 */	li r0, 0
/* 8010D640 0010A580  2C 03 00 02 */	cmpwi r3, 2
/* 8010D644 0010A584  41 82 00 0C */	beq .L_8010D650
/* 8010D648 0010A588  2C 03 00 03 */	cmpwi r3, 3
/* 8010D64C 0010A58C  40 82 00 08 */	bne .L_8010D654
.L_8010D650:
/* 8010D650 0010A590  38 00 00 01 */	li r0, 1
.L_8010D654:
/* 8010D654 0010A594  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8010D658 0010A598  41 82 00 14 */	beq .L_8010D66C
/* 8010D65C 0010A59C  3C 60 00 17 */	lis r3, 0x00177000@ha
/* 8010D660 0010A5A0  38 03 70 00 */	addi r0, r3, 0x00177000@l
/* 8010D664 0010A5A4  90 1D 00 50 */	stw r0, 0x50(r29)
/* 8010D668 0010A5A8  48 00 00 20 */	b .L_8010D688
.L_8010D66C:
/* 8010D66C 0010A5AC  2C 03 00 01 */	cmpwi r3, 1
/* 8010D670 0010A5B0  40 82 00 18 */	bne .L_8010D688
/* 8010D674 0010A5B4  3C 60 00 1C */	lis r3, 0x00300000@ha
/* 8010D678 0010A5B8  38 03 20 00 */	addi r0, r3, 0x00300000@l
/* 8010D67C 0010A5BC  90 1D 00 50 */	stw r0, 0x50(r29)
/* 8010D680 0010A5C0  48 00 00 08 */	b .L_8010D688
.L_8010D684:
/* 8010D684 0010A5C4  90 BD 00 50 */	stw r5, 0x50(r29)
.L_8010D688:
/* 8010D688 0010A5C8  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D68C 0010A5CC  38 9F 00 40 */	addi r4, r31, 0x40
/* 8010D690 0010A5D0  38 A0 00 00 */	li r5, 0
/* 8010D694 0010A5D4  48 31 5C C9 */	bl heapStatusStart__6SystemFPcP7JKRHeap
/* 8010D698 0010A5D8  83 6D 88 2C */	lwz r27, sCurrentHeap__7JKRHeap@sda21(r13)
/* 8010D69C 0010A5DC  38 A0 00 01 */	li r5, 1
/* 8010D6A0 0010A5E0  80 7D 00 50 */	lwz r3, 0x50(r29)
/* 8010D6A4 0010A5E4  7F 64 DB 78 */	mr r4, r27
/* 8010D6A8 0010A5E8  4B F1 76 C9 */	bl create__12JKRSolidHeapFUlP7JKRHeapb
/* 8010D6AC 0010A5EC  90 7D 00 4C */	stw r3, 0x4c(r29)
/* 8010D6B0 0010A5F0  80 7D 00 4C */	lwz r3, 0x4c(r29)
/* 8010D6B4 0010A5F4  4B F1 5E F1 */	bl becomeCurrentHeap__7JKRHeapFv
/* 8010D6B8 0010A5F8  38 7D 00 58 */	addi r3, r29, 0x58
/* 8010D6BC 0010A5FC  48 01 A5 CD */	bl loadResource__Q34Game10EnemyStone3MgrFv
/* 8010D6C0 0010A600  7F 63 DB 78 */	mr r3, r27
/* 8010D6C4 0010A604  81 9B 00 00 */	lwz r12, 0(r27)
/* 8010D6C8 0010A608  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010D6CC 0010A60C  7D 89 03 A6 */	mtctr r12
/* 8010D6D0 0010A610  4E 80 04 21 */	bctrl 
/* 8010D6D4 0010A614  3C 03 BA A8 */	subis r0, r3, 0x4558
/* 8010D6D8 0010A618  28 00 50 48 */	cmplwi r0, 0x5048
/* 8010D6DC 0010A61C  41 82 00 18 */	beq .L_8010D6F4
/* 8010D6E0 0010A620  38 7F 00 4C */	addi r3, r31, 0x4c
/* 8010D6E4 0010A624  38 BF 00 60 */	addi r5, r31, 0x60
/* 8010D6E8 0010A628  38 80 07 34 */	li r4, 0x734
/* 8010D6EC 0010A62C  4C C6 31 82 */	crclr 6
/* 8010D6F0 0010A630  4B F1 CF 51 */	bl panic_f__12JUTExceptionFPCciPCce
.L_8010D6F4:
/* 8010D6F4 0010A634  38 61 00 08 */	addi r3, r1, 8
/* 8010D6F8 0010A638  38 9F 00 6C */	addi r4, r31, 0x6c
/* 8010D6FC 0010A63C  48 33 EF 21 */	bl __ct__Q212LoadResource11ArgAramOnlyFPCc
/* 8010D700 0010A640  38 00 00 02 */	li r0, 2
/* 8010D704 0010A644  93 61 00 20 */	stw r27, 0x20(r1)
/* 8010D708 0010A648  80 6D 9C 28 */	lwz r3, gLoadResourceMgr@sda21(r13)
/* 8010D70C 0010A64C  38 81 00 08 */	addi r4, r1, 8
/* 8010D710 0010A650  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010D714 0010A654  48 33 F0 01 */	bl mountArchive__Q212LoadResource3MgrFRQ212LoadResource3Arg
/* 8010D718 0010A658  7C 60 1B 78 */	mr r0, r3
/* 8010D71C 0010A65C  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D720 0010A660  7C 1A 03 78 */	mr r26, r0
/* 8010D724 0010A664  38 9F 00 88 */	addi r4, r31, 0x88
/* 8010D728 0010A668  80 1A 00 34 */	lwz r0, 0x34(r26)
/* 8010D72C 0010A66C  38 A0 00 00 */	li r5, 0
/* 8010D730 0010A670  90 0D 91 A8 */	stw r0, gParmArc__4Game@sda21(r13)
/* 8010D734 0010A674  48 31 5C 29 */	bl heapStatusStart__6SystemFPcP7JKRHeap
/* 8010D738 0010A678  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D73C 0010A67C  48 31 5C 31 */	bl heapStatusIndividual__6SystemFv
/* 8010D740 0010A680  3C 60 80 4B */	lis r3, gEnemyInfo__4Game@ha
/* 8010D744 0010A684  3B 20 00 00 */	li r25, 0
/* 8010D748 0010A688  3B 83 C5 38 */	addi r28, r3, gEnemyInfo__4Game@l
/* 8010D74C 0010A68C  48 00 00 4C */	b .L_8010D798
.L_8010D750:
/* 8010D750 0010A690  88 9C 00 04 */	lbz r4, 4(r28)
/* 8010D754 0010A694  7F A3 EB 78 */	mr r3, r29
/* 8010D758 0010A698  38 A0 00 01 */	li r5, 1
/* 8010D75C 0010A69C  7C 84 07 74 */	extsb r4, r4
/* 8010D760 0010A6A0  48 00 03 21 */	bl getEnemyNum__Q24Game15GeneralEnemyMgrFib
/* 8010D764 0010A6A4  A0 1C 00 08 */	lhz r0, 8(r28)
/* 8010D768 0010A6A8  54 66 06 3E */	clrlwi r6, r3, 0x18
/* 8010D76C 0010A6AC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010D770 0010A6B0  41 82 00 20 */	beq .L_8010D790
/* 8010D774 0010A6B4  2C 06 00 00 */	cmpwi r6, 0
/* 8010D778 0010A6B8  40 81 00 18 */	ble .L_8010D790
/* 8010D77C 0010A6BC  88 BC 00 04 */	lbz r5, 4(r28)
/* 8010D780 0010A6C0  7F A3 EB 78 */	mr r3, r29
/* 8010D784 0010A6C4  7F C4 F3 78 */	mr r4, r30
/* 8010D788 0010A6C8  7C A5 07 74 */	extsb r5, r5
/* 8010D78C 0010A6CC  4B FF E5 B1 */	bl createEnemyMgr__Q24Game15GeneralEnemyMgrFUcii
.L_8010D790:
/* 8010D790 0010A6D0  3B 9C 00 34 */	addi r28, r28, 0x34
/* 8010D794 0010A6D4  3B 39 00 01 */	addi r25, r25, 1
.L_8010D798:
/* 8010D798 0010A6D8  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010D79C 0010A6DC  7C 19 00 00 */	cmpw r25, r0
/* 8010D7A0 0010A6E0  41 80 FF B0 */	blt .L_8010D750
/* 8010D7A4 0010A6E4  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D7A8 0010A6E8  48 31 5B C9 */	bl heapStatusNormal__6SystemFv
/* 8010D7AC 0010A6EC  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D7B0 0010A6F0  38 9F 00 88 */	addi r4, r31, 0x88
/* 8010D7B4 0010A6F4  48 31 5B B1 */	bl heapStatusEnd__6SystemFPc
/* 8010D7B8 0010A6F8  7F 63 DB 78 */	mr r3, r27
/* 8010D7BC 0010A6FC  4B F1 5D E9 */	bl becomeCurrentHeap__7JKRHeapFv
/* 8010D7C0 0010A700  80 7D 00 4C */	lwz r3, 0x4c(r29)
/* 8010D7C4 0010A704  38 00 00 01 */	li r0, 1
/* 8010D7C8 0010A708  28 1A 00 00 */	cmplwi r26, 0
/* 8010D7CC 0010A70C  98 03 00 69 */	stb r0, 0x69(r3)
/* 8010D7D0 0010A710  41 82 00 1C */	beq .L_8010D7EC
/* 8010D7D4 0010A714  7F 43 D3 78 */	mr r3, r26
/* 8010D7D8 0010A718  38 80 00 01 */	li r4, 1
/* 8010D7DC 0010A71C  81 9A 00 00 */	lwz r12, 0(r26)
/* 8010D7E0 0010A720  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010D7E4 0010A724  7D 89 03 A6 */	mtctr r12
/* 8010D7E8 0010A728  4E 80 04 21 */	bctrl 
.L_8010D7EC:
/* 8010D7EC 0010A72C  38 00 00 00 */	li r0, 0
/* 8010D7F0 0010A730  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 8010D7F4 0010A734  90 0D 91 A8 */	stw r0, gParmArc__4Game@sda21(r13)
/* 8010D7F8 0010A738  38 9F 00 40 */	addi r4, r31, 0x40
/* 8010D7FC 0010A73C  48 31 5B 69 */	bl heapStatusEnd__6SystemFPc
/* 8010D800 0010A740  BB 21 00 44 */	lmw r25, 0x44(r1)
/* 8010D804 0010A744  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8010D808 0010A748  7C 08 03 A6 */	mtlr r0
/* 8010D80C 0010A74C  38 21 00 60 */	addi r1, r1, 0x60
/* 8010D810 0010A750  4E 80 00 20 */	blr 
.endfn allocateEnemys__Q24Game15GeneralEnemyMgrFUci

.fn resetEnemyNum__Q24Game15GeneralEnemyMgrFv, global
/* 8010D814 0010A754  80 03 00 48 */	lwz r0, 0x48(r3)
/* 8010D818 0010A758  28 00 00 00 */	cmplwi r0, 0
/* 8010D81C 0010A75C  4D 82 00 20 */	beqlr 
/* 8010D820 0010A760  38 C0 00 00 */	li r6, 0
/* 8010D824 0010A764  7C C7 33 78 */	mr r7, r6
/* 8010D828 0010A768  7C C5 33 78 */	mr r5, r6
/* 8010D82C 0010A76C  48 00 00 18 */	b .L_8010D844
.L_8010D830:
/* 8010D830 0010A770  80 83 00 48 */	lwz r4, 0x48(r3)
/* 8010D834 0010A774  38 07 00 04 */	addi r0, r7, 4
/* 8010D838 0010A778  38 E7 00 08 */	addi r7, r7, 8
/* 8010D83C 0010A77C  38 C6 00 01 */	addi r6, r6, 1
/* 8010D840 0010A780  7C A4 01 AE */	stbx r5, r4, r0
.L_8010D844:
/* 8010D844 0010A784  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010D848 0010A788  7C 06 00 00 */	cmpw r6, r0
/* 8010D84C 0010A78C  41 80 FF E4 */	blt .L_8010D830
/* 8010D850 0010A790  4E 80 00 20 */	blr 
.endfn resetEnemyNum__Q24Game15GeneralEnemyMgrFv

.fn addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy, global
/* 8010D854 0010A794  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8010D858 0010A798  7C 08 02 A6 */	mflr r0
/* 8010D85C 0010A79C  90 01 00 34 */	stw r0, 0x34(r1)
/* 8010D860 0010A7A0  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 8010D864 0010A7A4  7C 9C 23 78 */	mr r28, r4
/* 8010D868 0010A7A8  2C 1C FF FF */	cmpwi r28, -1
/* 8010D86C 0010A7AC  7C 7B 1B 78 */	mr r27, r3
/* 8010D870 0010A7B0  7C BE 2B 78 */	mr r30, r5
/* 8010D874 0010A7B4  7C DD 33 78 */	mr r29, r6
/* 8010D878 0010A7B8  41 82 01 F4 */	beq .L_8010DA6C
/* 8010D87C 0010A7BC  3C 80 00 01 */	lis r4, 0x0000FFFF@ha
/* 8010D880 0010A7C0  7F 83 E3 78 */	mr r3, r28
/* 8010D884 0010A7C4  38 84 FF FF */	addi r4, r4, 0x0000FFFF@l
/* 8010D888 0010A7C8  48 01 5B 6D */	bl getEnemyMember__Q24Game13EnemyInfoFuncFii
/* 8010D88C 0010A7CC  57 DF 06 3E */	clrlwi r31, r30, 0x18
/* 8010D890 0010A7D0  80 DB 00 48 */	lwz r6, 0x48(r27)
/* 8010D894 0010A7D4  7C 1F 19 D6 */	mullw r0, r31, r3
/* 8010D898 0010A7D8  28 06 00 00 */	cmplwi r6, 0
/* 8010D89C 0010A7DC  54 05 06 3E */	clrlwi r5, r0, 0x18
/* 8010D8A0 0010A7E0  41 82 00 4C */	beq .L_8010D8EC
/* 8010D8A4 0010A7E4  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010D8A8 0010A7E8  7C C3 33 78 */	mr r3, r6
/* 8010D8AC 0010A7EC  38 80 00 00 */	li r4, 0
/* 8010D8B0 0010A7F0  7C 09 03 A6 */	mtctr r0
/* 8010D8B4 0010A7F4  2C 00 00 00 */	cmpwi r0, 0
/* 8010D8B8 0010A7F8  40 81 00 34 */	ble .L_8010D8EC
.L_8010D8BC:
/* 8010D8BC 0010A7FC  80 03 00 00 */	lwz r0, 0(r3)
/* 8010D8C0 0010A800  7C 1C 00 00 */	cmpw r28, r0
/* 8010D8C4 0010A804  40 82 00 1C */	bne .L_8010D8E0
/* 8010D8C8 0010A808  54 80 18 38 */	slwi r0, r4, 3
/* 8010D8CC 0010A80C  7C 66 02 14 */	add r3, r6, r0
/* 8010D8D0 0010A810  88 03 00 04 */	lbz r0, 4(r3)
/* 8010D8D4 0010A814  7C 00 2A 14 */	add r0, r0, r5
/* 8010D8D8 0010A818  98 03 00 04 */	stb r0, 4(r3)
/* 8010D8DC 0010A81C  48 00 00 10 */	b .L_8010D8EC
.L_8010D8E0:
/* 8010D8E0 0010A820  38 63 00 08 */	addi r3, r3, 8
/* 8010D8E4 0010A824  38 84 00 01 */	addi r4, r4, 1
/* 8010D8E8 0010A828  42 00 FF D4 */	bdnz .L_8010D8BC
.L_8010D8EC:
/* 8010D8EC 0010A82C  3B C0 00 00 */	li r30, 0
/* 8010D8F0 0010A830  48 00 01 74 */	b .L_8010DA64
.L_8010D8F4:
/* 8010D8F4 0010A834  2C 1C 00 32 */	cmpwi r28, 0x32
/* 8010D8F8 0010A838  41 82 00 20 */	beq .L_8010D918
/* 8010D8FC 0010A83C  40 80 00 10 */	bge .L_8010D90C
/* 8010D900 0010A840  2C 1C 00 2E */	cmpwi r28, 0x2e
/* 8010D904 0010A844  41 82 00 14 */	beq .L_8010D918
/* 8010D908 0010A848  48 00 00 88 */	b .L_8010D990
.L_8010D90C:
/* 8010D90C 0010A84C  2C 1C 00 57 */	cmpwi r28, 0x57
/* 8010D910 0010A850  41 82 00 08 */	beq .L_8010D918
/* 8010D914 0010A854  48 00 00 7C */	b .L_8010D990
.L_8010D918:
/* 8010D918 0010A858  28 1D 00 00 */	cmplwi r29, 0
/* 8010D91C 0010A85C  41 82 01 44 */	beq .L_8010DA60
/* 8010D920 0010A860  38 61 00 08 */	addi r3, r1, 8
/* 8010D924 0010A864  48 02 0A 29 */	bl __ct__Q24Game15EnemyPelletInfoFv
/* 8010D928 0010A868  88 1D 00 3C */	lbz r0, 0x3c(r29)
/* 8010D92C 0010A86C  88 7D 00 3D */	lbz r3, 0x3d(r29)
/* 8010D930 0010A870  88 9D 00 3E */	lbz r4, 0x3e(r29)
/* 8010D934 0010A874  28 00 00 00 */	cmplwi r0, 0
/* 8010D938 0010A878  88 BD 00 3F */	lbz r5, 0x3f(r29)
/* 8010D93C 0010A87C  C0 1D 00 40 */	lfs f0, 0x40(r29)
/* 8010D940 0010A880  98 01 00 08 */	stb r0, 8(r1)
/* 8010D944 0010A884  98 61 00 09 */	stb r3, 9(r1)
/* 8010D948 0010A888  98 81 00 0A */	stb r4, 0xa(r1)
/* 8010D94C 0010A88C  98 A1 00 0B */	stb r5, 0xb(r1)
/* 8010D950 0010A890  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8010D954 0010A894  40 82 01 0C */	bne .L_8010DA60
/* 8010D958 0010A898  28 03 00 01 */	cmplwi r3, 1
/* 8010D95C 0010A89C  40 82 01 04 */	bne .L_8010DA60
/* 8010D960 0010A8A0  3C 80 00 01 */	lis r4, 0x0000FFFF@ha
/* 8010D964 0010A8A4  7F 83 E3 78 */	mr r3, r28
/* 8010D968 0010A8A8  38 84 FF FF */	addi r4, r4, 0x0000FFFF@l
/* 8010D96C 0010A8AC  48 01 59 0D */	bl getEnemyInfo__Q24Game13EnemyInfoFuncFii
/* 8010D970 0010A8B0  7C 64 1B 78 */	mr r4, r3
/* 8010D974 0010A8B4  7F 63 DB 78 */	mr r3, r27
/* 8010D978 0010A8B8  80 04 00 2C */	lwz r0, 0x2c(r4)
/* 8010D97C 0010A8BC  38 C0 00 00 */	li r6, 0
/* 8010D980 0010A8C0  80 84 00 28 */	lwz r4, 0x28(r4)
/* 8010D984 0010A8C4  54 05 06 3E */	clrlwi r5, r0, 0x18
/* 8010D988 0010A8C8  4B FF FE CD */	bl addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy
/* 8010D98C 0010A8CC  48 00 00 D4 */	b .L_8010DA60
.L_8010D990:
/* 8010D990 0010A8D0  3C 80 00 01 */	lis r4, 0x0000FFFF@ha
/* 8010D994 0010A8D4  7F 83 E3 78 */	mr r3, r28
/* 8010D998 0010A8D8  38 84 FF FF */	addi r4, r4, 0x0000FFFF@l
/* 8010D99C 0010A8DC  48 01 58 DD */	bl getEnemyInfo__Q24Game13EnemyInfoFuncFii
/* 8010D9A0 0010A8E0  7C 64 1B 78 */	mr r4, r3
/* 8010D9A4 0010A8E4  7F 63 DB 78 */	mr r3, r27
/* 8010D9A8 0010A8E8  80 04 00 2C */	lwz r0, 0x2c(r4)
/* 8010D9AC 0010A8EC  38 C0 00 00 */	li r6, 0
/* 8010D9B0 0010A8F0  80 84 00 28 */	lwz r4, 0x28(r4)
/* 8010D9B4 0010A8F4  54 05 06 3E */	clrlwi r5, r0, 0x18
/* 8010D9B8 0010A8F8  4B FF FE 9D */	bl addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy
/* 8010D9BC 0010A8FC  2C 1C 00 5E */	cmpwi r28, 0x5e
/* 8010D9C0 0010A900  40 82 00 68 */	bne .L_8010DA28
/* 8010D9C4 0010A904  7F 63 DB 78 */	mr r3, r27
/* 8010D9C8 0010A908  38 80 00 25 */	li r4, 0x25
/* 8010D9CC 0010A90C  38 A0 00 01 */	li r5, 1
/* 8010D9D0 0010A910  48 00 00 B1 */	bl getEnemyNum__Q24Game15GeneralEnemyMgrFib
/* 8010D9D4 0010A914  54 60 06 3E */	clrlwi r0, r3, 0x18
/* 8010D9D8 0010A918  28 00 00 0A */	cmplwi r0, 0xa
/* 8010D9DC 0010A91C  40 80 00 18 */	bge .L_8010D9F4
/* 8010D9E0 0010A920  7F 63 DB 78 */	mr r3, r27
/* 8010D9E4 0010A924  38 80 00 25 */	li r4, 0x25
/* 8010D9E8 0010A928  38 A0 00 0A */	li r5, 0xa
/* 8010D9EC 0010A92C  38 C0 00 00 */	li r6, 0
/* 8010D9F0 0010A930  4B FF FE 65 */	bl addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy
.L_8010D9F4:
/* 8010D9F4 0010A934  7F 63 DB 78 */	mr r3, r27
/* 8010D9F8 0010A938  38 80 00 13 */	li r4, 0x13
/* 8010D9FC 0010A93C  38 A0 00 01 */	li r5, 1
/* 8010DA00 0010A940  48 00 00 81 */	bl getEnemyNum__Q24Game15GeneralEnemyMgrFib
/* 8010DA04 0010A944  54 60 06 3E */	clrlwi r0, r3, 0x18
/* 8010DA08 0010A948  28 00 00 1E */	cmplwi r0, 0x1e
/* 8010DA0C 0010A94C  40 80 00 54 */	bge .L_8010DA60
/* 8010DA10 0010A950  7F 63 DB 78 */	mr r3, r27
/* 8010DA14 0010A954  38 80 00 13 */	li r4, 0x13
/* 8010DA18 0010A958  38 A0 00 1E */	li r5, 0x1e
/* 8010DA1C 0010A95C  38 C0 00 00 */	li r6, 0
/* 8010DA20 0010A960  4B FF FE 35 */	bl addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy
/* 8010DA24 0010A964  48 00 00 3C */	b .L_8010DA60
.L_8010DA28:
/* 8010DA28 0010A968  2C 1C 00 1E */	cmpwi r28, 0x1e
/* 8010DA2C 0010A96C  40 82 00 34 */	bne .L_8010DA60
/* 8010DA30 0010A970  7F 63 DB 78 */	mr r3, r27
/* 8010DA34 0010A974  38 80 00 13 */	li r4, 0x13
/* 8010DA38 0010A978  38 A0 00 01 */	li r5, 1
/* 8010DA3C 0010A97C  48 00 00 45 */	bl getEnemyNum__Q24Game15GeneralEnemyMgrFib
/* 8010DA40 0010A980  54 60 06 3E */	clrlwi r0, r3, 0x18
/* 8010DA44 0010A984  28 00 00 0A */	cmplwi r0, 0xa
/* 8010DA48 0010A988  40 80 00 18 */	bge .L_8010DA60
/* 8010DA4C 0010A98C  7F 63 DB 78 */	mr r3, r27
/* 8010DA50 0010A990  38 80 00 13 */	li r4, 0x13
/* 8010DA54 0010A994  38 A0 00 0A */	li r5, 0xa
/* 8010DA58 0010A998  38 C0 00 00 */	li r6, 0
/* 8010DA5C 0010A99C  4B FF FD F9 */	bl addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy
.L_8010DA60:
/* 8010DA60 0010A9A0  3B DE 00 01 */	addi r30, r30, 1
.L_8010DA64:
/* 8010DA64 0010A9A4  7C 1E F8 00 */	cmpw r30, r31
/* 8010DA68 0010A9A8  41 80 FE 8C */	blt .L_8010D8F4
.L_8010DA6C:
/* 8010DA6C 0010A9AC  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 8010DA70 0010A9B0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8010DA74 0010A9B4  7C 08 03 A6 */	mtlr r0
/* 8010DA78 0010A9B8  38 21 00 30 */	addi r1, r1, 0x30
/* 8010DA7C 0010A9BC  4E 80 00 20 */	blr 
.endfn addEnemyNum__Q24Game15GeneralEnemyMgrFiUcPQ24Game14GenObjectEnemy

.fn getEnemyNum__Q24Game15GeneralEnemyMgrFib, global
/* 8010DA80 0010A9C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DA84 0010A9C4  54 A0 06 3F */	clrlwi. r0, r5, 0x18
/* 8010DA88 0010A9C8  38 E0 00 00 */	li r7, 0
/* 8010DA8C 0010A9CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010DA90 0010A9D0  93 C1 00 08 */	stw r30, 8(r1)
/* 8010DA94 0010A9D4  41 82 01 04 */	beq .L_8010DB98
/* 8010DA98 0010A9D8  83 E3 00 48 */	lwz r31, 0x48(r3)
/* 8010DA9C 0010A9DC  28 1F 00 00 */	cmplwi r31, 0
/* 8010DAA0 0010A9E0  41 82 01 3C */	beq .L_8010DBDC
/* 8010DAA4 0010A9E4  3C 60 80 4B */	lis r3, gEnemyInfo__4Game@ha
/* 8010DAA8 0010A9E8  81 8D 83 D0 */	lwz r12, gEnemyInfoNum__4Game@sda21(r13)
/* 8010DAAC 0010A9EC  3B C3 C5 38 */	addi r30, r3, gEnemyInfo__4Game@l
/* 8010DAB0 0010A9F0  38 60 FF FF */	li r3, -1
/* 8010DAB4 0010A9F4  7F C5 F3 78 */	mr r5, r30
/* 8010DAB8 0010A9F8  7D 89 03 A6 */	mtctr r12
/* 8010DABC 0010A9FC  2C 0C 00 00 */	cmpwi r12, 0
/* 8010DAC0 0010AA00  40 81 00 38 */	ble .L_8010DAF8
.L_8010DAC4:
/* 8010DAC4 0010AA04  88 05 00 04 */	lbz r0, 4(r5)
/* 8010DAC8 0010AA08  7C 00 07 74 */	extsb r0, r0
/* 8010DACC 0010AA0C  7C 00 20 00 */	cmpw r0, r4
/* 8010DAD0 0010AA10  40 82 00 20 */	bne .L_8010DAF0
/* 8010DAD4 0010AA14  A0 05 00 08 */	lhz r0, 8(r5)
/* 8010DAD8 0010AA18  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010DADC 0010AA1C  41 82 00 0C */	beq .L_8010DAE8
/* 8010DAE0 0010AA20  7C 83 23 78 */	mr r3, r4
/* 8010DAE4 0010AA24  48 00 00 0C */	b .L_8010DAF0
.L_8010DAE8:
/* 8010DAE8 0010AA28  88 65 00 05 */	lbz r3, 5(r5)
/* 8010DAEC 0010AA2C  7C 63 07 74 */	extsb r3, r3
.L_8010DAF0:
/* 8010DAF0 0010AA30  38 A5 00 34 */	addi r5, r5, 0x34
/* 8010DAF4 0010AA34  42 00 FF D0 */	bdnz .L_8010DAC4
.L_8010DAF8:
/* 8010DAF8 0010AA38  7C 04 18 50 */	subf r0, r4, r3
/* 8010DAFC 0010AA3C  38 C0 00 00 */	li r6, 0
/* 8010DB00 0010AA40  7C 00 00 34 */	cntlzw r0, r0
/* 8010DB04 0010AA44  7C CB 33 78 */	mr r11, r6
/* 8010DB08 0010AA48  54 03 DE 3E */	rlwinm r3, r0, 0x1b, 0x18, 0x1f
/* 8010DB0C 0010AA4C  48 00 00 80 */	b .L_8010DB8C
.L_8010DB10:
/* 8010DB10 0010AA50  28 03 00 00 */	cmplwi r3, 0
/* 8010DB14 0010AA54  7C BF 5A 14 */	add r5, r31, r11
/* 8010DB18 0010AA58  41 82 00 54 */	beq .L_8010DB6C
/* 8010DB1C 0010AA5C  7F CA F3 78 */	mr r10, r30
/* 8010DB20 0010AA60  81 25 00 00 */	lwz r9, 0(r5)
/* 8010DB24 0010AA64  39 00 FF FF */	li r8, -1
/* 8010DB28 0010AA68  7D 89 03 A6 */	mtctr r12
/* 8010DB2C 0010AA6C  2C 0C 00 00 */	cmpwi r12, 0
/* 8010DB30 0010AA70  40 81 00 40 */	ble .L_8010DB70
.L_8010DB34:
/* 8010DB34 0010AA74  88 0A 00 04 */	lbz r0, 4(r10)
/* 8010DB38 0010AA78  7C 00 07 74 */	extsb r0, r0
/* 8010DB3C 0010AA7C  7C 00 48 00 */	cmpw r0, r9
/* 8010DB40 0010AA80  40 82 00 20 */	bne .L_8010DB60
/* 8010DB44 0010AA84  A0 0A 00 08 */	lhz r0, 8(r10)
/* 8010DB48 0010AA88  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010DB4C 0010AA8C  41 82 00 0C */	beq .L_8010DB58
/* 8010DB50 0010AA90  7D 28 4B 78 */	mr r8, r9
/* 8010DB54 0010AA94  48 00 00 0C */	b .L_8010DB60
.L_8010DB58:
/* 8010DB58 0010AA98  89 0A 00 05 */	lbz r8, 5(r10)
/* 8010DB5C 0010AA9C  7D 08 07 74 */	extsb r8, r8
.L_8010DB60:
/* 8010DB60 0010AAA0  39 4A 00 34 */	addi r10, r10, 0x34
/* 8010DB64 0010AAA4  42 00 FF D0 */	bdnz .L_8010DB34
/* 8010DB68 0010AAA8  48 00 00 08 */	b .L_8010DB70
.L_8010DB6C:
/* 8010DB6C 0010AAAC  81 05 00 00 */	lwz r8, 0(r5)
.L_8010DB70:
/* 8010DB70 0010AAB0  7C 08 20 00 */	cmpw r8, r4
/* 8010DB74 0010AAB4  40 82 00 10 */	bne .L_8010DB84
/* 8010DB78 0010AAB8  88 05 00 04 */	lbz r0, 4(r5)
/* 8010DB7C 0010AABC  7C 07 02 14 */	add r0, r7, r0
/* 8010DB80 0010AAC0  54 07 06 3E */	clrlwi r7, r0, 0x18
.L_8010DB84:
/* 8010DB84 0010AAC4  39 6B 00 08 */	addi r11, r11, 8
/* 8010DB88 0010AAC8  38 C6 00 01 */	addi r6, r6, 1
.L_8010DB8C:
/* 8010DB8C 0010AACC  7C 06 60 00 */	cmpw r6, r12
/* 8010DB90 0010AAD0  41 80 FF 80 */	blt .L_8010DB10
/* 8010DB94 0010AAD4  48 00 00 48 */	b .L_8010DBDC
.L_8010DB98:
/* 8010DB98 0010AAD8  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010DB9C 0010AADC  7C E5 3B 78 */	mr r5, r7
/* 8010DBA0 0010AAE0  7C E6 3B 78 */	mr r6, r7
/* 8010DBA4 0010AAE4  7C 09 03 A6 */	mtctr r0
/* 8010DBA8 0010AAE8  2C 00 00 00 */	cmpwi r0, 0
/* 8010DBAC 0010AAEC  40 81 00 30 */	ble .L_8010DBDC
.L_8010DBB0:
/* 8010DBB0 0010AAF0  81 03 00 48 */	lwz r8, 0x48(r3)
/* 8010DBB4 0010AAF4  7C 08 30 2E */	lwzx r0, r8, r6
/* 8010DBB8 0010AAF8  7C 04 00 00 */	cmpw r4, r0
/* 8010DBBC 0010AAFC  40 82 00 14 */	bne .L_8010DBD0
/* 8010DBC0 0010AB00  54 A0 18 38 */	slwi r0, r5, 3
/* 8010DBC4 0010AB04  7C 68 02 14 */	add r3, r8, r0
/* 8010DBC8 0010AB08  88 E3 00 04 */	lbz r7, 4(r3)
/* 8010DBCC 0010AB0C  48 00 00 10 */	b .L_8010DBDC
.L_8010DBD0:
/* 8010DBD0 0010AB10  38 C6 00 08 */	addi r6, r6, 8
/* 8010DBD4 0010AB14  38 A5 00 01 */	addi r5, r5, 1
/* 8010DBD8 0010AB18  42 00 FF D8 */	bdnz .L_8010DBB0
.L_8010DBDC:
/* 8010DBDC 0010AB1C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010DBE0 0010AB20  7C E3 3B 78 */	mr r3, r7
/* 8010DBE4 0010AB24  83 C1 00 08 */	lwz r30, 8(r1)
/* 8010DBE8 0010AB28  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DBEC 0010AB2C  4E 80 00 20 */	blr 
.endfn getEnemyNum__Q24Game15GeneralEnemyMgrFib

.fn useHeap__Q24Game15GeneralEnemyMgrFv, global
/* 8010DBF0 0010AB30  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010DBF4 0010AB34  7C 08 02 A6 */	mflr r0
/* 8010DBF8 0010AB38  3C 80 80 4B */	lis r4, __vt__Q24Game15CreatureKillArg@ha
/* 8010DBFC 0010AB3C  38 A0 00 00 */	li r5, 0
/* 8010DC00 0010AB40  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010DC04 0010AB44  38 04 A2 D0 */	addi r0, r4, __vt__Q24Game15CreatureKillArg@l
/* 8010DC08 0010AB48  3C 80 80 4B */	lis r4, __vt__Q24Game12EnemyKillArg@ha
/* 8010DC0C 0010AB4C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010DC10 0010AB50  38 84 A2 C4 */	addi r4, r4, __vt__Q24Game12EnemyKillArg@l
/* 8010DC14 0010AB54  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010DC18 0010AB58  7C 7E 1B 78 */	mr r30, r3
/* 8010DC1C 0010AB5C  90 01 00 08 */	stw r0, 8(r1)
/* 8010DC20 0010AB60  64 A0 70 00 */	oris r0, r5, 0x7000
/* 8010DC24 0010AB64  90 A1 00 0C */	stw r5, 0xc(r1)
/* 8010DC28 0010AB68  90 81 00 08 */	stw r4, 8(r1)
/* 8010DC2C 0010AB6C  90 01 00 0C */	stw r0, 0xc(r1)
/* 8010DC30 0010AB70  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010DC34 0010AB74  48 00 00 20 */	b .L_8010DC54
.L_8010DC38:
/* 8010DC38 0010AB78  7F E3 FB 78 */	mr r3, r31
/* 8010DC3C 0010AB7C  38 81 00 08 */	addi r4, r1, 8
/* 8010DC40 0010AB80  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010DC44 0010AB84  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 8010DC48 0010AB88  7D 89 03 A6 */	mtctr r12
/* 8010DC4C 0010AB8C  4E 80 04 21 */	bctrl 
/* 8010DC50 0010AB90  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010DC54:
/* 8010DC54 0010AB94  28 1F 00 00 */	cmplwi r31, 0
/* 8010DC58 0010AB98  40 82 FF E0 */	bne .L_8010DC38
/* 8010DC5C 0010AB9C  80 7E 00 4C */	lwz r3, 0x4c(r30)
/* 8010DC60 0010ABA0  28 03 00 00 */	cmplwi r3, 0
/* 8010DC64 0010ABA4  41 82 00 1C */	beq .L_8010DC80
/* 8010DC68 0010ABA8  4B F1 5A C9 */	bl freeAll__7JKRHeapFv
/* 8010DC6C 0010ABAC  38 00 00 00 */	li r0, 0
/* 8010DC70 0010ABB0  90 1E 00 30 */	stw r0, 0x30(r30)
/* 8010DC74 0010ABB4  90 1E 00 2C */	stw r0, 0x2c(r30)
/* 8010DC78 0010ABB8  90 1E 00 28 */	stw r0, 0x28(r30)
/* 8010DC7C 0010ABBC  90 1E 00 24 */	stw r0, 0x24(r30)
.L_8010DC80:
/* 8010DC80 0010ABC0  38 00 00 00 */	li r0, 0
/* 8010DC84 0010ABC4  90 1E 00 14 */	stw r0, 0x14(r30)
/* 8010DC88 0010ABC8  80 7E 00 4C */	lwz r3, 0x4c(r30)
/* 8010DC8C 0010ABCC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010DC90 0010ABD0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010DC94 0010ABD4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010DC98 0010ABD8  7C 08 03 A6 */	mtlr r0
/* 8010DC9C 0010ABDC  38 21 00 20 */	addi r1, r1, 0x20
/* 8010DCA0 0010ABE0  4E 80 00 20 */	blr 
.endfn useHeap__Q24Game15GeneralEnemyMgrFv

.fn getEnemyMgr__Q24Game15GeneralEnemyMgrFi, global
/* 8010DCA4 0010ABE4  80 A3 00 30 */	lwz r5, 0x30(r3)
/* 8010DCA8 0010ABE8  38 60 00 00 */	li r3, 0
/* 8010DCAC 0010ABEC  48 00 00 18 */	b .L_8010DCC4
.L_8010DCB0:
/* 8010DCB0 0010ABF0  80 05 00 1C */	lwz r0, 0x1c(r5)
/* 8010DCB4 0010ABF4  7C 00 20 00 */	cmpw r0, r4
/* 8010DCB8 0010ABF8  40 82 00 08 */	bne .L_8010DCC0
/* 8010DCBC 0010ABFC  80 65 00 20 */	lwz r3, 0x20(r5)
.L_8010DCC0:
/* 8010DCC0 0010AC00  80 A5 00 04 */	lwz r5, 4(r5)
.L_8010DCC4:
/* 8010DCC4 0010AC04  28 05 00 00 */	cmplwi r5, 0
/* 8010DCC8 0010AC08  40 82 FF E8 */	bne .L_8010DCB0
/* 8010DCCC 0010AC0C  28 03 00 00 */	cmplwi r3, 0
/* 8010DCD0 0010AC10  4C 82 00 20 */	bnelr 
/* 8010DCD4 0010AC14  38 60 00 00 */	li r3, 0
/* 8010DCD8 0010AC18  4E 80 00 20 */	blr 
.endfn getEnemyMgr__Q24Game15GeneralEnemyMgrFi

.fn setMovieDraw__Q24Game15GeneralEnemyMgrFb, global
/* 8010DCDC 0010AC1C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DCE0 0010AC20  7C 08 02 A6 */	mflr r0
/* 8010DCE4 0010AC24  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DCE8 0010AC28  54 80 06 3F */	clrlwi. r0, r4, 0x18
/* 8010DCEC 0010AC2C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010DCF0 0010AC30  40 82 00 3C */	bne .L_8010DD2C
/* 8010DCF4 0010AC34  88 03 00 1C */	lbz r0, 0x1c(r3)
/* 8010DCF8 0010AC38  60 00 00 01 */	ori r0, r0, 1
/* 8010DCFC 0010AC3C  98 03 00 1C */	stb r0, 0x1c(r3)
/* 8010DD00 0010AC40  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010DD04 0010AC44  48 00 00 1C */	b .L_8010DD20
.L_8010DD08:
/* 8010DD08 0010AC48  7F E3 FB 78 */	mr r3, r31
/* 8010DD0C 0010AC4C  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010DD10 0010AC50  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8010DD14 0010AC54  7D 89 03 A6 */	mtctr r12
/* 8010DD18 0010AC58  4E 80 04 21 */	bctrl 
/* 8010DD1C 0010AC5C  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010DD20:
/* 8010DD20 0010AC60  28 1F 00 00 */	cmplwi r31, 0
/* 8010DD24 0010AC64  40 82 FF E4 */	bne .L_8010DD08
/* 8010DD28 0010AC68  48 00 00 38 */	b .L_8010DD60
.L_8010DD2C:
/* 8010DD2C 0010AC6C  88 03 00 1C */	lbz r0, 0x1c(r3)
/* 8010DD30 0010AC70  54 00 06 3C */	rlwinm r0, r0, 0, 0x18, 0x1e
/* 8010DD34 0010AC74  98 03 00 1C */	stb r0, 0x1c(r3)
/* 8010DD38 0010AC78  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8010DD3C 0010AC7C  48 00 00 1C */	b .L_8010DD58
.L_8010DD40:
/* 8010DD40 0010AC80  7F E3 FB 78 */	mr r3, r31
/* 8010DD44 0010AC84  81 9F 00 00 */	lwz r12, 0(r31)
/* 8010DD48 0010AC88  81 8C 00 78 */	lwz r12, 0x78(r12)
/* 8010DD4C 0010AC8C  7D 89 03 A6 */	mtctr r12
/* 8010DD50 0010AC90  4E 80 04 21 */	bctrl 
/* 8010DD54 0010AC94  83 FF 00 04 */	lwz r31, 4(r31)
.L_8010DD58:
/* 8010DD58 0010AC98  28 1F 00 00 */	cmplwi r31, 0
/* 8010DD5C 0010AC9C  40 82 FF E4 */	bne .L_8010DD40
.L_8010DD60:
/* 8010DD60 0010ACA0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DD64 0010ACA4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010DD68 0010ACA8  7C 08 03 A6 */	mtlr r0
/* 8010DD6C 0010ACAC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DD70 0010ACB0  4E 80 00 20 */	blr 
.endfn setMovieDraw__Q24Game15GeneralEnemyMgrFb

.fn endMovie__Q24Game12EnemyMgrNodeFv, weak
/* 8010DD74 0010ACB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DD78 0010ACB8  7C 08 02 A6 */	mflr r0
/* 8010DD7C 0010ACBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DD80 0010ACC0  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010DD84 0010ACC4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DD88 0010ACC8  81 8C 00 94 */	lwz r12, 0x94(r12)
/* 8010DD8C 0010ACCC  7D 89 03 A6 */	mtctr r12
/* 8010DD90 0010ACD0  4E 80 04 21 */	bctrl 
/* 8010DD94 0010ACD4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DD98 0010ACD8  7C 08 03 A6 */	mtlr r0
/* 8010DD9C 0010ACDC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DDA0 0010ACE0  4E 80 00 20 */	blr 
.endfn endMovie__Q24Game12EnemyMgrNodeFv

.fn startMovie__Q24Game12EnemyMgrNodeFv, weak
/* 8010DDA4 0010ACE4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DDA8 0010ACE8  7C 08 02 A6 */	mflr r0
/* 8010DDAC 0010ACEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DDB0 0010ACF0  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010DDB4 0010ACF4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DDB8 0010ACF8  81 8C 00 90 */	lwz r12, 0x90(r12)
/* 8010DDBC 0010ACFC  7D 89 03 A6 */	mtctr r12
/* 8010DDC0 0010AD00  4E 80 04 21 */	bctrl 
/* 8010DDC4 0010AD04  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DDC8 0010AD08  7C 08 03 A6 */	mtlr r0
/* 8010DDCC 0010AD0C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DDD0 0010AD10  4E 80 00 20 */	blr 
.endfn startMovie__Q24Game12EnemyMgrNodeFv

.fn prepareDayendEnemies__Q24Game15GeneralEnemyMgrFv, global
/* 8010DDD4 0010AD14  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8010DDD8 0010AD18  7C 08 02 A6 */	mflr r0
/* 8010DDDC 0010AD1C  90 01 00 34 */	stw r0, 0x34(r1)
/* 8010DDE0 0010AD20  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8010DDE4 0010AD24  3F E0 00 01 */	lis r31, 1
/* 8010DDE8 0010AD28  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8010DDEC 0010AD2C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8010DDF0 0010AD30  7C 7D 1B 78 */	mr r29, r3
/* 8010DDF4 0010AD34  83 C3 00 30 */	lwz r30, 0x30(r3)
/* 8010DDF8 0010AD38  48 00 00 74 */	b .L_8010DE6C
.L_8010DDFC:
/* 8010DDFC 0010AD3C  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8010DE00 0010AD40  38 9F FF FF */	addi r4, r31, -1
/* 8010DE04 0010AD44  48 01 54 75 */	bl getEnemyInfo__Q24Game13EnemyInfoFuncFii
/* 8010DE08 0010AD48  80 9D 00 30 */	lwz r4, 0x30(r29)
/* 8010DE0C 0010AD4C  48 00 00 08 */	b .L_8010DE14
.L_8010DE10:
/* 8010DE10 0010AD50  80 84 00 04 */	lwz r4, 4(r4)
.L_8010DE14:
/* 8010DE14 0010AD54  28 04 00 00 */	cmplwi r4, 0
/* 8010DE18 0010AD58  40 82 FF F8 */	bne .L_8010DE10
/* 8010DE1C 0010AD5C  A0 03 00 08 */	lhz r0, 8(r3)
/* 8010DE20 0010AD60  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 8010DE24 0010AD64  41 82 00 44 */	beq .L_8010DE68
/* 8010DE28 0010AD68  3C 60 80 4B */	lis r3, __vt__Q24Game15CreatureKillArg@ha
/* 8010DE2C 0010AD6C  38 80 00 00 */	li r4, 0
/* 8010DE30 0010AD70  38 03 A2 D0 */	addi r0, r3, __vt__Q24Game15CreatureKillArg@l
/* 8010DE34 0010AD74  3C 60 80 4B */	lis r3, __vt__Q24Game12EnemyKillArg@ha
/* 8010DE38 0010AD78  90 01 00 08 */	stw r0, 8(r1)
/* 8010DE3C 0010AD7C  38 A3 A2 C4 */	addi r5, r3, __vt__Q24Game12EnemyKillArg@l
/* 8010DE40 0010AD80  64 80 70 00 */	oris r0, r4, 0x7000
/* 8010DE44 0010AD84  7F C3 F3 78 */	mr r3, r30
/* 8010DE48 0010AD88  90 81 00 0C */	stw r4, 0xc(r1)
/* 8010DE4C 0010AD8C  38 81 00 08 */	addi r4, r1, 8
/* 8010DE50 0010AD90  90 A1 00 08 */	stw r5, 8(r1)
/* 8010DE54 0010AD94  90 01 00 0C */	stw r0, 0xc(r1)
/* 8010DE58 0010AD98  81 9E 00 00 */	lwz r12, 0(r30)
/* 8010DE5C 0010AD9C  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 8010DE60 0010ADA0  7D 89 03 A6 */	mtctr r12
/* 8010DE64 0010ADA4  4E 80 04 21 */	bctrl 
.L_8010DE68:
/* 8010DE68 0010ADA8  83 DE 00 04 */	lwz r30, 4(r30)
.L_8010DE6C:
/* 8010DE6C 0010ADAC  28 1E 00 00 */	cmplwi r30, 0
/* 8010DE70 0010ADB0  40 82 FF 8C */	bne .L_8010DDFC
/* 8010DE74 0010ADB4  28 1D 00 00 */	cmplwi r29, 0
/* 8010DE78 0010ADB8  7F A3 EB 78 */	mr r3, r29
/* 8010DE7C 0010ADBC  41 82 00 08 */	beq .L_8010DE84
/* 8010DE80 0010ADC0  38 7D 00 04 */	addi r3, r29, 4
.L_8010DE84:
/* 8010DE84 0010ADC4  38 00 00 00 */	li r0, 0
/* 8010DE88 0010ADC8  90 61 00 18 */	stw r3, 0x18(r1)
/* 8010DE8C 0010ADCC  38 61 00 10 */	addi r3, r1, 0x10
/* 8010DE90 0010ADD0  90 01 00 1C */	stw r0, 0x1c(r1)
/* 8010DE94 0010ADD4  90 01 00 10 */	stw r0, 0x10(r1)
/* 8010DE98 0010ADD8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DE9C 0010ADDC  48 00 05 F5 */	bl "first__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"
/* 8010DEA0 0010ADE0  3B E0 00 00 */	li r31, 0
/* 8010DEA4 0010ADE4  48 00 00 24 */	b .L_8010DEC8
.L_8010DEA8:
/* 8010DEA8 0010ADE8  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DEAC 0010ADEC  80 81 00 14 */	lwz r4, 0x14(r1)
/* 8010DEB0 0010ADF0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010DEB4 0010ADF4  7D 89 03 A6 */	mtctr r12
/* 8010DEB8 0010ADF8  4E 80 04 21 */	bctrl 
/* 8010DEBC 0010ADFC  9B E3 01 F3 */	stb r31, 0x1f3(r3)
/* 8010DEC0 0010AE00  38 61 00 10 */	addi r3, r1, 0x10
/* 8010DEC4 0010AE04  48 00 00 2D */	bl "next__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"
.L_8010DEC8:
/* 8010DEC8 0010AE08  80 61 00 10 */	lwz r3, 0x10(r1)
/* 8010DECC 0010AE0C  28 03 00 00 */	cmplwi r3, 0
/* 8010DED0 0010AE10  40 82 FF D8 */	bne .L_8010DEA8
/* 8010DED4 0010AE14  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8010DED8 0010AE18  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8010DEDC 0010AE1C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8010DEE0 0010AE20  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8010DEE4 0010AE24  7C 08 03 A6 */	mtlr r0
/* 8010DEE8 0010AE28  38 21 00 30 */	addi r1, r1, 0x30
/* 8010DEEC 0010AE2C  4E 80 00 20 */	blr 
.endfn prepareDayendEnemies__Q24Game15GeneralEnemyMgrFv

.fn "next__37GeneralMgrIterator<Q24Game9EnemyBase>Fv", weak
/* 8010DEF0 0010AE30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DEF4 0010AE34  7C 08 02 A6 */	mflr r0
/* 8010DEF8 0010AE38  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DEFC 0010AE3C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010DF00 0010AE40  7C 7F 1B 78 */	mr r31, r3
/* 8010DF04 0010AE44  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8010DF08 0010AE48  28 00 00 00 */	cmplwi r0, 0
/* 8010DF0C 0010AE4C  40 82 00 24 */	bne .L_8010DF30
/* 8010DF10 0010AE50  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010DF14 0010AE54  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010DF18 0010AE58  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DF1C 0010AE5C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010DF20 0010AE60  7D 89 03 A6 */	mtctr r12
/* 8010DF24 0010AE64  4E 80 04 21 */	bctrl 
/* 8010DF28 0010AE68  90 7F 00 04 */	stw r3, 4(r31)
/* 8010DF2C 0010AE6C  48 00 00 8C */	b .L_8010DFB8
.L_8010DF30:
/* 8010DF30 0010AE70  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010DF34 0010AE74  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DF38 0010AE78  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010DF3C 0010AE7C  7D 89 03 A6 */	mtctr r12
/* 8010DF40 0010AE80  4E 80 04 21 */	bctrl 
/* 8010DF44 0010AE84  90 7F 00 04 */	stw r3, 4(r31)
/* 8010DF48 0010AE88  48 00 00 50 */	b .L_8010DF98
.L_8010DF4C:
/* 8010DF4C 0010AE8C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010DF50 0010AE90  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DF54 0010AE94  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010DF58 0010AE98  7D 89 03 A6 */	mtctr r12
/* 8010DF5C 0010AE9C  4E 80 04 21 */	bctrl 
/* 8010DF60 0010AEA0  7C 64 1B 78 */	mr r4, r3
/* 8010DF64 0010AEA4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8010DF68 0010AEA8  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DF6C 0010AEAC  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010DF70 0010AEB0  7D 89 03 A6 */	mtctr r12
/* 8010DF74 0010AEB4  4E 80 04 21 */	bctrl 
/* 8010DF78 0010AEB8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8010DF7C 0010AEBC  40 82 00 70 */	bne .L_8010DFEC
/* 8010DF80 0010AEC0  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010DF84 0010AEC4  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010DF88 0010AEC8  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DF8C 0010AECC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010DF90 0010AED0  7D 89 03 A6 */	mtctr r12
/* 8010DF94 0010AED4  4E 80 04 21 */	bctrl 
.L_8010DF98:
/* 8010DF98 0010AED8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010DF9C 0010AEDC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DFA0 0010AEE0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010DFA4 0010AEE4  7D 89 03 A6 */	mtctr r12
/* 8010DFA8 0010AEE8  4E 80 04 21 */	bctrl 
/* 8010DFAC 0010AEEC  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010DFB0 0010AEF0  7C 04 18 40 */	cmplw r4, r3
/* 8010DFB4 0010AEF4  40 82 FF 98 */	bne .L_8010DF4C
.L_8010DFB8:
/* 8010DFB8 0010AEF8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010DFBC 0010AEFC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010DFC0 0010AF00  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010DFC4 0010AF04  7D 89 03 A6 */	mtctr r12
/* 8010DFC8 0010AF08  4E 80 04 21 */	bctrl 
/* 8010DFCC 0010AF0C  80 1F 00 04 */	lwz r0, 4(r31)
/* 8010DFD0 0010AF10  7C 00 18 40 */	cmplw r0, r3
/* 8010DFD4 0010AF14  40 82 00 18 */	bne .L_8010DFEC
/* 8010DFD8 0010AF18  80 9F 00 00 */	lwz r4, 0(r31)
/* 8010DFDC 0010AF1C  7F E3 FB 78 */	mr r3, r31
/* 8010DFE0 0010AF20  80 04 00 04 */	lwz r0, 4(r4)
/* 8010DFE4 0010AF24  90 1F 00 00 */	stw r0, 0(r31)
/* 8010DFE8 0010AF28  48 00 00 19 */	bl "setFirst__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"
.L_8010DFEC:
/* 8010DFEC 0010AF2C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DFF0 0010AF30  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010DFF4 0010AF34  7C 08 03 A6 */	mtlr r0
/* 8010DFF8 0010AF38  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DFFC 0010AF3C  4E 80 00 20 */	blr 
.endfn "next__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"

.fn "setFirst__37GeneralMgrIterator<Q24Game9EnemyBase>Fv", weak
/* 8010E000 0010AF40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E004 0010AF44  7C 08 02 A6 */	mflr r0
/* 8010E008 0010AF48  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E00C 0010AF4C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E010 0010AF50  7C 7F 1B 78 */	mr r31, r3
/* 8010E014 0010AF54  80 63 00 00 */	lwz r3, 0(r3)
/* 8010E018 0010AF58  28 03 00 00 */	cmplwi r3, 0
/* 8010E01C 0010AF5C  41 82 04 60 */	beq .L_8010E47C
/* 8010E020 0010AF60  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8010E024 0010AF64  28 00 00 00 */	cmplwi r0, 0
/* 8010E028 0010AF68  40 82 00 1C */	bne .L_8010E044
/* 8010E02C 0010AF6C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E030 0010AF70  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E034 0010AF74  7D 89 03 A6 */	mtctr r12
/* 8010E038 0010AF78  4E 80 04 21 */	bctrl 
/* 8010E03C 0010AF7C  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E040 0010AF80  48 00 00 88 */	b .L_8010E0C8
.L_8010E044:
/* 8010E044 0010AF84  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E048 0010AF88  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E04C 0010AF8C  7D 89 03 A6 */	mtctr r12
/* 8010E050 0010AF90  4E 80 04 21 */	bctrl 
/* 8010E054 0010AF94  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E058 0010AF98  48 00 00 50 */	b .L_8010E0A8
.L_8010E05C:
/* 8010E05C 0010AF9C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E060 0010AFA0  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E064 0010AFA4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010E068 0010AFA8  7D 89 03 A6 */	mtctr r12
/* 8010E06C 0010AFAC  4E 80 04 21 */	bctrl 
/* 8010E070 0010AFB0  7C 64 1B 78 */	mr r4, r3
/* 8010E074 0010AFB4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8010E078 0010AFB8  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E07C 0010AFBC  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010E080 0010AFC0  7D 89 03 A6 */	mtctr r12
/* 8010E084 0010AFC4  4E 80 04 21 */	bctrl 
/* 8010E088 0010AFC8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8010E08C 0010AFCC  40 82 03 F0 */	bne .L_8010E47C
/* 8010E090 0010AFD0  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E094 0010AFD4  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E098 0010AFD8  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E09C 0010AFDC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010E0A0 0010AFE0  7D 89 03 A6 */	mtctr r12
/* 8010E0A4 0010AFE4  4E 80 04 21 */	bctrl 
.L_8010E0A8:
/* 8010E0A8 0010AFE8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E0AC 0010AFEC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E0B0 0010AFF0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E0B4 0010AFF4  7D 89 03 A6 */	mtctr r12
/* 8010E0B8 0010AFF8  4E 80 04 21 */	bctrl 
/* 8010E0BC 0010AFFC  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E0C0 0010B000  7C 04 18 40 */	cmplw r4, r3
/* 8010E0C4 0010B004  40 82 FF 98 */	bne .L_8010E05C
.L_8010E0C8:
/* 8010E0C8 0010B008  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E0CC 0010B00C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E0D0 0010B010  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E0D4 0010B014  7D 89 03 A6 */	mtctr r12
/* 8010E0D8 0010B018  4E 80 04 21 */	bctrl 
/* 8010E0DC 0010B01C  80 1F 00 04 */	lwz r0, 4(r31)
/* 8010E0E0 0010B020  7C 00 18 40 */	cmplw r0, r3
/* 8010E0E4 0010B024  40 82 03 98 */	bne .L_8010E47C
/* 8010E0E8 0010B028  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E0EC 0010B02C  80 03 00 04 */	lwz r0, 4(r3)
/* 8010E0F0 0010B030  90 1F 00 00 */	stw r0, 0(r31)
/* 8010E0F4 0010B034  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E0F8 0010B038  28 03 00 00 */	cmplwi r3, 0
/* 8010E0FC 0010B03C  41 82 03 80 */	beq .L_8010E47C
/* 8010E100 0010B040  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8010E104 0010B044  28 00 00 00 */	cmplwi r0, 0
/* 8010E108 0010B048  40 82 00 1C */	bne .L_8010E124
/* 8010E10C 0010B04C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E110 0010B050  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E114 0010B054  7D 89 03 A6 */	mtctr r12
/* 8010E118 0010B058  4E 80 04 21 */	bctrl 
/* 8010E11C 0010B05C  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E120 0010B060  48 00 00 88 */	b .L_8010E1A8
.L_8010E124:
/* 8010E124 0010B064  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E128 0010B068  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E12C 0010B06C  7D 89 03 A6 */	mtctr r12
/* 8010E130 0010B070  4E 80 04 21 */	bctrl 
/* 8010E134 0010B074  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E138 0010B078  48 00 00 50 */	b .L_8010E188
.L_8010E13C:
/* 8010E13C 0010B07C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E140 0010B080  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E144 0010B084  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010E148 0010B088  7D 89 03 A6 */	mtctr r12
/* 8010E14C 0010B08C  4E 80 04 21 */	bctrl 
/* 8010E150 0010B090  7C 64 1B 78 */	mr r4, r3
/* 8010E154 0010B094  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8010E158 0010B098  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E15C 0010B09C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010E160 0010B0A0  7D 89 03 A6 */	mtctr r12
/* 8010E164 0010B0A4  4E 80 04 21 */	bctrl 
/* 8010E168 0010B0A8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8010E16C 0010B0AC  40 82 03 10 */	bne .L_8010E47C
/* 8010E170 0010B0B0  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E174 0010B0B4  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E178 0010B0B8  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E17C 0010B0BC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010E180 0010B0C0  7D 89 03 A6 */	mtctr r12
/* 8010E184 0010B0C4  4E 80 04 21 */	bctrl 
.L_8010E188:
/* 8010E188 0010B0C8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E18C 0010B0CC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E190 0010B0D0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E194 0010B0D4  7D 89 03 A6 */	mtctr r12
/* 8010E198 0010B0D8  4E 80 04 21 */	bctrl 
/* 8010E19C 0010B0DC  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E1A0 0010B0E0  7C 04 18 40 */	cmplw r4, r3
/* 8010E1A4 0010B0E4  40 82 FF 98 */	bne .L_8010E13C
.L_8010E1A8:
/* 8010E1A8 0010B0E8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E1AC 0010B0EC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E1B0 0010B0F0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E1B4 0010B0F4  7D 89 03 A6 */	mtctr r12
/* 8010E1B8 0010B0F8  4E 80 04 21 */	bctrl 
/* 8010E1BC 0010B0FC  80 1F 00 04 */	lwz r0, 4(r31)
/* 8010E1C0 0010B100  7C 00 18 40 */	cmplw r0, r3
/* 8010E1C4 0010B104  40 82 02 B8 */	bne .L_8010E47C
/* 8010E1C8 0010B108  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E1CC 0010B10C  80 03 00 04 */	lwz r0, 4(r3)
/* 8010E1D0 0010B110  90 1F 00 00 */	stw r0, 0(r31)
/* 8010E1D4 0010B114  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E1D8 0010B118  28 03 00 00 */	cmplwi r3, 0
/* 8010E1DC 0010B11C  41 82 02 A0 */	beq .L_8010E47C
/* 8010E1E0 0010B120  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8010E1E4 0010B124  28 00 00 00 */	cmplwi r0, 0
/* 8010E1E8 0010B128  40 82 00 1C */	bne .L_8010E204
/* 8010E1EC 0010B12C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E1F0 0010B130  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E1F4 0010B134  7D 89 03 A6 */	mtctr r12
/* 8010E1F8 0010B138  4E 80 04 21 */	bctrl 
/* 8010E1FC 0010B13C  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E200 0010B140  48 00 00 88 */	b .L_8010E288
.L_8010E204:
/* 8010E204 0010B144  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E208 0010B148  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E20C 0010B14C  7D 89 03 A6 */	mtctr r12
/* 8010E210 0010B150  4E 80 04 21 */	bctrl 
/* 8010E214 0010B154  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E218 0010B158  48 00 00 50 */	b .L_8010E268
.L_8010E21C:
/* 8010E21C 0010B15C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E220 0010B160  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E224 0010B164  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010E228 0010B168  7D 89 03 A6 */	mtctr r12
/* 8010E22C 0010B16C  4E 80 04 21 */	bctrl 
/* 8010E230 0010B170  7C 64 1B 78 */	mr r4, r3
/* 8010E234 0010B174  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8010E238 0010B178  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E23C 0010B17C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010E240 0010B180  7D 89 03 A6 */	mtctr r12
/* 8010E244 0010B184  4E 80 04 21 */	bctrl 
/* 8010E248 0010B188  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8010E24C 0010B18C  40 82 02 30 */	bne .L_8010E47C
/* 8010E250 0010B190  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E254 0010B194  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E258 0010B198  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E25C 0010B19C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010E260 0010B1A0  7D 89 03 A6 */	mtctr r12
/* 8010E264 0010B1A4  4E 80 04 21 */	bctrl 
.L_8010E268:
/* 8010E268 0010B1A8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E26C 0010B1AC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E270 0010B1B0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E274 0010B1B4  7D 89 03 A6 */	mtctr r12
/* 8010E278 0010B1B8  4E 80 04 21 */	bctrl 
/* 8010E27C 0010B1BC  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E280 0010B1C0  7C 04 18 40 */	cmplw r4, r3
/* 8010E284 0010B1C4  40 82 FF 98 */	bne .L_8010E21C
.L_8010E288:
/* 8010E288 0010B1C8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E28C 0010B1CC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E290 0010B1D0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E294 0010B1D4  7D 89 03 A6 */	mtctr r12
/* 8010E298 0010B1D8  4E 80 04 21 */	bctrl 
/* 8010E29C 0010B1DC  80 1F 00 04 */	lwz r0, 4(r31)
/* 8010E2A0 0010B1E0  7C 00 18 40 */	cmplw r0, r3
/* 8010E2A4 0010B1E4  40 82 01 D8 */	bne .L_8010E47C
/* 8010E2A8 0010B1E8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E2AC 0010B1EC  80 03 00 04 */	lwz r0, 4(r3)
/* 8010E2B0 0010B1F0  90 1F 00 00 */	stw r0, 0(r31)
/* 8010E2B4 0010B1F4  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E2B8 0010B1F8  28 03 00 00 */	cmplwi r3, 0
/* 8010E2BC 0010B1FC  41 82 01 C0 */	beq .L_8010E47C
/* 8010E2C0 0010B200  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8010E2C4 0010B204  28 00 00 00 */	cmplwi r0, 0
/* 8010E2C8 0010B208  40 82 00 1C */	bne .L_8010E2E4
/* 8010E2CC 0010B20C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E2D0 0010B210  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E2D4 0010B214  7D 89 03 A6 */	mtctr r12
/* 8010E2D8 0010B218  4E 80 04 21 */	bctrl 
/* 8010E2DC 0010B21C  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E2E0 0010B220  48 00 00 88 */	b .L_8010E368
.L_8010E2E4:
/* 8010E2E4 0010B224  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E2E8 0010B228  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E2EC 0010B22C  7D 89 03 A6 */	mtctr r12
/* 8010E2F0 0010B230  4E 80 04 21 */	bctrl 
/* 8010E2F4 0010B234  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E2F8 0010B238  48 00 00 50 */	b .L_8010E348
.L_8010E2FC:
/* 8010E2FC 0010B23C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E300 0010B240  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E304 0010B244  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010E308 0010B248  7D 89 03 A6 */	mtctr r12
/* 8010E30C 0010B24C  4E 80 04 21 */	bctrl 
/* 8010E310 0010B250  7C 64 1B 78 */	mr r4, r3
/* 8010E314 0010B254  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8010E318 0010B258  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E31C 0010B25C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010E320 0010B260  7D 89 03 A6 */	mtctr r12
/* 8010E324 0010B264  4E 80 04 21 */	bctrl 
/* 8010E328 0010B268  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8010E32C 0010B26C  40 82 01 50 */	bne .L_8010E47C
/* 8010E330 0010B270  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E334 0010B274  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E338 0010B278  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E33C 0010B27C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010E340 0010B280  7D 89 03 A6 */	mtctr r12
/* 8010E344 0010B284  4E 80 04 21 */	bctrl 
.L_8010E348:
/* 8010E348 0010B288  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E34C 0010B28C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E350 0010B290  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E354 0010B294  7D 89 03 A6 */	mtctr r12
/* 8010E358 0010B298  4E 80 04 21 */	bctrl 
/* 8010E35C 0010B29C  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E360 0010B2A0  7C 04 18 40 */	cmplw r4, r3
/* 8010E364 0010B2A4  40 82 FF 98 */	bne .L_8010E2FC
.L_8010E368:
/* 8010E368 0010B2A8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E36C 0010B2AC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E370 0010B2B0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E374 0010B2B4  7D 89 03 A6 */	mtctr r12
/* 8010E378 0010B2B8  4E 80 04 21 */	bctrl 
/* 8010E37C 0010B2BC  80 1F 00 04 */	lwz r0, 4(r31)
/* 8010E380 0010B2C0  7C 00 18 40 */	cmplw r0, r3
/* 8010E384 0010B2C4  40 82 00 F8 */	bne .L_8010E47C
/* 8010E388 0010B2C8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E38C 0010B2CC  80 03 00 04 */	lwz r0, 4(r3)
/* 8010E390 0010B2D0  90 1F 00 00 */	stw r0, 0(r31)
/* 8010E394 0010B2D4  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E398 0010B2D8  28 03 00 00 */	cmplwi r3, 0
/* 8010E39C 0010B2DC  41 82 00 E0 */	beq .L_8010E47C
/* 8010E3A0 0010B2E0  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8010E3A4 0010B2E4  28 00 00 00 */	cmplwi r0, 0
/* 8010E3A8 0010B2E8  40 82 00 1C */	bne .L_8010E3C4
/* 8010E3AC 0010B2EC  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E3B0 0010B2F0  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E3B4 0010B2F4  7D 89 03 A6 */	mtctr r12
/* 8010E3B8 0010B2F8  4E 80 04 21 */	bctrl 
/* 8010E3BC 0010B2FC  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E3C0 0010B300  48 00 00 88 */	b .L_8010E448
.L_8010E3C4:
/* 8010E3C4 0010B304  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E3C8 0010B308  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8010E3CC 0010B30C  7D 89 03 A6 */	mtctr r12
/* 8010E3D0 0010B310  4E 80 04 21 */	bctrl 
/* 8010E3D4 0010B314  90 7F 00 04 */	stw r3, 4(r31)
/* 8010E3D8 0010B318  48 00 00 50 */	b .L_8010E428
.L_8010E3DC:
/* 8010E3DC 0010B31C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E3E0 0010B320  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E3E4 0010B324  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010E3E8 0010B328  7D 89 03 A6 */	mtctr r12
/* 8010E3EC 0010B32C  4E 80 04 21 */	bctrl 
/* 8010E3F0 0010B330  7C 64 1B 78 */	mr r4, r3
/* 8010E3F4 0010B334  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8010E3F8 0010B338  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E3FC 0010B33C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8010E400 0010B340  7D 89 03 A6 */	mtctr r12
/* 8010E404 0010B344  4E 80 04 21 */	bctrl 
/* 8010E408 0010B348  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8010E40C 0010B34C  40 82 00 70 */	bne .L_8010E47C
/* 8010E410 0010B350  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E414 0010B354  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E418 0010B358  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E41C 0010B35C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8010E420 0010B360  7D 89 03 A6 */	mtctr r12
/* 8010E424 0010B364  4E 80 04 21 */	bctrl 
.L_8010E428:
/* 8010E428 0010B368  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E42C 0010B36C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E430 0010B370  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E434 0010B374  7D 89 03 A6 */	mtctr r12
/* 8010E438 0010B378  4E 80 04 21 */	bctrl 
/* 8010E43C 0010B37C  80 9F 00 04 */	lwz r4, 4(r31)
/* 8010E440 0010B380  7C 04 18 40 */	cmplw r4, r3
/* 8010E444 0010B384  40 82 FF 98 */	bne .L_8010E3DC
.L_8010E448:
/* 8010E448 0010B388  80 7F 00 00 */	lwz r3, 0(r31)
/* 8010E44C 0010B38C  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E450 0010B390  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8010E454 0010B394  7D 89 03 A6 */	mtctr r12
/* 8010E458 0010B398  4E 80 04 21 */	bctrl 
/* 8010E45C 0010B39C  80 1F 00 04 */	lwz r0, 4(r31)
/* 8010E460 0010B3A0  7C 00 18 40 */	cmplw r0, r3
/* 8010E464 0010B3A4  40 82 00 18 */	bne .L_8010E47C
/* 8010E468 0010B3A8  80 9F 00 00 */	lwz r4, 0(r31)
/* 8010E46C 0010B3AC  7F E3 FB 78 */	mr r3, r31
/* 8010E470 0010B3B0  80 04 00 04 */	lwz r0, 4(r4)
/* 8010E474 0010B3B4  90 1F 00 00 */	stw r0, 0(r31)
/* 8010E478 0010B3B8  4B FF FB 89 */	bl "setFirst__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"
.L_8010E47C:
/* 8010E47C 0010B3BC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E480 0010B3C0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E484 0010B3C4  7C 08 03 A6 */	mtlr r0
/* 8010E488 0010B3C8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E48C 0010B3CC  4E 80 00 20 */	blr 
.endfn "setFirst__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"

.fn "first__37GeneralMgrIterator<Q24Game9EnemyBase>Fv", weak
/* 8010E490 0010B3D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E494 0010B3D4  7C 08 02 A6 */	mflr r0
/* 8010E498 0010B3D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E49C 0010B3DC  80 83 00 08 */	lwz r4, 8(r3)
/* 8010E4A0 0010B3E0  80 04 00 10 */	lwz r0, 0x10(r4)
/* 8010E4A4 0010B3E4  90 03 00 00 */	stw r0, 0(r3)
/* 8010E4A8 0010B3E8  4B FF FB 59 */	bl "setFirst__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"
/* 8010E4AC 0010B3EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E4B0 0010B3F0  7C 08 03 A6 */	mtlr r0
/* 8010E4B4 0010B3F4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E4B8 0010B3F8  4E 80 00 20 */	blr 
.endfn "first__37GeneralMgrIterator<Q24Game9EnemyBase>Fv"

.fn createDayendEnemies__Q24Game15GeneralEnemyMgrFRQ23Sys6Sphere, global
/* 8010E4BC 0010B3FC  94 21 FE 90 */	stwu r1, -0x170(r1)
/* 8010E4C0 0010B400  7C 08 02 A6 */	mflr r0
/* 8010E4C4 0010B404  90 01 01 74 */	stw r0, 0x174(r1)
/* 8010E4C8 0010B408  DB E1 01 60 */	stfd f31, 0x160(r1)
/* 8010E4CC 0010B40C  F3 E1 01 68 */	psq_st f31, 360(r1), 0, qr0
/* 8010E4D0 0010B410  DB C1 01 50 */	stfd f30, 0x150(r1)
/* 8010E4D4 0010B414  F3 C1 01 58 */	psq_st f30, 344(r1), 0, qr0
/* 8010E4D8 0010B418  DB A1 01 40 */	stfd f29, 0x140(r1)
/* 8010E4DC 0010B41C  F3 A1 01 48 */	psq_st f29, 328(r1), 0, qr0
/* 8010E4E0 0010B420  DB 81 01 30 */	stfd f28, 0x130(r1)
/* 8010E4E4 0010B424  F3 81 01 38 */	psq_st f28, 312(r1), 0, qr0
/* 8010E4E8 0010B428  DB 61 01 20 */	stfd f27, 0x120(r1)
/* 8010E4EC 0010B42C  F3 61 01 28 */	psq_st f27, 296(r1), 0, qr0
/* 8010E4F0 0010B430  BE A1 00 F4 */	stmw r21, 0xf4(r1)
/* 8010E4F4 0010B434  7C 7E 1B 78 */	mr r30, r3
/* 8010E4F8 0010B438  7C 9F 23 78 */	mr r31, r4
/* 8010E4FC 0010B43C  38 7E 00 20 */	addi r3, r30, 0x20
/* 8010E500 0010B440  81 9E 00 20 */	lwz r12, 0x20(r30)
/* 8010E504 0010B444  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8010E508 0010B448  7D 89 03 A6 */	mtctr r12
/* 8010E50C 0010B44C  4E 80 04 21 */	bctrl 
/* 8010E510 0010B450  2C 03 00 00 */	cmpwi r3, 0
/* 8010E514 0010B454  41 82 0B F0 */	beq .L_8010F104
/* 8010E518 0010B458  CB C2 96 68 */	lfd f30, lbl_805179C8@sda21(r2)
/* 8010E51C 0010B45C  3B A0 00 00 */	li r29, 0
/* 8010E520 0010B460  C3 E2 96 48 */	lfs f31, lbl_805179A8@sda21(r2)
/* 8010E524 0010B464  3F 80 00 01 */	lis r28, 1
/* 8010E528 0010B468  3F 40 43 30 */	lis r26, 0x4330
/* 8010E52C 0010B46C  48 00 0B D0 */	b .L_8010F0FC
.L_8010E530:
/* 8010E530 0010B470  4B FB B0 71 */	bl rand
/* 8010E534 0010B474  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8010E538 0010B478  38 7E 00 20 */	addi r3, r30, 0x20
/* 8010E53C 0010B47C  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8010E540 0010B480  81 9E 00 20 */	lwz r12, 0x20(r30)
/* 8010E544 0010B484  93 41 00 D0 */	stw r26, 0xd0(r1)
/* 8010E548 0010B488  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8010E54C 0010B48C  C8 01 00 D0 */	lfd f0, 0xd0(r1)
/* 8010E550 0010B490  EC 00 F0 28 */	fsubs f0, f0, f30
/* 8010E554 0010B494  EF 80 F8 24 */	fdivs f28, f0, f31
/* 8010E558 0010B498  7D 89 03 A6 */	mtctr r12
/* 8010E55C 0010B49C  4E 80 04 21 */	bctrl 
/* 8010E560 0010B4A0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8010E564 0010B4A4  93 41 00 D8 */	stw r26, 0xd8(r1)
/* 8010E568 0010B4A8  38 7E 00 20 */	addi r3, r30, 0x20
/* 8010E56C 0010B4AC  90 01 00 DC */	stw r0, 0xdc(r1)
/* 8010E570 0010B4B0  C8 01 00 D8 */	lfd f0, 0xd8(r1)
/* 8010E574 0010B4B4  EC 00 F0 28 */	fsubs f0, f0, f30
/* 8010E578 0010B4B8  EC 1C 00 32 */	fmuls f0, f28, f0
/* 8010E57C 0010B4BC  FC 00 00 1E */	fctiwz f0, f0
/* 8010E580 0010B4C0  D8 01 00 E0 */	stfd f0, 0xe0(r1)
/* 8010E584 0010B4C4  80 81 00 E4 */	lwz r4, 0xe4(r1)
/* 8010E588 0010B4C8  48 30 31 15 */	bl getChildAt__5CNodeFi
/* 8010E58C 0010B4CC  7C 77 1B 78 */	mr r23, r3
/* 8010E590 0010B4D0  7E FB BB 78 */	mr r27, r23
.L_8010E594:
/* 8010E594 0010B4D4  80 7B 00 1C */	lwz r3, 0x1c(r27)
/* 8010E598 0010B4D8  38 9C FF FF */	addi r4, r28, -1
/* 8010E59C 0010B4DC  48 01 4C DD */	bl getEnemyInfo__Q24Game13EnemyInfoFuncFii
/* 8010E5A0 0010B4E0  80 9B 00 1C */	lwz r4, 0x1c(r27)
/* 8010E5A4 0010B4E4  7C 78 1B 78 */	mr r24, r3
/* 8010E5A8 0010B4E8  80 7E 00 30 */	lwz r3, 0x30(r30)
/* 8010E5AC 0010B4EC  3B 20 00 00 */	li r25, 0
/* 8010E5B0 0010B4F0  48 00 00 18 */	b .L_8010E5C8
.L_8010E5B4:
/* 8010E5B4 0010B4F4  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 8010E5B8 0010B4F8  7C 00 20 00 */	cmpw r0, r4
/* 8010E5BC 0010B4FC  40 82 00 08 */	bne .L_8010E5C4
/* 8010E5C0 0010B500  83 23 00 20 */	lwz r25, 0x20(r3)
.L_8010E5C4:
/* 8010E5C4 0010B504  80 63 00 04 */	lwz r3, 4(r3)
.L_8010E5C8:
/* 8010E5C8 0010B508  28 03 00 00 */	cmplwi r3, 0
/* 8010E5CC 0010B50C  40 82 FF E8 */	bne .L_8010E5B4
/* 8010E5D0 0010B510  80 6D 94 90 */	lwz r3, playData__4Game@sda21(r13)
/* 8010E5D4 0010B514  38 63 00 40 */	addi r3, r3, 0x40
/* 8010E5D8 0010B518  48 12 54 ED */	bl getTekiInfo__Q34Game8TekiStat3MgrFi
/* 8010E5DC 0010B51C  7C 75 1B 79 */	or. r21, r3, r3
/* 8010E5E0 0010B520  40 82 00 20 */	bne .L_8010E600
/* 8010E5E4 0010B524  3C 60 80 48 */	lis r3, lbl_8047AABC@ha
/* 8010E5E8 0010B528  3C A0 80 48 */	lis r5, lbl_8047AAD0@ha
/* 8010E5EC 0010B52C  38 63 AA BC */	addi r3, r3, lbl_8047AABC@l
/* 8010E5F0 0010B530  38 80 08 9B */	li r4, 0x89b
/* 8010E5F4 0010B534  38 A5 AA D0 */	addi r5, r5, lbl_8047AAD0@l
/* 8010E5F8 0010B538  4C C6 31 82 */	crclr 6
/* 8010E5FC 0010B53C  4B F1 C0 45 */	bl panic_f__12JUTExceptionFPCciPCce
.L_8010E600:
/* 8010E600 0010B540  A0 18 00 08 */	lhz r0, 8(r24)
/* 8010E604 0010B544  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 8010E608 0010B548  41 82 0A D8 */	beq .L_8010F0E0
/* 8010E60C 0010B54C  88 15 00 08 */	lbz r0, 8(r21)
/* 8010E610 0010B550  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010E614 0010B554  41 82 0A CC */	beq .L_8010F0E0
/* 8010E618 0010B558  38 61 00 9C */	addi r3, r1, 0x9c
/* 8010E61C 0010B55C  48 02 06 09 */	bl __ct__Q24Game13EnemyBirthArgFv
/* 8010E620 0010B560  38 00 00 00 */	li r0, 0
/* 8010E624 0010B564  98 01 00 CC */	stb r0, 0xcc(r1)
/* 8010E628 0010B568  A0 78 00 08 */	lhz r3, 8(r24)
/* 8010E62C 0010B56C  54 60 06 B5 */	rlwinm. r0, r3, 0, 0x1a, 0x1a
/* 8010E630 0010B570  41 82 01 60 */	beq .L_8010E790
/* 8010E634 0010B574  C0 1F 00 00 */	lfs f0, 0(r31)
/* 8010E638 0010B578  D0 01 00 9C */	stfs f0, 0x9c(r1)
/* 8010E63C 0010B57C  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8010E640 0010B580  D0 01 00 A0 */	stfs f0, 0xa0(r1)
/* 8010E644 0010B584  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8010E648 0010B588  D0 01 00 A4 */	stfs f0, 0xa4(r1)
/* 8010E64C 0010B58C  4B FB AF 55 */	bl rand
/* 8010E650 0010B590  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8010E654 0010B594  3C 00 43 30 */	lis r0, 0x4330
/* 8010E658 0010B598  90 61 00 E4 */	stw r3, 0xe4(r1)
/* 8010E65C 0010B59C  3C 60 80 4B */	lis r3, gEnemyInfo__4Game@ha
/* 8010E660 0010B5A0  C8 62 96 68 */	lfd f3, lbl_805179C8@sda21(r2)
/* 8010E664 0010B5A4  38 63 C5 38 */	addi r3, r3, gEnemyInfo__4Game@l
/* 8010E668 0010B5A8  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 8010E66C 0010B5AC  3B 00 00 00 */	li r24, 0
/* 8010E670 0010B5B0  C0 22 96 48 */	lfs f1, lbl_805179A8@sda21(r2)
/* 8010E674 0010B5B4  38 A0 FF FF */	li r5, -1
/* 8010E678 0010B5B8  C8 41 00 E0 */	lfd f2, 0xe0(r1)
/* 8010E67C 0010B5BC  C0 02 96 4C */	lfs f0, lbl_805179AC@sda21(r2)
/* 8010E680 0010B5C0  EC 42 18 28 */	fsubs f2, f2, f3
/* 8010E684 0010B5C4  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010E688 0010B5C8  EC 22 08 24 */	fdivs f1, f2, f1
/* 8010E68C 0010B5CC  EC 00 00 72 */	fmuls f0, f0, f1
/* 8010E690 0010B5D0  D0 01 00 A8 */	stfs f0, 0xa8(r1)
/* 8010E694 0010B5D4  80 9B 00 1C */	lwz r4, 0x1c(r27)
/* 8010E698 0010B5D8  7C 09 03 A6 */	mtctr r0
/* 8010E69C 0010B5DC  2C 00 00 00 */	cmpwi r0, 0
/* 8010E6A0 0010B5E0  40 81 00 38 */	ble .L_8010E6D8
.L_8010E6A4:
/* 8010E6A4 0010B5E4  88 03 00 04 */	lbz r0, 4(r3)
/* 8010E6A8 0010B5E8  7C 00 07 74 */	extsb r0, r0
/* 8010E6AC 0010B5EC  7C 00 20 00 */	cmpw r0, r4
/* 8010E6B0 0010B5F0  40 82 00 20 */	bne .L_8010E6D0
/* 8010E6B4 0010B5F4  A0 03 00 08 */	lhz r0, 8(r3)
/* 8010E6B8 0010B5F8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010E6BC 0010B5FC  41 82 00 0C */	beq .L_8010E6C8
/* 8010E6C0 0010B600  7C 85 23 78 */	mr r5, r4
/* 8010E6C4 0010B604  48 00 00 0C */	b .L_8010E6D0
.L_8010E6C8:
/* 8010E6C8 0010B608  88 A3 00 05 */	lbz r5, 5(r3)
/* 8010E6CC 0010B60C  7C A5 07 74 */	extsb r5, r5
.L_8010E6D0:
/* 8010E6D0 0010B610  38 63 00 34 */	addi r3, r3, 0x34
/* 8010E6D4 0010B614  42 00 FF D0 */	bdnz .L_8010E6A4
.L_8010E6D8:
/* 8010E6D8 0010B618  80 DE 00 30 */	lwz r6, 0x30(r30)
/* 8010E6DC 0010B61C  38 60 00 00 */	li r3, 0
/* 8010E6E0 0010B620  48 00 00 18 */	b .L_8010E6F8
.L_8010E6E4:
/* 8010E6E4 0010B624  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 8010E6E8 0010B628  7C 00 28 00 */	cmpw r0, r5
/* 8010E6EC 0010B62C  40 82 00 08 */	bne .L_8010E6F4
/* 8010E6F0 0010B630  80 66 00 20 */	lwz r3, 0x20(r6)
.L_8010E6F4:
/* 8010E6F4 0010B634  80 C6 00 04 */	lwz r6, 4(r6)
.L_8010E6F8:
/* 8010E6F8 0010B638  28 06 00 00 */	cmplwi r6, 0
/* 8010E6FC 0010B63C  40 82 FF E8 */	bne .L_8010E6E4
/* 8010E700 0010B640  28 03 00 00 */	cmplwi r3, 0
/* 8010E704 0010B644  41 82 00 20 */	beq .L_8010E724
/* 8010E708 0010B648  90 81 00 C4 */	stw r4, 0xc4(r1)
/* 8010E70C 0010B64C  38 81 00 9C */	addi r4, r1, 0x9c
/* 8010E710 0010B650  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E714 0010B654  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8010E718 0010B658  7D 89 03 A6 */	mtctr r12
/* 8010E71C 0010B65C  4E 80 04 21 */	bctrl 
/* 8010E720 0010B660  7C 78 1B 78 */	mr r24, r3
.L_8010E724:
/* 8010E724 0010B664  28 18 00 00 */	cmplwi r24, 0
/* 8010E728 0010B668  41 82 00 60 */	beq .L_8010E788
/* 8010E72C 0010B66C  7F 03 C3 78 */	mr r3, r24
/* 8010E730 0010B670  38 80 00 00 */	li r4, 0
/* 8010E734 0010B674  48 02 C8 95 */	bl init__Q24Game8CreatureFPQ24Game15CreatureInitArg
/* 8010E738 0010B678  3C 60 80 4B */	lis r3, __vt__Q24Game11Interaction@ha
/* 8010E73C 0010B67C  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010E740 0010B680  38 03 A3 00 */	addi r0, r3, __vt__Q24Game11Interaction@l
/* 8010E744 0010B684  3C 60 80 4B */	lis r3, __vt__Q24Game14InteractAttack@ha
/* 8010E748 0010B688  90 01 00 8C */	stw r0, 0x8c(r1)
/* 8010E74C 0010B68C  38 A3 4D E0 */	addi r5, r3, __vt__Q24Game14InteractAttack@l
/* 8010E750 0010B690  38 00 00 00 */	li r0, 0
/* 8010E754 0010B694  7F 03 C3 78 */	mr r3, r24
/* 8010E758 0010B698  93 01 00 90 */	stw r24, 0x90(r1)
/* 8010E75C 0010B69C  38 81 00 8C */	addi r4, r1, 0x8c
/* 8010E760 0010B6A0  90 A1 00 8C */	stw r5, 0x8c(r1)
/* 8010E764 0010B6A4  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 8010E768 0010B6A8  90 01 00 98 */	stw r0, 0x98(r1)
/* 8010E76C 0010B6AC  81 98 00 00 */	lwz r12, 0(r24)
/* 8010E770 0010B6B0  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8010E774 0010B6B4  7D 89 03 A6 */	mtctr r12
/* 8010E778 0010B6B8  4E 80 04 21 */	bctrl 
/* 8010E77C 0010B6BC  7F 03 C3 78 */	mr r3, r24
/* 8010E780 0010B6C0  38 80 00 00 */	li r4, 0
/* 8010E784 0010B6C4  48 02 D2 CD */	bl movie_begin__Q24Game8CreatureFb
.L_8010E788:
/* 8010E788 0010B6C8  3B BD 00 0A */	addi r29, r29, 0xa
/* 8010E78C 0010B6CC  48 00 09 70 */	b .L_8010F0FC
.L_8010E790:
/* 8010E790 0010B6D0  54 60 06 73 */	rlwinm. r0, r3, 0, 0x19, 0x19
/* 8010E794 0010B6D4  41 82 02 8C */	beq .L_8010EA20
/* 8010E798 0010B6D8  4B FB AE 09 */	bl rand
/* 8010E79C 0010B6DC  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8010E7A0 0010B6E0  3C 00 43 30 */	lis r0, 0x4330
/* 8010E7A4 0010B6E4  90 61 00 E4 */	stw r3, 0xe4(r1)
/* 8010E7A8 0010B6E8  3C 60 80 51 */	lis r3, atanTable___5JMath@ha
/* 8010E7AC 0010B6EC  C8 42 96 68 */	lfd f2, lbl_805179C8@sda21(r2)
/* 8010E7B0 0010B6F0  38 63 D1 E0 */	addi r3, r3, atanTable___5JMath@l
/* 8010E7B4 0010B6F4  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 8010E7B8 0010B6F8  C0 02 96 48 */	lfs f0, lbl_805179A8@sda21(r2)
/* 8010E7BC 0010B6FC  C8 21 00 E0 */	lfd f1, 0xe0(r1)
/* 8010E7C0 0010B700  C0 82 96 4C */	lfs f4, lbl_805179AC@sda21(r2)
/* 8010E7C4 0010B704  EC A1 10 28 */	fsubs f5, f1, f2
/* 8010E7C8 0010B708  C0 7F 00 00 */	lfs f3, 0(r31)
/* 8010E7CC 0010B70C  C0 21 00 9C */	lfs f1, 0x9c(r1)
/* 8010E7D0 0010B710  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8010E7D4 0010B714  EC A5 00 24 */	fdivs f5, f5, f0
/* 8010E7D8 0010B718  C0 01 00 A4 */	lfs f0, 0xa4(r1)
/* 8010E7DC 0010B71C  EF A4 01 72 */	fmuls f29, f4, f5
/* 8010E7E0 0010B720  EC 23 08 28 */	fsubs f1, f3, f1
/* 8010E7E4 0010B724  EC 42 00 28 */	fsubs f2, f2, f0
/* 8010E7E8 0010B728  4B F2 69 21 */	bl "atan2___Q25JMath18TAtanTable<1024,f>CFff"
/* 8010E7EC 0010B72C  48 30 33 E5 */	bl roundAng__Ff
/* 8010E7F0 0010B730  D0 21 00 A8 */	stfs f1, 0xa8(r1)
/* 8010E7F4 0010B734  3C 60 80 4B */	lis r3, gEnemyInfo__4Game@ha
/* 8010E7F8 0010B738  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010E7FC 0010B73C  38 63 C5 38 */	addi r3, r3, gEnemyInfo__4Game@l
/* 8010E800 0010B740  80 9B 00 1C */	lwz r4, 0x1c(r27)
/* 8010E804 0010B744  3B 00 00 00 */	li r24, 0
/* 8010E808 0010B748  38 A0 FF FF */	li r5, -1
/* 8010E80C 0010B74C  7C 09 03 A6 */	mtctr r0
/* 8010E810 0010B750  2C 00 00 00 */	cmpwi r0, 0
/* 8010E814 0010B754  40 81 00 38 */	ble .L_8010E84C
.L_8010E818:
/* 8010E818 0010B758  88 03 00 04 */	lbz r0, 4(r3)
/* 8010E81C 0010B75C  7C 00 07 74 */	extsb r0, r0
/* 8010E820 0010B760  7C 00 20 00 */	cmpw r0, r4
/* 8010E824 0010B764  40 82 00 20 */	bne .L_8010E844
/* 8010E828 0010B768  A0 03 00 08 */	lhz r0, 8(r3)
/* 8010E82C 0010B76C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010E830 0010B770  41 82 00 0C */	beq .L_8010E83C
/* 8010E834 0010B774  7C 85 23 78 */	mr r5, r4
/* 8010E838 0010B778  48 00 00 0C */	b .L_8010E844
.L_8010E83C:
/* 8010E83C 0010B77C  88 A3 00 05 */	lbz r5, 5(r3)
/* 8010E840 0010B780  7C A5 07 74 */	extsb r5, r5
.L_8010E844:
/* 8010E844 0010B784  38 63 00 34 */	addi r3, r3, 0x34
/* 8010E848 0010B788  42 00 FF D0 */	bdnz .L_8010E818
.L_8010E84C:
/* 8010E84C 0010B78C  80 DE 00 30 */	lwz r6, 0x30(r30)
/* 8010E850 0010B790  38 60 00 00 */	li r3, 0
/* 8010E854 0010B794  48 00 00 18 */	b .L_8010E86C
.L_8010E858:
/* 8010E858 0010B798  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 8010E85C 0010B79C  7C 00 28 00 */	cmpw r0, r5
/* 8010E860 0010B7A0  40 82 00 08 */	bne .L_8010E868
/* 8010E864 0010B7A4  80 66 00 20 */	lwz r3, 0x20(r6)
.L_8010E868:
/* 8010E868 0010B7A8  80 C6 00 04 */	lwz r6, 4(r6)
.L_8010E86C:
/* 8010E86C 0010B7AC  28 06 00 00 */	cmplwi r6, 0
/* 8010E870 0010B7B0  40 82 FF E8 */	bne .L_8010E858
/* 8010E874 0010B7B4  28 03 00 00 */	cmplwi r3, 0
/* 8010E878 0010B7B8  41 82 00 20 */	beq .L_8010E898
/* 8010E87C 0010B7BC  90 81 00 C4 */	stw r4, 0xc4(r1)
/* 8010E880 0010B7C0  38 81 00 9C */	addi r4, r1, 0x9c
/* 8010E884 0010B7C4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010E888 0010B7C8  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8010E88C 0010B7CC  7D 89 03 A6 */	mtctr r12
/* 8010E890 0010B7D0  4E 80 04 21 */	bctrl 
/* 8010E894 0010B7D4  7C 78 1B 78 */	mr r24, r3
.L_8010E898:
/* 8010E898 0010B7D8  28 18 00 00 */	cmplwi r24, 0
/* 8010E89C 0010B7DC  41 82 01 7C */	beq .L_8010EA18
/* 8010E8A0 0010B7E0  7F 03 C3 78 */	mr r3, r24
/* 8010E8A4 0010B7E4  38 81 00 7C */	addi r4, r1, 0x7c
/* 8010E8A8 0010B7E8  81 98 00 00 */	lwz r12, 0(r24)
/* 8010E8AC 0010B7EC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010E8B0 0010B7F0  7D 89 03 A6 */	mtctr r12
/* 8010E8B4 0010B7F4  4E 80 04 21 */	bctrl 
/* 8010E8B8 0010B7F8  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 8010E8BC 0010B7FC  C0 21 00 88 */	lfs f1, 0x88(r1)
/* 8010E8C0 0010B800  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010E8C4 0010B804  EC A2 08 28 */	fsubs f5, f2, f1
/* 8010E8C8 0010B808  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 8010E8CC 0010B80C  40 80 00 08 */	bge .L_8010E8D4
/* 8010E8D0 0010B810  FC A0 00 90 */	fmr f5, f0
.L_8010E8D4:
/* 8010E8D4 0010B814  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010E8D8 0010B818  FC 20 E8 90 */	fmr f1, f29
/* 8010E8DC 0010B81C  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 8010E8E0 0010B820  40 80 00 08 */	bge .L_8010E8E8
/* 8010E8E4 0010B824  FC 20 E8 50 */	fneg f1, f29
.L_8010E8E8:
/* 8010E8E8 0010B828  C0 62 96 54 */	lfs f3, lbl_805179B4@sda21(r2)
/* 8010E8EC 0010B82C  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 8010E8F0 0010B830  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010E8F4 0010B834  38 83 71 A0 */	addi r4, r3, sincosTable___5JMath@l
/* 8010E8F8 0010B838  EC 41 00 F2 */	fmuls f2, f1, f3
/* 8010E8FC 0010B83C  C0 3F 00 08 */	lfs f1, 8(r31)
/* 8010E900 0010B840  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 8010E904 0010B844  FC 00 10 1E */	fctiwz f0, f2
/* 8010E908 0010B848  D8 01 00 E0 */	stfd f0, 0xe0(r1)
/* 8010E90C 0010B84C  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 8010E910 0010B850  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010E914 0010B854  7C 64 02 14 */	add r3, r4, r0
/* 8010E918 0010B858  C0 03 00 04 */	lfs f0, 4(r3)
/* 8010E91C 0010B85C  EC 85 08 3A */	fmadds f4, f5, f0, f1
/* 8010E920 0010B860  40 80 00 28 */	bge .L_8010E948
/* 8010E924 0010B864  C0 02 96 58 */	lfs f0, lbl_805179B8@sda21(r2)
/* 8010E928 0010B868  EC 1D 00 32 */	fmuls f0, f29, f0
/* 8010E92C 0010B86C  FC 00 00 1E */	fctiwz f0, f0
/* 8010E930 0010B870  D8 01 00 D8 */	stfd f0, 0xd8(r1)
/* 8010E934 0010B874  80 01 00 DC */	lwz r0, 0xdc(r1)
/* 8010E938 0010B878  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010E93C 0010B87C  7C 04 04 2E */	lfsx f0, r4, r0
/* 8010E940 0010B880  FC 40 00 50 */	fneg f2, f0
/* 8010E944 0010B884  48 00 00 1C */	b .L_8010E960
.L_8010E948:
/* 8010E948 0010B888  EC 1D 00 F2 */	fmuls f0, f29, f3
/* 8010E94C 0010B88C  FC 00 00 1E */	fctiwz f0, f0
/* 8010E950 0010B890  D8 01 00 D0 */	stfd f0, 0xd0(r1)
/* 8010E954 0010B894  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 8010E958 0010B898  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010E95C 0010B89C  7C 44 04 2E */	lfsx f2, r4, r0
.L_8010E960:
/* 8010E960 0010B8A0  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8010E964 0010B8A4  38 81 00 70 */	addi r4, r1, 0x70
/* 8010E968 0010B8A8  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010E96C 0010B8AC  EC 25 08 BA */	fmadds f1, f5, f2, f1
/* 8010E970 0010B8B0  D0 81 00 78 */	stfs f4, 0x78(r1)
/* 8010E974 0010B8B4  80 6D 93 08 */	lwz r3, mapMgr__4Game@sda21(r13)
/* 8010E978 0010B8B8  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 8010E97C 0010B8BC  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 8010E980 0010B8C0  81 83 00 04 */	lwz r12, 4(r3)
/* 8010E984 0010B8C4  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8010E988 0010B8C8  7D 89 03 A6 */	mtctr r12
/* 8010E98C 0010B8CC  4E 80 04 21 */	bctrl 
/* 8010E990 0010B8D0  D0 21 00 74 */	stfs f1, 0x74(r1)
/* 8010E994 0010B8D4  7F 03 C3 78 */	mr r3, r24
/* 8010E998 0010B8D8  38 81 00 70 */	addi r4, r1, 0x70
/* 8010E99C 0010B8DC  38 A0 00 00 */	li r5, 0
/* 8010E9A0 0010B8E0  48 02 C8 09 */	bl "setPosition__Q24Game8CreatureFR10Vector3<f>b"
/* 8010E9A4 0010B8E4  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 8010E9A8 0010B8E8  7F 03 C3 78 */	mr r3, r24
/* 8010E9AC 0010B8EC  38 80 00 00 */	li r4, 0
/* 8010E9B0 0010B8F0  D0 18 01 98 */	stfs f0, 0x198(r24)
/* 8010E9B4 0010B8F4  C0 01 00 74 */	lfs f0, 0x74(r1)
/* 8010E9B8 0010B8F8  D0 18 01 9C */	stfs f0, 0x19c(r24)
/* 8010E9BC 0010B8FC  C0 01 00 78 */	lfs f0, 0x78(r1)
/* 8010E9C0 0010B900  D0 18 01 A0 */	stfs f0, 0x1a0(r24)
/* 8010E9C4 0010B904  48 02 C6 05 */	bl init__Q24Game8CreatureFPQ24Game15CreatureInitArg
/* 8010E9C8 0010B908  3C 60 80 4B */	lis r3, __vt__Q24Game11Interaction@ha
/* 8010E9CC 0010B90C  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010E9D0 0010B910  38 03 A3 00 */	addi r0, r3, __vt__Q24Game11Interaction@l
/* 8010E9D4 0010B914  3C 60 80 4B */	lis r3, __vt__Q24Game14InteractAttack@ha
/* 8010E9D8 0010B918  90 01 00 60 */	stw r0, 0x60(r1)
/* 8010E9DC 0010B91C  38 A3 4D E0 */	addi r5, r3, __vt__Q24Game14InteractAttack@l
/* 8010E9E0 0010B920  38 00 00 00 */	li r0, 0
/* 8010E9E4 0010B924  7F 03 C3 78 */	mr r3, r24
/* 8010E9E8 0010B928  93 01 00 64 */	stw r24, 0x64(r1)
/* 8010E9EC 0010B92C  38 81 00 60 */	addi r4, r1, 0x60
/* 8010E9F0 0010B930  90 A1 00 60 */	stw r5, 0x60(r1)
/* 8010E9F4 0010B934  D0 01 00 68 */	stfs f0, 0x68(r1)
/* 8010E9F8 0010B938  90 01 00 6C */	stw r0, 0x6c(r1)
/* 8010E9FC 0010B93C  81 98 00 00 */	lwz r12, 0(r24)
/* 8010EA00 0010B940  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8010EA04 0010B944  7D 89 03 A6 */	mtctr r12
/* 8010EA08 0010B948  4E 80 04 21 */	bctrl 
/* 8010EA0C 0010B94C  7F 03 C3 78 */	mr r3, r24
/* 8010EA10 0010B950  38 80 00 00 */	li r4, 0
/* 8010EA14 0010B954  48 02 D0 3D */	bl movie_begin__Q24Game8CreatureFb
.L_8010EA18:
/* 8010EA18 0010B958  3B BD 00 05 */	addi r29, r29, 5
/* 8010EA1C 0010B95C  48 00 06 E0 */	b .L_8010F0FC
.L_8010EA20:
/* 8010EA20 0010B960  54 60 06 31 */	rlwinm. r0, r3, 0, 0x18, 0x18
/* 8010EA24 0010B964  41 82 03 60 */	beq .L_8010ED84
/* 8010EA28 0010B968  7F 23 CB 78 */	mr r3, r25
/* 8010EA2C 0010B96C  81 99 00 00 */	lwz r12, 0(r25)
/* 8010EA30 0010B970  81 8C 00 8C */	lwz r12, 0x8c(r12)
/* 8010EA34 0010B974  7D 89 03 A6 */	mtctr r12
/* 8010EA38 0010B978  4E 80 04 21 */	bctrl 
/* 8010EA3C 0010B97C  7C 76 1B 78 */	mr r22, r3
/* 8010EA40 0010B980  4B FB AB 61 */	bl rand
/* 8010EA44 0010B984  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8010EA48 0010B988  3C 00 43 30 */	lis r0, 0x4330
/* 8010EA4C 0010B98C  90 61 00 E4 */	stw r3, 0xe4(r1)
/* 8010EA50 0010B990  C8 62 96 68 */	lfd f3, lbl_805179C8@sda21(r2)
/* 8010EA54 0010B994  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 8010EA58 0010B998  C0 22 96 48 */	lfs f1, lbl_805179A8@sda21(r2)
/* 8010EA5C 0010B99C  C8 41 00 E0 */	lfd f2, 0xe0(r1)
/* 8010EA60 0010B9A0  C0 02 96 5C */	lfs f0, lbl_805179BC@sda21(r2)
/* 8010EA64 0010B9A4  EC 42 18 28 */	fsubs f2, f2, f3
/* 8010EA68 0010B9A8  EC 22 08 24 */	fdivs f1, f2, f1
/* 8010EA6C 0010B9AC  EC 00 00 72 */	fmuls f0, f0, f1
/* 8010EA70 0010B9B0  FC 00 00 1E */	fctiwz f0, f0
/* 8010EA74 0010B9B4  D8 01 00 D8 */	stfd f0, 0xd8(r1)
/* 8010EA78 0010B9B8  80 61 00 DC */	lwz r3, 0xdc(r1)
/* 8010EA7C 0010B9BC  38 03 00 02 */	addi r0, r3, 2
/* 8010EA80 0010B9C0  7C 16 00 00 */	cmpw r22, r0
/* 8010EA84 0010B9C4  40 81 00 08 */	ble .L_8010EA8C
/* 8010EA88 0010B9C8  7C 16 03 78 */	mr r22, r0
.L_8010EA8C:
/* 8010EA8C 0010B9CC  4B FB AB 15 */	bl rand
/* 8010EA90 0010B9D0  3C A0 43 30 */	lis r5, 0x4330
/* 8010EA94 0010B9D4  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8010EA98 0010B9D8  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8010EA9C 0010B9DC  6E C0 80 00 */	xoris r0, r22, 0x8000
/* 8010EAA0 0010B9E0  3C 80 80 51 */	lis r4, atanTable___5JMath@ha
/* 8010EAA4 0010B9E4  3C 60 80 4B */	lis r3, gEnemyInfo__4Game@ha
/* 8010EAA8 0010B9E8  90 A1 00 D0 */	stw r5, 0xd0(r1)
/* 8010EAAC 0010B9EC  3B 24 D1 E0 */	addi r25, r4, atanTable___5JMath@l
/* 8010EAB0 0010B9F0  C8 82 96 68 */	lfd f4, lbl_805179C8@sda21(r2)
/* 8010EAB4 0010B9F4  3B 03 C5 38 */	addi r24, r3, gEnemyInfo__4Game@l
/* 8010EAB8 0010B9F8  C8 01 00 D0 */	lfd f0, 0xd0(r1)
/* 8010EABC 0010B9FC  3A A0 00 00 */	li r21, 0
/* 8010EAC0 0010BA00  90 01 00 EC */	stw r0, 0xec(r1)
/* 8010EAC4 0010BA04  EC 60 20 28 */	fsubs f3, f0, f4
/* 8010EAC8 0010BA08  C0 42 96 48 */	lfs f2, lbl_805179A8@sda21(r2)
/* 8010EACC 0010BA0C  90 A1 00 E8 */	stw r5, 0xe8(r1)
/* 8010EAD0 0010BA10  C0 22 96 4C */	lfs f1, lbl_805179AC@sda21(r2)
/* 8010EAD4 0010BA14  C8 01 00 E8 */	lfd f0, 0xe8(r1)
/* 8010EAD8 0010BA18  EC 43 10 24 */	fdivs f2, f3, f2
/* 8010EADC 0010BA1C  EC 00 20 28 */	fsubs f0, f0, f4
/* 8010EAE0 0010BA20  EF A1 00 B2 */	fmuls f29, f1, f2
/* 8010EAE4 0010BA24  EF 81 00 24 */	fdivs f28, f1, f0
/* 8010EAE8 0010BA28  48 00 02 8C */	b .L_8010ED74
.L_8010EAEC:
/* 8010EAEC 0010BA2C  4B FB AA B5 */	bl rand
/* 8010EAF0 0010BA30  C0 7F 00 00 */	lfs f3, 0(r31)
/* 8010EAF4 0010BA34  7F 23 CB 78 */	mr r3, r25
/* 8010EAF8 0010BA38  C0 21 00 9C */	lfs f1, 0x9c(r1)
/* 8010EAFC 0010BA3C  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8010EB00 0010BA40  C0 01 00 A4 */	lfs f0, 0xa4(r1)
/* 8010EB04 0010BA44  EC 23 08 28 */	fsubs f1, f3, f1
/* 8010EB08 0010BA48  EC 42 00 28 */	fsubs f2, f2, f0
/* 8010EB0C 0010BA4C  4B F2 65 FD */	bl "atan2___Q25JMath18TAtanTable<1024,f>CFff"
/* 8010EB10 0010BA50  48 30 30 C1 */	bl roundAng__Ff
/* 8010EB14 0010BA54  D0 21 00 A8 */	stfs f1, 0xa8(r1)
/* 8010EB18 0010BA58  7F 03 C3 78 */	mr r3, r24
/* 8010EB1C 0010BA5C  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010EB20 0010BA60  3A E0 00 00 */	li r23, 0
/* 8010EB24 0010BA64  80 9B 00 1C */	lwz r4, 0x1c(r27)
/* 8010EB28 0010BA68  38 A0 FF FF */	li r5, -1
/* 8010EB2C 0010BA6C  7C 09 03 A6 */	mtctr r0
/* 8010EB30 0010BA70  2C 00 00 00 */	cmpwi r0, 0
/* 8010EB34 0010BA74  40 81 00 38 */	ble .L_8010EB6C
.L_8010EB38:
/* 8010EB38 0010BA78  88 03 00 04 */	lbz r0, 4(r3)
/* 8010EB3C 0010BA7C  7C 00 07 74 */	extsb r0, r0
/* 8010EB40 0010BA80  7C 00 20 00 */	cmpw r0, r4
/* 8010EB44 0010BA84  40 82 00 20 */	bne .L_8010EB64
/* 8010EB48 0010BA88  A0 03 00 08 */	lhz r0, 8(r3)
/* 8010EB4C 0010BA8C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010EB50 0010BA90  41 82 00 0C */	beq .L_8010EB5C
/* 8010EB54 0010BA94  7C 85 23 78 */	mr r5, r4
/* 8010EB58 0010BA98  48 00 00 0C */	b .L_8010EB64
.L_8010EB5C:
/* 8010EB5C 0010BA9C  88 A3 00 05 */	lbz r5, 5(r3)
/* 8010EB60 0010BAA0  7C A5 07 74 */	extsb r5, r5
.L_8010EB64:
/* 8010EB64 0010BAA4  38 63 00 34 */	addi r3, r3, 0x34
/* 8010EB68 0010BAA8  42 00 FF D0 */	bdnz .L_8010EB38
.L_8010EB6C:
/* 8010EB6C 0010BAAC  80 DE 00 30 */	lwz r6, 0x30(r30)
/* 8010EB70 0010BAB0  38 60 00 00 */	li r3, 0
/* 8010EB74 0010BAB4  48 00 00 18 */	b .L_8010EB8C
.L_8010EB78:
/* 8010EB78 0010BAB8  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 8010EB7C 0010BABC  7C 00 28 00 */	cmpw r0, r5
/* 8010EB80 0010BAC0  40 82 00 08 */	bne .L_8010EB88
/* 8010EB84 0010BAC4  80 66 00 20 */	lwz r3, 0x20(r6)
.L_8010EB88:
/* 8010EB88 0010BAC8  80 C6 00 04 */	lwz r6, 4(r6)
.L_8010EB8C:
/* 8010EB8C 0010BACC  28 06 00 00 */	cmplwi r6, 0
/* 8010EB90 0010BAD0  40 82 FF E8 */	bne .L_8010EB78
/* 8010EB94 0010BAD4  28 03 00 00 */	cmplwi r3, 0
/* 8010EB98 0010BAD8  41 82 00 20 */	beq .L_8010EBB8
/* 8010EB9C 0010BADC  90 81 00 C4 */	stw r4, 0xc4(r1)
/* 8010EBA0 0010BAE0  38 81 00 9C */	addi r4, r1, 0x9c
/* 8010EBA4 0010BAE4  81 83 00 00 */	lwz r12, 0(r3)
/* 8010EBA8 0010BAE8  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8010EBAC 0010BAEC  7D 89 03 A6 */	mtctr r12
/* 8010EBB0 0010BAF0  4E 80 04 21 */	bctrl 
/* 8010EBB4 0010BAF4  7C 77 1B 78 */	mr r23, r3
.L_8010EBB8:
/* 8010EBB8 0010BAF8  28 17 00 00 */	cmplwi r23, 0
/* 8010EBBC 0010BAFC  41 82 01 B0 */	beq .L_8010ED6C
/* 8010EBC0 0010BB00  7E E3 BB 78 */	mr r3, r23
/* 8010EBC4 0010BB04  38 81 00 50 */	addi r4, r1, 0x50
/* 8010EBC8 0010BB08  81 97 00 00 */	lwz r12, 0(r23)
/* 8010EBCC 0010BB0C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010EBD0 0010BB10  7D 89 03 A6 */	mtctr r12
/* 8010EBD4 0010BB14  4E 80 04 21 */	bctrl 
/* 8010EBD8 0010BB18  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 8010EBDC 0010BB1C  C0 21 00 5C */	lfs f1, 0x5c(r1)
/* 8010EBE0 0010BB20  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010EBE4 0010BB24  EF 62 08 28 */	fsubs f27, f2, f1
/* 8010EBE8 0010BB28  FC 1B 00 40 */	fcmpo cr0, f27, f0
/* 8010EBEC 0010BB2C  40 80 00 08 */	bge .L_8010EBF4
/* 8010EBF0 0010BB30  FF 60 00 90 */	fmr f27, f0
.L_8010EBF4:
/* 8010EBF4 0010BB34  4B FB A9 AD */	bl rand
/* 8010EBF8 0010BB38  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8010EBFC 0010BB3C  3C 00 43 30 */	lis r0, 0x4330
/* 8010EC00 0010BB40  90 61 00 EC */	stw r3, 0xec(r1)
/* 8010EC04 0010BB44  FC 80 E8 90 */	fmr f4, f29
/* 8010EC08 0010BB48  C0 02 96 60 */	lfs f0, lbl_805179C0@sda21(r2)
/* 8010EC0C 0010BB4C  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 8010EC10 0010BB50  C8 42 96 68 */	lfd f2, lbl_805179C8@sda21(r2)
/* 8010EC14 0010BB54  EC 60 06 F2 */	fmuls f3, f0, f27
/* 8010EC18 0010BB58  C8 01 00 E8 */	lfd f0, 0xe8(r1)
/* 8010EC1C 0010BB5C  C0 22 96 48 */	lfs f1, lbl_805179A8@sda21(r2)
/* 8010EC20 0010BB60  EC 40 10 28 */	fsubs f2, f0, f2
/* 8010EC24 0010BB64  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010EC28 0010BB68  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 8010EC2C 0010BB6C  EC 02 08 24 */	fdivs f0, f2, f1
/* 8010EC30 0010BB70  EC A3 18 3A */	fmadds f5, f3, f0, f3
/* 8010EC34 0010BB74  40 80 00 08 */	bge .L_8010EC3C
/* 8010EC38 0010BB78  FC 80 E8 50 */	fneg f4, f29
.L_8010EC3C:
/* 8010EC3C 0010BB7C  C0 62 96 54 */	lfs f3, lbl_805179B4@sda21(r2)
/* 8010EC40 0010BB80  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 8010EC44 0010BB84  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010EC48 0010BB88  38 83 71 A0 */	addi r4, r3, sincosTable___5JMath@l
/* 8010EC4C 0010BB8C  EC 44 00 F2 */	fmuls f2, f4, f3
/* 8010EC50 0010BB90  C0 3F 00 08 */	lfs f1, 8(r31)
/* 8010EC54 0010BB94  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 8010EC58 0010BB98  FC 00 10 1E */	fctiwz f0, f2
/* 8010EC5C 0010BB9C  D8 01 00 E0 */	stfd f0, 0xe0(r1)
/* 8010EC60 0010BBA0  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 8010EC64 0010BBA4  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010EC68 0010BBA8  7C 64 02 14 */	add r3, r4, r0
/* 8010EC6C 0010BBAC  C0 03 00 04 */	lfs f0, 4(r3)
/* 8010EC70 0010BBB0  EC 85 08 3A */	fmadds f4, f5, f0, f1
/* 8010EC74 0010BBB4  40 80 00 28 */	bge .L_8010EC9C
/* 8010EC78 0010BBB8  C0 02 96 58 */	lfs f0, lbl_805179B8@sda21(r2)
/* 8010EC7C 0010BBBC  EC 1D 00 32 */	fmuls f0, f29, f0
/* 8010EC80 0010BBC0  FC 00 00 1E */	fctiwz f0, f0
/* 8010EC84 0010BBC4  D8 01 00 D8 */	stfd f0, 0xd8(r1)
/* 8010EC88 0010BBC8  80 01 00 DC */	lwz r0, 0xdc(r1)
/* 8010EC8C 0010BBCC  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010EC90 0010BBD0  7C 04 04 2E */	lfsx f0, r4, r0
/* 8010EC94 0010BBD4  FC 40 00 50 */	fneg f2, f0
/* 8010EC98 0010BBD8  48 00 00 1C */	b .L_8010ECB4
.L_8010EC9C:
/* 8010EC9C 0010BBDC  EC 1D 00 F2 */	fmuls f0, f29, f3
/* 8010ECA0 0010BBE0  FC 00 00 1E */	fctiwz f0, f0
/* 8010ECA4 0010BBE4  D8 01 00 D0 */	stfd f0, 0xd0(r1)
/* 8010ECA8 0010BBE8  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 8010ECAC 0010BBEC  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010ECB0 0010BBF0  7C 44 04 2E */	lfsx f2, r4, r0
.L_8010ECB4:
/* 8010ECB4 0010BBF4  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8010ECB8 0010BBF8  38 81 00 44 */	addi r4, r1, 0x44
/* 8010ECBC 0010BBFC  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010ECC0 0010BC00  EC 25 08 BA */	fmadds f1, f5, f2, f1
/* 8010ECC4 0010BC04  D0 81 00 4C */	stfs f4, 0x4c(r1)
/* 8010ECC8 0010BC08  80 6D 93 08 */	lwz r3, mapMgr__4Game@sda21(r13)
/* 8010ECCC 0010BC0C  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 8010ECD0 0010BC10  D0 21 00 44 */	stfs f1, 0x44(r1)
/* 8010ECD4 0010BC14  81 83 00 04 */	lwz r12, 4(r3)
/* 8010ECD8 0010BC18  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8010ECDC 0010BC1C  7D 89 03 A6 */	mtctr r12
/* 8010ECE0 0010BC20  4E 80 04 21 */	bctrl 
/* 8010ECE4 0010BC24  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 8010ECE8 0010BC28  7E E3 BB 78 */	mr r3, r23
/* 8010ECEC 0010BC2C  38 81 00 44 */	addi r4, r1, 0x44
/* 8010ECF0 0010BC30  38 A0 00 00 */	li r5, 0
/* 8010ECF4 0010BC34  48 02 C4 B5 */	bl "setPosition__Q24Game8CreatureFR10Vector3<f>b"
/* 8010ECF8 0010BC38  C0 01 00 44 */	lfs f0, 0x44(r1)
/* 8010ECFC 0010BC3C  7E E3 BB 78 */	mr r3, r23
/* 8010ED00 0010BC40  38 80 00 00 */	li r4, 0
/* 8010ED04 0010BC44  D0 17 01 98 */	stfs f0, 0x198(r23)
/* 8010ED08 0010BC48  C0 01 00 48 */	lfs f0, 0x48(r1)
/* 8010ED0C 0010BC4C  D0 17 01 9C */	stfs f0, 0x19c(r23)
/* 8010ED10 0010BC50  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 8010ED14 0010BC54  D0 17 01 A0 */	stfs f0, 0x1a0(r23)
/* 8010ED18 0010BC58  48 02 C2 B1 */	bl init__Q24Game8CreatureFPQ24Game15CreatureInitArg
/* 8010ED1C 0010BC5C  3C 60 80 4B */	lis r3, __vt__Q24Game11Interaction@ha
/* 8010ED20 0010BC60  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010ED24 0010BC64  38 03 A3 00 */	addi r0, r3, __vt__Q24Game11Interaction@l
/* 8010ED28 0010BC68  3C 60 80 4B */	lis r3, __vt__Q24Game14InteractAttack@ha
/* 8010ED2C 0010BC6C  90 01 00 34 */	stw r0, 0x34(r1)
/* 8010ED30 0010BC70  38 A3 4D E0 */	addi r5, r3, __vt__Q24Game14InteractAttack@l
/* 8010ED34 0010BC74  38 00 00 00 */	li r0, 0
/* 8010ED38 0010BC78  7E E3 BB 78 */	mr r3, r23
/* 8010ED3C 0010BC7C  92 E1 00 38 */	stw r23, 0x38(r1)
/* 8010ED40 0010BC80  38 81 00 34 */	addi r4, r1, 0x34
/* 8010ED44 0010BC84  90 A1 00 34 */	stw r5, 0x34(r1)
/* 8010ED48 0010BC88  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8010ED4C 0010BC8C  90 01 00 40 */	stw r0, 0x40(r1)
/* 8010ED50 0010BC90  81 97 00 00 */	lwz r12, 0(r23)
/* 8010ED54 0010BC94  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8010ED58 0010BC98  7D 89 03 A6 */	mtctr r12
/* 8010ED5C 0010BC9C  4E 80 04 21 */	bctrl 
/* 8010ED60 0010BCA0  7E E3 BB 78 */	mr r3, r23
/* 8010ED64 0010BCA4  38 80 00 00 */	li r4, 0
/* 8010ED68 0010BCA8  48 02 CC E9 */	bl movie_begin__Q24Game8CreatureFb
.L_8010ED6C:
/* 8010ED6C 0010BCAC  EF BD E0 2A */	fadds f29, f29, f28
/* 8010ED70 0010BCB0  3A B5 00 01 */	addi r21, r21, 1
.L_8010ED74:
/* 8010ED74 0010BCB4  7C 15 B0 00 */	cmpw r21, r22
/* 8010ED78 0010BCB8  41 80 FD 74 */	blt .L_8010EAEC
/* 8010ED7C 0010BCBC  3B BD 00 03 */	addi r29, r29, 3
/* 8010ED80 0010BCC0  48 00 03 7C */	b .L_8010F0FC
.L_8010ED84:
/* 8010ED84 0010BCC4  7F 23 CB 78 */	mr r3, r25
/* 8010ED88 0010BCC8  81 99 00 00 */	lwz r12, 0(r25)
/* 8010ED8C 0010BCCC  81 8C 00 8C */	lwz r12, 0x8c(r12)
/* 8010ED90 0010BCD0  7D 89 03 A6 */	mtctr r12
/* 8010ED94 0010BCD4  4E 80 04 21 */	bctrl 
/* 8010ED98 0010BCD8  7C 75 1B 78 */	mr r21, r3
/* 8010ED9C 0010BCDC  4B FB A8 05 */	bl rand
/* 8010EDA0 0010BCE0  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8010EDA4 0010BCE4  3C 00 43 30 */	lis r0, 0x4330
/* 8010EDA8 0010BCE8  90 61 00 EC */	stw r3, 0xec(r1)
/* 8010EDAC 0010BCEC  C8 62 96 68 */	lfd f3, lbl_805179C8@sda21(r2)
/* 8010EDB0 0010BCF0  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 8010EDB4 0010BCF4  C0 22 96 48 */	lfs f1, lbl_805179A8@sda21(r2)
/* 8010EDB8 0010BCF8  C8 41 00 E8 */	lfd f2, 0xe8(r1)
/* 8010EDBC 0010BCFC  C0 02 96 64 */	lfs f0, lbl_805179C4@sda21(r2)
/* 8010EDC0 0010BD00  EC 42 18 28 */	fsubs f2, f2, f3
/* 8010EDC4 0010BD04  EC 22 08 24 */	fdivs f1, f2, f1
/* 8010EDC8 0010BD08  EC 00 00 72 */	fmuls f0, f0, f1
/* 8010EDCC 0010BD0C  FC 00 00 1E */	fctiwz f0, f0
/* 8010EDD0 0010BD10  D8 01 00 E0 */	stfd f0, 0xe0(r1)
/* 8010EDD4 0010BD14  80 61 00 E4 */	lwz r3, 0xe4(r1)
/* 8010EDD8 0010BD18  38 03 00 07 */	addi r0, r3, 7
/* 8010EDDC 0010BD1C  7C 15 00 00 */	cmpw r21, r0
/* 8010EDE0 0010BD20  40 81 00 08 */	ble .L_8010EDE8
/* 8010EDE4 0010BD24  7C 15 03 78 */	mr r21, r0
.L_8010EDE8:
/* 8010EDE8 0010BD28  4B FB A7 B9 */	bl rand
/* 8010EDEC 0010BD2C  3C A0 43 30 */	lis r5, 0x4330
/* 8010EDF0 0010BD30  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8010EDF4 0010BD34  90 01 00 DC */	stw r0, 0xdc(r1)
/* 8010EDF8 0010BD38  6E A0 80 00 */	xoris r0, r21, 0x8000
/* 8010EDFC 0010BD3C  3C 80 80 51 */	lis r4, atanTable___5JMath@ha
/* 8010EE00 0010BD40  3C 60 80 4B */	lis r3, gEnemyInfo__4Game@ha
/* 8010EE04 0010BD44  90 A1 00 D8 */	stw r5, 0xd8(r1)
/* 8010EE08 0010BD48  3B 04 D1 E0 */	addi r24, r4, atanTable___5JMath@l
/* 8010EE0C 0010BD4C  C8 82 96 68 */	lfd f4, lbl_805179C8@sda21(r2)
/* 8010EE10 0010BD50  3B 23 C5 38 */	addi r25, r3, gEnemyInfo__4Game@l
/* 8010EE14 0010BD54  C8 01 00 D8 */	lfd f0, 0xd8(r1)
/* 8010EE18 0010BD58  3A C0 00 00 */	li r22, 0
/* 8010EE1C 0010BD5C  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8010EE20 0010BD60  EC 60 20 28 */	fsubs f3, f0, f4
/* 8010EE24 0010BD64  C0 42 96 48 */	lfs f2, lbl_805179A8@sda21(r2)
/* 8010EE28 0010BD68  90 A1 00 D0 */	stw r5, 0xd0(r1)
/* 8010EE2C 0010BD6C  C0 22 96 4C */	lfs f1, lbl_805179AC@sda21(r2)
/* 8010EE30 0010BD70  C8 01 00 D0 */	lfd f0, 0xd0(r1)
/* 8010EE34 0010BD74  EC 43 10 24 */	fdivs f2, f3, f2
/* 8010EE38 0010BD78  EC 00 20 28 */	fsubs f0, f0, f4
/* 8010EE3C 0010BD7C  EF 81 00 B2 */	fmuls f28, f1, f2
/* 8010EE40 0010BD80  EF A1 00 24 */	fdivs f29, f1, f0
/* 8010EE44 0010BD84  48 00 02 8C */	b .L_8010F0D0
.L_8010EE48:
/* 8010EE48 0010BD88  4B FB A7 59 */	bl rand
/* 8010EE4C 0010BD8C  C0 7F 00 00 */	lfs f3, 0(r31)
/* 8010EE50 0010BD90  7F 03 C3 78 */	mr r3, r24
/* 8010EE54 0010BD94  C0 21 00 9C */	lfs f1, 0x9c(r1)
/* 8010EE58 0010BD98  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8010EE5C 0010BD9C  C0 01 00 A4 */	lfs f0, 0xa4(r1)
/* 8010EE60 0010BDA0  EC 23 08 28 */	fsubs f1, f3, f1
/* 8010EE64 0010BDA4  EC 42 00 28 */	fsubs f2, f2, f0
/* 8010EE68 0010BDA8  4B F2 62 A1 */	bl "atan2___Q25JMath18TAtanTable<1024,f>CFff"
/* 8010EE6C 0010BDAC  48 30 2D 65 */	bl roundAng__Ff
/* 8010EE70 0010BDB0  D0 21 00 A8 */	stfs f1, 0xa8(r1)
/* 8010EE74 0010BDB4  7F 23 CB 78 */	mr r3, r25
/* 8010EE78 0010BDB8  80 0D 83 D0 */	lwz r0, gEnemyInfoNum__4Game@sda21(r13)
/* 8010EE7C 0010BDBC  3A E0 00 00 */	li r23, 0
/* 8010EE80 0010BDC0  80 9B 00 1C */	lwz r4, 0x1c(r27)
/* 8010EE84 0010BDC4  38 A0 FF FF */	li r5, -1
/* 8010EE88 0010BDC8  7C 09 03 A6 */	mtctr r0
/* 8010EE8C 0010BDCC  2C 00 00 00 */	cmpwi r0, 0
/* 8010EE90 0010BDD0  40 81 00 38 */	ble .L_8010EEC8
.L_8010EE94:
/* 8010EE94 0010BDD4  88 03 00 04 */	lbz r0, 4(r3)
/* 8010EE98 0010BDD8  7C 00 07 74 */	extsb r0, r0
/* 8010EE9C 0010BDDC  7C 00 20 00 */	cmpw r0, r4
/* 8010EEA0 0010BDE0  40 82 00 20 */	bne .L_8010EEC0
/* 8010EEA4 0010BDE4  A0 03 00 08 */	lhz r0, 8(r3)
/* 8010EEA8 0010BDE8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8010EEAC 0010BDEC  41 82 00 0C */	beq .L_8010EEB8
/* 8010EEB0 0010BDF0  7C 85 23 78 */	mr r5, r4
/* 8010EEB4 0010BDF4  48 00 00 0C */	b .L_8010EEC0
.L_8010EEB8:
/* 8010EEB8 0010BDF8  88 A3 00 05 */	lbz r5, 5(r3)
/* 8010EEBC 0010BDFC  7C A5 07 74 */	extsb r5, r5
.L_8010EEC0:
/* 8010EEC0 0010BE00  38 63 00 34 */	addi r3, r3, 0x34
/* 8010EEC4 0010BE04  42 00 FF D0 */	bdnz .L_8010EE94
.L_8010EEC8:
/* 8010EEC8 0010BE08  80 DE 00 30 */	lwz r6, 0x30(r30)
/* 8010EECC 0010BE0C  38 60 00 00 */	li r3, 0
/* 8010EED0 0010BE10  48 00 00 18 */	b .L_8010EEE8
.L_8010EED4:
/* 8010EED4 0010BE14  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 8010EED8 0010BE18  7C 00 28 00 */	cmpw r0, r5
/* 8010EEDC 0010BE1C  40 82 00 08 */	bne .L_8010EEE4
/* 8010EEE0 0010BE20  80 66 00 20 */	lwz r3, 0x20(r6)
.L_8010EEE4:
/* 8010EEE4 0010BE24  80 C6 00 04 */	lwz r6, 4(r6)
.L_8010EEE8:
/* 8010EEE8 0010BE28  28 06 00 00 */	cmplwi r6, 0
/* 8010EEEC 0010BE2C  40 82 FF E8 */	bne .L_8010EED4
/* 8010EEF0 0010BE30  28 03 00 00 */	cmplwi r3, 0
/* 8010EEF4 0010BE34  41 82 00 20 */	beq .L_8010EF14
/* 8010EEF8 0010BE38  90 81 00 C4 */	stw r4, 0xc4(r1)
/* 8010EEFC 0010BE3C  38 81 00 9C */	addi r4, r1, 0x9c
/* 8010EF00 0010BE40  81 83 00 00 */	lwz r12, 0(r3)
/* 8010EF04 0010BE44  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8010EF08 0010BE48  7D 89 03 A6 */	mtctr r12
/* 8010EF0C 0010BE4C  4E 80 04 21 */	bctrl 
/* 8010EF10 0010BE50  7C 77 1B 78 */	mr r23, r3
.L_8010EF14:
/* 8010EF14 0010BE54  28 17 00 00 */	cmplwi r23, 0
/* 8010EF18 0010BE58  41 82 01 B0 */	beq .L_8010F0C8
/* 8010EF1C 0010BE5C  7E E3 BB 78 */	mr r3, r23
/* 8010EF20 0010BE60  38 81 00 24 */	addi r4, r1, 0x24
/* 8010EF24 0010BE64  81 97 00 00 */	lwz r12, 0(r23)
/* 8010EF28 0010BE68  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8010EF2C 0010BE6C  7D 89 03 A6 */	mtctr r12
/* 8010EF30 0010BE70  4E 80 04 21 */	bctrl 
/* 8010EF34 0010BE74  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 8010EF38 0010BE78  C0 21 00 30 */	lfs f1, 0x30(r1)
/* 8010EF3C 0010BE7C  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010EF40 0010BE80  EF 62 08 28 */	fsubs f27, f2, f1
/* 8010EF44 0010BE84  FC 1B 00 40 */	fcmpo cr0, f27, f0
/* 8010EF48 0010BE88  40 80 00 08 */	bge .L_8010EF50
/* 8010EF4C 0010BE8C  FF 60 00 90 */	fmr f27, f0
.L_8010EF50:
/* 8010EF50 0010BE90  4B FB A6 51 */	bl rand
/* 8010EF54 0010BE94  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8010EF58 0010BE98  3C 00 43 30 */	lis r0, 0x4330
/* 8010EF5C 0010BE9C  90 61 00 EC */	stw r3, 0xec(r1)
/* 8010EF60 0010BEA0  FC 80 E0 90 */	fmr f4, f28
/* 8010EF64 0010BEA4  C0 02 96 60 */	lfs f0, lbl_805179C0@sda21(r2)
/* 8010EF68 0010BEA8  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 8010EF6C 0010BEAC  C8 42 96 68 */	lfd f2, lbl_805179C8@sda21(r2)
/* 8010EF70 0010BEB0  EC 60 06 F2 */	fmuls f3, f0, f27
/* 8010EF74 0010BEB4  C8 01 00 E8 */	lfd f0, 0xe8(r1)
/* 8010EF78 0010BEB8  C0 22 96 48 */	lfs f1, lbl_805179A8@sda21(r2)
/* 8010EF7C 0010BEBC  EC 40 10 28 */	fsubs f2, f0, f2
/* 8010EF80 0010BEC0  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010EF84 0010BEC4  FC 1C 00 40 */	fcmpo cr0, f28, f0
/* 8010EF88 0010BEC8  EC 02 08 24 */	fdivs f0, f2, f1
/* 8010EF8C 0010BECC  EC A3 18 3A */	fmadds f5, f3, f0, f3
/* 8010EF90 0010BED0  40 80 00 08 */	bge .L_8010EF98
/* 8010EF94 0010BED4  FC 80 E0 50 */	fneg f4, f28
.L_8010EF98:
/* 8010EF98 0010BED8  C0 62 96 54 */	lfs f3, lbl_805179B4@sda21(r2)
/* 8010EF9C 0010BEDC  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 8010EFA0 0010BEE0  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010EFA4 0010BEE4  38 83 71 A0 */	addi r4, r3, sincosTable___5JMath@l
/* 8010EFA8 0010BEE8  EC 44 00 F2 */	fmuls f2, f4, f3
/* 8010EFAC 0010BEEC  C0 3F 00 08 */	lfs f1, 8(r31)
/* 8010EFB0 0010BEF0  FC 1C 00 40 */	fcmpo cr0, f28, f0
/* 8010EFB4 0010BEF4  FC 00 10 1E */	fctiwz f0, f2
/* 8010EFB8 0010BEF8  D8 01 00 E0 */	stfd f0, 0xe0(r1)
/* 8010EFBC 0010BEFC  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 8010EFC0 0010BF00  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010EFC4 0010BF04  7C 64 02 14 */	add r3, r4, r0
/* 8010EFC8 0010BF08  C0 03 00 04 */	lfs f0, 4(r3)
/* 8010EFCC 0010BF0C  EC 85 08 3A */	fmadds f4, f5, f0, f1
/* 8010EFD0 0010BF10  40 80 00 28 */	bge .L_8010EFF8
/* 8010EFD4 0010BF14  C0 02 96 58 */	lfs f0, lbl_805179B8@sda21(r2)
/* 8010EFD8 0010BF18  EC 1C 00 32 */	fmuls f0, f28, f0
/* 8010EFDC 0010BF1C  FC 00 00 1E */	fctiwz f0, f0
/* 8010EFE0 0010BF20  D8 01 00 D8 */	stfd f0, 0xd8(r1)
/* 8010EFE4 0010BF24  80 01 00 DC */	lwz r0, 0xdc(r1)
/* 8010EFE8 0010BF28  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010EFEC 0010BF2C  7C 04 04 2E */	lfsx f0, r4, r0
/* 8010EFF0 0010BF30  FC 40 00 50 */	fneg f2, f0
/* 8010EFF4 0010BF34  48 00 00 1C */	b .L_8010F010
.L_8010EFF8:
/* 8010EFF8 0010BF38  EC 1C 00 F2 */	fmuls f0, f28, f3
/* 8010EFFC 0010BF3C  FC 00 00 1E */	fctiwz f0, f0
/* 8010F000 0010BF40  D8 01 00 D0 */	stfd f0, 0xd0(r1)
/* 8010F004 0010BF44  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 8010F008 0010BF48  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 8010F00C 0010BF4C  7C 44 04 2E */	lfsx f2, r4, r0
.L_8010F010:
/* 8010F010 0010BF50  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8010F014 0010BF54  38 81 00 18 */	addi r4, r1, 0x18
/* 8010F018 0010BF58  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010F01C 0010BF5C  EC 25 08 BA */	fmadds f1, f5, f2, f1
/* 8010F020 0010BF60  D0 81 00 20 */	stfs f4, 0x20(r1)
/* 8010F024 0010BF64  80 6D 93 08 */	lwz r3, mapMgr__4Game@sda21(r13)
/* 8010F028 0010BF68  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8010F02C 0010BF6C  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 8010F030 0010BF70  81 83 00 04 */	lwz r12, 4(r3)
/* 8010F034 0010BF74  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8010F038 0010BF78  7D 89 03 A6 */	mtctr r12
/* 8010F03C 0010BF7C  4E 80 04 21 */	bctrl 
/* 8010F040 0010BF80  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 8010F044 0010BF84  7E E3 BB 78 */	mr r3, r23
/* 8010F048 0010BF88  38 81 00 18 */	addi r4, r1, 0x18
/* 8010F04C 0010BF8C  38 A0 00 00 */	li r5, 0
/* 8010F050 0010BF90  48 02 C1 59 */	bl "setPosition__Q24Game8CreatureFR10Vector3<f>b"
/* 8010F054 0010BF94  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 8010F058 0010BF98  7E E3 BB 78 */	mr r3, r23
/* 8010F05C 0010BF9C  38 80 00 00 */	li r4, 0
/* 8010F060 0010BFA0  D0 17 01 98 */	stfs f0, 0x198(r23)
/* 8010F064 0010BFA4  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 8010F068 0010BFA8  D0 17 01 9C */	stfs f0, 0x19c(r23)
/* 8010F06C 0010BFAC  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 8010F070 0010BFB0  D0 17 01 A0 */	stfs f0, 0x1a0(r23)
/* 8010F074 0010BFB4  48 02 BF 55 */	bl init__Q24Game8CreatureFPQ24Game15CreatureInitArg
/* 8010F078 0010BFB8  3C 60 80 4B */	lis r3, __vt__Q24Game11Interaction@ha
/* 8010F07C 0010BFBC  C0 02 96 50 */	lfs f0, lbl_805179B0@sda21(r2)
/* 8010F080 0010BFC0  38 03 A3 00 */	addi r0, r3, __vt__Q24Game11Interaction@l
/* 8010F084 0010BFC4  3C 60 80 4B */	lis r3, __vt__Q24Game14InteractAttack@ha
/* 8010F088 0010BFC8  90 01 00 08 */	stw r0, 8(r1)
/* 8010F08C 0010BFCC  38 A3 4D E0 */	addi r5, r3, __vt__Q24Game14InteractAttack@l
/* 8010F090 0010BFD0  38 00 00 00 */	li r0, 0
/* 8010F094 0010BFD4  7E E3 BB 78 */	mr r3, r23
/* 8010F098 0010BFD8  92 E1 00 0C */	stw r23, 0xc(r1)
/* 8010F09C 0010BFDC  38 81 00 08 */	addi r4, r1, 8
/* 8010F0A0 0010BFE0  90 A1 00 08 */	stw r5, 8(r1)
/* 8010F0A4 0010BFE4  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8010F0A8 0010BFE8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F0AC 0010BFEC  81 97 00 00 */	lwz r12, 0(r23)
/* 8010F0B0 0010BFF0  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8010F0B4 0010BFF4  7D 89 03 A6 */	mtctr r12
/* 8010F0B8 0010BFF8  4E 80 04 21 */	bctrl 
/* 8010F0BC 0010BFFC  7E E3 BB 78 */	mr r3, r23
/* 8010F0C0 0010C000  38 80 00 00 */	li r4, 0
/* 8010F0C4 0010C004  48 02 C9 8D */	bl movie_begin__Q24Game8CreatureFb
.L_8010F0C8:
/* 8010F0C8 0010C008  EF 9C E8 2A */	fadds f28, f28, f29
/* 8010F0CC 0010C00C  3A D6 00 01 */	addi r22, r22, 1
.L_8010F0D0:
/* 8010F0D0 0010C010  7C 16 A8 00 */	cmpw r22, r21
/* 8010F0D4 0010C014  41 80 FD 74 */	blt .L_8010EE48
/* 8010F0D8 0010C018  3B BD 00 01 */	addi r29, r29, 1
/* 8010F0DC 0010C01C  48 00 00 20 */	b .L_8010F0FC
.L_8010F0E0:
/* 8010F0E0 0010C020  83 7B 00 04 */	lwz r27, 4(r27)
/* 8010F0E4 0010C024  28 1B 00 00 */	cmplwi r27, 0
/* 8010F0E8 0010C028  40 82 00 08 */	bne .L_8010F0F0
/* 8010F0EC 0010C02C  83 7E 00 30 */	lwz r27, 0x30(r30)
.L_8010F0F0:
/* 8010F0F0 0010C030  7C 1B B8 40 */	cmplw r27, r23
/* 8010F0F4 0010C034  40 82 F4 A0 */	bne .L_8010E594
/* 8010F0F8 0010C038  3B BD 00 0A */	addi r29, r29, 0xa
.L_8010F0FC:
/* 8010F0FC 0010C03C  2C 1D 00 0A */	cmpwi r29, 0xa
/* 8010F100 0010C040  41 80 F4 30 */	blt .L_8010E530
.L_8010F104:
/* 8010F104 0010C044  E3 E1 01 68 */	psq_l f31, 360(r1), 0, qr0
/* 8010F108 0010C048  CB E1 01 60 */	lfd f31, 0x160(r1)
/* 8010F10C 0010C04C  E3 C1 01 58 */	psq_l f30, 344(r1), 0, qr0
/* 8010F110 0010C050  CB C1 01 50 */	lfd f30, 0x150(r1)
/* 8010F114 0010C054  E3 A1 01 48 */	psq_l f29, 328(r1), 0, qr0
/* 8010F118 0010C058  CB A1 01 40 */	lfd f29, 0x140(r1)
/* 8010F11C 0010C05C  E3 81 01 38 */	psq_l f28, 312(r1), 0, qr0
/* 8010F120 0010C060  CB 81 01 30 */	lfd f28, 0x130(r1)
/* 8010F124 0010C064  E3 61 01 28 */	psq_l f27, 296(r1), 0, qr0
/* 8010F128 0010C068  CB 61 01 20 */	lfd f27, 0x120(r1)
/* 8010F12C 0010C06C  BA A1 00 F4 */	lmw r21, 0xf4(r1)
/* 8010F130 0010C070  80 01 01 74 */	lwz r0, 0x174(r1)
/* 8010F134 0010C074  7C 08 03 A6 */	mtlr r0
/* 8010F138 0010C078  38 21 01 70 */	addi r1, r1, 0x170
/* 8010F13C 0010C07C  4E 80 00 20 */	blr 
.endfn createDayendEnemies__Q24Game15GeneralEnemyMgrFRQ23Sys6Sphere

.fn setDebugParm__Q24Game12EnemyMgrNodeFUl, weak
/* 8010F140 0010C080  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F144 0010C084  7C 08 02 A6 */	mflr r0
/* 8010F148 0010C088  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F14C 0010C08C  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010F150 0010C090  81 83 00 00 */	lwz r12, 0(r3)
/* 8010F154 0010C094  81 8C 00 84 */	lwz r12, 0x84(r12)
/* 8010F158 0010C098  7D 89 03 A6 */	mtctr r12
/* 8010F15C 0010C09C  4E 80 04 21 */	bctrl 
/* 8010F160 0010C0A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F164 0010C0A4  7C 08 03 A6 */	mtlr r0
/* 8010F168 0010C0A8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F16C 0010C0AC  4E 80 00 20 */	blr 
.endfn setDebugParm__Q24Game12EnemyMgrNodeFUl

.fn resetDebugParm__Q24Game12EnemyMgrNodeFUl, weak
/* 8010F170 0010C0B0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F174 0010C0B4  7C 08 02 A6 */	mflr r0
/* 8010F178 0010C0B8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F17C 0010C0BC  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010F180 0010C0C0  81 83 00 00 */	lwz r12, 0(r3)
/* 8010F184 0010C0C4  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8010F188 0010C0C8  7D 89 03 A6 */	mtctr r12
/* 8010F18C 0010C0CC  4E 80 04 21 */	bctrl 
/* 8010F190 0010C0D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F194 0010C0D4  7C 08 03 A6 */	mtlr r0
/* 8010F198 0010C0D8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F19C 0010C0DC  4E 80 00 20 */	blr 
.endfn resetDebugParm__Q24Game12EnemyMgrNodeFUl

.fn __dt__Q24Game15GeneralEnemyMgrFv, weak
/* 8010F1A0 0010C0E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F1A4 0010C0E4  7C 08 02 A6 */	mflr r0
/* 8010F1A8 0010C0E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F1AC 0010C0EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010F1B0 0010C0F0  7C 9F 23 78 */	mr r31, r4
/* 8010F1B4 0010C0F4  93 C1 00 08 */	stw r30, 8(r1)
/* 8010F1B8 0010C0F8  7C 7E 1B 79 */	or. r30, r3, r3
/* 8010F1BC 0010C0FC  41 82 00 7C */	beq .L_8010F238
/* 8010F1C0 0010C100  3C 60 80 4B */	lis r3, __vt__Q24Game15GeneralEnemyMgr@ha
/* 8010F1C4 0010C104  34 1E 00 58 */	addic. r0, r30, 0x58
/* 8010F1C8 0010C108  38 63 B5 24 */	addi r3, r3, __vt__Q24Game15GeneralEnemyMgr@l
/* 8010F1CC 0010C10C  90 7E 00 00 */	stw r3, 0(r30)
/* 8010F1D0 0010C110  38 03 00 38 */	addi r0, r3, 0x38
/* 8010F1D4 0010C114  90 1E 00 04 */	stw r0, 4(r30)
/* 8010F1D8 0010C118  41 82 00 1C */	beq .L_8010F1F4
/* 8010F1DC 0010C11C  38 7E 00 78 */	addi r3, r30, 0x78
/* 8010F1E0 0010C120  38 80 FF FF */	li r4, -1
/* 8010F1E4 0010C124  48 30 23 A5 */	bl __dt__5CNodeFv
/* 8010F1E8 0010C128  38 7E 00 60 */	addi r3, r30, 0x60
/* 8010F1EC 0010C12C  38 80 FF FF */	li r4, -1
/* 8010F1F0 0010C130  48 30 23 99 */	bl __dt__5CNodeFv
.L_8010F1F4:
/* 8010F1F4 0010C134  34 1E 00 20 */	addic. r0, r30, 0x20
/* 8010F1F8 0010C138  41 82 00 24 */	beq .L_8010F21C
/* 8010F1FC 0010C13C  3C 80 80 4B */	lis r4, __vt__Q24Game12EnemyMgrNode@ha
/* 8010F200 0010C140  38 7E 00 20 */	addi r3, r30, 0x20
/* 8010F204 0010C144  38 A4 B5 70 */	addi r5, r4, __vt__Q24Game12EnemyMgrNode@l
/* 8010F208 0010C148  38 80 00 00 */	li r4, 0
/* 8010F20C 0010C14C  90 BE 00 20 */	stw r5, 0x20(r30)
/* 8010F210 0010C150  38 05 00 10 */	addi r0, r5, 0x10
/* 8010F214 0010C154  90 1E 00 38 */	stw r0, 0x38(r30)
/* 8010F218 0010C158  48 30 23 71 */	bl __dt__5CNodeFv
.L_8010F21C:
/* 8010F21C 0010C15C  38 7E 00 04 */	addi r3, r30, 4
/* 8010F220 0010C160  38 80 00 00 */	li r4, 0
/* 8010F224 0010C164  48 30 23 65 */	bl __dt__5CNodeFv
/* 8010F228 0010C168  7F E0 07 35 */	extsh. r0, r31
/* 8010F22C 0010C16C  40 81 00 0C */	ble .L_8010F238
/* 8010F230 0010C170  7F C3 F3 78 */	mr r3, r30
/* 8010F234 0010C174  4B F1 4E 81 */	bl __dl__FPv
.L_8010F238:
/* 8010F238 0010C178  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F23C 0010C17C  7F C3 F3 78 */	mr r3, r30
/* 8010F240 0010C180  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F244 0010C184  83 C1 00 08 */	lwz r30, 8(r1)
/* 8010F248 0010C188  7C 08 03 A6 */	mtlr r0
/* 8010F24C 0010C18C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F250 0010C190  4E 80 00 20 */	blr 
.endfn __dt__Q24Game15GeneralEnemyMgrFv

.fn getMatrixLoadType__Q24Game12EnemyMgrNodeFv, weak
/* 8010F254 0010C194  38 60 00 01 */	li r3, 1
/* 8010F258 0010C198  4E 80 00 20 */	blr 
.endfn getMatrixLoadType__Q24Game12EnemyMgrNodeFv

.fn doEntry__16GenericObjectMgrFv, weak
/* 8010F25C 0010C19C  4E 80 00 20 */	blr 
.endfn doEntry__16GenericObjectMgrFv

.fn "@24@getMatrixLoadType__Q24Game12EnemyMgrNodeFv", weak
/* 8010F260 0010C1A0  38 63 FF E8 */	addi r3, r3, -24
/* 8010F264 0010C1A4  4B FF FF F0 */	b getMatrixLoadType__Q24Game12EnemyMgrNodeFv
.endfn "@24@getMatrixLoadType__Q24Game12EnemyMgrNodeFv"

.fn "@24@doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport", weak
/* 8010F268 0010C1A8  38 63 FF E8 */	addi r3, r3, -24
/* 8010F26C 0010C1AC  4B FF E1 D8 */	b doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport
.endfn "@24@doSimpleDraw__Q24Game12EnemyMgrNodeFP8Viewport"

.fn "@24@doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics", weak
/* 8010F270 0010C1B0  38 63 FF E8 */	addi r3, r3, -24
/* 8010F274 0010C1B4  4B FF E1 20 */	b doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics
.endfn "@24@doDirectDraw__Q24Game12EnemyMgrNodeFR8Graphics"

.fn "@24@doSimulation__Q24Game12EnemyMgrNodeFf", weak
/* 8010F278 0010C1B8  38 63 FF E8 */	addi r3, r3, -24
/* 8010F27C 0010C1BC  4B FF E0 80 */	b doSimulation__Q24Game12EnemyMgrNodeFf
.endfn "@24@doSimulation__Q24Game12EnemyMgrNodeFf"

.fn "@24@doViewCalc__Q24Game12EnemyMgrNodeFv", weak
/* 8010F280 0010C1C0  38 63 FF E8 */	addi r3, r3, -24
/* 8010F284 0010C1C4  4B FF DF E0 */	b doViewCalc__Q24Game12EnemyMgrNodeFv
.endfn "@24@doViewCalc__Q24Game12EnemyMgrNodeFv"

.fn "@24@doSetView__Q24Game12EnemyMgrNodeFi", weak
/* 8010F288 0010C1C8  38 63 FF E8 */	addi r3, r3, -24
/* 8010F28C 0010C1CC  4B FF DF 50 */	b doSetView__Q24Game12EnemyMgrNodeFi
.endfn "@24@doSetView__Q24Game12EnemyMgrNodeFi"

.fn "@24@doEntry__Q24Game12EnemyMgrNodeFv", weak
/* 8010F290 0010C1D0  38 63 FF E8 */	addi r3, r3, -24
/* 8010F294 0010C1D4  4B FF DE B0 */	b doEntry__Q24Game12EnemyMgrNodeFv
.endfn "@24@doEntry__Q24Game12EnemyMgrNodeFv"

.fn "@24@doAnimation__Q24Game12EnemyMgrNodeFv", weak
/* 8010F298 0010C1D8  38 63 FF E8 */	addi r3, r3, -24
/* 8010F29C 0010C1DC  4B FF DE 20 */	b doAnimation__Q24Game12EnemyMgrNodeFv
.endfn "@24@doAnimation__Q24Game12EnemyMgrNodeFv"

.fn "@4@__dt__Q24Game15GeneralEnemyMgrFv", weak
/* 8010F2A0 0010C1E0  38 63 FF FC */	addi r3, r3, -4
/* 8010F2A4 0010C1E4  4B FF FE FC */	b __dt__Q24Game15GeneralEnemyMgrFv
.endfn "@4@__dt__Q24Game15GeneralEnemyMgrFv"
