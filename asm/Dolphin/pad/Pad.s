.include "macros.inc"
.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj lbl_804A9E60, local
	.asciz "<< Dolphin SDK - PAD\trelease build: Aug  6 2003 04:30:02 (0x2301) >>"
.endobj lbl_804A9E60
.balign 4
.obj ResetFunctionInfo, local
	.4byte OnReset
	.4byte 0x0000007F
	.4byte 0x00000000
	.4byte 0x00000000
.endobj ResetFunctionInfo

.section .bss  # 0x804EFC20 - 0x8051467C
.obj Type, local
	.skip 0x10
.endobj Type
.obj Origin, local
	.skip 0x30
.endobj Origin
.obj CmdProbeDevice, local
	.skip 0x10
.endobj CmdProbeDevice

.section .sdata, "wa"  # 0x80514680 - 0x80514D80
.balign 8
.obj __PADVersion, global
	.4byte lbl_804A9E60
.endobj __PADVersion
.obj ResettingChan, local
	.4byte 0x00000020
.endobj ResettingChan
.obj XPatchBits, local
	.4byte 0xF0000000
.endobj XPatchBits
.obj AnalogMode, local
	.4byte 0x00000300
.endobj AnalogMode
.obj Spec, local
	.4byte 5
.endobj Spec
.obj MakeStatus, local
	.4byte SPEC2_MakeStatus
.endobj MakeStatus
.obj CmdReadOrigin, local
	.4byte 0x41000000
.endobj CmdReadOrigin
.obj CmdCalibrate, local
	.4byte 0x42000000
.endobj CmdCalibrate

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj Initialized, local
	.skip 4
.endobj Initialized
.obj EnabledBits, local
	.skip 4
.endobj Initialized
.obj ResettingBits, local
	.skip 4
.endobj ResettingBits
.obj RecalibrateBits, local
	.skip 4
.endobj RecalibrateBits
.obj WaitingBits, local
	.skip 4
.endobj WaitingBits
.obj CheckingBits, local
	.skip 4
.endobj CheckingBits
.obj PendingBits, local
	.skip 4
.endobj PendingBits
.obj BarrelBits, local
	.skip 4
.endobj BarrelBits
.obj SamplingCallback, local
	.skip 4
.endobj SamplingCallback
.obj recalibrated$388, local
	.skip 4
.endobj recalibrated$388
.obj __PADSpec, global
	.skip 4
.endobj __PADSpec

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn UpdateOrigin, local
/* 800F3540 000F0480  7C 08 02 A6 */	mflr r0
/* 800F3544 000F0484  3C A0 80 4F */	lis r5, Origin@ha
/* 800F3548 000F0488  90 01 00 04 */	stw r0, 4(r1)
/* 800F354C 000F048C  1C C3 00 0C */	mulli r6, r3, 0xc
/* 800F3550 000F0490  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F3554 000F0494  38 A5 71 40 */	addi r5, r5, Origin@l
/* 800F3558 000F0498  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F355C 000F049C  7F E5 32 14 */	add r31, r5, r6
/* 800F3560 000F04A0  80 0D 83 8C */	lwz r0, AnalogMode@sda21(r13)
/* 800F3564 000F04A4  54 04 05 6E */	rlwinm r4, r0, 0, 0x15, 0x17
/* 800F3568 000F04A8  2C 04 04 00 */	cmpwi r4, 0x400
/* 800F356C 000F04AC  3C 00 80 00 */	lis r0, 0x8000
/* 800F3570 000F04B0  7C 00 1C 30 */	srw r0, r0, r3
/* 800F3574 000F04B4  41 82 00 F4 */	beq .L_800F3668
/* 800F3578 000F04B8  40 80 00 34 */	bge .L_800F35AC
/* 800F357C 000F04BC  2C 04 02 00 */	cmpwi r4, 0x200
/* 800F3580 000F04C0  41 82 00 B8 */	beq .L_800F3638
/* 800F3584 000F04C4  40 80 00 1C */	bge .L_800F35A0
/* 800F3588 000F04C8  2C 04 01 00 */	cmpwi r4, 0x100
/* 800F358C 000F04CC  41 82 00 78 */	beq .L_800F3604
/* 800F3590 000F04D0  40 80 00 D8 */	bge .L_800F3668
/* 800F3594 000F04D4  2C 04 00 00 */	cmpwi r4, 0
/* 800F3598 000F04D8  41 82 00 38 */	beq .L_800F35D0
/* 800F359C 000F04DC  48 00 00 CC */	b .L_800F3668
.L_800F35A0:
/* 800F35A0 000F04E0  2C 04 03 00 */	cmpwi r4, 0x300
/* 800F35A4 000F04E4  41 82 00 C4 */	beq .L_800F3668
/* 800F35A8 000F04E8  48 00 00 C0 */	b .L_800F3668
.L_800F35AC:
/* 800F35AC 000F04EC  2C 04 06 00 */	cmpwi r4, 0x600
/* 800F35B0 000F04F0  41 82 00 20 */	beq .L_800F35D0
/* 800F35B4 000F04F4  40 80 00 10 */	bge .L_800F35C4
/* 800F35B8 000F04F8  2C 04 05 00 */	cmpwi r4, 0x500
/* 800F35BC 000F04FC  41 82 00 14 */	beq .L_800F35D0
/* 800F35C0 000F0500  48 00 00 A8 */	b .L_800F3668
.L_800F35C4:
/* 800F35C4 000F0504  2C 04 07 00 */	cmpwi r4, 0x700
/* 800F35C8 000F0508  41 82 00 08 */	beq .L_800F35D0
/* 800F35CC 000F050C  48 00 00 9C */	b .L_800F3668
.L_800F35D0:
/* 800F35D0 000F0510  88 9F 00 06 */	lbz r4, 6(r31)
/* 800F35D4 000F0514  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F35D8 000F0518  98 9F 00 06 */	stb r4, 6(r31)
/* 800F35DC 000F051C  88 9F 00 07 */	lbz r4, 7(r31)
/* 800F35E0 000F0520  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F35E4 000F0524  98 9F 00 07 */	stb r4, 7(r31)
/* 800F35E8 000F0528  88 9F 00 08 */	lbz r4, 8(r31)
/* 800F35EC 000F052C  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F35F0 000F0530  98 9F 00 08 */	stb r4, 8(r31)
/* 800F35F4 000F0534  88 9F 00 09 */	lbz r4, 9(r31)
/* 800F35F8 000F0538  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F35FC 000F053C  98 9F 00 09 */	stb r4, 9(r31)
/* 800F3600 000F0540  48 00 00 68 */	b .L_800F3668
.L_800F3604:
/* 800F3604 000F0544  88 9F 00 04 */	lbz r4, 4(r31)
/* 800F3608 000F0548  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F360C 000F054C  98 9F 00 04 */	stb r4, 4(r31)
/* 800F3610 000F0550  88 9F 00 05 */	lbz r4, 5(r31)
/* 800F3614 000F0554  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F3618 000F0558  98 9F 00 05 */	stb r4, 5(r31)
/* 800F361C 000F055C  88 9F 00 08 */	lbz r4, 8(r31)
/* 800F3620 000F0560  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F3624 000F0564  98 9F 00 08 */	stb r4, 8(r31)
/* 800F3628 000F0568  88 9F 00 09 */	lbz r4, 9(r31)
/* 800F362C 000F056C  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F3630 000F0570  98 9F 00 09 */	stb r4, 9(r31)
/* 800F3634 000F0574  48 00 00 34 */	b .L_800F3668
.L_800F3638:
/* 800F3638 000F0578  88 9F 00 04 */	lbz r4, 4(r31)
/* 800F363C 000F057C  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F3640 000F0580  98 9F 00 04 */	stb r4, 4(r31)
/* 800F3644 000F0584  88 9F 00 05 */	lbz r4, 5(r31)
/* 800F3648 000F0588  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F364C 000F058C  98 9F 00 05 */	stb r4, 5(r31)
/* 800F3650 000F0590  88 9F 00 06 */	lbz r4, 6(r31)
/* 800F3654 000F0594  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F3658 000F0598  98 9F 00 06 */	stb r4, 6(r31)
/* 800F365C 000F059C  88 9F 00 07 */	lbz r4, 7(r31)
/* 800F3660 000F05A0  54 84 00 36 */	rlwinm r4, r4, 0, 0, 0x1b
/* 800F3664 000F05A4  98 9F 00 07 */	stb r4, 7(r31)
.L_800F3668:
/* 800F3668 000F05A8  88 9F 00 02 */	lbz r4, 2(r31)
/* 800F366C 000F05AC  38 84 FF 80 */	addi r4, r4, -128
/* 800F3670 000F05B0  98 9F 00 02 */	stb r4, 2(r31)
/* 800F3674 000F05B4  88 9F 00 03 */	lbz r4, 3(r31)
/* 800F3678 000F05B8  38 84 FF 80 */	addi r4, r4, -128
/* 800F367C 000F05BC  98 9F 00 03 */	stb r4, 3(r31)
/* 800F3680 000F05C0  88 9F 00 04 */	lbz r4, 4(r31)
/* 800F3684 000F05C4  38 84 FF 80 */	addi r4, r4, -128
/* 800F3688 000F05C8  98 9F 00 04 */	stb r4, 4(r31)
/* 800F368C 000F05CC  88 9F 00 05 */	lbz r4, 5(r31)
/* 800F3690 000F05D0  38 84 FF 80 */	addi r4, r4, -128
/* 800F3694 000F05D4  98 9F 00 05 */	stb r4, 5(r31)
/* 800F3698 000F05D8  80 8D 83 88 */	lwz r4, XPatchBits@sda21(r13)
/* 800F369C 000F05DC  7C 80 00 39 */	and. r0, r4, r0
/* 800F36A0 000F05E0  41 82 00 30 */	beq .L_800F36D0
/* 800F36A4 000F05E4  88 1F 00 02 */	lbz r0, 2(r31)
/* 800F36A8 000F05E8  7C 00 07 74 */	extsb r0, r0
/* 800F36AC 000F05EC  2C 00 00 40 */	cmpwi r0, 0x40
/* 800F36B0 000F05F0  40 81 00 20 */	ble .L_800F36D0
/* 800F36B4 000F05F4  48 00 2C 39 */	bl SIGetType
/* 800F36B8 000F05F8  54 63 00 1E */	rlwinm r3, r3, 0, 0, 0xf
/* 800F36BC 000F05FC  3C 03 F7 00 */	addis r0, r3, 0xf700
/* 800F36C0 000F0600  28 00 00 00 */	cmplwi r0, 0
/* 800F36C4 000F0604  40 82 00 0C */	bne .L_800F36D0
/* 800F36C8 000F0608  38 00 00 00 */	li r0, 0
/* 800F36CC 000F060C  98 1F 00 02 */	stb r0, 2(r31)
.L_800F36D0:
/* 800F36D0 000F0610  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F36D4 000F0614  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F36D8 000F0618  38 21 00 18 */	addi r1, r1, 0x18
/* 800F36DC 000F061C  7C 08 03 A6 */	mtlr r0
/* 800F36E0 000F0620  4E 80 00 20 */	blr 
.endfn UpdateOrigin

.fn PADOriginCallback, local
/* 800F36E4 000F0624  7C 08 02 A6 */	mflr r0
/* 800F36E8 000F0628  90 01 00 04 */	stw r0, 4(r1)
/* 800F36EC 000F062C  54 80 07 3F */	clrlwi. r0, r4, 0x1c
/* 800F36F0 000F0630  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F36F4 000F0634  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800F36F8 000F0638  40 82 00 48 */	bne .L_800F3740
/* 800F36FC 000F063C  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3700 000F0640  4B FF FE 41 */	bl UpdateOrigin
/* 800F3704 000F0644  83 ED 83 84 */	lwz r31, ResettingChan@sda21(r13)
/* 800F3708 000F0648  3C 00 80 00 */	lis r0, 0x8000
/* 800F370C 000F064C  80 6D 8F F4 */	lwz r3, EnabledBits@sda21(r13)
/* 800F3710 000F0650  38 81 00 1C */	addi r4, r1, 0x1c
/* 800F3714 000F0654  7C 00 FC 30 */	srw r0, r0, r31
/* 800F3718 000F0658  7C 60 03 78 */	or r0, r3, r0
/* 800F371C 000F065C  90 0D 8F F4 */	stw r0, EnabledBits@sda21(r13)
/* 800F3720 000F0660  7F E3 FB 78 */	mr r3, r31
/* 800F3724 000F0664  48 00 26 75 */	bl SIGetResponse
/* 800F3728 000F0668  80 0D 83 8C */	lwz r0, AnalogMode@sda21(r13)
/* 800F372C 000F066C  38 7F 00 00 */	addi r3, r31, 0
/* 800F3730 000F0670  64 04 00 40 */	oris r4, r0, 0x40
/* 800F3734 000F0674  48 00 23 F9 */	bl SISetCommand
/* 800F3738 000F0678  80 6D 8F F4 */	lwz r3, EnabledBits@sda21(r13)
/* 800F373C 000F067C  48 00 24 81 */	bl SIEnablePolling
.L_800F3740:
/* 800F3740 000F0680  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F3744 000F0684  7C A0 00 34 */	cntlzw r0, r5
/* 800F3748 000F0688  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F374C 000F068C  80 8D 83 84 */	lwz r4, ResettingChan@sda21(r13)
/* 800F3750 000F0690  2C 04 00 20 */	cmpwi r4, 0x20
/* 800F3754 000F0694  41 82 00 40 */	beq .L_800F3794
/* 800F3758 000F0698  3C 00 80 00 */	lis r0, 0x8000
/* 800F375C 000F069C  7C 00 24 30 */	srw r0, r0, r4
/* 800F3760 000F06A0  7C A0 00 78 */	andc r0, r5, r0
/* 800F3764 000F06A4  1C 84 00 0C */	mulli r4, r4, 0xc
/* 800F3768 000F06A8  90 0D 8F F8 */	stw r0, ResettingBits@sda21(r13)
/* 800F376C 000F06AC  3C 60 80 4F */	lis r3, Origin@ha
/* 800F3770 000F06B0  38 03 71 40 */	addi r0, r3, Origin@l
/* 800F3774 000F06B4  7C 60 22 14 */	add r3, r0, r4
/* 800F3778 000F06B8  38 80 00 00 */	li r4, 0
/* 800F377C 000F06BC  38 A0 00 0C */	li r5, 0xc
/* 800F3780 000F06C0  4B F1 19 35 */	bl memset
/* 800F3784 000F06C4  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3788 000F06C8  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F378C 000F06CC  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3790 000F06D0  48 00 2D 21 */	bl SIGetTypeAsync
.L_800F3794:
/* 800F3794 000F06D4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F3798 000F06D8  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800F379C 000F06DC  38 21 00 30 */	addi r1, r1, 0x30
/* 800F37A0 000F06E0  7C 08 03 A6 */	mtlr r0
/* 800F37A4 000F06E4  4E 80 00 20 */	blr 
.endfn PADOriginCallback

.fn PADOriginUpdateCallback, local
/* 800F37A8 000F06E8  7C 08 02 A6 */	mflr r0
/* 800F37AC 000F06EC  90 01 00 04 */	stw r0, 4(r1)
/* 800F37B0 000F06F0  3C 00 80 00 */	lis r0, 0x8000
/* 800F37B4 000F06F4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800F37B8 000F06F8  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800F37BC 000F06FC  3B E4 00 00 */	addi r31, r4, 0
/* 800F37C0 000F0700  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800F37C4 000F0704  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800F37C8 000F0708  7C 7D 1B 78 */	mr r29, r3
/* 800F37CC 000F070C  7C 1E EC 30 */	srw r30, r0, r29
/* 800F37D0 000F0710  80 6D 8F F4 */	lwz r3, EnabledBits@sda21(r13)
/* 800F37D4 000F0714  7C 60 F0 39 */	and. r0, r3, r30
/* 800F37D8 000F0718  41 82 00 80 */	beq .L_800F3858
/* 800F37DC 000F071C  57 E0 07 3F */	clrlwi. r0, r31, 0x1c
/* 800F37E0 000F0720  40 82 00 0C */	bne .L_800F37EC
/* 800F37E4 000F0724  7F A3 EB 78 */	mr r3, r29
/* 800F37E8 000F0728  4B FF FD 59 */	bl UpdateOrigin
.L_800F37EC:
/* 800F37EC 000F072C  57 E0 07 39 */	rlwinm. r0, r31, 0, 0x1c, 0x1c
/* 800F37F0 000F0730  41 82 00 68 */	beq .L_800F3858
/* 800F37F4 000F0734  4B FF B4 45 */	bl OSDisableInterrupts
/* 800F37F8 000F0738  3B E3 00 00 */	addi r31, r3, 0
/* 800F37FC 000F073C  38 7E 00 00 */	addi r3, r30, 0
/* 800F3800 000F0740  48 00 24 59 */	bl SIDisablePolling
/* 800F3804 000F0744  80 0D 8F F4 */	lwz r0, EnabledBits@sda21(r13)
/* 800F3808 000F0748  7F C9 F0 F8 */	nor r9, r30, r30
/* 800F380C 000F074C  80 CD 90 00 */	lwz r6, WaitingBits@sda21(r13)
/* 800F3810 000F0750  7F A3 EB 78 */	mr r3, r29
/* 800F3814 000F0754  80 AD 90 04 */	lwz r5, CheckingBits@sda21(r13)
/* 800F3818 000F0758  80 8D 90 08 */	lwz r4, PendingBits@sda21(r13)
/* 800F381C 000F075C  7C 08 48 38 */	and r8, r0, r9
/* 800F3820 000F0760  80 0D 90 0C */	lwz r0, BarrelBits@sda21(r13)
/* 800F3824 000F0764  7C C7 48 38 */	and r7, r6, r9
/* 800F3828 000F0768  7C A6 48 38 */	and r6, r5, r9
/* 800F382C 000F076C  7C 85 48 38 */	and r5, r4, r9
/* 800F3830 000F0770  91 0D 8F F4 */	stw r8, EnabledBits@sda21(r13)
/* 800F3834 000F0774  7C 00 48 38 */	and r0, r0, r9
/* 800F3838 000F0778  90 ED 90 00 */	stw r7, WaitingBits@sda21(r13)
/* 800F383C 000F077C  38 80 00 00 */	li r4, 0
/* 800F3840 000F0780  90 CD 90 04 */	stw r6, CheckingBits@sda21(r13)
/* 800F3844 000F0784  90 AD 90 08 */	stw r5, PendingBits@sda21(r13)
/* 800F3848 000F0788  90 0D 90 0C */	stw r0, BarrelBits@sda21(r13)
/* 800F384C 000F078C  4B FF DD B5 */	bl OSSetWirelessID
/* 800F3850 000F0790  7F E3 FB 78 */	mr r3, r31
/* 800F3854 000F0794  4B FF B4 0D */	bl OSRestoreInterrupts
.L_800F3858:
/* 800F3858 000F0798  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800F385C 000F079C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800F3860 000F07A0  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800F3864 000F07A4  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800F3868 000F07A8  38 21 00 28 */	addi r1, r1, 0x28
/* 800F386C 000F07AC  7C 08 03 A6 */	mtlr r0
/* 800F3870 000F07B0  4E 80 00 20 */	blr 
.endfn PADOriginUpdateCallback

