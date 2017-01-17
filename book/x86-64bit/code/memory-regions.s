section .data
var	DB	64	; Declare a byte containing the value 64. Label the
			; Memory location "var".
var2	DB	?	; Declare an uninitialized byte labeled "var2".
	DB	10	; Declare an unlabeled byte initialized to 10. This
			; byte will reside at the memory address var2+1.
var3	DQ	?	; Declare an uninitialized 64-bit quantity ('Q' is for
			; quad-word)
X	DW	?	; Declare an uninitialized two-byte word labeled "X".
Y	DD	3000	; Declare 32 bits of memory starting at address "Y"
			; initialized to contain 3000.
Z	DD	1,2,3	; Declare three 4-byte words of memory starting at
			; address "Z", and initialized to 1, 2, and 3,
			; respectively. E.g. 3 will be stored at address Z+8.
