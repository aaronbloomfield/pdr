	.file	"test_max.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	max
	.type	max, @function
max:
.LFB1021:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	cmp	eax, DWORD PTR [ebp+12]
	jle	.L2
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-4], eax
	jmp	.L3
.L2:
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [ebp-4], eax
.L3:
	mov	eax, DWORD PTR [ebp-4]
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1021:
	.size	max, .-max
	.section	.rodata
.LC0:
	.string	"Enter value 1: "
.LC1:
	.string	"Enter value 2: "
.LC2:
	.string	"The result is: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1022:
	.cfi_startproc
	lea	ecx, [esp+4]
	.cfi_def_cfa 1, 0
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	mov	ebp, esp
	push	ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	sub	esp, 20
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-12], eax
	xor	eax, eax
	mov	DWORD PTR [ebp-24], 0
	mov	DWORD PTR [ebp-20], 0
	sub	esp, 8
	push	OFFSET FLAT:.LC0
	push	OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	esp, 16
	sub	esp, 8
	push	OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	push	eax
	call	_ZNSolsEPFRSoS_E
	add	esp, 16
	sub	esp, 8
	lea	eax, [ebp-24]
	push	eax
	push	OFFSET FLAT:_ZSt3cin
	call	_ZNSirsERi
	add	esp, 16
	sub	esp, 8
	push	OFFSET FLAT:.LC1
	push	OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	esp, 16
	sub	esp, 8
	push	OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	push	eax
	call	_ZNSolsEPFRSoS_E
	add	esp, 16
	sub	esp, 8
	lea	eax, [ebp-20]
	push	eax
	push	OFFSET FLAT:_ZSt3cin
	call	_ZNSirsERi
	add	esp, 16
	mov	edx, DWORD PTR [ebp-20]
	mov	eax, DWORD PTR [ebp-24]
	sub	esp, 8
	push	edx
	push	eax
	call	max
	add	esp, 16
	mov	DWORD PTR [ebp-16], eax
	sub	esp, 8
	push	OFFSET FLAT:.LC2
	push	OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	esp, 16
	sub	esp, 8
	push	DWORD PTR [ebp-16]
	push	eax
	call	_ZNSolsEi
	add	esp, 16
	sub	esp, 8
	push	OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	push	eax
	call	_ZNSolsEPFRSoS_E
	add	esp, 16
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-12]
	xor	ecx, DWORD PTR gs:20
	je	.L7
	call	__stack_chk_fail
.L7:
	mov	ecx, DWORD PTR [ebp-4]
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	lea	esp, [ecx-4]
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1022:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1031:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 8
	cmp	DWORD PTR [ebp+8], 1
	jne	.L10
	cmp	DWORD PTR [ebp+12], 65535
	jne	.L10
	sub	esp, 12
	push	OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	add	esp, 16
	sub	esp, 4
	push	OFFSET FLAT:__dso_handle
	push	OFFSET FLAT:_ZStL8__ioinit
	push	OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
	add	esp, 16
.L10:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1031:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_max, @function
_GLOBAL__sub_I_max:
.LFB1032:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 8
	sub	esp, 8
	push	65535
	push	1
	call	_Z41__static_initialization_and_destruction_0ii
	add	esp, 16
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1032:
	.size	_GLOBAL__sub_I_max, .-_GLOBAL__sub_I_max
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_max
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
