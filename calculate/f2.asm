section .text
global f2
EXTERN exp
f2:
	push ebp
	mov ebp, esp

	push ebx
	finit
	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	fld qword[esp]
	add esp, 8
	pop ebx
	pop ebp
	ret
