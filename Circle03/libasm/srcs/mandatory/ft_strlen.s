global _ft_strlen
	section .text

_ft_strlen:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 20h

    mov     QWORD [rbp - 24], rdi
    mov     QWORD [rbp - 16], 0
