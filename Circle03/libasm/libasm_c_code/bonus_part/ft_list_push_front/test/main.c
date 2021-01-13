/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:15:11 by gipark            #+#    #+#             */
/*   Updated: 2021/01/05 02:55:08 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
/*
int			main(void)
{
	t_list	*begin_list;
	int		data1;
	int		data2;

	data1 = 10;
	data2 = 20;
	begin_list = ft_create_elem(&data1);
	ft_list_push_front(&begin_list, &data2);
	printf("begin_list->next: %p\n", begin_list->next);
	printf("begin_list->data: %d\n", *((int *)begin_list->data));
	printf("begin_list->next->next: %p\n", begin_list->next->next);
	printf("begin_list->next->data: %d\n", *((int *)begin_list->next->data));
	return (0);
}
*/

int			main(void)
{
	t_list	*list;
	t_list	*tmp;
	int		count;
	int		*convert_count;
	int		i;

	count = 10;
	convert_count = malloc(sizeof(int));
	*convert_count = count;
	list = ft_create_elem(convert_count);
	while (count > 0)
	{
		count--;
		convert_count = malloc(sizeof(int));
		*convert_count = count;
		ft_list_push_front(&list, convert_count);
	}
	tmp = list;
	i = 1;
	while (tmp)
	{
		printf("%d:tmp->data: %d\n", i++, *((int *)tmp->data));
		tmp = tmp->next;
	}
	return (0);
}
