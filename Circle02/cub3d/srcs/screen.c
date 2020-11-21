/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:41:22 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:31:13 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_ray(t_all *all)
{
	double	angle;
	double	dist;

	angle = ((double)all->ray.i - (all->win.x / 2)) * 33 / (all->win.x / 2);
	angle = angle * M_PI / 180;
	all->ray.x = all->dir.x * cos(angle) - all->dir.y * sin(angle);
	all->ray.y = all->dir.y * cos(angle) + all->dir.x * sin(angle);
	dist = hypot(all->ray.x, all->ray.y);
	all->ray.x /= dist;
	all->ray.y /= dist;
}

void	ft_direction(t_all *all)
{
	if (all->ray.x >= 0)
		all->ray.v = 1;
	else
		all->ray.v = 0;
	if (all->ray.y >= 0)
		all->ray.w = 1;
	else
		all->ray.w = 0;
}

void	ft_vertical(t_all *all)
{
	double	x;
	double	y;

	x = floor(all->pos.x) + all->ray.v;
	y = all->pos.y + (x - all->pos.x) * (all->ray.y / all->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < all->map.y)
	{
		if (all->map.tab[(int)floor(y)][(int)(x - 1 + all->ray.v)] == '1')
		{
			all->hit.x = x;
			all->hit.y = y;
			all->hit.d = hypot(x - all->pos.x, y - all->pos.y);
			return ;
		}
		x += (2 * all->ray.v - 1);
		y += (2 * all->ray.v - 1) * all->ray.y / all->ray.x;
	}
	all->hit.x = all->pos.x;
	all->hit.y = all->pos.y;
	all->hit.d = 1000000000;
}

void	ft_horizon(t_all *all)
{
	double	y;
	double	x;

	y = floor(all->pos.y) + all->ray.w;
	x = all->pos.x + (y - all->pos.y) * (all->ray.x / all->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < all->map.x)
	{
		if (all->map.tab[(int)(y - 1 + all->ray.w)][(int)floor(x)] == '1')
		{
			if (all->hit.d > hypot(x - all->pos.x, y - all->pos.y))
			{
				all->hit.x = x;
				all->hit.y = y;
				all->hit.d = hypot(x - all->pos.x, y - all->pos.y);
			}
			return ;
		}
		y += (2 * all->ray.w - 1);
		x += (2 * all->ray.w - 1) * all->ray.x / all->ray.y;
	}
}

void	ft_screen(t_all *all)
{
	int		bpp;
	int		sl;
	int		end;

	all->img.ptr = mlx_new_image(all->mlx.ptr, all->win.x, all->win.y);
	all->img.addr = (unsigned int *)mlx_get_data_addr(all->img.ptr, &bpp, &sl, &end);
	all->stk = malloc(sizeof(t_stk) * all->win.x);
	while (all->ray.i < all->win.x)
	{
		ft_ray(all);
		ft_direction(all);
		ft_vertical(all);
		ft_horizon(all);
		ft_stock(all);
		ft_column(all, ft_size(all));
		all->ray.i++;
	}
	ft_sprite(all);
}
