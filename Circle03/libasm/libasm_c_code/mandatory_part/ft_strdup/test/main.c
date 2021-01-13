/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:41:47 by gipark            #+#    #+#             */
/*   Updated: 2021/01/13 19:47:46 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	printf("string: %s\n", argv[1]);
	printf("string_addr: %p\n", argv[1]);
	printf("[Duplicate]\n");
	printf("strdup: %s\n", strdup(argv[1]));
	printf("strdup_addr: %p\n", strdup(argv[1]));
	printf("ft_strdup: %s\n", ft_strdup(argv[1]));
	printf("ft_strdup_addr: %p\n", ft_strdup(argv[1]));
	return (0);
}
