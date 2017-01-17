	.text
	.intel_syntax noprefix
	.file	"test_string_compare.cpp"
	.globl	compare_string
	.align	16, 0x90
	.type	compare_string,@function
compare_string:                         # @compare_string
	.cfi_startproc
# BB#0:
	mov	al, byte ptr [rdi]
	test	al, al
	je	.LBB0_4
# BB#1:                                 # %.lr.ph.preheader
	inc	rdi
	.align	16, 0x90
.LBB0_2:                                # %.lr.ph
                                        # =>This Inner Loop Header: Depth=1
	movzx	ecx, byte ptr [rsi]
	movzx	edx, al
	cmp	edx, ecx
	jne	.LBB0_5
# BB#3:                                 #   in Loop: Header=BB0_2 Depth=1
	inc	rsi
	mov	al, byte ptr [rdi]
	inc	rdi
	test	al, al
	jne	.LBB0_2
.LBB0_4:
	xor	eax, eax
.LBB0_5:                                # %.critedge
	movzx	ecx, byte ptr [rsi]
	movzx	eax, al
	cmp	eax, ecx
	sete	al
	ret
.Lfunc_end0:
	.size	compare_string, .Lfunc_end0-compare_string
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception0
# BB#0:
	push	rbp
.Ltmp43:
	.cfi_def_cfa_offset 16
	push	r15
.Ltmp44:
	.cfi_def_cfa_offset 24
	push	r14
.Ltmp45:
	.cfi_def_cfa_offset 32
	push	r12
.Ltmp46:
	.cfi_def_cfa_offset 40
	push	rbx
.Ltmp47:
	.cfi_def_cfa_offset 48
	sub	rsp, 64
.Ltmp48:
	.cfi_def_cfa_offset 112
.Ltmp49:
	.cfi_offset rbx, -48
.Ltmp50:
	.cfi_offset r12, -40
.Ltmp51:
	.cfi_offset r14, -32
.Ltmp52:
	.cfi_offset r15, -24
.Ltmp53:
	.cfi_offset rbp, -16
	lea	r15, [rsp + 48]
	mov	qword ptr [rsp + 32], r15
	mov	qword ptr [rsp + 40], 0
	mov	byte ptr [rsp + 48], 0
	lea	r12, [rsp + 16]
	mov	qword ptr [rsp], r12
	mov	qword ptr [rsp + 8], 0
	mov	byte ptr [rsp + 16], 0
.Ltmp0:
	mov	edi, _ZSt4cout
	mov	esi, .L.str
	mov	edx, 16
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp1:
# BB#1:                                 # %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit
	mov	rax, qword ptr [rip + _ZSt4cout]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [rax + _ZSt4cout+240]
	test	rbx, rbx
	je	.LBB1_2
.LBB1_3:                                # %.noexc34
	cmp	byte ptr [rbx + 56], 0
	je	.LBB1_5
# BB#4:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB1_7
.LBB1_5:
.Ltmp2:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
.Ltmp3:
# BB#6:                                 # %.noexc38
	mov	rax, qword ptr [rbx]
	mov	rax, qword ptr [rax + 48]
.Ltmp4:
	mov	esi, 10
	mov	rdi, rbx
	call	rax
.Ltmp5:
.LBB1_7:                                # %.noexc
.Ltmp6:
	movsx	esi, al
	mov	edi, _ZSt4cout
	call	_ZNSo3putEc
.Ltmp7:
# BB#8:                                 # %.noexc4
.Ltmp8:
	mov	rdi, rax
	call	_ZNSo5flushEv
.Ltmp9:
# BB#9:                                 # %_ZNSolsEPFRSoS_E.exit
.Ltmp10:
	lea	rsi, [rsp + 32]
	mov	edi, _ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp11:
# BB#10:
.Ltmp12:
	mov	edi, _ZSt4cout
	mov	esi, .L.str.1
	mov	edx, 16
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp13:
# BB#11:                                # %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit8
	mov	rax, qword ptr [rip + _ZSt4cout]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [rax + _ZSt4cout+240]
	test	rbx, rbx
	je	.LBB1_12
.LBB1_13:                               # %.noexc17
	cmp	byte ptr [rbx + 56], 0
	je	.LBB1_15
# BB#14:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB1_17
.LBB1_15:
.Ltmp14:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
.Ltmp15:
# BB#16:                                # %.noexc19
	mov	rax, qword ptr [rbx]
	mov	rax, qword ptr [rax + 48]
.Ltmp16:
	mov	esi, 10
	mov	rdi, rbx
	call	rax
.Ltmp17:
.LBB1_17:                               # %.noexc11
.Ltmp18:
	movsx	esi, al
	mov	edi, _ZSt4cout
	call	_ZNSo3putEc
.Ltmp19:
# BB#18:                                # %.noexc12
.Ltmp20:
	mov	rdi, rax
	call	_ZNSo5flushEv
.Ltmp21:
# BB#19:                                # %_ZNSolsEPFRSoS_E.exit10
.Ltmp22:
	lea	rsi, [rsp]
	mov	edi, _ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp23:
# BB#20:
	mov	rcx, qword ptr [rsp + 32]
	mov	rax, qword ptr [rsp]
	mov	bl, byte ptr [rcx]
	test	bl, bl
	je	.LBB1_24
