mov eax, [ebx]		; Move the 4 bytes in memory at the address contained 
			; in EBX into EAX
mov [var], ebx		; Move the contents of EBX into the 4 bytes at memory 
			; address "var" (Note, "var" is a 32-bit constant).
mov eax, [esi-4]	; Move 4 bytes at memory address ESI+(-4) into EAX
mov [esi+eax], cl	; Move the contents of CL into the byte at address
			; ESI+EAX
mov edx, [esi+4*ebx]	; Move the 4 bytes of data at address ESI+4*EBX into
			; EDX
