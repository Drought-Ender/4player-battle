.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_ogObjSMenuItem_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8048E438, local
	.asciz "ogObjSMenuItem.cpp"
.endobj lbl_8048E438
.balign 4
.obj lbl_8048E44C, local
	.asciz "s_menu_item_l.blo"
.endobj lbl_8048E44C
.balign 4
.obj lbl_8048E460, local
	.asciz "s_menu_powerup_icon.blo"
.endobj lbl_8048E460
.balign 4
.obj lbl_8048E478, local
	.asciz "s_menu_item_spray.blo"
.endobj lbl_8048E478
.balign 4
.obj lbl_8048E490, local
	.asciz "s_menu_item_l.btk"
.endobj lbl_8048E490
.balign 4
.obj lbl_8048E4A4, local
	.asciz "s_menu_item_l_02.btk"
.endobj lbl_8048E4A4
.balign 4
.obj lbl_8048E4BC, local
	.asciz "s_menu_item_l_03.btk"
.endobj lbl_8048E4BC
.balign 4
.obj lbl_8048E4D4, local
	.asciz "s_menu_item_l_04.btk"
.endobj lbl_8048E4D4
.balign 4
.obj lbl_8048E4EC, local
	.asciz "s_menu_item_l_05.btk"
.endobj lbl_8048E4EC
.balign 4
.obj lbl_8048E504, local
	.asciz "s_menu_item_spray.btk"
.endobj lbl_8048E504
.balign 4
.obj lbl_8048E51C, local
	.asciz "icon tag not found !!\n"
.endobj lbl_8048E51C
.balign 4
.obj lbl_8048E534, local
	.asciz "screenObj.h"
.endobj lbl_8048E534
.balign 4
.obj lbl_8048E540, local
	.asciz "P2Assert"
.endobj lbl_8048E540

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj EquipItemList__Q24Game5Equip, global
	.4byte 0x00000002
	.4byte 0x00000003
	.4byte 0x00000004
	.4byte 0x00000005
	.4byte 0x00000006
	.4byte 0x00000001
	.4byte 0x00000007
	.4byte 0x00000000
	.4byte 0x00000008
	.4byte 0x0000000A
	.4byte 0x0000000B
	.4byte 0x00000009
.endobj EquipItemList__Q24Game5Equip
.balign 8
.obj ItemMsgID_List__Q22og9newScreen, global # u64 literals
	.8byte 0x00363132325F3030
	.8byte 0x00363131395F3030
	.8byte 0x00363132365F3030
	.8byte 0x00363131365F3030
	.8byte 0x00363131375F3030
	.8byte 0x00363132395F3030
	.8byte 0x00363132305F3030
	.8byte 0x00363131385F3030
	.8byte 0x00363132315F3030
	.8byte 0x00363132375F3030
	.8byte 0x00363132385F3030
	.8byte 0x00363132335F3030
.endobj ItemMsgID_List__Q22og9newScreen
.obj __vt__Q32og9newScreen12ObjSMenuItem, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q32og9newScreen12ObjSMenuItemFv
	.4byte getChildCount__5CNodeFv
	.4byte 0
	.4byte 0
	.4byte "@24@__dt__Q32og9newScreen12ObjSMenuItemFv"
	.4byte update__Q26Screen7ObjBaseFv
	.4byte draw__Q26Screen7ObjBaseFR8Graphics
	.4byte start__Q26Screen7ObjBaseFPCQ26Screen13StartSceneArg
	.4byte end__Q26Screen7ObjBaseFPCQ26Screen11EndSceneArg
	.4byte setOwner__Q26Screen7ObjBaseFPQ26Screen9SceneBase
	.4byte getOwner__Q26Screen7ObjBaseCFv
	.4byte create__Q26Screen7ObjBaseFP10JKRArchive
	.4byte confirmSetScene__Q26Screen7ObjBaseFRQ26Screen11SetSceneArg
	.4byte confirmStartScene__Q26Screen7ObjBaseFPQ26Screen13StartSceneArg
	.4byte confirmEndScene__Q26Screen7ObjBaseFPQ26Screen11EndSceneArg
	.4byte doStart__Q32og9newScreen12ObjSMenuItemFPCQ26Screen13StartSceneArg
	.4byte doEnd__Q32og9newScreen12ObjSMenuItemFPCQ26Screen11EndSceneArg
	.4byte doCreate__Q32og9newScreen12ObjSMenuItemFP10JKRArchive
	.4byte doUpdateFadein__Q32og9newScreen12ObjSMenuBaseFv
	.4byte doUpdateFadeinFinish__Q32og9newScreen12ObjSMenuBaseFv
	.4byte doUpdate__Q32og9newScreen12ObjSMenuItemFv
	.4byte doUpdateFinish__Q32og9newScreen12ObjSMenuItemFv
	.4byte doUpdateFadeout__Q32og9newScreen12ObjSMenuItemFv
	.4byte doUpdateFadeoutFinish__Q32og9newScreen12ObjSMenuBaseFv
	.4byte doDraw__Q32og9newScreen12ObjSMenuItemFR8Graphics
	.4byte doConfirmSetScene__Q26Screen7ObjBaseFRQ26Screen11SetSceneArg
	.4byte doConfirmStartScene__Q26Screen7ObjBaseFPQ26Screen13StartSceneArg
	.4byte doConfirmEndScene__Q26Screen7ObjBaseFRPQ26Screen11EndSceneArg
	.4byte in_L__Q32og9newScreen12ObjSMenuItemFv
	.4byte in_R__Q32og9newScreen12ObjSMenuItemFv
	.4byte wait__Q32og9newScreen12ObjSMenuItemFv
	.4byte out_L__Q32og9newScreen12ObjSMenuItemFv
	.4byte out_R__Q32og9newScreen12ObjSMenuItemFv
	.4byte loop__Q32og9newScreen12ObjSMenuBaseFv
	.4byte doUpdateCancelAction__Q32og9newScreen12ObjSMenuItemFv
	.4byte doUpdateRAction__Q32og9newScreen12ObjSMenuItemFv
	.4byte doUpdateLAction__Q32og9newScreen12ObjSMenuItemFv
	.4byte updateFadeIn__Q32og9newScreen12ObjSMenuBaseFv
	.4byte updateFadeOut__Q32og9newScreen12ObjSMenuBaseFv
	.4byte commonUpdate__Q32og9newScreen12ObjSMenuItemFv
.endobj __vt__Q32og9newScreen12ObjSMenuItem

.section .bss  # 0x804EFC20 - 0x8051467C
# ogObjSMenuItem.cpp
.comm msVal__Q32og9newScreen12ObjSMenuItem, 0x20, 4

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_8051D830, local
	.float -96.0
.endobj lbl_8051D830
.obj lbl_8051D834, local
	.float 0.0
.endobj lbl_8051D834
.obj lbl_8051D838, local
	.float -100.0
.endobj lbl_8051D838
.obj lbl_8051D83C, local
	.float 80.0
.endobj lbl_8051D83C
.obj lbl_8051D840, local
	.float 1.0
.endobj lbl_8051D840
.obj lbl_8051D844, local
	.float 15.0
.endobj lbl_8051D844
.obj lbl_8051D848, local
	.float -27.0
.endobj lbl_8051D848
.obj lbl_8051D84C, local
	.float 0.95
.endobj lbl_8051D84C
.obj lbl_8051D850, local
	.float 0.9
.endobj lbl_8051D850

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q32og9newScreen12ObjSMenuItemFPCc, global
/* 80312EF8 0030FE38  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80312EFC 0030FE3C  7C 08 02 A6 */	mflr r0
/* 80312F00 0030FE40  90 01 00 14 */	stw r0, 0x14(r1)
/* 80312F04 0030FE44  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80312F08 0030FE48  7C 9F 23 78 */	mr r31, r4
/* 80312F0C 0030FE4C  93 C1 00 08 */	stw r30, 8(r1)
/* 80312F10 0030FE50  7C 7E 1B 78 */	mr r30, r3
/* 80312F14 0030FE54  48 00 32 FD */	bl __ct__Q32og9newScreen12ObjSMenuBaseFv
/* 80312F18 0030FE58  3C 60 80 4E */	lis r3, __vt__Q32og9newScreen12ObjSMenuItem@ha
/* 80312F1C 0030FE5C  38 00 00 00 */	li r0, 0
/* 80312F20 0030FE60  38 83 86 D0 */	addi r4, r3, __vt__Q32og9newScreen12ObjSMenuItem@l
/* 80312F24 0030FE64  7F C3 F3 78 */	mr r3, r30
/* 80312F28 0030FE68  90 9E 00 00 */	stw r4, 0(r30)
/* 80312F2C 0030FE6C  38 84 00 10 */	addi r4, r4, 0x10
/* 80312F30 0030FE70  90 9E 00 18 */	stw r4, 0x18(r30)
/* 80312F34 0030FE74  90 1E 00 A8 */	stw r0, 0xa8(r30)
/* 80312F38 0030FE78  90 1E 00 AC */	stw r0, 0xac(r30)
/* 80312F3C 0030FE7C  90 1E 00 B4 */	stw r0, 0xb4(r30)
/* 80312F40 0030FE80  90 1E 00 B8 */	stw r0, 0xb8(r30)
/* 80312F44 0030FE84  90 1E 00 B0 */	stw r0, 0xb0(r30)
/* 80312F48 0030FE88  90 1E 00 BC */	stw r0, 0xbc(r30)
/* 80312F4C 0030FE8C  90 1E 00 C0 */	stw r0, 0xc0(r30)
/* 80312F50 0030FE90  90 1E 00 C4 */	stw r0, 0xc4(r30)
/* 80312F54 0030FE94  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 80312F58 0030FE98  93 FE 00 14 */	stw r31, 0x14(r30)
/* 80312F5C 0030FE9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80312F60 0030FEA0  83 C1 00 08 */	lwz r30, 8(r1)
/* 80312F64 0030FEA4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80312F68 0030FEA8  7C 08 03 A6 */	mtlr r0
/* 80312F6C 0030FEAC  38 21 00 10 */	addi r1, r1, 0x10
/* 80312F70 0030FEB0  4E 80 00 20 */	blr 
.endfn __ct__Q32og9newScreen12ObjSMenuItemFPCc

.fn __dt__Q32og9newScreen12ObjSMenuItemFv, global
/* 80312F74 0030FEB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80312F78 0030FEB8  7C 08 02 A6 */	mflr r0
/* 80312F7C 0030FEBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80312F80 0030FEC0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80312F84 0030FEC4  7C 9F 23 78 */	mr r31, r4
/* 80312F88 0030FEC8  93 C1 00 08 */	stw r30, 8(r1)
/* 80312F8C 0030FECC  7C 7E 1B 79 */	or. r30, r3, r3
/* 80312F90 0030FED0  41 82 00 8C */	beq .L_8031301C
/* 80312F94 0030FED4  3C 80 80 4E */	lis r4, __vt__Q32og9newScreen12ObjSMenuItem@ha
/* 80312F98 0030FED8  38 84 86 D0 */	addi r4, r4, __vt__Q32og9newScreen12ObjSMenuItem@l
/* 80312F9C 0030FEDC  90 9E 00 00 */	stw r4, 0(r30)
/* 80312FA0 0030FEE0  38 04 00 10 */	addi r0, r4, 0x10
/* 80312FA4 0030FEE4  90 1E 00 18 */	stw r0, 0x18(r30)
/* 80312FA8 0030FEE8  41 82 00 64 */	beq .L_8031300C
/* 80312FAC 0030FEEC  3C 80 80 4E */	lis r4, __vt__Q32og9newScreen12ObjSMenuBase@ha
/* 80312FB0 0030FEF0  38 84 89 B0 */	addi r4, r4, __vt__Q32og9newScreen12ObjSMenuBase@l
/* 80312FB4 0030FEF4  90 9E 00 00 */	stw r4, 0(r30)
/* 80312FB8 0030FEF8  38 04 00 10 */	addi r0, r4, 0x10
/* 80312FBC 0030FEFC  90 1E 00 18 */	stw r0, 0x18(r30)
/* 80312FC0 0030FF00  41 82 00 4C */	beq .L_8031300C
/* 80312FC4 0030FF04  3C 80 80 4F */	lis r4, __vt__Q26Screen7ObjBase@ha
/* 80312FC8 0030FF08  38 84 D7 58 */	addi r4, r4, __vt__Q26Screen7ObjBase@l
/* 80312FCC 0030FF0C  90 9E 00 00 */	stw r4, 0(r30)
/* 80312FD0 0030FF10  38 04 00 10 */	addi r0, r4, 0x10
/* 80312FD4 0030FF14  90 1E 00 18 */	stw r0, 0x18(r30)
/* 80312FD8 0030FF18  41 82 00 34 */	beq .L_8031300C
/* 80312FDC 0030FF1C  3C 80 80 4E */	lis r4, __vt__Q26Screen8IObjBase@ha
/* 80312FE0 0030FF20  38 84 82 40 */	addi r4, r4, __vt__Q26Screen8IObjBase@l
/* 80312FE4 0030FF24  90 9E 00 00 */	stw r4, 0(r30)
/* 80312FE8 0030FF28  38 04 00 10 */	addi r0, r4, 0x10
/* 80312FEC 0030FF2C  90 1E 00 18 */	stw r0, 0x18(r30)
/* 80312FF0 0030FF30  48 0F E5 E1 */	bl del__5CNodeFv
/* 80312FF4 0030FF34  38 7E 00 18 */	addi r3, r30, 0x18
/* 80312FF8 0030FF38  38 80 00 00 */	li r4, 0
/* 80312FFC 0030FF3C  4B D0 A0 39 */	bl __dt__11JKRDisposerFv
/* 80313000 0030FF40  7F C3 F3 78 */	mr r3, r30
/* 80313004 0030FF44  38 80 00 00 */	li r4, 0
/* 80313008 0030FF48  48 0F E5 81 */	bl __dt__5CNodeFv
.L_8031300C:
/* 8031300C 0030FF4C  7F E0 07 35 */	extsh. r0, r31
/* 80313010 0030FF50  40 81 00 0C */	ble .L_8031301C
/* 80313014 0030FF54  7F C3 F3 78 */	mr r3, r30
/* 80313018 0030FF58  4B D1 10 9D */	bl __dl__FPv
.L_8031301C:
/* 8031301C 0030FF5C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313020 0030FF60  7F C3 F3 78 */	mr r3, r30
/* 80313024 0030FF64  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80313028 0030FF68  83 C1 00 08 */	lwz r30, 8(r1)
/* 8031302C 0030FF6C  7C 08 03 A6 */	mtlr r0
/* 80313030 0030FF70  38 21 00 10 */	addi r1, r1, 0x10
/* 80313034 0030FF74  4E 80 00 20 */	blr 
.endfn __dt__Q32og9newScreen12ObjSMenuItemFv

