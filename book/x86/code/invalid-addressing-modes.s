mov eax, [ebx-ecx]	; Can only add register values
mov [eax+esi+edi], ebx	; At most 2 registers in address computation
