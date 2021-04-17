/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:07:20 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:51:38 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_arg(char *s, int i)
{
	int	len;

	while (s[i])
	{
		len = 0;
		if (((!ft_isdigit(s[i]) && (s[i] != '-' && s[i] != '+')) ||
				(s[i] == '-' && (!ft_isdigit(s[i + 1]))) || ((s[i] == '-'
				|| s[i] == '+') && (s[i + 1] == '+' || s[i + 1] == '-'))))
			return (0);
		while (ft_isdigit(s[i]))
		{
			len++;
			if (len == 10 && ((s[i] > '7' || ft_isdigit(s[i + 1])) &&
						s[i - len] != '-'))
				return (0);
			if (len == 10 && ((s[i] > '8' || ft_isdigit(s[i + 1])) &&
						s[i - len] == '-'))
				return (0);
			i++;
		}
		if (((s[i] == ' ' || ((s[i] == '-') && ft_isdigit(s[i + 1])) ||
						((s[i] == '+') && ft_isdigit(s[i + 1]))) && s[i + 1]))
			i++;
	}
	return (1);
}

int		check_dup(t_list *list)
{
	int		num;
	t_list	*tmp;

	num = list->content;
	tmp = list;
	while (list->next)
	{
		list = list->next;
		if (list->content == num)
			return (0);
	}
	if (tmp->next)
		if (!(check_dup(tmp->next)))
			return (0);
	return (1);
}

t_list	*check_list(t_list *list, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			add_list(&list, ft_atoi(&argv[i][j]));
			while (ft_isdigit(argv[i][j]) || argv[i][j] == '-' ||
					argv[i][j] == '+')
				j++;
			if (argv[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (list);
}

t_list	*init_list(int argc, char **argv)
{
	t_list	*list;
	int		i;

	i = 1;
	list = NULL;
	while (i < argc)
	{
		if (!(check_arg(argv[i], 0)) || !argv[1][0])
			return (0);
		i++;
	}
	list = check_list(list, argc, argv);
	if (!(check_dup(list)))
	{
		clear_list(list);
		return (NULL);
	}
	return (list);
}