.fn doCreate__Q32og9newScreen12ObjSMenuItemFP10JKRArchive, global
/* 80313038 0030FF78  94 21 FF 30 */	stwu r1, -0xd0(r1)
/* 8031303C 0030FF7C  7C 08 02 A6 */	mflr r0
/* 80313040 0030FF80  3C A0 80 49 */	lis r5, lbl_8048E438@ha
/* 80313044 0030FF84  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 80313048 0030FF88  BD C1 00 88 */	stmw r14, 0x88(r1)
/* 8031304C 0030FF8C  7C 7F 1B 78 */	mr r31, r3
/* 80313050 0030FF90  3A E5 E4 38 */	addi r23, r5, lbl_8048E438@l
/* 80313054 0030FF94  90 81 00 20 */	stw r4, 0x20(r1)
/* 80313058 0030FF98  48 14 0F 51 */	bl getDispMember__Q26Screen7ObjBaseFv
/* 8031305C 0030FF9C  3C 80 00 4F */	lis r4, 0x004F4741@ha
/* 80313060 0030FFA0  3C C0 49 54 */	lis r6, 0x4954454D@ha
/* 80313064 0030FFA4  3C A0 00 53 */	lis r5, 0x00534D5F@ha
/* 80313068 0030FFA8  38 84 47 41 */	addi r4, r4, 0x004F4741@l
/* 8031306C 0030FFAC  38 C6 45 4D */	addi r6, r6, 0x4954454D@l
/* 80313070 0030FFB0  38 A5 4D 5F */	addi r5, r5, 0x00534D5F@l
/* 80313074 0030FFB4  4B FF C4 4D */	bl getSubMember__Q32og6Screen14DispMemberBaseFUlUx
/* 80313078 0030FFB8  90 7F 00 A8 */	stw r3, 0xa8(r31)
/* 8031307C 0030FFBC  80 1F 00 A8 */	lwz r0, 0xa8(r31)
/* 80313080 0030FFC0  28 00 00 00 */	cmplwi r0, 0
/* 80313084 0030FFC4  40 82 00 38 */	bne .L_803130BC
/* 80313088 0030FFC8  38 60 00 C4 */	li r3, 0xc4
/* 8031308C 0030FFCC  4B D1 0E 19 */	bl __nw__FUl
/* 80313090 0030FFD0  28 03 00 00 */	cmplwi r3, 0
/* 80313094 0030FFD4  41 82 00 08 */	beq .L_8031309C
/* 80313098 0030FFD8  4B F0 22 61 */	bl __ct__Q32og6Screen18DispMemberSMenuAllFv
.L_8031309C:
/* 8031309C 0030FFDC  3C 80 00 4F */	lis r4, 0x004F4741@ha
/* 803130A0 0030FFE0  3C C0 49 54 */	lis r6, 0x4954454D@ha
/* 803130A4 0030FFE4  3C A0 00 53 */	lis r5, 0x00534D5F@ha
/* 803130A8 0030FFE8  38 84 47 41 */	addi r4, r4, 0x004F4741@l
/* 803130AC 0030FFEC  38 C6 45 4D */	addi r6, r6, 0x4954454D@l
/* 803130B0 0030FFF0  38 A5 4D 5F */	addi r5, r5, 0x00534D5F@l
/* 803130B4 0030FFF4  4B FF C4 0D */	bl getSubMember__Q32og6Screen14DispMemberBaseFUlUx
/* 803130B8 0030FFF8  90 7F 00 A8 */	stw r3, 0xa8(r31)
.L_803130BC:
/* 803130BC 0030FFFC  38 60 01 48 */	li r3, 0x148
/* 803130C0 00310000  4B D1 0D E5 */	bl __nw__FUl
/* 803130C4 00310004  28 03 00 00 */	cmplwi r3, 0
/* 803130C8 00310008  41 82 00 08 */	beq .L_803130D0
/* 803130CC 0031000C  48 12 1C E1 */	bl __ct__Q29P2DScreen10Mgr_tuningFv
.L_803130D0:
/* 803130D0 00310010  90 7F 00 AC */	stw r3, 0xac(r31)
/* 803130D4 00310014  38 97 00 14 */	addi r4, r23, 0x14
/* 803130D8 00310018  80 C1 00 20 */	lwz r6, 0x20(r1)
/* 803130DC 0031001C  3C A0 01 04 */	lis r5, 0x104
/* 803130E0 00310020  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 803130E4 00310024  4B D2 C5 41 */	bl set__9J2DScreenFPCcUlP10JKRArchive
/* 803130E8 00310028  38 60 01 18 */	li r3, 0x118
/* 803130EC 0031002C  4B D1 0D B9 */	bl __nw__FUl
/* 803130F0 00310030  7C 78 1B 79 */	or. r24, r3, r3
/* 803130F4 00310034  41 82 00 0C */	beq .L_80313100
/* 803130F8 00310038  4B D2 C3 7D */	bl __ct__9J2DScreenFv
/* 803130FC 0031003C  7C 78 1B 78 */	mr r24, r3
.L_80313100:
/* 80313100 00310040  80 C1 00 20 */	lwz r6, 0x20(r1)
/* 80313104 00310044  7F 03 C3 78 */	mr r3, r24
/* 80313108 00310048  38 97 00 28 */	addi r4, r23, 0x28
/* 8031310C 0031004C  3C A0 01 04 */	lis r5, 0x104
/* 80313110 00310050  4B D2 C5 15 */	bl set__9J2DScreenFPCcUlP10JKRArchive
/* 80313114 00310054  3D 20 66 66 */	lis r9, 0x66666667@ha
/* 80313118 00310058  3D 00 65 6D */	lis r8, 0x656D3030@ha
/* 8031311C 0031005C  3C E0 00 4E */	lis r7, 0x004E6974@ha
/* 80313120 00310060  3C C0 6F 6E */	lis r6, 0x6F6E3030@ha
/* 80313124 00310064  3C A0 00 50 */	lis r5, 0x00506963@ha
/* 80313128 00310068  3C 80 6D 62 */	lis r4, 0x6D623030@ha
/* 8031312C 0031006C  3C 60 50 69 */	lis r3, 0x50697465@ha
/* 80313130 00310070  3A C9 66 67 */	addi r22, r9, 0x66666667@l
/* 80313134 00310074  3A 88 30 30 */	addi r20, r8, 0x656D3030@l
/* 80313138 00310078  3A 67 69 74 */	addi r19, r7, 0x004E6974@l
/* 8031313C 0031007C  3A 26 30 30 */	addi r17, r6, 0x6F6E3030@l
/* 80313140 00310080  3A 05 69 63 */	addi r16, r5, 0x00506963@l
/* 80313144 00310084  39 E4 30 30 */	addi r15, r4, 0x6D623030@l
/* 80313148 00310088  39 C3 74 65 */	addi r14, r3, 0x50697465@l
/* 8031314C 0031008C  3B 60 00 00 */	li r27, 0
.L_80313150:
/* 80313150 00310090  7C B6 D8 96 */	mulhw r5, r22, r27
/* 80313154 00310094  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313158 00310098  7C A0 16 70 */	srawi r0, r5, 2
/* 8031315C 0031009C  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80313160 003100A0  7C 00 22 14 */	add r0, r0, r4
/* 80313164 003100A4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 80313168 003100A8  7E A0 D8 50 */	subf r21, r0, r27
/* 8031316C 003100AC  7E BA FE 70 */	srawi r26, r21, 0x1f
/* 80313170 003100B0  7C D5 A0 14 */	addc r6, r21, r20
/* 80313174 003100B4  7C FA 99 14 */	adde r7, r26, r19
/* 80313178 003100B8  7C A0 16 70 */	srawi r0, r5, 2
/* 8031317C 003100BC  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80313180 003100C0  7C A0 22 14 */	add r5, r0, r4
/* 80313184 003100C4  7C 16 28 96 */	mulhw r0, r22, r5
/* 80313188 003100C8  7C 00 16 70 */	srawi r0, r0, 2
/* 8031318C 003100CC  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80313190 003100D0  7C 00 22 14 */	add r0, r0, r4
/* 80313194 003100D4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 80313198 003100D8  7C 00 28 50 */	subf r0, r0, r5
/* 8031319C 003100DC  54 12 40 2E */	slwi r18, r0, 8
/* 803131A0 003100E0  7E 59 FE 70 */	srawi r25, r18, 0x1f
/* 803131A4 003100E4  7C C6 90 14 */	addc r6, r6, r18
/* 803131A8 003100E8  7C A7 C9 14 */	adde r5, r7, r25
/* 803131AC 003100EC  4B FE FD 01 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803131B0 003100F0  7C 95 88 14 */	addc r4, r21, r17
/* 803131B4 003100F4  7C 65 1B 78 */	mr r5, r3
/* 803131B8 003100F8  7C 1A 81 14 */	adde r0, r26, r16
/* 803131BC 003100FC  7F 03 C3 78 */	mr r3, r24
/* 803131C0 00310100  7C C4 90 14 */	addc r6, r4, r18
/* 803131C4 00310104  7C BC 2B 78 */	mr r28, r5
/* 803131C8 00310108  7C A0 C9 14 */	adde r5, r0, r25
/* 803131CC 0031010C  4B FE FC E1 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803131D0 00310110  7C 95 78 14 */	addc r4, r21, r15
/* 803131D4 00310114  7C 65 1B 78 */	mr r5, r3
/* 803131D8 00310118  7C 1A 71 14 */	adde r0, r26, r14
/* 803131DC 0031011C  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 803131E0 00310120  7C C4 90 14 */	addc r6, r4, r18
/* 803131E4 00310124  7C B2 2B 78 */	mr r18, r5
/* 803131E8 00310128  7C A0 C9 14 */	adde r5, r0, r25
/* 803131EC 0031012C  4B FE FC C1 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803131F0 00310130  7C 60 1B 78 */	mr r0, r3
/* 803131F4 00310134  7E 43 93 78 */	mr r3, r18
/* 803131F8 00310138  7C 15 03 78 */	mr r21, r0
/* 803131FC 0031013C  88 95 00 B7 */	lbz r4, 0xb7(r21)
/* 80313200 00310140  4B D2 5A BD */	bl setBasePosition__7J2DPaneF15J2DBasePosition
/* 80313204 00310144  7F 83 E3 78 */	mr r3, r28
/* 80313208 00310148  7E 44 93 78 */	mr r4, r18
/* 8031320C 0031014C  4B D2 44 B9 */	bl appendChild__7J2DPaneFP7J2DPane
/* 80313210 00310150  7E A3 AB 78 */	mr r3, r21
/* 80313214 00310154  4B D2 51 0D */	bl getBounds__7J2DPaneFv
/* 80313218 00310158  7C 64 1B 78 */	mr r4, r3
/* 8031321C 0031015C  7E 43 93 78 */	mr r3, r18
/* 80313220 00310160  4B D2 4D 19 */	bl "place__7J2DPaneFRCQ29JGeometry8TBox2<f>"
/* 80313224 00310164  3B 7B 00 01 */	addi r27, r27, 1
/* 80313228 00310168  2C 1B 00 0C */	cmpwi r27, 0xc
/* 8031322C 0031016C  41 80 FF 24 */	blt .L_80313150
/* 80313230 00310170  38 60 01 38 */	li r3, 0x138
/* 80313234 00310174  4B D1 0C 71 */	bl __nw__FUl
/* 80313238 00310178  28 03 00 00 */	cmplwi r3, 0
/* 8031323C 0031017C  41 82 00 08 */	beq .L_80313244
/* 80313240 00310180  48 12 18 81 */	bl __ct__Q29P2DScreen3MgrFv
.L_80313244:
/* 80313244 00310184  90 7F 00 B0 */	stw r3, 0xb0(r31)
/* 80313248 00310188  38 97 00 40 */	addi r4, r23, 0x40
/* 8031324C 0031018C  80 C1 00 20 */	lwz r6, 0x20(r1)
/* 80313250 00310190  3C A0 01 04 */	lis r5, 0x104
/* 80313254 00310194  80 7F 00 B0 */	lwz r3, 0xb0(r31)
/* 80313258 00310198  4B D2 C3 CD */	bl set__9J2DScreenFPCcUlP10JKRArchive
/* 8031325C 0031019C  3C A0 61 79 */	lis r5, 0x61793030@ha
/* 80313260 003101A0  3C 80 4E 73 */	lis r4, 0x4E737072@ha
/* 80313264 003101A4  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313268 003101A8  38 C5 30 30 */	addi r6, r5, 0x61793030@l
/* 8031326C 003101AC  38 A4 70 72 */	addi r5, r4, 0x4E737072@l
/* 80313270 003101B0  4B FE FC 3D */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313274 003101B4  90 7F 00 BC */	stw r3, 0xbc(r31)
/* 80313278 003101B8  3C A0 61 79 */	lis r5, 0x61793031@ha
/* 8031327C 003101BC  3C 80 4E 73 */	lis r4, 0x4E737072@ha
/* 80313280 003101C0  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313284 003101C4  38 C5 30 31 */	addi r6, r5, 0x61793031@l
/* 80313288 003101C8  38 A4 70 72 */	addi r5, r4, 0x4E737072@l
/* 8031328C 003101CC  4B FE FC 21 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313290 003101D0  90 7F 00 C0 */	stw r3, 0xc0(r31)
/* 80313294 003101D4  3C A0 61 79 */	lis r5, 0x61793030@ha
/* 80313298 003101D8  3C 80 4E 73 */	lis r4, 0x4E737072@ha
/* 8031329C 003101DC  80 7F 00 B0 */	lwz r3, 0xb0(r31)
/* 803132A0 003101E0  38 C5 30 30 */	addi r6, r5, 0x61793030@l
/* 803132A4 003101E4  38 A4 70 72 */	addi r5, r4, 0x4E737072@l
/* 803132A8 003101E8  4B FE FC 05 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803132AC 003101EC  90 7F 00 C4 */	stw r3, 0xc4(r31)
/* 803132B0 003101F0  3C A0 61 79 */	lis r5, 0x61793031@ha
/* 803132B4 003101F4  3C 80 4E 73 */	lis r4, 0x4E737072@ha
/* 803132B8 003101F8  80 7F 00 B0 */	lwz r3, 0xb0(r31)
/* 803132BC 003101FC  38 C5 30 31 */	addi r6, r5, 0x61793031@l
/* 803132C0 00310200  38 A4 70 72 */	addi r5, r4, 0x4E737072@l
/* 803132C4 00310204  4B FE FB E9 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803132C8 00310208  90 7F 00 C8 */	stw r3, 0xc8(r31)
/* 803132CC 0031020C  3C 60 80 51 */	lis r3, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 803132D0 00310210  38 83 3C 90 */	addi r4, r3, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 803132D4 00310214  80 7F 00 BC */	lwz r3, 0xbc(r31)
/* 803132D8 00310218  C0 24 00 08 */	lfs f1, 8(r4)
/* 803132DC 0031021C  81 83 00 00 */	lwz r12, 0(r3)
/* 803132E0 00310220  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 803132E4 00310224  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 803132E8 00310228  7D 89 03 A6 */	mtctr r12
/* 803132EC 0031022C  4E 80 04 21 */	bctrl 
/* 803132F0 00310230  80 7F 00 C0 */	lwz r3, 0xc0(r31)
/* 803132F4 00310234  3C 80 80 51 */	lis r4, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 803132F8 00310238  38 84 3C 90 */	addi r4, r4, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 803132FC 0031023C  81 83 00 00 */	lwz r12, 0(r3)
/* 80313300 00310240  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 80313304 00310244  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80313308 00310248  C0 44 00 14 */	lfs f2, 0x14(r4)
/* 8031330C 0031024C  7D 89 03 A6 */	mtctr r12
/* 80313310 00310250  4E 80 04 21 */	bctrl 
/* 80313314 00310254  80 7F 00 A8 */	lwz r3, 0xa8(r31)
/* 80313318 00310258  88 83 00 24 */	lbz r4, 0x24(r3)
/* 8031331C 0031025C  28 04 00 00 */	cmplwi r4, 0
/* 80313320 00310260  40 82 00 90 */	bne .L_803133B0
/* 80313324 00310264  88 03 00 25 */	lbz r0, 0x25(r3)
/* 80313328 00310268  28 00 00 00 */	cmplwi r0, 0
/* 8031332C 0031026C  40 82 00 84 */	bne .L_803133B0
/* 80313330 00310270  3C 80 77 69 */	lis r4, 0x77696E30@ha
/* 80313334 00310274  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313338 00310278  38 C4 6E 30 */	addi r6, r4, 0x77696E30@l
/* 8031333C 0031027C  38 A0 00 4E */	li r5, 0x4e
/* 80313340 00310280  4B FE FB 6D */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313344 00310284  38 00 00 00 */	li r0, 0
/* 80313348 00310288  3C 80 77 69 */	lis r4, 0x77696E31@ha
/* 8031334C 0031028C  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 80313350 00310290  38 C4 6E 31 */	addi r6, r4, 0x77696E31@l
/* 80313354 00310294  38 A0 00 4E */	li r5, 0x4e
/* 80313358 00310298  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 8031335C 0031029C  4B FE FB 51 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313360 003102A0  38 00 00 00 */	li r0, 0
/* 80313364 003102A4  3C A0 5F 30 */	lis r5, 0x5F303032@ha
/* 80313368 003102A8  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 8031336C 003102AC  3C 80 4E 55 */	lis r4, 0x4E554C4C@ha
/* 80313370 003102B0  38 C5 30 32 */	addi r6, r5, 0x5F303032@l
/* 80313374 003102B4  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313378 003102B8  38 A4 4C 4C */	addi r5, r4, 0x4E554C4C@l
/* 8031337C 003102BC  4B FE FB 31 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313380 003102C0  81 83 00 00 */	lwz r12, 0(r3)
/* 80313384 003102C4  C0 22 F4 D0 */	lfs f1, lbl_8051D830@sda21(r2)
/* 80313388 003102C8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8031338C 003102CC  C0 42 F4 D4 */	lfs f2, lbl_8051D834@sda21(r2)
/* 80313390 003102D0  7D 89 03 A6 */	mtctr r12
/* 80313394 003102D4  4E 80 04 21 */	bctrl 
/* 80313398 003102D8  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 8031339C 003102DC  38 00 00 00 */	li r0, 0
/* 803133A0 003102E0  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 803133A4 003102E4  80 7F 00 C8 */	lwz r3, 0xc8(r31)
/* 803133A8 003102E8  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 803133AC 003102EC  48 00 00 C0 */	b .L_8031346C
.L_803133B0:
/* 803133B0 003102F0  28 04 00 00 */	cmplwi r4, 0
/* 803133B4 003102F4  40 82 00 5C */	bne .L_80313410
/* 803133B8 003102F8  3C 80 77 69 */	lis r4, 0x77696E30@ha
/* 803133BC 003102FC  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 803133C0 00310300  38 C4 6E 30 */	addi r6, r4, 0x77696E30@l
/* 803133C4 00310304  38 A0 00 4E */	li r5, 0x4e
/* 803133C8 00310308  4B FE FA E5 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803133CC 0031030C  38 00 00 00 */	li r0, 0
/* 803133D0 00310310  3C 80 77 69 */	lis r4, 0x77696E31@ha
/* 803133D4 00310314  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 803133D8 00310318  38 C4 6E 31 */	addi r6, r4, 0x77696E31@l
/* 803133DC 0031031C  38 A0 00 4E */	li r5, 0x4e
/* 803133E0 00310320  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 803133E4 00310324  4B FE FA C9 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803133E8 00310328  81 83 00 00 */	lwz r12, 0(r3)
/* 803133EC 0031032C  C0 22 F4 D4 */	lfs f1, lbl_8051D834@sda21(r2)
/* 803133F0 00310330  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 803133F4 00310334  C0 42 F4 D8 */	lfs f2, lbl_8051D838@sda21(r2)
/* 803133F8 00310338  7D 89 03 A6 */	mtctr r12
/* 803133FC 0031033C  4E 80 04 21 */	bctrl 
/* 80313400 00310340  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 80313404 00310344  38 00 00 00 */	li r0, 0
/* 80313408 00310348  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 8031340C 0031034C  48 00 00 60 */	b .L_8031346C
.L_80313410:
/* 80313410 00310350  88 03 00 25 */	lbz r0, 0x25(r3)
/* 80313414 00310354  28 00 00 00 */	cmplwi r0, 0
/* 80313418 00310358  40 82 00 54 */	bne .L_8031346C
/* 8031341C 0031035C  3C 80 77 69 */	lis r4, 0x77696E30@ha
/* 80313420 00310360  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313424 00310364  38 C4 6E 30 */	addi r6, r4, 0x77696E30@l
/* 80313428 00310368  38 A0 00 4E */	li r5, 0x4e
/* 8031342C 0031036C  4B FE FA 81 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313430 00310370  81 83 00 00 */	lwz r12, 0(r3)
/* 80313434 00310374  C0 22 F4 D4 */	lfs f1, lbl_8051D834@sda21(r2)
/* 80313438 00310378  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8031343C 0031037C  C0 42 F4 DC */	lfs f2, lbl_8051D83C@sda21(r2)
/* 80313440 00310380  7D 89 03 A6 */	mtctr r12
/* 80313444 00310384  4E 80 04 21 */	bctrl 
/* 80313448 00310388  3C 80 77 69 */	lis r4, 0x77696E31@ha
/* 8031344C 0031038C  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313450 00310390  38 C4 6E 31 */	addi r6, r4, 0x77696E31@l
/* 80313454 00310394  38 A0 00 4E */	li r5, 0x4e
/* 80313458 00310398  4B FE FA 55 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 8031345C 0031039C  38 00 00 00 */	li r0, 0
/* 80313460 003103A0  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 80313464 003103A4  80 7F 00 C8 */	lwz r3, 0xc8(r31)
/* 80313468 003103A8  98 03 00 B0 */	stb r0, 0xb0(r3)
.L_8031346C:
/* 8031346C 003103AC  38 60 00 1C */	li r3, 0x1c
/* 80313470 003103B0  4B D1 0A 35 */	bl __nw__FUl
/* 80313474 003103B4  28 03 00 00 */	cmplwi r3, 0
/* 80313478 003103B8  41 82 00 0C */	beq .L_80313484
/* 8031347C 003103BC  38 80 00 05 */	li r4, 5
/* 80313480 003103C0  4B FF 1F D9 */	bl __ct__Q32og6Screen9AnimGroupFi
.L_80313484:
/* 80313484 003103C4  90 7F 00 B4 */	stw r3, 0xb4(r31)
/* 80313488 003103C8  3C 60 80 51 */	lis r3, msBaseVal__Q32og9newScreen12ObjSMenuBase@ha
/* 8031348C 003103CC  38 E3 3C F4 */	addi r7, r3, msBaseVal__Q32og9newScreen12ObjSMenuBase@l
/* 80313490 003103D0  80 81 00 20 */	lwz r4, 0x20(r1)
/* 80313494 003103D4  80 7F 00 B4 */	lwz r3, 0xb4(r31)
/* 80313498 003103D8  38 D7 00 58 */	addi r6, r23, 0x58
/* 8031349C 003103DC  80 BF 00 AC */	lwz r5, 0xac(r31)
/* 803134A0 003103E0  C0 27 00 00 */	lfs f1, 0(r7)
/* 803134A4 003103E4  4B FF 24 F5 */	bl registAnimGroupScreen__Q22og6ScreenFPQ32og6Screen9AnimGroupP10JKRArchiveP9J2DScreenPcf
/* 803134A8 003103E8  3C 80 80 51 */	lis r4, msBaseVal__Q32og9newScreen12ObjSMenuBase@ha
/* 803134AC 003103EC  80 7F 00 B4 */	lwz r3, 0xb4(r31)
/* 803134B0 003103F0  C0 24 3C F4 */	lfs f1, msBaseVal__Q32og9newScreen12ObjSMenuBase@l(r4)
/* 803134B4 003103F4  38 D7 00 6C */	addi r6, r23, 0x6c
/* 803134B8 003103F8  80 BF 00 AC */	lwz r5, 0xac(r31)
/* 803134BC 003103FC  80 81 00 20 */	lwz r4, 0x20(r1)
/* 803134C0 00310400  4B FF 24 D9 */	bl registAnimGroupScreen__Q22og6ScreenFPQ32og6Screen9AnimGroupP10JKRArchiveP9J2DScreenPcf
/* 803134C4 00310404  3C 80 80 51 */	lis r4, msBaseVal__Q32og9newScreen12ObjSMenuBase@ha
/* 803134C8 00310408  80 7F 00 B4 */	lwz r3, 0xb4(r31)
/* 803134CC 0031040C  C0 24 3C F4 */	lfs f1, msBaseVal__Q32og9newScreen12ObjSMenuBase@l(r4)
/* 803134D0 00310410  38 D7 00 84 */	addi r6, r23, 0x84
/* 803134D4 00310414  80 BF 00 AC */	lwz r5, 0xac(r31)
/* 803134D8 00310418  80 81 00 20 */	lwz r4, 0x20(r1)
/* 803134DC 0031041C  4B FF 24 BD */	bl registAnimGroupScreen__Q22og6ScreenFPQ32og6Screen9AnimGroupP10JKRArchiveP9J2DScreenPcf
/* 803134E0 00310420  3C 80 80 51 */	lis r4, msBaseVal__Q32og9newScreen12ObjSMenuBase@ha
/* 803134E4 00310424  80 7F 00 B4 */	lwz r3, 0xb4(r31)
/* 803134E8 00310428  C0 24 3C F4 */	lfs f1, msBaseVal__Q32og9newScreen12ObjSMenuBase@l(r4)
/* 803134EC 0031042C  38 D7 00 9C */	addi r6, r23, 0x9c
/* 803134F0 00310430  80 BF 00 AC */	lwz r5, 0xac(r31)
/* 803134F4 00310434  80 81 00 20 */	lwz r4, 0x20(r1)
/* 803134F8 00310438  4B FF 24 A1 */	bl registAnimGroupScreen__Q22og6ScreenFPQ32og6Screen9AnimGroupP10JKRArchiveP9J2DScreenPcf
/* 803134FC 0031043C  3C 80 80 51 */	lis r4, msBaseVal__Q32og9newScreen12ObjSMenuBase@ha
/* 80313500 00310440  80 7F 00 B4 */	lwz r3, 0xb4(r31)
/* 80313504 00310444  C0 24 3C F4 */	lfs f1, msBaseVal__Q32og9newScreen12ObjSMenuBase@l(r4)
/* 80313508 00310448  38 D7 00 B4 */	addi r6, r23, 0xb4
/* 8031350C 0031044C  80 BF 00 AC */	lwz r5, 0xac(r31)
/* 80313510 00310450  80 81 00 20 */	lwz r4, 0x20(r1)
/* 80313514 00310454  4B FF 24 85 */	bl registAnimGroupScreen__Q22og6ScreenFPQ32og6Screen9AnimGroupP10JKRArchiveP9J2DScreenPcf
/* 80313518 00310458  38 60 00 1C */	li r3, 0x1c
/* 8031351C 0031045C  4B D1 09 89 */	bl __nw__FUl
/* 80313520 00310460  28 03 00 00 */	cmplwi r3, 0
/* 80313524 00310464  41 82 00 0C */	beq .L_80313530
/* 80313528 00310468  38 80 00 01 */	li r4, 1
/* 8031352C 0031046C  4B FF 1F 2D */	bl __ct__Q32og6Screen9AnimGroupFi
.L_80313530:
/* 80313530 00310470  90 7F 00 B8 */	stw r3, 0xb8(r31)
/* 80313534 00310474  38 D7 00 CC */	addi r6, r23, 0xcc
/* 80313538 00310478  80 81 00 20 */	lwz r4, 0x20(r1)
/* 8031353C 0031047C  C0 22 F4 E0 */	lfs f1, lbl_8051D840@sda21(r2)
/* 80313540 00310480  80 7F 00 B8 */	lwz r3, 0xb8(r31)
/* 80313544 00310484  80 BF 00 B0 */	lwz r5, 0xb0(r31)
/* 80313548 00310488  4B FF 24 51 */	bl registAnimGroupScreen__Q22og6ScreenFPQ32og6Screen9AnimGroupP10JKRArchiveP9J2DScreenPcf
/* 8031354C 0031048C  80 BF 00 A8 */	lwz r5, 0xa8(r31)
/* 80313550 00310490  3C 60 75 70 */	lis r3, 0x75705F32@ha
/* 80313554 00310494  39 03 5F 32 */	addi r8, r3, 0x75705F32@l
/* 80313558 00310498  38 80 00 03 */	li r4, 3
/* 8031355C 0031049C  38 A5 00 08 */	addi r5, r5, 8
/* 80313560 003104A0  38 00 00 00 */	li r0, 0
/* 80313564 003104A4  90 A1 00 08 */	stw r5, 8(r1)
/* 80313568 003104A8  38 C3 5F 31 */	addi r6, r3, 0x5f31
/* 8031356C 003104AC  7D 0A 43 78 */	mr r10, r8
/* 80313570 003104B0  38 A0 00 50 */	li r5, 0x50
/* 80313574 003104B4  90 81 00 0C */	stw r4, 0xc(r1)
/* 80313578 003104B8  38 E0 00 50 */	li r7, 0x50
/* 8031357C 003104BC  39 20 00 50 */	li r9, 0x50
/* 80313580 003104C0  90 81 00 10 */	stw r4, 0x10(r1)
/* 80313584 003104C4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313588 003104C8  80 01 00 20 */	lwz r0, 0x20(r1)
/* 8031358C 003104CC  90 01 00 18 */	stw r0, 0x18(r1)
/* 80313590 003104D0  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313594 003104D4  4B FF 8F 9D */	bl setCallBack_CounterRV__Q22og6ScreenFPQ29P2DScreen3MgrUxUxUxPUlUsUsbP10JKRArchive
/* 80313598 003104D8  80 BF 00 A8 */	lwz r5, 0xa8(r31)
/* 8031359C 003104DC  3C 60 70 53 */	lis r3, 0x70535F32@ha
/* 803135A0 003104E0  39 03 5F 32 */	addi r8, r3, 0x70535F32@l
/* 803135A4 003104E4  38 80 00 02 */	li r4, 2
/* 803135A8 003104E8  38 A5 00 0C */	addi r5, r5, 0xc
/* 803135AC 003104EC  38 00 00 00 */	li r0, 0
/* 803135B0 003104F0  90 A1 00 08 */	stw r5, 8(r1)
/* 803135B4 003104F4  38 C3 5F 31 */	addi r6, r3, 0x5f31
/* 803135B8 003104F8  7D 0A 43 78 */	mr r10, r8
/* 803135BC 003104FC  38 A0 50 75 */	li r5, 0x5075
/* 803135C0 00310500  90 81 00 0C */	stw r4, 0xc(r1)
/* 803135C4 00310504  38 E0 50 75 */	li r7, 0x5075
/* 803135C8 00310508  39 20 50 75 */	li r9, 0x5075
/* 803135CC 0031050C  90 81 00 10 */	stw r4, 0x10(r1)
/* 803135D0 00310510  90 01 00 14 */	stw r0, 0x14(r1)
/* 803135D4 00310514  80 01 00 20 */	lwz r0, 0x20(r1)
/* 803135D8 00310518  90 01 00 18 */	stw r0, 0x18(r1)
/* 803135DC 0031051C  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 803135E0 00310520  4B FF 8F 51 */	bl setCallBack_CounterRV__Q22og6ScreenFPQ29P2DScreen3MgrUxUxUxPUlUsUsbP10JKRArchive
/* 803135E4 00310524  80 BF 00 A8 */	lwz r5, 0xa8(r31)
/* 803135E8 00310528  3C 80 77 6E */	lis r4, 0x776E5F32@ha
/* 803135EC 0031052C  39 04 5F 32 */	addi r8, r4, 0x776E5F32@l
/* 803135F0 00310530  39 60 00 03 */	li r11, 3
/* 803135F4 00310534  38 05 00 10 */	addi r0, r5, 0x10
/* 803135F8 00310538  3C 60 00 50 */	lis r3, 0x0050646F@ha
/* 803135FC 0031053C  90 01 00 08 */	stw r0, 8(r1)
/* 80313600 00310540  38 A3 64 6F */	addi r5, r3, 0x0050646F@l
/* 80313604 00310544  38 00 00 00 */	li r0, 0
/* 80313608 00310548  7D 0A 43 78 */	mr r10, r8
/* 8031360C 0031054C  91 61 00 0C */	stw r11, 0xc(r1)
/* 80313610 00310550  7C A7 2B 78 */	mr r7, r5
/* 80313614 00310554  7C A9 2B 78 */	mr r9, r5
/* 80313618 00310558  38 C4 5F 31 */	addi r6, r4, 0x5f31
/* 8031361C 0031055C  91 61 00 10 */	stw r11, 0x10(r1)
/* 80313620 00310560  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313624 00310564  80 01 00 20 */	lwz r0, 0x20(r1)
/* 80313628 00310568  90 01 00 18 */	stw r0, 0x18(r1)
/* 8031362C 0031056C  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313630 00310570  4B FF 8F 01 */	bl setCallBack_CounterRV__Q22og6ScreenFPQ29P2DScreen3MgrUxUxUxPUlUsUsbP10JKRArchive
/* 80313634 00310574  80 BF 00 A8 */	lwz r5, 0xa8(r31)
/* 80313638 00310578  3C 80 6E 53 */	lis r4, 0x6E535F32@ha
/* 8031363C 0031057C  39 04 5F 32 */	addi r8, r4, 0x6E535F32@l
/* 80313640 00310580  39 60 00 02 */	li r11, 2
/* 80313644 00310584  38 05 00 14 */	addi r0, r5, 0x14
/* 80313648 00310588  3C 60 50 64 */	lis r3, 0x50646F77@ha
/* 8031364C 0031058C  90 01 00 08 */	stw r0, 8(r1)
/* 80313650 00310590  38 A3 6F 77 */	addi r5, r3, 0x50646F77@l
/* 80313654 00310594  38 00 00 00 */	li r0, 0
/* 80313658 00310598  7D 0A 43 78 */	mr r10, r8
/* 8031365C 0031059C  91 61 00 0C */	stw r11, 0xc(r1)
/* 80313660 003105A0  7C A7 2B 78 */	mr r7, r5
/* 80313664 003105A4  7C A9 2B 78 */	mr r9, r5
/* 80313668 003105A8  38 C4 5F 31 */	addi r6, r4, 0x5f31
/* 8031366C 003105AC  91 61 00 10 */	stw r11, 0x10(r1)
/* 80313670 003105B0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313674 003105B4  80 01 00 20 */	lwz r0, 0x20(r1)
/* 80313678 003105B8  90 01 00 18 */	stw r0, 0x18(r1)
/* 8031367C 003105BC  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313680 003105C0  4B FF 8E B1 */	bl setCallBack_CounterRV__Q22og6ScreenFPQ29P2DScreen3MgrUxUxUxPUlUsUsbP10JKRArchive
/* 80313684 003105C4  38 00 00 FF */	li r0, 0xff
/* 80313688 003105C8  3C C0 6D 30 */	lis r6, 0x6D303030@ha
/* 8031368C 003105CC  3C 80 80 4E */	lis r4, ItemMsgID_List__Q22og9newScreen@ha
/* 80313690 003105D0  3C A0 54 69 */	lis r5, 0x54697465@ha
/* 80313694 003105D4  3C 60 80 4E */	lis r3, EquipItemList__Q24Game5Equip@ha
/* 80313698 003105D8  98 01 00 38 */	stb r0, 0x38(r1)
/* 8031369C 003105DC  3A C4 86 70 */	addi r22, r4, ItemMsgID_List__Q22og9newScreen@l
/* 803136A0 003105E0  3C 80 6F 6E */	lis r4, 0x6F6E3030@ha
/* 803136A4 003105E4  39 60 00 00 */	li r11, 0
/* 803136A8 003105E8  3A 83 86 40 */	addi r20, r3, EquipItemList__Q24Game5Equip@l
/* 803136AC 003105EC  39 80 00 A0 */	li r12, 0xa0
/* 803136B0 003105F0  3D 40 80 51 */	lis r10, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 803136B4 003105F4  3D 20 66 66 */	lis r9, 0x66666667@ha
/* 803136B8 003105F8  3D 00 6D 62 */	lis r8, 0x6D623030@ha
/* 803136BC 003105FC  3C E0 50 69 */	lis r7, 0x50697465@ha
/* 803136C0 00310600  98 01 00 39 */	stb r0, 0x39(r1)
/* 803136C4 00310604  3C 60 00 50 */	lis r3, 0x00506963@ha
/* 803136C8 00310608  3A A1 00 48 */	addi r21, r1, 0x48
/* 803136CC 0031060C  98 01 00 3A */	stb r0, 0x3a(r1)
/* 803136D0 00310610  38 06 30 30 */	addi r0, r6, 0x6D303030@l
/* 803136D4 00310614  3B 0A 3C 90 */	addi r24, r10, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 803136D8 00310618  3B 29 66 67 */	addi r25, r9, 0x66666667@l
/* 803136DC 0031061C  90 01 00 78 */	stw r0, 0x78(r1)
/* 803136E0 00310620  38 05 74 65 */	addi r0, r5, 0x54697465@l
/* 803136E4 00310624  3B 68 30 30 */	addi r27, r8, 0x6D623030@l
/* 803136E8 00310628  39 C7 74 65 */	addi r14, r7, 0x50697465@l
/* 803136EC 0031062C  90 01 00 7C */	stw r0, 0x7c(r1)
/* 803136F0 00310630  38 04 30 30 */	addi r0, r4, 0x6F6E3030@l
/* 803136F4 00310634  3A 20 00 00 */	li r17, 0
/* 803136F8 00310638  90 01 00 80 */	stw r0, 0x80(r1)
/* 803136FC 0031063C  38 03 69 63 */	addi r0, r3, 0x00506963@l
/* 80313700 00310640  99 81 00 3B */	stb r12, 0x3b(r1)
/* 80313704 00310644  90 01 00 84 */	stw r0, 0x84(r1)
/* 80313708 00310648  99 61 00 34 */	stb r11, 0x34(r1)
/* 8031370C 0031064C  99 61 00 35 */	stb r11, 0x35(r1)
/* 80313710 00310650  99 61 00 36 */	stb r11, 0x36(r1)
/* 80313714 00310654  99 61 00 37 */	stb r11, 0x37(r1)
.L_80313718:
/* 80313718 00310658  7C B9 88 96 */	mulhw r5, r25, r17
/* 8031371C 0031065C  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313720 00310660  7C A0 16 70 */	srawi r0, r5, 2
/* 80313724 00310664  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80313728 00310668  7C 00 22 14 */	add r0, r0, r4
/* 8031372C 0031066C  1C 00 00 0A */	mulli r0, r0, 0xa
/* 80313730 00310670  7F 40 88 50 */	subf r26, r0, r17
/* 80313734 00310674  7F 52 FE 70 */	srawi r18, r26, 0x1f
/* 80313738 00310678  7C DA D8 14 */	addc r6, r26, r27
/* 8031373C 0031067C  7C F2 71 14 */	adde r7, r18, r14
/* 80313740 00310680  7C A0 16 70 */	srawi r0, r5, 2
/* 80313744 00310684  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80313748 00310688  7C A0 22 14 */	add r5, r0, r4
/* 8031374C 0031068C  7C 19 28 96 */	mulhw r0, r25, r5
/* 80313750 00310690  7C 00 16 70 */	srawi r0, r0, 2
/* 80313754 00310694  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80313758 00310698  7C 00 22 14 */	add r0, r0, r4
/* 8031375C 0031069C  1C 00 00 0A */	mulli r0, r0, 0xa
/* 80313760 003106A0  7C 00 28 50 */	subf r0, r0, r5
/* 80313764 003106A4  54 1C 40 2E */	slwi r28, r0, 8
/* 80313768 003106A8  7F 93 FE 70 */	srawi r19, r28, 0x1f
/* 8031376C 003106AC  7C C6 E0 14 */	addc r6, r6, r28
/* 80313770 003106B0  7C A7 99 14 */	adde r5, r7, r19
/* 80313774 003106B4  4B FE F7 39 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 80313778 003106B8  80 01 00 78 */	lwz r0, 0x78(r1)
/* 8031377C 003106BC  7C 65 1B 78 */	mr r5, r3
/* 80313780 003106C0  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313784 003106C4  7C 9A 00 14 */	addc r4, r26, r0
/* 80313788 003106C8  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 8031378C 003106CC  7C 12 01 14 */	adde r0, r18, r0
/* 80313790 003106D0  7F A4 E0 14 */	addc r29, r4, r28
/* 80313794 003106D4  7C A4 2B 78 */	mr r4, r5
/* 80313798 003106D8  7F C0 99 14 */	adde r30, r0, r19
/* 8031379C 003106DC  7C 90 23 78 */	mr r16, r4
/* 803137A0 003106E0  7F A6 EB 78 */	mr r6, r29
/* 803137A4 003106E4  7F C5 F3 78 */	mr r5, r30
/* 803137A8 003106E8  4B FE F7 05 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803137AC 003106EC  80 96 00 00 */	lwz r4, 0(r22)
/* 803137B0 003106F0  7C 6F 1B 78 */	mr r15, r3
/* 803137B4 003106F4  80 B6 00 04 */	lwz r5, 4(r22)
/* 803137B8 003106F8  80 01 00 80 */	lwz r0, 0x80(r1)
/* 803137BC 003106FC  90 AF 00 1C */	stw r5, 0x1c(r15)
/* 803137C0 00310700  7C 7A 00 14 */	addc r3, r26, r0
/* 803137C4 00310704  80 01 00 84 */	lwz r0, 0x84(r1)
/* 803137C8 00310708  90 8F 00 18 */	stw r4, 0x18(r15)
/* 803137CC 0031070C  7C 12 01 14 */	adde r0, r18, r0
/* 803137D0 00310710  7C C3 E0 14 */	addc r6, r3, r28
/* 803137D4 00310714  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 803137D8 00310718  7C A0 99 14 */	adde r5, r0, r19
/* 803137DC 0031071C  4B FE F6 D1 */	bl TagSearch__Q22og6ScreenFP9J2DScreenUx
/* 803137E0 00310720  90 75 00 00 */	stw r3, 0(r21)
/* 803137E4 00310724  80 15 00 00 */	lwz r0, 0(r21)
/* 803137E8 00310728  28 00 00 00 */	cmplwi r0, 0
/* 803137EC 0031072C  41 82 01 20 */	beq .L_8031390C
/* 803137F0 00310730  3C 80 80 51 */	lis r4, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 803137F4 00310734  7E 03 83 78 */	mr r3, r16
/* 803137F8 00310738  38 A4 3C 90 */	addi r5, r4, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 803137FC 0031073C  38 81 00 30 */	addi r4, r1, 0x30
/* 80313800 00310740  80 05 00 00 */	lwz r0, 0(r5)
/* 80313804 00310744  82 54 00 00 */	lwz r18, 0(r20)
/* 80313808 00310748  90 01 00 30 */	stw r0, 0x30(r1)
/* 8031380C 0031074C  81 90 00 00 */	lwz r12, 0(r16)
/* 80313810 00310750  81 8C 01 2C */	lwz r12, 0x12c(r12)
/* 80313814 00310754  7D 89 03 A6 */	mtctr r12
/* 80313818 00310758  4E 80 04 21 */	bctrl 
/* 8031381C 0031075C  80 18 00 04 */	lwz r0, 4(r24)
/* 80313820 00310760  7E 03 83 78 */	mr r3, r16
/* 80313824 00310764  38 81 00 2C */	addi r4, r1, 0x2c
/* 80313828 00310768  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8031382C 0031076C  81 90 00 00 */	lwz r12, 0(r16)
/* 80313830 00310770  81 8C 01 28 */	lwz r12, 0x128(r12)
/* 80313834 00310774  7D 89 03 A6 */	mtctr r12
/* 80313838 00310778  4E 80 04 21 */	bctrl 
/* 8031383C 0031077C  80 7F 00 A8 */	lwz r3, 0xa8(r31)
/* 80313840 00310780  38 12 00 18 */	addi r0, r18, 0x18
/* 80313844 00310784  7C 03 00 AE */	lbzx r0, r3, r0
/* 80313848 00310788  28 00 00 00 */	cmplwi r0, 0
/* 8031384C 0031078C  41 82 00 20 */	beq .L_8031386C
/* 80313850 00310790  80 75 00 00 */	lwz r3, 0(r21)
/* 80313854 00310794  38 00 00 01 */	li r0, 1
/* 80313858 00310798  28 0F 00 00 */	cmplwi r15, 0
/* 8031385C 0031079C  98 03 00 B0 */	stb r0, 0xb0(r3)
/* 80313860 003107A0  41 82 00 C0 */	beq .L_80313920
/* 80313864 003107A4  98 0F 00 B0 */	stb r0, 0xb0(r15)
/* 80313868 003107A8  48 00 00 B8 */	b .L_80313920
.L_8031386C:
/* 8031386C 003107AC  80 75 00 00 */	lwz r3, 0(r21)
/* 80313870 003107B0  38 A0 00 01 */	li r5, 1
/* 80313874 003107B4  80 01 00 38 */	lwz r0, 0x38(r1)
/* 80313878 003107B8  38 81 00 28 */	addi r4, r1, 0x28
/* 8031387C 003107BC  98 A3 00 B0 */	stb r5, 0xb0(r3)
/* 80313880 003107C0  90 01 00 28 */	stw r0, 0x28(r1)
/* 80313884 003107C4  81 83 00 00 */	lwz r12, 0(r3)
/* 80313888 003107C8  81 8C 01 2C */	lwz r12, 0x12c(r12)
/* 8031388C 003107CC  7D 89 03 A6 */	mtctr r12
/* 80313890 003107D0  4E 80 04 21 */	bctrl 
/* 80313894 003107D4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80313898 003107D8  38 81 00 24 */	addi r4, r1, 0x24
/* 8031389C 003107DC  80 75 00 00 */	lwz r3, 0(r21)
/* 803138A0 003107E0  90 01 00 24 */	stw r0, 0x24(r1)
/* 803138A4 003107E4  81 83 00 00 */	lwz r12, 0(r3)
/* 803138A8 003107E8  81 8C 01 28 */	lwz r12, 0x128(r12)
/* 803138AC 003107EC  7D 89 03 A6 */	mtctr r12
/* 803138B0 003107F0  4E 80 04 21 */	bctrl 
/* 803138B4 003107F4  28 0F 00 00 */	cmplwi r15, 0
/* 803138B8 003107F8  41 82 00 40 */	beq .L_803138F8
/* 803138BC 003107FC  38 00 00 01 */	li r0, 1
/* 803138C0 00310800  3C 60 30 5F */	lis r3, 0x305F3030@ha
/* 803138C4 00310804  98 0F 00 B0 */	stb r0, 0xb0(r15)
/* 803138C8 00310808  38 03 30 30 */	addi r0, r3, 0x305F3030@l
/* 803138CC 0031080C  3C 80 00 36 */	lis r4, 0x00363133@ha
/* 803138D0 00310810  7D E3 7B 78 */	mr r3, r15
/* 803138D4 00310814  90 0F 00 1C */	stw r0, 0x1c(r15)
/* 803138D8 00310818  38 04 31 33 */	addi r0, r4, 0x00363133@l
/* 803138DC 0031081C  38 80 00 80 */	li r4, 0x80
/* 803138E0 00310820  90 0F 00 18 */	stw r0, 0x18(r15)
/* 803138E4 00310824  81 8F 00 00 */	lwz r12, 0(r15)
/* 803138E8 00310828  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 803138EC 0031082C  7D 89 03 A6 */	mtctr r12
/* 803138F0 00310830  4E 80 04 21 */	bctrl 
/* 803138F4 00310834  48 00 00 2C */	b .L_80313920
.L_803138F8:
/* 803138F8 00310838  7F A4 EB 78 */	mr r4, r29
/* 803138FC 0031083C  7F C3 F3 78 */	mr r3, r30
/* 80313900 00310840  38 A1 00 3C */	addi r5, r1, 0x3c
/* 80313904 00310844  4B FE F2 C9 */	bl TagToName__Q22og6ScreenFUxPc
/* 80313908 00310848  48 00 00 18 */	b .L_80313920
.L_8031390C:
/* 8031390C 0031084C  38 77 00 00 */	addi r3, r23, 0
/* 80313910 00310850  38 B7 00 E4 */	addi r5, r23, 0xe4
/* 80313914 00310854  38 80 01 82 */	li r4, 0x182
/* 80313918 00310858  4C C6 31 82 */	crclr 6
/* 8031391C 0031085C  4B D1 6D 25 */	bl panic_f__12JUTExceptionFPCciPCce
.L_80313920:
/* 80313920 00310860  3A 31 00 01 */	addi r17, r17, 1
/* 80313924 00310864  3A B5 00 04 */	addi r21, r21, 4
/* 80313928 00310868  2C 11 00 0C */	cmpwi r17, 0xc
/* 8031392C 0031086C  3A 94 00 04 */	addi r20, r20, 4
/* 80313930 00310870  3A D6 00 08 */	addi r22, r22, 8
/* 80313934 00310874  41 80 FD E4 */	blt .L_80313718
/* 80313938 00310878  80 BF 00 AC */	lwz r5, 0xac(r31)
/* 8031393C 0031087C  7F E3 FB 78 */	mr r3, r31
/* 80313940 00310880  80 81 00 20 */	lwz r4, 0x20(r1)
/* 80313944 00310884  48 00 2A 35 */	bl doCreateAfter__Q32og9newScreen12ObjSMenuBaseFP10JKRArchivePQ29P2DScreen3Mgr
/* 80313948 00310888  B9 C1 00 88 */	lmw r14, 0x88(r1)
/* 8031394C 0031088C  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 80313950 00310890  7C 08 03 A6 */	mtlr r0
/* 80313954 00310894  38 21 00 D0 */	addi r1, r1, 0xd0
/* 80313958 00310898  4E 80 00 20 */	blr 
.endfn doCreate__Q32og9newScreen12ObjSMenuItemFP10JKRArchive

