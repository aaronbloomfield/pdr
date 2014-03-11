.file	"test_string_compare.cpp"
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
.globl _compare_string
.def	_compare_string;
.scl	2;
.type	32;
.endef
_compare_string:
push	ebp
mov	ebp, esp
L11:
mov	eax, DWORD PTR [ebp+8]
cmp	BYTE PTR [eax], 0
je	L12
mov	eax, DWORD PTR [ebp+8]
mov	edx, DWORD PTR [ebp+12]
movzx	eax, BYTE PTR [eax]
cmp	al, BYTE PTR [edx]
jne	L12
inc	DWORD PTR [ebp+8]
lea	eax, [ebp+12]
inc	DWORD PTR [eax]
jmp	L11
L12:
mov	eax, DWORD PTR [ebp+8]
mov	edx, DWORD PTR [ebp+12]
movzx	eax, BYTE PTR [eax]
cmp	al, BYTE PTR [edx]
sete	al
movzx	eax, al
pop	ebp
ret
.def	___main;
.scl	2;
.type	32;
.endef
.def	__Unwind_SjLj_Resume;
.scl	2;
.type	32;
.endef
.def	___gxx_personality_sj0;
.scl	2;
.type	32;
.endef
.def	__Unwind_SjLj_Register;
.scl	2;
.type	32;
.endef
.def	__Unwind_SjLj_Unregister;
.scl	2;
.type	32;
.endef
.section .rdata,"dr"
LC0:
.ascii "Enter string 1: \0"
LC1:
.ascii "Enter string 2: \0"
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
push	edi
push	esi
push	ebx
sub	esp, 156
and	esp, -16
mov	eax, 0
add	eax, 15
add	eax, 15
shr	eax, 4
sal	eax, 4
mov	DWORD PTR [ebp-140], eax
mov	eax, DWORD PTR [ebp-140]
call	__alloca
mov	DWORD PTR [ebp-88], OFFSET FLAT:
___gxx_personality_sj0
mov	DWORD PTR [ebp-84], OFFSET FLAT:
LLSDA1381
lea	eax, [ebp-80]
lea	edx, [ebp-24]
mov	DWORD PTR [eax], edx
mov	edx, OFFSET FLAT:
L22
mov	DWORD PTR [eax+4], edx
mov	DWORD PTR [eax+8], esp
lea	eax, [ebp-112]
mov	DWORD PTR [esp], eax
call	__Unwind_SjLj_Register
call	___main
lea	eax, [ebp-40]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], -1
call	__ZNSsC1Ev
lea	eax, [ebp-56]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], 2
call	__ZNSsC1Ev
mov	DWORD PTR [esp+4], OFFSET FLAT:
LC0
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
mov	DWORD PTR [ebp-108], 1
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	DWORD PTR [esp+4], OFFSET FLAT:
__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], eax
call	__ZNSolsEPFRSoS_E
lea	eax, [ebp-40]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt3cin
call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
mov	DWORD PTR [esp+4], OFFSET FLAT:
LC1
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	DWORD PTR [esp+4], OFFSET FLAT:
__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], eax
call	__ZNSolsEPFRSoS_E
lea	eax, [ebp-56]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt3cin
call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
lea	eax, [ebp-56]
mov	DWORD PTR [esp], eax
call	__ZNKSs5c_strEv
mov	DWORD PTR [ebp-120], eax
lea	eax, [ebp-40]
mov	DWORD PTR [esp], eax
call	__ZNKSs5c_strEv
mov	edx, DWORD PTR [ebp-120]
mov	DWORD PTR [esp+4], edx
mov	DWORD PTR [esp], eax
call	_compare_string
mov	BYTE PTR [ebp-57], al
mov	DWORD PTR [esp+4], OFFSET FLAT:
LC2
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt4cout
call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
mov	edx, eax
movzx	eax, BYTE PTR [ebp-57]
mov	DWORD PTR [esp+4], eax
mov	DWORD PTR [esp], edx
call	__ZNSolsEb
mov	DWORD PTR [esp+4], OFFSET FLAT:
__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
mov	DWORD PTR [esp], eax
call	__ZNSolsEPFRSoS_E
lea	eax, [ebp-56]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], 2
call	__ZNSsD1Ev
lea	eax, [ebp-40]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], -1
call	__ZNSsD1Ev
mov	DWORD PTR [ebp-116], 0
jmp	L13
L22:
lea	ebp, [ebp+24]
mov	eax, DWORD PTR [ebp-108]
mov	edx, DWORD PTR [ebp-104]
mov	DWORD PTR [ebp-128], edx
cmp	eax, 1
je	L18
L14:
mov	eax, DWORD PTR [ebp-128]
mov	DWORD PTR [ebp-124], eax
lea	eax, [ebp-56]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], 0
call	__ZNSsD1Ev
mov	edx, DWORD PTR [ebp-124]
mov	DWORD PTR [ebp-128], edx
L16:
L18:
mov	eax, DWORD PTR [ebp-128]
mov	DWORD PTR [ebp-132], eax
lea	eax, [ebp-40]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], 0
call	__ZNSsD1Ev
mov	edx, DWORD PTR [ebp-132]
mov	DWORD PTR [ebp-128], edx
L20:
mov	eax, DWORD PTR [ebp-128]
mov	DWORD PTR [esp], eax
mov	DWORD PTR [ebp-108], -1
call	__Unwind_SjLj_Resume
L13:
lea	eax, [ebp-112]
mov	DWORD PTR [esp], eax
call	__Unwind_SjLj_Unregister
mov	eax, DWORD PTR [ebp-116]
lea	esp, [ebp-12]
pop	ebx
pop	esi
pop	edi
pop	ebp
ret
.section	.gcc_except_table,"dr"
LLSDA1381:
.byte	0xff
.byte	0xff
.byte	0x1
.uleb128 LLSDACSE1381-LLSDACSB1381
LLSDACSB1381:
.uleb128 0x0
.uleb128 0x0
.uleb128 0x1
.uleb128 0x0
LLSDACSE1381:
.text
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
jae	L24
mov	eax, DWORD PTR [ebp+12]
mov	DWORD PTR [ebp-4], eax
jmp	L23
L24:
mov	eax, DWORD PTR [ebp+8]
mov	DWORD PTR [ebp-4], eax
L23:
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
jne	L26
cmp	DWORD PTR [ebp+8], 1
jne	L26
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt8__ioinit
call	__ZNSt8ios_base4InitC1Ev
L26:
cmp	DWORD PTR [ebp+12], 65535
jne	L25
cmp	DWORD PTR [ebp+8], 0
jne	L25
mov	DWORD PTR [esp], OFFSET FLAT:
__ZSt8__ioinit
call	__ZNSt8ios_base4InitD1Ev
L25:
leave
ret
.align 2
.def	__GLOBAL__I_compare_string;
.scl	3;
.type	32;
.endef
__GLOBAL__I_compare_string:
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
.long	__GLOBAL__I_compare_string
.text
.align 2
.def	__GLOBAL__D_compare_string;
.scl	3;
.type	32;
.endef
__GLOBAL__D_compare_string:
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
.long	__GLOBAL__D_compare_string
.def	__ZNSt8ios_base4InitD1Ev;
.scl	3;
.type	32;
.endef
.def	__ZNSolsEb;
.scl	3;
.type	32;
.endef
.def	__ZNKSs5c_strEv;
.scl	3;
.type	32;
.endef
.def	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;
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
.def	__ZNSsD1Ev;
.scl	3;
.type	32;
.endef
.def	__ZNSsC1Ev;
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