.fn PADProbeCallback, local
/* 800F3874 000F07B4  7C 08 02 A6 */	mflr r0
/* 800F3878 000F07B8  90 01 00 04 */	stw r0, 4(r1)
/* 800F387C 000F07BC  54 80 07 3F */	clrlwi. r0, r4, 0x1c
/* 800F3880 000F07C0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F3884 000F07C4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800F3888 000F07C8  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800F388C 000F07CC  40 82 00 54 */	bne .L_800F38E0
/* 800F3890 000F07D0  83 CD 83 84 */	lwz r30, ResettingChan@sda21(r13)
/* 800F3894 000F07D4  3F E0 80 00 */	lis r31, 0x8000
/* 800F3898 000F07D8  80 6D 8F F4 */	lwz r3, EnabledBits@sda21(r13)
/* 800F389C 000F07DC  38 81 00 1C */	addi r4, r1, 0x1c
/* 800F38A0 000F07E0  7F E0 F4 30 */	srw r0, r31, r30
/* 800F38A4 000F07E4  7C 60 03 78 */	or r0, r3, r0
/* 800F38A8 000F07E8  90 0D 8F F4 */	stw r0, EnabledBits@sda21(r13)
/* 800F38AC 000F07EC  7F C3 F3 78 */	mr r3, r30
/* 800F38B0 000F07F0  48 00 24 E9 */	bl SIGetResponse
/* 800F38B4 000F07F4  80 0D 83 8C */	lwz r0, AnalogMode@sda21(r13)
/* 800F38B8 000F07F8  38 7E 00 00 */	addi r3, r30, 0
/* 800F38BC 000F07FC  64 04 00 40 */	oris r4, r0, 0x40
/* 800F38C0 000F0800  48 00 22 6D */	bl SISetCommand
/* 800F38C4 000F0804  80 6D 8F F4 */	lwz r3, EnabledBits@sda21(r13)
/* 800F38C8 000F0808  48 00 22 F5 */	bl SIEnablePolling
/* 800F38CC 000F080C  80 0D 83 84 */	lwz r0, ResettingChan@sda21(r13)
/* 800F38D0 000F0810  80 6D 90 00 */	lwz r3, WaitingBits@sda21(r13)
/* 800F38D4 000F0814  7F E0 04 30 */	srw r0, r31, r0
/* 800F38D8 000F0818  7C 60 03 78 */	or r0, r3, r0
/* 800F38DC 000F081C  90 0D 90 00 */	stw r0, WaitingBits@sda21(r13)
.L_800F38E0:
/* 800F38E0 000F0820  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F38E4 000F0824  7C A0 00 34 */	cntlzw r0, r5
/* 800F38E8 000F0828  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F38EC 000F082C  80 8D 83 84 */	lwz r4, ResettingChan@sda21(r13)
/* 800F38F0 000F0830  2C 04 00 20 */	cmpwi r4, 0x20
/* 800F38F4 000F0834  41 82 00 40 */	beq .L_800F3934
/* 800F38F8 000F0838  3C 00 80 00 */	lis r0, 0x8000
/* 800F38FC 000F083C  7C 00 24 30 */	srw r0, r0, r4
/* 800F3900 000F0840  7C A0 00 78 */	andc r0, r5, r0
/* 800F3904 000F0844  1C 84 00 0C */	mulli r4, r4, 0xc
/* 800F3908 000F0848  90 0D 8F F8 */	stw r0, ResettingBits@sda21(r13)
/* 800F390C 000F084C  3C 60 80 4F */	lis r3, Origin@ha
/* 800F3910 000F0850  38 03 71 40 */	addi r0, r3, Origin@l
/* 800F3914 000F0854  7C 60 22 14 */	add r3, r0, r4
/* 800F3918 000F0858  38 80 00 00 */	li r4, 0
/* 800F391C 000F085C  38 A0 00 0C */	li r5, 0xc
/* 800F3920 000F0860  4B F1 17 95 */	bl memset
/* 800F3924 000F0864  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3928 000F0868  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F392C 000F086C  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3930 000F0870  48 00 2B 81 */	bl SIGetTypeAsync
.L_800F3934:
/* 800F3934 000F0874  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F3938 000F0878  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800F393C 000F087C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800F3940 000F0880  38 21 00 30 */	addi r1, r1, 0x30
/* 800F3944 000F0884  7C 08 03 A6 */	mtlr r0
/* 800F3948 000F0888  4E 80 00 20 */	blr 
.endfn PADProbeCallback

.fn PADTypeAndStatusCallback, local
/* 800F394C 000F088C  7C 08 02 A6 */	mflr r0
/* 800F3950 000F0890  3C C0 80 4F */	lis r6, Type@ha
/* 800F3954 000F0894  90 01 00 04 */	stw r0, 4(r1)
/* 800F3958 000F0898  54 80 07 3F */	clrlwi. r0, r4, 0x1c
/* 800F395C 000F089C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800F3960 000F08A0  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 800F3964 000F08A4  3F E0 80 00 */	lis r31, 0x8000
/* 800F3968 000F08A8  93 C1 00 38 */	stw r30, 0x38(r1)
/* 800F396C 000F08AC  3B C6 71 30 */	addi r30, r6, Type@l
/* 800F3970 000F08B0  93 A1 00 34 */	stw r29, 0x34(r1)
/* 800F3974 000F08B4  93 81 00 30 */	stw r28, 0x30(r1)
/* 800F3978 000F08B8  83 AD 83 84 */	lwz r29, ResettingChan@sda21(r13)
/* 800F397C 000F08BC  80 AD 8F FC */	lwz r5, RecalibrateBits@sda21(r13)
/* 800F3980 000F08C0  7F FC EC 30 */	srw r28, r31, r29
/* 800F3984 000F08C4  7C A3 E0 78 */	andc r3, r5, r28
/* 800F3988 000F08C8  90 6D 8F FC */	stw r3, RecalibrateBits@sda21(r13)
/* 800F398C 000F08CC  7C A5 E0 38 */	and r5, r5, r28
/* 800F3990 000F08D0  38 60 00 01 */	li r3, 1
/* 800F3994 000F08D4  41 82 00 54 */	beq .L_800F39E8
/* 800F3998 000F08D8  80 8D 8F F8 */	lwz r4, ResettingBits@sda21(r13)
/* 800F399C 000F08DC  7C 80 00 34 */	cntlzw r0, r4
/* 800F39A0 000F08E0  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F39A4 000F08E4  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F39A8 000F08E8  2C 03 00 20 */	cmpwi r3, 0x20
/* 800F39AC 000F08EC  41 82 02 AC */	beq .L_800F3C58
/* 800F39B0 000F08F0  1C 03 00 0C */	mulli r0, r3, 0xc
/* 800F39B4 000F08F4  7F E3 1C 30 */	srw r3, r31, r3
/* 800F39B8 000F08F8  7C 84 18 78 */	andc r4, r4, r3
/* 800F39BC 000F08FC  7C 7E 02 14 */	add r3, r30, r0
/* 800F39C0 000F0900  90 8D 8F F8 */	stw r4, ResettingBits@sda21(r13)
/* 800F39C4 000F0904  38 80 00 00 */	li r4, 0
/* 800F39C8 000F0908  38 A0 00 0C */	li r5, 0xc
/* 800F39CC 000F090C  38 63 00 10 */	addi r3, r3, 0x10
/* 800F39D0 000F0910  4B F1 16 E5 */	bl memset
/* 800F39D4 000F0914  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F39D8 000F0918  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F39DC 000F091C  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F39E0 000F0920  48 00 2A D1 */	bl SIGetTypeAsync
/* 800F39E4 000F0924  48 00 02 74 */	b .L_800F3C58
.L_800F39E8:
/* 800F39E8 000F0928  54 86 00 2E */	rlwinm r6, r4, 0, 0, 0x17
/* 800F39EC 000F092C  54 84 00 C8 */	rlwinm r4, r4, 0, 3, 4
/* 800F39F0 000F0930  3C 04 F8 00 */	addis r0, r4, 0xf800
/* 800F39F4 000F0934  57 A4 10 3A */	slwi r4, r29, 2
/* 800F39F8 000F0938  28 00 00 00 */	cmplwi r0, 0
/* 800F39FC 000F093C  7C DE 21 2E */	stwx r6, r30, r4
/* 800F3A00 000F0940  40 82 00 0C */	bne .L_800F3A0C
/* 800F3A04 000F0944  54 C0 01 CF */	rlwinm. r0, r6, 0, 7, 7
/* 800F3A08 000F0948  40 82 00 58 */	bne .L_800F3A60
.L_800F3A0C:
/* 800F3A0C 000F094C  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F3A10 000F0950  7C A0 00 34 */	cntlzw r0, r5
/* 800F3A14 000F0954  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F3A18 000F0958  80 8D 83 84 */	lwz r4, ResettingChan@sda21(r13)
/* 800F3A1C 000F095C  2C 04 00 20 */	cmpwi r4, 0x20
/* 800F3A20 000F0960  41 82 02 38 */	beq .L_800F3C58
/* 800F3A24 000F0964  3C 60 80 00 */	lis r3, 0x8000
/* 800F3A28 000F0968  1C 04 00 0C */	mulli r0, r4, 0xc
/* 800F3A2C 000F096C  7C 63 24 30 */	srw r3, r3, r4
/* 800F3A30 000F0970  7C A4 18 78 */	andc r4, r5, r3
/* 800F3A34 000F0974  7C 7E 02 14 */	add r3, r30, r0
/* 800F3A38 000F0978  90 8D 8F F8 */	stw r4, ResettingBits@sda21(r13)
/* 800F3A3C 000F097C  38 80 00 00 */	li r4, 0
/* 800F3A40 000F0980  38 A0 00 0C */	li r5, 0xc
/* 800F3A44 000F0984  38 63 00 10 */	addi r3, r3, 0x10
/* 800F3A48 000F0988  4B F1 16 6D */	bl memset
/* 800F3A4C 000F098C  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3A50 000F0990  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3A54 000F0994  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3A58 000F0998  48 00 2A 59 */	bl SIGetTypeAsync
/* 800F3A5C 000F099C  48 00 01 FC */	b .L_800F3C58
.L_800F3A60:
/* 800F3A60 000F09A0  80 0D 83 90 */	lwz r0, Spec@sda21(r13)
/* 800F3A64 000F09A4  28 00 00 02 */	cmplwi r0, 2
/* 800F3A68 000F09A8  40 80 00 84 */	bge .L_800F3AEC
/* 800F3A6C 000F09AC  80 0D 8F F4 */	lwz r0, EnabledBits@sda21(r13)
/* 800F3A70 000F09B0  38 7D 00 00 */	addi r3, r29, 0
/* 800F3A74 000F09B4  38 81 00 1C */	addi r4, r1, 0x1c
/* 800F3A78 000F09B8  7C 00 E3 78 */	or r0, r0, r28
/* 800F3A7C 000F09BC  90 0D 8F F4 */	stw r0, EnabledBits@sda21(r13)
/* 800F3A80 000F09C0  48 00 23 19 */	bl SIGetResponse
/* 800F3A84 000F09C4  80 0D 83 8C */	lwz r0, AnalogMode@sda21(r13)
/* 800F3A88 000F09C8  38 7D 00 00 */	addi r3, r29, 0
/* 800F3A8C 000F09CC  64 04 00 40 */	oris r4, r0, 0x40
/* 800F3A90 000F09D0  48 00 20 9D */	bl SISetCommand
/* 800F3A94 000F09D4  80 6D 8F F4 */	lwz r3, EnabledBits@sda21(r13)
/* 800F3A98 000F09D8  48 00 21 25 */	bl SIEnablePolling
/* 800F3A9C 000F09DC  80 8D 8F F8 */	lwz r4, ResettingBits@sda21(r13)
/* 800F3AA0 000F09E0  7C 80 00 34 */	cntlzw r0, r4
/* 800F3AA4 000F09E4  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F3AA8 000F09E8  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3AAC 000F09EC  2C 03 00 20 */	cmpwi r3, 0x20
/* 800F3AB0 000F09F0  41 82 01 A8 */	beq .L_800F3C58
/* 800F3AB4 000F09F4  1C 03 00 0C */	mulli r0, r3, 0xc
/* 800F3AB8 000F09F8  7F E3 1C 30 */	srw r3, r31, r3
/* 800F3ABC 000F09FC  7C 84 18 78 */	andc r4, r4, r3
/* 800F3AC0 000F0A00  7C 7E 02 14 */	add r3, r30, r0
/* 800F3AC4 000F0A04  90 8D 8F F8 */	stw r4, ResettingBits@sda21(r13)
/* 800F3AC8 000F0A08  38 80 00 00 */	li r4, 0
/* 800F3ACC 000F0A0C  38 A0 00 0C */	li r5, 0xc
/* 800F3AD0 000F0A10  38 63 00 10 */	addi r3, r3, 0x10
/* 800F3AD4 000F0A14  4B F1 15 E1 */	bl memset
/* 800F3AD8 000F0A18  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3ADC 000F0A1C  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3AE0 000F0A20  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3AE4 000F0A24  48 00 29 CD */	bl SIGetTypeAsync
/* 800F3AE8 000F0A28  48 00 01 70 */	b .L_800F3C58
.L_800F3AEC:
/* 800F3AEC 000F0A2C  54 C0 00 01 */	rlwinm. r0, r6, 0, 0, 0
/* 800F3AF0 000F0A30  41 82 00 0C */	beq .L_800F3AFC
/* 800F3AF4 000F0A34  54 C0 01 4B */	rlwinm. r0, r6, 0, 5, 5
/* 800F3AF8 000F0A38  41 82 00 74 */	beq .L_800F3B6C
.L_800F3AFC:
/* 800F3AFC 000F0A3C  28 05 00 00 */	cmplwi r5, 0
/* 800F3B00 000F0A40  41 82 00 38 */	beq .L_800F3B38
/* 800F3B04 000F0A44  1C 1D 00 0C */	mulli r0, r29, 0xc
/* 800F3B08 000F0A48  3C 60 80 0F */	lis r3, PADOriginCallback@ha
/* 800F3B0C 000F0A4C  7C DE 02 14 */	add r6, r30, r0
/* 800F3B10 000F0A50  39 03 36 E4 */	addi r8, r3, PADOriginCallback@l
/* 800F3B14 000F0A54  38 7D 00 00 */	addi r3, r29, 0
/* 800F3B18 000F0A58  38 8D 83 9C */	addi r4, r13, CmdCalibrate@sda21
/* 800F3B1C 000F0A5C  38 A0 00 03 */	li r5, 3
/* 800F3B20 000F0A60  38 E0 00 0A */	li r7, 0xa
/* 800F3B24 000F0A64  39 40 00 00 */	li r10, 0
/* 800F3B28 000F0A68  39 20 00 00 */	li r9, 0
/* 800F3B2C 000F0A6C  38 C6 00 10 */	addi r6, r6, 0x10
/* 800F3B30 000F0A70  48 00 23 B9 */	bl SITransfer
/* 800F3B34 000F0A74  48 00 00 C0 */	b .L_800F3BF4
.L_800F3B38:
/* 800F3B38 000F0A78  1C 1D 00 0C */	mulli r0, r29, 0xc
/* 800F3B3C 000F0A7C  3C 60 80 0F */	lis r3, PADOriginCallback@ha
/* 800F3B40 000F0A80  7C DE 02 14 */	add r6, r30, r0
/* 800F3B44 000F0A84  39 03 36 E4 */	addi r8, r3, PADOriginCallback@l
/* 800F3B48 000F0A88  38 7D 00 00 */	addi r3, r29, 0
/* 800F3B4C 000F0A8C  38 8D 83 98 */	addi r4, r13, CmdReadOrigin@sda21
/* 800F3B50 000F0A90  38 A0 00 01 */	li r5, 1
/* 800F3B54 000F0A94  38 E0 00 0A */	li r7, 0xa
/* 800F3B58 000F0A98  39 40 00 00 */	li r10, 0
/* 800F3B5C 000F0A9C  39 20 00 00 */	li r9, 0
/* 800F3B60 000F0AA0  38 C6 00 10 */	addi r6, r6, 0x10
/* 800F3B64 000F0AA4  48 00 23 85 */	bl SITransfer
/* 800F3B68 000F0AA8  48 00 00 8C */	b .L_800F3BF4
.L_800F3B6C:
/* 800F3B6C 000F0AAC  54 C0 02 D7 */	rlwinm. r0, r6, 0, 0xb, 0xb
/* 800F3B70 000F0AB0  41 82 00 84 */	beq .L_800F3BF4
/* 800F3B74 000F0AB4  54 C0 03 19 */	rlwinm. r0, r6, 0, 0xc, 0xc
/* 800F3B78 000F0AB8  40 82 00 7C */	bne .L_800F3BF4
/* 800F3B7C 000F0ABC  54 C0 03 5B */	rlwinm. r0, r6, 0, 0xd, 0xd
/* 800F3B80 000F0AC0  40 82 00 74 */	bne .L_800F3BF4
/* 800F3B84 000F0AC4  54 C0 00 43 */	rlwinm. r0, r6, 0, 1, 1
/* 800F3B88 000F0AC8  41 82 00 38 */	beq .L_800F3BC0
/* 800F3B8C 000F0ACC  1C 1D 00 0C */	mulli r0, r29, 0xc
/* 800F3B90 000F0AD0  3C 60 80 0F */	lis r3, PADOriginCallback@ha
/* 800F3B94 000F0AD4  7C DE 02 14 */	add r6, r30, r0
/* 800F3B98 000F0AD8  39 03 36 E4 */	addi r8, r3, PADOriginCallback@l
/* 800F3B9C 000F0ADC  38 7D 00 00 */	addi r3, r29, 0
/* 800F3BA0 000F0AE0  38 8D 83 98 */	addi r4, r13, CmdReadOrigin@sda21
/* 800F3BA4 000F0AE4  38 A0 00 01 */	li r5, 1
/* 800F3BA8 000F0AE8  38 E0 00 0A */	li r7, 0xa
/* 800F3BAC 000F0AEC  39 40 00 00 */	li r10, 0
/* 800F3BB0 000F0AF0  39 20 00 00 */	li r9, 0
/* 800F3BB4 000F0AF4  38 C6 00 10 */	addi r6, r6, 0x10
/* 800F3BB8 000F0AF8  48 00 23 31 */	bl SITransfer
/* 800F3BBC 000F0AFC  48 00 00 38 */	b .L_800F3BF4
.L_800F3BC0:
/* 800F3BC0 000F0B00  1C 1D 00 0C */	mulli r0, r29, 0xc
/* 800F3BC4 000F0B04  3C 60 80 0F */	lis r3, PADProbeCallback@ha
/* 800F3BC8 000F0B08  7C 9E 22 14 */	add r4, r30, r4
/* 800F3BCC 000F0B0C  7C DE 02 14 */	add r6, r30, r0
/* 800F3BD0 000F0B10  39 03 38 74 */	addi r8, r3, PADProbeCallback@l
/* 800F3BD4 000F0B14  38 7D 00 00 */	addi r3, r29, 0
/* 800F3BD8 000F0B18  38 A0 00 03 */	li r5, 3
/* 800F3BDC 000F0B1C  38 E0 00 08 */	li r7, 8
/* 800F3BE0 000F0B20  39 40 00 00 */	li r10, 0
/* 800F3BE4 000F0B24  39 20 00 00 */	li r9, 0
/* 800F3BE8 000F0B28  38 84 00 40 */	addi r4, r4, 0x40
/* 800F3BEC 000F0B2C  38 C6 00 10 */	addi r6, r6, 0x10
/* 800F3BF0 000F0B30  48 00 22 F9 */	bl SITransfer
.L_800F3BF4:
/* 800F3BF4 000F0B34  2C 03 00 00 */	cmpwi r3, 0
/* 800F3BF8 000F0B38  40 82 00 60 */	bne .L_800F3C58
/* 800F3BFC 000F0B3C  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F3C00 000F0B40  80 6D 90 08 */	lwz r3, PendingBits@sda21(r13)
/* 800F3C04 000F0B44  7C A0 00 34 */	cntlzw r0, r5
/* 800F3C08 000F0B48  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F3C0C 000F0B4C  7C 60 E3 78 */	or r0, r3, r28
/* 800F3C10 000F0B50  80 8D 83 84 */	lwz r4, ResettingChan@sda21(r13)
/* 800F3C14 000F0B54  90 0D 90 08 */	stw r0, PendingBits@sda21(r13)
/* 800F3C18 000F0B58  2C 04 00 20 */	cmpwi r4, 0x20
/* 800F3C1C 000F0B5C  41 82 00 3C */	beq .L_800F3C58
/* 800F3C20 000F0B60  3C 60 80 00 */	lis r3, 0x8000
/* 800F3C24 000F0B64  1C 04 00 0C */	mulli r0, r4, 0xc
/* 800F3C28 000F0B68  7C 63 24 30 */	srw r3, r3, r4
/* 800F3C2C 000F0B6C  7C A4 18 78 */	andc r4, r5, r3
/* 800F3C30 000F0B70  7C 7E 02 14 */	add r3, r30, r0
/* 800F3C34 000F0B74  90 8D 8F F8 */	stw r4, ResettingBits@sda21(r13)
/* 800F3C38 000F0B78  38 80 00 00 */	li r4, 0
/* 800F3C3C 000F0B7C  38 A0 00 0C */	li r5, 0xc
/* 800F3C40 000F0B80  38 63 00 10 */	addi r3, r3, 0x10
/* 800F3C44 000F0B84  4B F1 14 71 */	bl memset
/* 800F3C48 000F0B88  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3C4C 000F0B8C  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3C50 000F0B90  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3C54 000F0B94  48 00 28 5D */	bl SIGetTypeAsync
.L_800F3C58:
/* 800F3C58 000F0B98  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800F3C5C 000F0B9C  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 800F3C60 000F0BA0  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 800F3C64 000F0BA4  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 800F3C68 000F0BA8  83 81 00 30 */	lwz r28, 0x30(r1)
/* 800F3C6C 000F0BAC  38 21 00 40 */	addi r1, r1, 0x40
/* 800F3C70 000F0BB0  7C 08 03 A6 */	mtlr r0
/* 800F3C74 000F0BB4  4E 80 00 20 */	blr 
.endfn PADTypeAndStatusCallback

