.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_JASCmdStack_cpp

.section .bss  # 0x804EFC20 - 0x8051467C
.lcomm lbl_804F06E8, 0xC, 4
.lcomm lbl_804F06F4, 0xC, 4
# JASCmdStack.cpp
.comm sCommandListOnce__10JASPortCmd, 0x18, 4
.comm sCommandListStay__10JASPortCmd, 0xC, 4

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn addPortCmdOnce__10JASPortCmdFv, global
/* 800A6724 000A3664  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800A6728 000A3668  7C 08 02 A6 */	mflr r0
/* 800A672C 000A366C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800A6730 000A3670  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800A6734 000A3674  93 C1 00 08 */	stw r30, 8(r1)
/* 800A6738 000A3678  7C 7E 1B 78 */	mr r30, r3
/* 800A673C 000A367C  48 04 84 FD */	bl OSDisableInterrupts
/* 800A6740 000A3680  3C 80 80 51 */	lis r4, sCommandListOnce__10JASPortCmd@ha
/* 800A6744 000A3684  38 04 21 8C */	addi r0, r4, sCommandListOnce__10JASPortCmd@l
/* 800A6748 000A3688  7F C4 F3 78 */	mr r4, r30
/* 800A674C 000A368C  7C 7E 1B 78 */	mr r30, r3
/* 800A6750 000A3690  7C 03 03 78 */	mr r3, r0
/* 800A6754 000A3694  4B F8 01 91 */	bl append__10JSUPtrListFP10JSUPtrLink
/* 800A6758 000A3698  7C 7F 1B 78 */	mr r31, r3
/* 800A675C 000A369C  7F C3 F3 78 */	mr r3, r30
/* 800A6760 000A36A0  48 04 85 01 */	bl OSRestoreInterrupts
/* 800A6764 000A36A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800A6768 000A36A8  7F E3 FB 78 */	mr r3, r31
/* 800A676C 000A36AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800A6770 000A36B0  83 C1 00 08 */	lwz r30, 8(r1)
/* 800A6774 000A36B4  7C 08 03 A6 */	mtlr r0
/* 800A6778 000A36B8  38 21 00 10 */	addi r1, r1, 0x10
/* 800A677C 000A36BC  4E 80 00 20 */	blr 
.endfn addPortCmdOnce__10JASPortCmdFv

.fn setPortCmd__10JASPortCmdFPFP11JASPortArgs_vP11JASPortArgs, global
/* 800A6780 000A36C0  80 03 00 04 */	lwz r0, 4(r3)
/* 800A6784 000A36C4  28 00 00 00 */	cmplwi r0, 0
/* 800A6788 000A36C8  41 82 00 0C */	beq .L_800A6794
/* 800A678C 000A36CC  38 60 00 00 */	li r3, 0
/* 800A6790 000A36D0  4E 80 00 20 */	blr 
.L_800A6794:
/* 800A6794 000A36D4  90 83 00 10 */	stw r4, 0x10(r3)
/* 800A6798 000A36D8  90 A3 00 14 */	stw r5, 0x14(r3)
/* 800A679C 000A36DC  38 60 00 01 */	li r3, 1
/* 800A67A0 000A36E0  4E 80 00 20 */	blr 
.endfn setPortCmd__10JASPortCmdFPFP11JASPortArgs_vP11JASPortArgs

.fn execAllCommand__10JASPortCmdFv, global
/* 800A67A4 000A36E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800A67A8 000A36E8  7C 08 02 A6 */	mflr r0
/* 800A67AC 000A36EC  3C 60 80 51 */	lis r3, sCommandListOnce__10JASPortCmd@ha
/* 800A67B0 000A36F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800A67B4 000A36F4  38 63 21 8C */	addi r3, r3, sCommandListOnce__10JASPortCmd@l
/* 800A67B8 000A36F8  48 00 00 21 */	bl execCommandOnce__Q210JASPortCmd9TPortHeadFv
/* 800A67BC 000A36FC  3C 60 80 51 */	lis r3, sCommandListStay__10JASPortCmd@ha
/* 800A67C0 000A3700  38 63 21 A4 */	addi r3, r3, sCommandListStay__10JASPortCmd@l
/* 800A67C4 000A3704  48 00 00 9D */	bl execCommandStay__Q210JASPortCmd9TPortHeadFv
/* 800A67C8 000A3708  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800A67CC 000A370C  7C 08 03 A6 */	mtlr r0
/* 800A67D0 000A3710  38 21 00 10 */	addi r1, r1, 0x10
/* 800A67D4 000A3714  4E 80 00 20 */	blr 
.endfn execAllCommand__10JASPortCmdFv

