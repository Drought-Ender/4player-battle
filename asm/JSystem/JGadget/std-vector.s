.include "macros.inc"

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn extend_default__Q27JGadget6vectorFUlUlUl, global
/* 8002766C 000245AC  54 83 08 3C */	slwi r3, r4, 1
/* 80027670 000245B0  4E 80 00 20 */	blr 
.endfn extend_default__Q27JGadget6vectorFUlUlUl

.fn "__ct__Q27JGadget20TVector_pointer_voidFRCQ27JGadget14TAllocator<Pv>", global
/* 80027674 000245B4  88 04 00 00 */	lbz r0, 0(r4)
/* 80027678 000245B8  38 A0 00 00 */	li r5, 0
/* 8002767C 000245BC  3C 80 80 02 */	lis r4, extend_default__Q27JGadget6vectorFUlUlUl@ha
/* 80027680 000245C0  98 03 00 00 */	stb r0, 0(r3)
/* 80027684 000245C4  38 04 76 6C */	addi r0, r4, extend_default__Q27JGadget6vectorFUlUlUl@l
/* 80027688 000245C8  90 A3 00 04 */	stw r5, 4(r3)
/* 8002768C 000245CC  80 83 00 04 */	lwz r4, 4(r3)
/* 80027690 000245D0  90 83 00 08 */	stw r4, 8(r3)
/* 80027694 000245D4  90 A3 00 0C */	stw r5, 0xc(r3)
/* 80027698 000245D8  90 03 00 10 */	stw r0, 0x10(r3)
/* 8002769C 000245DC  4E 80 00 20 */	blr 
.endfn "__ct__Q27JGadget20TVector_pointer_voidFRCQ27JGadget14TAllocator<Pv>"

.fn "insert__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvUlRCPv", weak
/* 800276A0 000245E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800276A4 000245E4  7C 08 02 A6 */	mflr r0
/* 800276A8 000245E8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800276AC 000245EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800276B0 000245F0  7C DF 33 78 */	mr r31, r6
/* 800276B4 000245F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800276B8 000245F8  7C BE 2B 79 */	or. r30, r5, r5
/* 800276BC 000245FC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800276C0 00024600  7C 7D 1B 78 */	mr r29, r3
/* 800276C4 00024604  41 82 00 38 */	beq .L_800276FC
/* 800276C8 00024608  48 00 00 51 */	bl "Insert_raw__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvUl"
/* 800276CC 0002460C  80 1D 00 08 */	lwz r0, 8(r29)
/* 800276D0 00024610  7C 03 00 40 */	cmplw r3, r0
/* 800276D4 00024614  41 82 00 28 */	beq .L_800276FC
/* 800276D8 00024618  80 1F 00 00 */	lwz r0, 0(r31)
/* 800276DC 0002461C  7F C9 03 A6 */	mtctr r30
/* 800276E0 00024620  28 1E 00 00 */	cmplwi r30, 0
/* 800276E4 00024624  41 82 00 18 */	beq .L_800276FC
.L_800276E8:
/* 800276E8 00024628  28 03 00 00 */	cmplwi r3, 0
/* 800276EC 0002462C  41 82 00 08 */	beq .L_800276F4
/* 800276F0 00024630  90 03 00 00 */	stw r0, 0(r3)
.L_800276F4:
/* 800276F4 00024634  38 63 00 04 */	addi r3, r3, 4
/* 800276F8 00024638  42 00 FF F0 */	bdnz .L_800276E8
.L_800276FC:
/* 800276FC 0002463C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80027700 00024640  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80027704 00024644  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80027708 00024648  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8002770C 0002464C  7C 08 03 A6 */	mtlr r0
/* 80027710 00024650  38 21 00 20 */	addi r1, r1, 0x20
/* 80027714 00024654  4E 80 00 20 */	blr 
.endfn "insert__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvUlRCPv"

