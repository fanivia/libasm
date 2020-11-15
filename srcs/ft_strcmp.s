global _ft_strcmp
section .text
_ft_strcmp:
			mov rax, -1
_loop:
			inc rax
			mov	bl, byte[rdi + rax]
			sub bl, byte[rsi + rax]
			jnz _exit
			cmp byte[rdi + rax], 0
			jnz _loop
_exit:
			mov al, bl
			ret