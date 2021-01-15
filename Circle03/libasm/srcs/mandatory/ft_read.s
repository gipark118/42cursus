section .text
	global	_ft_read
	extern	___error

_ft_read:
	mov	rax, 0x2000003		; read syscall number (rax = 0x2000003)
	syscall
	jc	_err				; if carry flag equals 1, jump _err
	ret

_err:
	push	rax				; sub rsp, rax's data size	; mov [rsp], rax
	call	_error			; rax = _error
	pop		rdx				; mov rdx, [rsp]	; add rsp, rax's data size
	mov		[rax], rdx		; *rax = rdx
	mov		rax, -1			; rax = -1
	ret
