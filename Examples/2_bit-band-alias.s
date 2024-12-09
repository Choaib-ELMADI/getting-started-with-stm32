	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute 21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute 23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute 24, 1	@ Tag_ABI_align8_needed
	.eabi_attribute 25, 1	@ Tag_ABI_align8_preserved
	.eabi_attribute 26, 1	@ Tag_ABI_enum_size
	.eabi_attribute 30, 6	@ Tag_ABI_optimization_goals
	.eabi_attribute 34, 1	@ Tag_CPU_unaligned_access
	.eabi_attribute 18, 4	@ Tag_ABI_PCS_wchar_t
	.file	"2_bit-band-alias.c"
@ GNU C17 (Arm GNU Toolchain 13.3.Rel1 (Build arm-13.24)) version 13.3.1 20240614 (arm-none-eabi)
@	compiled by GNU C version 9.3-win32 20200320, GMP version 6.2.1, MPFR version 3.1.6, MPC version 1.0.3, isl version isl-0.15-1-g835ea3a-GMP

@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed: -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -march=armv7e-m -g -O0
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 1 "2_bit-band-alias.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"\012 %d \012\000"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
.LFB3:
	.loc 1 3 17
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}	@
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #24	@,,
	.cfi_def_cfa_offset 32
	add	r7, sp, #0	@,,
	.cfi_def_cfa_register 7
