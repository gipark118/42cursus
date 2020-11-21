/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:57:11 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:44:34 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_all_pixel(t_all *all, int index, unsigned int col)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (col >= NONE)
		return (all->img.addr[index]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256);
	g = (col / 256 % 256) * (1 - (double)t / 256);
	b = (col % 256) * (1 - (double)t / 256);
	r += (all->img.addr[index] / (256 * 256) % 256) * ((double)t / 256);
	g += (all->img.addr[index] / 256 % 256) * ((double)t / 256);
	b += (all->img.addr[index] % 256) * ((double)t / 256);
	return (r * 256 * 256 + g * 256 + b);
}

void			ft_all_draw(t_all *all, int loc, double dist)
{
	unsigned int	col;
	double			size;
	int				index;
	int				i;
	int				j;

	i = 0;
	j = 0;
	size = all->win.y / dist / 2;
	loc = loc - size / 2;
	while (i < size)
	{
		while ((loc + i >= 0 && loc + i < all->win.x) &&
				(j < size && all->stk[loc + i].d > dist))
		{
			col = 64 * floor(64 * (double)j / size) + (double)i / size * 64;
			col = all->tex.i[col];
			index = loc + i + (all->win.y / 2 + j) * all->win.x;
			if (index < all->win.x * all->win.y)
				all->img.addr[index] = ft_all_pixel(all, index, col);
			j++;
		}
		i++;
		j = 0;
	}
}

void			ft_all_locate(t_all *all, double dirx, double diry, double dist)
{
	double	angle;

	dirx = (dirx - all->pos.x) / dist;
	diry = (diry - all->pos.y) / dist;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = all->dir.a - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	ft_all_draw(all, angle * all->win.x / 66, dist);
}

void			ft_all_order(t_all *all)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < all->map.spr - 1)
	{
		j = i + 1;
		while (j < all->map.spr)
		{
			if (all->spr[i].d < all->spr[j].d)
			{
				tmp = all->spr[i];
				all->spr[i] = all->spr[j];
				all->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			ft_sprite(t_all *all)
{
	int		i;
	double	dist;

	dist = hypot(all->dir.x, all->dir.y);
	if (all->dir.y <= 0)
		all->dir.a = acos(all->dir.x / dist) * 180 / M_PI;
	else
		all->dir.a = 360 - acos(all->dir.x / dist) * 180 / M_PI;
	i = 0;
	while (i < all->map.spr)
	{
		all->spr[i].d = hypot(all->spr[i].x - all->pos.x, all->spr[i].y - all->pos.y);
		i++;
	}
	ft_all_order(all);
	i = 0;
	while (i < all->map.spr)
	{
		ft_all_locate(all, all->spr[i].x, all->spr[i].y, all->spr[i].d);
		i++;
	}
	free(all->stk);
}
