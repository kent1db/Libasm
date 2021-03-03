global _hello_world

section .data
	hello db 'hello world', 10
	hello_len equ $-hello

section .text

_hello_world:
	mov rax, 0x02000004
	mov rdi, 1
	mov rsi, hello
	mov rdx, hello_len
	syscall
	ret