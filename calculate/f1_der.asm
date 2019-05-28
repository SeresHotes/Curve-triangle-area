section .text
global f1_der
EXTERN exp
f1_der:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 3220176896
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

	fld qword[esp]
	mov ebx, esp
	and esp, -16
	sub esp, 16
	fstp qword[esp]
	call exp
	mov esp, ebx
	fstp qword[esp]

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

	push 3220176896
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

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	push 0
	push 0

	fld qword[esp + 8]
	fld qword[esp]
	faddp
	add esp, 8
	fstp qword[esp]

	fld qword[esp]
	add esp, 8
	pop ebx
	pop ebp
	ret
