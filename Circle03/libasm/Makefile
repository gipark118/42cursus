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

SRCS	= ${addprefix srcs/mandatory, ${shell ls ./srcs/mandatory | grep '\.c'}}
BONUS_SRCS	= ${addprefix srcs/bonus, ${shell ls ./srcs/bonus | grep '\.c'}}
OBJS	= ${SRCS:%.s=%.o}
BONUS_OBJS	= ${BONUS_SRCS:%.s=%.o}
NAME	= libasm.a
LIBC	= ar rcs
RM	= rm -f
NASM	= nasm
NASM_FLAGS	= -f macho64

all : ${NAME}

%.o : %.s
	${NASM} -s -o $@ ${NASM_FLAGS} $<

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

bonus : ${BONUS_OBJS}
	${LIBC} ${NAME} ${BONUS_OBJS}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all bonus

.PHONY : all bonus clean fclean re
