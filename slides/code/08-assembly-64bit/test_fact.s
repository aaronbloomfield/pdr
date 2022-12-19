	.text
	.intel_syntax noprefix
	.file	"test_fact.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90         # -- Begin function __cxx_global_var_init
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# %bb.0:
	push	rax
	.cfi_def_cfa_offset 16
	movabs	rdi, offset _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, offset _ZNSt8ios_base4InitD1Ev
	movabs	rsi, offset _ZStL8__ioinit
	movabs	rdx, offset __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rsp + 4], eax # 4-byte Spill
	pop	rax
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc
                                        # -- End function
	.text
	.globl	fact                    # -- Begin function fact
	.p2align	4, 0x90
	.type	fact,@function
fact:                                   # @fact
	.cfi_startproc
# %bb.0:
	sub	rsp, 24
	.cfi_def_cfa_offset 32
	mov	dword ptr [rsp + 12], edi
	cmp	dword ptr [rsp + 12], 0
	jne	.LBB1_2
# %bb.1:
	mov	qword ptr [rsp + 16], 1
	jmp	.LBB1_3
.LBB1_2:
	mov	eax, dword ptr [rsp + 12]
	mov	ecx, eax
	mov	eax, dword ptr [rsp + 12]
	sub	eax, 1
	mov	edi, eax
	mov	qword ptr [rsp], rcx    # 8-byte Spill
	call	fact
	mov	rcx, qword ptr [rsp]    # 8-byte Reload
	imul	rcx, rax
	mov	qword ptr [rsp + 16], rcx
.LBB1_3:
	mov	rax, qword ptr [rsp + 16]
	add	rsp, 24
	ret
.Lfunc_end1:
	.size	fact, .Lfunc_end1-fact
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	movabs	rdi, offset _ZSt4cout
	movabs	rsi, offset .L.str
	mov	dword ptr [rsp + 36], 0
	mov	dword ptr [rsp + 32], 0
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, offset _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	movabs	rdi, offset _ZSt3cin
	lea	rsi, [rsp + 32]
	mov	qword ptr [rsp + 16], rax # 8-byte Spill
	call	_ZNSirsERj
	mov	edi, dword ptr [rsp + 32]
	mov	qword ptr [rsp + 8], rax # 8-byte Spill
	call	fact
	movabs	rdi, offset _ZSt4cout
	movabs	rsi, offset .L.str.1
	mov	qword ptr [rsp + 24], rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	rsi, qword ptr [rsp + 24]
	mov	rdi, rax
	call	_ZNSolsEl
	movabs	rsi, offset _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
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
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90         # -- Begin function _GLOBAL__sub_I_test_fact.cpp
	.type	_GLOBAL__sub_I_test_fact.cpp,@function
_GLOBAL__sub_I_test_fact.cpp:           # @_GLOBAL__sub_I_test_fact.cpp
	.cfi_startproc
# %bb.0:
	push	rax
	.cfi_def_cfa_offset 16
	call	__cxx_global_var_init
	pop	rax
	ret
.Lfunc_end3:
	.size	_GLOBAL__sub_I_test_fact.cpp, .Lfunc_end3-_GLOBAL__sub_I_test_fact.cpp
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter value for fact(): "
	.size	.L.str, 25

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"The result is: "
	.size	.L.str.1, 16

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_test_fact.cpp

	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
