/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:41:47 by gipark            #+#    #+#             */
/*   Updated: 2021/01/13 18:48:06 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		printf("Error\n");
		return (0);
	}
	printf("string1: %s\n", argv[1]);
	printf("string2: %s\n", argv[2]);
	printf("[Comparison]\n");
	printf("strcmp: %d\n", strcmp(argv[1], argv[2]));
	printf("ft_strcmp: %d\n", ft_strcmp(argv[1], argv[2]));
	return (0);
}