.fn PADReceiveCheckCallback, local
/* 800F3C78 000F0BB8  7C 08 02 A6 */	mflr r0
/* 800F3C7C 000F0BBC  90 01 00 04 */	stw r0, 4(r1)
/* 800F3C80 000F0BC0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F3C84 000F0BC4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F3C88 000F0BC8  7C 7F 1B 78 */	mr r31, r3
/* 800F3C8C 000F0BCC  3C 60 80 00 */	lis r3, 0x8000
/* 800F3C90 000F0BD0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F3C94 000F0BD4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F3C98 000F0BD8  7C 7D FC 30 */	srw r29, r3, r31
/* 800F3C9C 000F0BDC  80 0D 8F F4 */	lwz r0, EnabledBits@sda21(r13)
/* 800F3CA0 000F0BE0  7C 00 E8 39 */	and. r0, r0, r29
/* 800F3CA4 000F0BE4  41 82 00 F8 */	beq .L_800F3D9C
/* 800F3CA8 000F0BE8  80 AD 90 00 */	lwz r5, WaitingBits@sda21(r13)
/* 800F3CAC 000F0BEC  7F A6 E8 F8 */	nor r6, r29, r29
/* 800F3CB0 000F0BF0  80 6D 90 04 */	lwz r3, CheckingBits@sda21(r13)
/* 800F3CB4 000F0BF4  54 80 07 3F */	clrlwi. r0, r4, 0x1c
/* 800F3CB8 000F0BF8  7C A5 30 38 */	and r5, r5, r6
/* 800F3CBC 000F0BFC  7C 63 30 38 */	and r3, r3, r6
/* 800F3CC0 000F0C00  90 AD 90 00 */	stw r5, WaitingBits@sda21(r13)
/* 800F3CC4 000F0C04  90 6D 90 04 */	stw r3, CheckingBits@sda21(r13)
/* 800F3CC8 000F0C08  54 83 00 2E */	rlwinm r3, r4, 0, 0, 0x17
/* 800F3CCC 000F0C0C  40 82 00 6C */	bne .L_800F3D38
/* 800F3CD0 000F0C10  54 60 00 01 */	rlwinm. r0, r3, 0, 0, 0
/* 800F3CD4 000F0C14  41 82 00 64 */	beq .L_800F3D38
/* 800F3CD8 000F0C18  54 60 02 D7 */	rlwinm. r0, r3, 0, 0xb, 0xb
/* 800F3CDC 000F0C1C  41 82 00 5C */	beq .L_800F3D38
/* 800F3CE0 000F0C20  54 60 00 43 */	rlwinm. r0, r3, 0, 1, 1
/* 800F3CE4 000F0C24  41 82 00 54 */	beq .L_800F3D38
/* 800F3CE8 000F0C28  54 60 01 4B */	rlwinm. r0, r3, 0, 5, 5
/* 800F3CEC 000F0C2C  40 82 00 4C */	bne .L_800F3D38
/* 800F3CF0 000F0C30  54 60 03 19 */	rlwinm. r0, r3, 0, 0xc, 0xc
/* 800F3CF4 000F0C34  40 82 00 44 */	bne .L_800F3D38
/* 800F3CF8 000F0C38  54 60 03 5B */	rlwinm. r0, r3, 0, 0xd, 0xd
/* 800F3CFC 000F0C3C  40 82 00 3C */	bne .L_800F3D38
/* 800F3D00 000F0C40  1C 9F 00 0C */	mulli r4, r31, 0xc
/* 800F3D04 000F0C44  3C 60 80 4F */	lis r3, Origin@ha
/* 800F3D08 000F0C48  38 03 71 40 */	addi r0, r3, Origin@l
/* 800F3D0C 000F0C4C  3C 60 80 0F */	lis r3, PADOriginUpdateCallback@ha
/* 800F3D10 000F0C50  7C C0 22 14 */	add r6, r0, r4
/* 800F3D14 000F0C54  39 03 37 A8 */	addi r8, r3, PADOriginUpdateCallback@l
/* 800F3D18 000F0C58  38 7F 00 00 */	addi r3, r31, 0
/* 800F3D1C 000F0C5C  38 8D 83 98 */	addi r4, r13, CmdReadOrigin@sda21
/* 800F3D20 000F0C60  38 A0 00 01 */	li r5, 1
/* 800F3D24 000F0C64  38 E0 00 0A */	li r7, 0xa
/* 800F3D28 000F0C68  39 40 00 00 */	li r10, 0
/* 800F3D2C 000F0C6C  39 20 00 00 */	li r9, 0
/* 800F3D30 000F0C70  48 00 21 B9 */	bl SITransfer
/* 800F3D34 000F0C74  48 00 00 68 */	b .L_800F3D9C
.L_800F3D38:
/* 800F3D38 000F0C78  4B FF AF 01 */	bl OSDisableInterrupts
/* 800F3D3C 000F0C7C  3B C3 00 00 */	addi r30, r3, 0
/* 800F3D40 000F0C80  38 7D 00 00 */	addi r3, r29, 0
/* 800F3D44 000F0C84  48 00 1F 15 */	bl SIDisablePolling
/* 800F3D48 000F0C88  80 0D 8F F4 */	lwz r0, EnabledBits@sda21(r13)
/* 800F3D4C 000F0C8C  7F A9 E8 F8 */	nor r9, r29, r29
/* 800F3D50 000F0C90  80 CD 90 00 */	lwz r6, WaitingBits@sda21(r13)
/* 800F3D54 000F0C94  7F E3 FB 78 */	mr r3, r31
/* 800F3D58 000F0C98  80 AD 90 04 */	lwz r5, CheckingBits@sda21(r13)
/* 800F3D5C 000F0C9C  80 8D 90 08 */	lwz r4, PendingBits@sda21(r13)
/* 800F3D60 000F0CA0  7C 08 48 38 */	and r8, r0, r9
/* 800F3D64 000F0CA4  80 0D 90 0C */	lwz r0, BarrelBits@sda21(r13)
/* 800F3D68 000F0CA8  7C C7 48 38 */	and r7, r6, r9
/* 800F3D6C 000F0CAC  7C A6 48 38 */	and r6, r5, r9
/* 800F3D70 000F0CB0  7C 85 48 38 */	and r5, r4, r9
/* 800F3D74 000F0CB4  91 0D 8F F4 */	stw r8, EnabledBits@sda21(r13)
/* 800F3D78 000F0CB8  7C 00 48 38 */	and r0, r0, r9
/* 800F3D7C 000F0CBC  90 ED 90 00 */	stw r7, WaitingBits@sda21(r13)
/* 800F3D80 000F0CC0  38 80 00 00 */	li r4, 0
/* 800F3D84 000F0CC4  90 CD 90 04 */	stw r6, CheckingBits@sda21(r13)
/* 800F3D88 000F0CC8  90 AD 90 08 */	stw r5, PendingBits@sda21(r13)
/* 800F3D8C 000F0CCC  90 0D 90 0C */	stw r0, BarrelBits@sda21(r13)
/* 800F3D90 000F0CD0  4B FF D8 71 */	bl OSSetWirelessID
/* 800F3D94 000F0CD4  7F C3 F3 78 */	mr r3, r30
/* 800F3D98 000F0CD8  4B FF AE C9 */	bl OSRestoreInterrupts
.L_800F3D9C:
/* 800F3D9C 000F0CDC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F3DA0 000F0CE0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F3DA4 000F0CE4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F3DA8 000F0CE8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F3DAC 000F0CEC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F3DB0 000F0CF0  7C 08 03 A6 */	mtlr r0
/* 800F3DB4 000F0CF4  4E 80 00 20 */	blr 
.endfn PADReceiveCheckCallback

.fn PADReset, global
/* 800F3DB8 000F0CF8  7C 08 02 A6 */	mflr r0
/* 800F3DBC 000F0CFC  90 01 00 04 */	stw r0, 4(r1)
/* 800F3DC0 000F0D00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F3DC4 000F0D04  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F3DC8 000F0D08  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F3DCC 000F0D0C  7C 7E 1B 78 */	mr r30, r3
/* 800F3DD0 000F0D10  4B FF AE 69 */	bl OSDisableInterrupts
/* 800F3DD4 000F0D14  80 8D 90 08 */	lwz r4, PendingBits@sda21(r13)
/* 800F3DD8 000F0D18  39 00 00 00 */	li r8, 0
/* 800F3DDC 000F0D1C  80 AD 90 00 */	lwz r5, WaitingBits@sda21(r13)
/* 800F3DE0 000F0D20  7C 7F 1B 78 */	mr r31, r3
/* 800F3DE4 000F0D24  80 0D 90 04 */	lwz r0, CheckingBits@sda21(r13)
/* 800F3DE8 000F0D28  7F DE 23 78 */	or r30, r30, r4
/* 800F3DEC 000F0D2C  80 8D 8F F8 */	lwz r4, ResettingBits@sda21(r13)
/* 800F3DF0 000F0D30  7C A5 03 78 */	or r5, r5, r0
/* 800F3DF4 000F0D34  80 0D 83 90 */	lwz r0, Spec@sda21(r13)
/* 800F3DF8 000F0D38  7F DE 28 78 */	andc r30, r30, r5
/* 800F3DFC 000F0D3C  80 CD 8F F4 */	lwz r6, EnabledBits@sda21(r13)
/* 800F3E00 000F0D40  7C 85 F3 78 */	or r5, r4, r30
/* 800F3E04 000F0D44  80 8D 90 0C */	lwz r4, BarrelBits@sda21(r13)
/* 800F3E08 000F0D48  7F C7 F0 F8 */	nor r7, r30, r30
/* 800F3E0C 000F0D4C  90 AD 8F F8 */	stw r5, ResettingBits@sda21(r13)
/* 800F3E10 000F0D50  7C C5 38 38 */	and r5, r6, r7
/* 800F3E14 000F0D54  7C 84 38 38 */	and r4, r4, r7
/* 800F3E18 000F0D58  80 ED 8F F8 */	lwz r7, ResettingBits@sda21(r13)
/* 800F3E1C 000F0D5C  28 00 00 04 */	cmplwi r0, 4
/* 800F3E20 000F0D60  91 0D 90 08 */	stw r8, PendingBits@sda21(r13)
/* 800F3E24 000F0D64  7C E3 30 38 */	and r3, r7, r6
/* 800F3E28 000F0D68  90 AD 8F F4 */	stw r5, EnabledBits@sda21(r13)
/* 800F3E2C 000F0D6C  90 8D 90 0C */	stw r4, BarrelBits@sda21(r13)
/* 800F3E30 000F0D70  40 82 00 10 */	bne .L_800F3E40
/* 800F3E34 000F0D74  80 0D 8F FC */	lwz r0, RecalibrateBits@sda21(r13)
/* 800F3E38 000F0D78  7C 00 F3 78 */	or r0, r0, r30
/* 800F3E3C 000F0D7C  90 0D 8F FC */	stw r0, RecalibrateBits@sda21(r13)
.L_800F3E40:
/* 800F3E40 000F0D80  48 00 1E 19 */	bl SIDisablePolling
/* 800F3E44 000F0D84  80 0D 83 84 */	lwz r0, ResettingChan@sda21(r13)
/* 800F3E48 000F0D88  2C 00 00 20 */	cmpwi r0, 0x20
/* 800F3E4C 000F0D8C  40 82 00 58 */	bne .L_800F3EA4
/* 800F3E50 000F0D90  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F3E54 000F0D94  7C A0 00 34 */	cntlzw r0, r5
/* 800F3E58 000F0D98  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F3E5C 000F0D9C  80 8D 83 84 */	lwz r4, ResettingChan@sda21(r13)
/* 800F3E60 000F0DA0  2C 04 00 20 */	cmpwi r4, 0x20
/* 800F3E64 000F0DA4  41 82 00 40 */	beq .L_800F3EA4
/* 800F3E68 000F0DA8  3C 00 80 00 */	lis r0, 0x8000
/* 800F3E6C 000F0DAC  7C 00 24 30 */	srw r0, r0, r4
/* 800F3E70 000F0DB0  7C A0 00 78 */	andc r0, r5, r0
/* 800F3E74 000F0DB4  1C 84 00 0C */	mulli r4, r4, 0xc
/* 800F3E78 000F0DB8  90 0D 8F F8 */	stw r0, ResettingBits@sda21(r13)
/* 800F3E7C 000F0DBC  3C 60 80 4F */	lis r3, Origin@ha
/* 800F3E80 000F0DC0  38 03 71 40 */	addi r0, r3, Origin@l
/* 800F3E84 000F0DC4  7C 60 22 14 */	add r3, r0, r4
/* 800F3E88 000F0DC8  38 80 00 00 */	li r4, 0
/* 800F3E8C 000F0DCC  38 A0 00 0C */	li r5, 0xc
/* 800F3E90 000F0DD0  4B F1 12 25 */	bl memset
/* 800F3E94 000F0DD4  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3E98 000F0DD8  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3E9C 000F0DDC  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3EA0 000F0DE0  48 00 26 11 */	bl SIGetTypeAsync
.L_800F3EA4:
/* 800F3EA4 000F0DE4  7F E3 FB 78 */	mr r3, r31
/* 800F3EA8 000F0DE8  4B FF AD B9 */	bl OSRestoreInterrupts
/* 800F3EAC 000F0DEC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F3EB0 000F0DF0  38 60 00 01 */	li r3, 1
/* 800F3EB4 000F0DF4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F3EB8 000F0DF8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F3EBC 000F0DFC  38 21 00 18 */	addi r1, r1, 0x18
/* 800F3EC0 000F0E00  7C 08 03 A6 */	mtlr r0
/* 800F3EC4 000F0E04  4E 80 00 20 */	blr 
.endfn PADReset

