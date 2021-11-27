NAME		= ft_containers

DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/
SRCS		= 	main.cpp	\
				vector.cpp	\
				stack.cpp	\
				map.cpp
OBJS		= $(SRCS:%.cpp=$(DIR_OBJS)%.o)
INCS		= ./includes/

CC			= clang++
RM			= rm -rf
CCFLAGS		= -Wall -Wextra -Werror -std=c++98

all :		$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CCFLAGS) -I$(INCS) $(OBJS) -o $(NAME)

$(DIR_OBJS) :
			mkdir $(DIR_OBJS)

$(OBJS) :	$(DIR_OBJS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.cpp
			$(CC) $(CCFLAGS) -I$(INCS) -c $< -o $@

clean :
			$(RM) $(DIR_OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	clean fclean all re
