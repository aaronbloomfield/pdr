	.file	"test_abs_c.c"
	.intel_syntax noprefix
	.text
	.globl	absolute_value
	.type	absolute_value, @function
absolute_value:
.LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	cmp	DWORD PTR [ebp+8], 0
	jns	.L2
	neg	DWORD PTR [ebp+8]
.L2:
	mov	eax, DWORD PTR [ebp+8]
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	absolute_value, .-absolute_value
	.section	.rodata
.LC0:
	.string	"Enter a value: "
.LC1:
	.string	"%d"
.LC2:
	.string	"The result is: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
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
	mov	DWORD PTR [ebp-20], 0
	sub	esp, 12
	push	OFFSET FLAT:.LC0
	call	puts
	add	esp, 16
	sub	esp, 8
	lea	eax, [ebp-20]
	push	eax
	push	OFFSET FLAT:.LC1
	call	__isoc99_scanf
	add	esp, 16
	mov	eax, DWORD PTR [ebp-20]
	sub	esp, 12
	push	eax
	call	absolute_value
	add	esp, 16
	mov	DWORD PTR [ebp-16], eax
	sub	esp, 8
	push	DWORD PTR [ebp-16]
	push	OFFSET FLAT:.LC2
	call	printf
	add	esp, 16
	mov	eax, 0
	mov	edx, DWORD PTR [ebp-12]
	xor	edx, DWORD PTR gs:20
	je	.L6
	call	__stack_chk_fail
.L6:
	mov	ecx, DWORD PTR [ebp-4]
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	lea	esp, [ecx-4]
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