.fn "Insert_raw__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvUl", weak
/* 80027718 00024658  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8002771C 0002465C  7C 08 02 A6 */	mflr r0
/* 80027720 00024660  90 01 00 34 */	stw r0, 0x34(r1)
/* 80027724 00024664  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 80027728 00024668  7C BC 2B 79 */	or. r28, r5, r5
/* 8002772C 0002466C  7C 7B 1B 78 */	mr r27, r3
/* 80027730 00024670  7C 9E 23 78 */	mr r30, r4
/* 80027734 00024674  40 82 00 0C */	bne .L_80027740
/* 80027738 00024678  7C 83 23 78 */	mr r3, r4
/* 8002773C 0002467C  48 00 04 38 */	b .L_80027B74
.L_80027740:
/* 80027740 00024680  80 BB 00 04 */	lwz r5, 4(r27)
/* 80027744 00024684  28 05 00 00 */	cmplwi r5, 0
/* 80027748 00024688  40 82 00 0C */	bne .L_80027754
/* 8002774C 0002468C  38 00 00 00 */	li r0, 0
/* 80027750 00024690  48 00 00 14 */	b .L_80027764
.L_80027754:
/* 80027754 00024694  80 1B 00 08 */	lwz r0, 8(r27)
/* 80027758 00024698  7C 05 00 50 */	subf r0, r5, r0
/* 8002775C 0002469C  7C 00 16 70 */	srawi r0, r0, 2
/* 80027760 000246A0  7C 00 01 94 */	addze r0, r0
.L_80027764:
/* 80027764 000246A4  80 7B 00 0C */	lwz r3, 0xc(r27)
/* 80027768 000246A8  7C 1C 02 14 */	add r0, r28, r0
/* 8002776C 000246AC  7C 00 18 40 */	cmplw r0, r3
/* 80027770 000246B0  41 81 02 18 */	bgt .L_80027988
/* 80027774 000246B4  57 87 10 3A */	slwi r7, r28, 2
/* 80027778 000246B8  80 DB 00 08 */	lwz r6, 8(r27)
/* 8002777C 000246BC  7D 1E 3A 14 */	add r8, r30, r7
/* 80027780 000246C0  7C 08 30 40 */	cmplw r8, r6
/* 80027784 000246C4  40 80 01 44 */	bge .L_800278C8
/* 80027788 000246C8  7D 27 30 50 */	subf r9, r7, r6
/* 8002778C 000246CC  38 66 00 03 */	addi r3, r6, 3
/* 80027790 000246D0  7C 09 30 40 */	cmplw r9, r6
/* 80027794 000246D4  7C 69 18 50 */	subf r3, r9, r3
/* 80027798 000246D8  7D 25 4B 78 */	mr r5, r9
/* 8002779C 000246DC  54 63 F0 BE */	srwi r3, r3, 2
/* 800277A0 000246E0  40 80 00 7C */	bge .L_8002781C
/* 800277A4 000246E4  54 60 E8 FF */	rlwinm. r0, r3, 0x1d, 3, 0x1f
/* 800277A8 000246E8  7C 09 03 A6 */	mtctr r0
/* 800277AC 000246EC  41 82 00 58 */	beq .L_80027804
.L_800277B0:
/* 800277B0 000246F0  80 05 00 00 */	lwz r0, 0(r5)
/* 800277B4 000246F4  90 06 00 00 */	stw r0, 0(r6)
/* 800277B8 000246F8  80 05 00 04 */	lwz r0, 4(r5)
/* 800277BC 000246FC  90 06 00 04 */	stw r0, 4(r6)
/* 800277C0 00024700  80 05 00 08 */	lwz r0, 8(r5)
/* 800277C4 00024704  90 06 00 08 */	stw r0, 8(r6)
/* 800277C8 00024708  80 05 00 0C */	lwz r0, 0xc(r5)
/* 800277CC 0002470C  90 06 00 0C */	stw r0, 0xc(r6)
/* 800277D0 00024710  80 05 00 10 */	lwz r0, 0x10(r5)
/* 800277D4 00024714  90 06 00 10 */	stw r0, 0x10(r6)
/* 800277D8 00024718  80 05 00 14 */	lwz r0, 0x14(r5)
/* 800277DC 0002471C  90 06 00 14 */	stw r0, 0x14(r6)
/* 800277E0 00024720  80 05 00 18 */	lwz r0, 0x18(r5)
/* 800277E4 00024724  90 06 00 18 */	stw r0, 0x18(r6)
/* 800277E8 00024728  80 05 00 1C */	lwz r0, 0x1c(r5)
/* 800277EC 0002472C  38 A5 00 20 */	addi r5, r5, 0x20
/* 800277F0 00024730  90 06 00 1C */	stw r0, 0x1c(r6)
/* 800277F4 00024734  38 C6 00 20 */	addi r6, r6, 0x20
/* 800277F8 00024738  42 00 FF B8 */	bdnz .L_800277B0
/* 800277FC 0002473C  70 63 00 07 */	andi. r3, r3, 7
/* 80027800 00024740  41 82 00 1C */	beq .L_8002781C
.L_80027804:
/* 80027804 00024744  7C 69 03 A6 */	mtctr r3
.L_80027808:
/* 80027808 00024748  80 05 00 00 */	lwz r0, 0(r5)
/* 8002780C 0002474C  38 A5 00 04 */	addi r5, r5, 4
/* 80027810 00024750  90 06 00 00 */	stw r0, 0(r6)
/* 80027814 00024754  38 C6 00 04 */	addi r6, r6, 4
/* 80027818 00024758  42 00 FF F0 */	bdnz .L_80027808
.L_8002781C:
/* 8002781C 0002475C  38 69 00 03 */	addi r3, r9, 3
/* 80027820 00024760  7C 09 F0 40 */	cmplw r9, r30
/* 80027824 00024764  7C 7E 18 50 */	subf r3, r30, r3
/* 80027828 00024768  80 DB 00 08 */	lwz r6, 8(r27)
/* 8002782C 0002476C  7D 25 4B 78 */	mr r5, r9
/* 80027830 00024770  54 63 F0 BE */	srwi r3, r3, 2
/* 80027834 00024774  40 81 00 6C */	ble .L_800278A0
/* 80027838 00024778  54 60 E8 FF */	rlwinm. r0, r3, 0x1d, 3, 0x1f
/* 8002783C 0002477C  7C 09 03 A6 */	mtctr r0
/* 80027840 00024780  41 82 00 50 */	beq .L_80027890
.L_80027844:
/* 80027844 00024784  80 05 FF FC */	lwz r0, -4(r5)
/* 80027848 00024788  90 06 FF FC */	stw r0, -4(r6)
/* 8002784C 0002478C  80 05 FF F8 */	lwz r0, -8(r5)
/* 80027850 00024790  90 06 FF F8 */	stw r0, -8(r6)
/* 80027854 00024794  80 05 FF F4 */	lwz r0, -0xc(r5)
/* 80027858 00024798  90 06 FF F4 */	stw r0, -0xc(r6)
/* 8002785C 0002479C  80 05 FF F0 */	lwz r0, -0x10(r5)
/* 80027860 000247A0  90 06 FF F0 */	stw r0, -0x10(r6)
/* 80027864 000247A4  80 05 FF EC */	lwz r0, -0x14(r5)
/* 80027868 000247A8  90 06 FF EC */	stw r0, -0x14(r6)
/* 8002786C 000247AC  80 05 FF E8 */	lwz r0, -0x18(r5)
/* 80027870 000247B0  90 06 FF E8 */	stw r0, -0x18(r6)
/* 80027874 000247B4  80 05 FF E4 */	lwz r0, -0x1c(r5)
/* 80027878 000247B8  90 06 FF E4 */	stw r0, -0x1c(r6)
/* 8002787C 000247BC  84 05 FF E0 */	lwzu r0, -0x20(r5)
/* 80027880 000247C0  94 06 FF E0 */	stwu r0, -0x20(r6)
/* 80027884 000247C4  42 00 FF C0 */	bdnz .L_80027844
/* 80027888 000247C8  70 63 00 07 */	andi. r3, r3, 7
/* 8002788C 000247CC  41 82 00 14 */	beq .L_800278A0
.L_80027890:
/* 80027890 000247D0  7C 69 03 A6 */	mtctr r3
.L_80027894:
/* 80027894 000247D4  84 05 FF FC */	lwzu r0, -4(r5)
/* 80027898 000247D8  94 06 FF FC */	stwu r0, -4(r6)
/* 8002789C 000247DC  42 00 FF F8 */	bdnz .L_80027894
.L_800278A0:
/* 800278A0 000247E0  7F C3 F3 78 */	mr r3, r30
/* 800278A4 000247E4  48 00 00 08 */	b .L_800278AC
.L_800278A8:
/* 800278A8 000247E8  38 63 00 04 */	addi r3, r3, 4
.L_800278AC:
/* 800278AC 000247EC  7C 03 40 40 */	cmplw r3, r8
/* 800278B0 000247F0  40 82 FF F8 */	bne .L_800278A8
/* 800278B4 000247F4  80 1B 00 08 */	lwz r0, 8(r27)
/* 800278B8 000247F8  7C 83 23 78 */	mr r3, r4
/* 800278BC 000247FC  7C 00 3A 14 */	add r0, r0, r7
/* 800278C0 00024800  90 1B 00 08 */	stw r0, 8(r27)
/* 800278C4 00024804  48 00 02 B0 */	b .L_80027B74
.L_800278C8:
/* 800278C8 00024808  38 66 00 03 */	addi r3, r6, 3
/* 800278CC 0002480C  7C 1E 30 40 */	cmplw r30, r6
/* 800278D0 00024810  7C 7E 18 50 */	subf r3, r30, r3
/* 800278D4 00024814  7D 06 43 78 */	mr r6, r8
/* 800278D8 00024818  7F C5 F3 78 */	mr r5, r30
/* 800278DC 0002481C  54 63 F0 BE */	srwi r3, r3, 2
/* 800278E0 00024820  40 80 00 7C */	bge .L_8002795C
/* 800278E4 00024824  54 60 E8 FF */	rlwinm. r0, r3, 0x1d, 3, 0x1f
/* 800278E8 00024828  7C 09 03 A6 */	mtctr r0
/* 800278EC 0002482C  41 82 00 58 */	beq .L_80027944
.L_800278F0:
/* 800278F0 00024830  80 05 00 00 */	lwz r0, 0(r5)
/* 800278F4 00024834  90 06 00 00 */	stw r0, 0(r6)
/* 800278F8 00024838  80 05 00 04 */	lwz r0, 4(r5)
/* 800278FC 0002483C  90 06 00 04 */	stw r0, 4(r6)
/* 80027900 00024840  80 05 00 08 */	lwz r0, 8(r5)
/* 80027904 00024844  90 06 00 08 */	stw r0, 8(r6)
/* 80027908 00024848  80 05 00 0C */	lwz r0, 0xc(r5)
/* 8002790C 0002484C  90 06 00 0C */	stw r0, 0xc(r6)
/* 80027910 00024850  80 05 00 10 */	lwz r0, 0x10(r5)
/* 80027914 00024854  90 06 00 10 */	stw r0, 0x10(r6)
/* 80027918 00024858  80 05 00 14 */	lwz r0, 0x14(r5)
/* 8002791C 0002485C  90 06 00 14 */	stw r0, 0x14(r6)
/* 80027920 00024860  80 05 00 18 */	lwz r0, 0x18(r5)
/* 80027924 00024864  90 06 00 18 */	stw r0, 0x18(r6)
/* 80027928 00024868  80 05 00 1C */	lwz r0, 0x1c(r5)
/* 8002792C 0002486C  38 A5 00 20 */	addi r5, r5, 0x20
/* 80027930 00024870  90 06 00 1C */	stw r0, 0x1c(r6)
/* 80027934 00024874  38 C6 00 20 */	addi r6, r6, 0x20
/* 80027938 00024878  42 00 FF B8 */	bdnz .L_800278F0
/* 8002793C 0002487C  70 63 00 07 */	andi. r3, r3, 7
/* 80027940 00024880  41 82 00 1C */	beq .L_8002795C
.L_80027944:
/* 80027944 00024884  7C 69 03 A6 */	mtctr r3
.L_80027948:
/* 80027948 00024888  80 05 00 00 */	lwz r0, 0(r5)
/* 8002794C 0002488C  38 A5 00 04 */	addi r5, r5, 4
/* 80027950 00024890  90 06 00 00 */	stw r0, 0(r6)
/* 80027954 00024894  38 C6 00 04 */	addi r6, r6, 4
/* 80027958 00024898  42 00 FF F0 */	bdnz .L_80027948
.L_8002795C:
/* 8002795C 0002489C  80 1B 00 08 */	lwz r0, 8(r27)
/* 80027960 000248A0  7F C3 F3 78 */	mr r3, r30
/* 80027964 000248A4  48 00 00 08 */	b .L_8002796C
.L_80027968:
/* 80027968 000248A8  38 63 00 04 */	addi r3, r3, 4
.L_8002796C:
/* 8002796C 000248AC  7C 03 00 40 */	cmplw r3, r0
/* 80027970 000248B0  40 82 FF F8 */	bne .L_80027968
/* 80027974 000248B4  80 1B 00 08 */	lwz r0, 8(r27)
/* 80027978 000248B8  7C 83 23 78 */	mr r3, r4
/* 8002797C 000248BC  7C 00 3A 14 */	add r0, r0, r7
/* 80027980 000248C0  90 1B 00 08 */	stw r0, 8(r27)
/* 80027984 000248C4  48 00 01 F0 */	b .L_80027B74
.L_80027988:
/* 80027988 000248C8  28 05 00 00 */	cmplwi r5, 0
/* 8002798C 000248CC  40 82 00 0C */	bne .L_80027998
/* 80027990 000248D0  38 80 00 00 */	li r4, 0
/* 80027994 000248D4  48 00 00 14 */	b .L_800279A8
.L_80027998:
/* 80027998 000248D8  80 1B 00 08 */	lwz r0, 8(r27)
/* 8002799C 000248DC  7C 05 00 50 */	subf r0, r5, r0
/* 800279A0 000248E0  7C 00 16 70 */	srawi r0, r0, 2
/* 800279A4 000248E4  7C 80 01 94 */	addze r4, r0
.L_800279A8:
/* 800279A8 000248E8  81 9B 00 10 */	lwz r12, 0x10(r27)
/* 800279AC 000248EC  7F 85 E3 78 */	mr r5, r28
/* 800279B0 000248F0  7F A4 E2 14 */	add r29, r4, r28
/* 800279B4 000248F4  7D 89 03 A6 */	mtctr r12
/* 800279B8 000248F8  4E 80 04 21 */	bctrl 
/* 800279BC 000248FC  7C 1D 18 40 */	cmplw r29, r3
/* 800279C0 00024900  7C 7F 1B 78 */	mr r31, r3
/* 800279C4 00024904  40 81 00 08 */	ble .L_800279CC
/* 800279C8 00024908  7F BF EB 78 */	mr r31, r29
.L_800279CC:
/* 800279CC 0002490C  57 E3 10 3A */	slwi r3, r31, 2
/* 800279D0 00024910  4B FF C4 D5 */	bl __nw__FUl
/* 800279D4 00024914  7C 60 1B 79 */	or. r0, r3, r3
/* 800279D8 00024918  40 82 00 0C */	bne .L_800279E4
/* 800279DC 0002491C  80 7B 00 08 */	lwz r3, 8(r27)
/* 800279E0 00024920  48 00 01 94 */	b .L_80027B74
.L_800279E4:
/* 800279E4 00024924  80 BB 00 04 */	lwz r5, 4(r27)
/* 800279E8 00024928  38 9E 00 03 */	addi r4, r30, 3
/* 800279EC 0002492C  93 61 00 08 */	stw r27, 8(r1)
/* 800279F0 00024930  7C 06 03 78 */	mr r6, r0
/* 800279F4 00024934  7C 05 F0 40 */	cmplw r5, r30
/* 800279F8 00024938  7C 85 20 50 */	subf r4, r5, r4
/* 800279FC 0002493C  90 01 00 0C */	stw r0, 0xc(r1)
/* 80027A00 00024940  54 84 F0 BE */	srwi r4, r4, 2
/* 80027A04 00024944  40 80 00 7C */	bge .L_80027A80
/* 80027A08 00024948  54 83 E8 FF */	rlwinm. r3, r4, 0x1d, 3, 0x1f
/* 80027A0C 0002494C  7C 69 03 A6 */	mtctr r3
/* 80027A10 00024950  41 82 00 58 */	beq .L_80027A68
.L_80027A14:
/* 80027A14 00024954  80 65 00 00 */	lwz r3, 0(r5)
/* 80027A18 00024958  90 66 00 00 */	stw r3, 0(r6)
/* 80027A1C 0002495C  80 65 00 04 */	lwz r3, 4(r5)
/* 80027A20 00024960  90 66 00 04 */	stw r3, 4(r6)
/* 80027A24 00024964  80 65 00 08 */	lwz r3, 8(r5)
/* 80027A28 00024968  90 66 00 08 */	stw r3, 8(r6)
/* 80027A2C 0002496C  80 65 00 0C */	lwz r3, 0xc(r5)
/* 80027A30 00024970  90 66 00 0C */	stw r3, 0xc(r6)
/* 80027A34 00024974  80 65 00 10 */	lwz r3, 0x10(r5)
/* 80027A38 00024978  90 66 00 10 */	stw r3, 0x10(r6)
/* 80027A3C 0002497C  80 65 00 14 */	lwz r3, 0x14(r5)
/* 80027A40 00024980  90 66 00 14 */	stw r3, 0x14(r6)
/* 80027A44 00024984  80 65 00 18 */	lwz r3, 0x18(r5)
/* 80027A48 00024988  90 66 00 18 */	stw r3, 0x18(r6)
/* 80027A4C 0002498C  80 65 00 1C */	lwz r3, 0x1c(r5)
/* 80027A50 00024990  38 A5 00 20 */	addi r5, r5, 0x20
/* 80027A54 00024994  90 66 00 1C */	stw r3, 0x1c(r6)
/* 80027A58 00024998  38 C6 00 20 */	addi r6, r6, 0x20
/* 80027A5C 0002499C  42 00 FF B8 */	bdnz .L_80027A14
/* 80027A60 000249A0  70 84 00 07 */	andi. r4, r4, 7
/* 80027A64 000249A4  41 82 00 1C */	beq .L_80027A80
.L_80027A68:
/* 80027A68 000249A8  7C 89 03 A6 */	mtctr r4
.L_80027A6C:
/* 80027A6C 000249AC  80 65 00 00 */	lwz r3, 0(r5)
/* 80027A70 000249B0  38 A5 00 04 */	addi r5, r5, 4
/* 80027A74 000249B4  90 66 00 00 */	stw r3, 0(r6)
/* 80027A78 000249B8  38 C6 00 04 */	addi r6, r6, 4
/* 80027A7C 000249BC  42 00 FF F0 */	bdnz .L_80027A6C
.L_80027A80:
/* 80027A80 000249C0  80 BB 00 08 */	lwz r5, 8(r27)
/* 80027A84 000249C4  57 83 10 3A */	slwi r3, r28, 2
/* 80027A88 000249C8  7C DD 33 78 */	mr r29, r6
/* 80027A8C 000249CC  7F C7 F3 78 */	mr r7, r30
/* 80027A90 000249D0  38 85 00 03 */	addi r4, r5, 3
/* 80027A94 000249D4  7C 1E 28 40 */	cmplw r30, r5
/* 80027A98 000249D8  7C 9E 20 50 */	subf r4, r30, r4
/* 80027A9C 000249DC  7C A6 1A 14 */	add r5, r6, r3
/* 80027AA0 000249E0  54 84 F0 BE */	srwi r4, r4, 2
/* 80027AA4 000249E4  40 80 00 7C */	bge .L_80027B20
/* 80027AA8 000249E8  54 83 E8 FF */	rlwinm. r3, r4, 0x1d, 3, 0x1f
/* 80027AAC 000249EC  7C 69 03 A6 */	mtctr r3
/* 80027AB0 000249F0  41 82 00 58 */	beq .L_80027B08
.L_80027AB4:
/* 80027AB4 000249F4  80 67 00 00 */	lwz r3, 0(r7)
/* 80027AB8 000249F8  90 65 00 00 */	stw r3, 0(r5)
/* 80027ABC 000249FC  80 67 00 04 */	lwz r3, 4(r7)
/* 80027AC0 00024A00  90 65 00 04 */	stw r3, 4(r5)
/* 80027AC4 00024A04  80 67 00 08 */	lwz r3, 8(r7)
/* 80027AC8 00024A08  90 65 00 08 */	stw r3, 8(r5)
/* 80027ACC 00024A0C  80 67 00 0C */	lwz r3, 0xc(r7)
/* 80027AD0 00024A10  90 65 00 0C */	stw r3, 0xc(r5)
/* 80027AD4 00024A14  80 67 00 10 */	lwz r3, 0x10(r7)
/* 80027AD8 00024A18  90 65 00 10 */	stw r3, 0x10(r5)
/* 80027ADC 00024A1C  80 67 00 14 */	lwz r3, 0x14(r7)
/* 80027AE0 00024A20  90 65 00 14 */	stw r3, 0x14(r5)
/* 80027AE4 00024A24  80 67 00 18 */	lwz r3, 0x18(r7)
/* 80027AE8 00024A28  90 65 00 18 */	stw r3, 0x18(r5)
/* 80027AEC 00024A2C  80 67 00 1C */	lwz r3, 0x1c(r7)
/* 80027AF0 00024A30  38 E7 00 20 */	addi r7, r7, 0x20
/* 80027AF4 00024A34  90 65 00 1C */	stw r3, 0x1c(r5)
/* 80027AF8 00024A38  38 A5 00 20 */	addi r5, r5, 0x20
/* 80027AFC 00024A3C  42 00 FF B8 */	bdnz .L_80027AB4
/* 80027B00 00024A40  70 84 00 07 */	andi. r4, r4, 7
/* 80027B04 00024A44  41 82 00 1C */	beq .L_80027B20
.L_80027B08:
/* 80027B08 00024A48  7C 89 03 A6 */	mtctr r4
.L_80027B0C:
/* 80027B0C 00024A4C  80 67 00 00 */	lwz r3, 0(r7)
/* 80027B10 00024A50  38 E7 00 04 */	addi r7, r7, 4
/* 80027B14 00024A54  90 65 00 00 */	stw r3, 0(r5)
/* 80027B18 00024A58  38 A5 00 04 */	addi r5, r5, 4
/* 80027B1C 00024A5C  42 00 FF F0 */	bdnz .L_80027B0C
.L_80027B20:
/* 80027B20 00024A60  80 7B 00 04 */	lwz r3, 4(r27)
/* 80027B24 00024A64  80 BB 00 08 */	lwz r5, 8(r27)
/* 80027B28 00024A68  7C 64 1B 78 */	mr r4, r3
/* 80027B2C 00024A6C  48 00 00 08 */	b .L_80027B34
.L_80027B30:
/* 80027B30 00024A70  38 84 00 04 */	addi r4, r4, 4
.L_80027B34:
/* 80027B34 00024A74  7C 04 28 40 */	cmplw r4, r5
/* 80027B38 00024A78  40 82 FF F8 */	bne .L_80027B30
/* 80027B3C 00024A7C  80 BB 00 04 */	lwz r5, 4(r27)
/* 80027B40 00024A80  80 9B 00 08 */	lwz r4, 8(r27)
/* 80027B44 00024A84  90 61 00 0C */	stw r3, 0xc(r1)
/* 80027B48 00024A88  7C 85 20 50 */	subf r4, r5, r4
/* 80027B4C 00024A8C  7C 84 16 70 */	srawi r4, r4, 2
/* 80027B50 00024A90  7C 84 01 94 */	addze r4, r4
/* 80027B54 00024A94  7C 9C 22 14 */	add r4, r28, r4
/* 80027B58 00024A98  54 84 10 3A */	slwi r4, r4, 2
/* 80027B5C 00024A9C  7C 80 22 14 */	add r4, r0, r4
/* 80027B60 00024AA0  90 9B 00 08 */	stw r4, 8(r27)
/* 80027B64 00024AA4  90 1B 00 04 */	stw r0, 4(r27)
/* 80027B68 00024AA8  93 FB 00 0C */	stw r31, 0xc(r27)
/* 80027B6C 00024AAC  4B FF C5 49 */	bl __dl__FPv
/* 80027B70 00024AB0  7F A3 EB 78 */	mr r3, r29
.L_80027B74:
/* 80027B74 00024AB4  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 80027B78 00024AB8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80027B7C 00024ABC  7C 08 03 A6 */	mtlr r0
/* 80027B80 00024AC0  38 21 00 30 */	addi r1, r1, 0x30
/* 80027B84 00024AC4  4E 80 00 20 */	blr 
.endfn "Insert_raw__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvUl"