.fn execCommandOnce__Q210JASPortCmd9TPortHeadFv, global
/* 800A67D8 000A3718  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800A67DC 000A371C  7C 08 02 A6 */	mflr r0
/* 800A67E0 000A3720  90 01 00 24 */	stw r0, 0x24(r1)
/* 800A67E4 000A3724  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800A67E8 000A3728  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800A67EC 000A372C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800A67F0 000A3730  93 81 00 10 */	stw r28, 0x10(r1)
/* 800A67F4 000A3734  7C 7C 1B 78 */	mr r28, r3
/* 800A67F8 000A3738  48 04 84 41 */	bl OSDisableInterrupts
/* 800A67FC 000A373C  83 BC 00 00 */	lwz r29, 0(r28)
/* 800A6800 000A3740  7C 7E 1B 78 */	mr r30, r3
/* 800A6804 000A3744  48 00 00 2C */	b .L_800A6830
.L_800A6808:
/* 800A6808 000A3748  80 7D 00 00 */	lwz r3, 0(r29)
/* 800A680C 000A374C  83 FD 00 0C */	lwz r31, 0xc(r29)
/* 800A6810 000A3750  81 83 00 10 */	lwz r12, 0x10(r3)
/* 800A6814 000A3754  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800A6818 000A3758  7D 89 03 A6 */	mtctr r12
/* 800A681C 000A375C  4E 80 04 21 */	bctrl 
/* 800A6820 000A3760  7F 83 E3 78 */	mr r3, r28
/* 800A6824 000A3764  7F A4 EB 78 */	mr r4, r29
/* 800A6828 000A3768  4B F8 03 FD */	bl remove__10JSUPtrListFP10JSUPtrLink
/* 800A682C 000A376C  7F FD FB 78 */	mr r29, r31
.L_800A6830:
/* 800A6830 000A3770  28 1D 00 00 */	cmplwi r29, 0
/* 800A6834 000A3774  40 82 FF D4 */	bne .L_800A6808
/* 800A6838 000A3778  7F C3 F3 78 */	mr r3, r30
/* 800A683C 000A377C  48 04 84 25 */	bl OSRestoreInterrupts
/* 800A6840 000A3780  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800A6844 000A3784  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800A6848 000A3788  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800A684C 000A378C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800A6850 000A3790  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800A6854 000A3794  7C 08 03 A6 */	mtlr r0
/* 800A6858 000A3798  38 21 00 20 */	addi r1, r1, 0x20
/* 800A685C 000A379C  4E 80 00 20 */	blr 
.endfn execCommandOnce__Q210JASPortCmd9TPortHeadFv

.fn execCommandStay__Q210JASPortCmd9TPortHeadFv, global
/* 800A6860 000A37A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800A6864 000A37A4  7C 08 02 A6 */	mflr r0
/* 800A6868 000A37A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800A686C 000A37AC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800A6870 000A37B0  93 C1 00 08 */	stw r30, 8(r1)
/* 800A6874 000A37B4  7C 7E 1B 78 */	mr r30, r3
/* 800A6878 000A37B8  48 04 83 C1 */	bl OSDisableInterrupts
/* 800A687C 000A37BC  83 DE 00 00 */	lwz r30, 0(r30)
/* 800A6880 000A37C0  7C 7F 1B 78 */	mr r31, r3
/* 800A6884 000A37C4  48 00 00 1C */	b .L_800A68A0
.L_800A6888:
/* 800A6888 000A37C8  80 7E 00 00 */	lwz r3, 0(r30)
/* 800A688C 000A37CC  81 83 00 10 */	lwz r12, 0x10(r3)
/* 800A6890 000A37D0  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800A6894 000A37D4  7D 89 03 A6 */	mtctr r12
/* 800A6898 000A37D8  4E 80 04 21 */	bctrl 
/* 800A689C 000A37DC  83 DE 00 0C */	lwz r30, 0xc(r30)
.L_800A68A0:
/* 800A68A0 000A37E0  28 1E 00 00 */	cmplwi r30, 0
/* 800A68A4 000A37E4  40 82 FF E4 */	bne .L_800A6888
/* 800A68A8 000A37E8  7F E3 FB 78 */	mr r3, r31
/* 800A68AC 000A37EC  48 04 83 B5 */	bl OSRestoreInterrupts
/* 800A68B0 000A37F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800A68B4 000A37F4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800A68B8 000A37F8  83 C1 00 08 */	lwz r30, 8(r1)
/* 800A68BC 000A37FC  7C 08 03 A6 */	mtlr r0
/* 800A68C0 000A3800  38 21 00 10 */	addi r1, r1, 0x10
/* 800A68C4 000A3804  4E 80 00 20 */	blr 
.endfn execCommandStay__Q210JASPortCmd9TPortHeadFv

