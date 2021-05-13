# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:11:33 by gipark            #+#    #+#              #
#    Updated: 2021/05/14 00:15:36 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= replace

DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/
SRCS		= main.cpp		\
			  replace.cpp

OBJS		= $(SRCS:%.cpp=$(DIR_OBJS)%.o)
INCS		= ./includes/

CC			= clang++
RM			= rm -rf
CFLAGS		= -Wall -Wextar -Werror

all :		$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFALGS) -I$(INCS) $(OBJS) -o $(NAME)

$(OBJS) :	$(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.cpp
			$(CC) $(CFALGS) -I$(INCS) -c $< -o $@

$(DIR_OBJS) :
			mkdir $(DIR_OBJS)

clean :
			$(RM) $(DIR_OBJS)

fclean :	clean
			$(RM) $(NAME) *.replace */*.replace

re :		fclean all

.PHONY :	clean fclean all re