# BB#21:                                # %.lr.ph.i.preheader
	inc	rcx
	.align	16, 0x90
.LBB1_22:                               # %.lr.ph.i
                                        # =>This Inner Loop Header: Depth=1
	movzx	edx, byte ptr [rax]
	movzx	esi, bl
	cmp	esi, edx
	jne	.LBB1_25
# BB#23:                                #   in Loop: Header=BB1_22 Depth=1
	inc	rax
	mov	bl, byte ptr [rcx]
	inc	rcx
	test	bl, bl
	jne	.LBB1_22
.LBB1_24:
	xor	ebx, ebx
.LBB1_25:                               # %compare_string.exit
	mov	bpl, byte ptr [rax]
.Ltmp24:
	mov	edi, _ZSt4cout
	mov	esi, .L.str.2
	mov	edx, 15
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp25:
# BB#26:                                # %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit22
	movzx	eax, bpl
	movzx	ecx, bl
	cmp	ecx, eax
	sete	al
	movzx	esi, al
.Ltmp26:
	mov	edi, _ZSt4cout
	call	_ZNSo9_M_insertIbEERSoT_
	mov	r14, rax
.Ltmp27:
# BB#27:                                # %_ZNSolsEb.exit
	mov	rax, qword ptr [r14]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [r14 + rax + 240]
	test	rbx, rbx
	je	.LBB1_28
.LBB1_29:                               # %.noexc42
	cmp	byte ptr [rbx + 56], 0
	je	.LBB1_31
# BB#30:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB1_33
.LBB1_31:
.Ltmp28:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
.Ltmp29:
# BB#32:                                # %.noexc46
	mov	rax, qword ptr [rbx]
	mov	rax, qword ptr [rax + 48]
.Ltmp30:
	mov	esi, 10
	mov	rdi, rbx
	call	rax
.Ltmp31:
.LBB1_33:                               # %.noexc26
.Ltmp32:
	movsx	esi, al
	mov	rdi, r14
	call	_ZNSo3putEc
.Ltmp33:
# BB#34:                                # %.noexc27
.Ltmp34:
	mov	rdi, rax
	call	_ZNSo5flushEv
.Ltmp35:
# BB#35:                                # %_ZNSolsEPFRSoS_E.exit25
	mov	rdi, qword ptr [rsp]
	cmp	rdi, r12
	je	.LBB1_37
# BB#36:
	call	_ZdlPv
.LBB1_37:                               # %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit32
	mov	rdi, qword ptr [rsp + 32]
	cmp	rdi, r15
	je	.LBB1_39
# BB#38:
	call	_ZdlPv
.LBB1_39:                               # %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit3
	xor	eax, eax
	add	rsp, 64
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	pop	rbp
	ret
.LBB1_2:
.Ltmp40:
	call	_ZSt16__throw_bad_castv
.Ltmp41:
	jmp	.LBB1_3
.LBB1_12:
.Ltmp38:
	call	_ZSt16__throw_bad_castv
.Ltmp39:
	jmp	.LBB1_13
.LBB1_28:
.Ltmp36:
	call	_ZSt16__throw_bad_castv
.Ltmp37:
	jmp	.LBB1_29
.LBB1_40:
.Ltmp42:
	mov	rbx, rax
	mov	rdi, qword ptr [rsp]
	cmp	rdi, r12
	je	.LBB1_42
# BB#41:
	call	_ZdlPv
.LBB1_42:                               # %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit33
	mov	rdi, qword ptr [rsp + 32]
	cmp	rdi, r15
	je	.LBB1_44
# BB#43:
	call	_ZdlPv
.LBB1_44:                               # %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit
	mov	rdi, rbx
	call	_Unwind_Resume
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table1:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\234"                  # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	26                      # Call site table length
	.long	.Ltmp0-.Lfunc_begin0    # >> Call Site 1 <<
	.long	.Ltmp37-.Ltmp0          #   Call between .Ltmp0 and .Ltmp37
	.long	.Ltmp42-.Lfunc_begin0   #     jumps to .Ltmp42
	.byte	0                       #   On action: cleanup
	.long	.Ltmp37-.Lfunc_begin0   # >> Call Site 2 <<
	.long	.Lfunc_end1-.Ltmp37     #   Call between .Ltmp37 and .Lfunc_end1
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.align	4

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_test_string_compare.cpp,@function
_GLOBAL__sub_I_test_string_compare.cpp: # @_GLOBAL__sub_I_test_string_compare.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp54:
	.cfi_def_cfa_offset 16
	mov	edi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edi, _ZNSt8ios_base4InitD1Ev
	mov	esi, _ZStL8__ioinit
	mov	edx, __dso_handle
	pop	rax
	jmp	__cxa_atexit            # TAILCALL
.Lfunc_end2:
	.size	_GLOBAL__sub_I_test_string_compare.cpp, .Lfunc_end2-_GLOBAL__sub_I_test_string_compare.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter string 1: "
	.size	.L.str, 17

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Enter string 2: "
	.size	.L.str.1, 17

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"The result is: "
	.size	.L.str.2, 16

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_test_string_compare.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
