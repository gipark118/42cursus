/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:26:17 by gipark            #+#    #+#             */
/*   Updated: 2021/01/07 21:09:41 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*remove;

	if (!(begin_list))
		return ;
	tmp = *begin_list;
	while (tmp && tmp->next)
	{
		if (!((*cmp)(tmp->next->data, data_ref)))
		{
			remove = tmp->next;
			tmp->next = remove->next;
			(*free_fct)(remove->data);
			free(remove);
			continue;
		}
		tmp = tmp->next;
	}
	tmp = *begin_list;
	if (!((*cmp)(tmp->data, data_ref)))
	{
		*begin_list = tmp->next;
		(*free_fct)(tmp->data);
		free(tmp);
	}
}
