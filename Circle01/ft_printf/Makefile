# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 01:55:39 by gipark            #+#    #+#              #
#    Updated: 2020/08/20 02:31:35 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=

BONUS_SRCS	=
OBJS	= ${SRCS:%.c=%.o}
BONUS_OBJS	= ${BONUS_SRCS:%.c=%.o}
NAME	= libftprintf.a
LIBC	= ar rcs
RM	= rm -f
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

all : ${NAME}

%.o : %.c
	${CC} -c -o $@ ${CFLAGS} $<

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all bonus

bonus : ${BONUS_OBJS}
	${LIBC} ${NAME} ${BONUS_OBJS}

.PHONY : clean fclean all re bonus
