global myFunc

section .text
	
myFunc:
	; *** Standard subroutine prologue ***
	sub rsp, 8           ; room for a 64-bit local var (result)
	push rbx             ; save callee-save registers
	push rbp             ; both will be used by myFunc

	; *** Subroutine Body ***
	mov rax, rdi         ; param 1 to rax
	mov rbp, rsi         ; param 2 to rbp
	mov rbx, rdx         ; param 3 to rbx
	mov [rsp+16], rbx    ; put rbx into local var
	add [rsp+16], rbp    ; add rbp into local var
	mov rax, [rsp+16]    ; mov contents of local var to rax
			     ; (return value/final result)
	
	; *** Standard subroutine epilogue ***
	pop rbp              ; recover callee save registers
	pop rbx              ; REVERSE of when pushed
	add rsp, 8           ; deallocate local var(s)
	ret                  ; pop top value from stack, jump there
	