@ 2_bit-band-alias.c:14:     int *alias_base_address      = (unsigned *) 0x22000000;
	.loc 1 14 10
	mov	r3, #570425344	@ tmp123,
	str	r3, [r7, #20]	@ tmp123, alias_base_address
@ 2_bit-band-alias.c:15:     int *bit_band_base_address   = (unsigned *) 0x20000000;
	.loc 1 15 10
	mov	r3, #536870912	@ tmp124,
	str	r3, [r7, #16]	@ tmp124, bit_band_base_address
@ 2_bit-band-alias.c:16:     int *bit_band_memory_address = (unsigned *) 0x20000200;
	.loc 1 16 10
	ldr	r3, .L2	@ tmp125,
	str	r3, [r7, #12]	@ tmp125, bit_band_memory_address
@ 2_bit-band-alias.c:17:     int bit_order = 4;
	.loc 1 17 9
	movs	r3, #4	@ tmp126,
	str	r3, [r7, #8]	@ tmp126, bit_order
@ 2_bit-band-alias.c:20:     *bit_band_memory_address = 0xFF;
	.loc 1 20 30
	ldr	r3, [r7, #12]	@ tmp127, bit_band_memory_address
	movs	r2, #255	@ tmp128,
	str	r2, [r3]	@ tmp128, *bit_band_memory_address_12
@ 2_bit-band-alias.c:21:     printf("\n %d \n", *bit_band_memory_address);
	.loc 1 21 5
	ldr	r3, [r7, #12]	@ tmp129, bit_band_memory_address
	ldr	r3, [r3]	@ _1, *bit_band_memory_address_12
	mov	r1, r3	@, _1
	ldr	r0, .L2+4	@,
	bl	printf		@
@ 2_bit-band-alias.c:23:     alias_address = (unsigned *) ((alias_base_address) + (32 * (bit_band_memory_address - bit_band_base_address)) + (bit_order * 4));
	.loc 1 23 89
	ldr	r2, [r7, #12]	@ tmp130, bit_band_memory_address
	ldr	r3, [r7, #16]	@ tmp131, bit_band_base_address
	subs	r3, r2, r3	@ _2, tmp130, tmp131
	asrs	r3, r3, #2	@ tmp132, _2,
@ 2_bit-band-alias.c:23:     alias_address = (unsigned *) ((alias_base_address) + (32 * (bit_band_memory_address - bit_band_base_address)) + (bit_order * 4));
	.loc 1 23 115
	lsls	r2, r3, #3	@ _5, _4,
	ldr	r3, [r7, #8]	@ bit_order.0_6, bit_order
	add	r3, r3, r2	@ _7, _5
	lsls	r3, r3, #4	@ _8, _7,
@ 2_bit-band-alias.c:23:     alias_address = (unsigned *) ((alias_base_address) + (32 * (bit_band_memory_address - bit_band_base_address)) + (bit_order * 4));
	.loc 1 23 19
	ldr	r2, [r7, #20]	@ tmp134, alias_base_address
	add	r3, r3, r2	@ tmp133, tmp134
	str	r3, [r7, #4]	@ tmp133, alias_address
@ 2_bit-band-alias.c:25:     *alias_address = 0;
	.loc 1 25 20
	ldr	r3, [r7, #4]	@ tmp135, alias_address
	movs	r2, #0	@ tmp136,
	str	r2, [r3]	@ tmp136, *alias_address_17
@ 2_bit-band-alias.c:26:     printf("\n %d \n", *bit_band_memory_address);
	.loc 1 26 5
	ldr	r3, [r7, #12]	@ tmp137, bit_band_memory_address
	ldr	r3, [r3]	@ _9, *bit_band_memory_address_12
	mov	r1, r3	@, _9
	ldr	r0, .L2+4	@,
	bl	printf		@
@ 2_bit-band-alias.c:27: }
	.loc 1 27 1
	nop	
	adds	r7, r7, #24	@,,
	.cfi_def_cfa_offset 8
	mov	sp, r7	@,
	.cfi_def_cfa_register 13
	@ sp needed	@
	pop	{r7, pc}	@
.L3:
	.align	2
.L2:
	.word	536871424
	.word	.LC0
	.cfi_endproc
.LFE3:
	.size	main, .-main
.Letext0:
	.file 2 "C:/arm-gnu-toolchain-arm-none-eabi/arm-none-eabi/include/stdio.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0xfa
	.2byte	0x5
	.byte	0x1
	.byte	0x4
	.4byte	.Ldebug_abbrev0
	.uleb128 0x4
	.4byte	.LASF16
	.byte	0x1d
	.4byte	.LASF17
	.4byte	.LASF18
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x1
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1
	.uleb128 0x1
	.byte	0x2
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x1
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x1
	.byte	0x4
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x1
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x1
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x1
	.byte	0x8
	.byte	0x4
	.4byte	.LASF9
	.uleb128 0x1
	.byte	0x1
	.byte	0x8
	.4byte	.LASF10
	.uleb128 0x6
	.4byte	0x73
	.uleb128 0x3
	.4byte	0x7a
	.uleb128 0x7
	.4byte	.LASF19
	.byte	0x2
	.byte	0xce
	.byte	0x5
	.4byte	0x5e
	.4byte	0x9b
	.uleb128 0x8
	.4byte	0x7f
	.uleb128 0x9
	.byte	0
	.uleb128 0xa
	.4byte	.LASF20
	.byte	0x1
	.byte	0x3
	.byte	0x6
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xf8
	.uleb128 0x2
	.4byte	.LASF11
	.byte	0xe
	.byte	0xa
	.4byte	0xf8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x2
	.4byte	.LASF12
	.byte	0xf
	.byte	0xa
	.4byte	0xf8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x2
	.4byte	.LASF13
	.byte	0x10
	.byte	0xa
	.4byte	0xf8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2
	.4byte	.LASF14
	.byte	0x11
	.byte	0x9
	.4byte	0x5e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x2
	.4byte	.LASF15
	.byte	0x12
	.byte	0xa
	.4byte	0xf8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x3
	.4byte	0x5e
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 4
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF6:
	.ascii	"long long int\000"
.LASF8:
	.ascii	"unsigned int\000"
.LASF20:
	.ascii	"main\000"
.LASF18:
	.ascii	"C:\\\\Users\\\\Choaib ELMADI\\\\Documents\\\\D.I.F."
	.ascii	"Y\\\\2. Electronics\\\\7. STM32\\\\Docs\\\\I Introd"
	.ascii	"uction\\\\Chapter 1 - Introduction to STM32 MCU Por"
	.ascii	"tfolio\\\\Examples\000"
.LASF5:
	.ascii	"long unsigned int\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF14:
	.ascii	"bit_order\000"
.LASF17:
	.ascii	"2_bit-band-alias.c\000"
.LASF11:
	.ascii	"alias_base_address\000"
.LASF1:
	.ascii	"unsigned char\000"
.LASF10:
	.ascii	"char\000"
.LASF4:
	.ascii	"long int\000"
.LASF15:
	.ascii	"alias_address\000"
.LASF3:
	.ascii	"short unsigned int\000"
.LASF19:
	.ascii	"printf\000"
.LASF13:
	.ascii	"bit_band_memory_address\000"
.LASF9:
	.ascii	"long double\000"
.LASF12:
	.ascii	"bit_band_base_address\000"
.LASF2:
	.ascii	"short int\000"
.LASF16:
	.ascii	"GNU C17 13.3.1 20240614 -mcpu=cortex-m4 -mthumb -mf"
	.ascii	"loat-abi=soft -march=armv7e-m -g -O0\000"
.LASF0:
	.ascii	"signed char\000"
	.ident	"GCC: (Arm GNU Toolchain 13.3.Rel1 (Build arm-13.24)) 13.3.1 20240614"
