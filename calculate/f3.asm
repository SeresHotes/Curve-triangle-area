section .text
global f3
EXTERN exp
f3:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 1074790400
	push 0

	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

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