.fn doUpdateLAction__Q32og9newScreen12ObjSMenuItemFv, global
/* 8031395C 0031089C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80313960 003108A0  7C 08 02 A6 */	mflr r0
/* 80313964 003108A4  3C 80 80 51 */	lis r4, msBaseVal__Q32og9newScreen12ObjSMenuBase@ha
/* 80313968 003108A8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8031396C 003108AC  38 84 3C F4 */	addi r4, r4, msBaseVal__Q32og9newScreen12ObjSMenuBase@l
/* 80313970 003108B0  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80313974 003108B4  7C 7F 1B 78 */	mr r31, r3
/* 80313978 003108B8  88 04 00 18 */	lbz r0, 0x18(r4)
/* 8031397C 003108BC  28 00 00 00 */	cmplwi r0, 0
/* 80313980 003108C0  41 82 00 4C */	beq .L_803139CC
/* 80313984 003108C4  48 14 06 25 */	bl getDispMember__Q26Screen7ObjBaseFv
/* 80313988 003108C8  3C A0 80 4E */	lis r5, __vt__Q26Screen12SceneArgBase@ha
/* 8031398C 003108CC  3C 80 80 4E */	lis r4, __vt__Q26Screen11SetSceneArg@ha
/* 80313990 003108D0  38 05 84 68 */	addi r0, r5, __vt__Q26Screen12SceneArgBase@l
/* 80313994 003108D4  38 C0 27 2B */	li r6, 0x272b
/* 80313998 003108D8  90 01 00 28 */	stw r0, 0x28(r1)
/* 8031399C 003108DC  38 E4 84 58 */	addi r7, r4, __vt__Q26Screen11SetSceneArg@l
/* 803139A0 003108E0  38 A0 00 00 */	li r5, 0
/* 803139A4 003108E4  38 00 00 01 */	li r0, 1
/* 803139A8 003108E8  90 61 00 34 */	stw r3, 0x34(r1)
/* 803139AC 003108EC  7F E3 FB 78 */	mr r3, r31
/* 803139B0 003108F0  38 81 00 28 */	addi r4, r1, 0x28
/* 803139B4 003108F4  90 E1 00 28 */	stw r7, 0x28(r1)
/* 803139B8 003108F8  90 C1 00 2C */	stw r6, 0x2c(r1)
/* 803139BC 003108FC  98 A1 00 30 */	stb r5, 0x30(r1)
/* 803139C0 00310900  98 01 00 31 */	stb r0, 0x31(r1)
/* 803139C4 00310904  48 00 2E 35 */	bl jump_L__Q32og9newScreen12ObjSMenuBaseFRQ26Screen11SetSceneArg
/* 803139C8 00310908  48 00 00 A8 */	b .L_80313A70
.L_803139CC:
/* 803139CC 0031090C  48 14 05 DD */	bl getDispMember__Q26Screen7ObjBaseFv
/* 803139D0 00310910  88 03 00 A5 */	lbz r0, 0xa5(r3)
/* 803139D4 00310914  28 00 00 00 */	cmplwi r0, 0
/* 803139D8 00310918  41 82 00 50 */	beq .L_80313A28
/* 803139DC 0031091C  7F E3 FB 78 */	mr r3, r31
/* 803139E0 00310920  48 14 05 C9 */	bl getDispMember__Q26Screen7ObjBaseFv
/* 803139E4 00310924  3C A0 80 4E */	lis r5, __vt__Q26Screen12SceneArgBase@ha
/* 803139E8 00310928  3C 80 80 4E */	lis r4, __vt__Q26Screen11SetSceneArg@ha
/* 803139EC 0031092C  38 05 84 68 */	addi r0, r5, __vt__Q26Screen12SceneArgBase@l
/* 803139F0 00310930  38 C0 27 1B */	li r6, 0x271b
/* 803139F4 00310934  90 01 00 18 */	stw r0, 0x18(r1)
/* 803139F8 00310938  38 E4 84 58 */	addi r7, r4, __vt__Q26Screen11SetSceneArg@l
/* 803139FC 0031093C  38 A0 00 00 */	li r5, 0
/* 80313A00 00310940  38 00 00 01 */	li r0, 1
/* 80313A04 00310944  90 61 00 24 */	stw r3, 0x24(r1)
/* 80313A08 00310948  7F E3 FB 78 */	mr r3, r31
/* 80313A0C 0031094C  38 81 00 18 */	addi r4, r1, 0x18
/* 80313A10 00310950  90 E1 00 18 */	stw r7, 0x18(r1)
/* 80313A14 00310954  90 C1 00 1C */	stw r6, 0x1c(r1)
/* 80313A18 00310958  98 A1 00 20 */	stb r5, 0x20(r1)
/* 80313A1C 0031095C  98 01 00 21 */	stb r0, 0x21(r1)
/* 80313A20 00310960  48 00 2D D9 */	bl jump_L__Q32og9newScreen12ObjSMenuBaseFRQ26Screen11SetSceneArg
/* 80313A24 00310964  48 00 00 4C */	b .L_80313A70
.L_80313A28:
/* 80313A28 00310968  7F E3 FB 78 */	mr r3, r31
/* 80313A2C 0031096C  48 14 05 7D */	bl getDispMember__Q26Screen7ObjBaseFv
/* 80313A30 00310970  3C A0 80 4E */	lis r5, __vt__Q26Screen12SceneArgBase@ha
/* 80313A34 00310974  3C 80 80 4E */	lis r4, __vt__Q26Screen11SetSceneArg@ha
/* 80313A38 00310978  38 05 84 68 */	addi r0, r5, __vt__Q26Screen12SceneArgBase@l
/* 80313A3C 0031097C  38 C0 27 1A */	li r6, 0x271a
/* 80313A40 00310980  90 01 00 08 */	stw r0, 8(r1)
/* 80313A44 00310984  38 E4 84 58 */	addi r7, r4, __vt__Q26Screen11SetSceneArg@l
/* 80313A48 00310988  38 A0 00 00 */	li r5, 0
/* 80313A4C 0031098C  38 00 00 01 */	li r0, 1
/* 80313A50 00310990  90 61 00 14 */	stw r3, 0x14(r1)
/* 80313A54 00310994  7F E3 FB 78 */	mr r3, r31
/* 80313A58 00310998  38 81 00 08 */	addi r4, r1, 8
/* 80313A5C 0031099C  90 E1 00 08 */	stw r7, 8(r1)
/* 80313A60 003109A0  90 C1 00 0C */	stw r6, 0xc(r1)
/* 80313A64 003109A4  98 A1 00 10 */	stb r5, 0x10(r1)
/* 80313A68 003109A8  98 01 00 11 */	stb r0, 0x11(r1)
/* 80313A6C 003109AC  48 00 2D 8D */	bl jump_L__Q32og9newScreen12ObjSMenuBaseFRQ26Screen11SetSceneArg
.L_80313A70:
/* 80313A70 003109B0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80313A74 003109B4  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 80313A78 003109B8  7C 08 03 A6 */	mtlr r0
/* 80313A7C 003109BC  38 21 00 40 */	addi r1, r1, 0x40
/* 80313A80 003109C0  4E 80 00 20 */	blr 
.endfn doUpdateLAction__Q32og9newScreen12ObjSMenuItemFv

