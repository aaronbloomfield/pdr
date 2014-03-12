	.file	"test_string_compare.cpp"
	.text
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
.Ltmp2:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp3:
	.cfi_def_cfa_offset 8
.Ltmp4:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp5:
	.cfi_def_cfa_register ebp
	sub	ESP, 24
	lea	EAX, DWORD PTR [_ZStL8__ioinit]
	mov	DWORD PTR [ESP], EAX
	call	_ZNSt8ios_base4InitC1Ev
	lea	EAX, DWORD PTR [_ZNSt8ios_base4InitD1Ev]
	lea	ECX, DWORD PTR [_ZStL8__ioinit]
	lea	EDX, DWORD PTR [__dso_handle]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	mov	DWORD PTR [ESP + 8], EDX
	call	__cxa_atexit
	mov	DWORD PTR [EBP - 4], EAX # 4-byte Spill
	add	ESP, 24
	pop	EBP
	ret
.Ltmp6:
	.size	__cxx_global_var_init, .Ltmp6-__cxx_global_var_init
.Ltmp7:
	.cfi_endproc
.Leh_func_end0:

	.globl	compare_string
	.align	16, 0x90
	.type	compare_string,@function
compare_string:                         # @compare_string
# BB#0:
	sub	ESP, 12
	mov	EAX, DWORD PTR [ESP + 20]
	mov	ECX, DWORD PTR [ESP + 16]
	mov	DWORD PTR [ESP + 8], ECX
	mov	DWORD PTR [ESP + 4], EAX
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	mov	AL, 0
	mov	ECX, DWORD PTR [ESP + 8]
	movsx	ECX, BYTE PTR [ECX]
	cmp	ECX, 0
	mov	BYTE PTR [ESP + 3], AL  # 1-byte Spill
	je	.LBB1_3
# BB#2:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	EAX, DWORD PTR [ESP + 8]
	movsx	EAX, BYTE PTR [EAX]
	mov	ECX, DWORD PTR [ESP + 4]
	movsx	ECX, BYTE PTR [ECX]
	cmp	EAX, ECX
	sete	DL
	mov	BYTE PTR [ESP + 3], DL  # 1-byte Spill
.LBB1_3:                                #   in Loop: Header=BB1_1 Depth=1
	mov	AL, BYTE PTR [ESP + 3]  # 1-byte Reload
	test	AL, 1
	jne	.LBB1_4
	jmp	.LBB1_5
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
	mov	EAX, DWORD PTR [ESP + 8]
	add	EAX, 1
	mov	DWORD PTR [ESP + 8], EAX
	mov	EAX, DWORD PTR [ESP + 4]
	add	EAX, 1
	mov	DWORD PTR [ESP + 4], EAX
	jmp	.LBB1_1
.LBB1_5:
	mov	EAX, DWORD PTR [ESP + 8]
	movsx	EAX, BYTE PTR [EAX]
	mov	ECX, DWORD PTR [ESP + 4]
	movsx	ECX, BYTE PTR [ECX]
	cmp	EAX, ECX
	sete	DL
	and	DL, 1
	movzx	EAX, DL
	add	ESP, 12
	ret
.Ltmp8:
	.size	compare_string, .Ltmp8-compare_string

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp46:
	.cfi_startproc
	.cfi_personality 0, __gxx_personality_v0
.Leh_func_begin2:
	.cfi_lsda 0, .Lexception2
# BB#0:
	push	EBP
.Ltmp47:
	.cfi_def_cfa_offset 8
.Ltmp48:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp49:
	.cfi_def_cfa_register ebp
	sub	ESP, 104
	mov	DWORD PTR [EBP - 4], 0
	lea	EAX, DWORD PTR [EBP - 8]
	mov	ECX, ESP
	mov	DWORD PTR [ECX], EAX
	call	_ZNSsC1Ev
.Ltmp9:
	lea	EAX, DWORD PTR [EBP - 16]
	mov	ECX, ESP
	mov	DWORD PTR [ECX], EAX
	call	_ZNSsC1Ev
