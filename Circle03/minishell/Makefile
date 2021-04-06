# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjoo <hjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 23:04:51 by hjoo              #+#    #+#              #
#    Updated: 2021/02/05 14:31:57 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRCS_LIST		= \
					main.c \
					\
					env/env_utils.c \
					env/env_utils2.c \
					\
					parsing/token.c \
					parsing/token2.c \
					parsing/cmds.c \
					parsing/bin_path.c \
					parsing/parsing_token.c \
					parsing/parsing_cmds.c \
					\
					commands/echo.c \
					commands/cd.c \
					commands/exit.c \
					commands/env.c \
					commands/pwd.c \
					commands/unset.c \
					commands/export.c \
					\
					utils/redirect.c \
					utils/command_process.c \
					utils/command_process2.c \
					utils/free_utils.c \
					utils/utils.c \
					utils/utils2.c \
					utils/quotes.c \
					utils/gnl_no_eof.c\
					utils/exec.c \
					utils/signals.c \
					utils/errors.c \

SRCS_FOLDER		= srcs

SRCS			= $(addprefix ${SRCS_FOLDER}/, ${SRCS_LIST})
OBJS			= ${SRCS:.c=.o}

HEADER			= includes

LIBFT 			= libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
LFLAGS			= -L libft -lft -lncurses

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -j -C $(LIBFT)
				@$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

%.o: %.c
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS)
				@make clean -C $(LIBFT)

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean
				@make -j

.PHONY: 		all fclean clean re bonus
