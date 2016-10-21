	.text
	.file	"test_abs.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$_ZStL8__ioinit, %rdi
	callq	_ZNSt8ios_base4InitC1Ev
	movabsq	$_ZNSt8ios_base4InitD1Ev, %rdi
	movabsq	$_ZStL8__ioinit, %rsi
	movabsq	$__dso_handle, %rdx
	callq	__cxa_atexit
	movl	%eax, -4(%rbp)          # 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
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
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jge	.LBB1_2
# BB#1:
	xorl	%eax, %eax
	subl	-4(%rbp), %eax
	movl	%eax, -4(%rbp)
.LBB1_2:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
.Lfunc_end1:
	.size	absolute_value, .Lfunc_end1-absolute_value
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movabsq	$_ZSt4cout, %rdi
	movabsq	$.L.str, %rsi
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabsq	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %rsi
	movq	%rax, %rdi
	callq	_ZNSolsEPFRSoS_E
	movabsq	$_ZSt3cin, %rdi
	leaq	-8(%rbp), %rsi
	movq	%rax, -24(%rbp)         # 8-byte Spill
	callq	_ZNSirsERi
	movl	-8(%rbp), %edi
	movq	%rax, -32(%rbp)         # 8-byte Spill
	callq	absolute_value
	movabsq	$_ZSt4cout, %rdi
	movabsq	$.L.str.1, %rsi
	movl	%eax, -12(%rbp)
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-12(%rbp), %esi
	movq	%rax, %rdi
	callq	_ZNSolsEi
	movabsq	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %rsi
	movq	%rax, %rdi
	callq	_ZNSolsEPFRSoS_E
	xorl	%ecx, %ecx
	movq	%rax, -40(%rbp)         # 8-byte Spill
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_test_abs.cpp,@function
_GLOBAL__sub_I_test_abs.cpp:            # @_GLOBAL__sub_I_test_abs.cpp
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp11:
	.cfi_def_cfa_register %rbp
	callq	__cxx_global_var_init
	popq	%rbp
	retq
.Lfunc_end3:
	.size	_GLOBAL__sub_I_test_abs.cpp, .Lfunc_end3-_GLOBAL__sub_I_test_abs.cpp
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
	.quad	_GLOBAL__sub_I_test_abs.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
