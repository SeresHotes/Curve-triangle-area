section .text
global f4_der
f4_der:
	push ebp
	mov ebp, esp

	finit
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

	fld qword[esp]
	fld ST0
	fmulp
	fld1
	fdivrp ST1, ST0
	fstp qword[esp]

	push 1072693248
	push 0

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
	fmulp
	add esp, 8
	fstp qword[esp]

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
	fcos
	fstp qword[esp]

	fld qword[esp]
	fld ST0
	fmulp
	fld1
	fdivrp ST1, ST0
	fstp qword[esp]

	push 1075052544
	push 0

	fld qword[esp]
	fcos
	fstp qword[esp]

	push 0
	push 0

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	fld qword[esp + 8]
	fld qword[esp]
	fsubp
	add esp, 8
	fstp qword[esp]

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	push 1072693248
	push 0

	push 1074790400
	push 0

	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]

	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	push 0
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

	fld qword[esp + 8]
	fld qword[esp]
	faddp
	add esp, 8
	fstp qword[esp]

	fld qword[esp]
	add esp, 8
	pop ebp
	ret
