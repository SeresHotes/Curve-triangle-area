section .text
global f2
f2:
	push ebp
	mov ebp, esp

	finit
	mov ecx, dword[ebp + 8]
	mov edx, dword[ebp + 12]
	push edx
	push ecx

	fld qword[esp]
	add esp, 8
	pop ebp
	ret