.fn doUpdateRAction__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313A84 003109C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80313A88 003109C8  7C 08 02 A6 */	mflr r0
/* 80313A8C 003109CC  90 01 00 24 */	stw r0, 0x24(r1)
/* 80313A90 003109D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80313A94 003109D4  7C 7F 1B 78 */	mr r31, r3
/* 80313A98 003109D8  48 14 05 11 */	bl getDispMember__Q26Screen7ObjBaseFv
/* 80313A9C 003109DC  3C A0 80 4E */	lis r5, __vt__Q26Screen12SceneArgBase@ha
/* 80313AA0 003109E0  3C 80 80 4E */	lis r4, __vt__Q26Screen11SetSceneArg@ha
/* 80313AA4 003109E4  38 05 84 68 */	addi r0, r5, __vt__Q26Screen12SceneArgBase@l
/* 80313AA8 003109E8  38 C0 27 1D */	li r6, 0x271d
/* 80313AAC 003109EC  90 01 00 08 */	stw r0, 8(r1)
/* 80313AB0 003109F0  38 E4 84 58 */	addi r7, r4, __vt__Q26Screen11SetSceneArg@l
/* 80313AB4 003109F4  38 A0 00 00 */	li r5, 0
/* 80313AB8 003109F8  38 00 00 01 */	li r0, 1
/* 80313ABC 003109FC  90 61 00 14 */	stw r3, 0x14(r1)
/* 80313AC0 00310A00  7F E3 FB 78 */	mr r3, r31
/* 80313AC4 00310A04  38 81 00 08 */	addi r4, r1, 8
/* 80313AC8 00310A08  90 E1 00 08 */	stw r7, 8(r1)
/* 80313ACC 00310A0C  90 C1 00 0C */	stw r6, 0xc(r1)
/* 80313AD0 00310A10  98 A1 00 10 */	stb r5, 0x10(r1)
/* 80313AD4 00310A14  98 01 00 11 */	stb r0, 0x11(r1)
/* 80313AD8 00310A18  48 00 2E 05 */	bl jump_R__Q32og9newScreen12ObjSMenuBaseFRQ26Screen11SetSceneArg
/* 80313ADC 00310A1C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80313AE0 00310A20  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80313AE4 00310A24  7C 08 03 A6 */	mtlr r0
/* 80313AE8 00310A28  38 21 00 20 */	addi r1, r1, 0x20
/* 80313AEC 00310A2C  4E 80 00 20 */	blr 
.endfn doUpdateRAction__Q32og9newScreen12ObjSMenuItemFv

