# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:41:40 by gipark            #+#    #+#              #
#    Updated: 2021/04/14 16:42:06 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

SRCS_NAME =	 checker.c				\
			 utils.c				\
			 init_list.c			\
			 push.c					\
			 rotate.c				\
			 reverse_rotate.c		\
			 swap.c					\
			 free_utils.c			\
			 resolve.c				\
			 median.c				\

SRCS_NAME2	= push_swap.c			\
			  free_utils.c			\
			  resolve.c				\
			  short_resolve.c		\
			  utils.c				\
			  init_list.c			\
			  push.c				\
			  rotate.c				\
			  reverse_rotate.c		\
			  swap.c				\
			  median.c				\

SRCS_1 = $(addprefix srcs/, $(SRCS_NAME))
SRCS_2 = $(addprefix srcs/, $(SRCS_NAME2))

OBJS_NAME = $(SRCS_1:%.c=%.o)
OBJS_NAME2 = $(SRCS_2:%.c=%.o)

LIB = ./libft/libft.a
LIB_PATH = ./libft
INCS = -I libft/includes -I ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME) $(NAME2)

%.o : %.c
	@$(CC) -c -o $@ $(CFLAGS) $< $(INCS)

$(NAME) : $(OBJS_NAME)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJS_NAME) $(INCS) $(LIB) -o $(NAME)

$(NAME2) : $(OBJS_NAME2)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJS_NAME2) $(INCS) $(LIB) -o $(NAME2)

clean :
	@make clean -C $(LIB_PATH)
	@$(RM) $(OBJS_NAME)
	@$(RM) $(OBJS_NAME2)

fclean : clean
	@make fclean -C $(LIB_PATH)
	@$(RM) $(NAME) $(NAME2)

re : fclean all

.PHONY : clean fclean all re