.Ltmp10:
	jmp	.LBB2_1
.LBB2_1:
.Ltmp11:
	mov	EAX, ESP
	mov	DWORD PTR [EAX + 4], .L.str
	mov	DWORD PTR [EAX], _ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp12:
	mov	DWORD PTR [EBP - 36], EAX # 4-byte Spill
	jmp	.LBB2_2
.LBB2_2:
.Ltmp13:
	mov	EAX, ESP
	mov	ECX, DWORD PTR [EBP - 36] # 4-byte Reload
	mov	DWORD PTR [EAX], ECX
	mov	DWORD PTR [EAX + 4], _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	call	_ZNSolsEPFRSoS_E
.Ltmp14:
	mov	DWORD PTR [EBP - 40], EAX # 4-byte Spill
	jmp	.LBB2_3
.LBB2_3:
.Ltmp15:
	lea	EAX, DWORD PTR [EBP - 8]
	mov	ECX, ESP
	mov	DWORD PTR [ECX + 4], EAX
	mov	DWORD PTR [ECX], _ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
.Ltmp16:
	mov	DWORD PTR [EBP - 44], EAX # 4-byte Spill
	jmp	.LBB2_4
.LBB2_4:
.Ltmp17:
	mov	EAX, ESP
	mov	DWORD PTR [EAX + 4], .L.str1
	mov	DWORD PTR [EAX], _ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp18:
	mov	DWORD PTR [EBP - 48], EAX # 4-byte Spill
	jmp	.LBB2_5
.LBB2_5:
.Ltmp19:
	mov	EAX, ESP
	mov	ECX, DWORD PTR [EBP - 48] # 4-byte Reload
	mov	DWORD PTR [EAX], ECX
	mov	DWORD PTR [EAX + 4], _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	call	_ZNSolsEPFRSoS_E
.Ltmp20:
	mov	DWORD PTR [EBP - 52], EAX # 4-byte Spill
	jmp	.LBB2_6
.LBB2_6:
.Ltmp21:
	lea	EAX, DWORD PTR [EBP - 16]
	mov	ECX, ESP
	mov	DWORD PTR [ECX + 4], EAX
	mov	DWORD PTR [ECX], _ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
.Ltmp22:
	mov	DWORD PTR [EBP - 56], EAX # 4-byte Spill
	jmp	.LBB2_7
.LBB2_7:
.Ltmp23:
	lea	EAX, DWORD PTR [EBP - 8]
	mov	ECX, ESP
	mov	DWORD PTR [ECX], EAX
	call	_ZNKSs5c_strEv
.Ltmp24:
	mov	DWORD PTR [EBP - 60], EAX # 4-byte Spill
	jmp	.LBB2_8
.LBB2_8:
.Ltmp25:
	lea	EAX, DWORD PTR [EBP - 16]
	mov	ECX, ESP
	mov	DWORD PTR [ECX], EAX
	call	_ZNKSs5c_strEv
.Ltmp26:
	mov	DWORD PTR [EBP - 64], EAX # 4-byte Spill
	jmp	.LBB2_9
.LBB2_9:
.Ltmp27:
	mov	EAX, ESP
	mov	ECX, DWORD PTR [EBP - 64] # 4-byte Reload
	mov	DWORD PTR [EAX + 4], ECX
	mov	EDX, DWORD PTR [EBP - 60] # 4-byte Reload
	mov	DWORD PTR [EAX], EDX
	call	compare_string
.Ltmp28:
	mov	BYTE PTR [EBP - 65], AL # 1-byte Spill
	jmp	.LBB2_10
.LBB2_10:
	mov	AL, BYTE PTR [EBP - 65] # 1-byte Reload
	and	AL, 1
	mov	BYTE PTR [EBP - 25], AL