.fn commonUpdate__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313AF0 00310A30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313AF4 00310A34  7C 08 02 A6 */	mflr r0
/* 80313AF8 00310A38  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313AFC 00310A3C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80313B00 00310A40  7C 7F 1B 78 */	mr r31, r3
/* 80313B04 00310A44  48 00 2A 39 */	bl commonUpdateBase__Q32og9newScreen12ObjSMenuBaseFv
/* 80313B08 00310A48  3C 80 80 51 */	lis r4, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 80313B0C 00310A4C  7F E3 FB 78 */	mr r3, r31
/* 80313B10 00310A50  38 84 3C 90 */	addi r4, r4, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 80313B14 00310A54  C0 24 00 18 */	lfs f1, 0x18(r4)
/* 80313B18 00310A58  C0 44 00 1C */	lfs f2, 0x1c(r4)
/* 80313B1C 00310A5C  48 00 28 1D */	bl setSMenuScale__Q32og9newScreen12ObjSMenuBaseFff
/* 80313B20 00310A60  80 7F 00 BC */	lwz r3, 0xbc(r31)
/* 80313B24 00310A64  3C 80 80 51 */	lis r4, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 80313B28 00310A68  38 84 3C 90 */	addi r4, r4, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 80313B2C 00310A6C  81 83 00 00 */	lwz r12, 0(r3)
/* 80313B30 00310A70  C0 24 00 08 */	lfs f1, 8(r4)
/* 80313B34 00310A74  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80313B38 00310A78  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 80313B3C 00310A7C  7D 89 03 A6 */	mtctr r12
/* 80313B40 00310A80  4E 80 04 21 */	bctrl 
/* 80313B44 00310A84  80 7F 00 C0 */	lwz r3, 0xc0(r31)
/* 80313B48 00310A88  3C 80 80 51 */	lis r4, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 80313B4C 00310A8C  38 84 3C 90 */	addi r4, r4, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 80313B50 00310A90  81 83 00 00 */	lwz r12, 0(r3)
/* 80313B54 00310A94  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 80313B58 00310A98  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80313B5C 00310A9C  C0 44 00 14 */	lfs f2, 0x14(r4)
/* 80313B60 00310AA0  7D 89 03 A6 */	mtctr r12
/* 80313B64 00310AA4  4E 80 04 21 */	bctrl 
/* 80313B68 00310AA8  80 7F 00 B4 */	lwz r3, 0xb4(r31)
/* 80313B6C 00310AAC  4B FF 19 7D */	bl update__Q32og6Screen9AnimGroupFv
/* 80313B70 00310AB0  80 7F 00 B8 */	lwz r3, 0xb8(r31)
/* 80313B74 00310AB4  4B FF 19 75 */	bl update__Q32og6Screen9AnimGroupFv
/* 80313B78 00310AB8  C0 7F 00 40 */	lfs f3, 0x40(r31)
/* 80313B7C 00310ABC  C0 42 24 3C */	lfs f2, mstTuningTransX__Q29P2DScreen10Mgr_tuning@sda21(r2)
/* 80313B80 00310AC0  C0 22 F4 D4 */	lfs f1, lbl_8051D834@sda21(r2)
/* 80313B84 00310AC4  C0 02 24 40 */	lfs f0, mstTuningTransY__Q29P2DScreen10Mgr_tuning@sda21(r2)
/* 80313B88 00310AC8  EC 43 10 2A */	fadds f2, f3, f2
/* 80313B8C 00310ACC  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313B90 00310AD0  EC 01 00 2A */	fadds f0, f1, f0
/* 80313B94 00310AD4  D0 43 01 40 */	stfs f2, 0x140(r3)
/* 80313B98 00310AD8  D0 03 01 44 */	stfs f0, 0x144(r3)
/* 80313B9C 00310ADC  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313BA0 00310AE0  81 83 00 00 */	lwz r12, 0(r3)
/* 80313BA4 00310AE4  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80313BA8 00310AE8  7D 89 03 A6 */	mtctr r12
/* 80313BAC 00310AEC  4E 80 04 21 */	bctrl 
/* 80313BB0 00310AF0  80 7F 00 B0 */	lwz r3, 0xb0(r31)
/* 80313BB4 00310AF4  81 83 00 00 */	lwz r12, 0(r3)
/* 80313BB8 00310AF8  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80313BBC 00310AFC  7D 89 03 A6 */	mtctr r12
/* 80313BC0 00310B00  4E 80 04 21 */	bctrl 
/* 80313BC4 00310B04  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313BC8 00310B08  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80313BCC 00310B0C  7C 08 03 A6 */	mtlr r0
/* 80313BD0 00310B10  38 21 00 10 */	addi r1, r1, 0x10
/* 80313BD4 00310B14  4E 80 00 20 */	blr 
.endfn commonUpdate__Q32og9newScreen12ObjSMenuItemFv

