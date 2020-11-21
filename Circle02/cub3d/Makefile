# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 23:25:44 by gipark            #+#    #+#              #
#    Updated: 2020/11/22 00:38:52 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRCS	= ${addprefix srcs/, ${shell ls ./srcs | grep '\.c'}}
OBJS	= ${SRCS:%.c=%.o}
INCS	= ./includes
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX	= mlx
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit

HEADER	= cub3d.h

all : ${NAME}

${NAME} : ${OBJS}
	make -C mlx
	${CC} -o ${NAME} -L ${MLX} ${MLXFLAGS} ${OBJS}

clean :
	make clean -C mlx
	rm -rf ${OBJS}
	rm -f bitmap.bmp

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean all re
