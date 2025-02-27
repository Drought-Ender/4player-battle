.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
	.4byte __sinit_gameflow_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
# Epoch note: none of these strings are named. 
.obj str_RootMenu, local
	.asciz "Root Menu"
.endobj str_RootMenu
.balign 4
.obj str_objedit, local
	.asciz "Object Editor"
.endobj str_objedit
.balign 4
.obj str_sgame, local
	.asciz "Single Game"
.endobj str_sgame
.balign 4
.obj str_cgame, local
	.asciz "Challenge Game"
.endobj str_cgame
.balign 4
.obj str_test_challenge, local
	.asciz "Test Challenge"
.endobj str_test_challenge
.balign 4
.obj str_test_teki, local
	.asciz "Teki Test"
.endobj str_test_teki
.balign 4
.obj str_animEdit, local
	.asciz "Anim Editor"
.endobj str_animEdit
.balign 4
.obj str_mapEdit, local
	.asciz "Map Parts Editor"
.endobj str_mapEdit
.balign 4
.obj str_texview, local
	.asciz "Tex Viewer"
.endobj str_texview
.balign 4
.obj str_ogtest, local
	.asciz "Ogawa Screen Test"
.endobj str_ogtest
.balign 4
.obj str_yamashita, local
	.asciz "Yamashita"
.endobj str_yamashita
.balign 4
.obj str_nishimura, local
	.asciz "Nishimura"
.endobj str_nishimura
.balign 4
.obj str_nishimura2, local
	.asciz "Nishimura2"
.endobj str_nishimura2
.balign 4
.obj str_morimura, local
	.asciz "Morimura"
.endobj str_morimura
.balign 4
.obj str_2D_Debug, local
	.asciz "2D Debug"
.endobj str_2D_Debug
.balign 4
.obj str_caveEditor, local
	.asciz "Cave Editor"
.endobj str_caveEditor
.balign 4
.obj str_cameraEditor, local
	.asciz "JStudio CameraEditor"
.endobj str_cameraEditor
.balign 4
.obj str_movieTest, local
	.asciz "Movie Test"
.endobj str_movieTest
.balign 4
.obj str_kandoTest, local
	.asciz "JStudio Kando Test"
.endobj str_kandoTest
.balign 4
.obj str_pelletTest, local
	.asciz "Pellet Test"
.endobj str_pelletTest
.balign 4
.obj str_mainTitle, local
	.asciz "Main Title"
.endobj str_mainTitle
.balign 4
.obj str_msgPreviewer, local
	.asciz "Message Previewer"
.endobj str_msgPreviewer
.balign 4
.obj str_ebiMainTitle, local
	.asciz "Ebi Main Title"
.endobj str_ebiMainTitle
.balign 4
.obj str_E3_Thanks, local
	.asciz "E3 Thanks Section"
.endobj str_E3_Thanks
.balign 4
.obj str_ebimunEff, local
	.asciz "Ebimun Effect"
.endobj str_ebimunEff
.balign 4
.obj str_2D_Debug2, local
	.asciz "2D Debug2"
.endobj str_2D_Debug2
.balign 4
.obj lbl_80499BC8, local
	.asciz "gameflow.cpp"
.endobj lbl_80499BC8
.balign 4
.obj lbl_80499BD8, local
	.asciz "Unknown SectionFlag. %d \n"
.endobj lbl_80499BD8
.balign 4
.obj lbl_80499BF4, local
	.asciz "P2Assert"
