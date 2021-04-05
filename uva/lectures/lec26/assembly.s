; factArray() and factorial()
;
; for factArray():
; Parameter 1 (in rdi) is the starting address of a sequence of 64-bit longs
; Parameter 2 (in rsi) is the number of integers in the sequence
;
; for factorial():
; Parameter 1 (in rdi) is the value to return the factorial of


	global factArray
	global factorial

	section .text

	
;  factArray(): given a array and a size, compute the factorial of each spot in that array
	
factArray:

	xor r10, r10 			; r10 will store i to loop through a

_factArrayLoop:
	cmp r10, rsi 			; is i == n?
	je _factArrayDone

	; put parameters in proper place
	; save values that could get overwritten
	push rdi
	push rsi
	push r10

	; put the parameter into rdi and call factorial()
	mov rdi, [rdi + 8*r10]
	call factorial

	; restore the pushed values
	pop r10
	pop rsi
	pop rdi

	; store the return value in the right place
	mov [rdi + 8*r10], rax
	
	; finish up the loop
	inc r10
	jmp _factArrayLoop

_factArrayDone:
	ret



; factorial(): takes one param (in rdi) and computes the factorial of that value

factorial:
	cmp rdi, 1			; is the parameter 1?
	jle _factbase

	; recursively compute the factorial
	mov rsi, rdi 			; mov param over
	push rsi
	;; the previous two lines could have been simplified with 'push rdi'

	dec rdi				; setup n-1 for recursive call
	call factorial			; call factorial
	pop rsi
	imul rax, rsi 			; multiply n into recursive answer
	ret 				; return

_factbase:
	mov rax, 1
	ret