.fn doUpdate__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313BD8 00310B18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313BDC 00310B1C  7C 08 02 A6 */	mflr r0
/* 80313BE0 00310B20  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313BE4 00310B24  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80313BE8 00310B28  7C 7F 1B 78 */	mr r31, r3
/* 80313BEC 00310B2C  81 83 00 00 */	lwz r12, 0(r3)
/* 80313BF0 00310B30  81 8C 00 A4 */	lwz r12, 0xa4(r12)
/* 80313BF4 00310B34  7D 89 03 A6 */	mtctr r12
/* 80313BF8 00310B38  4E 80 04 21 */	bctrl 
/* 80313BFC 00310B3C  7F E3 FB 78 */	mr r3, r31
/* 80313C00 00310B40  48 00 29 5D */	bl doUpdate__Q32og9newScreen12ObjSMenuBaseFv
/* 80313C04 00310B44  7C 60 1B 78 */	mr r0, r3
/* 80313C08 00310B48  80 7F 00 AC */	lwz r3, 0xac(r31)
/* 80313C0C 00310B4C  7C 1F 03 78 */	mr r31, r0
/* 80313C10 00310B50  4B D2 CF 1D */	bl animation__9J2DScreenFv
/* 80313C14 00310B54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313C18 00310B58  7F E3 FB 78 */	mr r3, r31
/* 80313C1C 00310B5C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80313C20 00310B60  7C 08 03 A6 */	mtlr r0
/* 80313C24 00310B64  38 21 00 10 */	addi r1, r1, 0x10
/* 80313C28 00310B68  4E 80 00 20 */	blr 
.endfn doUpdate__Q32og9newScreen12ObjSMenuItemFv

