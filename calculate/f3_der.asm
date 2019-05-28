section .text
global f3_der
EXTERN exp
f3_der:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 1074118410
	push 2333366121

	push 1074118410
	push 2333366121

	fld qword[esp + 8]
	fld qword[esp]
	fsubp
	add esp, 8
	fstp qword[esp]

	fld qword[esp]
	add esp, 8
	pop ebx
	pop ebp
	ret