.fn PADRecalibrate, global
/* 800F3EC8 000F0E08  7C 08 02 A6 */	mflr r0
/* 800F3ECC 000F0E0C  90 01 00 04 */	stw r0, 4(r1)
/* 800F3ED0 000F0E10  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F3ED4 000F0E14  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F3ED8 000F0E18  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F3EDC 000F0E1C  7C 7E 1B 78 */	mr r30, r3
/* 800F3EE0 000F0E20  4B FF AD 59 */	bl OSDisableInterrupts
/* 800F3EE4 000F0E24  80 AD 90 08 */	lwz r5, PendingBits@sda21(r13)
/* 800F3EE8 000F0E28  39 00 00 00 */	li r8, 0
/* 800F3EEC 000F0E2C  80 CD 90 00 */	lwz r6, WaitingBits@sda21(r13)
/* 800F3EF0 000F0E30  3C 80 80 00 */	lis r4, 0x800030E3@ha
/* 800F3EF4 000F0E34  80 0D 90 04 */	lwz r0, CheckingBits@sda21(r13)
/* 800F3EF8 000F0E38  7F DE 2B 78 */	or r30, r30, r5
/* 800F3EFC 000F0E3C  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F3F00 000F0E40  7C C6 03 78 */	or r6, r6, r0
/* 800F3F04 000F0E44  88 04 30 E3 */	lbz r0, 0x800030E3@l(r4)
/* 800F3F08 000F0E48  7F DE 30 78 */	andc r30, r30, r6
/* 800F3F0C 000F0E4C  80 CD 8F F4 */	lwz r6, EnabledBits@sda21(r13)
/* 800F3F10 000F0E50  7C A5 F3 78 */	or r5, r5, r30
/* 800F3F14 000F0E54  80 8D 90 0C */	lwz r4, BarrelBits@sda21(r13)
/* 800F3F18 000F0E58  90 AD 8F F8 */	stw r5, ResettingBits@sda21(r13)
/* 800F3F1C 000F0E5C  7F C9 F0 F8 */	nor r9, r30, r30
/* 800F3F20 000F0E60  7C C5 48 38 */	and r5, r6, r9
/* 800F3F24 000F0E64  7C 84 48 38 */	and r4, r4, r9
/* 800F3F28 000F0E68  80 ED 8F F8 */	lwz r7, ResettingBits@sda21(r13)
/* 800F3F2C 000F0E6C  7C 7F 1B 78 */	mr r31, r3
/* 800F3F30 000F0E70  91 0D 90 08 */	stw r8, PendingBits@sda21(r13)
/* 800F3F34 000F0E74  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 800F3F38 000F0E78  90 AD 8F F4 */	stw r5, EnabledBits@sda21(r13)
/* 800F3F3C 000F0E7C  7C E3 30 38 */	and r3, r7, r6
/* 800F3F40 000F0E80  90 8D 90 0C */	stw r4, BarrelBits@sda21(r13)
/* 800F3F44 000F0E84  40 82 00 10 */	bne .L_800F3F54
/* 800F3F48 000F0E88  80 0D 8F FC */	lwz r0, RecalibrateBits@sda21(r13)
/* 800F3F4C 000F0E8C  7C 00 F3 78 */	or r0, r0, r30
/* 800F3F50 000F0E90  90 0D 8F FC */	stw r0, RecalibrateBits@sda21(r13)
.L_800F3F54:
/* 800F3F54 000F0E94  48 00 1D 05 */	bl SIDisablePolling
/* 800F3F58 000F0E98  80 0D 83 84 */	lwz r0, ResettingChan@sda21(r13)
/* 800F3F5C 000F0E9C  2C 00 00 20 */	cmpwi r0, 0x20
/* 800F3F60 000F0EA0  40 82 00 58 */	bne .L_800F3FB8
/* 800F3F64 000F0EA4  80 AD 8F F8 */	lwz r5, ResettingBits@sda21(r13)
/* 800F3F68 000F0EA8  7C A0 00 34 */	cntlzw r0, r5
/* 800F3F6C 000F0EAC  90 0D 83 84 */	stw r0, ResettingChan@sda21(r13)
/* 800F3F70 000F0EB0  80 8D 83 84 */	lwz r4, ResettingChan@sda21(r13)
/* 800F3F74 000F0EB4  2C 04 00 20 */	cmpwi r4, 0x20
/* 800F3F78 000F0EB8  41 82 00 40 */	beq .L_800F3FB8
/* 800F3F7C 000F0EBC  3C 00 80 00 */	lis r0, 0x8000
/* 800F3F80 000F0EC0  7C 00 24 30 */	srw r0, r0, r4
/* 800F3F84 000F0EC4  7C A0 00 78 */	andc r0, r5, r0
/* 800F3F88 000F0EC8  1C 84 00 0C */	mulli r4, r4, 0xc
/* 800F3F8C 000F0ECC  90 0D 8F F8 */	stw r0, ResettingBits@sda21(r13)
/* 800F3F90 000F0ED0  3C 60 80 4F */	lis r3, Origin@ha
/* 800F3F94 000F0ED4  38 03 71 40 */	addi r0, r3, Origin@l
/* 800F3F98 000F0ED8  7C 60 22 14 */	add r3, r0, r4
/* 800F3F9C 000F0EDC  38 80 00 00 */	li r4, 0
/* 800F3FA0 000F0EE0  38 A0 00 0C */	li r5, 0xc
/* 800F3FA4 000F0EE4  4B F1 11 11 */	bl memset
/* 800F3FA8 000F0EE8  3C 80 80 0F */	lis r4, PADTypeAndStatusCallback@ha
/* 800F3FAC 000F0EEC  80 6D 83 84 */	lwz r3, ResettingChan@sda21(r13)
/* 800F3FB0 000F0EF0  38 84 39 4C */	addi r4, r4, PADTypeAndStatusCallback@l
/* 800F3FB4 000F0EF4  48 00 24 FD */	bl SIGetTypeAsync
.L_800F3FB8:
/* 800F3FB8 000F0EF8  7F E3 FB 78 */	mr r3, r31
/* 800F3FBC 000F0EFC  4B FF AC A5 */	bl OSRestoreInterrupts
/* 800F3FC0 000F0F00  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F3FC4 000F0F04  38 60 00 01 */	li r3, 1
/* 800F3FC8 000F0F08  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F3FCC 000F0F0C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F3FD0 000F0F10  38 21 00 18 */	addi r1, r1, 0x18
/* 800F3FD4 000F0F14  7C 08 03 A6 */	mtlr r0
/* 800F3FD8 000F0F18  4E 80 00 20 */	blr 
.endfn PADRecalibrate

.fn PADInit, global
/* 800F3FDC 000F0F1C  7C 08 02 A6 */	mflr r0
/* 800F3FE0 000F0F20  3C 60 80 4F */	lis r3, Type@ha
/* 800F3FE4 000F0F24  90 01 00 04 */	stw r0, 4(r1)
/* 800F3FE8 000F0F28  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800F3FEC 000F0F2C  BF 21 00 1C */	stmw r25, 0x1c(r1)
/* 800F3FF0 000F0F30  3B E3 71 30 */	addi r31, r3, Type@l
/* 800F3FF4 000F0F34  80 0D 8F F0 */	lwz r0, Initialized@sda21(r13)
/* 800F3FF8 000F0F38  2C 00 00 00 */	cmpwi r0, 0
/* 800F3FFC 000F0F3C  41 82 00 0C */	beq .L_800F4008
/* 800F4000 000F0F40  38 60 00 01 */	li r3, 1
/* 800F4004 000F0F44  48 00 01 14 */	b .L_800F4118
.L_800F4008:
/* 800F4008 000F0F48  80 6D 83 80 */	lwz r3, __PADVersion@sda21(r13)
/* 800F400C 000F0F4C  4B FF 7A 7D */	bl OSRegisterVersion
/* 800F4010 000F0F50  80 6D 90 18 */	lwz r3, __PADSpec@sda21(r13)
/* 800F4014 000F0F54  28 03 00 00 */	cmplwi r3, 0
/* 800F4018 000F0F58  41 82 00 08 */	beq .L_800F4020
/* 800F401C 000F0F5C  48 00 04 C9 */	bl PADSetSpec
.L_800F4020:
/* 800F4020 000F0F60  80 0D 90 28 */	lwz r0, __PADFixBits@sda21(r13)
/* 800F4024 000F0F64  38 60 00 01 */	li r3, 1
/* 800F4028 000F0F68  90 6D 8F F0 */	stw r3, Initialized@sda21(r13)
/* 800F402C 000F0F6C  28 00 00 00 */	cmplwi r0, 0
/* 800F4030 000F0F70  41 82 00 8C */	beq .L_800F40BC
/* 800F4034 000F0F74  4B FF EB 5D */	bl OSGetTime
/* 800F4038 000F0F78  3B 24 00 00 */	addi r25, r4, 0
/* 800F403C 000F0F7C  3B 43 00 00 */	addi r26, r3, 0
/* 800F4040 000F0F80  38 A0 00 10 */	li r5, 0x10
/* 800F4044 000F0F84  4B FC E0 F1 */	bl __shr2i
/* 800F4048 000F0F88  3C A0 00 01 */	lis r5, 0x0000FFFF@ha
/* 800F404C 000F0F8C  3B 65 FF FF */	addi r27, r5, 0x0000FFFF@l
/* 800F4050 000F0F90  3B 80 00 00 */	li r28, 0
/* 800F4054 000F0F94  7C 86 D8 38 */	and r6, r4, r27
/* 800F4058 000F0F98  7F 24 D8 38 */	and r4, r25, r27
/* 800F405C 000F0F9C  7C 65 E0 38 */	and r5, r3, r28
/* 800F4060 000F0FA0  7F 40 E0 38 */	and r0, r26, r28
/* 800F4064 000F0FA4  7F A4 30 14 */	addc r29, r4, r6
/* 800F4068 000F0FA8  38 7A 00 00 */	addi r3, r26, 0
/* 800F406C 000F0FAC  38 99 00 00 */	addi r4, r25, 0
/* 800F4070 000F0FB0  7F C0 29 14 */	adde r30, r0, r5
/* 800F4074 000F0FB4  38 A0 00 20 */	li r5, 0x20
/* 800F4078 000F0FB8  4B FC E0 BD */	bl __shr2i
/* 800F407C 000F0FBC  7C 84 D8 38 */	and r4, r4, r27
/* 800F4080 000F0FC0  7C 60 E0 38 */	and r0, r3, r28
/* 800F4084 000F0FC4  7F A4 E8 14 */	addc r29, r4, r29
/* 800F4088 000F0FC8  38 7A 00 00 */	addi r3, r26, 0
/* 800F408C 000F0FCC  38 99 00 00 */	addi r4, r25, 0
/* 800F4090 000F0FD0  7F C0 F1 14 */	adde r30, r0, r30
/* 800F4094 000F0FD4  38 A0 00 30 */	li r5, 0x30
/* 800F4098 000F0FD8  4B FC E0 9D */	bl __shr2i
/* 800F409C 000F0FDC  7C 80 D8 38 */	and r0, r4, r27
/* 800F40A0 000F0FE0  7C A0 E8 14 */	addc r5, r0, r29
/* 800F40A4 000F0FE4  3C 00 F0 00 */	lis r0, 0xf000
/* 800F40A8 000F0FE8  38 80 3F FF */	li r4, 0x3fff
/* 800F40AC 000F0FEC  90 0D 8F FC */	stw r0, RecalibrateBits@sda21(r13)
/* 800F40B0 000F0FF0  7C A0 20 38 */	and r0, r5, r4
/* 800F40B4 000F0FF4  3C 60 80 00 */	lis r3, 0x800030E0@ha
/* 800F40B8 000F0FF8  B0 03 30 E0 */	sth r0, 0x800030E0@l(r3)
.L_800F40BC:
/* 800F40BC 000F0FFC  3C 60 80 00 */	lis r3, 0x800030E0@ha
/* 800F40C0 000F1000  A0 03 30 E0 */	lhz r0, 0x800030E0@l(r3)
/* 800F40C4 000F1004  54 00 42 AE */	rlwinm r0, r0, 8, 0xa, 0x17
/* 800F40C8 000F1008  64 00 4D 00 */	oris r0, r0, 0x4d00
/* 800F40CC 000F100C  90 1F 00 40 */	stw r0, 0x40(r31)
/* 800F40D0 000F1010  A0 03 30 E0 */	lhz r0, 0x30e0(r3)
/* 800F40D4 000F1014  54 00 42 AE */	rlwinm r0, r0, 8, 0xa, 0x17
/* 800F40D8 000F1018  64 00 4D 40 */	oris r0, r0, 0x4d40
/* 800F40DC 000F101C  90 1F 00 44 */	stw r0, 0x44(r31)
/* 800F40E0 000F1020  A0 03 30 E0 */	lhz r0, 0x30e0(r3)
/* 800F40E4 000F1024  54 00 42 AE */	rlwinm r0, r0, 8, 0xa, 0x17
/* 800F40E8 000F1028  64 00 4D 80 */	oris r0, r0, 0x4d80
/* 800F40EC 000F102C  90 1F 00 48 */	stw r0, 0x48(r31)
/* 800F40F0 000F1030  A0 03 30 E0 */	lhz r0, 0x30e0(r3)
/* 800F40F4 000F1034  54 00 42 AE */	rlwinm r0, r0, 8, 0xa, 0x17
/* 800F40F8 000F1038  64 00 4D C0 */	oris r0, r0, 0x4dc0
/* 800F40FC 000F103C  90 1F 00 4C */	stw r0, 0x4c(r31)
/* 800F4100 000F1040  48 00 27 41 */	bl SIRefreshSamplingRate
/* 800F4104 000F1044  3C 60 80 4B */	lis r3, ResetFunctionInfo@ha
/* 800F4108 000F1048  38 63 9E A8 */	addi r3, r3, ResetFunctionInfo@l
/* 800F410C 000F104C  4B FF C1 99 */	bl OSRegisterResetFunction
/* 800F4110 000F1050  3C 60 F0 00 */	lis r3, 0xf000
/* 800F4114 000F1054  4B FF FC A5 */	bl PADReset
.L_800F4118:
/* 800F4118 000F1058  BB 21 00 1C */	lmw r25, 0x1c(r1)
/* 800F411C 000F105C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800F4120 000F1060  38 21 00 38 */	addi r1, r1, 0x38
/* 800F4124 000F1064  7C 08 03 A6 */	mtlr r0
/* 800F4128 000F1068  4E 80 00 20 */	blr 
.endfn PADInit

