/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:34:40 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:52:35 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_algo(t_list **list_a, t_info *info)
{
	if (sort_size(*list_a) > 8)
	{
		if (!(resolve(list_a, info)))
			return (0);
	}
	else
		short_resolve(list_a, info);
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*list_a;
	t_info	*info;

	if (argc < 2)
		return (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	info->p = 1;
	if (!(list_a = init_list(argc, argv)))
	{
		free(info);
		return (write(2, "Error\n", 6));
	}
	sort_algo(&list_a, info);
	clear_list(list_a);
	free(info);
	return (0);
}
