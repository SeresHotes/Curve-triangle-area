section .text
global f1_der
EXTERN exp
f1_der:
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
