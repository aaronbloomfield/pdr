	.text
	.intel_syntax noprefix
	.file	"test_string_compare.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rbp - 4], eax # 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	compare_string
	.align	16, 0x90
	.type	compare_string,@function
compare_string:                         # @compare_string
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp5:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 8]
	movsx	eax, byte ptr [rdx]
	cmp	eax, 0
	mov	byte ptr [rbp - 17], cl # 1-byte Spill
	je	.LBB1_3
# BB#2:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	rax, qword ptr [rbp - 8]
	movsx	ecx, byte ptr [rax]
	mov	rax, qword ptr [rbp - 16]
	movsx	edx, byte ptr [rax]
	cmp	ecx, edx
	sete	sil
	mov	byte ptr [rbp - 17], sil # 1-byte Spill
.LBB1_3:                                #   in Loop: Header=BB1_1 Depth=1
	mov	al, byte ptr [rbp - 17] # 1-byte Reload
	test	al, 1
	jne	.LBB1_4
	jmp	.LBB1_5
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
	mov	rax, qword ptr [rbp - 8]
	add	rax, 1
	mov	qword ptr [rbp - 8], rax
	mov	rax, qword ptr [rbp - 16]
	add	rax, 1
	mov	qword ptr [rbp - 16], rax
	jmp	.LBB1_1
.LBB1_5:
	mov	rax, qword ptr [rbp - 8]
	movsx	ecx, byte ptr [rax]
	mov	rax, qword ptr [rbp - 16]
	movsx	edx, byte ptr [rax]
	cmp	ecx, edx
	sete	sil
	and	sil, 1
	movzx	eax, sil
	pop	rbp
	ret
.Lfunc_end1:
	.size	compare_string, .Lfunc_end1-compare_string
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
.Ltmp41:
	.cfi_def_cfa_offset 16
.Ltmp42:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp43:
	.cfi_def_cfa_register rbp
	sub	rsp, 192
	mov	dword ptr [rbp - 4], 0
	lea	rdi, [rbp - 40]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
.Ltmp6:
	lea	rdi, [rbp - 72]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
.Ltmp7:
	jmp	.LBB2_1
.LBB2_1:
.Ltmp8:
	mov	eax, _ZSt4cout
	mov	edi, eax
	mov	eax, .L.str
	mov	esi, eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp9:
	mov	qword ptr [rbp - 96], rax # 8-byte Spill
	jmp	.LBB2_2
.LBB2_2:
.Ltmp10:
	mov	eax, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	esi, eax
	mov	rdi, qword ptr [rbp - 96] # 8-byte Reload
	call	_ZNSolsEPFRSoS_E
.Ltmp11:
	mov	qword ptr [rbp - 104], rax # 8-byte Spill
	jmp	.LBB2_3
.LBB2_3:
.Ltmp12:
	mov	eax, _ZSt3cin
	mov	edi, eax
	lea	rsi, [rbp - 40]
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp13:
	mov	qword ptr [rbp - 112], rax # 8-byte Spill
	jmp	.LBB2_4
.LBB2_4:
.Ltmp14:
	mov	eax, _ZSt4cout
	mov	edi, eax
	mov	eax, .L.str.1
	mov	esi, eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp15:
	mov	qword ptr [rbp - 120], rax # 8-byte Spill
	jmp	.LBB2_5
.LBB2_5:
.Ltmp16:
	mov	eax, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	esi, eax
	mov	rdi, qword ptr [rbp - 120] # 8-byte Reload
	call	_ZNSolsEPFRSoS_E
.Ltmp17:
	mov	qword ptr [rbp - 128], rax # 8-byte Spill
	jmp	.LBB2_6
.LBB2_6:
.Ltmp18:
	mov	eax, _ZSt3cin
	mov	edi, eax
	lea	rsi, [rbp - 72]
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp19:
	mov	qword ptr [rbp - 136], rax # 8-byte Spill
	jmp	.LBB2_7
.LBB2_7:
.Ltmp20:
	lea	rdi, [rbp - 40]
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv
.Ltmp21:
	mov	qword ptr [rbp - 144], rax # 8-byte Spill
	jmp	.LBB2_8
.LBB2_8:
.Ltmp22:
	lea	rdi, [rbp - 72]
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv
.Ltmp23:
	mov	qword ptr [rbp - 152], rax # 8-byte Spill
	jmp	.LBB2_9
.LBB2_9:
.Ltmp24:
	mov	rdi, qword ptr [rbp - 144] # 8-byte Reload
	mov	rsi, qword ptr [rbp - 152] # 8-byte Reload
	call	compare_string
.Ltmp25:
	mov	byte ptr [rbp - 153], al # 1-byte Spill
	jmp	.LBB2_10
.LBB2_10:
	mov	al, byte ptr [rbp - 153] # 1-byte Reload
	and	al, 1
	mov	byte ptr [rbp - 85], al
.Ltmp26:
	mov	ecx, _ZSt4cout
	mov	edi, ecx
	mov	ecx, .L.str.2
	mov	esi, ecx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp27:
	mov	qword ptr [rbp - 168], rax # 8-byte Spill
	jmp	.LBB2_11
.LBB2_11:
	movzx	eax, byte ptr [rbp - 85]
.Ltmp28:
	and	eax, 1
	mov	rdi, qword ptr [rbp - 168] # 8-byte Reload
	mov	esi, eax
	call	_ZNSolsEb
