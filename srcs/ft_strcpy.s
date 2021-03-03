global _ft_strcpy

section .text
_ft_strcpy:
	mov rax, rdi

_next_char:
	cmp [rsi], byte 0
	je _end_string
	mov rdx, [rsi]
	mov [rdi], rdx
	inc rdi
	inc rsi
	jmp _next_char 

_end_string:
	mov [rdi], byte 0
	ret