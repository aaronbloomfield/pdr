; Want to call a function "myFunc" that takes three
; integer parameters. First parameter is in rax.
; Second parameter is the constant 123. Third
; parameter is in memory location "var"

push rdi         ; rdi will be a param, so saving it

                 ; long retVal = myFunc(x, 123, z);
mov rdi, rax     ; put first param in rdi
mov rsi, 123     ; put second param in rsi
mov rdx, [var]   ; put third param in rdx

call myFunc      ; call the function

pop rdi          ; restore saved rdi value

; return value of myFunc is now available in rax 
; (if there is any return value)