.fn PADRead, global
/* 800F412C 000F106C  7C 08 02 A6 */	mflr r0
/* 800F4130 000F1070  90 01 00 04 */	stw r0, 4(r1)
/* 800F4134 000F1074  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800F4138 000F1078  BE C1 00 18 */	stmw r22, 0x18(r1)
/* 800F413C 000F107C  7C 77 1B 78 */	mr r23, r3
/* 800F4140 000F1080  4B FF AA F9 */	bl OSDisableInterrupts
/* 800F4144 000F1084  3B 20 00 00 */	li r25, 0
/* 800F4148 000F1088  1C B9 00 0C */	mulli r5, r25, 0xc
/* 800F414C 000F108C  3C 80 80 4F */	lis r4, Origin@ha
/* 800F4150 000F1090  38 04 71 40 */	addi r0, r4, Origin@l
/* 800F4154 000F1094  7F 80 2A 14 */	add r28, r0, r5
/* 800F4158 000F1098  3C 80 80 0F */	lis r4, PADOriginUpdateCallback@ha
/* 800F415C 000F109C  3C A0 80 0F */	lis r5, PADReceiveCheckCallback@ha
/* 800F4160 000F10A0  3B 43 00 00 */	addi r26, r3, 0
/* 800F4164 000F10A4  3A C4 37 A8 */	addi r22, r4, PADOriginUpdateCallback@l
/* 800F4168 000F10A8  3B E5 3C 78 */	addi r31, r5, PADReceiveCheckCallback@l
/* 800F416C 000F10AC  3B 00 00 00 */	li r24, 0
/* 800F4170 000F10B0  3F C0 80 00 */	lis r30, 0x8000
.L_800F4174:
/* 800F4174 000F10B4  80 0D 90 08 */	lwz r0, PendingBits@sda21(r13)
/* 800F4178 000F10B8  7F DB CC 30 */	srw r27, r30, r25
/* 800F417C 000F10BC  7C 00 D8 39 */	and. r0, r0, r27
/* 800F4180 000F10C0  41 82 00 28 */	beq .L_800F41A8
/* 800F4184 000F10C4  38 60 00 00 */	li r3, 0
/* 800F4188 000F10C8  4B FF FC 31 */	bl PADReset
/* 800F418C 000F10CC  38 00 FF FE */	li r0, -2
/* 800F4190 000F10D0  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F4194 000F10D4  38 77 00 00 */	addi r3, r23, 0
/* 800F4198 000F10D8  38 80 00 00 */	li r4, 0
/* 800F419C 000F10DC  38 A0 00 0A */	li r5, 0xa
/* 800F41A0 000F10E0  4B F1 0F 15 */	bl memset
/* 800F41A4 000F10E4  48 00 02 54 */	b .L_800F43F8
.L_800F41A8:
/* 800F41A8 000F10E8  80 0D 8F F8 */	lwz r0, ResettingBits@sda21(r13)
/* 800F41AC 000F10EC  7C 00 D8 39 */	and. r0, r0, r27
/* 800F41B0 000F10F0  40 82 00 10 */	bne .L_800F41C0
/* 800F41B4 000F10F4  80 0D 83 84 */	lwz r0, ResettingChan@sda21(r13)
/* 800F41B8 000F10F8  7C 00 C8 00 */	cmpw r0, r25
/* 800F41BC 000F10FC  40 82 00 20 */	bne .L_800F41DC
.L_800F41C0:
/* 800F41C0 000F1100  38 00 FF FE */	li r0, -2
/* 800F41C4 000F1104  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F41C8 000F1108  38 77 00 00 */	addi r3, r23, 0
/* 800F41CC 000F110C  38 80 00 00 */	li r4, 0
/* 800F41D0 000F1110  38 A0 00 0A */	li r5, 0xa
/* 800F41D4 000F1114  4B F1 0E E1 */	bl memset
/* 800F41D8 000F1118  48 00 02 20 */	b .L_800F43F8
.L_800F41DC:
/* 800F41DC 000F111C  80 0D 8F F4 */	lwz r0, EnabledBits@sda21(r13)
/* 800F41E0 000F1120  7C 00 D8 39 */	and. r0, r0, r27
/* 800F41E4 000F1124  40 82 00 20 */	bne .L_800F4204
/* 800F41E8 000F1128  38 00 FF FF */	li r0, -1
/* 800F41EC 000F112C  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F41F0 000F1130  38 77 00 00 */	addi r3, r23, 0
/* 800F41F4 000F1134  38 80 00 00 */	li r4, 0
/* 800F41F8 000F1138  38 A0 00 0A */	li r5, 0xa
/* 800F41FC 000F113C  4B F1 0E B9 */	bl memset
/* 800F4200 000F1140  48 00 01 F8 */	b .L_800F43F8
.L_800F4204:
/* 800F4204 000F1144  7F 23 CB 78 */	mr r3, r25
/* 800F4208 000F1148  48 00 0D 15 */	bl SIIsChanBusy
/* 800F420C 000F114C  2C 03 00 00 */	cmpwi r3, 0
/* 800F4210 000F1150  41 82 00 20 */	beq .L_800F4230
/* 800F4214 000F1154  38 00 FF FD */	li r0, -3
/* 800F4218 000F1158  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F421C 000F115C  38 77 00 00 */	addi r3, r23, 0
/* 800F4220 000F1160  38 80 00 00 */	li r4, 0
/* 800F4224 000F1164  38 A0 00 0A */	li r5, 0xa
/* 800F4228 000F1168  4B F1 0E 8D */	bl memset
/* 800F422C 000F116C  48 00 01 CC */	b .L_800F43F8
.L_800F4230:
/* 800F4230 000F1170  7F 23 CB 78 */	mr r3, r25
/* 800F4234 000F1174  48 00 18 7D */	bl SIGetStatus
/* 800F4238 000F1178  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 800F423C 000F117C  41 82 00 D8 */	beq .L_800F4314
/* 800F4240 000F1180  38 79 00 00 */	addi r3, r25, 0
/* 800F4244 000F1184  38 81 00 10 */	addi r4, r1, 0x10
/* 800F4248 000F1188  48 00 1B 51 */	bl SIGetResponse
/* 800F424C 000F118C  80 0D 90 00 */	lwz r0, WaitingBits@sda21(r13)
/* 800F4250 000F1190  7C 00 D8 39 */	and. r0, r0, r27
/* 800F4254 000F1194  41 82 00 40 */	beq .L_800F4294
/* 800F4258 000F1198  38 00 00 00 */	li r0, 0
/* 800F425C 000F119C  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F4260 000F11A0  38 77 00 00 */	addi r3, r23, 0
/* 800F4264 000F11A4  38 80 00 00 */	li r4, 0
/* 800F4268 000F11A8  38 A0 00 0A */	li r5, 0xa
/* 800F426C 000F11AC  4B F1 0E 49 */	bl memset
/* 800F4270 000F11B0  80 6D 90 04 */	lwz r3, CheckingBits@sda21(r13)
/* 800F4274 000F11B4  7C 60 D8 39 */	and. r0, r3, r27
/* 800F4278 000F11B8  40 82 01 80 */	bne .L_800F43F8
/* 800F427C 000F11BC  7C 60 DB 78 */	or r0, r3, r27
/* 800F4280 000F11C0  90 0D 90 04 */	stw r0, CheckingBits@sda21(r13)
/* 800F4284 000F11C4  38 79 00 00 */	addi r3, r25, 0
/* 800F4288 000F11C8  38 9F 00 00 */	addi r4, r31, 0
/* 800F428C 000F11CC  48 00 22 25 */	bl SIGetTypeAsync
/* 800F4290 000F11D0  48 00 01 68 */	b .L_800F43F8
.L_800F4294:
/* 800F4294 000F11D4  4B FF A9 A5 */	bl OSDisableInterrupts
/* 800F4298 000F11D8  3B A3 00 00 */	addi r29, r3, 0
/* 800F429C 000F11DC  38 7B 00 00 */	addi r3, r27, 0
/* 800F42A0 000F11E0  48 00 19 B9 */	bl SIDisablePolling
/* 800F42A4 000F11E4  80 0D 8F F4 */	lwz r0, EnabledBits@sda21(r13)
/* 800F42A8 000F11E8  7F 69 D8 F8 */	nor r9, r27, r27
/* 800F42AC 000F11EC  80 CD 90 00 */	lwz r6, WaitingBits@sda21(r13)
/* 800F42B0 000F11F0  7F 23 CB 78 */	mr r3, r25
/* 800F42B4 000F11F4  80 AD 90 04 */	lwz r5, CheckingBits@sda21(r13)
/* 800F42B8 000F11F8  80 8D 90 08 */	lwz r4, PendingBits@sda21(r13)
/* 800F42BC 000F11FC  7C 08 48 38 */	and r8, r0, r9
/* 800F42C0 000F1200  80 0D 90 0C */	lwz r0, BarrelBits@sda21(r13)
/* 800F42C4 000F1204  7C C7 48 38 */	and r7, r6, r9
/* 800F42C8 000F1208  7C A6 48 38 */	and r6, r5, r9
/* 800F42CC 000F120C  7C 85 48 38 */	and r5, r4, r9
/* 800F42D0 000F1210  91 0D 8F F4 */	stw r8, EnabledBits@sda21(r13)
/* 800F42D4 000F1214  7C 00 48 38 */	and r0, r0, r9
/* 800F42D8 000F1218  90 ED 90 00 */	stw r7, WaitingBits@sda21(r13)
/* 800F42DC 000F121C  38 80 00 00 */	li r4, 0
/* 800F42E0 000F1220  90 CD 90 04 */	stw r6, CheckingBits@sda21(r13)
/* 800F42E4 000F1224  90 AD 90 08 */	stw r5, PendingBits@sda21(r13)
/* 800F42E8 000F1228  90 0D 90 0C */	stw r0, BarrelBits@sda21(r13)
/* 800F42EC 000F122C  4B FF D3 15 */	bl OSSetWirelessID
/* 800F42F0 000F1230  7F A3 EB 78 */	mr r3, r29
/* 800F42F4 000F1234  4B FF A9 6D */	bl OSRestoreInterrupts
/* 800F42F8 000F1238  38 00 FF FF */	li r0, -1
/* 800F42FC 000F123C  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F4300 000F1240  38 77 00 00 */	addi r3, r23, 0
/* 800F4304 000F1244  38 80 00 00 */	li r4, 0
/* 800F4308 000F1248  38 A0 00 0A */	li r5, 0xa
/* 800F430C 000F124C  4B F1 0D A9 */	bl memset
/* 800F4310 000F1250  48 00 00 E8 */	b .L_800F43F8
.L_800F4314:
/* 800F4314 000F1254  7F 23 CB 78 */	mr r3, r25
/* 800F4318 000F1258  48 00 1F D5 */	bl SIGetType
/* 800F431C 000F125C  54 60 00 85 */	rlwinm. r0, r3, 0, 2, 2
/* 800F4320 000F1260  40 82 00 08 */	bne .L_800F4328
/* 800F4324 000F1264  7F 18 DB 78 */	or r24, r24, r27
.L_800F4328:
/* 800F4328 000F1268  38 79 00 00 */	addi r3, r25, 0
/* 800F432C 000F126C  38 81 00 10 */	addi r4, r1, 0x10
/* 800F4330 000F1270  48 00 1A 69 */	bl SIGetResponse
/* 800F4334 000F1274  2C 03 00 00 */	cmpwi r3, 0
/* 800F4338 000F1278  40 82 00 20 */	bne .L_800F4358
/* 800F433C 000F127C  38 00 FF FD */	li r0, -3
/* 800F4340 000F1280  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F4344 000F1284  38 77 00 00 */	addi r3, r23, 0
/* 800F4348 000F1288  38 80 00 00 */	li r4, 0
/* 800F434C 000F128C  38 A0 00 0A */	li r5, 0xa
/* 800F4350 000F1290  4B F1 0D 65 */	bl memset
/* 800F4354 000F1294  48 00 00 A4 */	b .L_800F43F8
.L_800F4358:
/* 800F4358 000F1298  80 01 00 10 */	lwz r0, 0x10(r1)
/* 800F435C 000F129C  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 800F4360 000F12A0  41 82 00 20 */	beq .L_800F4380
/* 800F4364 000F12A4  38 00 FF FD */	li r0, -3
/* 800F4368 000F12A8  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F436C 000F12AC  38 77 00 00 */	addi r3, r23, 0
/* 800F4370 000F12B0  38 80 00 00 */	li r4, 0
/* 800F4374 000F12B4  38 A0 00 0A */	li r5, 0xa
/* 800F4378 000F12B8  4B F1 0D 3D */	bl memset
/* 800F437C 000F12BC  48 00 00 7C */	b .L_800F43F8
.L_800F4380:
/* 800F4380 000F12C0  81 8D 83 94 */	lwz r12, MakeStatus@sda21(r13)
/* 800F4384 000F12C4  38 79 00 00 */	addi r3, r25, 0
/* 800F4388 000F12C8  38 97 00 00 */	addi r4, r23, 0
/* 800F438C 000F12CC  7D 88 03 A6 */	mtlr r12
/* 800F4390 000F12D0  38 A1 00 10 */	addi r5, r1, 0x10
/* 800F4394 000F12D4  4E 80 00 21 */	blrl 
/* 800F4398 000F12D8  A0 17 00 00 */	lhz r0, 0(r23)
/* 800F439C 000F12DC  54 00 04 A5 */	rlwinm. r0, r0, 0, 0x12, 0x12
/* 800F43A0 000F12E0  41 82 00 44 */	beq .L_800F43E4
/* 800F43A4 000F12E4  38 00 FF FD */	li r0, -3
/* 800F43A8 000F12E8  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F43AC 000F12EC  38 77 00 00 */	addi r3, r23, 0
/* 800F43B0 000F12F0  38 80 00 00 */	li r4, 0
/* 800F43B4 000F12F4  38 A0 00 0A */	li r5, 0xa
/* 800F43B8 000F12F8  4B F1 0C FD */	bl memset
/* 800F43BC 000F12FC  38 79 00 00 */	addi r3, r25, 0
/* 800F43C0 000F1300  38 DC 00 00 */	addi r6, r28, 0
/* 800F43C4 000F1304  39 16 00 00 */	addi r8, r22, 0
/* 800F43C8 000F1308  38 8D 83 98 */	addi r4, r13, CmdReadOrigin@sda21
/* 800F43CC 000F130C  38 A0 00 01 */	li r5, 1
/* 800F43D0 000F1310  38 E0 00 0A */	li r7, 0xa
/* 800F43D4 000F1314  39 40 00 00 */	li r10, 0
/* 800F43D8 000F1318  39 20 00 00 */	li r9, 0
/* 800F43DC 000F131C  48 00 1B 0D */	bl SITransfer
/* 800F43E0 000F1320  48 00 00 18 */	b .L_800F43F8
.L_800F43E4:
/* 800F43E4 000F1324  38 00 00 00 */	li r0, 0
/* 800F43E8 000F1328  98 17 00 0A */	stb r0, 0xa(r23)
/* 800F43EC 000F132C  A0 17 00 00 */	lhz r0, 0(r23)
/* 800F43F0 000F1330  54 00 06 6E */	rlwinm r0, r0, 0, 0x19, 0x17
/* 800F43F4 000F1334  B0 17 00 00 */	sth r0, 0(r23)
.L_800F43F8:
/* 800F43F8 000F1338  3B 39 00 01 */	addi r25, r25, 1
/* 800F43FC 000F133C  2C 19 00 04 */	cmpwi r25, 4
/* 800F4400 000F1340  3B 9C 00 0C */	addi r28, r28, 0xc
/* 800F4404 000F1344  3A F7 00 0C */	addi r23, r23, 0xc
/* 800F4408 000F1348  41 80 FD 6C */	blt .L_800F4174
/* 800F440C 000F134C  7F 43 D3 78 */	mr r3, r26
/* 800F4410 000F1350  4B FF A8 51 */	bl OSRestoreInterrupts
/* 800F4414 000F1354  7F 03 C3 78 */	mr r3, r24
/* 800F4418 000F1358  BA C1 00 18 */	lmw r22, 0x18(r1)
/* 800F441C 000F135C  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800F4420 000F1360  38 21 00 40 */	addi r1, r1, 0x40
/* 800F4424 000F1364  7C 08 03 A6 */	mtlr r0
/* 800F4428 000F1368  4E 80 00 20 */	blr 
.endfn PADRead

.fn PADControlMotor, global
/* 800F442C 000F136C  7C 08 02 A6 */	mflr r0
/* 800F4430 000F1370  90 01 00 04 */	stw r0, 4(r1)
/* 800F4434 000F1374  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800F4438 000F1378  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800F443C 000F137C  93 C1 00 20 */	stw r30, 0x20(r1)
li r4, 4
/* 800F4440 000F1380  3B C4 00 00 */	addi r30, r4, 0
/* 800F4444 000F1384  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800F4448 000F1388  3B A3 00 00 */	addi r29, r3, 0
/* 800F444C 000F138C  4B FF A7 ED */	bl OSDisableInterrupts
/* 800F4450 000F1390  3C 00 80 00 */	lis r0, 0x8000
/* 800F4454 000F1394  80 8D 8F F4 */	lwz r4, EnabledBits@sda21(r13)
/* 800F4458 000F1398  7C 00 EC 30 */	srw r0, r0, r29
/* 800F445C 000F139C  7C 80 00 39 */	and. r0, r4, r0
/* 800F4460 000F13A0  3B E3 00 00 */	addi r31, r3, 0
/* 800F4464 000F13A4  41 82 00 5C */	beq .L_800F44C0
/* 800F4468 000F13A8  7F A3 EB 78 */	mr r3, r29
/* 800F446C 000F13AC  48 00 1E 81 */	bl SIGetType
/* 800F4470 000F13B0  54 60 00 85 */	rlwinm. r0, r3, 0, 2, 2
/* 800F4474 000F13B4  40 82 00 4C */	bne .L_800F44C0
/* 800F4478 000F13B8  80 0D 83 90 */	lwz r0, Spec@sda21(r13)
/* 800F447C 000F13BC  28 00 00 02 */	cmplwi r0, 2
/* 800F4480 000F13C0  40 80 00 10 */	bge .L_800F4490
/* 800F4484 000F13C4  28 1E 00 02 */	cmplwi r30, 2
/* 800F4488 000F13C8  40 82 00 08 */	bne .L_800F4490
/* 800F448C 000F13CC  3B C0 00 00 */	li r30, 0
.L_800F4490:
/* 800F4490 000F13D0  3C 60 80 00 */	lis r3, 0x800030E3@ha
/* 800F4494 000F13D4  88 03 30 E3 */	lbz r0, 0x800030E3@l(r3)
/* 800F4498 000F13D8  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 800F449C 000F13DC  41 82 00 08 */	beq .L_800F44A4
/* 800F44A0 000F13E0  3B C0 00 00 */	li r30, 0
.L_800F44A4:
/* 800F44A4 000F13E4  80 8D 83 8C */	lwz r4, AnalogMode@sda21(r13)
/* 800F44A8 000F13E8  57 C0 07 BE */	clrlwi r0, r30, 0x1e
/* 800F44AC 000F13EC  38 7D 00 00 */	addi r3, r29, 0
/* 800F44B0 000F13F0  64 84 00 40 */	oris r4, r4, 0x40
/* 800F44B4 000F13F4  7C 84 03 78 */	or r4, r4, r0
/* 800F44B8 000F13F8  48 00 16 75 */	bl SISetCommand
/* 800F44BC 000F13FC  48 00 16 85 */	bl SITransferCommands
.L_800F44C0:
/* 800F44C0 000F1400  7F E3 FB 78 */	mr r3, r31
/* 800F44C4 000F1404  4B FF A7 9D */	bl OSRestoreInterrupts
/* 800F44C8 000F1408  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800F44CC 000F140C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800F44D0 000F1410  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800F44D4 000F1414  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800F44D8 000F1418  38 21 00 28 */	addi r1, r1, 0x28
/* 800F44DC 000F141C  7C 08 03 A6 */	mtlr r0
/* 800F44E0 000F1420  4E 80 00 20 */	blr 
.endfn PADControlMotor

.fn PADSetSpec, global
/* 800F44E4 000F1424  38 00 00 00 */	li r0, 0
/* 800F44E8 000F1428  2C 03 00 01 */	cmpwi r3, 1
/* 800F44EC 000F142C  90 0D 90 18 */	stw r0, __PADSpec@sda21(r13)
/* 800F44F0 000F1430  41 82 00 30 */	beq .L_800F4520
/* 800F44F4 000F1434  40 80 00 10 */	bge .L_800F4504
/* 800F44F8 000F1438  2C 03 00 00 */	cmpwi r3, 0
/* 800F44FC 000F143C  40 80 00 14 */	bge .L_800F4510
/* 800F4500 000F1440  48 00 00 3C */	b .L_800F453C
.L_800F4504:
/* 800F4504 000F1444  2C 03 00 06 */	cmpwi r3, 6
/* 800F4508 000F1448  40 80 00 34 */	bge .L_800F453C
/* 800F450C 000F144C  48 00 00 24 */	b .L_800F4530
.L_800F4510:
/* 800F4510 000F1450  3C 80 80 0F */	lis r4, SPEC0_MakeStatus@ha
/* 800F4514 000F1454  38 04 45 44 */	addi r0, r4, SPEC0_MakeStatus@l
/* 800F4518 000F1458  90 0D 83 94 */	stw r0, MakeStatus@sda21(r13)
/* 800F451C 000F145C  48 00 00 20 */	b .L_800F453C
.L_800F4520:
/* 800F4520 000F1460  3C 80 80 0F */	lis r4, SPEC1_MakeStatus@ha
/* 800F4524 000F1464  38 04 46 B8 */	addi r0, r4, SPEC1_MakeStatus@l
/* 800F4528 000F1468  90 0D 83 94 */	stw r0, MakeStatus@sda21(r13)
/* 800F452C 000F146C  48 00 00 10 */	b .L_800F453C
.L_800F4530:
/* 800F4530 000F1470  3C 80 80 0F */	lis r4, SPEC2_MakeStatus@ha
/* 800F4534 000F1474  38 04 48 2C */	addi r0, r4, SPEC2_MakeStatus@l
/* 800F4538 000F1478  90 0D 83 94 */	stw r0, MakeStatus@sda21(r13)
.L_800F453C:
/* 800F453C 000F147C  90 6D 83 90 */	stw r3, Spec@sda21(r13)
/* 800F4540 000F1480  4E 80 00 20 */	blr 
.endfn PADSetSpec