.endobj lbl_80499BF4

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST
.balign 4
.obj "sSectionInfo__22@unnamed@gameflow_cpp@", local
	.4byte str_RootMenu
	.4byte 0x00000000
	.4byte str_objedit
	.4byte 0x01010000
	.4byte str_sgame
	.4byte 0x02010000
	.4byte str_cgame
	.4byte 0x03010000
	.4byte str_test_challenge
	.4byte 0x04010100
	.4byte str_test_teki
	.4byte 0x05010000
	.4byte str_animEdit
	.4byte 0x06010000
	.4byte str_mapEdit
	.4byte 0x07010000
	.4byte str_texview
	.4byte 0x08010000
	.4byte str_Ogawa
	.4byte 0x09010000
	.4byte str_ogtest
	.4byte 0x1C010000
	.4byte str_Hikino
	.4byte 0x0A010000
	.4byte str_yamashita
	.4byte 0x0B010000
	.4byte str_nishimura
	.4byte 0x0C010000
	.4byte str_nishimura2
	.4byte 0x0D010000
	.4byte str_morimura
	.4byte 0x0E010000
	.4byte str_2D_Debug
	.4byte 0x1A010100
	.4byte str_Fujino
	.4byte 0x1B010000
	.4byte str_Ebisawa
	.4byte 0x0F010000
	.4byte str_caveEditor
	.4byte 0x10010000
	.4byte str_cameraEditor
	.4byte 0x11010000
	.4byte str_movieTest
	.4byte 0x12010000
	.4byte str_kandoTest
	.4byte 0x13010000
	.4byte str_pelletTest
	.4byte 0x14010000
	.4byte str_boot
	.4byte 0x15000000
	.4byte str_mainTitle
	.4byte 0x16010000
	.4byte str_demo
	.4byte 0x17010000
	.4byte str_msgPreviewer
	.4byte 0x18010100
	.4byte str_ebiMainTitle
	.4byte 0x19010000
	.4byte str_E3_Thanks
	.4byte 0x1D010000
	.4byte str_vsgame
	.4byte 0x1E010000
	.4byte str_ebimunEff
	.4byte 0x1F010000
	.4byte str_2D_Debug2
	.4byte 0x20010100
	.4byte str_exp_c
	.4byte 0x21000000
	.4byte str_exp_s
	.4byte 0x22000000
.endobj "sSectionInfo__22@unnamed@gameflow_cpp@"
.balign 4
.obj __vt__8GameFlow, global
	.4byte 0
	.4byte 0
	.4byte run__8GameFlowFv
	.4byte getCurrentSection__8GameFlowFv
.endobj __vt__8GameFlow
.balign 4
.obj __vt__11ISectionMgr, weak
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte getCurrentSection__11ISectionMgrFv
.endobj __vt__11ISectionMgr

.section .sdata, "wa"  # 0x80514680 - 0x80514D80
.balign 8
.obj mActiveSectionFlag__8GameFlow, global
	.4byte 21
.endobj mActiveSectionFlag__8GameFlow

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
.obj str_Ogawa, local
	.asciz "Ogawa"
.endobj str_Ogawa
.balign 4
.obj str_Hikino, local
	.asciz "Hikino"
.endobj str_Hikino
.balign 4
.obj str_Fujino, local
	.asciz "Fujino"
.endobj str_Fujino
.balign 4
.obj str_Ebisawa, local
	.asciz "Ebisawa"
.endobj str_Ebisawa
.balign 4
.obj str_boot, local
	.asciz "Boot"
.endobj str_boot
.balign 4
.obj str_demo, local
	.asciz "Demo"
.endobj str_demo
.balign 4
.obj str_vsgame, local
	.asciz "VS Game"
.endobj str_vsgame
.balign 4
.obj str_exp_c, local
	.asciz "EXP_C"
.endobj str_exp_c
.balign 4
.obj str_exp_s, local
	.asciz "EXP_S"
