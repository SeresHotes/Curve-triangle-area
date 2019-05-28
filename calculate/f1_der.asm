section .text
global f1_der
EXTERN exp
f1_der:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 1074118410
	push 2333366121

	fld qword[esp]
	add esp, 8
	pop ebx
	pop ebp
	ret
