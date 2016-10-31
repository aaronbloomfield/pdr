; vecsum.s
;
; Purpose : This file contains the implementation of the function
;           vecsum, which adds up a vector of integers.
;
; Parameter 1 (in rdi) is the starting address of a sequence of 64-bit longs
; Parameter 2 (in rsi) is the number of integers in the sequence
; Return value is a long that is the sum of the integers in the sequence
;

	global vecsum

	section .text

vecsum:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start:	
	cmp	r10, rsi	 ; does i == n?
	je	done		 ; if so, we are done with the loop
	add	rax, [rdi+8*r10] ; add a[i] to rax
	inc	r10		 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret
