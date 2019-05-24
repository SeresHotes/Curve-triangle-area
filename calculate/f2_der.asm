section .text
global f2_der
f2_der:
	push ebp
	mov ebp, esp

	finit
	push 1072693248
	push 0

	fld qword[esp]
	add esp, 8
	pop ebp
	ret
