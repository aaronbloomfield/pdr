global returnTwo

section .data
	var DD 2

section .text
	
returnTwo:	
	mov eax, [var]
	ret
