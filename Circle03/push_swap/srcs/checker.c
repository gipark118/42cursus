/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:39:04 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:51:52 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "ra")))
		ra(list_a, 0);
	else if (!(ft_strcmp(line, "rb")))
		rb(list_b, 0);
	else if (!(ft_strcmp(line, "rr")))
		rr(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "sa")))
		sa(*list_a, 0);
	else if (!(ft_strcmp(line, "sb")))
		sb(*list_b, 0);
	else if (!(ft_strcmp(line, "ss")))
		ss(*list_a, *list_b, 0);
	else if (!(ft_strcmp(line, "rra")))
		rra(list_a, 0);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(list_b, 0);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "pa")))
		pa(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "pb")))
		pb(list_a, list_b, 0);
	else
		return (0);
	return (1);
}

int	checker(t_list **list_a, t_list **list_b)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		if (!(split(line, list_a, list_b)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_info	*info;
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	if (!(list_a = init_list(argc, argv)))
		return (clear_all(list_a, info));
	if ((ret = checker(&list_a, &list_b)) == 0)
		return (clear_all(list_a, info));
	if (list_a && is_sort(list_a) && !list_b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (list_b)
		clear_list(list_b);
	clear_list(list_a);
	free(info);
	return (0);
}
