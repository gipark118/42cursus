; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/15 15:13:10 by gipark            #+#    #+#              ;
;    Updated: 2021/01/22 12:18:36 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcmp
	extern ___error

; rdi == s1, rsi == s2
_ft_strcmp:
	test	rdi, rdi	; if s1 < 0
	js		_err		; if sign flag == 1, jump to _err
	test	rsi, rsi	; if s2 < 0
	js		_err		; if sign flag == 1, jump to _err
	mov		rax, 0
	_loop:
		mov		al, BYTE [rdi]		; al = (char *)rdi
		mov		bl, BYTE [rsi]		; bl = (char *)rsi
		cmp		al, 0				; if (s1[i] == 0)
		je		_end				;	break	(jump to _end)
		cmp		bl, 0				; if (s2[i] == 0)
		je		_end				;	break	(jump to _end)
		cmp		al, bl				; if (s1[i] != s2[i])
		jne		_end				;	break	(jump to _end)
		inc		rdi					; s1++
		inc		rsi					; s2++
		jmp		_loop				; jump to _loop
	_end:
	sub		rax, rbx				; rax -= rbx (s1[i] - s2[i])
	ret

_err:
	push	rax				; sub rsp, rax's data size	; mov [rsp], rax
	call	___error		; rax = _error
	pop		rdx				; mov rdx, [rsp]	; add rsp, rax's data size
	mov		[rax], rdx		; *rax = rdx
	mov		rax, -1			; rax = -1
	ret
