/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:15:11 by gipark            #+#    #+#             */
/*   Updated: 2021/01/08 01:03:35 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int			compare_number(void *data, void *data2)
{
	if (*(int *)data < *(int *)data2)
		return (0);
	else
		return (1);
}

int			main(void)
{
	t_list	*list;
	t_list	*tmp;
	int		count;
	int		*convert_count;
	int		i;

	count = 10;
	convert_count = (int *)malloc(sizeof(int));
	*convert_count = count;
	list = ft_create_elem(convert_count);
	while (count > 0)
	{
		count--;
		convert_count = (int *)malloc(sizeof(int));
		*convert_count = count;
		ft_list_push_back(&list, convert_count);
	}
	tmp = list;
	i = 0;
	while (tmp)
	{
		printf("%d:list->data: %d\n", i++, *((int *)tmp->data));
		tmp = tmp->next;
	}
	//printf("%d:list->data: %d\n", i, *((int *)tmp->data));
	printf("\n");
	printf("[[SORT]]\n");
	ft_list_sort(&list, &compare_number);
	tmp = list;
	i = 0;
	while (tmp)
	{
		printf("Sorted list[%d]: %d\n", i++, *((int *)tmp->data));
		tmp = tmp->next;
	}
	return (0);
}