.fn SPEC0_MakeStatus, local
/* 800F4544 000F1484  38 60 00 00 */	li r3, 0
/* 800F4548 000F1488  B0 64 00 00 */	sth r3, 0(r4)
/* 800F454C 000F148C  80 05 00 00 */	lwz r0, 0(r5)
/* 800F4550 000F1490  54 00 87 39 */	rlwinm. r0, r0, 0x10, 0x1c, 0x1c
/* 800F4554 000F1494  41 82 00 08 */	beq .L_800F455C
/* 800F4558 000F1498  38 60 01 00 */	li r3, 0x100
.L_800F455C:
/* 800F455C 000F149C  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F4560 000F14A0  7C 00 1B 78 */	or r0, r0, r3
/* 800F4564 000F14A4  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4568 000F14A8  80 05 00 00 */	lwz r0, 0(r5)
/* 800F456C 000F14AC  54 00 86 B5 */	rlwinm. r0, r0, 0x10, 0x1a, 0x1a
/* 800F4570 000F14B0  41 82 00 0C */	beq .L_800F457C
/* 800F4574 000F14B4  38 60 02 00 */	li r3, 0x200
/* 800F4578 000F14B8  48 00 00 08 */	b .L_800F4580
.L_800F457C:
/* 800F457C 000F14BC  38 60 00 00 */	li r3, 0
.L_800F4580:
/* 800F4580 000F14C0  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F4584 000F14C4  7C 00 1B 78 */	or r0, r0, r3
/* 800F4588 000F14C8  B0 04 00 00 */	sth r0, 0(r4)
/* 800F458C 000F14CC  80 05 00 00 */	lwz r0, 0(r5)
/* 800F4590 000F14D0  54 00 85 EF */	rlwinm. r0, r0, 0x10, 0x17, 0x17
/* 800F4594 000F14D4  41 82 00 0C */	beq .L_800F45A0
/* 800F4598 000F14D8  38 60 04 00 */	li r3, 0x400
/* 800F459C 000F14DC  48 00 00 08 */	b .L_800F45A4
.L_800F45A0:
/* 800F45A0 000F14E0  38 60 00 00 */	li r3, 0
.L_800F45A4:
/* 800F45A4 000F14E4  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F45A8 000F14E8  7C 00 1B 78 */	or r0, r0, r3
/* 800F45AC 000F14EC  B0 04 00 00 */	sth r0, 0(r4)
/* 800F45B0 000F14F0  80 05 00 00 */	lwz r0, 0(r5)
/* 800F45B4 000F14F4  54 00 87 FF */	rlwinm. r0, r0, 0x10, 0x1f, 0x1f
/* 800F45B8 000F14F8  41 82 00 0C */	beq .L_800F45C4
/* 800F45BC 000F14FC  38 60 08 00 */	li r3, 0x800
/* 800F45C0 000F1500  48 00 00 08 */	b .L_800F45C8
.L_800F45C4:
/* 800F45C4 000F1504  38 60 00 00 */	li r3, 0
.L_800F45C8:
/* 800F45C8 000F1508  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F45CC 000F150C  7C 00 1B 78 */	or r0, r0, r3
/* 800F45D0 000F1510  B0 04 00 00 */	sth r0, 0(r4)
/* 800F45D4 000F1514  80 05 00 00 */	lwz r0, 0(r5)
/* 800F45D8 000F1518  54 00 86 F7 */	rlwinm. r0, r0, 0x10, 0x1b, 0x1b
/* 800F45DC 000F151C  41 82 00 0C */	beq .L_800F45E8
/* 800F45E0 000F1520  38 C0 10 00 */	li r6, 0x1000
/* 800F45E4 000F1524  48 00 00 08 */	b .L_800F45EC
.L_800F45E8:
/* 800F45E8 000F1528  38 C0 00 00 */	li r6, 0
.L_800F45EC:
/* 800F45EC 000F152C  A0 64 00 00 */	lhz r3, 0(r4)
/* 800F45F0 000F1530  38 00 00 00 */	li r0, 0
/* 800F45F4 000F1534  7C 63 33 78 */	or r3, r3, r6
/* 800F45F8 000F1538  B0 64 00 00 */	sth r3, 0(r4)
/* 800F45FC 000F153C  80 65 00 04 */	lwz r3, 4(r5)
/* 800F4600 000F1540  54 63 84 3E */	srwi r3, r3, 0x10
/* 800F4604 000F1544  7C 63 07 74 */	extsb r3, r3
/* 800F4608 000F1548  98 64 00 02 */	stb r3, 2(r4)
/* 800F460C 000F154C  80 65 00 04 */	lwz r3, 4(r5)
/* 800F4610 000F1550  54 63 46 3E */	srwi r3, r3, 0x18
/* 800F4614 000F1554  7C 63 07 74 */	extsb r3, r3
/* 800F4618 000F1558  98 64 00 03 */	stb r3, 3(r4)
/* 800F461C 000F155C  80 65 00 04 */	lwz r3, 4(r5)
/* 800F4620 000F1560  7C 63 07 74 */	extsb r3, r3
/* 800F4624 000F1564  98 64 00 04 */	stb r3, 4(r4)
/* 800F4628 000F1568  80 65 00 04 */	lwz r3, 4(r5)
/* 800F462C 000F156C  54 63 C2 3E */	srwi r3, r3, 8
/* 800F4630 000F1570  7C 63 07 74 */	extsb r3, r3
/* 800F4634 000F1574  98 64 00 05 */	stb r3, 5(r4)
/* 800F4638 000F1578  80 65 00 00 */	lwz r3, 0(r5)
/* 800F463C 000F157C  54 63 C6 3E */	rlwinm r3, r3, 0x18, 0x18, 0x1f
/* 800F4640 000F1580  98 64 00 06 */	stb r3, 6(r4)
/* 800F4644 000F1584  80 65 00 00 */	lwz r3, 0(r5)
/* 800F4648 000F1588  98 64 00 07 */	stb r3, 7(r4)
/* 800F464C 000F158C  98 04 00 08 */	stb r0, 8(r4)
/* 800F4650 000F1590  98 04 00 09 */	stb r0, 9(r4)
/* 800F4654 000F1594  88 04 00 06 */	lbz r0, 6(r4)
/* 800F4658 000F1598  28 00 00 AA */	cmplwi r0, 0xaa
/* 800F465C 000F159C  41 80 00 10 */	blt .L_800F466C
/* 800F4660 000F15A0  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F4664 000F15A4  60 00 00 40 */	ori r0, r0, 0x40
/* 800F4668 000F15A8  B0 04 00 00 */	sth r0, 0(r4)
.L_800F466C:
/* 800F466C 000F15AC  88 04 00 07 */	lbz r0, 7(r4)
/* 800F4670 000F15B0  28 00 00 AA */	cmplwi r0, 0xaa
/* 800F4674 000F15B4  41 80 00 10 */	blt .L_800F4684
/* 800F4678 000F15B8  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F467C 000F15BC  60 00 00 20 */	ori r0, r0, 0x20
/* 800F4680 000F15C0  B0 04 00 00 */	sth r0, 0(r4)
.L_800F4684:
/* 800F4684 000F15C4  88 64 00 02 */	lbz r3, 2(r4)
/* 800F4688 000F15C8  38 03 FF 80 */	addi r0, r3, -128
/* 800F468C 000F15CC  98 04 00 02 */	stb r0, 2(r4)
/* 800F4690 000F15D0  88 64 00 03 */	lbz r3, 3(r4)
/* 800F4694 000F15D4  38 03 FF 80 */	addi r0, r3, -128
/* 800F4698 000F15D8  98 04 00 03 */	stb r0, 3(r4)
/* 800F469C 000F15DC  88 64 00 04 */	lbz r3, 4(r4)
/* 800F46A0 000F15E0  38 03 FF 80 */	addi r0, r3, -128
/* 800F46A4 000F15E4  98 04 00 04 */	stb r0, 4(r4)
/* 800F46A8 000F15E8  88 64 00 05 */	lbz r3, 5(r4)
/* 800F46AC 000F15EC  38 03 FF 80 */	addi r0, r3, -128
/* 800F46B0 000F15F0  98 04 00 05 */	stb r0, 5(r4)
/* 800F46B4 000F15F4  4E 80 00 20 */	blr 
.endfn SPEC0_MakeStatus

.fn SPEC1_MakeStatus, local
/* 800F46B8 000F15F8  38 60 00 00 */	li r3, 0
/* 800F46BC 000F15FC  B0 64 00 00 */	sth r3, 0(r4)
/* 800F46C0 000F1600  80 05 00 00 */	lwz r0, 0(r5)
/* 800F46C4 000F1604  54 00 86 31 */	rlwinm. r0, r0, 0x10, 0x18, 0x18
/* 800F46C8 000F1608  41 82 00 08 */	beq .L_800F46D0
/* 800F46CC 000F160C  38 60 01 00 */	li r3, 0x100
.L_800F46D0:
/* 800F46D0 000F1610  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F46D4 000F1614  7C 00 1B 78 */	or r0, r0, r3
/* 800F46D8 000F1618  B0 04 00 00 */	sth r0, 0(r4)
/* 800F46DC 000F161C  80 05 00 00 */	lwz r0, 0(r5)
/* 800F46E0 000F1620  54 00 85 EF */	rlwinm. r0, r0, 0x10, 0x17, 0x17
/* 800F46E4 000F1624  41 82 00 0C */	beq .L_800F46F0
/* 800F46E8 000F1628  38 60 02 00 */	li r3, 0x200
/* 800F46EC 000F162C  48 00 00 08 */	b .L_800F46F4
.L_800F46F0:
/* 800F46F0 000F1630  38 60 00 00 */	li r3, 0
.L_800F46F4:
/* 800F46F4 000F1634  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F46F8 000F1638  7C 00 1B 78 */	or r0, r0, r3
/* 800F46FC 000F163C  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4700 000F1640  80 05 00 00 */	lwz r0, 0(r5)
/* 800F4704 000F1644  54 00 86 B5 */	rlwinm. r0, r0, 0x10, 0x1a, 0x1a
/* 800F4708 000F1648  41 82 00 0C */	beq .L_800F4714
/* 800F470C 000F164C  38 60 04 00 */	li r3, 0x400
/* 800F4710 000F1650  48 00 00 08 */	b .L_800F4718
.L_800F4714:
/* 800F4714 000F1654  38 60 00 00 */	li r3, 0
.L_800F4718:
/* 800F4718 000F1658  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F471C 000F165C  7C 00 1B 78 */	or r0, r0, r3
/* 800F4720 000F1660  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4724 000F1664  80 05 00 00 */	lwz r0, 0(r5)
/* 800F4728 000F1668  54 00 86 F7 */	rlwinm. r0, r0, 0x10, 0x1b, 0x1b
/* 800F472C 000F166C  41 82 00 0C */	beq .L_800F4738
/* 800F4730 000F1670  38 60 08 00 */	li r3, 0x800
/* 800F4734 000F1674  48 00 00 08 */	b .L_800F473C
.L_800F4738:
/* 800F4738 000F1678  38 60 00 00 */	li r3, 0
.L_800F473C:
/* 800F473C 000F167C  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F4740 000F1680  7C 00 1B 78 */	or r0, r0, r3
/* 800F4744 000F1684  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4748 000F1688  80 05 00 00 */	lwz r0, 0(r5)
/* 800F474C 000F168C  54 00 85 AD */	rlwinm. r0, r0, 0x10, 0x16, 0x16
/* 800F4750 000F1690  41 82 00 0C */	beq .L_800F475C
/* 800F4754 000F1694  38 C0 10 00 */	li r6, 0x1000
/* 800F4758 000F1698  48 00 00 08 */	b .L_800F4760
.L_800F475C:
/* 800F475C 000F169C  38 C0 00 00 */	li r6, 0
.L_800F4760:
/* 800F4760 000F16A0  A0 64 00 00 */	lhz r3, 0(r4)
/* 800F4764 000F16A4  38 00 00 00 */	li r0, 0
/* 800F4768 000F16A8  7C 63 33 78 */	or r3, r3, r6
/* 800F476C 000F16AC  B0 64 00 00 */	sth r3, 0(r4)
/* 800F4770 000F16B0  80 65 00 04 */	lwz r3, 4(r5)
/* 800F4774 000F16B4  54 63 84 3E */	srwi r3, r3, 0x10
/* 800F4778 000F16B8  7C 63 07 74 */	extsb r3, r3
/* 800F477C 000F16BC  98 64 00 02 */	stb r3, 2(r4)
/* 800F4780 000F16C0  80 65 00 04 */	lwz r3, 4(r5)
/* 800F4784 000F16C4  54 63 46 3E */	srwi r3, r3, 0x18
/* 800F4788 000F16C8  7C 63 07 74 */	extsb r3, r3
/* 800F478C 000F16CC  98 64 00 03 */	stb r3, 3(r4)
/* 800F4790 000F16D0  80 65 00 04 */	lwz r3, 4(r5)
/* 800F4794 000F16D4  7C 63 07 74 */	extsb r3, r3
/* 800F4798 000F16D8  98 64 00 04 */	stb r3, 4(r4)
/* 800F479C 000F16DC  80 65 00 04 */	lwz r3, 4(r5)
/* 800F47A0 000F16E0  54 63 C2 3E */	srwi r3, r3, 8
/* 800F47A4 000F16E4  7C 63 07 74 */	extsb r3, r3
/* 800F47A8 000F16E8  98 64 00 05 */	stb r3, 5(r4)
/* 800F47AC 000F16EC  80 65 00 00 */	lwz r3, 0(r5)
/* 800F47B0 000F16F0  54 63 C6 3E */	rlwinm r3, r3, 0x18, 0x18, 0x1f
/* 800F47B4 000F16F4  98 64 00 06 */	stb r3, 6(r4)
/* 800F47B8 000F16F8  80 65 00 00 */	lwz r3, 0(r5)
/* 800F47BC 000F16FC  98 64 00 07 */	stb r3, 7(r4)
/* 800F47C0 000F1700  98 04 00 08 */	stb r0, 8(r4)
/* 800F47C4 000F1704  98 04 00 09 */	stb r0, 9(r4)
/* 800F47C8 000F1708  88 04 00 06 */	lbz r0, 6(r4)
/* 800F47CC 000F170C  28 00 00 AA */	cmplwi r0, 0xaa
/* 800F47D0 000F1710  41 80 00 10 */	blt .L_800F47E0
/* 800F47D4 000F1714  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F47D8 000F1718  60 00 00 40 */	ori r0, r0, 0x40
/* 800F47DC 000F171C  B0 04 00 00 */	sth r0, 0(r4)
.L_800F47E0:
/* 800F47E0 000F1720  88 04 00 07 */	lbz r0, 7(r4)
/* 800F47E4 000F1724  28 00 00 AA */	cmplwi r0, 0xaa
/* 800F47E8 000F1728  41 80 00 10 */	blt .L_800F47F8
/* 800F47EC 000F172C  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F47F0 000F1730  60 00 00 20 */	ori r0, r0, 0x20
/* 800F47F4 000F1734  B0 04 00 00 */	sth r0, 0(r4)
.L_800F47F8:
/* 800F47F8 000F1738  88 64 00 02 */	lbz r3, 2(r4)
/* 800F47FC 000F173C  38 03 FF 80 */	addi r0, r3, -128
/* 800F4800 000F1740  98 04 00 02 */	stb r0, 2(r4)
/* 800F4804 000F1744  88 64 00 03 */	lbz r3, 3(r4)
/* 800F4808 000F1748  38 03 FF 80 */	addi r0, r3, -128
/* 800F480C 000F174C  98 04 00 03 */	stb r0, 3(r4)
/* 800F4810 000F1750  88 64 00 04 */	lbz r3, 4(r4)
/* 800F4814 000F1754  38 03 FF 80 */	addi r0, r3, -128
/* 800F4818 000F1758  98 04 00 04 */	stb r0, 4(r4)
/* 800F481C 000F175C  88 64 00 05 */	lbz r3, 5(r4)
/* 800F4820 000F1760  38 03 FF 80 */	addi r0, r3, -128
/* 800F4824 000F1764  98 04 00 05 */	stb r0, 5(r4)
/* 800F4828 000F1768  4E 80 00 20 */	blr 
.endfn SPEC1_MakeStatus