.endobj str_exp_s

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__8GameFlowFv, global
/* 804241A4 004210E4  3C 80 80 4F */	lis r4, __vt__11ISectionMgr@ha
/* 804241A8 004210E8  3C A0 80 4F */	lis r5, __vt__8GameFlow@ha
/* 804241AC 004210EC  38 04 BD 24 */	addi r0, r4, __vt__11ISectionMgr@l
/* 804241B0 004210F0  38 80 00 15 */	li r4, 0x15
/* 804241B4 004210F4  90 03 00 00 */	stw r0, 0(r3)
/* 804241B8 004210F8  38 A5 BD 14 */	addi r5, r5, __vt__8GameFlow@l
/* 804241BC 004210FC  38 00 00 00 */	li r0, 0
/* 804241C0 00421100  90 A3 00 00 */	stw r5, 0(r3)
/* 804241C4 00421104  90 8D 86 78 */	stw r4, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 804241C8 00421108  90 03 00 04 */	stw r0, 4(r3)
/* 804241CC 0042110C  4E 80 00 20 */	blr 
.endfn __ct__8GameFlowFv

.fn run__8GameFlowFv, global
/* 804241D0 00421110  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 804241D4 00421114  7C 08 02 A6 */	mflr r0
/* 804241D8 00421118  90 01 00 44 */	stw r0, 0x44(r1)
/* 804241DC 0042111C  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 804241E0 00421120  93 C1 00 38 */	stw r30, 0x38(r1)
/* 804241E4 00421124  93 A1 00 34 */	stw r29, 0x34(r1)
/* 804241E8 00421128  7C 7D 1B 78 */	mr r29, r3
.L_804241EC:
/* 804241EC 0042112C  83 ED 88 2C */	lwz r31, sCurrentHeap__7JKRHeap@sda21(r13)
/* 804241F0 00421130  38 00 00 00 */	li r0, 0
/* 804241F4 00421134  90 01 00 08 */	stw r0, 8(r1)
/* 804241F8 00421138  28 1F 00 00 */	cmplwi r31, 0
/* 804241FC 0042113C  90 01 00 0C */	stw r0, 0xc(r1)
/* 80424200 00421140  38 E0 FF FF */	li r7, -1
/* 80424204 00421144  38 C0 00 01 */	li r6, 1
/* 80424208 00421148  38 00 00 00 */	li r0, 0
/* 8042420C 0042114C  93 E1 00 18 */	stw r31, 0x18(r1)
/* 80424210 00421150  7F E3 FB 78 */	mr r3, r31
/* 80424214 00421154  38 81 00 08 */	addi r4, r1, 8
/* 80424218 00421158  90 E1 00 1C */	stw r7, 0x1c(r1)
/* 8042421C 0042115C  38 A0 FF FF */	li r5, -1
/* 80424220 00421160  98 C1 00 20 */	stb r6, 0x20(r1)
/* 80424224 00421164  90 01 00 24 */	stw r0, 0x24(r1)
/* 80424228 00421168  90 E1 00 28 */	stw r7, 0x28(r1)
/* 8042422C 0042116C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80424230 00421170  81 8C 00 54 */	lwz r12, 0x54(r12)
/* 80424234 00421174  7D 89 03 A6 */	mtctr r12
/* 80424238 00421178  4E 80 04 21 */	bctrl 
/* 8042423C 0042117C  7F E3 FB 78 */	mr r3, r31
/* 80424240 00421180  4B BF F5 75 */	bl getFreeSize__7JKRHeapFv
/* 80424244 00421184  7F E4 FB 78 */	mr r4, r31
/* 80424248 00421188  38 A0 00 01 */	li r5, 1
/* 8042424C 0042118C  4B BF BC 7D */	bl create__10JKRExpHeapFUlP7JKRHeapb
/* 80424250 00421190  7C 7E 1B 78 */	mr r30, r3
/* 80424254 00421194  7F A3 EB 78 */	mr r3, r29
/* 80424258 00421198  48 00 00 55 */	bl setSection__8GameFlowFv
/* 8042425C 0042119C  80 7D 00 04 */	lwz r3, 4(r29)
/* 80424260 004211A0  81 83 00 00 */	lwz r12, 0(r3)
/* 80424264 004211A4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80424268 004211A8  7D 89 03 A6 */	mtctr r12
/* 8042426C 004211AC  4E 80 04 21 */	bctrl 
/* 80424270 004211B0  80 7D 00 04 */	lwz r3, 4(r29)
/* 80424274 004211B4  81 83 00 00 */	lwz r12, 0(r3)
/* 80424278 004211B8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8042427C 004211BC  7D 89 03 A6 */	mtctr r12
/* 80424280 004211C0  4E 80 04 21 */	bctrl 
/* 80424284 004211C4  80 7D 00 04 */	lwz r3, 4(r29)
/* 80424288 004211C8  4B FF FC F5 */	bl exit__7SectionFv
/* 8042428C 004211CC  7F C3 F3 78 */	mr r3, r30
/* 80424290 004211D0  4B BF F3 25 */	bl destroy__7JKRHeapFv
/* 80424294 004211D4  7F E3 FB 78 */	mr r3, r31
/* 80424298 004211D8  4B BF F3 0D */	bl becomeCurrentHeap__7JKRHeapFv
/* 8042429C 004211DC  38 61 00 08 */	addi r3, r1, 8
/* 804242A0 004211E0  38 80 FF FF */	li r4, -1
/* 804242A4 004211E4  4B BF FE 59 */	bl __dt__Q27JKRHeap6TStateFv
/* 804242A8 004211E8  4B FF FF 44 */	b .L_804241EC
.endfn run__8GameFlowFv

