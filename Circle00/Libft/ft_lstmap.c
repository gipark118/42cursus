/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:19:01 by gipark            #+#    #+#             */
/*   Updated: 2020/04/11 16:45:23 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *head;
	t_list *next;

	if (lst)
	{
		tmp = lst;
		if (!(head = ft_lstnew(f(tmp->content))))
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			if (!(next = ft_lstnew(f(tmp->content))))
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, next);
			tmp = tmp->next;
		}
		return (head);
	}
	return (NULL);
}
