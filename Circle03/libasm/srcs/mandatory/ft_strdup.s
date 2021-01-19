; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/18 23:53:13 by gipark            #+#    #+#              ;
;    Updated: 2021/01/20 01:03:29 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global	_ft_strdup
	extern	___error
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

; rdi = s1
_ft_strdup:
	test	rdi, rdi	; if s1 < 0
	js		_err		; if sign flag == 1, jump to _err
	call	_ft_strlen	; call _ft_strlen
	add		rax, 1		; rax += 1 (for '\0')
	push	rdi			; sub rsp, 8	; mov [rsp], rdi
	mov		rdi, rax
	call	_malloc		; call _malloc
	cmp		rax, 0		; if rax == 0
	je		_err		;	if zf == 1, jump to _err
	pop		rdi			; mov rdi, [rsp]	; add rsp, 8
	push	rsi			; sub rsp, 8	; mov [rsp], rsi
	mov		rsi, rdi	; rsi = rdi (newstr = s1)
	mov		rdi, rax	
	call	_ft_strcpy
	pop		rsi
	ret

_err:
	push	rax				; sub rsp, rax's data size	; mov [rsp], rax
	call	___error		; rax = _error
	pop		rdx				; mov rdx, [rsp]	; add rsp, rax's data size
	mov		[rax], rdx		; *rax = rdx
	mov		rax, -1			; rax = -1
	ret
