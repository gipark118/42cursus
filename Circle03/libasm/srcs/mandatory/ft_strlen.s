; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/15 12:08:51 by gipark            #+#    #+#              ;
;    Updated: 2021/01/15 12:08:53 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

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
