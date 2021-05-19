# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 06:40:15 by gipark            #+#    #+#              #
#    Updated: 2021/05/18 20:11:00 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= convert

DIR_SRCS	= ./
DIR_OBJS	= ./objs/
SRCS		= main.cpp
OBJS		= $(SRCS:%.cpp=$(DIR_OBJS)%.o)

CC			= clang++
RM			= rm -rf
CFLAGS		= -Wall -Wextar -Werror

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

test :		$(NAME)
			./convert 0
			./convert nan
			./convert 42.0f

.PHONY :	clean fclean all re test
