section .text
global pff
EXTERN exp
pff:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 1074118410
	push 2333366121

	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	push 1074118410
	push 2333366121

	fld qword[esp + 8]
	fld qword[esp]
	fsubp
	add esp, 8
	fstp qword[esp]

	push 1074118410
	push 2333366121

	fld qword[esp + 8]
	fld qword[esp]
	fdivp st1, st0
	add esp, 8
	fstp qword[esp]

	fld qword[esp]
	add esp, 8
	pop ebx
	pop ebp
	ret
