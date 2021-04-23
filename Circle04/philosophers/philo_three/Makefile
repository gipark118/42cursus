# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 08:40:57 by gipark            #+#    #+#              #
#    Updated: 2021/04/23 08:41:05 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRCS_NAME = main.c			\
			init.c			\
			state.c			\
			utils.c			\
			exit.c			\

SRCS = $(addprefix srcs/, $(SRCS_NAME))
OBJS = $(SRCS:%.c=%.o)
INCS = ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -lpthread $(OBJS) -I$(INCS) -o $(NAME)

%.o : %.c
	$(CC) -c -o $@ ${CFLAGS} $< -I$(INCS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