.Ltmp29:
	mov	qword ptr [rbp - 176], rax # 8-byte Spill
	jmp	.LBB2_12
.LBB2_12:
.Ltmp30:
	mov	eax, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	esi, eax
	mov	rdi, qword ptr [rbp - 176] # 8-byte Reload
	call	_ZNSolsEPFRSoS_E
.Ltmp31:
	mov	qword ptr [rbp - 184], rax # 8-byte Spill
	jmp	.LBB2_13
.LBB2_13:
	mov	dword ptr [rbp - 4], 0
.Ltmp35:
	lea	rdi, [rbp - 72]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp36:
	jmp	.LBB2_16
.LBB2_14:
.Ltmp37:
	mov	ecx, edx
	mov	qword ptr [rbp - 80], rax
	mov	dword ptr [rbp - 84], ecx
	jmp	.LBB2_18
.LBB2_15:
.Ltmp32:
	mov	ecx, edx
	mov	qword ptr [rbp - 80], rax
	mov	dword ptr [rbp - 84], ecx
.Ltmp33:
	lea	rdi, [rbp - 72]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp34:
	jmp	.LBB2_17
.LBB2_16:
	lea	rdi, [rbp - 40]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	mov	eax, dword ptr [rbp - 4]
	add	rsp, 192
	pop	rbp
	ret
.LBB2_17:
	jmp	.LBB2_18
.LBB2_18:
.Ltmp38:
	lea	rdi, [rbp - 40]
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.Ltmp39:
	jmp	.LBB2_19
.LBB2_19:
	jmp	.LBB2_20
.LBB2_20:
	mov	rdi, qword ptr [rbp - 80]
	call	_Unwind_Resume
.LBB2_21:
.Ltmp40:
	mov	ecx, edx
	mov	rdi, rax
	mov	dword ptr [rbp - 188], ecx # 4-byte Spill
	call	__clang_call_terminate
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table2:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\360"                  # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	104                     # Call site table length
	.long	.Lfunc_begin0-.Lfunc_begin0 # >> Call Site 1 <<
	.long	.Ltmp6-.Lfunc_begin0    #   Call between .Lfunc_begin0 and .Ltmp6
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp6-.Lfunc_begin0    # >> Call Site 2 <<
	.long	.Ltmp7-.Ltmp6           #   Call between .Ltmp6 and .Ltmp7
	.long	.Ltmp37-.Lfunc_begin0   #     jumps to .Ltmp37
	.byte	0                       #   On action: cleanup
	.long	.Ltmp8-.Lfunc_begin0    # >> Call Site 3 <<
	.long	.Ltmp31-.Ltmp8          #   Call between .Ltmp8 and .Ltmp31
	.long	.Ltmp32-.Lfunc_begin0   #     jumps to .Ltmp32
	.byte	0                       #   On action: cleanup
	.long	.Ltmp35-.Lfunc_begin0   # >> Call Site 4 <<
	.long	.Ltmp36-.Ltmp35         #   Call between .Ltmp35 and .Ltmp36
	.long	.Ltmp37-.Lfunc_begin0   #     jumps to .Ltmp37
	.byte	0                       #   On action: cleanup
	.long	.Ltmp33-.Lfunc_begin0   # >> Call Site 5 <<
	.long	.Ltmp34-.Ltmp33         #   Call between .Ltmp33 and .Ltmp34
	.long	.Ltmp40-.Lfunc_begin0   #     jumps to .Ltmp40
	.byte	1                       #   On action: 1
	.long	.Ltmp34-.Lfunc_begin0   # >> Call Site 6 <<
	.long	.Ltmp38-.Ltmp34         #   Call between .Ltmp34 and .Ltmp38
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp38-.Lfunc_begin0   # >> Call Site 7 <<
	.long	.Ltmp39-.Ltmp38         #   Call between .Ltmp38 and .Ltmp39
	.long	.Ltmp40-.Lfunc_begin0   #     jumps to .Ltmp40
	.byte	1                       #   On action: 1
	.long	.Ltmp39-.Lfunc_begin0   # >> Call Site 8 <<
	.long	.Lfunc_end2-.Ltmp39     #   Call between .Ltmp39 and .Lfunc_end2
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.byte	1                       # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                       #   No further actions
                                        # >> Catch TypeInfos <<
	.long	0                       # TypeInfo 1
	.align	4

	.section	.text.__clang_call_terminate,"axG",@progbits,__clang_call_terminate,comdat
	.hidden	__clang_call_terminate
	.weak	__clang_call_terminate
	.align	16, 0x90
	.type	__clang_call_terminate,@function
__clang_call_terminate:                 # @__clang_call_terminate
# BB#0:
	push	rax
	call	__cxa_begin_catch
	mov	qword ptr [rsp], rax    # 8-byte Spill
	call	_ZSt9terminatev
.Lfunc_end3:
	.size	__clang_call_terminate, .Lfunc_end3-__clang_call_terminate

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_test_string_compare.cpp,@function
_GLOBAL__sub_I_test_string_compare.cpp: # @_GLOBAL__sub_I_test_string_compare.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp44:
	.cfi_def_cfa_offset 16
.Ltmp45:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp46:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end4:
	.size	_GLOBAL__sub_I_test_string_compare.cpp, .Lfunc_end4-_GLOBAL__sub_I_test_string_compare.cpp
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