.fn doDraw__Q32og9newScreen12ObjSMenuItemFR8Graphics, global
/* 80313C2C 00310B6C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80313C30 00310B70  7C 08 02 A6 */	mflr r0
/* 80313C34 00310B74  90 01 00 24 */	stw r0, 0x24(r1)
/* 80313C38 00310B78  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80313C3C 00310B7C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80313C40 00310B80  7C 9E 23 78 */	mr r30, r4
/* 80313C44 00310B84  3B FE 01 90 */	addi r31, r30, 0x190
/* 80313C48 00310B88  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80313C4C 00310B8C  7C 7D 1B 78 */	mr r29, r3
/* 80313C50 00310B90  7F E3 FB 78 */	mr r3, r31
/* 80313C54 00310B94  81 9F 00 00 */	lwz r12, 0(r31)
/* 80313C58 00310B98  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80313C5C 00310B9C  7D 89 03 A6 */	mtctr r12
/* 80313C60 00310BA0  4E 80 04 21 */	bctrl 
/* 80313C64 00310BA4  80 7D 00 AC */	lwz r3, 0xac(r29)
/* 80313C68 00310BA8  28 03 00 00 */	cmplwi r3, 0
/* 80313C6C 00310BAC  41 82 00 1C */	beq .L_80313C88
/* 80313C70 00310BB0  81 83 00 00 */	lwz r12, 0(r3)
/* 80313C74 00310BB4  7F C4 F3 78 */	mr r4, r30
/* 80313C78 00310BB8  7F E5 FB 78 */	mr r5, r31
/* 80313C7C 00310BBC  81 8C 00 9C */	lwz r12, 0x9c(r12)
/* 80313C80 00310BC0  7D 89 03 A6 */	mtctr r12
/* 80313C84 00310BC4  4E 80 04 21 */	bctrl 
.L_80313C88:
/* 80313C88 00310BC8  80 1D 00 B0 */	lwz r0, 0xb0(r29)
/* 80313C8C 00310BCC  28 00 00 00 */	cmplwi r0, 0
/* 80313C90 00310BD0  41 82 00 48 */	beq .L_80313CD8
/* 80313C94 00310BD4  80 7D 00 BC */	lwz r3, 0xbc(r29)
/* 80313C98 00310BD8  80 9D 00 C4 */	lwz r4, 0xc4(r29)
/* 80313C9C 00310BDC  38 63 00 80 */	addi r3, r3, 0x80
/* 80313CA0 00310BE0  38 84 00 50 */	addi r4, r4, 0x50
/* 80313CA4 00310BE4  4B DD 66 29 */	bl PSMTXCopy
/* 80313CA8 00310BE8  80 7D 00 C0 */	lwz r3, 0xc0(r29)
/* 80313CAC 00310BEC  80 9D 00 C8 */	lwz r4, 0xc8(r29)
/* 80313CB0 00310BF0  38 63 00 80 */	addi r3, r3, 0x80
/* 80313CB4 00310BF4  38 84 00 50 */	addi r4, r4, 0x50
/* 80313CB8 00310BF8  4B DD 66 15 */	bl PSMTXCopy
/* 80313CBC 00310BFC  80 7D 00 B0 */	lwz r3, 0xb0(r29)
/* 80313CC0 00310C00  7F C4 F3 78 */	mr r4, r30
/* 80313CC4 00310C04  7F E5 FB 78 */	mr r5, r31
/* 80313CC8 00310C08  81 83 00 00 */	lwz r12, 0(r3)
/* 80313CCC 00310C0C  81 8C 00 9C */	lwz r12, 0x9c(r12)
/* 80313CD0 00310C10  7D 89 03 A6 */	mtctr r12
/* 80313CD4 00310C14  4E 80 04 21 */	bctrl 
.L_80313CD8:
/* 80313CD8 00310C18  7F A3 EB 78 */	mr r3, r29
/* 80313CDC 00310C1C  7F C4 F3 78 */	mr r4, r30
/* 80313CE0 00310C20  48 00 31 AD */	bl drawYaji__Q32og9newScreen12ObjSMenuBaseFR8Graphics
/* 80313CE4 00310C24  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80313CE8 00310C28  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80313CEC 00310C2C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80313CF0 00310C30  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80313CF4 00310C34  7C 08 03 A6 */	mtlr r0
/* 80313CF8 00310C38  38 21 00 20 */	addi r1, r1, 0x20
/* 80313CFC 00310C3C  4E 80 00 20 */	blr 
.endfn doDraw__Q32og9newScreen12ObjSMenuItemFR8Graphics

.fn in_L__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313D00 00310C40  38 00 00 00 */	li r0, 0
/* 80313D04 00310C44  C0 02 F4 E4 */	lfs f0, lbl_8051D844@sda21(r2)
/* 80313D08 00310C48  90 03 00 38 */	stw r0, 0x38(r3)
/* 80313D0C 00310C4C  D0 03 00 4C */	stfs f0, 0x4c(r3)
/* 80313D10 00310C50  4E 80 00 20 */	blr 
.endfn in_L__Q32og9newScreen12ObjSMenuItemFv

.fn in_R__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313D14 00310C54  38 00 00 01 */	li r0, 1
/* 80313D18 00310C58  C0 02 F4 E4 */	lfs f0, lbl_8051D844@sda21(r2)
/* 80313D1C 00310C5C  90 03 00 38 */	stw r0, 0x38(r3)
/* 80313D20 00310C60  D0 03 00 4C */	stfs f0, 0x4c(r3)
/* 80313D24 00310C64  4E 80 00 20 */	blr 
.endfn in_R__Q32og9newScreen12ObjSMenuItemFv

.fn wait__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313D28 00310C68  38 00 00 04 */	li r0, 4
/* 80313D2C 00310C6C  90 03 00 38 */	stw r0, 0x38(r3)
/* 80313D30 00310C70  4E 80 00 20 */	blr 
.endfn wait__Q32og9newScreen12ObjSMenuItemFv

