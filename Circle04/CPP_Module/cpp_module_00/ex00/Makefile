# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 06:45:21 by gipark            #+#    #+#              #
#    Updated: 2021/05/11 07:32:06 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

DIR_SRCS	= ./
DIR_OBJS	= ./objs/
SRCS		= megaphone.cpp
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

test :		$(NAME)
			./megaphone "shhhhh... I think the students are asleep..."
			./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
			./megaphone

.PHONY :	clean fclean all re test