.fn __sinit_JASCmdStack_cpp, local
/* 800A68C8 000A3808  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800A68CC 000A380C  7C 08 02 A6 */	mflr r0
/* 800A68D0 000A3810  3C 60 80 51 */	lis r3, sCommandListOnce__10JASPortCmd@ha
/* 800A68D4 000A3814  90 01 00 14 */	stw r0, 0x14(r1)
/* 800A68D8 000A3818  38 63 21 8C */	addi r3, r3, sCommandListOnce__10JASPortCmd@l
/* 800A68DC 000A381C  4B F7 FF F5 */	bl initiate__10JSUPtrListFv
/* 800A68E0 000A3820  3C 60 80 51 */	lis r3, sCommandListOnce__10JASPortCmd@ha
/* 800A68E4 000A3824  3C 80 80 0A */	lis r4, __dt__Q210JASPortCmd9TPortHeadFv@ha
/* 800A68E8 000A3828  3C A0 80 4F */	lis r5, lbl_804F06E8@ha
/* 800A68EC 000A382C  38 63 21 8C */	addi r3, r3, sCommandListOnce__10JASPortCmd@l
/* 800A68F0 000A3830  38 84 69 34 */	addi r4, r4, __dt__Q210JASPortCmd9TPortHeadFv@l
/* 800A68F4 000A3834  38 A5 06 E8 */	addi r5, r5, lbl_804F06E8@l
/* 800A68F8 000A3838  48 01 AE 09 */	bl __register_global_object
/* 800A68FC 000A383C  3C 60 80 51 */	lis r3, sCommandListStay__10JASPortCmd@ha
/* 800A6900 000A3840  38 63 21 A4 */	addi r3, r3, sCommandListStay__10JASPortCmd@l
/* 800A6904 000A3844  4B F7 FF CD */	bl initiate__10JSUPtrListFv
/* 800A6908 000A3848  3C 60 80 51 */	lis r3, sCommandListStay__10JASPortCmd@ha
/* 800A690C 000A384C  3C 80 80 0A */	lis r4, __dt__Q210JASPortCmd9TPortHeadFv@ha
/* 800A6910 000A3850  3C A0 80 4F */	lis r5, lbl_804F06F4@ha
/* 800A6914 000A3854  38 63 21 A4 */	addi r3, r3, sCommandListStay__10JASPortCmd@l
/* 800A6918 000A3858  38 84 69 34 */	addi r4, r4, __dt__Q210JASPortCmd9TPortHeadFv@l
/* 800A691C 000A385C  38 A5 06 F4 */	addi r5, r5, lbl_804F06F4@l
/* 800A6920 000A3860  48 01 AD E1 */	bl __register_global_object
/* 800A6924 000A3864  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800A6928 000A3868  7C 08 03 A6 */	mtlr r0
/* 800A692C 000A386C  38 21 00 10 */	addi r1, r1, 0x10
/* 800A6930 000A3870  4E 80 00 20 */	blr 
.endfn __sinit_JASCmdStack_cpp

.fn __dt__Q210JASPortCmd9TPortHeadFv, weak
/* 800A6934 000A3874  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800A6938 000A3878  7C 08 02 A6 */	mflr r0
/* 800A693C 000A387C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800A6940 000A3880  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800A6944 000A3884  7C 9F 23 78 */	mr r31, r4
/* 800A6948 000A3888  93 C1 00 08 */	stw r30, 8(r1)
/* 800A694C 000A388C  7C 7E 1B 79 */	or. r30, r3, r3
/* 800A6950 000A3890  41 82 00 20 */	beq .L_800A6970
/* 800A6954 000A3894  41 82 00 0C */	beq .L_800A6960
/* 800A6958 000A3898  38 80 00 00 */	li r4, 0
/* 800A695C 000A389C  4B F7 FF 0D */	bl __dt__10JSUPtrListFv
.L_800A6960:
/* 800A6960 000A38A0  7F E0 07 35 */	extsh. r0, r31
/* 800A6964 000A38A4  40 81 00 0C */	ble .L_800A6970
/* 800A6968 000A38A8  7F C3 F3 78 */	mr r3, r30
/* 800A696C 000A38AC  4B F7 D7 49 */	bl __dl__FPv
.L_800A6970:
/* 800A6970 000A38B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800A6974 000A38B4  7F C3 F3 78 */	mr r3, r30
/* 800A6978 000A38B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800A697C 000A38BC  83 C1 00 08 */	lwz r30, 8(r1)
/* 800A6980 000A38C0  7C 08 03 A6 */	mtlr r0
/* 800A6984 000A38C4  38 21 00 10 */	addi r1, r1, 0x10
/* 800A6988 000A38C8  4E 80 00 20 */	blr 
.endfn __dt__Q210JASPortCmd9TPortHeadFv
