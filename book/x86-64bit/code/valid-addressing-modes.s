mov rax, [rbx]		; Move the 8 bytes in memory at the address contained 
			; in EBX into EAX
mov [var], rbx		; Move the contents of EBX into the 8 bytes at memory 
			; address "var" (Note, "var" is a 32-bit constant).
mov rax, [rsi-8]	; Move 8 bytes at memory address ESI+(-8) into EAX
mov [rsi+rax], cl	; Move the contents of CL into the byte at address
			; ESI+EAX
mov edx, [esi+4*ebx]	; Move the 4 bytes of data at address ESI+4*EBX into
			; EDX.  This is only 4 bytes because we use the 
			; 4-byte "sub-registers" of edx, esi, and ebx instead
			; of rdx, rsi, and rbx
