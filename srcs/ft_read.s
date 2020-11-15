global	_ft_read
extern	___error

section	.text
_ft_read:
			mov		rax, 0x2000003	; syscall for read = 3
			syscall
			jnc		_exit
			push	rax
			call	___error
			pop		rbx
			mov		[rax], rbx
			mov		rax, -1
_exit:
			ret