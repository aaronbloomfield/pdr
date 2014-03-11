.file	"test_max.cpp"
.intel_syntax
.text
.align 2
.def	__ZSt17__verify_groupingPKcjRKSs;
.scl	3;
.type	32;
.endef
__ZSt17__verify_groupingPKcjRKSs:
push	ebp
mov	ebp, esp
sub	esp, 40
mov	eax, DWORD PTR [ebp+16]
mov	DWORD PTR [esp], eax
call	__ZNKSs4sizeEv
dec	eax
mov	DWORD PTR [ebp-4], eax
mov	eax, DWORD PTR [ebp+12]
dec	eax
mov	DWORD PTR [ebp-12], eax
lea	eax, [ebp-12]
mov	DWORD PTR [esp+4], eax
lea	eax, [ebp-4]
mov	DWORD PTR [esp], eax
call	__ZSt3minIjERKT_S2_S2_
mov	eax, DWORD PTR [eax]
mov	DWORD PTR [ebp-8], eax
mov	eax, DWORD PTR [ebp-4]
mov	DWORD PTR [ebp-16], eax
mov	BYTE PTR [ebp-17], 1
mov	DWORD PTR [ebp-24], 0
L2:
mov	eax, DWORD PTR [ebp-24]
cmp	eax, DWORD PTR [ebp-8]
jae	L5
cmp	BYTE PTR [ebp-17], 0
je	L5
mov	eax, DWORD PTR [ebp-16]
mov	DWORD PTR [esp+4], eax
mov	eax, DWORD PTR [ebp+16]
mov	DWORD PTR [esp], eax
call	__ZNKSsixEj
mov	ecx, eax
mov	eax, DWORD PTR [ebp-24]
mov	edx, DWORD PTR [ebp+8]
add	edx, eax
movzx	eax, BYTE PTR [ecx]
cmp	al, BYTE PTR [edx]
sete	al
mov	BYTE PTR [ebp-17], al
lea	eax, [ebp-16]
dec	DWORD PTR [eax]
lea	eax, [ebp-24]
inc	DWORD PTR [eax]
jmp	L2
L5:
cmp	DWORD PTR [ebp-16], 0
je	L6
cmp	BYTE PTR [ebp-17], 0
je	L6
mov	eax, DWORD PTR [ebp-16]
mov	DWORD PTR [esp+4], eax
mov	eax, DWORD PTR [ebp+16]
mov	DWORD PTR [esp], eax
call	__ZNKSsixEj
mov	ecx, eax
mov	eax, DWORD PTR [ebp-8]
mov	edx, DWORD PTR [ebp+8]
add	edx, eax
movzx	eax, BYTE PTR [ecx]
cmp	al, BYTE PTR [edx]
sete	al
mov	BYTE PTR [ebp-17], al
lea	eax, [ebp-16]
dec	DWORD PTR [eax]
jmp	L5
L6:
mov	DWORD PTR [esp+4], 0
mov	eax, DWORD PTR [ebp+16]
mov	DWORD PTR [esp], eax
call	__ZNKSsixEj
mov	ecx, eax
mov	eax, DWORD PTR [ebp-8]
mov	edx, DWORD PTR [ebp+8]
add	edx, eax
movzx	eax, BYTE PTR [ecx]
cmp	al, BYTE PTR [edx]
jg	L8
movzx	eax, BYTE PTR [ebp-17]
and	eax, 1
mov	BYTE PTR [ebp-25], al
jmp	L9
L8:
mov	BYTE PTR [ebp-25], 0
L9:
movzx	eax, BYTE PTR [ebp-25]
mov	BYTE PTR [ebp-17], al
movzx	eax, BYTE PTR [ebp-17]
leave
ret
.lcomm __ZSt8__ioinit,16
.align 2
.globl _max
.def	_max;
.scl	2;
.type	32;
.endef
_max:
push	ebp
mov	ebp, esp
sub	esp, 4
mov	eax, DWORD PTR [ebp+8]
cmp	eax, DWORD PTR [ebp+12]
jle	L11
mov	eax, DWORD PTR [ebp+8]
mov	DWORD PTR [ebp-4], eax
jmp	L12
L11:
mov	eax, DWORD PTR [ebp+12]
mov	DWORD PTR [ebp-4], eax
L12:
mov	eax, DWORD PTR [ebp-4]
leave
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
mov	DWORD PTR [ebp-16], eax
mov	eax, DWORD PTR [ebp-16]
call	__alloca
call	___main
mov	DWORD PTR [ebp-4], 0
mov	DWORD PTR [ebp-8], 0
mov	DWORD PTR [esp+4], OFFSET FLAT:
LC0
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	DWORD PTR [esp+4], OFFSET FLAT:
__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], eax
call	__ZNSolsEPFRSoS_E
lea	eax, [ebp-4]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt3cin
call	__ZNSirsERi
mov	DWORD PTR [esp+4], OFFSET FLAT:
LC1
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	DWORD PTR [esp+4], OFFSET FLAT:
__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], eax
call	__ZNSolsEPFRSoS_E
lea	eax, [ebp-8]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt3cin
call	__ZNSirsERi
mov	eax, DWORD PTR [ebp-8]
mov	DWORD PTR [esp+4], eax
mov	eax, DWORD PTR [ebp-4]
mov	DWORD PTR [esp], eax
call	_max
mov	DWORD PTR [ebp-12], eax
mov	DWORD PTR [esp+4], OFFSET FLAT:
LC2
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	edx, eax
mov	eax, DWORD PTR [ebp-12]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], edx
call	__ZNSolsEi
mov	DWORD PTR [esp+4], OFFSET FLAT:
__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], eax
call	__ZNSolsEPFRSoS_E
mov	eax, 0
leave
ret
.section	.text$_ZSt3minIjERKT_S2_S2_,"x"
.linkonce discard
.align 2
.globl __ZSt3minIjERKT_S2_S2_
.def	__ZSt3minIjERKT_S2_S2_;
.scl	2;
.type	32;
.endef
__ZSt3minIjERKT_S2_S2_:
push	ebp
mov	ebp, esp
sub	esp, 4
mov	eax, DWORD PTR [ebp+12]
mov	edx, DWORD PTR [ebp+8]
mov	eax, DWORD PTR [eax]
cmp	eax, DWORD PTR [edx]
jae	L15
mov	eax, DWORD PTR [ebp+12]
mov	DWORD PTR [ebp-4], eax
jmp	L14
L15:
mov	eax, DWORD PTR [ebp+8]
mov	DWORD PTR [ebp-4], eax
L14:
mov	eax, DWORD PTR [ebp-4]
leave
ret
.text
.align 2
.def	__Z41__static_initialization_and_destruction_0ii;
.scl	3;
.type	32;
.endef
__Z41__static_initialization_and_destruction_0ii:
push	ebp
mov	ebp, esp
sub	esp, 8
cmp	DWORD PTR [ebp+12], 65535
jne	L17
cmp	DWORD PTR [ebp+8], 1
jne	L17
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt8__ioinit
call	__ZNSt8ios_base4InitC1Ev
L17:
cmp	DWORD PTR [ebp+12], 65535
jne	L16
cmp	DWORD PTR [ebp+8], 0
jne	L16
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt8__ioinit
call	__ZNSt8ios_base4InitD1Ev
L16:
leave
ret
.align 2
.def	__GLOBAL__I_max;
.scl	3;
.type	32;
.endef
__GLOBAL__I_max:
push	ebp
mov	ebp, esp
sub	esp, 8
mov	DWORD PTR [esp+4], 65535
mov	DWORD PTR [esp], 1
call	__Z41__static_initialization_and_destruction_0ii
leave
ret
.section	.ctors,"w"
.align 4
.long	__GLOBAL__I_max
.text
.align 2
.def	__GLOBAL__D_max;
.scl	3;
.type	32;
.endef
__GLOBAL__D_max:
push	ebp
mov	ebp, esp
sub	esp, 8
mov	DWORD PTR [esp+4], 65535
mov	DWORD PTR [esp], 0
call	__Z41__static_initialization_and_destruction_0ii
leave
ret
.section	.dtors,"w"
.align 4
.long	__GLOBAL__D_max
.def	__ZNSt8ios_base4InitD1Ev;
.scl	3;
.type	32;
.endef
.def	__ZNSolsEi;
.scl	3;
.type	32;
.endef
.def	__ZNSirsERi;
.scl	3;
.type	32;
.endef
.def	__ZNSolsEPFRSoS_E;
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
.def	__ZNKSsixEj;
.scl	3;
.type	32;
.endef
.def	__ZNKSs4sizeEv;
.scl	3;
.type	32;
.endef
.def	__ZSt3minIjERKT_S2_S2_;
.scl	3;
.type	32;
.endef
