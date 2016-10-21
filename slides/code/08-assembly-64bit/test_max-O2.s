	.text
	.intel_syntax noprefix
	.file	"test_max.cpp"
	.globl	max
	.align	16, 0x90
	.type	max,@function
max:                                    # @max
	.cfi_startproc
# BB#0:
	cmp	edi, esi
	cmovge	esi, edi
	mov	eax, esi
	ret
.Lfunc_end0:
	.size	max, .Lfunc_end0-max
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	r14
.Ltmp0:
	.cfi_def_cfa_offset 16
	push	rbx
.Ltmp1:
	.cfi_def_cfa_offset 24
	push	rax
.Ltmp2:
	.cfi_def_cfa_offset 32
.Ltmp3:
	.cfi_offset rbx, -24
.Ltmp4:
	.cfi_offset r14, -16
	mov	dword ptr [rsp + 4], 0
	mov	dword ptr [rsp], 0
	mov	edi, _ZSt4cout
	mov	esi, .L.str
	mov	edx, 15
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	mov	rax, qword ptr [rip + _ZSt4cout]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [rax + _ZSt4cout+240]
	test	rbx, rbx
	je	.LBB1_13
# BB#1:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
	cmp	byte ptr [rbx + 56], 0
	je	.LBB1_3
# BB#2:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB1_4
.LBB1_3:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	rax, qword ptr [rbx]
	mov	esi, 10
	mov	rdi, rbx
	call	qword ptr [rax + 48]
.LBB1_4:                                # %_ZNKSt5ctypeIcE5widenEc.exit
	movsx	esi, al
	mov	edi, _ZSt4cout
	call	_ZNSo3putEc
	mov	rdi, rax
	call	_ZNSo5flushEv
	lea	rsi, [rsp + 4]
	mov	edi, _ZSt3cin
	call	_ZNSirsERi
	mov	edi, _ZSt4cout
	mov	esi, .L.str.1
	mov	edx, 15
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	mov	rax, qword ptr [rip + _ZSt4cout]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [rax + _ZSt4cout+240]
	test	rbx, rbx
	je	.LBB1_13
# BB#5:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit5
	cmp	byte ptr [rbx + 56], 0
	je	.LBB1_7
# BB#6:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB1_8
.LBB1_7:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	rax, qword ptr [rbx]
	mov	esi, 10
	mov	rdi, rbx
	call	qword ptr [rax + 48]
.LBB1_8:                                # %_ZNKSt5ctypeIcE5widenEc.exit2
	movsx	esi, al
	mov	edi, _ZSt4cout
	call	_ZNSo3putEc
	mov	rdi, rax
	call	_ZNSo5flushEv
	lea	rsi, [rsp]
	mov	edi, _ZSt3cin
	call	_ZNSirsERi
	mov	eax, dword ptr [rsp + 4]
	mov	ebx, dword ptr [rsp]
	cmp	eax, ebx
	cmovge	ebx, eax
	mov	edi, _ZSt4cout
	mov	esi, .L.str.2
	mov	edx, 15
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	mov	edi, _ZSt4cout
	mov	esi, ebx
	call	_ZNSolsEi
	mov	r14, rax
	mov	rax, qword ptr [r14]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [r14 + rax + 240]
	test	rbx, rbx
	je	.LBB1_13
# BB#9:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit6
	cmp	byte ptr [rbx + 56], 0
	je	.LBB1_11
# BB#10:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB1_12
.LBB1_11:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	rax, qword ptr [rbx]
	mov	esi, 10
	mov	rdi, rbx
	call	qword ptr [rax + 48]
.LBB1_12:                               # %_ZNKSt5ctypeIcE5widenEc.exit4
	movsx	esi, al
	mov	rdi, r14
	call	_ZNSo3putEc
	mov	rdi, rax
	call	_ZNSo5flushEv
	xor	eax, eax
	add	rsp, 8
	pop	rbx
	pop	r14
	ret
.LBB1_13:
	call	_ZSt16__throw_bad_castv
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_test_max.cpp,@function
_GLOBAL__sub_I_test_max.cpp:            # @_GLOBAL__sub_I_test_max.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp5:
	.cfi_def_cfa_offset 16
	mov	edi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edi, _ZNSt8ios_base4InitD1Ev
	mov	esi, _ZStL8__ioinit
	mov	edx, __dso_handle
	pop	rax
	jmp	__cxa_atexit            # TAILCALL
.Lfunc_end2:
	.size	_GLOBAL__sub_I_test_max.cpp, .Lfunc_end2-_GLOBAL__sub_I_test_max.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter value 1: "
	.size	.L.str, 16

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Enter value 2: "
	.size	.L.str.1, 16

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"The result is: "
	.size	.L.str.2, 16

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_test_max.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
