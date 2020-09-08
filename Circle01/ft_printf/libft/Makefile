# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 09:31:52 by gipark            #+#    #+#              #
#    Updated: 2020/09/08 09:39:09 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${shell ls . | grep '\.c'}
OBJS	= ${SRCS:%.c=%.o}
NAME	= libft.a
LIBC	= ar rcs
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

all : ${NAME}

%.o : %.c
	${CC} -c -o $@ ${CFLAGS} $<

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: clean fclean all re
