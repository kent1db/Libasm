global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text
_ft_strdup:
	xor rax, rax
	push rdi
	call _ft_strlen
	mov rdi, rax
	add rdi, 1
	call _malloc
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret
