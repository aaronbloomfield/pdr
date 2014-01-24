bytes	DB	10	DUP(?)	; Declare 10 uninitialized bytes starting at
				; the address "bytes".
arr	DD	100	DUP(0)	; Declare 100 4 bytes words, all initialized
				; to 0, starting at memory location "arr".
str	DB	'hello', 0	; Declare 5 bytes starting at the address 
				; "str" initialized to the ASCII character 
				; values for the characters 'h', 'e', 'l', 
				; 'l', 'o', and '\0' (NULL), respectively.