.fn SPEC2_MakeStatus, local
/* 800F482C 000F176C  80 05 00 00 */	lwz r0, 0(r5)
/* 800F4830 000F1770  54 00 84 BE */	rlwinm r0, r0, 0x10, 0x12, 0x1f
/* 800F4834 000F1774  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4838 000F1778  80 05 00 00 */	lwz r0, 0(r5)
/* 800F483C 000F177C  54 00 C2 3E */	srwi r0, r0, 8
/* 800F4840 000F1780  7C 00 07 74 */	extsb r0, r0
/* 800F4844 000F1784  98 04 00 02 */	stb r0, 2(r4)
/* 800F4848 000F1788  80 05 00 00 */	lwz r0, 0(r5)
/* 800F484C 000F178C  7C 00 07 74 */	extsb r0, r0
/* 800F4850 000F1790  98 04 00 03 */	stb r0, 3(r4)
/* 800F4854 000F1794  80 0D 83 8C */	lwz r0, AnalogMode@sda21(r13)
/* 800F4858 000F1798  54 00 05 6E */	rlwinm r0, r0, 0, 0x15, 0x17
/* 800F485C 000F179C  2C 00 04 00 */	cmpwi r0, 0x400
/* 800F4860 000F17A0  41 82 01 98 */	beq .L_800F49F8
/* 800F4864 000F17A4  40 80 00 34 */	bge .L_800F4898
/* 800F4868 000F17A8  2C 00 02 00 */	cmpwi r0, 0x200
/* 800F486C 000F17AC  41 82 00 F8 */	beq .L_800F4964
/* 800F4870 000F17B0  40 80 00 1C */	bge .L_800F488C
/* 800F4874 000F17B4  2C 00 01 00 */	cmpwi r0, 0x100
/* 800F4878 000F17B8  41 82 00 98 */	beq .L_800F4910
/* 800F487C 000F17BC  40 80 01 BC */	bge .L_800F4A38
/* 800F4880 000F17C0  2C 00 00 00 */	cmpwi r0, 0
/* 800F4884 000F17C4  41 82 00 38 */	beq .L_800F48BC
/* 800F4888 000F17C8  48 00 01 B0 */	b .L_800F4A38
.L_800F488C:
/* 800F488C 000F17CC  2C 00 03 00 */	cmpwi r0, 0x300
/* 800F4890 000F17D0  41 82 01 24 */	beq .L_800F49B4
/* 800F4894 000F17D4  48 00 01 A4 */	b .L_800F4A38
.L_800F4898:
/* 800F4898 000F17D8  2C 00 06 00 */	cmpwi r0, 0x600
/* 800F489C 000F17DC  41 82 00 20 */	beq .L_800F48BC
/* 800F48A0 000F17E0  40 80 00 10 */	bge .L_800F48B0
/* 800F48A4 000F17E4  2C 00 05 00 */	cmpwi r0, 0x500
/* 800F48A8 000F17E8  41 82 00 14 */	beq .L_800F48BC
/* 800F48AC 000F17EC  48 00 01 8C */	b .L_800F4A38
.L_800F48B0:
/* 800F48B0 000F17F0  2C 00 07 00 */	cmpwi r0, 0x700
/* 800F48B4 000F17F4  41 82 00 08 */	beq .L_800F48BC
/* 800F48B8 000F17F8  48 00 01 80 */	b .L_800F4A38
.L_800F48BC:
/* 800F48BC 000F17FC  80 05 00 04 */	lwz r0, 4(r5)
/* 800F48C0 000F1800  54 00 46 3E */	srwi r0, r0, 0x18
/* 800F48C4 000F1804  7C 00 07 74 */	extsb r0, r0
/* 800F48C8 000F1808  98 04 00 04 */	stb r0, 4(r4)
/* 800F48CC 000F180C  80 05 00 04 */	lwz r0, 4(r5)
/* 800F48D0 000F1810  54 00 84 3E */	srwi r0, r0, 0x10
/* 800F48D4 000F1814  7C 00 07 74 */	extsb r0, r0
/* 800F48D8 000F1818  98 04 00 05 */	stb r0, 5(r4)
/* 800F48DC 000F181C  80 05 00 04 */	lwz r0, 4(r5)
/* 800F48E0 000F1820  54 00 C6 36 */	rlwinm r0, r0, 0x18, 0x18, 0x1b
/* 800F48E4 000F1824  98 04 00 06 */	stb r0, 6(r4)
/* 800F48E8 000F1828  80 05 00 04 */	lwz r0, 4(r5)
/* 800F48EC 000F182C  54 00 E6 36 */	rlwinm r0, r0, 0x1c, 0x18, 0x1b
/* 800F48F0 000F1830  98 04 00 07 */	stb r0, 7(r4)
/* 800F48F4 000F1834  80 05 00 04 */	lwz r0, 4(r5)
/* 800F48F8 000F1838  54 00 06 36 */	rlwinm r0, r0, 0, 0x18, 0x1b
/* 800F48FC 000F183C  98 04 00 08 */	stb r0, 8(r4)
/* 800F4900 000F1840  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4904 000F1844  54 00 26 36 */	rlwinm r0, r0, 4, 0x18, 0x1b
/* 800F4908 000F1848  98 04 00 09 */	stb r0, 9(r4)
/* 800F490C 000F184C  48 00 01 2C */	b .L_800F4A38
.L_800F4910:
/* 800F4910 000F1850  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4914 000F1854  54 00 46 36 */	rlwinm r0, r0, 8, 0x18, 0x1b
/* 800F4918 000F1858  7C 00 07 74 */	extsb r0, r0
/* 800F491C 000F185C  98 04 00 04 */	stb r0, 4(r4)
/* 800F4920 000F1860  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4924 000F1864  54 00 66 36 */	rlwinm r0, r0, 0xc, 0x18, 0x1b
/* 800F4928 000F1868  7C 00 07 74 */	extsb r0, r0
/* 800F492C 000F186C  98 04 00 05 */	stb r0, 5(r4)
/* 800F4930 000F1870  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4934 000F1874  54 00 86 3E */	rlwinm r0, r0, 0x10, 0x18, 0x1f
/* 800F4938 000F1878  98 04 00 06 */	stb r0, 6(r4)
/* 800F493C 000F187C  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4940 000F1880  54 00 C6 3E */	rlwinm r0, r0, 0x18, 0x18, 0x1f
/* 800F4944 000F1884  98 04 00 07 */	stb r0, 7(r4)
/* 800F4948 000F1888  80 05 00 04 */	lwz r0, 4(r5)
/* 800F494C 000F188C  54 00 06 36 */	rlwinm r0, r0, 0, 0x18, 0x1b
/* 800F4950 000F1890  98 04 00 08 */	stb r0, 8(r4)
/* 800F4954 000F1894  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4958 000F1898  54 00 26 36 */	rlwinm r0, r0, 4, 0x18, 0x1b
/* 800F495C 000F189C  98 04 00 09 */	stb r0, 9(r4)
/* 800F4960 000F18A0  48 00 00 D8 */	b .L_800F4A38
.L_800F4964:
/* 800F4964 000F18A4  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4968 000F18A8  54 00 46 36 */	rlwinm r0, r0, 8, 0x18, 0x1b
/* 800F496C 000F18AC  7C 00 07 74 */	extsb r0, r0
/* 800F4970 000F18B0  98 04 00 04 */	stb r0, 4(r4)
/* 800F4974 000F18B4  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4978 000F18B8  54 00 66 36 */	rlwinm r0, r0, 0xc, 0x18, 0x1b
/* 800F497C 000F18BC  7C 00 07 74 */	extsb r0, r0
/* 800F4980 000F18C0  98 04 00 05 */	stb r0, 5(r4)
/* 800F4984 000F18C4  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4988 000F18C8  54 00 86 36 */	rlwinm r0, r0, 0x10, 0x18, 0x1b
/* 800F498C 000F18CC  98 04 00 06 */	stb r0, 6(r4)
/* 800F4990 000F18D0  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4994 000F18D4  54 00 A6 36 */	rlwinm r0, r0, 0x14, 0x18, 0x1b
/* 800F4998 000F18D8  98 04 00 07 */	stb r0, 7(r4)
/* 800F499C 000F18DC  80 05 00 04 */	lwz r0, 4(r5)
/* 800F49A0 000F18E0  54 00 C6 3E */	rlwinm r0, r0, 0x18, 0x18, 0x1f
/* 800F49A4 000F18E4  98 04 00 08 */	stb r0, 8(r4)
/* 800F49A8 000F18E8  80 05 00 04 */	lwz r0, 4(r5)
/* 800F49AC 000F18EC  98 04 00 09 */	stb r0, 9(r4)
/* 800F49B0 000F18F0  48 00 00 88 */	b .L_800F4A38
.L_800F49B4:
/* 800F49B4 000F18F4  80 C5 00 04 */	lwz r6, 4(r5)
/* 800F49B8 000F18F8  38 00 00 00 */	li r0, 0
/* 800F49BC 000F18FC  54 C6 46 3E */	srwi r6, r6, 0x18
/* 800F49C0 000F1900  7C C6 07 74 */	extsb r6, r6
/* 800F49C4 000F1904  98 C4 00 04 */	stb r6, 4(r4)
/* 800F49C8 000F1908  80 C5 00 04 */	lwz r6, 4(r5)
/* 800F49CC 000F190C  54 C6 84 3E */	srwi r6, r6, 0x10
/* 800F49D0 000F1910  7C C6 07 74 */	extsb r6, r6
/* 800F49D4 000F1914  98 C4 00 05 */	stb r6, 5(r4)
/* 800F49D8 000F1918  80 C5 00 04 */	lwz r6, 4(r5)
/* 800F49DC 000F191C  54 C6 C6 3E */	rlwinm r6, r6, 0x18, 0x18, 0x1f
/* 800F49E0 000F1920  98 C4 00 06 */	stb r6, 6(r4)
/* 800F49E4 000F1924  80 A5 00 04 */	lwz r5, 4(r5)
/* 800F49E8 000F1928  98 A4 00 07 */	stb r5, 7(r4)
/* 800F49EC 000F192C  98 04 00 08 */	stb r0, 8(r4)
/* 800F49F0 000F1930  98 04 00 09 */	stb r0, 9(r4)
/* 800F49F4 000F1934  48 00 00 44 */	b .L_800F4A38
.L_800F49F8:
/* 800F49F8 000F1938  80 C5 00 04 */	lwz r6, 4(r5)
/* 800F49FC 000F193C  38 00 00 00 */	li r0, 0
/* 800F4A00 000F1940  54 C6 46 3E */	srwi r6, r6, 0x18
/* 800F4A04 000F1944  7C C6 07 74 */	extsb r6, r6
/* 800F4A08 000F1948  98 C4 00 04 */	stb r6, 4(r4)
/* 800F4A0C 000F194C  80 C5 00 04 */	lwz r6, 4(r5)
/* 800F4A10 000F1950  54 C6 84 3E */	srwi r6, r6, 0x10
/* 800F4A14 000F1954  7C C6 07 74 */	extsb r6, r6
/* 800F4A18 000F1958  98 C4 00 05 */	stb r6, 5(r4)
/* 800F4A1C 000F195C  98 04 00 06 */	stb r0, 6(r4)
/* 800F4A20 000F1960  98 04 00 07 */	stb r0, 7(r4)
/* 800F4A24 000F1964  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4A28 000F1968  54 00 C6 3E */	rlwinm r0, r0, 0x18, 0x18, 0x1f
/* 800F4A2C 000F196C  98 04 00 08 */	stb r0, 8(r4)
/* 800F4A30 000F1970  80 05 00 04 */	lwz r0, 4(r5)
/* 800F4A34 000F1974  98 04 00 09 */	stb r0, 9(r4)
.L_800F4A38:
/* 800F4A38 000F1978  88 E4 00 02 */	lbz r7, 2(r4)
/* 800F4A3C 000F197C  3C A0 80 4F */	lis r5, Type@ha
/* 800F4A40 000F1980  54 66 10 3A */	slwi r6, r3, 2
/* 800F4A44 000F1984  38 07 FF 80 */	addi r0, r7, -128
/* 800F4A48 000F1988  98 04 00 02 */	stb r0, 2(r4)
/* 800F4A4C 000F198C  38 05 71 30 */	addi r0, r5, Type@l
/* 800F4A50 000F1990  7C A0 32 14 */	add r5, r0, r6
/* 800F4A54 000F1994  88 C4 00 03 */	lbz r6, 3(r4)
/* 800F4A58 000F1998  38 06 FF 80 */	addi r0, r6, -128
/* 800F4A5C 000F199C  98 04 00 03 */	stb r0, 3(r4)
/* 800F4A60 000F19A0  88 C4 00 04 */	lbz r6, 4(r4)
/* 800F4A64 000F19A4  38 06 FF 80 */	addi r0, r6, -128
/* 800F4A68 000F19A8  98 04 00 04 */	stb r0, 4(r4)
/* 800F4A6C 000F19AC  88 C4 00 05 */	lbz r6, 5(r4)
/* 800F4A70 000F19B0  38 06 FF 80 */	addi r0, r6, -128
/* 800F4A74 000F19B4  98 04 00 05 */	stb r0, 5(r4)
/* 800F4A78 000F19B8  80 05 00 00 */	lwz r0, 0(r5)
/* 800F4A7C 000F19BC  54 05 00 1E */	rlwinm r5, r0, 0, 0, 0xf
/* 800F4A80 000F19C0  3C 05 F7 00 */	addis r0, r5, 0xf700
/* 800F4A84 000F19C4  28 00 00 00 */	cmplwi r0, 0
/* 800F4A88 000F19C8  40 82 00 44 */	bne .L_800F4ACC
/* 800F4A8C 000F19CC  A0 04 00 00 */	lhz r0, 0(r4)
/* 800F4A90 000F19D0  54 00 06 30 */	rlwinm r0, r0, 0, 0x18, 0x18
/* 800F4A94 000F19D4  68 00 00 80 */	xori r0, r0, 0x80
/* 800F4A98 000F19D8  2C 00 00 00 */	cmpwi r0, 0
/* 800F4A9C 000F19DC  41 82 00 30 */	beq .L_800F4ACC
/* 800F4AA0 000F19E0  3C 00 80 00 */	lis r0, 0x8000
/* 800F4AA4 000F19E4  80 AD 90 0C */	lwz r5, BarrelBits@sda21(r13)
/* 800F4AA8 000F19E8  7C 00 1C 30 */	srw r0, r0, r3
/* 800F4AAC 000F19EC  7C A0 03 78 */	or r0, r5, r0
/* 800F4AB0 000F19F0  90 0D 90 0C */	stw r0, BarrelBits@sda21(r13)
/* 800F4AB4 000F19F4  38 00 00 00 */	li r0, 0
/* 800F4AB8 000F19F8  98 04 00 02 */	stb r0, 2(r4)
/* 800F4ABC 000F19FC  98 04 00 03 */	stb r0, 3(r4)
/* 800F4AC0 000F1A00  98 04 00 04 */	stb r0, 4(r4)
/* 800F4AC4 000F1A04  98 04 00 05 */	stb r0, 5(r4)
/* 800F4AC8 000F1A08  4E 80 00 20 */	blr 
.L_800F4ACC:
/* 800F4ACC 000F1A0C  3C 00 80 00 */	lis r0, 0x8000
/* 800F4AD0 000F1A10  80 AD 90 0C */	lwz r5, BarrelBits@sda21(r13)
/* 800F4AD4 000F1A14  7C 00 1C 30 */	srw r0, r0, r3
/* 800F4AD8 000F1A18  7C A0 00 78 */	andc r0, r5, r0
/* 800F4ADC 000F1A1C  90 0D 90 0C */	stw r0, BarrelBits@sda21(r13)
/* 800F4AE0 000F1A20  3C A0 80 4F */	lis r5, Origin@ha
/* 800F4AE4 000F1A24  1C 63 00 0C */	mulli r3, r3, 0xc
/* 800F4AE8 000F1A28  88 C4 00 02 */	lbz r6, 2(r4)
/* 800F4AEC 000F1A2C  38 05 71 40 */	addi r0, r5, Origin@l
/* 800F4AF0 000F1A30  7C 60 1A 14 */	add r3, r0, r3
/* 800F4AF4 000F1A34  88 E3 00 02 */	lbz r7, 2(r3)
/* 800F4AF8 000F1A38  7C E0 07 75 */	extsb. r0, r7
/* 800F4AFC 000F1A3C  40 81 00 24 */	ble .L_800F4B20
/* 800F4B00 000F1A40  7C E5 07 74 */	extsb r5, r7
/* 800F4B04 000F1A44  38 05 FF 80 */	addi r0, r5, -128
/* 800F4B08 000F1A48  7C 05 07 74 */	extsb r5, r0
/* 800F4B0C 000F1A4C  7C C0 07 74 */	extsb r0, r6
/* 800F4B10 000F1A50  7C 00 28 00 */	cmpw r0, r5
/* 800F4B14 000F1A54  40 80 00 30 */	bge .L_800F4B44
/* 800F4B18 000F1A58  7C A6 2B 78 */	mr r6, r5
/* 800F4B1C 000F1A5C  48 00 00 28 */	b .L_800F4B44
.L_800F4B20:
/* 800F4B20 000F1A60  7C E0 07 75 */	extsb. r0, r7
/* 800F4B24 000F1A64  40 80 00 20 */	bge .L_800F4B44
/* 800F4B28 000F1A68  7C E5 07 74 */	extsb r5, r7
/* 800F4B2C 000F1A6C  38 05 00 7F */	addi r0, r5, 0x7f
/* 800F4B30 000F1A70  7C 05 07 74 */	extsb r5, r0
/* 800F4B34 000F1A74  7C C0 07 74 */	extsb r0, r6
/* 800F4B38 000F1A78  7C 05 00 00 */	cmpw r5, r0
/* 800F4B3C 000F1A7C  40 80 00 08 */	bge .L_800F4B44
/* 800F4B40 000F1A80  7C A6 2B 78 */	mr r6, r5
.L_800F4B44:
/* 800F4B44 000F1A84  7C C7 30 50 */	subf r6, r7, r6
/* 800F4B48 000F1A88  98 C4 00 02 */	stb r6, 2(r4)
/* 800F4B4C 000F1A8C  88 E3 00 03 */	lbz r7, 3(r3)
/* 800F4B50 000F1A90  88 C4 00 03 */	lbz r6, 3(r4)
/* 800F4B54 000F1A94  7C E0 07 75 */	extsb. r0, r7
/* 800F4B58 000F1A98  40 81 00 24 */	ble .L_800F4B7C
/* 800F4B5C 000F1A9C  7C E5 07 74 */	extsb r5, r7
/* 800F4B60 000F1AA0  38 05 FF 80 */	addi r0, r5, -128
/* 800F4B64 000F1AA4  7C 05 07 74 */	extsb r5, r0
/* 800F4B68 000F1AA8  7C C0 07 74 */	extsb r0, r6
/* 800F4B6C 000F1AAC  7C 00 28 00 */	cmpw r0, r5
/* 800F4B70 000F1AB0  40 80 00 30 */	bge .L_800F4BA0
/* 800F4B74 000F1AB4  7C A6 2B 78 */	mr r6, r5
/* 800F4B78 000F1AB8  48 00 00 28 */	b .L_800F4BA0
.L_800F4B7C:
/* 800F4B7C 000F1ABC  7C E0 07 75 */	extsb. r0, r7
/* 800F4B80 000F1AC0  40 80 00 20 */	bge .L_800F4BA0
/* 800F4B84 000F1AC4  7C E5 07 74 */	extsb r5, r7
/* 800F4B88 000F1AC8  38 05 00 7F */	addi r0, r5, 0x7f
/* 800F4B8C 000F1ACC  7C 05 07 74 */	extsb r5, r0
/* 800F4B90 000F1AD0  7C C0 07 74 */	extsb r0, r6
/* 800F4B94 000F1AD4  7C 05 00 00 */	cmpw r5, r0
/* 800F4B98 000F1AD8  40 80 00 08 */	bge .L_800F4BA0
/* 800F4B9C 000F1ADC  7C A6 2B 78 */	mr r6, r5
.L_800F4BA0:
/* 800F4BA0 000F1AE0  7C C7 30 50 */	subf r6, r7, r6
/* 800F4BA4 000F1AE4  98 C4 00 03 */	stb r6, 3(r4)
/* 800F4BA8 000F1AE8  88 E3 00 04 */	lbz r7, 4(r3)
/* 800F4BAC 000F1AEC  88 C4 00 04 */	lbz r6, 4(r4)
/* 800F4BB0 000F1AF0  7C E0 07 75 */	extsb. r0, r7
/* 800F4BB4 000F1AF4  40 81 00 24 */	ble .L_800F4BD8
/* 800F4BB8 000F1AF8  7C E5 07 74 */	extsb r5, r7
/* 800F4BBC 000F1AFC  38 05 FF 80 */	addi r0, r5, -128
/* 800F4BC0 000F1B00  7C 05 07 74 */	extsb r5, r0
/* 800F4BC4 000F1B04  7C C0 07 74 */	extsb r0, r6
/* 800F4BC8 000F1B08  7C 00 28 00 */	cmpw r0, r5
/* 800F4BCC 000F1B0C  40 80 00 30 */	bge .L_800F4BFC
/* 800F4BD0 000F1B10  7C A6 2B 78 */	mr r6, r5
/* 800F4BD4 000F1B14  48 00 00 28 */	b .L_800F4BFC
.L_800F4BD8:
/* 800F4BD8 000F1B18  7C E0 07 75 */	extsb. r0, r7
/* 800F4BDC 000F1B1C  40 80 00 20 */	bge .L_800F4BFC
/* 800F4BE0 000F1B20  7C E5 07 74 */	extsb r5, r7
/* 800F4BE4 000F1B24  38 05 00 7F */	addi r0, r5, 0x7f
/* 800F4BE8 000F1B28  7C 05 07 74 */	extsb r5, r0
/* 800F4BEC 000F1B2C  7C C0 07 74 */	extsb r0, r6
/* 800F4BF0 000F1B30  7C 05 00 00 */	cmpw r5, r0
/* 800F4BF4 000F1B34  40 80 00 08 */	bge .L_800F4BFC
/* 800F4BF8 000F1B38  7C A6 2B 78 */	mr r6, r5
.L_800F4BFC:
/* 800F4BFC 000F1B3C  7C C7 30 50 */	subf r6, r7, r6
/* 800F4C00 000F1B40  98 C4 00 04 */	stb r6, 4(r4)
/* 800F4C04 000F1B44  88 E3 00 05 */	lbz r7, 5(r3)
/* 800F4C08 000F1B48  88 C4 00 05 */	lbz r6, 5(r4)
/* 800F4C0C 000F1B4C  7C E0 07 75 */	extsb. r0, r7
/* 800F4C10 000F1B50  40 81 00 24 */	ble .L_800F4C34
/* 800F4C14 000F1B54  7C E5 07 74 */	extsb r5, r7
/* 800F4C18 000F1B58  38 05 FF 80 */	addi r0, r5, -128
/* 800F4C1C 000F1B5C  7C 05 07 74 */	extsb r5, r0
/* 800F4C20 000F1B60  7C C0 07 74 */	extsb r0, r6
/* 800F4C24 000F1B64  7C 00 28 00 */	cmpw r0, r5
/* 800F4C28 000F1B68  40 80 00 30 */	bge .L_800F4C58
/* 800F4C2C 000F1B6C  7C A6 2B 78 */	mr r6, r5
/* 800F4C30 000F1B70  48 00 00 28 */	b .L_800F4C58
.L_800F4C34:
/* 800F4C34 000F1B74  7C E0 07 75 */	extsb. r0, r7
/* 800F4C38 000F1B78  40 80 00 20 */	bge .L_800F4C58
/* 800F4C3C 000F1B7C  7C E5 07 74 */	extsb r5, r7
/* 800F4C40 000F1B80  38 05 00 7F */	addi r0, r5, 0x7f
/* 800F4C44 000F1B84  7C 05 07 74 */	extsb r5, r0
/* 800F4C48 000F1B88  7C C0 07 74 */	extsb r0, r6
/* 800F4C4C 000F1B8C  7C 05 00 00 */	cmpw r5, r0
/* 800F4C50 000F1B90  40 80 00 08 */	bge .L_800F4C58
/* 800F4C54 000F1B94  7C A6 2B 78 */	mr r6, r5
.L_800F4C58:
/* 800F4C58 000F1B98  7C C7 30 50 */	subf r6, r7, r6
/* 800F4C5C 000F1B9C  98 C4 00 05 */	stb r6, 5(r4)
/* 800F4C60 000F1BA0  88 03 00 06 */	lbz r0, 6(r3)
/* 800F4C64 000F1BA4  88 A4 00 06 */	lbz r5, 6(r4)
/* 800F4C68 000F1BA8  7C 05 00 40 */	cmplw r5, r0
/* 800F4C6C 000F1BAC  40 80 00 08 */	bge .L_800F4C74
/* 800F4C70 000F1BB0  7C 05 03 78 */	mr r5, r0
.L_800F4C74:
/* 800F4C74 000F1BB4  7C A0 28 50 */	subf r5, r0, r5
/* 800F4C78 000F1BB8  98 A4 00 06 */	stb r5, 6(r4)
/* 800F4C7C 000F1BBC  88 03 00 07 */	lbz r0, 7(r3)
/* 800F4C80 000F1BC0  88 64 00 07 */	lbz r3, 7(r4)
/* 800F4C84 000F1BC4  7C 03 00 40 */	cmplw r3, r0
/* 800F4C88 000F1BC8  40 80 00 08 */	bge .L_800F4C90
/* 800F4C8C 000F1BCC  7C 03 03 78 */	mr r3, r0
.L_800F4C90:
/* 800F4C90 000F1BD0  7C 60 18 50 */	subf r3, r0, r3
/* 800F4C94 000F1BD4  98 64 00 07 */	stb r3, 7(r4)
/* 800F4C98 000F1BD8  4E 80 00 20 */	blr 
.endfn SPEC2_MakeStatus

