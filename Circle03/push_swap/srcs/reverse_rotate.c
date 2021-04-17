/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:02:35 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:27:42 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list_a, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	tmp = *list_a;
	cp = *list_a;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list_a;
	*list_a = tmp;
	if (p == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	cp = *list_b;
	if (!(*list_b))
		return ;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list_b;
	*list_b = tmp;
	if (p == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b, int p)
{
	rra(list_a, 0);
	rrb(list_b, 0);
	if (p == 1)
		write(1, "rrr\n", 4);
}
