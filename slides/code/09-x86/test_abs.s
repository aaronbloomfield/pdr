	.file	"test_abs.cpp"
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

	.globl	absolute_value
	.align	16, 0x90
	.type	absolute_value,@function
absolute_value:                         # @absolute_value
# BB#0:
	push	EAX
	mov	EAX, DWORD PTR [ESP + 8]
	mov	DWORD PTR [ESP], EAX
	cmp	DWORD PTR [ESP], 0
	jge	.LBB1_2
# BB#1:
	mov	EAX, 0
	sub	EAX, DWORD PTR [ESP]
	mov	DWORD PTR [ESP], EAX
.LBB1_2:
	mov	EAX, DWORD PTR [ESP]
	pop	EDX
	ret
.Ltmp8:
	.size	absolute_value, .Ltmp8-absolute_value

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp11:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp12:
	.cfi_def_cfa_offset 8
.Ltmp13:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp14:
	.cfi_def_cfa_register ebp
	sub	ESP, 40
	lea	EAX, DWORD PTR [_ZSt4cout]
	lea	ECX, DWORD PTR [.L.str]
	mov	DWORD PTR [EBP - 4], 0
	mov	DWORD PTR [EBP - 8], 0
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	ECX, DWORD PTR [_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEPFRSoS_E
	lea	ECX, DWORD PTR [_ZSt3cin]
	lea	EDX, DWORD PTR [EBP - 8]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	mov	DWORD PTR [EBP - 16], EAX # 4-byte Spill
	call	_ZNSirsERi
	mov	ECX, DWORD PTR [EBP - 8]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [EBP - 20], EAX # 4-byte Spill
	call	absolute_value
	lea	ECX, DWORD PTR [_ZSt4cout]
	lea	EDX, DWORD PTR [.L.str1]
	mov	DWORD PTR [EBP - 12], EAX
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	ECX, DWORD PTR [EBP - 12]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEi
	lea	ECX, DWORD PTR [_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEPFRSoS_E
	mov	ECX, 0
	mov	DWORD PTR [EBP - 24], EAX # 4-byte Spill
	mov	EAX, ECX
	add	ESP, 40
	pop	EBP
	ret
.Ltmp15:
	.size	main, .Ltmp15-main
.Ltmp16:
	.cfi_endproc
.Leh_func_end2:

	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
.Ltmp19:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp20:
	.cfi_def_cfa_offset 8
.Ltmp21:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp22:
	.cfi_def_cfa_register ebp
	sub	ESP, 8
	call	__cxx_global_var_init
	add	ESP, 8
	pop	EBP
	ret
.Ltmp23:
	.size	_GLOBAL__I_a, .Ltmp23-_GLOBAL__I_a
.Ltmp24:
	.cfi_endproc
.Leh_func_end3:

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Enter a value: "
	.size	.L.str, 16

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "The result is: "
	.size	.L.str1, 16

	.section	.ctors,"aw",@progbits
	.align	4
	.long	_GLOBAL__I_a

	.section	".note.GNU-stack","",@progbits
