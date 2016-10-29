	.text
	.intel_syntax noprefix
	.file	"test_abs_int.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rsp + 4], eax # 4-byte Spill
	pop	rax
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	absolute_value
	.align	16, 0x90
	.type	absolute_value,@function
absolute_value:                         # @absolute_value
	.cfi_startproc
# BB#0:
	mov	dword ptr [rsp - 4], edi
	cmp	dword ptr [rsp - 4], 0
	jge	.LBB1_2
# BB#1:
	xor	eax, eax
	sub	eax, dword ptr [rsp - 4]
	mov	dword ptr [rsp - 4], eax
.LBB1_2:
	mov	eax, dword ptr [rsp - 4]
	ret
.Lfunc_end1:
	.size	absolute_value, .Lfunc_end1-absolute_value
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	sub	rsp, 40
.Ltmp1:
	.cfi_def_cfa_offset 48
	movabs	rdi, _ZSt4cout
	movabs	rsi, .L.str
	mov	dword ptr [rsp + 36], 0
	mov	dword ptr [rsp + 32], 0
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	movabs	rdi, _ZSt3cin
	lea	rsi, [rsp + 32]
	mov	qword ptr [rsp + 16], rax # 8-byte Spill
	call	_ZNSirsERi
	mov	edi, dword ptr [rsp + 32]
	mov	qword ptr [rsp + 8], rax # 8-byte Spill
	call	absolute_value
	movabs	rdi, _ZSt4cout
	movabs	rsi, .L.str.1
	mov	dword ptr [rsp + 28], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, dword ptr [rsp + 28]
	mov	rdi, rax
	call	_ZNSolsEi
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	xor	ecx, ecx
	mov	qword ptr [rsp], rax    # 8-byte Spill
	mov	eax, ecx
	add	rsp, 40
	ret
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_test_abs_int.cpp,@function
_GLOBAL__sub_I_test_abs_int.cpp:        # @_GLOBAL__sub_I_test_abs_int.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp2:
	.cfi_def_cfa_offset 16
	call	__cxx_global_var_init
	pop	rax
	ret
.Lfunc_end3:
	.size	_GLOBAL__sub_I_test_abs_int.cpp, .Lfunc_end3-_GLOBAL__sub_I_test_abs_int.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter a value: "
	.size	.L.str, 16

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"The result is: "
	.size	.L.str.1, 16

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_test_abs_int.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