.if version == 1
.fn setSection__8GameFlowFv, global
/* 804242AC 004211EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 804242B0 004211F0  7C 08 02 A6 */	mflr r0
/* 804242B4 004211F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 804242B8 004211F8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 804242BC 004211FC  7C 7F 1B 78 */	mr r31, r3
/* 804242C0 00421200  80 6D 88 2C */	lwz r3, sCurrentHeap__7JKRHeap@sda21(r13)
/* 804242C4 00421204  4B BF F4 F1 */	bl getFreeSize__7JKRHeapFv
/* 804242C8 00421208  80 CD 86 78 */	lwz r6, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 804242CC 0042120C  2C 06 00 15 */	cmpwi r6, 0x15
/* 804242D0 00421210  41 82 00 14 */	beq .L_804242E4
/* 804242D4 00421214  40 80 00 68 */	bge .L_8042433C
/* 804242D8 00421218  2C 06 00 00 */	cmpwi r6, 0
/* 804242DC 0042121C  41 82 00 34 */	beq .L_80424310
/* 804242E0 00421220  48 00 00 5C */	b .L_8042433C
.L_804242E4:
/* 804242E4 00421224  38 60 00 E8 */	li r3, 0x108
/* 804242E8 00421228  4B BF FB BD */	bl __nw__FUl
/* 804242EC 0042122C  7C 60 1B 79 */	or. r0, r3, r3
/* 804242F0 00421230  41 82 00 10 */	beq .L_80424300
/* 804242F4 00421234  80 8D 88 2C */	lwz r4, sCurrentHeap__7JKRHeap@sda21(r13)
/* 804242F8 00421238  48 02 3A 75 */	bl __ct__11BootSectionFP7JKRHeap
/* 804242FC 0042123C  7C 60 1B 78 */	mr r0, r3
.L_80424300:
/* 80424300 00421240  90 1F 00 04 */	stw r0, 4(r31)
/* 80424304 00421244  38 00 00 00 */	li r0, 0
/* 80424308 00421248  90 0D 86 78 */	stw r0, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 8042430C 0042124C  48 00 00 4C */	b .L_80424358
.L_80424310:
/* 80424310 00421250  38 60 00 44 */	li r3, 0x60
/* 80424314 00421254  4B BF FB 91 */	bl __nw__FUl
/* 80424318 00421258  7C 60 1B 79 */	or. r0, r3, r3
/* 8042431C 0042125C  41 82 00 10 */	beq .L_8042432C
/* 80424320 00421260  80 8D 88 2C */	lwz r4, sCurrentHeap__7JKRHeap@sda21(r13)
/* 80424324 00421264  48 02 87 A9 */	bl __ct__15RootMenuSectionFP7JKRHeap
/* 80424328 00421268  7C 60 1B 78 */	mr r0, r3
.L_8042432C:
/* 8042432C 0042126C  90 1F 00 04 */	stw r0, 4(r31)
/* 80424330 00421270  38 00 00 16 */	li r0, 0x16
/* 80424334 00421274  90 0D 86 78 */	stw r0, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 80424338 00421278  48 00 00 20 */	b .L_80424358
.L_8042433C:
/* 8042433C 0042127C  3C 60 80 4A */	lis r3, lbl_80499BC8@ha
/* 80424340 00421280  3C 80 80 4A */	lis r4, lbl_80499BD8@ha
/* 80424344 00421284  38 A4 9B D8 */	addi r5, r4, lbl_80499BD8@l
/* 80424348 00421288  38 63 9B C8 */	addi r3, r3, lbl_80499BC8@l
/* 8042434C 0042128C  38 80 00 BC */	li r4, 0xbc
/* 80424350 00421290  4C C6 31 82 */	crclr 6
/* 80424354 00421294  4B C0 62 ED */	bl panic_f__12JUTExceptionFPCciPCce
.L_80424358:
/* 80424358 00421298  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8042435C 0042129C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80424360 004212A0  7C 08 03 A6 */	mtlr r0
/* 80424364 004212A4  38 21 00 10 */	addi r1, r1, 0x10
/* 80424368 004212A8  4E 80 00 20 */	blr 
.endfn setSection__8GameFlowFv
.else
.fn setSection__8GameFlowFv, global
/* 804242AC 004211EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 804242B0 004211F0  7C 08 02 A6 */	mflr r0
/* 804242B4 004211F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 804242B8 004211F8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 804242BC 004211FC  7C 7F 1B 78 */	mr r31, r3
/* 804242C0 00421200  80 6D 88 2C */	lwz r3, sCurrentHeap__7JKRHeap@sda21(r13)
/* 804242C4 00421204  4B BF F4 F1 */	bl getFreeSize__7JKRHeapFv
/* 804242C8 00421208  80 CD 86 78 */	lwz r6, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 804242CC 0042120C  2C 06 00 15 */	cmpwi r6, 0x15
/* 804242D0 00421210  41 82 00 14 */	beq .L_804242E4
/* 804242D4 00421214  40 80 00 68 */	bge .L_8042433C
/* 804242D8 00421218  2C 06 00 00 */	cmpwi r6, 0
/* 804242DC 0042121C  41 82 00 34 */	beq .L_80424310
/* 804242E0 00421220  48 00 00 5C */	b .L_8042433C
.L_804242E4:
/* 804242E4 00421224  38 60 00 E8 */	li r3, 0xe8
/* 804242E8 00421228  4B BF FB BD */	bl __nw__FUl
/* 804242EC 0042122C  7C 60 1B 79 */	or. r0, r3, r3
/* 804242F0 00421230  41 82 00 10 */	beq .L_80424300
/* 804242F4 00421234  80 8D 88 2C */	lwz r4, sCurrentHeap__7JKRHeap@sda21(r13)
/* 804242F8 00421238  48 02 3A 75 */	bl __ct__11BootSectionFP7JKRHeap
/* 804242FC 0042123C  7C 60 1B 78 */	mr r0, r3
.L_80424300:
/* 80424300 00421240  90 1F 00 04 */	stw r0, 4(r31)
/* 80424304 00421244  38 00 00 00 */	li r0, 0
/* 80424308 00421248  90 0D 86 78 */	stw r0, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 8042430C 0042124C  48 00 00 4C */	b .L_80424358
.L_80424310:
/* 80424310 00421250  38 60 00 44 */	li r3, 0x44
/* 80424314 00421254  4B BF FB 91 */	bl __nw__FUl
/* 80424318 00421258  7C 60 1B 79 */	or. r0, r3, r3
/* 8042431C 0042125C  41 82 00 10 */	beq .L_8042432C
/* 80424320 00421260  80 8D 88 2C */	lwz r4, sCurrentHeap__7JKRHeap@sda21(r13)
/* 80424324 00421264  48 02 87 A9 */	bl __ct__15RootMenuSectionFP7JKRHeap
/* 80424328 00421268  7C 60 1B 78 */	mr r0, r3
.L_8042432C:
/* 8042432C 0042126C  90 1F 00 04 */	stw r0, 4(r31)
/* 80424330 00421270  38 00 00 16 */	li r0, 0x16
/* 80424334 00421274  90 0D 86 78 */	stw r0, mActiveSectionFlag__8GameFlow@sda21(r13)
/* 80424338 00421278  48 00 00 20 */	b .L_80424358
.L_8042433C:
/* 8042433C 0042127C  3C 60 80 4A */	lis r3, lbl_80499BC8@ha
/* 80424340 00421280  3C 80 80 4A */	lis r4, lbl_80499BD8@ha
/* 80424344 00421284  38 A4 9B D8 */	addi r5, r4, lbl_80499BD8@l
/* 80424348 00421288  38 63 9B C8 */	addi r3, r3, lbl_80499BC8@l
/* 8042434C 0042128C  38 80 00 BC */	li r4, 0xbc
/* 80424350 00421290  4C C6 31 82 */	crclr 6
/* 80424354 00421294  4B C0 62 ED */	bl panic_f__12JUTExceptionFPCciPCce
.L_80424358:
/* 80424358 00421298  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8042435C 0042129C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80424360 004212A0  7C 08 03 A6 */	mtlr r0
/* 80424364 004212A4  38 21 00 10 */	addi r1, r1, 0x10
/* 80424368 004212A8  4E 80 00 20 */	blr 
.endfn setSection__8GameFlowFv
.endif

