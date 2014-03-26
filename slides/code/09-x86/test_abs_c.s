	.file	"test_abs_c.c"
	.intel_syntax noprefix
	.text
	.globl	_Z14absolute_valuei
	.type	_Z14absolute_valuei, @function
_Z14absolute_valuei:
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
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE0:
	.size	_Z14absolute_valuei, .-_Z14absolute_valuei
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
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	and	esp, -16
	sub	esp, 32
	mov	DWORD PTR [esp+24], 0
	mov	DWORD PTR [esp], OFFSET FLAT:.LC0
	call	puts
	lea	eax, [esp+24]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:.LC1
	call	scanf
	mov	eax, DWORD PTR [esp+24]
	mov	DWORD PTR [esp], eax
	call	_Z14absolute_valuei
	mov	DWORD PTR [esp+28], eax
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:.LC2
	call	printf
	mov	eax, 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
