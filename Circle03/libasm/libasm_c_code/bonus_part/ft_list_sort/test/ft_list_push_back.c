/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 03:28:44 by gipark            #+#    #+#             */
/*   Updated: 2021/01/05 03:48:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;
	t_list	*tmp;

	if (!(begin_list && data))
		return ;
	list = ft_create_elem(data);
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list;
}
