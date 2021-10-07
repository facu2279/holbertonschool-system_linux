BITS 64
global asm_strpbrk	; EXPORT our 'asm_strpbrk' function

	section .text

	; size_t asm_strpbrk(const char *s1, const char *s2);
	; returns the difference between two strings
	;
	; edi <- const char s1
	; esi <- const chat s2
	;
	; Return: The diff of the last character
asm_strpbrk:
	push rbp ; saves base pointer into the stack
	mov rbp, rsp ; update base pointer to handle the current stack position

	push r15
	push rbx
	push rcx
	mov r14d, esi
	while_not_null_s1:
		mov esi, r14d
		mov bl, [edi]
		cmp bl, 0
		je return_value
		jmp while_not_null_s2
		next_iteration:
			inc edi
			jmp while_not_null_s1

	return_value:
	xor rax, rax; return value

	function_epilogue:
	pop rcx
	pop rbx
	pop r15
	mov rsp, rbp; Restore previous stack frame
	pop rbp; Those two lines are equivalent to 'leave'
	ret		; return to address in the stack IP

while_not_null_s2:
	mov cl, [esi]
	cmp cl, 0
	je next_iteration
	cmp bl, cl
	je match_found
	inc esi
	jmp while_not_null_s2

match_found:
	mov rax, rdi
	jmp function_epilogue
