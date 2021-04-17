/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:01:43 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:29:16 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(t_list **list, int num)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->content = num;
		new->next = NULL;
		if (*list)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
		{
			*list = new;
			return ;
		}
	}
}

int		sort_size(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		find_max(t_list *list, int skip)
{
	int	max;

	max = -2147483648;
	while (list->next)
	{
		if (list->content > max && list->content != skip)
			max = list->content;
		list = list->next;
	}
	if (list->content > max && list->content != skip)
		max = list->content;
	return (max);
}

int		find_min(t_list *list)
{
	int	min;

	min = 2147483647;
	while (list->next)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	if (list->content < min)
		min = list->content;
	return (min);
}

int		find_pos(int n, t_list *list)
{
	int	pos;

	pos = 0;
	while (list->content != n)
	{
		list = list->next;
		pos++;
	}
	return (pos);
}
