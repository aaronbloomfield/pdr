	.file	"test_abs_c.c"
	.text
	.globl	absolute_value
	.align	16, 0x90
	.type	absolute_value,@function
absolute_value:                         # @absolute_value
# BB#0:
	push	EAX
	mov	EAX, DWORD PTR [ESP + 8]
	mov	DWORD PTR [ESP], EAX
	cmp	DWORD PTR [ESP], 0
	jge	.LBB0_2
# BB#1:
	mov	EAX, 0
	sub	EAX, DWORD PTR [ESP]
	mov	DWORD PTR [ESP], EAX
.LBB0_2:
	mov	EAX, DWORD PTR [ESP]
	pop	EDX
	ret
.Ltmp0:
	.size	absolute_value, .Ltmp0-absolute_value

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	push	EBP
	mov	EBP, ESP
	sub	ESP, 40
	lea	EAX, DWORD PTR [.L.str]
	mov	DWORD PTR [EBP - 4], 0
	mov	DWORD PTR [EBP - 8], 0
	mov	DWORD PTR [ESP], EAX
	call	printf
	lea	ECX, DWORD PTR [.L.str1]
	lea	EDX, DWORD PTR [EBP - 8]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EDX
	mov	DWORD PTR [EBP - 16], EAX # 4-byte Spill
	call	__isoc99_scanf
	mov	ECX, DWORD PTR [EBP - 8]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [EBP - 20], EAX # 4-byte Spill
	call	absolute_value
	lea	ECX, DWORD PTR [.L.str2]
	mov	DWORD PTR [EBP - 12], EAX
	mov	EAX, DWORD PTR [EBP - 12]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EAX
	call	printf
	mov	ECX, 0
	mov	DWORD PTR [EBP - 24], EAX # 4-byte Spill
	mov	EAX, ECX
	add	ESP, 40
	pop	EBP
	ret
.Ltmp1:
	.size	main, .Ltmp1-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Enter a value: \n"
	.size	.L.str, 17

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "%d"
	.size	.L.str1, 3

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "The result is: %d\n"
	.size	.L.str2, 19


	.section	".note.GNU-stack","",@progbits
