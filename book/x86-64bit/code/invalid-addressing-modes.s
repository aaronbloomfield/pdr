mov rax, [rbx-rcx]	; Can only add register values
mov [rax+rsi+rdi], rbx	; At most 2 registers in address computation
