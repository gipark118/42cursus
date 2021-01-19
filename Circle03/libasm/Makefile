# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 16:02:12 by gipark            #+#    #+#              #
#    Updated: 2021/01/13 23:31:23 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${addprefix srcs/mandatory/, ${shell ls ./srcs/mandatory | grep '\.s'}}
BONUS_SRCS	= ${addprefix srcs/bonus/, ${shell ls ./srcs/bonus | grep '\.s'}}
OBJS	= ${SRCS:%.s=%.o}
BONUS_OBJS	= ${BONUS_SRCS:%.s=%.o}
INCS	= ./includes
NAME	= libasm.a
LIBC	= ar rcs
RM	= rm -rf
NASM	= nasm
NASM_FLAGS	= -f macho64

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I./includes/
MAIN	= main.c
MAIN_OBJ	= ${MAIN:%.c=%.o}
EXEC	= test

%.o : %.s
	${NASM} -s -o $@ ${NASM_FLAGS} $<

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

${EXEC} : ${NAME} ${MAIN_OBJ}
	${CC} ${CFLAGS} ${MAIN_OBJ} ${NAME} -o ${EXEC}

all	: ${NAME}

bonus : ${BONUS_OBJS}
	${LIBC} ${NAME} ${BONUS_OBJS}

clean :
	${RM} ${OBJS} ${BONUS_OBJS} ${MAIN_OBJ}
	${RM} ${EXEC}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re
