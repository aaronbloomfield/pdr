.file	"test_max.cpp"
.intel_syntax
.section	.ctors,"w"
.align 4
.long	__GLOBAL__I_max
.section	.dtors,"w"
.align 4
.long	__GLOBAL__D_max
.lcomm __ZSt8__ioinit,16
.text
.align 2
.p2align 4,,15
.globl _max
.def	_max;
.scl	2;
.type	32;
.endef
_max:
push	ebp
mov	ebp, esp
mov	eax, DWORD PTR [ebp+8]
mov	edx, DWORD PTR [ebp+12]
cmp	eax, edx
jg	L3
mov	eax, edx
L3:
pop	ebp
ret
.def	___main;
.scl	2;
.type	32;
.endef
.section .rdata,"dr"
LC0:
.ascii "Enter value 1: \0"
LC1:
.ascii "Enter value 2: \0"
LC2:
.ascii "The result is: \0"
.text
.align 2
.p2align 4,,15
.globl _main
.def	_main;
.scl	2;
.type	32;
.endef
_main:
push	ebp
mov	eax, 16
mov	ebp, esp
push	ebx
sub	esp, 20
and	esp, -16
call	__alloca
call	___main
mov	DWORD PTR [ebp-8], 0
mov	ecx, OFFSET FLAT:
LC0
mov	DWORD PTR [ebp-12], 0
mov	DWORD PTR [esp+4], ecx
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	DWORD PTR [esp], eax
call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt3cin
lea	eax, [ebp-8]
mov	DWORD PTR [esp+4], eax
call	__ZNSirsERi
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
mov	edx, OFFSET FLAT:
LC1
mov	DWORD PTR [esp+4], edx
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	DWORD PTR [esp], eax
call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt3cin
lea	eax, [ebp-12]
mov	DWORD PTR [esp+4], eax
call	__ZNSirsERi
mov	eax, DWORD PTR [ebp-12]
mov	DWORD PTR [esp+4], eax
mov	eax, DWORD PTR [ebp-8]
mov	DWORD PTR [esp], eax
call	_max
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
mov	ebx, eax
mov	eax, OFFSET FLAT:
LC2
mov	DWORD PTR [esp+4], eax
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	edx, eax
mov	eax, DWORD PTR [eax]
mov	ecx, DWORD PTR [eax-12]
lea	eax, [edx+ecx]
mov	eax, DWORD PTR [eax+12]
test	al, 64
jne	L11
test	al, 8
je	L10
L11:
mov	DWORD PTR [esp+4], ebx
mov	DWORD PTR [esp], edx
call	__ZNSolsEm
mov	DWORD PTR [esp], eax
call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	ebx, DWORD PTR [ebp-4]
xor	eax, eax
leave
ret
.p2align 4,,7
L10:
mov	DWORD PTR [esp+4], ebx
mov	DWORD PTR [esp], edx
call	__ZNSolsEl
mov	DWORD PTR [esp], eax
call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	ebx, DWORD PTR [ebp-4]
xor	eax, eax
leave
ret
.align 2
.p2align 4,,15
.def	__Z41__static_initialization_and_destruction_0ii;
.scl	3;
.type	32;
.endef
__Z41__static_initialization_and_destruction_0ii:
push	ebp
mov	ebp, esp
sub	esp, 24
mov	DWORD PTR [ebp-8], ebx
cmp	edx, 65535
sete	bl
mov	DWORD PTR [ebp-4], esi
cmp	eax, 1
mov	esi, eax
sete	al
test	bl, al
jne	L20
test	esi, esi
sete	al
test	bl, al
jne	L21
L17:
mov	ebx, DWORD PTR [ebp-8]
mov	esi, DWORD PTR [ebp-4]
mov	esp, ebp
pop	ebp
ret
.p2align 4,,7
L20:
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt8__ioinit
call	__ZNSt8ios_base4InitC1Ev
test	esi, esi
sete	al
test	bl, al
je	L17
.p2align 4,,15
L21:
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt8__ioinit
call	__ZNSt8ios_base4InitD1Ev
mov	ebx, DWORD PTR [ebp-8]
mov	esi, DWORD PTR [ebp-4]
mov	esp, ebp
pop	ebp
ret
.align 2
.p2align 4,,15
.def	__GLOBAL__I_max;
.scl	3;
.type	32;
.endef
__GLOBAL__I_max:
push	ebp
mov	edx, 65535
mov	ebp, esp
pop	ebp
mov	eax, 1
jmp	__Z41__static_initialization_and_destruction_0ii
.align 2
.p2align 4,,15
.def	__GLOBAL__D_max;
.scl	3;
.type	32;
.endef
__GLOBAL__D_max:
push	ebp
mov	edx, 65535
mov	ebp, esp
pop	ebp
xor	eax, eax
jmp	__Z41__static_initialization_and_destruction_0ii
.def	__ZNSt8ios_base4InitD1Ev;
.scl	3;
.type	32;
.endef
.def	__ZNSolsEl;
.scl	3;
.type	32;
.endef
.def	__ZNSolsEm;
.scl	3;
.type	32;
.endef
.def	__ZNSirsERi;
.scl	3;
.type	32;
.endef
.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;
.scl	3;
.type	32;
.endef
.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;
.scl	3;
.type	32;
.endef
.def	__ZNSt8ios_base4InitC1Ev;
.scl	3;
.type	32;
.endef
