	.file	"test_max.cpp"
	.text
	.globl	max
	.align	16, 0x90
	.type	max,@function
max:                                    # @max
# BB#0:
	mov	EAX, DWORD PTR [ESP + 8]
	mov	ECX, DWORD PTR [ESP + 4]
	cmp	ECX, EAX
	cmovg	EAX, ECX
	ret
.Ltmp0:
	.size	max, .Ltmp0-max

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp4:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp5:
	.cfi_def_cfa_offset 8
.Ltmp6:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp7:
	.cfi_def_cfa_register ebp
	push	EDI
	push	ESI
	sub	ESP, 32
.Ltmp8:
	.cfi_offset esi, -16
.Ltmp9:
	.cfi_offset edi, -12
	mov	DWORD PTR [EBP - 12], 0
	mov	DWORD PTR [EBP - 16], 0
	mov	DWORD PTR [ESP + 8], 15
	mov	DWORD PTR [ESP + 4], .L.str
	mov	DWORD PTR [ESP], _ZSt4cout
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	EAX, _ZSt4cout
	mov	EAX, DWORD PTR [EAX - 12]
	mov	ESI, DWORD PTR [EAX + _ZSt4cout+124]
	test	ESI, ESI
	je	.LBB1_13
# BB#1:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
	cmp	BYTE PTR [ESI + 28], 0
	je	.LBB1_3
# BB#2:
	mov	AL, BYTE PTR [ESI + 39]
	jmp	.LBB1_4
.LBB1_3:
	mov	DWORD PTR [ESP], ESI
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	EAX, DWORD PTR [ESI]
	mov	DWORD PTR [ESP], ESI
	mov	DWORD PTR [ESP + 4], 10
	call	DWORD PTR [EAX + 24]
.LBB1_4:                                # %_ZNKSt5ctypeIcE5widenEc.exit
	movsx	EAX, AL
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP], _ZSt4cout
	call	_ZNSo3putEc
	mov	DWORD PTR [ESP], EAX
	call	_ZNSo5flushEv
	lea	EAX, DWORD PTR [EBP - 12]
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP], _ZSt3cin
	call	_ZNSirsERi
	mov	DWORD PTR [ESP + 8], 15
	mov	DWORD PTR [ESP + 4], .L.str1
	mov	DWORD PTR [ESP], _ZSt4cout
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	EAX, _ZSt4cout
	mov	EAX, DWORD PTR [EAX - 12]
	mov	ESI, DWORD PTR [EAX + _ZSt4cout+124]
	test	ESI, ESI
	je	.LBB1_13
# BB#5:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit5
	cmp	BYTE PTR [ESI + 28], 0
	je	.LBB1_7
# BB#6:
	mov	AL, BYTE PTR [ESI + 39]
	jmp	.LBB1_8
.LBB1_7:
	mov	DWORD PTR [ESP], ESI
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	EAX, DWORD PTR [ESI]
	mov	DWORD PTR [ESP], ESI
	mov	DWORD PTR [ESP + 4], 10
	call	DWORD PTR [EAX + 24]
.LBB1_8:                                # %_ZNKSt5ctypeIcE5widenEc.exit2
	movsx	EAX, AL
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP], _ZSt4cout
	call	_ZNSo3putEc
	mov	DWORD PTR [ESP], EAX
	call	_ZNSo5flushEv
	lea	EAX, DWORD PTR [EBP - 16]
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP], _ZSt3cin
	call	_ZNSirsERi
	mov	ESI, DWORD PTR [EBP - 16]
	mov	EAX, DWORD PTR [EBP - 12]
	mov	DWORD PTR [ESP + 8], 15
	mov	DWORD PTR [ESP + 4], .L.str2
	mov	DWORD PTR [ESP], _ZSt4cout
	cmp	EAX, ESI
	cmovg	ESI, EAX
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	DWORD PTR [ESP + 4], ESI
	mov	DWORD PTR [ESP], _ZSt4cout
	call	_ZNSolsEi
	mov	ESI, EAX
	mov	EAX, DWORD PTR [ESI]
	mov	EAX, DWORD PTR [EAX - 12]
	mov	EDI, DWORD PTR [EAX + ESI + 124]
	test	EDI, EDI
	je	.LBB1_13
# BB#9:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit6
	cmp	BYTE PTR [EDI + 28], 0
	je	.LBB1_11
# BB#10:
	mov	AL, BYTE PTR [EDI + 39]
	jmp	.LBB1_12
.LBB1_11:
	mov	DWORD PTR [ESP], EDI
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	EAX, DWORD PTR [EDI]
	mov	DWORD PTR [ESP], EDI
	mov	DWORD PTR [ESP + 4], 10
	call	DWORD PTR [EAX + 24]
.LBB1_12:                               # %_ZNKSt5ctypeIcE5widenEc.exit4
	movsx	EAX, AL
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP], ESI
	call	_ZNSo3putEc
	mov	DWORD PTR [ESP], EAX
	call	_ZNSo5flushEv
	xor	EAX, EAX
	add	ESP, 32
	pop	ESI
	pop	EDI
	pop	EBP
	ret
.LBB1_13:
	call	_ZSt16__throw_bad_castv
.Ltmp10:
	.size	main, .Ltmp10-main
.Ltmp11:
	.cfi_endproc
.Leh_func_end1:

	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
.Ltmp14:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp15:
	.cfi_def_cfa_offset 8
.Ltmp16:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp17:
	.cfi_def_cfa_register ebp
	sub	ESP, 24
	mov	DWORD PTR [ESP], _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [ESP + 8], __dso_handle
	mov	DWORD PTR [ESP + 4], _ZStL8__ioinit
	mov	DWORD PTR [ESP], _ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
	add	ESP, 24
	pop	EBP
	ret
.Ltmp18:
	.size	_GLOBAL__I_a, .Ltmp18-_GLOBAL__I_a
.Ltmp19:
	.cfi_endproc
.Leh_func_end2:

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
