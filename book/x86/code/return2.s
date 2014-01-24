.486
.MODEL FLAT

.DATA
var	DD	2

.CODE
PUBLIC _returnTwo
_returnTwo PROC
	mov eax, [var]
	ret
_returnTwo ENDP
END
	