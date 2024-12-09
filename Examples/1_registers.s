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
	.file	"1_registers.c"
@ GNU C17 (Arm GNU Toolchain 13.3.Rel1 (Build arm-13.24)) version 13.3.1 20240614 (arm-none-eabi)
@	compiled by GNU C version 9.3-win32 20200320, GMP version 6.2.1, MPFR version 3.1.6, MPC version 1.0.3, isl version isl-0.15-1-g835ea3a-GMP

@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed: -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -march=armv7e-m -g -O0
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 1 "1_registers.c"
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
.LFB0:
	.loc 1 3 17
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}	@
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	sub	sp, sp, #12	@,,
	.cfi_def_cfa_offset 16
	add	r7, sp, #0	@,,
	.cfi_def_cfa_register 7
@ 1_registers.c:6:     a = 3;
	.loc 1 6 7
	movs	r3, #3	@ tmp114,
	strb	r3, [r7, #7]	@ tmp115, a
@ 1_registers.c:7:     b = 2;
	.loc 1 7 7
	movs	r3, #2	@ tmp116,
	strb	r3, [r7, #6]	@ tmp117, b
@ 1_registers.c:8:     c = a * b;
	.loc 1 8 7
	ldrb	r2, [r7, #7]	@ tmp118, a
	ldrb	r3, [r7, #6]	@ tmp119, b
	smulbb	r3, r2, r3	@ tmp121, tmp118, tmp119
	strb	r3, [r7, #5]	@ tmp122, c
@ 1_registers.c:9: }
	.loc 1 9 1
	nop	
	adds	r7, r7, #12	@,,
	.cfi_def_cfa_offset 4
	mov	sp, r7	@,
	.cfi_def_cfa_register 13
	@ sp needed	@
	pop	{r7}		@
	.cfi_restore 7
	.cfi_def_cfa_offset 0
	bx	lr	@
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.file 2 "C:/arm-gnu-toolchain-arm-none-eabi/arm-none-eabi/include/machine/_default_types.h"
	.file 3 "C:/arm-gnu-toolchain-arm-none-eabi/arm-none-eabi/include/sys/_stdint.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0xb5
	.2byte	0x5
	.byte	0x1
	.byte	0x4
	.4byte	.Ldebug_abbrev0
	.uleb128 0x4
	.4byte	.LASF11
	.byte	0x1d
	.4byte	.LASF12
	.4byte	.LASF13
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x3
	.4byte	.LASF9
	.byte	0x2
	.byte	0x2b
	.byte	0x17
	.4byte	0x39
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
	.uleb128 0x3
	.4byte	.LASF10
	.byte	0x3
	.byte	0x18
	.byte	0x13
	.4byte	0x2d
	.uleb128 0x6
	.4byte	.LASF14
	.byte	0x1
	.byte	0x3
	.byte	0x6
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.ascii	"a\000"
	.byte	0xd
	.4byte	0x78
	.uleb128 0x2
	.byte	0x91
	.sleb128 -9
	.uleb128 0x2
	.ascii	"b\000"
	.byte	0x10
	.4byte	0x78
	.uleb128 0x2
	.byte	0x91
	.sleb128 -10
	.uleb128 0x2
	.ascii	"c\000"
	.byte	0x13
	.4byte	0x78
	.uleb128 0x2
	.byte	0x91
	.sleb128 -11
	.byte	0
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
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0x21
	.sleb128 4
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
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
	.uleb128 0x7a
	.uleb128 0x19
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
.LASF9:
	.ascii	"__uint8_t\000"
.LASF12:
	.ascii	"1_registers.c\000"
.LASF1:
	.ascii	"unsigned char\000"
.LASF5:
	.ascii	"long unsigned int\000"
.LASF3:
	.ascii	"short unsigned int\000"
.LASF14:
	.ascii	"main\000"
.LASF8:
	.ascii	"unsigned int\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF10:
	.ascii	"uint8_t\000"
.LASF6:
	.ascii	"long long int\000"
.LASF13:
	.ascii	"C:\\\\Users\\\\Choaib ELMADI\\\\Documents\\\\D.I.F."
	.ascii	"Y\\\\2. Electronics\\\\7. STM32\\\\Docs\\\\I Introd"
	.ascii	"uction\\\\Chapter 1 - Introduction to STM32 MCU Por"
	.ascii	"tfolio\\\\Examples\000"
.LASF2:
	.ascii	"short int\000"
.LASF4:
	.ascii	"long int\000"
.LASF0:
	.ascii	"signed char\000"
.LASF11:
	.ascii	"GNU C17 13.3.1 20240614 -mcpu=cortex-m4 -mthumb -mf"
	.ascii	"loat-abi=soft -march=armv7e-m -g -O0\000"
	.ident	"GCC: (Arm GNU Toolchain 13.3.Rel1 (Build arm-13.24)) 13.3.1 20240614"
