/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:31:53 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:32:00 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **begin_list, void *data, int (*cmp)(),
			void (*del)())
{
	t_list	*current;
	t_list	*next;

	if (!*begin_list)
		return ;
	while (*begin_list && cmp((*begin_list)->content, data) == 0)
	{
		next = (*begin_list)->next;
		del(*begin_list);
		*begin_list = next;
	}
	if (!*begin_list)
		return ;
	current = *begin_list;
	while (current && current->next)
	{
		if (cmp(current->next->content, data) == 0)
		{
			next = current->next->next;
			del(current->next);
			current->next = next;
		}
		else
			current = current->next;
	}
}
