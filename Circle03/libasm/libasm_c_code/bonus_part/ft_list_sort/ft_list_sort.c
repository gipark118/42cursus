/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:04:44 by gipark            #+#    #+#             */
/*   Updated: 2021/01/08 00:57:33 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	int		swap;

	if (!(begin_list))
		return ;
	swap = 1;
	while (swap)
	{
		swap = 0;
		tmp = *begin_list;
		while (tmp->next)
		{
			if ((*cmp)(tmp->data, tmp->next->data))
			{
				ft_swap(&(tmp->data), &(tmp->next->data));
				swap = 1;
			}
			tmp = tmp->next;
		}
	}
}
