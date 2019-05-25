section .text
global f1
EXTERN exp
f1:
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

	push 1074266112
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