.Ltmp29:
	mov	ECX, ESP
	mov	DWORD PTR [ECX + 4], .L.str2
	mov	DWORD PTR [ECX], _ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp30:
	mov	DWORD PTR [EBP - 72], EAX # 4-byte Spill
	jmp	.LBB2_11
.LBB2_11:
	movzx	EAX, BYTE PTR [EBP - 25]
.Ltmp31:
	mov	ECX, ESP
	and	EAX, 1
	mov	DWORD PTR [ECX + 4], EAX
	mov	EAX, DWORD PTR [EBP - 72] # 4-byte Reload
	mov	DWORD PTR [ECX], EAX
	call	_ZNSolsEb
.Ltmp32:
	mov	DWORD PTR [EBP - 76], EAX # 4-byte Spill
	jmp	.LBB2_12
.LBB2_12:
.Ltmp33:
	mov	EAX, ESP
	mov	ECX, DWORD PTR [EBP - 76] # 4-byte Reload
	mov	DWORD PTR [EAX], ECX
	mov	DWORD PTR [EAX + 4], _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	call	_ZNSolsEPFRSoS_E
.Ltmp34:
	mov	DWORD PTR [EBP - 80], EAX # 4-byte Spill
	jmp	.LBB2_13
.LBB2_13:
	mov	DWORD PTR [EBP - 4], 0
	mov	DWORD PTR [EBP - 32], 1
.Ltmp38:
	lea	EAX, DWORD PTR [EBP - 16]
	mov	ECX, ESP
	mov	DWORD PTR [ECX], EAX
	call	_ZNSsD1Ev
.Ltmp39:
	jmp	.LBB2_16
.LBB2_14:
.Ltmp40:
	mov	DWORD PTR [EBP - 20], EAX
	mov	DWORD PTR [EBP - 24], EDX
	jmp	.LBB2_18
.LBB2_15:
.Ltmp35:
	mov	DWORD PTR [EBP - 20], EAX
	mov	DWORD PTR [EBP - 24], EDX
.Ltmp36:
	lea	EAX, DWORD PTR [EBP - 16]
	mov	EDX, ESP
	mov	DWORD PTR [EDX], EAX
	call	_ZNSsD1Ev
.Ltmp37:
	jmp	.LBB2_17
.LBB2_16:
	lea	EAX, DWORD PTR [EBP - 8]
	mov	DWORD PTR [ESP], EAX
	call	_ZNSsD1Ev
	mov	EAX, DWORD PTR [EBP - 4]
	add	ESP, 104
	pop	EBP
	ret
.LBB2_17:
.LBB2_18:
.Ltmp41:
	lea	EAX, DWORD PTR [EBP - 8]
	mov	ECX, ESP
	mov	DWORD PTR [ECX], EAX
	call	_ZNSsD1Ev
.Ltmp42:
	jmp	.LBB2_19
.LBB2_19:
# BB#20:
	mov	EAX, DWORD PTR [EBP - 20]
	mov	ECX, DWORD PTR [EBP - 24]
	mov	DWORD PTR [EBP - 84], ECX # 4-byte Spill
	mov	DWORD PTR [EBP - 88], EAX # 4-byte Spill
	jmp	.LBB2_22
.LBB2_21:
.Ltmp43:
	mov	DWORD PTR [EBP - 92], EDX # 4-byte Spill
	mov	DWORD PTR [EBP - 96], EAX # 4-byte Spill
	call	_ZSt9terminatev
.LBB2_22:                               # %unwind_resume
	mov	EAX, DWORD PTR [EBP - 88] # 4-byte Reload
	mov	DWORD PTR [ESP], EAX
	call	_Unwind_Resume
.Ltmp50:
	.size	main, .Ltmp50-main
.Ltmp51:
	.cfi_endproc
.Leh_func_end2:
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table2:
.Lexception2:
	.byte	255                     # @LPStart Encoding = omit
	.byte	0                       # @TType Encoding = absptr
	.byte	240                     # @TType base offset
	.zero	1
	.byte	3                       # Call site Encoding = udata4
	.byte	104                     # Call site table length
