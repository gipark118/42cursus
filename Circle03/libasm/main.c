/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:01:14 by gipark            #+#    #+#             */
/*   Updated: 2021/01/22 12:24:22 by gipark           ###   ########.fr       */
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
#define WHITE_COLOR		"\x1b[37m"
#define COLOR_RESET		"\x1b[0m"

void	test_ft_strlen(int argc, char **argv)
{
	int i;
	int	j;

	if (argc == 1)
		return ;
	printf(MAGENTA_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(BLUE_COLOR "[1] \"\"\n" COLOR_RESET);
	printf(CYAN_COLOR "strlen: %lu" COLOR_RESET "\n", strlen(""));
	printf(CYAN_COLOR "ft_strlen: %lu" COLOR_RESET "\n", ft_strlen(""));
	printf(BLUE_COLOR "[2] \"    \"\n" COLOR_RESET);
	printf(CYAN_COLOR "strlen: %lu" COLOR_RESET "\n", strlen("    "));
	printf(CYAN_COLOR "ft_strlen: %lu" COLOR_RESET "\n", ft_strlen("    "));
	i = 3;
	j = 2;
	while (argv[j] )
	{
		printf(BLUE_COLOR "[%d] %s\n" COLOR_RESET, i, argv[j]);
		printf(CYAN_COLOR "strlen: %lu" COLOR_RESET "\n", strlen(argv[j]));
		printf(CYAN_COLOR "ft_strlen: %lu" COLOR_RESET "\n", ft_strlen(argv[j]));
		i++;
		j++;
	}
}

void	test_ft_strcpy(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc % 2 != 0)
		return ;
	printf(MAGENTA_COLOR "ft_strcpy" COLOR_RESET "\n");
	i = 1;
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

void	test_ft_strcmp(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc % 2 != 0)
		return ;
	printf(MAGENTA_COLOR "ft_strcmp" COLOR_RESET "\n");
	i = 0;
	j = 2;
	while (argv[j])
	{
		printf(BLUE_COLOR "[%d] dst: %s, src: %s\n" COLOR_RESET, i, argv[j], argv[j + 1]);
		printf(CYAN_COLOR "strcmp: %d" COLOR_RESET "\n", strcmp(argv[j], argv[j + 1]));
		printf(CYAN_COLOR "ft_strcmp: %d" COLOR_RESET "\n", ft_strcmp(argv[j], argv[j + 1]));
		i++;
		j += 2;
	}
}