.fn out_L__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313D34 00310C74  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313D38 00310C78  7C 08 02 A6 */	mflr r0
/* 80313D3C 00310C7C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313D40 00310C80  38 00 00 02 */	li r0, 2
/* 80313D44 00310C84  90 03 00 38 */	stw r0, 0x38(r3)
/* 80313D48 00310C88  80 6D 97 A8 */	lwz r3, ogSound__2og@sda21(r13)
/* 80313D4C 00310C8C  4B FF 8E FD */	bl setSMenuLR__Q22og5SoundFv
/* 80313D50 00310C90  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313D54 00310C94  7C 08 03 A6 */	mtlr r0
/* 80313D58 00310C98  38 21 00 10 */	addi r1, r1, 0x10
/* 80313D5C 00310C9C  4E 80 00 20 */	blr 
.endfn out_L__Q32og9newScreen12ObjSMenuItemFv

.fn out_R__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313D60 00310CA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313D64 00310CA4  7C 08 02 A6 */	mflr r0
/* 80313D68 00310CA8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313D6C 00310CAC  38 00 00 03 */	li r0, 3
/* 80313D70 00310CB0  90 03 00 38 */	stw r0, 0x38(r3)
/* 80313D74 00310CB4  80 6D 97 A8 */	lwz r3, ogSound__2og@sda21(r13)
/* 80313D78 00310CB8  4B FF 8E D1 */	bl setSMenuLR__Q22og5SoundFv
/* 80313D7C 00310CBC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313D80 00310CC0  7C 08 03 A6 */	mtlr r0
/* 80313D84 00310CC4  38 21 00 10 */	addi r1, r1, 0x10
/* 80313D88 00310CC8  4E 80 00 20 */	blr 
.endfn out_R__Q32og9newScreen12ObjSMenuItemFv

.fn doStart__Q32og9newScreen12ObjSMenuItemFPCQ26Screen13StartSceneArg, global
/* 80313D8C 00310CCC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313D90 00310CD0  7C 08 02 A6 */	mflr r0
/* 80313D94 00310CD4  C0 22 F4 D4 */	lfs f1, lbl_8051D834@sda21(r2)
/* 80313D98 00310CD8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313D9C 00310CDC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80313DA0 00310CE0  7C 9F 23 78 */	mr r31, r4
/* 80313DA4 00310CE4  93 C1 00 08 */	stw r30, 8(r1)
/* 80313DA8 00310CE8  7C 7E 1B 78 */	mr r30, r3
/* 80313DAC 00310CEC  80 63 00 B4 */	lwz r3, 0xb4(r3)
/* 80313DB0 00310CF0  4B FF 19 B1 */	bl setFrame__Q32og6Screen9AnimGroupFf
/* 80313DB4 00310CF4  80 7E 00 B4 */	lwz r3, 0xb4(r30)
/* 80313DB8 00310CF8  38 80 00 01 */	li r4, 1
/* 80313DBC 00310CFC  4B FF 19 49 */	bl setRepeat__Q32og6Screen9AnimGroupFb
/* 80313DC0 00310D00  80 7E 00 B4 */	lwz r3, 0xb4(r30)
/* 80313DC4 00310D04  C0 22 F4 E0 */	lfs f1, lbl_8051D840@sda21(r2)
/* 80313DC8 00310D08  4B FF 18 E1 */	bl setSpeed__Q32og6Screen9AnimGroupFf
/* 80313DCC 00310D0C  80 7E 00 B4 */	lwz r3, 0xb4(r30)
/* 80313DD0 00310D10  4B FF 1A E9 */	bl start__Q32og6Screen9AnimGroupFv
/* 80313DD4 00310D14  80 7E 00 B8 */	lwz r3, 0xb8(r30)
/* 80313DD8 00310D18  C0 22 F4 D4 */	lfs f1, lbl_8051D834@sda21(r2)
/* 80313DDC 00310D1C  4B FF 19 85 */	bl setFrame__Q32og6Screen9AnimGroupFf
/* 80313DE0 00310D20  80 7E 00 B8 */	lwz r3, 0xb8(r30)
/* 80313DE4 00310D24  38 80 00 01 */	li r4, 1
/* 80313DE8 00310D28  4B FF 19 1D */	bl setRepeat__Q32og6Screen9AnimGroupFb
/* 80313DEC 00310D2C  80 7E 00 B8 */	lwz r3, 0xb8(r30)
/* 80313DF0 00310D30  C0 22 F4 E0 */	lfs f1, lbl_8051D840@sda21(r2)
/* 80313DF4 00310D34  4B FF 18 B5 */	bl setSpeed__Q32og6Screen9AnimGroupFf
/* 80313DF8 00310D38  80 7E 00 B8 */	lwz r3, 0xb8(r30)
/* 80313DFC 00310D3C  4B FF 1A BD */	bl start__Q32og6Screen9AnimGroupFv
/* 80313E00 00310D40  3C 60 00 36 */	lis r3, 0x00363035@ha
/* 80313E04 00310D44  3C C0 32 5F */	lis r6, 0x325F3030@ha
/* 80313E08 00310D48  38 A3 30 35 */	addi r5, r3, 0x00363035@l
/* 80313E0C 00310D4C  3D 00 30 5F */	lis r8, 0x305F3030@ha
/* 80313E10 00310D50  3C 80 31 5F */	lis r4, 0x315F3030@ha
/* 80313E14 00310D54  7F C3 F3 78 */	mr r3, r30
/* 80313E18 00310D58  7C A7 2B 78 */	mr r7, r5
/* 80313E1C 00310D5C  7C A9 2B 78 */	mr r9, r5
/* 80313E20 00310D60  38 C6 30 30 */	addi r6, r6, 0x325F3030@l
/* 80313E24 00310D64  39 08 30 30 */	addi r8, r8, 0x305F3030@l
/* 80313E28 00310D68  39 44 30 30 */	addi r10, r4, 0x315F3030@l
/* 80313E2C 00310D6C  48 00 2C E5 */	bl setYajiName__Q32og9newScreen12ObjSMenuBaseFUxUxUx
/* 80313E30 00310D70  7F C3 F3 78 */	mr r3, r30
/* 80313E34 00310D74  48 00 2D 49 */	bl stopYaji__Q32og9newScreen12ObjSMenuBaseFv
/* 80313E38 00310D78  7F C3 F3 78 */	mr r3, r30
/* 80313E3C 00310D7C  7F E4 FB 78 */	mr r4, r31
/* 80313E40 00310D80  48 00 2B 81 */	bl start_LR__Q32og9newScreen12ObjSMenuBaseFPCQ26Screen13StartSceneArg
/* 80313E44 00310D84  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313E48 00310D88  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80313E4C 00310D8C  83 C1 00 08 */	lwz r30, 8(r1)
/* 80313E50 00310D90  7C 08 03 A6 */	mtlr r0
/* 80313E54 00310D94  38 21 00 10 */	addi r1, r1, 0x10
/* 80313E58 00310D98  4E 80 00 20 */	blr 
.endfn doStart__Q32og9newScreen12ObjSMenuItemFPCQ26Screen13StartSceneArg

.fn doEnd__Q32og9newScreen12ObjSMenuItemFPCQ26Screen11EndSceneArg, global
/* 80313E5C 00310D9C  38 60 00 01 */	li r3, 1
/* 80313E60 00310DA0  4E 80 00 20 */	blr 
.endfn doEnd__Q32og9newScreen12ObjSMenuItemFPCQ26Screen11EndSceneArg

.fn doUpdateFinish__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313E64 00310DA4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313E68 00310DA8  7C 08 02 A6 */	mflr r0
/* 80313E6C 00310DAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313E70 00310DB0  48 00 28 19 */	bl doUpdateFinish__Q32og9newScreen12ObjSMenuBaseFv
/* 80313E74 00310DB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313E78 00310DB8  7C 08 03 A6 */	mtlr r0
/* 80313E7C 00310DBC  38 21 00 10 */	addi r1, r1, 0x10
/* 80313E80 00310DC0  4E 80 00 20 */	blr 
.endfn doUpdateFinish__Q32og9newScreen12ObjSMenuItemFv

.fn doUpdateFadeout__Q32og9newScreen12ObjSMenuItemFv, global
/* 80313E84 00310DC4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80313E88 00310DC8  7C 08 02 A6 */	mflr r0
/* 80313E8C 00310DCC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80313E90 00310DD0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80313E94 00310DD4  7C 7F 1B 78 */	mr r31, r3
/* 80313E98 00310DD8  81 83 00 00 */	lwz r12, 0(r3)
/* 80313E9C 00310DDC  81 8C 00 A4 */	lwz r12, 0xa4(r12)
/* 80313EA0 00310DE0  7D 89 03 A6 */	mtctr r12
/* 80313EA4 00310DE4  4E 80 04 21 */	bctrl 
/* 80313EA8 00310DE8  7F E3 FB 78 */	mr r3, r31
/* 80313EAC 00310DEC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80313EB0 00310DF0  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 80313EB4 00310DF4  7D 89 03 A6 */	mtctr r12
/* 80313EB8 00310DF8  4E 80 04 21 */	bctrl 
/* 80313EBC 00310DFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80313EC0 00310E00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80313EC4 00310E04  7C 08 03 A6 */	mtlr r0
/* 80313EC8 00310E08  38 21 00 10 */	addi r1, r1, 0x10
/* 80313ECC 00310E0C  4E 80 00 20 */	blr 
.endfn doUpdateFadeout__Q32og9newScreen12ObjSMenuItemFv

.fn doUpdateCancelAction__Q32og9newScreen12ObjSMenuItemFv, weak
/* 80313ED0 00310E10  4E 80 00 20 */	blr 
.endfn doUpdateCancelAction__Q32og9newScreen12ObjSMenuItemFv

.fn __sinit_ogObjSMenuItem_cpp, local
/* 80313ED4 00310E14  3C 60 80 51 */	lis r3, msVal__Q32og9newScreen12ObjSMenuItem@ha
/* 80313ED8 00310E18  38 80 FF FF */	li r4, -1
/* 80313EDC 00310E1C  38 E3 3C 90 */	addi r7, r3, msVal__Q32og9newScreen12ObjSMenuItem@l
/* 80313EE0 00310E20  C0 42 F4 E8 */	lfs f2, lbl_8051D848@sda21(r2)
/* 80313EE4 00310E24  C0 22 F4 EC */	lfs f1, lbl_8051D84C@sda21(r2)
/* 80313EE8 00310E28  38 C0 00 00 */	li r6, 0
/* 80313EEC 00310E2C  90 87 00 04 */	stw r4, 4(r7)
/* 80313EF0 00310E30  38 60 00 FF */	li r3, 0xff
/* 80313EF4 00310E34  C0 02 F4 F0 */	lfs f0, lbl_8051D850@sda21(r2)
/* 80313EF8 00310E38  38 00 00 64 */	li r0, 0x64
/* 80313EFC 00310E3C  90 87 00 00 */	stw r4, 0(r7)
/* 80313F00 00310E40  38 A0 00 6E */	li r5, 0x6e
/* 80313F04 00310E44  38 80 00 B0 */	li r4, 0xb0
/* 80313F08 00310E48  98 C7 00 00 */	stb r6, 0(r7)
/* 80313F0C 00310E4C  98 A7 00 01 */	stb r5, 1(r7)
/* 80313F10 00310E50  98 87 00 02 */	stb r4, 2(r7)
/* 80313F14 00310E54  98 67 00 03 */	stb r3, 3(r7)
/* 80313F18 00310E58  98 C7 00 04 */	stb r6, 4(r7)
/* 80313F1C 00310E5C  98 C7 00 05 */	stb r6, 5(r7)
/* 80313F20 00310E60  98 07 00 06 */	stb r0, 6(r7)
/* 80313F24 00310E64  98 67 00 07 */	stb r3, 7(r7)
/* 80313F28 00310E68  D0 47 00 08 */	stfs f2, 8(r7)
/* 80313F2C 00310E6C  D0 47 00 0C */	stfs f2, 0xc(r7)
/* 80313F30 00310E70  D0 47 00 10 */	stfs f2, 0x10(r7)
/* 80313F34 00310E74  D0 47 00 14 */	stfs f2, 0x14(r7)
/* 80313F38 00310E78  D0 27 00 18 */	stfs f1, 0x18(r7)
/* 80313F3C 00310E7C  D0 07 00 1C */	stfs f0, 0x1c(r7)
/* 80313F40 00310E80  4E 80 00 20 */	blr 
.endfn __sinit_ogObjSMenuItem_cpp

.fn "@24@__dt__Q32og9newScreen12ObjSMenuItemFv", weak
/* 80313F44 00310E84  38 63 FF E8 */	addi r3, r3, -24
/* 80313F48 00310E88  4B FF F0 2C */	b __dt__Q32og9newScreen12ObjSMenuItemFv
.endfn "@24@__dt__Q32og9newScreen12ObjSMenuItemFv"
