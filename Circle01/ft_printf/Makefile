# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 01:55:39 by gipark            #+#    #+#              #
#    Updated: 2020/09/08 05:32:06 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${addprefix srcs/, ${shell ls ./srcs | grep '\.c'}}

OBJS	= ${SRCS:%.c=%.o}
NAME	= libftprintf.a
LIBC	= ar rcs
RM	= rm -f
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft.a
LIBFT_DIR	= libft
LIBFT_LIB	= ${LIBFT_DIR}/${LIBFT}

all : ${NAME}

${LIBFT_LIB} :
	${MAKE} -C ${LIBFT_DIR}

%.o : %.c
	${CC} -c -o $@ ${CFLAGS} $< -I./includes

${NAME} : ${LIBFT_LIB} ${OBJS}
	cp ${LIBFT_LIB} ${NAME}
	${LIBC} ${NAME} ${OBJS}

bonus : ${NAME}

clean :
	${MAKE} -C ${LIBFT_DIR} clean
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${NAME}

re : fclean all bonus

.PHONY : clean fclean all re bonus
