section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, 0		; rax = 0
	jmp loop		; jump to loop

loop:
	cmp BYTE [rdi + rax], 0			; rdi, rdi + rax, rdi + rax + rax... subtract 0
	je	exit					; if [rcx + rax] - 0 equals 0, jump to exit
	inc	rax						; rax++
	jmp loop					; jump to loop again

exit:
	ret			; return rax
