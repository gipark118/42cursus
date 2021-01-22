; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/15 12:09:15 by gipark            #+#    #+#              ;
;    Updated: 2021/01/22 11:09:55 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcpy
	extern ___error

; rdi == dst, rsi == src, rcx == index
_ft_strcpy:
	test	rdi, rdi		; if dst < 0
	js		_err			; jump to _err
	test	rsi, rsi		; if src < 0
	js		_err			; jump to _err
	push	rdx				; sub rsp, 8	; mov [rsp], rdx
	push	rcx				; sub rsp, 8	; mov [rsp], rcx
	mov		rdx, 0			; rdx = 0
	mov		rcx, 0			; rcx = 0
	_loop:
		mov	dl, BYTE [rsi + rcx]		; dl = src[i]
		mov	BYTE [rdi + rcx], dl		; dst[i] = dl
		cmp [rsi + rcx], BYTE 0			; while condition check
		je	_end						; if ZF = 1 (src[i] == '\0'), jump to _end
		inc	rcx							; i++
		jmp	_loop						; jump to _loop (while loop)
	_end:
	mov	rax, rdi		; rax = rdi
	pop	rcx				; mov rcx, [rsp]	; add rsp, 8
	pop rdx				; mov rdx, [rsp]	; add rsp, 8
	ret
	
_err:
	push	rax				; sub rsp, rax's data size	; mov [rsp], rax
	call	___error		; rax = _error
	pop		rdx				; mov rdx, [rsp]	; add rsp, rax's data size
	mov		[rax], rdx		; *rax = rdx
	mov		rax, -1			; rax = -1
	ret
