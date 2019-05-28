section .text
global f1
EXTERN exp
f1:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 0
	push 0

	fld qword[esp]
	add esp, 8
	pop ebx
	pop ebp
	ret
