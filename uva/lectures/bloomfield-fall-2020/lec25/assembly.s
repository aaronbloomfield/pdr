; assembly.s, which contains the addOrMult() function
;
; Parameter 1 (in rdi) is the boolean (whether to add or mult)
; Parameter 2 (in rsi) is the starting address of a sequence of 64-bit longs
; Parameter 3 (in rdx) is the number of integers in the sequence
; Return value is a long that is the sum of the integers in the sequence
;

	global addOrMult

	section .text

addOrMult:
	
	; subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i

	; see if boolean is true or false
	; boolean is in lowest 1 byte of rdi (dil)
	cmp 	dil, 0
	je 	_mult

_add:	
	cmp	r10, rdx	 ; does i == n?
	je	_done		 ; if so, we are done with the loop
	add	rax, [rsi+8*r10] ; add a[i] to rax
	inc	r10		 ; increment our counter i
	jmp	_add		 ; we are done with this loop iteration

_mult:
	mov 	rax, 1	
_multloop:
	cmp	r10, rdx		; does i == n?
	je	_done			; if so, we are done with the loop
	imul	rax, [rsi+8*r10] 	; multi a[i] by rax
	inc	r10			; increment our counter i
	jmp	_multloop		; we are done with this loop iteration

_done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret
