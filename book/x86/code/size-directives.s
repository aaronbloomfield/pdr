mov BYTE PTR [ebx], 2		; Move 2 into the single byte at memory
				; location EBX
mov WORD PTR [ebx], 2		; Move the 16-bit integer representation of 2 
				; into the 2 bytes starting at address EBX
mov DWORD PTR [ebx], 2		; Move the 32-bit integer representation of 2
				; into the 4 bytes starting at address EBX
