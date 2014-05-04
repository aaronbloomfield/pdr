	.file	"test_string_compare.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	compare_string
	.type	compare_string, @function
compare_string:
.LFB966:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	jmp	.L2
.L5:
	add	DWORD PTR [ebp+8], 1
	add	DWORD PTR [ebp+12], 1
.L2:
	mov	eax, DWORD PTR [ebp+8]
	movzx	eax, BYTE PTR [eax]
	test	al, al
	je	.L3
	mov	eax, DWORD PTR [ebp+8]
	movzx	edx, BYTE PTR [eax]
	mov	eax, DWORD PTR [ebp+12]
	movzx	eax, BYTE PTR [eax]
	cmp	dl, al
	jne	.L3
	mov	eax, 1
	jmp	.L4
.L3:
	mov	eax, 0
.L4:
	test	al, al
	jne	.L5
	mov	eax, DWORD PTR [ebp+8]
	movzx	edx, BYTE PTR [eax]
	mov	eax, DWORD PTR [ebp+12]
	movzx	eax, BYTE PTR [eax]
	cmp	dl, al
	sete	al
	pop	ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE966:
	.size	compare_string, .-compare_string
	.section	.rodata
.LC0:
	.string	"Enter string 1: "
.LC1:
	.string	"Enter string 2: "
.LC2:
	.string	"The result is: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB967:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA967
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	ebx
	and	esp, -16
	sub	esp, 32
	lea	eax, [esp+20]
	mov	DWORD PTR [esp], eax
.LEHB0:
	.cfi_offset 3, -12
	call	_ZNSsC1Ev
.LEHE0:
	lea	eax, [esp+24]
	mov	DWORD PTR [esp], eax
.LEHB1:
	call	_ZNSsC1Ev
.LEHE1:
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC0
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
.LEHB2:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	lea	eax, [esp+20]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC1
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	lea	eax, [esp+24]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	lea	eax, [esp+24]
	mov	DWORD PTR [esp], eax
	call	_ZNKSs5c_strEv
	mov	ebx, eax
	lea	eax, [esp+20]
	mov	DWORD PTR [esp], eax
	call	_ZNKSs5c_strEv
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], eax
	call	compare_string
	mov	BYTE PTR [esp+31], al
	movzx	ebx, BYTE PTR [esp+31]
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEb
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
.LEHE2:
	mov	ebx, 0
	lea	eax, [esp+24]
	mov	DWORD PTR [esp], eax
.LEHB3:
	call	_ZNSsD1Ev
.LEHE3:
	lea	eax, [esp+20]
	mov	DWORD PTR [esp], eax
.LEHB4:
	call	_ZNSsD1Ev
.LEHE4:
	mov	eax, ebx
	mov	ebx, DWORD PTR [ebp-4]
	leave
	.cfi_remember_state
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.cfi_restore 3
	ret
.L10:
	.cfi_restore_state
	mov	ebx, eax
	lea	eax, [esp+24]
	mov	DWORD PTR [esp], eax
	call	_ZNSsD1Ev
	jmp	.L8
.L9:
	mov	ebx, eax
.L8:
	lea	eax, [esp+20]
	mov	DWORD PTR [esp], eax
	call	_ZNSsD1Ev
	mov	eax, ebx
	mov	DWORD PTR [esp], eax
.LEHB5:
	call	_Unwind_Resume
.LEHE5:
	.cfi_endproc
.LFE967:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA967:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE967-.LLSDACSB967
.LLSDACSB967:
	.uleb128 .LEHB0-.LFB967
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB967
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L9-.LFB967
	.uleb128 0
	.uleb128 .LEHB2-.LFB967
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L10-.LFB967
	.uleb128 0
	.uleb128 .LEHB3-.LFB967
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L9-.LFB967
	.uleb128 0
	.uleb128 .LEHB4-.LFB967
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB967
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE967:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1015:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	cmp	DWORD PTR [ebp+8], 1
	jne	.L11
	cmp	DWORD PTR [ebp+12], 65535
	jne	.L11
	mov	DWORD PTR [esp], OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	eax, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	mov	DWORD PTR [esp+8], OFFSET FLAT:__dso_handle
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZStL8__ioinit
	mov	DWORD PTR [esp], eax
	call	__cxa_atexit
.L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1015:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_compare_string, @function
_GLOBAL__sub_I_compare_string:
.LFB1016:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [esp+4], 65535
	mov	DWORD PTR [esp], 1
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1016:
	.size	_GLOBAL__sub_I_compare_string, .-_GLOBAL__sub_I_compare_string
	.section	.ctors,"aw",@progbits
	.align 4
	.long	_GLOBAL__sub_I_compare_string
	.section	.rodata
	.align 4
	.type	_ZZL18__gthread_active_pvE20__gthread_active_ptr, @object
	.size	_ZZL18__gthread_active_pvE20__gthread_active_ptr, 4
_ZZL18__gthread_active_pvE20__gthread_active_ptr:
	.long	_ZL22__gthrw_pthread_cancelm
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
