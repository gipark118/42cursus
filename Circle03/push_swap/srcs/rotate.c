/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:55:40 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:27:56 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_a) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	cp = (*list_a)->next;
	while ((*list_a)->next)
		*list_a = (*list_a)->next;
	(*list_a)->next = tmp;
	tmp->next = NULL;
	*list_a = cp;
	if (p == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	cp = (*list_b)->next;
	while ((*list_b)->next)
		*list_b = (*list_b)->next;
	(*list_b)->next = tmp;
	tmp->next = NULL;
	*list_b = cp;
	if (p == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **list_a, t_list **list_b, int p)
{
	ra(list_a, 0);
	rb(list_b, 0);
	if (p == 1)
		write(1, "rr\n", 3);
}
