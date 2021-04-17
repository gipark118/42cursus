/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:12:56 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:28:18 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list_a, int p)
{
	if (!list_a)
		return ;
	if (list_a->next)
	{
		ft_swap(&list_a->content, &list_a->next->content);
		if (p == 1)
			ft_putstr("sa\n");
	}
}

void	sb(t_list *list_b, int p)
{
	if (!list_b)
		return ;
	if (list_b->next)
	{
		ft_swap(&list_b->content, &list_b->next->content);
		if (p == 1)
			ft_putstr("sb\n");
	}
}

void	ss(t_list *list_a, t_list *list_b, int p)
{
	sa(list_a, 0);
	sb(list_b, 0);
	if (p == 1)
		ft_putstr("ss\n");
}
