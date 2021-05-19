# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 06:42:24 by gipark            #+#    #+#              #
#    Updated: 2021/05/18 15:15:47 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= whatever

DIR_SRCS	= ./
DIR_OBJS	= ./objs/
SRCS		= main.cpp
OBJS		= $(SRCS:%.cpp=$(DIR_OBJS)%.o)

CC			= clang++
RM			= rm -rf
CFLAGS		= -Wall -Wextar -Werror -std=c++98

all :		$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFALGS) $(OBJS) -o $(NAME)

$(OBJS) :	$(DIR_OBJS)

$(DIR_OBJS) :
			mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.cpp
			$(CC) $(CFALGS) -c $< -o $@

clean :
			$(RM) $(DIR_OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	clean fclean all re test
