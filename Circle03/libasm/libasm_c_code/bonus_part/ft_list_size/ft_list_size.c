/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:44:31 by gipark            #+#    #+#             */
/*   Updated: 2021/01/05 01:40:19 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		count;

	if (!(begin_list))
		return (0);
	count = 1;
	tmp = begin_list->next;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