.fn __dt__Q27JGadget20TVector_pointer_voidFv, global
/* 80027B88 00024AC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80027B8C 00024ACC  7C 08 02 A6 */	mflr r0
/* 80027B90 00024AD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80027B94 00024AD4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80027B98 00024AD8  7C 9F 23 78 */	mr r31, r4
/* 80027B9C 00024ADC  93 C1 00 08 */	stw r30, 8(r1)
/* 80027BA0 00024AE0  7C 7E 1B 79 */	or. r30, r3, r3
/* 80027BA4 00024AE4  41 82 00 D0 */	beq .L_80027C74
/* 80027BA8 00024AE8  41 82 00 BC */	beq .L_80027C64
/* 80027BAC 00024AEC  80 BE 00 08 */	lwz r5, 8(r30)
/* 80027BB0 00024AF0  80 9E 00 04 */	lwz r4, 4(r30)
/* 80027BB4 00024AF4  38 65 00 03 */	addi r3, r5, 3
/* 80027BB8 00024AF8  7C 05 28 40 */	cmplw r5, r5
/* 80027BBC 00024AFC  7C 65 18 50 */	subf r3, r5, r3
/* 80027BC0 00024B00  54 63 F0 BE */	srwi r3, r3, 2
/* 80027BC4 00024B04  40 80 00 7C */	bge .L_80027C40
/* 80027BC8 00024B08  54 60 E8 FF */	rlwinm. r0, r3, 0x1d, 3, 0x1f
/* 80027BCC 00024B0C  7C 09 03 A6 */	mtctr r0
/* 80027BD0 00024B10  41 82 00 58 */	beq .L_80027C28
.L_80027BD4:
/* 80027BD4 00024B14  80 05 00 00 */	lwz r0, 0(r5)
/* 80027BD8 00024B18  90 04 00 00 */	stw r0, 0(r4)
/* 80027BDC 00024B1C  80 05 00 04 */	lwz r0, 4(r5)
/* 80027BE0 00024B20  90 04 00 04 */	stw r0, 4(r4)
/* 80027BE4 00024B24  80 05 00 08 */	lwz r0, 8(r5)
/* 80027BE8 00024B28  90 04 00 08 */	stw r0, 8(r4)
/* 80027BEC 00024B2C  80 05 00 0C */	lwz r0, 0xc(r5)
/* 80027BF0 00024B30  90 04 00 0C */	stw r0, 0xc(r4)
/* 80027BF4 00024B34  80 05 00 10 */	lwz r0, 0x10(r5)
/* 80027BF8 00024B38  90 04 00 10 */	stw r0, 0x10(r4)
/* 80027BFC 00024B3C  80 05 00 14 */	lwz r0, 0x14(r5)
/* 80027C00 00024B40  90 04 00 14 */	stw r0, 0x14(r4)
/* 80027C04 00024B44  80 05 00 18 */	lwz r0, 0x18(r5)
/* 80027C08 00024B48  90 04 00 18 */	stw r0, 0x18(r4)
/* 80027C0C 00024B4C  80 05 00 1C */	lwz r0, 0x1c(r5)
/* 80027C10 00024B50  38 A5 00 20 */	addi r5, r5, 0x20
/* 80027C14 00024B54  90 04 00 1C */	stw r0, 0x1c(r4)
/* 80027C18 00024B58  38 84 00 20 */	addi r4, r4, 0x20
/* 80027C1C 00024B5C  42 00 FF B8 */	bdnz .L_80027BD4
/* 80027C20 00024B60  70 63 00 07 */	andi. r3, r3, 7
/* 80027C24 00024B64  41 82 00 1C */	beq .L_80027C40
.L_80027C28:
/* 80027C28 00024B68  7C 69 03 A6 */	mtctr r3
.L_80027C2C:
/* 80027C2C 00024B6C  80 05 00 00 */	lwz r0, 0(r5)
/* 80027C30 00024B70  38 A5 00 04 */	addi r5, r5, 4
/* 80027C34 00024B74  90 04 00 00 */	stw r0, 0(r4)
/* 80027C38 00024B78  38 84 00 04 */	addi r4, r4, 4
/* 80027C3C 00024B7C  42 00 FF F0 */	bdnz .L_80027C2C
.L_80027C40:
/* 80027C40 00024B80  80 1E 00 08 */	lwz r0, 8(r30)
/* 80027C44 00024B84  7C 83 23 78 */	mr r3, r4
/* 80027C48 00024B88  48 00 00 08 */	b .L_80027C50
.L_80027C4C:
/* 80027C4C 00024B8C  38 63 00 04 */	addi r3, r3, 4
.L_80027C50:
/* 80027C50 00024B90  7C 03 00 40 */	cmplw r3, r0
/* 80027C54 00024B94  40 82 FF F8 */	bne .L_80027C4C
/* 80027C58 00024B98  90 9E 00 08 */	stw r4, 8(r30)
/* 80027C5C 00024B9C  80 7E 00 04 */	lwz r3, 4(r30)
/* 80027C60 00024BA0  4B FF C4 55 */	bl __dl__FPv
.L_80027C64:
/* 80027C64 00024BA4  7F E0 07 35 */	extsh. r0, r31
/* 80027C68 00024BA8  40 81 00 0C */	ble .L_80027C74
/* 80027C6C 00024BAC  7F C3 F3 78 */	mr r3, r30
/* 80027C70 00024BB0  4B FF C4 45 */	bl __dl__FPv
.L_80027C74:
/* 80027C74 00024BB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80027C78 00024BB8  7F C3 F3 78 */	mr r3, r30
/* 80027C7C 00024BBC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80027C80 00024BC0  83 C1 00 08 */	lwz r30, 8(r1)
/* 80027C84 00024BC4  7C 08 03 A6 */	mtlr r0
/* 80027C88 00024BC8  38 21 00 10 */	addi r1, r1, 0x10
/* 80027C8C 00024BCC  4E 80 00 20 */	blr 
.endfn __dt__Q27JGadget20TVector_pointer_voidFv

