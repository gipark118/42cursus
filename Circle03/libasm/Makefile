# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 16:02:12 by gipark            #+#    #+#              #
#    Updated: 2020/08/12 16:55:24 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s
BONUS_SRCS	= ft_atoi_base.s \
							ft_list_push_front.s \
							ft_list_size.s \
							ft_list_sort.s \
							ft_list_remove_if.s
OBJS			= ${SRCS:%.s=%.o}
BONUS_OBJS	= ${BONUS_SRCS:%.s=%.o}
NAME	= libasm.a
LIBC	= ar -rcs
RM	= rm -f
NASM	= nasm
NASM_FLAGS	= -f macho64

all : ${NAME}

.s.o :
	${NASM} ${NA_FLAGS} -s $< -o ${<:%.s=%.o}

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

bonus : ${BONUS_OBJS}
	${LIBC} ${NAME} ${BONUS_OBJS}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean :
	${RM} ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re
