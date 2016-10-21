	.text
	.intel_syntax noprefix
	.file	"test_max.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rbp - 4], eax # 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	max
	.align	16, 0x90
	.type	max,@function
max:                                    # @max
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp5:
	.cfi_def_cfa_register rbp
	mov	dword ptr [rbp - 4], edi
	mov	dword ptr [rbp - 8], esi
	mov	esi, dword ptr [rbp - 4]
	cmp	esi, dword ptr [rbp - 8]
	jle	.LBB1_2
# BB#1:
	mov	eax, dword ptr [rbp - 4]
	mov	dword ptr [rbp - 12], eax
	jmp	.LBB1_3
.LBB1_2:
	mov	eax, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 12], eax
.LBB1_3:
	mov	eax, dword ptr [rbp - 12]
	pop	rbp
	ret
.Lfunc_end1:
	.size	max, .Lfunc_end1-max
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp8:
	.cfi_def_cfa_register rbp
	sub	rsp, 64
	movabs	rdi, _ZSt4cout
	movabs	rsi, .L.str
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], 0
	mov	dword ptr [rbp - 12], 0
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	movabs	rdi, _ZSt3cin
	lea	rsi, [rbp - 8]
	mov	qword ptr [rbp - 24], rax # 8-byte Spill
	call	_ZNSirsERi
	movabs	rdi, _ZSt4cout
	movabs	rsi, .L.str.1
	mov	qword ptr [rbp - 32], rax # 8-byte Spill
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	movabs	rdi, _ZSt3cin
	lea	rsi, [rbp - 12]
	mov	qword ptr [rbp - 40], rax # 8-byte Spill
	call	_ZNSirsERi
	mov	edi, dword ptr [rbp - 8]
	mov	esi, dword ptr [rbp - 12]
	mov	qword ptr [rbp - 48], rax # 8-byte Spill
	call	max
	movabs	rdi, _ZSt4cout
	movabs	rsi, .L.str.2
	mov	dword ptr [rbp - 16], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, dword ptr [rbp - 16]
	mov	rdi, rax
	call	_ZNSolsEi
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	xor	ecx, ecx
	mov	qword ptr [rbp - 56], rax # 8-byte Spill
	mov	eax, ecx
	add	rsp, 64
	pop	rbp
	ret
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_test_max.cpp,@function
_GLOBAL__sub_I_test_max.cpp:            # @_GLOBAL__sub_I_test_max.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp11:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end3:
	.size	_GLOBAL__sub_I_test_max.cpp, .Lfunc_end3-_GLOBAL__sub_I_test_max.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter value 1: "
	.size	.L.str, 16

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Enter value 2: "
	.size	.L.str.1, 16

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"The result is: "
	.size	.L.str.2, 16

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_test_max.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