.fn insert__Q27JGadget20TVector_pointer_voidFPPvRCPv, global
/* 80027C90 00024BD0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80027C94 00024BD4  7C 08 02 A6 */	mflr r0
/* 80027C98 00024BD8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80027C9C 00024BDC  48 00 00 15 */	bl "insert__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvRCPv"
/* 80027CA0 00024BE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80027CA4 00024BE4  7C 08 03 A6 */	mtlr r0
/* 80027CA8 00024BE8  38 21 00 10 */	addi r1, r1, 0x10
/* 80027CAC 00024BEC  4E 80 00 20 */	blr 
.endfn insert__Q27JGadget20TVector_pointer_voidFPPvRCPv

.fn "insert__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvRCPv", weak
/* 80027CB0 00024BF0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80027CB4 00024BF4  7C 08 02 A6 */	mflr r0
/* 80027CB8 00024BF8  7C A6 2B 78 */	mr r6, r5
/* 80027CBC 00024BFC  38 A0 00 01 */	li r5, 1
/* 80027CC0 00024C00  90 01 00 14 */	stw r0, 0x14(r1)
/* 80027CC4 00024C04  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80027CC8 00024C08  93 C1 00 08 */	stw r30, 8(r1)
/* 80027CCC 00024C0C  7C 7E 1B 78 */	mr r30, r3
/* 80027CD0 00024C10  80 03 00 04 */	lwz r0, 4(r3)
/* 80027CD4 00024C14  7C 00 20 50 */	subf r0, r0, r4
/* 80027CD8 00024C18  7C 00 16 70 */	srawi r0, r0, 2
/* 80027CDC 00024C1C  7F E0 01 94 */	addze r31, r0
/* 80027CE0 00024C20  4B FF F9 C1 */	bl "insert__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvUlRCPv"
/* 80027CE4 00024C24  80 7E 00 04 */	lwz r3, 4(r30)
/* 80027CE8 00024C28  57 E0 10 3A */	slwi r0, r31, 2
/* 80027CEC 00024C2C  7C 63 02 14 */	add r3, r3, r0
/* 80027CF0 00024C30  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80027CF4 00024C34  83 C1 00 08 */	lwz r30, 8(r1)
/* 80027CF8 00024C38  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80027CFC 00024C3C  7C 08 03 A6 */	mtlr r0
/* 80027D00 00024C40  38 21 00 10 */	addi r1, r1, 0x10
/* 80027D04 00024C44  4E 80 00 20 */	blr 
.endfn "insert__Q27JGadget38TVector<Pv,Q27JGadget14TAllocator<Pv>>FPPvRCPv"

