section .text
global f3_der
f3_der:
	push ebp
	mov ebp, esp

	finit
	push 0
	push 0

	push 1072693248
	push 0

	fld qword[esp + 8]
	fld qword[esp]
	fsubp
	add esp, 8
	fstp qword[esp]

	fld qword[esp]
	add esp, 8
	pop ebp
	ret
