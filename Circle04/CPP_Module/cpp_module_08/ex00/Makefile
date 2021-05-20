# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 06:43:06 by gipark            #+#    #+#              #
#    Updated: 2021/05/20 11:33:34 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= easyfind

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
