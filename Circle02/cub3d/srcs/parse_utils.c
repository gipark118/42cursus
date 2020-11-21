/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:54:33 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:25:29 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_resolution(t_all *all, char *line, int *i)
{
	if (all->win.x != 0 || all->win.y != 0)
		return (-3);
	(*i)++;
	all->win.x = ft_atoi(line, i);
	all->win.y = ft_atoi(line, i);
	if (all->win.x > 2560)
		all->win.x = 2560;
	if (all->win.y > 1400)
		all->win.y = 1400;
	ft_whitespace(line, i);
	if (all->win.x <= 0 || all->win.y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}

int		ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (-5);
	(*i)++;
	r = ft_atoi(line, i);
	(*i)++;
	g = ft_atoi(line, i);
	(*i)++;
	b = ft_atoi(line, i);
	ft_whitespace(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

void	ft_position(t_all *all)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < all->map.y)
	{
		while (++j < all->map.x)
		{
			c = all->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				all->pos.y = (double)i + 0.5;
				all->pos.x = (double)j + 0.5;
				all->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				all->dir.x *= (c == 'W') ? -1 : 1;
				all->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				all->dir.y *= (c == 'N') ? -1 : 1;
				all->err.p++;
			}
		}
		j = -1;
	}
}

int		ft_all_list(t_all *all)
{
	int		i;
	int		j;
	int		k;

	if (all->spr != NULL)
		free(all->spr);
	if (!(all->spr = malloc(sizeof(t_spr) * all->map.spr)))
		return (-1);
	i = 0;
	j = 0;
	while (j < all->map.y)
	{
		k = 0;
		while (k < all->map.x)
		{
			if (all->map.tab[j][k] == '2')
			{
				all->spr[i].y = (double)j + 0.5;
				all->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}
