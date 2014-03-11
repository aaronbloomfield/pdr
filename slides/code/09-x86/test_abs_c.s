.file	"test_abs_c.c"
.intel_syntax
.text
.align 2
.globl __Z14absolute_valuei
.def	__Z14absolute_valuei;
.scl	2;
.type	32;
.endef
__Z14absolute_valuei:
push	ebp
mov	ebp, esp
cmp	DWORD PTR [ebp+8], 0
jns	L2
neg	DWORD PTR [ebp+8]
L2:
mov	eax, DWORD PTR [ebp+8]
pop	ebp
ret
.def	___main;
.scl	2;
.type	32;
.endef
.section .rdata,"dr"
LC0:
.ascii "Enter a value: \12\0"
LC1:
.ascii "%d\0"
LC2:
.ascii "The result is: %d\12\0"
.text
.align 2
.globl _main
.def	_main;
.scl	2;
.type	32;
.endef
_main:
push	ebp
mov	ebp, esp
sub	esp, 24
and	esp, -16
mov	eax, 0
add	eax, 15
add	eax, 15
shr	eax, 4
sal	eax, 4
mov	DWORD PTR [ebp-12], eax
mov	eax, DWORD PTR [ebp-12]
call	__alloca
call	___main
mov	DWORD PTR [ebp-4], 0
mov	DWORD PTR [esp], OFFSET FLAT:
LC0
call	_printf
lea	eax, [ebp-4]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], OFFSET FLAT:
LC1
call	_scanf
mov	eax, DWORD PTR [ebp-4]
mov	DWORD PTR [esp], eax
call	__Z14absolute_valuei
mov	DWORD PTR [ebp-8], eax
mov	eax, DWORD PTR [ebp-8]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], OFFSET FLAT:
LC2
call	_printf
mov	eax, 0
leave
ret
.def	_scanf;
.scl	2;
.type	32;
.endef
.def	_printf;
.scl	2;
.type	32;
.endef
