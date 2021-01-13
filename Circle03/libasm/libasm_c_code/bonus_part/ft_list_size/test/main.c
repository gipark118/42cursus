/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:15:11 by gipark            #+#    #+#             */
/*   Updated: 2021/01/05 01:49:51 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

int			main(void)
{
	t_list	*list;
	int		count;

	count = 10;
	list = ft_create_elem(&count);
	while (count > 0)
	{
		count--;
		ft_list_push_front(&list, &count);
	}
	printf("list_size: %d\n", ft_list_size(list));
	return (0);
}