void	test_ft_write(int argc, char **argv)
{
	int	i;
	int	j;
	int	fd;
	char buf[100];

	if (argc == 1)
		return ;
	printf(MAGENTA_COLOR "ft_write" COLOR_RESET "\n");
	printf(BLUE_COLOR "[1] %s (wrong fd)\n" COLOR_RESET, "Aseembly");
	printf(CYAN_COLOR "write: %zd" COLOR_RESET "\n", write(-1, "Aseembly", strlen("Aseembly")));
	printf(CYAN_COLOR "ft_write: %zd" COLOR_RESET "\n", ft_write(-1, "Aseembly", ft_strlen("Aseembly")));
	fd = open("testfile", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf(BLUE_COLOR "[2] %s (open fd) | " COLOR_RESET, "Assembly");
	printf(BLUE_COLOR "open(\"testfile\", O_WRONLY), Assembly\n" COLOR_RESET);
	write(fd, "Assembly", 8);
	ft_write(fd, "Assembly", 8);
	close(fd);
	fd = open("testfile", O_RDONLY);
	read(fd, buf, 8);
	printf(CYAN_COLOR "write: %zd\n" COLOR_RESET, write(1, buf, 8));
	read(fd, buf, 8);
	printf(CYAN_COLOR "ft_write: %zd\n" COLOR_RESET, ft_write(1, buf, 8));
	close(fd);
	remove("testfile");
	i = 3;
	j = 2;
	while (argv[j])
	{
		printf(BLUE_COLOR "[%d] %s\n" COLOR_RESET, i, argv[j]);
		printf(CYAN_COLOR "write: %zd" COLOR_RESET "\n", write(1, argv[j], strlen(argv[j])));
		printf(CYAN_COLOR "ft_write: %zd" COLOR_RESET "\n", ft_write(1, argv[j], ft_strlen(argv[j])));
		i++;
		j++;
	}
}

void	test_ft_read()
{
	int	fd;
	char buf[1024];
	char str[1024];
	ssize_t	ret;

	printf(MAGENTA_COLOR "ft_read" COLOR_RESET "\n");
	printf(BLUE_COLOR "[1] libasm.h" COLOR_RESET "\n");
	fd = open("includes/libasm.h", O_RDONLY);
	ret = read(fd, buf, 10);
	printf(CYAN_COLOR "read: %zd, %s\n" COLOR_RESET, ret, strncpy(str, buf, 10));
	close(fd);
	fd = open("includes/libasm.h", O_RDONLY);
	ret = ft_read(fd, buf, 10);
	printf(CYAN_COLOR "ft_read: %zd, %s\n" COLOR_RESET, ret, strncpy(str, buf, 10));
	close(fd);
	printf(BLUE_COLOR "[2] srcs/mandatory/ft_read.s" COLOR_RESET "\n");
	fd = open("srcs/mandatory/ft_read.s", O_RDONLY);
	ret = read(fd, buf, 10);
	printf(CYAN_COLOR "read: %zd, %s\n" COLOR_RESET, ret, strncpy(str, buf, 10));
	close(fd);
	fd = open("srcs/mandatory/ft_read.s", O_RDONLY);
	ret = ft_read(fd, buf, 10);
	printf(CYAN_COLOR "ft_read: %zd, %s\n" COLOR_RESET, ret, strncpy(str, buf, 10));
	printf(BLUE_COLOR "[3] Makefile" COLOR_RESET "\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buf, 10);
	printf(CYAN_COLOR "read: %zd, %s\n" COLOR_RESET, ret, strncpy(str, buf, 10));
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buf, 10);
	printf(CYAN_COLOR "ft_read: %zd, %s\n" COLOR_RESET, ret, strncpy(str, buf, 10));
	printf(BLUE_COLOR "[4] main.c (wrong fd)" COLOR_RESET "\n");
	ret = read(-1, buf, 10);
	printf(CYAN_COLOR "read: %zd\n" COLOR_RESET, ret);
	ret = ft_read(-1, buf, 10);
	printf(CYAN_COLOR "ft_read: %zd\n" COLOR_RESET, ret);
}

void	test_ft_strdup(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return ;
	printf(MAGENTA_COLOR "ft_strdup" COLOR_RESET "\n");
	i = 0;
	j = 2;
	while (argv[j])
	{
		printf(BLUE_COLOR "[%d] %s\n" COLOR_RESET, i, argv[j]);
		printf(CYAN_COLOR "strdup: %s" COLOR_RESET "\n", strdup(argv[j]));
		printf(CYAN_COLOR "ft_strdup: %s" COLOR_RESET "\n", ft_strdup(argv[j]));
		i++;
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc >= 2 && !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen(argc, argv);
	if ((argc % 2 == 0) && !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy(argc, argv);
	if ((argc % 2 == 0) && !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp(argc, argv);
	if (argc >= 2 && !strcmp(argv[1], "ft_write"))
		test_ft_write(argc, argv);
	if (argc == 2 && !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc >= 2 && !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup(argc, argv);
	printf("\n");
	printf("=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-\n");
	printf(WHITE_COLOR "[MANUAL]\n");
	printf("./execute.out [function name] [argument1] [argument2] [argument3] ...\n" COLOR_RESET);
	printf(RED_COLOR "ft_strlen" COLOR_RESET "\n");
	printf(RED_COLOR "-> Input string" COLOR_RESET "\n");
	printf(GREEN_COLOR "ft_strcpy" COLOR_RESET "\n");
	printf(GREEN_COLOR "-> Be required an even number of arguments" COLOR_RESET "\n");
	printf(YELLOW_COLOR "ft_strcmp" COLOR_RESET "\n");
	printf(YELLOW_COLOR "-> Be required an even number of arguments" COLOR_RESET "\n");
	printf(BLUE_COLOR "ft_write" COLOR_RESET "\n");
	printf(BLUE_COLOR "-> Input string" COLOR_RESET "\n");
	printf(MAGENTA_COLOR "ft_read" COLOR_RESET "\n");
	printf(MAGENTA_COLOR "-> Nothing (Only ./test ft_read)" COLOR_RESET "\n");
	printf(CYAN_COLOR "ft_strdup" COLOR_RESET "\n");
	printf(CYAN_COLOR "-> Input string" COLOR_RESET "\n");
	return (0);
}
