section .text
global f3_der
EXTERN exp
f3_der:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 0
	push 0

	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	push 1073741824
	push 0

	push 1074118410
	push 2333366121

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	fld qword[esp + 8]
	fld qword[esp]
	faddp
	add esp, 8
	fstp qword[esp]

	push 0
	push 0

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
