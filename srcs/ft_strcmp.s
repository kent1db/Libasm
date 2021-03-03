global _ft_strcmp

section .text
_ft_strcmp:
	xor rax, rax
	xor r8, r8
	xor r9, r9

_next_char:
	movzx r8, byte [rdi]
	movzx r9, byte [rsi]
	cmp r8, r9
	jl _neg
	jg _sup
	or r8, r9
	jz _zero 
	inc	rdi
	inc rsi
	jmp _next_char

_neg:
	mov rax, -1
	ret
_sup:
	mov rax, 1
	ret
_zero:
	mov rax, 0
	ret