.fn getSectionInfo__8GameFlowFi, global
/* 8042436C 004212AC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80424370 004212B0  7C 08 02 A6 */	mflr r0
/* 80424374 004212B4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80424378 004212B8  38 00 00 00 */	li r0, 0
/* 8042437C 004212BC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80424380 004212C0  3B E0 00 00 */	li r31, 0
/* 80424384 004212C4  93 C1 00 08 */	stw r30, 8(r1)
/* 80424388 004212C8  7C 7E 1B 79 */	or. r30, r3, r3
/* 8042438C 004212CC  41 80 00 10 */	blt .L_8042439C
/* 80424390 004212D0  2C 1E 00 23 */	cmpwi r30, 0x23
/* 80424394 004212D4  40 80 00 08 */	bge .L_8042439C
/* 80424398 004212D8  38 00 00 01 */	li r0, 1
.L_8042439C:
/* 8042439C 004212DC  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 804243A0 004212E0  40 82 00 20 */	bne .L_804243C0
/* 804243A4 004212E4  3C 60 80 4A */	lis r3, lbl_80499BC8@ha
/* 804243A8 004212E8  3C A0 80 4A */	lis r5, lbl_80499BF4@ha
/* 804243AC 004212EC  38 63 9B C8 */	addi r3, r3, lbl_80499BC8@l
/* 804243B0 004212F0  38 80 00 C9 */	li r4, 0xc9
/* 804243B4 004212F4  38 A5 9B F4 */	addi r5, r5, lbl_80499BF4@l
/* 804243B8 004212F8  4C C6 31 82 */	crclr 6
/* 804243BC 004212FC  4B C0 62 85 */	bl panic_f__12JUTExceptionFPCciPCce
.L_804243C0:
/* 804243C0 00421300  3C 60 80 4F */	lis r3, "sSectionInfo__22@unnamed@gameflow_cpp@"@ha
/* 804243C4 00421304  38 00 00 23 */	li r0, 0x23
/* 804243C8 00421308  38 63 BB FC */	addi r3, r3, "sSectionInfo__22@unnamed@gameflow_cpp@"@l
/* 804243CC 0042130C  38 80 00 00 */	li r4, 0
/* 804243D0 00421310  7C 09 03 A6 */	mtctr r0
.L_804243D4:
/* 804243D4 00421314  88 03 00 04 */	lbz r0, 4(r3)
/* 804243D8 00421318  7C 1E 00 00 */	cmpw r30, r0
/* 804243DC 0042131C  40 82 00 18 */	bne .L_804243F4
/* 804243E0 00421320  3C 60 80 4F */	lis r3, "sSectionInfo__22@unnamed@gameflow_cpp@"@ha
/* 804243E4 00421324  54 84 18 38 */	slwi r4, r4, 3
/* 804243E8 00421328  38 03 BB FC */	addi r0, r3, "sSectionInfo__22@unnamed@gameflow_cpp@"@l
/* 804243EC 0042132C  7F E0 22 14 */	add r31, r0, r4
/* 804243F0 00421330  48 00 00 10 */	b .L_80424400
.L_804243F4:
/* 804243F4 00421334  38 63 00 08 */	addi r3, r3, 8
/* 804243F8 00421338  38 84 00 01 */	addi r4, r4, 1
/* 804243FC 0042133C  42 00 FF D8 */	bdnz .L_804243D4
.L_80424400:
/* 80424400 00421340  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80424404 00421344  7F E3 FB 78 */	mr r3, r31
/* 80424408 00421348  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8042440C 0042134C  83 C1 00 08 */	lwz r30, 8(r1)
/* 80424410 00421350  7C 08 03 A6 */	mtlr r0
/* 80424414 00421354  38 21 00 10 */	addi r1, r1, 0x10
/* 80424418 00421358  4E 80 00 20 */	blr 
.endfn getSectionInfo__8GameFlowFi


