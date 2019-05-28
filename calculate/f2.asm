section .text
global f2
EXTERN exp
f2:
	push ebp
	mov ebp, esp

	push ebx
	finit
	push 1072693248
	push 0

	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

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
