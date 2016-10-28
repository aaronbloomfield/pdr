; vecsum.s
;
; Purpose : This file contains the implementation of the function
;           vecsum, which adds up a vector of integers.
	
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
        push    rbp
        mov     rbp, rsp
        mov     [rbp - 8], rdi
        mov     [rbp - 16], rsi
	xor	rax, rax
        mov     [rbp - 24], rax
        mov     [rbp - 32], rax
.LBB0_1:
        mov     rax, [rbp - 32]
        cmp     rax, [rbp - 16]
        jge     .LBB0_4
        mov     rax, [rbp - 32]
        mov     rcx, [rbp - 8]
        mov     rax, [rcx + 8*rax]
        add     rax, [rbp - 24]
        mov     [rbp - 24], rax
        mov     rax, [rbp - 32]
        add     rax, 1
        mov     [rbp - 32], rax
        jmp     .LBB0_1
.LBB0_4:
        mov     rax, [rbp - 24]
        mov     ecx, eax
        mov     eax, ecx
        pop     rbp
        ret