.fn getCurrentSection__8GameFlowFv, weak
/* 80424564 004214A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80424568 004214A8  7C 08 02 A6 */	mflr r0
/* 8042456C 004214AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80424570 004214B0  80 63 00 04 */	lwz r3, 4(r3)
/* 80424574 004214B4  28 03 00 00 */	cmplwi r3, 0
/* 80424578 004214B8  41 82 00 18 */	beq .L_80424590
/* 8042457C 004214BC  81 83 00 00 */	lwz r12, 0(r3)
/* 80424580 004214C0  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80424584 004214C4  7D 89 03 A6 */	mtctr r12
/* 80424588 004214C8  4E 80 04 21 */	bctrl 
/* 8042458C 004214CC  48 00 00 08 */	b .L_80424594
.L_80424590:
/* 80424590 004214D0  38 60 00 00 */	li r3, 0
.L_80424594:
/* 80424594 004214D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80424598 004214D8  7C 08 03 A6 */	mtlr r0
/* 8042459C 004214DC  38 21 00 10 */	addi r1, r1, 0x10
/* 804245A0 004214E0  4E 80 00 20 */	blr 
.endfn getCurrentSection__8GameFlowFv

.fn __sinit_gameflow_cpp, local
/* 804245A4 004214E4  3C 80 80 51 */	lis r4, __float_nan@ha
/* 804245A8 004214E8  38 00 FF FF */	li r0, -1
/* 804245AC 004214EC  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 804245B0 004214F0  3C 60 80 4F */	lis r3, govNAN___Q24Game5P2JST@ha
/* 804245B4 004214F4  90 0D 9B 08 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 804245B8 004214F8  D4 03 BB F0 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 804245BC 004214FC  D0 0D 9B 0C */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 804245C0 00421500  D0 03 00 04 */	stfs f0, 4(r3)
/* 804245C4 00421504  D0 03 00 08 */	stfs f0, 8(r3)
/* 804245C8 00421508  4E 80 00 20 */	blr 
.endfn __sinit_gameflow_cpp
