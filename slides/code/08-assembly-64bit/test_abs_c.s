	.text
	.intel_syntax noprefix
	.file	"test_abs_c.c"
	.globl	absolute_value
	.align	16, 0x90
	.type	absolute_value,@function
absolute_value:                         # @absolute_value
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
	mov	dword ptr [rbp - 4], edi
	cmp	dword ptr [rbp - 4], 0
	jge	.LBB0_2
# BB#1:
	xor	eax, eax
	sub	eax, dword ptr [rbp - 4]
	mov	dword ptr [rbp - 4], eax
.LBB0_2:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
.Lfunc_end0:
	.size	absolute_value, .Lfunc_end0-absolute_value
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
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
	sub	rsp, 32
	movabs	rdi, .L.str
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], 0
	mov	al, 0
	call	printf
	movabs	rdi, .L.str.1
	lea	rsi, [rbp - 8]
	mov	dword ptr [rbp - 16], eax # 4-byte Spill
	mov	al, 0
	call	__isoc99_scanf
	mov	edi, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 20], eax # 4-byte Spill
	call	absolute_value
	movabs	rdi, .L.str.2
	mov	dword ptr [rbp - 12], eax
	mov	esi, dword ptr [rbp - 12]
	mov	al, 0
	call	printf
	xor	esi, esi
	mov	dword ptr [rbp - 24], eax # 4-byte Spill
	mov	eax, esi
	add	rsp, 32
	pop	rbp
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter a value: \n"
	.size	.L.str, 17

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"%d"
	.size	.L.str.1, 3

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"The result is: %d\n"
	.size	.L.str.2, 19


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
