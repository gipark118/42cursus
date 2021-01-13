/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:41:47 by gipark            #+#    #+#             */
/*   Updated: 2021/01/13 18:07:45 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argc--)
	{
		printf("string: %s, strlen: %lu\n", argv[i], strlen(argv[i]));
		printf("string: %s, ft_strlen: %lu\n", argv[i], ft_strlen(argv[i]));
		i++;
	}
	return (0);
}