.Lset0 = .Leh_func_begin2-.Leh_func_begin2 # >> Call Site 1 <<
	.long	.Lset0
.Lset1 = .Ltmp9-.Leh_func_begin2        #   Call between .Leh_func_begin2 and .Ltmp9
	.long	.Lset1
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lset2 = .Ltmp9-.Leh_func_begin2        # >> Call Site 2 <<
	.long	.Lset2
.Lset3 = .Ltmp10-.Ltmp9                 #   Call between .Ltmp9 and .Ltmp10
	.long	.Lset3
.Lset4 = .Ltmp40-.Leh_func_begin2       #     jumps to .Ltmp40
	.long	.Lset4
	.byte	0                       #   On action: cleanup
.Lset5 = .Ltmp11-.Leh_func_begin2       # >> Call Site 3 <<
	.long	.Lset5
.Lset6 = .Ltmp34-.Ltmp11                #   Call between .Ltmp11 and .Ltmp34
	.long	.Lset6
.Lset7 = .Ltmp35-.Leh_func_begin2       #     jumps to .Ltmp35
	.long	.Lset7
	.byte	0                       #   On action: cleanup
.Lset8 = .Ltmp38-.Leh_func_begin2       # >> Call Site 4 <<
	.long	.Lset8
.Lset9 = .Ltmp39-.Ltmp38                #   Call between .Ltmp38 and .Ltmp39
	.long	.Lset9
.Lset10 = .Ltmp40-.Leh_func_begin2      #     jumps to .Ltmp40
	.long	.Lset10
	.byte	0                       #   On action: cleanup
.Lset11 = .Ltmp36-.Leh_func_begin2      # >> Call Site 5 <<
	.long	.Lset11
.Lset12 = .Ltmp37-.Ltmp36               #   Call between .Ltmp36 and .Ltmp37
	.long	.Lset12
.Lset13 = .Ltmp43-.Leh_func_begin2      #     jumps to .Ltmp43
	.long	.Lset13
	.byte	1                       #   On action: 1
.Lset14 = .Ltmp37-.Leh_func_begin2      # >> Call Site 6 <<
	.long	.Lset14
.Lset15 = .Ltmp41-.Ltmp37               #   Call between .Ltmp37 and .Ltmp41
	.long	.Lset15
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lset16 = .Ltmp41-.Leh_func_begin2      # >> Call Site 7 <<
	.long	.Lset16
.Lset17 = .Ltmp42-.Ltmp41               #   Call between .Ltmp41 and .Ltmp42
	.long	.Lset17
.Lset18 = .Ltmp43-.Leh_func_begin2      #     jumps to .Ltmp43
	.long	.Lset18
	.byte	1                       #   On action: 1
.Lset19 = .Ltmp42-.Leh_func_begin2      # >> Call Site 8 <<
	.long	.Lset19
.Lset20 = .Leh_func_end2-.Ltmp42        #   Call between .Ltmp42 and .Leh_func_end2
	.long	.Lset20
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.byte	1                       # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                       #   No further actions
                                        # >> Catch TypeInfos <<
	.long	0                       # TypeInfo 1
	.align	4

	.text
	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
.Ltmp54:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp55:
	.cfi_def_cfa_offset 8
.Ltmp56:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp57:
	.cfi_def_cfa_register ebp
	sub	ESP, 8
	call	__cxx_global_var_init
	add	ESP, 8
	pop	EBP
	ret
.Ltmp58:
	.size	_GLOBAL__I_a, .Ltmp58-_GLOBAL__I_a
.Ltmp59:
	.cfi_endproc
.Leh_func_end3:

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Enter string 1: "
	.size	.L.str, 17

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "Enter string 2: "
	.size	.L.str1, 17

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "The result is: "
	.size	.L.str2, 16

	.section	.ctors,"aw",@progbits
	.align	4
	.long	_GLOBAL__I_a

	.section	".note.GNU-stack","",@progbits
