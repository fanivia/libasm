global	_ft_write
extern	___error

section	.text

_ft_write:	mov		rax, 0x2000004	; syscall for write = 4. For 64-bits in 'syscall_sw.h'
									; #define SYSCALL_CLASS_UNIX	2 /*Unix/BSD */
									; #define SYSCALL_CLASS_SHIFT	24
									; (2 << 24 == 0x2000000)
			syscall
			jnc		_exit
			push	rax
			call	___error
			pop		rbx
			mov		[rax], rbx
			mov		rax, -1
_exit:
			ret