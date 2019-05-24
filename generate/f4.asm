section .text
global f4
f4:
	push ebp
	mov ebp, esp

	finit
	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	push 1075052544
	push 0

	fld qword[esp]
	fsin
	fstp qword[esp]

	fld qword[esp]
	fptan
	fxchg
	fstp ST1
	fstp qword[esp]

	fld qword[esp + 8]
	fld qword[esp]
	fdivp st1, st0
	add esp, 8
	fstp qword[esp]

	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	push 1074790400
	push 0

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

	fld qword[esp]
	add esp, 8
	pop ebp
	ret
