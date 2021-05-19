# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 07:35:18 by gipark            #+#    #+#              #
#    Updated: 2021/05/12 03:50:48 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/
SRCS		= main.cpp		\
			  Contact.cpp	\
			  PhoneBook.cpp

OBJS		= $(SRCS:%.cpp=$(DIR_OBJS)%.o)
INCS		= ./includes/

CC			= clang++
RM			= rm -rf
CFLAGS		= -Wall -Wextar -Werror -std=c++98

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
			$(RM) $(NAME)

re :		fclean all

.PHONY :	clean fclean all re
