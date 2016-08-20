	.file	"test_abs.cpp"
	.text
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
.Ltmp2:
	.cfi_startproc
# BB#0:
	pushl	%ebp
.Ltmp3:
	.cfi_def_cfa_offset 8
.Ltmp4:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp5:
	.cfi_def_cfa_register %ebp
	subl	$24, %esp
	leal	_ZStL8__ioinit, %eax
	movl	%eax, (%esp)
	calll	_ZNSt8ios_base4InitC1Ev
	leal	_ZNSt8ios_base4InitD1Ev, %eax
	leal	_ZStL8__ioinit, %ecx
	leal	__dso_handle, %edx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	calll	__cxa_atexit
	movl	%eax, -4(%ebp)          # 4-byte Spill
	addl	$24, %esp
	popl	%ebp
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
	pushl	%eax
	movl	8(%esp), %eax
	movl	%eax, (%esp)
	cmpl	$0, (%esp)
	jge	.LBB1_2
# BB#1:
	movl	$0, %eax
	subl	(%esp), %eax
	movl	%eax, (%esp)
.LBB1_2:
	movl	(%esp), %eax
	popl	%edx
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
	pushl	%ebp
.Ltmp12:
	.cfi_def_cfa_offset 8
.Ltmp13:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp14:
	.cfi_def_cfa_register %ebp
	subl	$40, %esp
	leal	_ZSt4cout, %eax
	leal	.L.str, %ecx
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZNSolsEPFRSoS_E
	leal	_ZSt3cin, %ecx
	leal	-8(%ebp), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -16(%ebp)         # 4-byte Spill
	calll	_ZNSirsERi
	movl	-8(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, -20(%ebp)         # 4-byte Spill
	calll	absolute_value
	leal	_ZSt4cout, %ecx
	leal	.L.str1, %edx
	movl	%eax, -12(%ebp)
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-12(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZNSolsEi
	leal	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZNSolsEPFRSoS_E
	movl	$0, %ecx
	movl	%eax, -24(%ebp)         # 4-byte Spill
	movl	%ecx, %eax
	addl	$40, %esp
	popl	%ebp
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
	pushl	%ebp
.Ltmp20:
	.cfi_def_cfa_offset 8
.Ltmp21:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp22:
	.cfi_def_cfa_register %ebp
	subl	$8, %esp
	calll	__cxx_global_var_init
	addl	$8, %esp
	popl	%ebp
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
