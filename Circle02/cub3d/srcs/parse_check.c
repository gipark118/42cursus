/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 06:07:11 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:18:15 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_save_check(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i] == save[i])
	{
		if (arg[i] == '\0' && save[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_file_check(char *arg, char *cub)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == cub[2] && arg[i - 2] == cub[1])
		&& (arg[i - 3] == cub[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}

int		ft_map_check(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < all->map.y)
	{
		j = 0;
		while (j < all->map.x)
		{
			if (all->map.tab[i][j] != '1' && i == 0)
				return (-1);
			else if (all->map.tab[i][j] != '1' && i == all->map.y - 1)
				return (-1);
			else if (all->map.tab[i][j] != '1' && j == 0)
				return (-1);
			else if (all->map.tab[i][j] != '1' && j == all->map.x - 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_parse_check(t_all *all)
{
	if (all->win.x <= 0 || all->win.y <= 0)
		return (ft_strerror(-14));
	else if ((all->tex.n == NULL || all->tex.s == NULL || all->tex.e == NULL)
			|| (all->tex.w == NULL || all->tex.i == NULL))
		return (ft_strerror(-15));
	else if (all->tex.c == NONE || all->tex.f == NONE)
		return (ft_strerror(-16));
	else if (all->err.p == 0)
		return (ft_strerror(-17));
	else if (all->err.p > 1)
		return (ft_strerror(-18));
	else if (ft_map_check(all) == -1)
		return (ft_strerror(-19));
	return (1);
}
