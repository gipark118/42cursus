/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:01:14 by gipark            #+#    #+#             */
/*   Updated: 2021/01/15 11:22:10 by gipark           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc >= 2 && !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen(argc, argv);
	printf("\n");
	printf(RED_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(GREEN_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(YELLOW_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(BLUE_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(MAGENTA_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(CYAN_COLOR "ft_strlen" COLOR_RESET "\n");
	return (0);
}
