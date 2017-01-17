; vecsum.s
;
; Author  : Adam Ferrari
; Date    : Jan 29, 1998
; Purpose : This file contains the implementation of the function
;           vecsum, which adds up a vector of integers.
; Modified for NASM by Aaron Bloomfield on 9 Nov 2007
	
	global vecsum

	section .text

;
; vecsum
; Parameter 1  - the starting address of a sequence of 32-bit integers.
; Parameter 2  - the number of integers in the sequence.
; Return value - the sum of the integers in the sequence.
;

vecsum:
	; Standard prologue
	push  ebp		; Save the old base pointer
	mov   ebp, esp		; Set new value of the base pointer
	push  esi		; Save registers

	xor   eax, eax		; Place zero in EAX. We will keep a running
				; sum of the vector elements in EAX.

	mov   esi, [ebp+8]	; Put the vector starting address in ESI.
	mov   ecx, [ebp+12]	; Put the vector size in ECX. We will use
				; ECX to indicate how many vector elements
				; are left to add into the sum.

	cmp   ecx, 0		; If there are not more than zero elemen
	jle   vecsum_done	; in the array, skip to the end and return
				; zero (already in EAX).

vecsum_loop:
	mov   edx, [esi]	; Put the current vector element into EDX.
	add   eax, edx		; Add the current vector element into the
				; running sum.
	add   esi, 4		; Increment ESI to point to the next
				; vector element (4 bytes away).
	dec   ecx		; Decrement ECX, the counter of how many
				; left to do.
	cmp   ecx, 0		; If there are more than zero elements
	jg    vecsum_loop	; left to add up, then do the loop again.

vecsum_done:
	; At this point, the loop is done, and we have the sum of the
	; vector elements in EAX, which is exactly where we want the
	; return value to be.

	; Standard epilogue
	pop   esi		; Restore registers that we used.
				; Note - no local variables to dealocate.
	pop   ebp		; Restore the caller's base pointer.
	ret			; Return to the caller.
