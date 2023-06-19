.include "macros.inc"
.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj lbl_804A8810, local
	.4byte .L_800E9EEC
	.4byte .L_800E9F08
	.4byte .L_800E9F24
	.4byte .L_800E9F40
	.4byte .L_800E9F94
	.4byte .L_800E9FB0
	.4byte .L_800E9FCC
	.4byte .L_800E9FE8
	.4byte .L_800E9F5C
	.4byte .L_800EA004
	.4byte .L_800EA034
	.4byte .L_800EA064
	.4byte .L_800EA094
	.4byte .L_800EA0C4
	.4byte .L_800EA0F4
	.4byte .L_800EA124
	.4byte .L_800EA154
	.4byte .L_800EA180
	.4byte .L_800EA190
	.4byte .L_800EA1A0
	.4byte .L_800EA1B0
	.4byte .L_800E9F78
	.4byte .L_800EA1BC
.endobj lbl_804A8810
.obj lbl_804A886C, local
	.4byte .L_800E9AC0
	.4byte .L_800E9AE0
	.4byte .L_800E9B00
	.4byte .L_800E9B20
	.4byte .L_800E9B40
	.4byte .L_800E9B60
	.4byte .L_800E9B80
	.4byte .L_800E9BA0
	.4byte .L_800E9BC0
	.4byte .L_800E9BE0
	.4byte .L_800E9C20
	.4byte .L_800E9C40
	.4byte .L_800E9C5C
	.4byte .L_800E9C78
	.4byte .L_800E9C94
	.4byte .L_800E9CB0
	.4byte .L_800E9CCC
	.4byte .L_800E9CE8
	.4byte .L_800E9D04
	.4byte .L_800E9D20
	.4byte .L_800E9D3C
	.4byte .L_800E9D58
	.4byte .L_800E9D74
	.4byte .L_800E9D90
	.4byte .L_800E9DAC
	.4byte .L_800E9DC8
	.4byte .L_800E9DE4
	.4byte .L_800E9E00
	.4byte .L_800E9E1C
	.4byte .L_800E9E38
	.4byte .L_800E9E54
	.4byte .L_800E9E70
	.4byte .L_800E9E8C
	.4byte .L_800E9EA8
	.4byte .L_800E9C00
	.4byte .L_800E9EC0
.endobj lbl_804A886C

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn GXSetGPMetric, global
/* 800E9984 000E68C4  80 A2 92 90 */	lwz r5, __GXData@sda21(r2)
/* 800E9988 000E68C8  80 05 05 9C */	lwz r0, 0x59c(r5)
/* 800E998C 000E68CC  2C 00 00 22 */	cmpwi r0, 0x22
/* 800E9990 000E68D0  41 82 00 2C */	beq .L_800E99BC
/* 800E9994 000E68D4  40 80 00 74 */	bge .L_800E9A08
/* 800E9998 000E68D8  2C 00 00 0B */	cmpwi r0, 0xb
/* 800E999C 000E68DC  40 80 00 10 */	bge .L_800E99AC
/* 800E99A0 000E68E0  2C 00 00 00 */	cmpwi r0, 0
/* 800E99A4 000E68E4  40 80 00 18 */	bge .L_800E99BC
/* 800E99A8 000E68E8  48 00 00 60 */	b .L_800E9A08
.L_800E99AC:
/* 800E99AC 000E68EC  2C 00 00 1B */	cmpwi r0, 0x1b
/* 800E99B0 000E68F0  40 80 00 44 */	bge .L_800E99F4
/* 800E99B4 000E68F4  48 00 00 28 */	b .L_800E99DC
/* 800E99B8 000E68F8  48 00 00 50 */	b .L_800E9A08
.L_800E99BC:
/* 800E99BC 000E68FC  38 00 00 10 */	li r0, 0x10
/* 800E99C0 000E6900  3C C0 CC 01 */	lis r6, 0xCC008000@ha
/* 800E99C4 000E6904  98 06 80 00 */	stb r0, 0xCC008000@l(r6)
/* 800E99C8 000E6908  38 A0 10 06 */	li r5, 0x1006
/* 800E99CC 000E690C  38 00 00 00 */	li r0, 0
/* 800E99D0 000E6910  90 A6 80 00 */	stw r5, 0xCC008000@l(r6)
/* 800E99D4 000E6914  90 06 80 00 */	stw r0, 0xCC008000@l(r6)
/* 800E99D8 000E6918  48 00 00 30 */	b .L_800E9A08
.L_800E99DC:
/* 800E99DC 000E691C  38 00 00 61 */	li r0, 0x61
/* 800E99E0 000E6920  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E99E4 000E6924  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E99E8 000E6928  3C 00 23 00 */	lis r0, 0x2300
/* 800E99EC 000E692C  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E99F0 000E6930  48 00 00 18 */	b .L_800E9A08
.L_800E99F4:
/* 800E99F4 000E6934  38 00 00 61 */	li r0, 0x61
/* 800E99F8 000E6938  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E99FC 000E693C  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9A00 000E6940  3C 00 24 00 */	lis r0, 0x2400
/* 800E9A04 000E6944  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
.L_800E9A08:
/* 800E9A08 000E6948  80 C2 92 90 */	lwz r6, __GXData@sda21(r2)
/* 800E9A0C 000E694C  80 06 05 A0 */	lwz r0, 0x5a0(r6)
/* 800E9A10 000E6950  2C 00 00 15 */	cmpwi r0, 0x15
/* 800E9A14 000E6954  41 82 00 2C */	beq .L_800E9A40
/* 800E9A18 000E6958  40 80 00 7C */	bge .L_800E9A94
/* 800E9A1C 000E695C  2C 00 00 09 */	cmpwi r0, 9
/* 800E9A20 000E6960  40 80 00 10 */	bge .L_800E9A30
/* 800E9A24 000E6964  2C 00 00 00 */	cmpwi r0, 0
/* 800E9A28 000E6968  40 80 00 18 */	bge .L_800E9A40
/* 800E9A2C 000E696C  48 00 00 68 */	b .L_800E9A94
.L_800E9A30:
/* 800E9A30 000E6970  2C 00 00 11 */	cmpwi r0, 0x11
/* 800E9A34 000E6974  40 80 00 54 */	bge .L_800E9A88
/* 800E9A38 000E6978  48 00 00 20 */	b .L_800E9A58
/* 800E9A3C 000E697C  48 00 00 58 */	b .L_800E9A94
.L_800E9A40:
/* 800E9A40 000E6980  38 00 00 61 */	li r0, 0x61
/* 800E9A44 000E6984  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9A48 000E6988  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9A4C 000E698C  3C 00 67 00 */	lis r0, 0x6700
/* 800E9A50 000E6990  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9A54 000E6994  48 00 00 40 */	b .L_800E9A94
.L_800E9A58:
/* 800E9A58 000E6998  80 A6 05 A4 */	lwz r5, 0x5a4(r6)
/* 800E9A5C 000E699C  38 00 00 00 */	li r0, 0
/* 800E9A60 000E69A0  50 05 26 36 */	rlwimi r5, r0, 4, 0x18, 0x1b
/* 800E9A64 000E69A4  90 A6 05 A4 */	stw r5, 0x5a4(r6)
/* 800E9A68 000E69A8  38 00 00 08 */	li r0, 8
/* 800E9A6C 000E69AC  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9A70 000E69B0  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9A74 000E69B4  38 00 00 20 */	li r0, 0x20
/* 800E9A78 000E69B8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9A7C 000E69BC  80 06 05 A4 */	lwz r0, 0x5a4(r6)
/* 800E9A80 000E69C0  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9A84 000E69C4  48 00 00 10 */	b .L_800E9A94
.L_800E9A88:
/* 800E9A88 000E69C8  80 AD 8E B4 */	lwz r5, __cpReg@sda21(r13)
/* 800E9A8C 000E69CC  38 00 00 00 */	li r0, 0
/* 800E9A90 000E69D0  B0 05 00 06 */	sth r0, 6(r5)
.L_800E9A94:
/* 800E9A94 000E69D4  80 A2 92 90 */	lwz r5, __GXData@sda21(r2)
/* 800E9A98 000E69D8  90 65 05 9C */	stw r3, 0x59c(r5)
/* 800E9A9C 000E69DC  80 05 05 9C */	lwz r0, 0x59c(r5)
/* 800E9AA0 000E69E0  28 00 00 23 */	cmplwi r0, 0x23
/* 800E9AA4 000E69E4  41 81 04 1C */	bgt .L_800E9EC0
/* 800E9AA8 000E69E8  3C 60 80 4B */	lis r3, lbl_804A886C@ha
/* 800E9AAC 000E69EC  38 63 88 6C */	addi r3, r3, lbl_804A886C@l
/* 800E9AB0 000E69F0  54 00 10 3A */	slwi r0, r0, 2
/* 800E9AB4 000E69F4  7C 03 00 2E */	lwzx r0, r3, r0
/* 800E9AB8 000E69F8  7C 09 03 A6 */	mtctr r0
/* 800E9ABC 000E69FC  4E 80 04 20 */	bctr 
.L_800E9AC0:
/* 800E9AC0 000E6A00  38 00 00 10 */	li r0, 0x10
/* 800E9AC4 000E6A04  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9AC8 000E6A08  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9ACC 000E6A0C  38 60 10 06 */	li r3, 0x1006
/* 800E9AD0 000E6A10  38 00 02 73 */	li r0, 0x273
/* 800E9AD4 000E6A14  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9AD8 000E6A18  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9ADC 000E6A1C  48 00 03 E4 */	b .L_800E9EC0
.L_800E9AE0:
/* 800E9AE0 000E6A20  38 00 00 10 */	li r0, 0x10
/* 800E9AE4 000E6A24  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9AE8 000E6A28  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9AEC 000E6A2C  38 60 10 06 */	li r3, 0x1006
/* 800E9AF0 000E6A30  38 00 01 4A */	li r0, 0x14a
/* 800E9AF4 000E6A34  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9AF8 000E6A38  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9AFC 000E6A3C  48 00 03 C4 */	b .L_800E9EC0
.L_800E9B00:
/* 800E9B00 000E6A40  38 00 00 10 */	li r0, 0x10
/* 800E9B04 000E6A44  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9B08 000E6A48  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9B0C 000E6A4C  38 60 10 06 */	li r3, 0x1006
/* 800E9B10 000E6A50  38 00 01 6B */	li r0, 0x16b
/* 800E9B14 000E6A54  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9B18 000E6A58  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9B1C 000E6A5C  48 00 03 A4 */	b .L_800E9EC0
.L_800E9B20:
/* 800E9B20 000E6A60  38 00 00 10 */	li r0, 0x10
/* 800E9B24 000E6A64  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9B28 000E6A68  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9B2C 000E6A6C  38 60 10 06 */	li r3, 0x1006
/* 800E9B30 000E6A70  38 00 00 84 */	li r0, 0x84
/* 800E9B34 000E6A74  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9B38 000E6A78  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9B3C 000E6A7C  48 00 03 84 */	b .L_800E9EC0
.L_800E9B40:
/* 800E9B40 000E6A80  38 00 00 10 */	li r0, 0x10
/* 800E9B44 000E6A84  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9B48 000E6A88  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9B4C 000E6A8C  38 60 10 06 */	li r3, 0x1006
/* 800E9B50 000E6A90  38 00 00 C6 */	li r0, 0xc6
/* 800E9B54 000E6A94  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9B58 000E6A98  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9B5C 000E6A9C  48 00 03 64 */	b .L_800E9EC0
.L_800E9B60:
/* 800E9B60 000E6AA0  38 00 00 10 */	li r0, 0x10
/* 800E9B64 000E6AA4  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9B68 000E6AA8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9B6C 000E6AAC  38 60 10 06 */	li r3, 0x1006
/* 800E9B70 000E6AB0  38 00 02 10 */	li r0, 0x210
/* 800E9B74 000E6AB4  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9B78 000E6AB8  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9B7C 000E6ABC  48 00 03 44 */	b .L_800E9EC0
.L_800E9B80:
/* 800E9B80 000E6AC0  38 00 00 10 */	li r0, 0x10
/* 800E9B84 000E6AC4  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9B88 000E6AC8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9B8C 000E6ACC  38 60 10 06 */	li r3, 0x1006
/* 800E9B90 000E6AD0  38 00 02 52 */	li r0, 0x252
/* 800E9B94 000E6AD4  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9B98 000E6AD8  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9B9C 000E6ADC  48 00 03 24 */	b .L_800E9EC0
.L_800E9BA0:
/* 800E9BA0 000E6AE0  38 00 00 10 */	li r0, 0x10
/* 800E9BA4 000E6AE4  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9BA8 000E6AE8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9BAC 000E6AEC  38 60 10 06 */	li r3, 0x1006
/* 800E9BB0 000E6AF0  38 00 02 31 */	li r0, 0x231
/* 800E9BB4 000E6AF4  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9BB8 000E6AF8  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9BBC 000E6AFC  48 00 03 04 */	b .L_800E9EC0
.L_800E9BC0:
/* 800E9BC0 000E6B00  38 00 00 10 */	li r0, 0x10
/* 800E9BC4 000E6B04  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9BC8 000E6B08  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9BCC 000E6B0C  38 60 10 06 */	li r3, 0x1006
/* 800E9BD0 000E6B10  38 00 01 AD */	li r0, 0x1ad
/* 800E9BD4 000E6B14  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9BD8 000E6B18  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9BDC 000E6B1C  48 00 02 E4 */	b .L_800E9EC0
.L_800E9BE0:
/* 800E9BE0 000E6B20  38 00 00 10 */	li r0, 0x10
/* 800E9BE4 000E6B24  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9BE8 000E6B28  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9BEC 000E6B2C  38 60 10 06 */	li r3, 0x1006
/* 800E9BF0 000E6B30  38 00 01 CE */	li r0, 0x1ce
/* 800E9BF4 000E6B34  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9BF8 000E6B38  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9BFC 000E6B3C  48 00 02 C4 */	b .L_800E9EC0
.L_800E9C00:
/* 800E9C00 000E6B40  38 00 00 10 */	li r0, 0x10
/* 800E9C04 000E6B44  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9C08 000E6B48  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9C0C 000E6B4C  38 60 10 06 */	li r3, 0x1006
/* 800E9C10 000E6B50  38 00 00 21 */	li r0, 0x21
/* 800E9C14 000E6B54  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9C18 000E6B58  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9C1C 000E6B5C  48 00 02 A4 */	b .L_800E9EC0
.L_800E9C20:
/* 800E9C20 000E6B60  38 00 00 10 */	li r0, 0x10
/* 800E9C24 000E6B64  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9C28 000E6B68  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9C2C 000E6B6C  38 60 10 06 */	li r3, 0x1006
/* 800E9C30 000E6B70  38 00 01 53 */	li r0, 0x153
/* 800E9C34 000E6B74  90 65 80 00 */	stw r3, 0xCC008000@l(r5)
/* 800E9C38 000E6B78  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9C3C 000E6B7C  48 00 02 84 */	b .L_800E9EC0
.L_800E9C40:
/* 800E9C40 000E6B80  38 00 00 61 */	li r0, 0x61
/* 800E9C44 000E6B84  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9C48 000E6B88  3C 60 23 01 */	lis r3, 0x2300AE7F@ha
/* 800E9C4C 000E6B8C  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9C50 000E6B90  38 03 AE 7F */	addi r0, r3, 0x2300AE7F@l
/* 800E9C54 000E6B94  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9C58 000E6B98  48 00 02 68 */	b .L_800E9EC0
.L_800E9C5C:
/* 800E9C5C 000E6B9C  38 00 00 61 */	li r0, 0x61
/* 800E9C60 000E6BA0  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9C64 000E6BA4  3C 60 23 01 */	lis r3, 0x23008E7F@ha
/* 800E9C68 000E6BA8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9C6C 000E6BAC  38 03 8E 7F */	addi r0, r3, 0x23008E7F@l
/* 800E9C70 000E6BB0  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9C74 000E6BB4  48 00 02 4C */	b .L_800E9EC0
.L_800E9C78:
/* 800E9C78 000E6BB8  38 00 00 61 */	li r0, 0x61
/* 800E9C7C 000E6BBC  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9C80 000E6BC0  3C 60 23 01 */	lis r3, 0x23009E7F@ha
/* 800E9C84 000E6BC4  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9C88 000E6BC8  38 03 9E 7F */	addi r0, r3, 0x23009E7F@l
/* 800E9C8C 000E6BCC  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9C90 000E6BD0  48 00 02 30 */	b .L_800E9EC0
.L_800E9C94:
/* 800E9C94 000E6BD4  38 00 00 61 */	li r0, 0x61
/* 800E9C98 000E6BD8  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9C9C 000E6BDC  3C 60 23 00 */	lis r3, 0x23001E7F@ha
/* 800E9CA0 000E6BE0  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9CA4 000E6BE4  38 03 1E 7F */	addi r0, r3, 0x23001E7F@l
/* 800E9CA8 000E6BE8  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9CAC 000E6BEC  48 00 02 14 */	b .L_800E9EC0
.L_800E9CB0:
/* 800E9CB0 000E6BF0  38 00 00 61 */	li r0, 0x61
/* 800E9CB4 000E6BF4  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9CB8 000E6BF8  3C 60 23 01 */	lis r3, 0x2300AC3F@ha
/* 800E9CBC 000E6BFC  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9CC0 000E6C00  38 03 AC 3F */	addi r0, r3, 0x2300AC3F@l
/* 800E9CC4 000E6C04  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9CC8 000E6C08  48 00 01 F8 */	b .L_800E9EC0
.L_800E9CCC:
/* 800E9CCC 000E6C0C  38 00 00 61 */	li r0, 0x61
/* 800E9CD0 000E6C10  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9CD4 000E6C14  3C 60 23 01 */	lis r3, 0x2300AC7F@ha
/* 800E9CD8 000E6C18  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9CDC 000E6C1C  38 03 AC 7F */	addi r0, r3, 0x2300AC7F@l
/* 800E9CE0 000E6C20  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9CE4 000E6C24  48 00 01 DC */	b .L_800E9EC0
.L_800E9CE8:
/* 800E9CE8 000E6C28  38 00 00 61 */	li r0, 0x61
/* 800E9CEC 000E6C2C  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9CF0 000E6C30  3C 60 23 01 */	lis r3, 0x2300ACBF@ha
/* 800E9CF4 000E6C34  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9CF8 000E6C38  38 03 AC BF */	addi r0, r3, 0x2300ACBF@l
/* 800E9CFC 000E6C3C  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9D00 000E6C40  48 00 01 C0 */	b .L_800E9EC0
.L_800E9D04:
/* 800E9D04 000E6C44  38 00 00 61 */	li r0, 0x61
/* 800E9D08 000E6C48  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9D0C 000E6C4C  3C 60 23 01 */	lis r3, 0x2300ACFF@ha
/* 800E9D10 000E6C50  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9D14 000E6C54  38 03 AC FF */	addi r0, r3, 0x2300ACFF@l
/* 800E9D18 000E6C58  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9D1C 000E6C5C  48 00 01 A4 */	b .L_800E9EC0
.L_800E9D20:
/* 800E9D20 000E6C60  38 00 00 61 */	li r0, 0x61
/* 800E9D24 000E6C64  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9D28 000E6C68  3C 60 23 01 */	lis r3, 0x2300AD3F@ha
/* 800E9D2C 000E6C6C  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9D30 000E6C70  38 03 AD 3F */	addi r0, r3, 0x2300AD3F@l
/* 800E9D34 000E6C74  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9D38 000E6C78  48 00 01 88 */	b .L_800E9EC0
.L_800E9D3C:
/* 800E9D3C 000E6C7C  38 00 00 61 */	li r0, 0x61
/* 800E9D40 000E6C80  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9D44 000E6C84  3C 60 23 01 */	lis r3, 0x2300AD7F@ha
/* 800E9D48 000E6C88  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9D4C 000E6C8C  38 03 AD 7F */	addi r0, r3, 0x2300AD7F@l
/* 800E9D50 000E6C90  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9D54 000E6C94  48 00 01 6C */	b .L_800E9EC0
.L_800E9D58:
/* 800E9D58 000E6C98  38 00 00 61 */	li r0, 0x61
/* 800E9D5C 000E6C9C  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9D60 000E6CA0  3C 60 23 01 */	lis r3, 0x2300ADBF@ha
/* 800E9D64 000E6CA4  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9D68 000E6CA8  38 03 AD BF */	addi r0, r3, 0x2300ADBF@l
/* 800E9D6C 000E6CAC  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9D70 000E6CB0  48 00 01 50 */	b .L_800E9EC0
.L_800E9D74:
/* 800E9D74 000E6CB4  38 00 00 61 */	li r0, 0x61
/* 800E9D78 000E6CB8  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9D7C 000E6CBC  3C 60 23 01 */	lis r3, 0x2300ADFF@ha
/* 800E9D80 000E6CC0  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9D84 000E6CC4  38 03 AD FF */	addi r0, r3, 0x2300ADFF@l
/* 800E9D88 000E6CC8  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9D8C 000E6CCC  48 00 01 34 */	b .L_800E9EC0
.L_800E9D90:
/* 800E9D90 000E6CD0  38 00 00 61 */	li r0, 0x61
/* 800E9D94 000E6CD4  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9D98 000E6CD8  3C 60 23 01 */	lis r3, 0x2300AE3F@ha
/* 800E9D9C 000E6CDC  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9DA0 000E6CE0  38 03 AE 3F */	addi r0, r3, 0x2300AE3F@l
/* 800E9DA4 000E6CE4  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9DA8 000E6CE8  48 00 01 18 */	b .L_800E9EC0
.L_800E9DAC:
/* 800E9DAC 000E6CEC  38 00 00 61 */	li r0, 0x61
/* 800E9DB0 000E6CF0  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9DB4 000E6CF4  3C 60 23 01 */	lis r3, 0x2300A27F@ha
/* 800E9DB8 000E6CF8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9DBC 000E6CFC  38 03 A2 7F */	addi r0, r3, 0x2300A27F@l
/* 800E9DC0 000E6D00  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9DC4 000E6D04  48 00 00 FC */	b .L_800E9EC0
.L_800E9DC8:
/* 800E9DC8 000E6D08  38 00 00 61 */	li r0, 0x61
/* 800E9DCC 000E6D0C  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9DD0 000E6D10  3C 60 23 01 */	lis r3, 0x2300A67F@ha
/* 800E9DD4 000E6D14  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9DD8 000E6D18  38 03 A6 7F */	addi r0, r3, 0x2300A67F@l
/* 800E9DDC 000E6D1C  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9DE0 000E6D20  48 00 00 E0 */	b .L_800E9EC0
.L_800E9DE4:
/* 800E9DE4 000E6D24  38 00 00 61 */	li r0, 0x61
/* 800E9DE8 000E6D28  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9DEC 000E6D2C  3C 60 23 01 */	lis r3, 0x2300AA7F@ha
/* 800E9DF0 000E6D30  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9DF4 000E6D34  38 03 AA 7F */	addi r0, r3, 0x2300AA7F@l
/* 800E9DF8 000E6D38  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9DFC 000E6D3C  48 00 00 C4 */	b .L_800E9EC0
.L_800E9E00:
/* 800E9E00 000E6D40  38 00 00 61 */	li r0, 0x61
/* 800E9E04 000E6D44  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9E08 000E6D48  3C 60 24 03 */	lis r3, 0x2402C0C6@ha
/* 800E9E0C 000E6D4C  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9E10 000E6D50  38 03 C0 C6 */	addi r0, r3, 0x2402C0C6@l
/* 800E9E14 000E6D54  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9E18 000E6D58  48 00 00 A8 */	b .L_800E9EC0
.L_800E9E1C:
/* 800E9E1C 000E6D5C  38 00 00 61 */	li r0, 0x61
/* 800E9E20 000E6D60  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9E24 000E6D64  3C 60 24 03 */	lis r3, 0x2402C16B@ha
/* 800E9E28 000E6D68  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9E2C 000E6D6C  38 03 C1 6B */	addi r0, r3, 0x2402C16B@l
/* 800E9E30 000E6D70  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9E34 000E6D74  48 00 00 8C */	b .L_800E9EC0
.L_800E9E38:
/* 800E9E38 000E6D78  38 00 00 61 */	li r0, 0x61
/* 800E9E3C 000E6D7C  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9E40 000E6D80  3C 60 24 03 */	lis r3, 0x2402C0E7@ha
/* 800E9E44 000E6D84  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9E48 000E6D88  38 03 C0 E7 */	addi r0, r3, 0x2402C0E7@l
/* 800E9E4C 000E6D8C  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9E50 000E6D90  48 00 00 70 */	b .L_800E9EC0
.L_800E9E54:
/* 800E9E54 000E6D94  38 00 00 61 */	li r0, 0x61
/* 800E9E58 000E6D98  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9E5C 000E6D9C  3C 60 24 03 */	lis r3, 0x2402C108@ha
/* 800E9E60 000E6DA0  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9E64 000E6DA4  38 03 C1 08 */	addi r0, r3, 0x2402C108@l
/* 800E9E68 000E6DA8  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9E6C 000E6DAC  48 00 00 54 */	b .L_800E9EC0
.L_800E9E70:
/* 800E9E70 000E6DB0  38 00 00 61 */	li r0, 0x61
/* 800E9E74 000E6DB4  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9E78 000E6DB8  3C 60 24 03 */	lis r3, 0x2402C129@ha
/* 800E9E7C 000E6DBC  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9E80 000E6DC0  38 03 C1 29 */	addi r0, r3, 0x2402C129@l
/* 800E9E84 000E6DC4  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9E88 000E6DC8  48 00 00 38 */	b .L_800E9EC0
.L_800E9E8C:
/* 800E9E8C 000E6DCC  38 00 00 61 */	li r0, 0x61
/* 800E9E90 000E6DD0  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9E94 000E6DD4  3C 60 24 03 */	lis r3, 0x2402C14A@ha
/* 800E9E98 000E6DD8  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9E9C 000E6DDC  38 03 C1 4A */	addi r0, r3, 0x2402C14A@l
/* 800E9EA0 000E6DE0  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
/* 800E9EA4 000E6DE4  48 00 00 1C */	b .L_800E9EC0
.L_800E9EA8:
/* 800E9EA8 000E6DE8  38 00 00 61 */	li r0, 0x61
/* 800E9EAC 000E6DEC  3C A0 CC 01 */	lis r5, 0xCC008000@ha
/* 800E9EB0 000E6DF0  3C 60 24 03 */	lis r3, 0x2402C1AD@ha
/* 800E9EB4 000E6DF4  98 05 80 00 */	stb r0, 0xCC008000@l(r5)
/* 800E9EB8 000E6DF8  38 03 C1 AD */	addi r0, r3, 0x2402C1AD@l
/* 800E9EBC 000E6DFC  90 05 80 00 */	stw r0, 0xCC008000@l(r5)
.L_800E9EC0:
/* 800E9EC0 000E6E00  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800E9EC4 000E6E04  90 83 05 A0 */	stw r4, 0x5a0(r3)
/* 800E9EC8 000E6E08  80 03 05 A0 */	lwz r0, 0x5a0(r3)
/* 800E9ECC 000E6E0C  28 00 00 16 */	cmplwi r0, 0x16
/* 800E9ED0 000E6E10  41 81 02 EC */	bgt .L_800EA1BC
/* 800E9ED4 000E6E14  3C 80 80 4B */	lis r4, lbl_804A8810@ha
/* 800E9ED8 000E6E18  38 84 88 10 */	addi r4, r4, lbl_804A8810@l
/* 800E9EDC 000E6E1C  54 00 10 3A */	slwi r0, r0, 2
/* 800E9EE0 000E6E20  7C 04 00 2E */	lwzx r0, r4, r0
/* 800E9EE4 000E6E24  7C 09 03 A6 */	mtctr r0
/* 800E9EE8 000E6E28  4E 80 04 20 */	bctr 
.L_800E9EEC:
/* 800E9EEC 000E6E2C  38 00 00 61 */	li r0, 0x61
/* 800E9EF0 000E6E30  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9EF4 000E6E34  3C 60 67 00 */	lis r3, 0x67000042@ha
/* 800E9EF8 000E6E38  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9EFC 000E6E3C  38 03 00 42 */	addi r0, r3, 0x67000042@l
/* 800E9F00 000E6E40  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9F04 000E6E44  48 00 02 B8 */	b .L_800EA1BC
.L_800E9F08:
/* 800E9F08 000E6E48  38 00 00 61 */	li r0, 0x61
/* 800E9F0C 000E6E4C  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9F10 000E6E50  3C 60 67 00 */	lis r3, 0x67000084@ha
/* 800E9F14 000E6E54  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9F18 000E6E58  38 03 00 84 */	addi r0, r3, 0x67000084@l
/* 800E9F1C 000E6E5C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9F20 000E6E60  48 00 02 9C */	b .L_800EA1BC
.L_800E9F24:
/* 800E9F24 000E6E64  38 00 00 61 */	li r0, 0x61
/* 800E9F28 000E6E68  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9F2C 000E6E6C  3C 60 67 00 */	lis r3, 0x67000063@ha
/* 800E9F30 000E6E70  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9F34 000E6E74  38 03 00 63 */	addi r0, r3, 0x67000063@l
/* 800E9F38 000E6E78  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9F3C 000E6E7C  48 00 02 80 */	b .L_800EA1BC
.L_800E9F40:
/* 800E9F40 000E6E80  38 00 00 61 */	li r0, 0x61
/* 800E9F44 000E6E84  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9F48 000E6E88  3C 60 67 00 */	lis r3, 0x67000129@ha
/* 800E9F4C 000E6E8C  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9F50 000E6E90  38 03 01 29 */	addi r0, r3, 0x67000129@l
/* 800E9F54 000E6E94  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9F58 000E6E98  48 00 02 64 */	b .L_800EA1BC
.L_800E9F5C:
/* 800E9F5C 000E6E9C  38 00 00 61 */	li r0, 0x61
/* 800E9F60 000E6EA0  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9F64 000E6EA4  3C 60 67 00 */	lis r3, 0x67000252@ha
/* 800E9F68 000E6EA8  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9F6C 000E6EAC  38 03 02 52 */	addi r0, r3, 0x67000252@l
/* 800E9F70 000E6EB0  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9F74 000E6EB4  48 00 02 48 */	b .L_800EA1BC
.L_800E9F78:
/* 800E9F78 000E6EB8  38 00 00 61 */	li r0, 0x61
/* 800E9F7C 000E6EBC  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9F80 000E6EC0  3C 60 67 00 */	lis r3, 0x67000021@ha
/* 800E9F84 000E6EC4  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9F88 000E6EC8  38 03 00 21 */	addi r0, r3, 0x67000021@l
/* 800E9F8C 000E6ECC  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9F90 000E6ED0  48 00 02 2C */	b .L_800EA1BC
.L_800E9F94:
/* 800E9F94 000E6ED4  38 00 00 61 */	li r0, 0x61
/* 800E9F98 000E6ED8  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9F9C 000E6EDC  3C 60 67 00 */	lis r3, 0x6700014B@ha
/* 800E9FA0 000E6EE0  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9FA4 000E6EE4  38 03 01 4B */	addi r0, r3, 0x6700014B@l
/* 800E9FA8 000E6EE8  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9FAC 000E6EEC  48 00 02 10 */	b .L_800EA1BC
.L_800E9FB0:
/* 800E9FB0 000E6EF0  38 00 00 61 */	li r0, 0x61
/* 800E9FB4 000E6EF4  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9FB8 000E6EF8  3C 60 67 00 */	lis r3, 0x6700018D@ha
/* 800E9FBC 000E6EFC  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9FC0 000E6F00  38 03 01 8D */	addi r0, r3, 0x6700018D@l
/* 800E9FC4 000E6F04  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9FC8 000E6F08  48 00 01 F4 */	b .L_800EA1BC
.L_800E9FCC:
/* 800E9FCC 000E6F0C  38 00 00 61 */	li r0, 0x61
/* 800E9FD0 000E6F10  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9FD4 000E6F14  3C 60 67 00 */	lis r3, 0x670001CF@ha
/* 800E9FD8 000E6F18  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9FDC 000E6F1C  38 03 01 CF */	addi r0, r3, 0x670001CF@l
/* 800E9FE0 000E6F20  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800E9FE4 000E6F24  48 00 01 D8 */	b .L_800EA1BC
.L_800E9FE8:
/* 800E9FE8 000E6F28  38 00 00 61 */	li r0, 0x61
/* 800E9FEC 000E6F2C  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800E9FF0 000E6F30  3C 60 67 00 */	lis r3, 0x67000211@ha
/* 800E9FF4 000E6F34  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800E9FF8 000E6F38  38 03 02 11 */	addi r0, r3, 0x67000211@l
/* 800E9FFC 000E6F3C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA000 000E6F40  48 00 01 BC */	b .L_800EA1BC
.L_800EA004:
/* 800EA004 000E6F44  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA008 000E6F48  38 00 00 02 */	li r0, 2
/* 800EA00C 000E6F4C  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA010 000E6F50  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA014 000E6F54  38 00 00 08 */	li r0, 8
/* 800EA018 000E6F58  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA01C 000E6F5C  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA020 000E6F60  38 00 00 20 */	li r0, 0x20
/* 800EA024 000E6F64  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA028 000E6F68  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA02C 000E6F6C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA030 000E6F70  48 00 01 8C */	b .L_800EA1BC
.L_800EA034:
/* 800EA034 000E6F74  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA038 000E6F78  38 00 00 03 */	li r0, 3
/* 800EA03C 000E6F7C  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA040 000E6F80  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA044 000E6F84  38 00 00 08 */	li r0, 8
/* 800EA048 000E6F88  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA04C 000E6F8C  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA050 000E6F90  38 00 00 20 */	li r0, 0x20
/* 800EA054 000E6F94  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA058 000E6F98  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA05C 000E6F9C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA060 000E6FA0  48 00 01 5C */	b .L_800EA1BC
.L_800EA064:
/* 800EA064 000E6FA4  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA068 000E6FA8  38 00 00 04 */	li r0, 4
/* 800EA06C 000E6FAC  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA070 000E6FB0  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA074 000E6FB4  38 00 00 08 */	li r0, 8
/* 800EA078 000E6FB8  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA07C 000E6FBC  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA080 000E6FC0  38 00 00 20 */	li r0, 0x20
/* 800EA084 000E6FC4  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA088 000E6FC8  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA08C 000E6FCC  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA090 000E6FD0  48 00 01 2C */	b .L_800EA1BC
.L_800EA094:
/* 800EA094 000E6FD4  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA098 000E6FD8  38 00 00 05 */	li r0, 5
/* 800EA09C 000E6FDC  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA0A0 000E6FE0  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA0A4 000E6FE4  38 00 00 08 */	li r0, 8
/* 800EA0A8 000E6FE8  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA0AC 000E6FEC  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA0B0 000E6FF0  38 00 00 20 */	li r0, 0x20
/* 800EA0B4 000E6FF4  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA0B8 000E6FF8  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA0BC 000E6FFC  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA0C0 000E7000  48 00 00 FC */	b .L_800EA1BC
.L_800EA0C4:
/* 800EA0C4 000E7004  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA0C8 000E7008  38 00 00 06 */	li r0, 6
/* 800EA0CC 000E700C  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA0D0 000E7010  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA0D4 000E7014  38 00 00 08 */	li r0, 8
/* 800EA0D8 000E7018  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA0DC 000E701C  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA0E0 000E7020  38 00 00 20 */	li r0, 0x20
/* 800EA0E4 000E7024  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA0E8 000E7028  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA0EC 000E702C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA0F0 000E7030  48 00 00 CC */	b .L_800EA1BC
.L_800EA0F4:
/* 800EA0F4 000E7034  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA0F8 000E7038  38 00 00 07 */	li r0, 7
/* 800EA0FC 000E703C  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA100 000E7040  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA104 000E7044  38 00 00 08 */	li r0, 8
/* 800EA108 000E7048  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA10C 000E704C  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA110 000E7050  38 00 00 20 */	li r0, 0x20
/* 800EA114 000E7054  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA118 000E7058  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA11C 000E705C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA120 000E7060  48 00 00 9C */	b .L_800EA1BC
.L_800EA124:
/* 800EA124 000E7064  80 83 05 A4 */	lwz r4, 0x5a4(r3)
/* 800EA128 000E7068  38 00 00 09 */	li r0, 9
/* 800EA12C 000E706C  50 04 26 36 */	rlwimi r4, r0, 4, 0x18, 0x1b
/* 800EA130 000E7070  90 83 05 A4 */	stw r4, 0x5a4(r3)
/* 800EA134 000E7074  38 00 00 08 */	li r0, 8
/* 800EA138 000E7078  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA13C 000E707C  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA140 000E7080  38 00 00 20 */	li r0, 0x20
/* 800EA144 000E7084  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA148 000E7088  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA14C 000E708C  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA150 000E7090  48 00 00 6C */	b .L_800EA1BC
.L_800EA154:
/* 800EA154 000E7094  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA158 000E7098  38 A0 00 08 */	li r5, 8
/* 800EA15C 000E709C  50 A0 26 36 */	rlwimi r0, r5, 4, 0x18, 0x1b
/* 800EA160 000E70A0  90 03 05 A4 */	stw r0, 0x5a4(r3)
/* 800EA164 000E70A4  3C 80 CC 01 */	lis r4, 0xCC008000@ha
/* 800EA168 000E70A8  38 00 00 20 */	li r0, 0x20
/* 800EA16C 000E70AC  98 A4 80 00 */	stb r5, 0xCC008000@l(r4)
/* 800EA170 000E70B0  98 04 80 00 */	stb r0, 0xCC008000@l(r4)
/* 800EA174 000E70B4  80 03 05 A4 */	lwz r0, 0x5a4(r3)
/* 800EA178 000E70B8  90 04 80 00 */	stw r0, 0xCC008000@l(r4)
/* 800EA17C 000E70BC  48 00 00 40 */	b .L_800EA1BC
.L_800EA180:
/* 800EA180 000E70C0  80 6D 8E B4 */	lwz r3, __cpReg@sda21(r13)
/* 800EA184 000E70C4  38 00 00 02 */	li r0, 2
/* 800EA188 000E70C8  B0 03 00 06 */	sth r0, 6(r3)
/* 800EA18C 000E70CC  48 00 00 30 */	b .L_800EA1BC
.L_800EA190:
/* 800EA190 000E70D0  80 6D 8E B4 */	lwz r3, __cpReg@sda21(r13)
/* 800EA194 000E70D4  38 00 00 03 */	li r0, 3
/* 800EA198 000E70D8  B0 03 00 06 */	sth r0, 6(r3)
/* 800EA19C 000E70DC  48 00 00 20 */	b .L_800EA1BC
.L_800EA1A0:
/* 800EA1A0 000E70E0  80 6D 8E B4 */	lwz r3, __cpReg@sda21(r13)
/* 800EA1A4 000E70E4  38 00 00 04 */	li r0, 4
/* 800EA1A8 000E70E8  B0 03 00 06 */	sth r0, 6(r3)
/* 800EA1AC 000E70EC  48 00 00 10 */	b .L_800EA1BC
.L_800EA1B0:
/* 800EA1B0 000E70F0  80 6D 8E B4 */	lwz r3, __cpReg@sda21(r13)
/* 800EA1B4 000E70F4  38 00 00 05 */	li r0, 5
/* 800EA1B8 000E70F8  B0 03 00 06 */	sth r0, 6(r3)
.L_800EA1BC:
/* 800EA1BC 000E70FC  80 62 92 90 */	lwz r3, __GXData@sda21(r2)
/* 800EA1C0 000E7100  38 00 00 00 */	li r0, 0
/* 800EA1C4 000E7104  B0 03 00 02 */	sth r0, 2(r3)
/* 800EA1C8 000E7108  4E 80 00 20 */	blr 
.endfn GXSetGPMetric

.fn GXClearGPMetric, global
/* 800EA1CC 000E710C  80 6D 8E B4 */	lwz r3, __cpReg@sda21(r13)
/* 800EA1D0 000E7110  38 00 00 04 */	li r0, 4
/* 800EA1D4 000E7114  B0 03 00 04 */	sth r0, 4(r3)
/* 800EA1D8 000E7118  4E 80 00 20 */	blr 
.endfn GXClearGPMetric

.fn GXReadXfRasMetric, global
/* 800EA1DC 000E711C  80 ED 8E B4 */	lwz r7, __cpReg@sda21(r13)
/* 800EA1E0 000E7120  39 47 00 42 */	addi r10, r7, 0x42
/* 800EA1E4 000E7124  A1 07 00 42 */	lhz r8, 0x42(r7)
/* 800EA1E8 000E7128  39 27 00 40 */	addi r9, r7, 0x40
.L_800EA1EC:
/* 800EA1EC 000E712C  7D 00 43 78 */	mr r0, r8
/* 800EA1F0 000E7130  A0 E9 00 00 */	lhz r7, 0(r9)
/* 800EA1F4 000E7134  A1 0A 00 00 */	lhz r8, 0(r10)
/* 800EA1F8 000E7138  7C 08 00 40 */	cmplw r8, r0
/* 800EA1FC 000E713C  40 82 FF F0 */	bne .L_800EA1EC
/* 800EA200 000E7140  55 00 80 1E */	slwi r0, r8, 0x10
/* 800EA204 000E7144  7C 00 3B 78 */	or r0, r0, r7
/* 800EA208 000E7148  90 05 00 00 */	stw r0, 0(r5)
/* 800EA20C 000E714C  80 AD 8E B4 */	lwz r5, __cpReg@sda21(r13)
/* 800EA210 000E7150  39 25 00 46 */	addi r9, r5, 0x46
/* 800EA214 000E7154  A0 E5 00 46 */	lhz r7, 0x46(r5)
/* 800EA218 000E7158  39 05 00 44 */	addi r8, r5, 0x44
.L_800EA21C:
/* 800EA21C 000E715C  7C E0 3B 78 */	mr r0, r7
/* 800EA220 000E7160  A0 A8 00 00 */	lhz r5, 0(r8)
/* 800EA224 000E7164  A0 E9 00 00 */	lhz r7, 0(r9)
/* 800EA228 000E7168  7C 07 00 40 */	cmplw r7, r0
/* 800EA22C 000E716C  40 82 FF F0 */	bne .L_800EA21C
/* 800EA230 000E7170  54 E0 80 1E */	slwi r0, r7, 0x10
/* 800EA234 000E7174  7C 00 2B 78 */	or r0, r0, r5
/* 800EA238 000E7178  90 06 00 00 */	stw r0, 0(r6)
/* 800EA23C 000E717C  80 AD 8E B4 */	lwz r5, __cpReg@sda21(r13)
/* 800EA240 000E7180  39 05 00 4A */	addi r8, r5, 0x4a
/* 800EA244 000E7184  A0 C5 00 4A */	lhz r6, 0x4a(r5)
/* 800EA248 000E7188  38 E5 00 48 */	addi r7, r5, 0x48
.L_800EA24C:
/* 800EA24C 000E718C  7C C0 33 78 */	mr r0, r6
/* 800EA250 000E7190  A0 A7 00 00 */	lhz r5, 0(r7)
/* 800EA254 000E7194  A0 C8 00 00 */	lhz r6, 0(r8)
/* 800EA258 000E7198  7C 06 00 40 */	cmplw r6, r0
/* 800EA25C 000E719C  40 82 FF F0 */	bne .L_800EA24C
/* 800EA260 000E71A0  54 C0 80 1E */	slwi r0, r6, 0x10
/* 800EA264 000E71A4  7C 00 2B 78 */	or r0, r0, r5
/* 800EA268 000E71A8  90 03 00 00 */	stw r0, 0(r3)
/* 800EA26C 000E71AC  80 6D 8E B4 */	lwz r3, __cpReg@sda21(r13)
/* 800EA270 000E71B0  38 E3 00 4E */	addi r7, r3, 0x4e
/* 800EA274 000E71B4  A0 A3 00 4E */	lhz r5, 0x4e(r3)
/* 800EA278 000E71B8  38 C3 00 4C */	addi r6, r3, 0x4c
.L_800EA27C:
/* 800EA27C 000E71BC  7C A0 2B 78 */	mr r0, r5
/* 800EA280 000E71C0  A0 66 00 00 */	lhz r3, 0(r6)
/* 800EA284 000E71C4  A0 A7 00 00 */	lhz r5, 0(r7)
/* 800EA288 000E71C8  7C 05 00 40 */	cmplw r5, r0
/* 800EA28C 000E71CC  40 82 FF F0 */	bne .L_800EA27C
/* 800EA290 000E71D0  54 A0 80 1E */	slwi r0, r5, 0x10
/* 800EA294 000E71D4  7C 00 1B 78 */	or r0, r0, r3
/* 800EA298 000E71D8  90 04 00 00 */	stw r0, 0(r4)
/* 800EA29C 000E71DC  4E 80 00 20 */	blr 
.endfn GXReadXfRasMetric
