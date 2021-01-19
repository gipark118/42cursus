; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/15 15:13:10 by gipark            #+#    #+#              ;
;    Updated: 2021/01/20 01:02:45 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcmp
	extern ___error

; rdi == s1, rsi == s2, rcx == index
_ft_strcmp:
	test	rdi, rdi	; if s1 < 0
	js		_err		; if sign flag == 1, jump to _err
	test	rsi, rsi	; if s2 < 0
	js		_err		; if sign flag == 1, jump to _err
	push	rdx			; sub rsp, 8	; mov [rsp], rdx
	push	rcx			; sub rsp, 8	; mov [rsp], rcx
	mov		rdx, 0		; rdx = 0
	mov		rcx, 0		; rcx = 0
	_loop:
		cmp [rdi + rcx], BYTE 0						; if (s1[i] == 0)
		je	_end									;	break
		cmp [rsi + rcx], BYTE 0						; if (s2[i] == 0)
		je	_end									;	break
		mov	dl, BYTE [rdi + rcx]
		cmp dl, BYTE [rsi + rcx]					; if (s1[i] != s2[i])
		jne	_end									;	break
		inc	rcx										; i++
		jmp _loop									; jump to _loop

_end:
	mov	dl, [rdi + rcx]		; dl = s1[i]
	sub	dl, [rsi + rcx]		; dl = dl - s2[i] (== s1[i] - s2[i])
	mov BYTE [rax], dl
	pop	rdx
	pop rcx
	ret

_err:
	push	rax				; sub rsp, rax's data size	; mov [rsp], rax
	call	___error		; rax = _error
	pop		rdx				; mov rdx, [rsp]	; add rsp, rax's data size
	mov		[rax], rdx		; *rax = rdx
	mov		rax, -1			; rax = -1
	ret
