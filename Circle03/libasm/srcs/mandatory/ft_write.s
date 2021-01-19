; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/18 23:23:18 by gipark            #+#    #+#              ;
;    Updated: 2021/01/18 23:52:54 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_write
	extern ___error

_ft_write:
	mov	rax, 0x2000004		; write syscall number (rax = 0x2000004)
	syscall
	jc	_err				; if carry flag == 1, jump to _err
	ret

_err:
	push rax				; sub rsp, 8	; mov [rsp], rax
	call ___error
	pop	rdx					; mov rdx, [rsp]	; add rsp, 8
	mov	[rax], rdx			; *rax = rdx
	mov	rax, -1				; rax = -1
	ret
