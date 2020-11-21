/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:49:50 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:37:49 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_pixel(t_all *all, double i)
{
	int	index;

	if (floor(all->hit.y) == all->hit.y)
	{
		index = 64 * floor(64 * i) + 64 * (all->hit.x - floor(all->hit.x));
		if (all->ray.w == 1)
			return (all->tex.s[index]);
		else if (all->ray.w == 0)
			return (all->tex.n[index]);
	}
	else if (floor(all->hit.x) == all->hit.x)
	{
		index = 64 * floor(64 * i) + 64 * (all->hit.y - floor(all->hit.y));
		if (all->ray.v == 1)
			return (all->tex.e[index]);
		else if (all->ray.v == 0)
			return (all->tex.w[index]);
	}
	return (BLACK);
}

void			ft_column(t_all *all, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	start = all->win.x * (all->win.y - size) / 2;
	if (size > all->win.y)
		count = (size - all->win.y) / 2;
	else
		count = 0;
	color = all->tex.c;
	while (all->ray.i < all->win.x * all->win.y)
	{
		if (all->ray.i >= start && count < size)
		{
			color = ft_pixel(all, (double)count / size);
			count++;
		}
		else if (count == size)
			color = all->tex.f;
		all->img.addr[all->ray.i] = mlx_get_color_value(all->mlx.ptr, color);
		all->ray.i += all->win.x;
	}
	all->ray.i -= all->win.x * all->win.y;
}

int				ft_size(t_all *all)
{
	double	cor;
	double	eye;

	eye = fabs((double)all->ray.i / (all->win.x / 2) - 1);
	eye *= 28 * M_PI / 180;
	cor = (double)all->hit.d * cos(eye);
	return (round(all->win.y / cor));
}

void			ft_stock(t_all *all)
{
	all->stk[all->ray.i].x = all->ray.x;
	all->stk[all->ray.i].y = all->ray.y;
	all->stk[all->ray.i].d = all->hit.d;
}
