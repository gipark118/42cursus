/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:15:11 by gipark            #+#    #+#             */
/*   Updated: 2021/01/07 21:12:42 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void		ft_delprint(void *data)
{
	printf("delprint: %d\n", *((int *)data));
	return ;
}

int			compare_data_ref(void *data, void *data_ref)
{
	int comp;

	comp = *((int *)data) % *((int *)data_ref);
	return (comp);
}

int			main(void)
{
	t_list	*list;
	t_list	*tmp;
	int		count;
	int		*convert_count;
	int		i;
	int		*data_ref;

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
	printf("[[APPLY]]\n");
	data_ref = (int *)malloc(sizeof(int));
	*data_ref = 2;
	ft_list_remove_if(&list, data_ref, &compare_data_ref, &ft_delprint);
	tmp = list;
	i = 0;
	while (tmp)
	{
		printf("%d:list->data: %d\n", i++, *((int *)tmp->data));
		tmp = tmp->next;
	}
	return (0);
}