.fn erase__Q27JGadget20TVector_pointer_voidFPPvPPv, global
/* 80027D08 00024C48  80 E3 00 08 */	lwz r7, 8(r3)
/* 80027D0C 00024C4C  38 C7 00 03 */	addi r6, r7, 3
/* 80027D10 00024C50  7C 05 38 40 */	cmplw r5, r7
/* 80027D14 00024C54  7C C5 30 50 */	subf r6, r5, r6
/* 80027D18 00024C58  7C 87 23 78 */	mr r7, r4
/* 80027D1C 00024C5C  54 C6 F0 BE */	srwi r6, r6, 2
/* 80027D20 00024C60  40 80 00 7C */	bge .L_80027D9C
/* 80027D24 00024C64  54 C0 E8 FF */	rlwinm. r0, r6, 0x1d, 3, 0x1f
/* 80027D28 00024C68  7C 09 03 A6 */	mtctr r0
/* 80027D2C 00024C6C  41 82 00 58 */	beq .L_80027D84
.L_80027D30:
/* 80027D30 00024C70  80 05 00 00 */	lwz r0, 0(r5)
/* 80027D34 00024C74  90 07 00 00 */	stw r0, 0(r7)
/* 80027D38 00024C78  80 05 00 04 */	lwz r0, 4(r5)
/* 80027D3C 00024C7C  90 07 00 04 */	stw r0, 4(r7)
/* 80027D40 00024C80  80 05 00 08 */	lwz r0, 8(r5)
/* 80027D44 00024C84  90 07 00 08 */	stw r0, 8(r7)
/* 80027D48 00024C88  80 05 00 0C */	lwz r0, 0xc(r5)
/* 80027D4C 00024C8C  90 07 00 0C */	stw r0, 0xc(r7)
/* 80027D50 00024C90  80 05 00 10 */	lwz r0, 0x10(r5)
/* 80027D54 00024C94  90 07 00 10 */	stw r0, 0x10(r7)
/* 80027D58 00024C98  80 05 00 14 */	lwz r0, 0x14(r5)
/* 80027D5C 00024C9C  90 07 00 14 */	stw r0, 0x14(r7)
/* 80027D60 00024CA0  80 05 00 18 */	lwz r0, 0x18(r5)
/* 80027D64 00024CA4  90 07 00 18 */	stw r0, 0x18(r7)
/* 80027D68 00024CA8  80 05 00 1C */	lwz r0, 0x1c(r5)
/* 80027D6C 00024CAC  38 A5 00 20 */	addi r5, r5, 0x20
/* 80027D70 00024CB0  90 07 00 1C */	stw r0, 0x1c(r7)
/* 80027D74 00024CB4  38 E7 00 20 */	addi r7, r7, 0x20
/* 80027D78 00024CB8  42 00 FF B8 */	bdnz .L_80027D30
/* 80027D7C 00024CBC  70 C6 00 07 */	andi. r6, r6, 7
/* 80027D80 00024CC0  41 82 00 1C */	beq .L_80027D9C
.L_80027D84:
/* 80027D84 00024CC4  7C C9 03 A6 */	mtctr r6
.L_80027D88:
/* 80027D88 00024CC8  80 05 00 00 */	lwz r0, 0(r5)
/* 80027D8C 00024CCC  38 A5 00 04 */	addi r5, r5, 4
/* 80027D90 00024CD0  90 07 00 00 */	stw r0, 0(r7)
/* 80027D94 00024CD4  38 E7 00 04 */	addi r7, r7, 4
/* 80027D98 00024CD8  42 00 FF F0 */	bdnz .L_80027D88
.L_80027D9C:
/* 80027D9C 00024CDC  80 03 00 08 */	lwz r0, 8(r3)
/* 80027DA0 00024CE0  7C E5 3B 78 */	mr r5, r7
/* 80027DA4 00024CE4  48 00 00 08 */	b .L_80027DAC
.L_80027DA8:
/* 80027DA8 00024CE8  38 A5 00 04 */	addi r5, r5, 4
.L_80027DAC:
/* 80027DAC 00024CEC  7C 05 00 40 */	cmplw r5, r0
/* 80027DB0 00024CF0  40 82 FF F8 */	bne .L_80027DA8
/* 80027DB4 00024CF4  90 E3 00 08 */	stw r7, 8(r3)
/* 80027DB8 00024CF8  7C 83 23 78 */	mr r3, r4
/* 80027DBC 00024CFC  4E 80 00 20 */	blr 
.endfn erase__Q27JGadget20TVector_pointer_voidFPPvPPv
