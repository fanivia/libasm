global	_ft_strcpy

section	.text
_ft_strcpy:
			mov rbx, -1
			cmp rsi, 0
			je _exit
_loop:
			inc rbx
			mov al, byte[rsi + rbx]
			mov byte[rdi + rbx], al
			cmp byte[rsi + rbx], 0
			jne _loop
			mov rax, rdi
			ret
_exit:
			mov rdi, 0
			mov rax, rdi
			ret