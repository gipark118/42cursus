/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:26:24 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:35:29 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_b(int size, t_list **list_a, t_list **list_b, t_info *info)
{
	int		j;
	int		i;

	i = 0;
	while (i++ < 2)
	{
		j = 0;
		if (find_pos(find_min(*list_a), *list_a) < size / 2)
			j = 1;
		while ((*list_a)->content != find_min(*list_a))
		{
			if (j)
				ra(list_a, info->p);
			else
				rra(list_a, info->p);
		}
		pb(list_a, list_b, info->p);
	}
}

void		short_resolve(t_list **list_a, t_info *info)
{
	int		size;
	t_list	*list_b;

	list_b = 0;
	size = sort_size(*list_a);
	if (is_sort(*list_a))
		return ;
	if (size > 3)
		push_b(size, list_a, &list_b, info);
	while (!is_sort(*list_a))
	{
		if ((*list_a)->content >= find_max(*list_a, 0))
			ra(list_a, info->p);
		else if ((*list_a)->content > (*list_a)->next->content)
			sa(*list_a, info->p);
		else
			ra(list_a, info->p);
	}
	if (size > 3)
	{
		pa(list_a, &list_b, info->p);
		pa(list_a, &list_b, info->p);
	}
}
