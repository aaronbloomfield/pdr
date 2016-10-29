	.text
	.intel_syntax noprefix
	.file	"test_abs_c.c"
	.globl	absolute_value
	.align	16, 0x90
	.type	absolute_value,@function
absolute_value:                         # @absolute_value
	.cfi_startproc
# BB#0:
	mov	qword ptr [rsp - 8], rdi
	cmp	qword ptr [rsp - 8], 0
	jge	.LBB0_2
# BB#1:
	xor	eax, eax
	mov	ecx, eax
	sub	rcx, qword ptr [rsp - 8]
	mov	qword ptr [rsp - 8], rcx
.LBB0_2:
	mov	rax, qword ptr [rsp - 8]
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
	sub	rsp, 40
.Ltmp0:
	.cfi_def_cfa_offset 48
	movabs	rdi, .L.str
	mov	dword ptr [rsp + 36], 0
	mov	qword ptr [rsp + 24], 0
	mov	al, 0
	call	printf
	movabs	rdi, .L.str.1
	lea	rsi, [rsp + 24]
	mov	dword ptr [rsp + 12], eax # 4-byte Spill
	mov	al, 0
	call	__isoc99_scanf
	mov	rdi, qword ptr [rsp + 24]
	mov	dword ptr [rsp + 8], eax # 4-byte Spill
	call	absolute_value
	movabs	rdi, .L.str.2
	mov	qword ptr [rsp + 16], rax
	mov	rsi, qword ptr [rsp + 16]
	mov	al, 0
	call	printf
	xor	ecx, ecx
	mov	dword ptr [rsp + 4], eax # 4-byte Spill
	mov	eax, ecx
	add	rsp, 40
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
	.asciz	"%ld"
	.size	.L.str.1, 4

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"The result is: %ld\n"
	.size	.L.str.2, 20


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
