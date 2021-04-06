/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:32:35 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:32:36 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	**begin;
	t_list	*temp1;
	t_list	*temp3;

	if (!(begin = (t_list **)malloc(sizeof(t_list))))
		return (NULL);
	if (!(lst) || !(*begin = ft_lstnew(f(lst->content))) || f == NULL)
		return (NULL);
	lst = lst->next;
	temp1 = *begin;
	while (lst)
	{
		temp3 = temp1;
		if (!(temp1 = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(begin, del);
			return (NULL);
		}
		temp3->next = temp1;
		lst = lst->next;
	}
	temp1->next = NULL;
	return (*begin);
}
