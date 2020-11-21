/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:09:08 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 02:32:02 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_close(t_all *all, int win)
{
	int	i;

	i = 0;
	while (i < all->map.y)
		free(all->map.tab[i++]);
	free(all->map.tab);
	free(all->tex.n);
	free(all->tex.s);
	free(all->tex.e);
	free(all->tex.w);
	free(all->tex.i);
	if (win == 1)
		mlx_destroy_window(all->mlx.ptr, all->win.ptr);
	free(all->mlx.ptr);
	exit(0);
	return (1);
}

void	ft_move(t_all *all, double c)
{
	all->pos.x += c * (all->dir.x * SPEED / 100);
	if (all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] == '1')
		all->pos.x -= c * (all->dir.x * SPEED / 100);
	all->pos.y += c * (all->dir.y * SPEED / 100);
	if (all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] == '1')
		all->pos.y -= c * (all->dir.y * SPEED / 100);
	if (all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] == '2')
	{
		all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] = '0';
		all->map.spr--;
		ft_all_list(all);
	}
}

void	ft_move_side(t_all *all, double c)
{
	all->pos.x -= c * (all->dir.y * SPEED / 100);
	if (all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] == '1')
		all->pos.x += c * (all->dir.y * SPEED / 100);
	all->pos.y += c * (all->dir.x * SPEED / 100);
	if (all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] == '1')
		all->pos.y -= c * (all->dir.x * SPEED / 100);
	if (all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] == '2')
	{
		all->map.tab[(int)floor(all->pos.y)][(int)floor(all->pos.x)] = '0';
		all->map.spr--;
		ft_all_list(all);
	}
}

void	ft_rotate(t_all *all, double c)
{
	double	dist;

	all->dir.x = all->dir.x * cos(c * TURN) - all->dir.y * sin(c * TURN);
	all->dir.y = all->dir.y * cos(c * TURN) + all->dir.x * sin(c * TURN);
	dist = hypot(all->dir.x, all->dir.y);
	all->dir.x /= dist;
	all->dir.y /= dist;
}

int		ft_deal_key(int key, void *arg)
{
	if (key == ESC)
		ft_close(arg, 1);
	else if (key == W)
		ft_move(arg, 1);
	else if (key == A)
		ft_move_side(arg, -1);
	else if (key == S)
		ft_move(arg, -1);
	else if (key == D)
		ft_move_side(arg, 1);
	else if (key == LEFT)
		ft_rotate(arg, -1);
	else if (key == RIGHT)
		ft_rotate(arg, 1);
	ft_draw(arg);
	return (1);
}
