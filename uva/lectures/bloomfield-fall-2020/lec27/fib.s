	;  CS 2150, exam 2, fall 2019, question 11

fib:				; 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
				; fib(n) = fib(n-1) + fib(n-2)
	xor rax, rax		; set rax = 0
	cmp rdi, 0		; compare 1st param to zero
	je done			; jump to done if param is zero
	cmp rdi, 2		; compare 1st param to 2
	jle base		; jump to base if 1st param is <=2
	push rax		; no reason for this line
	dec rdi			; change parameter to n-1 (from n)
	________		; push rdi: save rdi with the n-1 value
	call fib		; call fib(n-1)
	________		; pop rdi: restore rdi with the n-1 value
	________		; must be a pop -- but to where?; pop to anywhere (pop r10; pop r11; pop rsi)
	mov r10, rax		; copy rax into r10; no reason for this line
	push rax		; push fib(n-1) result onto stack
	dec rdi			; change parameter to n-2 (from n-1)
	call fib		; call fib(n-2) -> rax
	pop r10			; restore fib(n-1) result into r10
	sum rax, r10		; sum fib(n-1) and fib(n-2) into rax (sum == add)
	ret			; return result
base:
	mov rax, 1		; set return value to 1
done:
	ret			; return value in rax
	