.fn PADSetAnalogMode, global
/* 800F4C9C 000F1BDC  7C 08 02 A6 */	mflr r0
/* 800F4CA0 000F1BE0  90 01 00 04 */	stw r0, 4(r1)
/* 800F4CA4 000F1BE4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F4CA8 000F1BE8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F4CAC 000F1BEC  7C 7F 1B 78 */	mr r31, r3
/* 800F4CB0 000F1BF0  4B FF 9F 89 */	bl OSDisableInterrupts
/* 800F4CB4 000F1BF4  80 AD 8F F4 */	lwz r5, EnabledBits@sda21(r13)
/* 800F4CB8 000F1BF8  57 E6 40 2E */	slwi r6, r31, 8
/* 800F4CBC 000F1BFC  80 8D 90 00 */	lwz r4, WaitingBits@sda21(r13)
/* 800F4CC0 000F1C00  7C 7F 1B 78 */	mr r31, r3
/* 800F4CC4 000F1C04  39 05 00 00 */	addi r8, r5, 0
/* 800F4CC8 000F1C08  7D 07 40 F8 */	nor r7, r8, r8
/* 800F4CCC 000F1C0C  80 0D 90 04 */	lwz r0, CheckingBits@sda21(r13)
/* 800F4CD0 000F1C10  7C A5 28 78 */	andc r5, r5, r5
/* 800F4CD4 000F1C14  90 CD 83 8C */	stw r6, AnalogMode@sda21(r13)
/* 800F4CD8 000F1C18  7C 84 38 38 */	and r4, r4, r7
/* 800F4CDC 000F1C1C  7C 00 38 38 */	and r0, r0, r7
/* 800F4CE0 000F1C20  90 AD 8F F4 */	stw r5, EnabledBits@sda21(r13)
/* 800F4CE4 000F1C24  7D 03 43 78 */	mr r3, r8
/* 800F4CE8 000F1C28  90 8D 90 00 */	stw r4, WaitingBits@sda21(r13)
/* 800F4CEC 000F1C2C  90 0D 90 04 */	stw r0, CheckingBits@sda21(r13)
/* 800F4CF0 000F1C30  48 00 0F 69 */	bl SIDisablePolling
/* 800F4CF4 000F1C34  7F E3 FB 78 */	mr r3, r31
/* 800F4CF8 000F1C38  4B FF 9F 69 */	bl OSRestoreInterrupts
/* 800F4CFC 000F1C3C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F4D00 000F1C40  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F4D04 000F1C44  38 21 00 18 */	addi r1, r1, 0x18
/* 800F4D08 000F1C48  7C 08 03 A6 */	mtlr r0
/* 800F4D0C 000F1C4C  4E 80 00 20 */	blr 
.endfn PADSetAnalogMode

.fn OnReset, local
/* 800F4D10 000F1C50  7C 08 02 A6 */	mflr r0
/* 800F4D14 000F1C54  90 01 00 04 */	stw r0, 4(r1)
/* 800F4D18 000F1C58  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4D1C 000F1C5C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F4D20 000F1C60  3B E3 00 00 */	addi r31, r3, 0
/* 800F4D24 000F1C64  80 0D 90 10 */	lwz r0, SamplingCallback@sda21(r13)
/* 800F4D28 000F1C68  28 00 00 00 */	cmplwi r0, 0
/* 800F4D2C 000F1C6C  41 82 00 0C */	beq .L_800F4D38
/* 800F4D30 000F1C70  38 60 00 00 */	li r3, 0
/* 800F4D34 000F1C74  48 00 00 F9 */	bl PADSetSamplingCallback
.L_800F4D38:
/* 800F4D38 000F1C78  2C 1F 00 00 */	cmpwi r31, 0
/* 800F4D3C 000F1C7C  40 82 00 70 */	bne .L_800F4DAC
/* 800F4D40 000F1C80  80 0D 8F F8 */	lwz r0, ResettingBits@sda21(r13)
/* 800F4D44 000F1C84  3B E0 00 00 */	li r31, 0
/* 800F4D48 000F1C88  38 7F 00 00 */	addi r3, r31, 0
/* 800F4D4C 000F1C8C  28 00 00 00 */	cmplwi r0, 0
/* 800F4D50 000F1C90  40 82 00 14 */	bne .L_800F4D64
/* 800F4D54 000F1C94  80 0D 83 84 */	lwz r0, ResettingChan@sda21(r13)
/* 800F4D58 000F1C98  2C 00 00 20 */	cmpwi r0, 0x20
/* 800F4D5C 000F1C9C  40 82 00 08 */	bne .L_800F4D64
/* 800F4D60 000F1CA0  38 60 00 01 */	li r3, 1
.L_800F4D64:
/* 800F4D64 000F1CA4  2C 03 00 00 */	cmpwi r3, 0
/* 800F4D68 000F1CA8  41 82 00 14 */	beq .L_800F4D7C
/* 800F4D6C 000F1CAC  48 00 01 91 */	bl SIBusy
/* 800F4D70 000F1CB0  2C 03 00 00 */	cmpwi r3, 0
/* 800F4D74 000F1CB4  40 82 00 08 */	bne .L_800F4D7C
/* 800F4D78 000F1CB8  3B E0 00 01 */	li r31, 1
.L_800F4D7C:
/* 800F4D7C 000F1CBC  80 0D 90 14 */	lwz r0, recalibrated$388@sda21(r13)
/* 800F4D80 000F1CC0  2C 00 00 00 */	cmpwi r0, 0
/* 800F4D84 000F1CC4  40 82 00 20 */	bne .L_800F4DA4
/* 800F4D88 000F1CC8  2C 1F 00 00 */	cmpwi r31, 0
/* 800F4D8C 000F1CCC  41 82 00 18 */	beq .L_800F4DA4
/* 800F4D90 000F1CD0  3C 60 F0 00 */	lis r3, 0xf000
/* 800F4D94 000F1CD4  4B FF F1 35 */	bl PADRecalibrate
/* 800F4D98 000F1CD8  90 6D 90 14 */	stw r3, recalibrated$388@sda21(r13)
/* 800F4D9C 000F1CDC  38 60 00 00 */	li r3, 0
/* 800F4DA0 000F1CE0  48 00 00 18 */	b .L_800F4DB8
.L_800F4DA4:
/* 800F4DA4 000F1CE4  7F E3 FB 78 */	mr r3, r31
/* 800F4DA8 000F1CE8  48 00 00 10 */	b .L_800F4DB8
.L_800F4DAC:
/* 800F4DAC 000F1CEC  38 00 00 00 */	li r0, 0
/* 800F4DB0 000F1CF0  90 0D 90 14 */	stw r0, recalibrated$388@sda21(r13)
/* 800F4DB4 000F1CF4  38 60 00 01 */	li r3, 1
.L_800F4DB8:
/* 800F4DB8 000F1CF8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4DBC 000F1CFC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F4DC0 000F1D00  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4DC4 000F1D04  7C 08 03 A6 */	mtlr r0
/* 800F4DC8 000F1D08  4E 80 00 20 */	blr 
.endfn OnReset

.fn SamplingHandler, local
/* 800F4DCC 000F1D0C  7C 08 02 A6 */	mflr r0
/* 800F4DD0 000F1D10  90 01 00 04 */	stw r0, 4(r1)
/* 800F4DD4 000F1D14  94 21 FD 20 */	stwu r1, -0x2e0(r1)
/* 800F4DD8 000F1D18  93 E1 02 DC */	stw r31, 0x2dc(r1)
/* 800F4DDC 000F1D1C  3B E4 00 00 */	addi r31, r4, 0
/* 800F4DE0 000F1D20  80 0D 90 10 */	lwz r0, SamplingCallback@sda21(r13)
/* 800F4DE4 000F1D24  28 00 00 00 */	cmplwi r0, 0
/* 800F4DE8 000F1D28  41 82 00 30 */	beq .L_800F4E18
/* 800F4DEC 000F1D2C  38 61 00 10 */	addi r3, r1, 0x10
/* 800F4DF0 000F1D30  4B FF 83 7D */	bl OSClearContext
/* 800F4DF4 000F1D34  38 61 00 10 */	addi r3, r1, 0x10
/* 800F4DF8 000F1D38  4B FF 81 AD */	bl OSSetCurrentContext
/* 800F4DFC 000F1D3C  81 8D 90 10 */	lwz r12, SamplingCallback@sda21(r13)
/* 800F4E00 000F1D40  7D 88 03 A6 */	mtlr r12
/* 800F4E04 000F1D44  4E 80 00 21 */	blrl 
/* 800F4E08 000F1D48  38 61 00 10 */	addi r3, r1, 0x10
/* 800F4E0C 000F1D4C  4B FF 83 61 */	bl OSClearContext
/* 800F4E10 000F1D50  7F E3 FB 78 */	mr r3, r31
/* 800F4E14 000F1D54  4B FF 81 91 */	bl OSSetCurrentContext
.L_800F4E18:
/* 800F4E18 000F1D58  80 01 02 E4 */	lwz r0, 0x2e4(r1)
/* 800F4E1C 000F1D5C  83 E1 02 DC */	lwz r31, 0x2dc(r1)
/* 800F4E20 000F1D60  38 21 02 E0 */	addi r1, r1, 0x2e0
/* 800F4E24 000F1D64  7C 08 03 A6 */	mtlr r0
/* 800F4E28 000F1D68  4E 80 00 20 */	blr 
.endfn SamplingHandler

.fn PADSetSamplingCallback, global
/* 800F4E2C 000F1D6C  7C 08 02 A6 */	mflr r0
/* 800F4E30 000F1D70  28 03 00 00 */	cmplwi r3, 0
/* 800F4E34 000F1D74  90 01 00 04 */	stw r0, 4(r1)
/* 800F4E38 000F1D78  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F4E3C 000F1D7C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F4E40 000F1D80  83 ED 90 10 */	lwz r31, SamplingCallback@sda21(r13)
/* 800F4E44 000F1D84  90 6D 90 10 */	stw r3, SamplingCallback@sda21(r13)
/* 800F4E48 000F1D88  41 82 00 14 */	beq .L_800F4E5C
/* 800F4E4C 000F1D8C  3C 60 80 0F */	lis r3, SamplingHandler@ha
/* 800F4E50 000F1D90  38 63 4D CC */	addi r3, r3, SamplingHandler@l
/* 800F4E54 000F1D94  48 00 07 DD */	bl SIRegisterPollingHandler
/* 800F4E58 000F1D98  48 00 00 10 */	b .L_800F4E68
.L_800F4E5C:
/* 800F4E5C 000F1D9C  3C 60 80 0F */	lis r3, SamplingHandler@ha
/* 800F4E60 000F1DA0  38 63 4D CC */	addi r3, r3, SamplingHandler@l
/* 800F4E64 000F1DA4  48 00 08 99 */	bl SIUnregisterPollingHandler
.L_800F4E68:
/* 800F4E68 000F1DA8  7F E3 FB 78 */	mr r3, r31
/* 800F4E6C 000F1DAC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F4E70 000F1DB0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F4E74 000F1DB4  38 21 00 18 */	addi r1, r1, 0x18
/* 800F4E78 000F1DB8  7C 08 03 A6 */	mtlr r0
/* 800F4E7C 000F1DBC  4E 80 00 20 */	blr 
.endfn PADSetSamplingCallback

.fn __PADDisableRecalibration, global
/* 800F4E80 000F1DC0  7C 08 02 A6 */	mflr r0
/* 800F4E84 000F1DC4  90 01 00 04 */	stw r0, 4(r1)
/* 800F4E88 000F1DC8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F4E8C 000F1DCC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F4E90 000F1DD0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F4E94 000F1DD4  7C 7E 1B 78 */	mr r30, r3
/* 800F4E98 000F1DD8  4B FF 9D A1 */	bl OSDisableInterrupts
/* 800F4E9C 000F1DDC  3C 80 80 00 */	lis r4, 0x800030E3@ha
/* 800F4EA0 000F1DE0  88 04 30 E3 */	lbz r0, 0x800030E3@l(r4)
/* 800F4EA4 000F1DE4  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 800F4EA8 000F1DE8  41 82 00 0C */	beq .L_800F4EB4
/* 800F4EAC 000F1DEC  3B E0 00 01 */	li r31, 1
/* 800F4EB0 000F1DF0  48 00 00 08 */	b .L_800F4EB8
.L_800F4EB4:
/* 800F4EB4 000F1DF4  3B E0 00 00 */	li r31, 0
.L_800F4EB8:
/* 800F4EB8 000F1DF8  3C 80 80 00 */	lis r4, 0x800030E3@ha
/* 800F4EBC 000F1DFC  88 04 30 E3 */	lbz r0, 0x800030E3@l(r4)
/* 800F4EC0 000F1E00  2C 1E 00 00 */	cmpwi r30, 0
/* 800F4EC4 000F1E04  54 00 06 B0 */	rlwinm r0, r0, 0, 0x1a, 0x18
/* 800F4EC8 000F1E08  98 04 30 E3 */	stb r0, 0x30e3(r4)
/* 800F4ECC 000F1E0C  41 82 00 10 */	beq .L_800F4EDC
/* 800F4ED0 000F1E10  88 04 30 E3 */	lbz r0, 0x30e3(r4)
/* 800F4ED4 000F1E14  60 00 00 40 */	ori r0, r0, 0x40
/* 800F4ED8 000F1E18  98 04 30 E3 */	stb r0, 0x30e3(r4)
.L_800F4EDC:
/* 800F4EDC 000F1E1C  4B FF 9D 85 */	bl OSRestoreInterrupts
/* 800F4EE0 000F1E20  7F E3 FB 78 */	mr r3, r31
/* 800F4EE4 000F1E24  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F4EE8 000F1E28  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F4EEC 000F1E2C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F4EF0 000F1E30  38 21 00 18 */	addi r1, r1, 0x18
/* 800F4EF4 000F1E34  7C 08 03 A6 */	mtlr r0
/* 800F4EF8 000F1E38  4E 80 00 20 */	blr 
.endfn __PADDisableRecalibration
