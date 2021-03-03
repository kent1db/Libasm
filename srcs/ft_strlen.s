global _ft_strlen

section .text
_ft_strlen:
	xor rcx, rcx 		;  rcx = 0 same as mov rcx, 0 but more efficient

_next_char:
	cmp [rdi], byte 0	; cmp if we point to the null = end of str
	je _end_string		; if its 0, go to _end_string
	inc rcx				; else increment rcx
	inc	rdi				; increment pointer
	jmp	_next_char		; loop again

_end_string:
	mov rax, rcx 		; count in rcx go into rax for return value
	ret