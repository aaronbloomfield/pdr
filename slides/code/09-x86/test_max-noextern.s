	.file	"foo.cpp"
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

	.globl	_Z3maxii
	.align	16, 0x90
	.type	_Z3maxii,@function
_Z3maxii:                               # @_Z3maxii
# BB#0:
	sub	ESP, 12
	mov	EAX, DWORD PTR [ESP + 20]
	mov	ECX, DWORD PTR [ESP + 16]
	mov	DWORD PTR [ESP + 8], ECX
	mov	DWORD PTR [ESP + 4], EAX
	mov	EAX, DWORD PTR [ESP + 8]
	cmp	EAX, DWORD PTR [ESP + 4]
	jle	.LBB1_2
# BB#1:
	mov	EAX, DWORD PTR [ESP + 8]
	mov	DWORD PTR [ESP], EAX
	jmp	.LBB1_3
.LBB1_2:
	mov	EAX, DWORD PTR [ESP + 4]
	mov	DWORD PTR [ESP], EAX
.LBB1_3:
	mov	EAX, DWORD PTR [ESP]
	add	ESP, 12
	ret
.Ltmp8:
	.size	_Z3maxii, .Ltmp8-_Z3maxii

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
	sub	ESP, 56
	lea	EAX, DWORD PTR [_ZSt4cout]
	lea	ECX, DWORD PTR [.L.str]
	mov	DWORD PTR [EBP - 4], 0
	mov	DWORD PTR [EBP - 8], 0
	mov	DWORD PTR [EBP - 12], 0
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
	mov	DWORD PTR [EBP - 20], EAX # 4-byte Spill
	call	_ZNSirsERi
	lea	ECX, DWORD PTR [_ZSt4cout]
	lea	EDX, DWORD PTR [.L.str1]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	mov	DWORD PTR [EBP - 24], EAX # 4-byte Spill
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	ECX, DWORD PTR [_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEPFRSoS_E
	lea	ECX, DWORD PTR [_ZSt3cin]
	lea	EDX, DWORD PTR [EBP - 12]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	mov	DWORD PTR [EBP - 28], EAX # 4-byte Spill
	call	_ZNSirsERi
	mov	ECX, DWORD PTR [EBP - 8]
	mov	EDX, DWORD PTR [EBP - 12]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	mov	DWORD PTR [EBP - 32], EAX # 4-byte Spill
	call	_Z3maxii
	lea	ECX, DWORD PTR [_ZSt4cout]
	lea	EDX, DWORD PTR [.L.str2]
	mov	DWORD PTR [EBP - 16], EAX
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	ECX, DWORD PTR [EBP - 16]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEi
	lea	ECX, DWORD PTR [_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEPFRSoS_E
	mov	ECX, 0
	mov	DWORD PTR [EBP - 36], EAX # 4-byte Spill
	mov	EAX, ECX
	add	ESP, 56
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
	.asciz	 "Enter value 1: "
	.size	.L.str, 16

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "Enter value 2: "
	.size	.L.str1, 16

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "The result is: "
	.size	.L.str2, 16

	.section	.ctors,"aw",@progbits
	.align	4
	.long	_GLOBAL__I_a

	.section	".note.GNU-stack","",@progbits
