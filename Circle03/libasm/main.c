/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:01:14 by gipark            #+#    #+#             */
/*   Updated: 2021/01/15 13:13:05 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"

#define RED_COLOR		"\x1b[31m"
#define GREEN_COLOR		"\x1b[32m"
#define YELLOW_COLOR	"\x1b[33m"
#define BLUE_COLOR		"\x1b[34m"
#define MAGENTA_COLOR	"\x1b[35m"
#define CYAN_COLOR		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

void	test_ft_strlen(int argc, char **argv)
{
	int i;
	int	j;

	printf(MAGENTA_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(BLUE_COLOR "[1] \"\"\n" COLOR_RESET);
	printf(CYAN_COLOR "strlen: %d" COLOR_RESET "\n", strlen(""));
	printf(CYAN_COLOR "ft_strlen: %d" COLOR_RESET "\n", ft_strlen(""));
	printf(BLUE_COLOR "[2] \"    \"\n" COLOR_RESET);
	printf(CYAN_COLOR "strlen: %d" COLOR_RESET "\n", strlen("    "));
	printf(CYAN_COLOR "ft_strlen: %d" COLOR_RESET "\n", ft_strlen("    "));
	i = 3;
	j = 2;
	while (argv[j] )
	{
		printf(BLUE_COLOR "[%d] %s\n" COLOR_RESET, i, argv[j]);
		printf(CYAN_COLOR "strlen: %d" COLOR_RESET "\n", strlen(argv[j]));
		printf(CYAN_COLOR "ft_strlen: %d" COLOR_RESET "\n", ft_strlen(argv[j]));
		i++;
		j++;
	}
}

void	test_ft_strcpy(int argc, char **argv)
{
	int	i;
	int	j;

	printf(MAGENTA_COLOR "ft_strcpy" COLOR_RESET "\n");
	i = 0;
	j = 2;
	while (argv[j])
	{
		printf(BLUE_COLOR "[%d] dst: %s, src: %s\n" COLOR_RESET, i, argv[j], argv[j + 1]);
		printf(CYAN_COLOR "strcpy: %s" COLOR_RESET "\n", strcpy(argv[j], argv[j + 1]));
		printf(CYAN_COLOR "ft_strcpy: %s" COLOR_RESET "\n", ft_strcpy(argv[j], argv[j + 1]));
		i++;
		j += 2;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc >= 2 && !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen(argc, argv);
	if ((argc % 2 == 0) && !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy(argc, argv);
	printf("\n");
	printf(RED_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(GREEN_COLOR "ft_strcpy" COLOR_RESET "\n");
	printf(GREEN_COLOR "-> Be required an even number of arguments" COLOR_RESET "\n");
	printf(YELLOW_COLOR "ft_strcmp" COLOR_RESET "\n");
	printf(BLUE_COLOR "ft_write" COLOR_RESET "\n");
	printf(MAGENTA_COLOR "ft_read" COLOR_RESET "\n");
	printf(CYAN_COLOR "ft_strdup" COLOR_RESET "\n");
	return (0);
}
