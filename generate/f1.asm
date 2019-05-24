section .text
global f1
f1:
	push ebp
	mov ebp, esp

	finit
	push 0
	push 0

	fld qword[esp]
	add esp, 8
	pop ebp
	ret
