section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, 0		; rax = 0
	jmp _loop		; jump to loop

_loop:
	cmp BYTE [rdi + rax], 0			; rdi, rdi + rax, rdi + rax + rax... subtract 0
	je	_exit					; if [rcx + rax] - 0 equals 0, jump to exit
	inc	rax						; rax++
	jmp _loop					; jump to loop again

_exit:
	ret			; return rax
