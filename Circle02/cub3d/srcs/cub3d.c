/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:29:02 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:38:36 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw(t_all *all)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	all->ray = ray;
	all->hit = hit;
	ft_screen(all);
	mlx_put_image_to_window(all->mlx.ptr, all->win.ptr, all->img.ptr, 0, 0);
	free(all->img.ptr);
	free(all->img.addr);
}

int		ft_cub3d(t_all all, char *cub, int bmp)
{
	t_pos	pos;
	t_dir	dir;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	all.pos = pos;
	all.dir = dir;
	all.mlx.ptr = mlx_init();
	if (ft_parse(&all, cub) == -1)
		return (ft_close(&all, 0));
	if (bmp == 1)
		return (ft_bmp(&all));
	ft_rotate(&all, 1);
	ft_move(&all, 1);
	ft_rotate(&all, -1);
	ft_move(&all, -1);
	all.win.ptr = mlx_new_window(all.mlx.ptr, all.win.x, all.win.y, "cub3D");
	ft_draw(&all);
	mlx_hook(all.win.ptr, X_EVENT_KEY_PRESS, 0, ft_deal_key, &all);
	mlx_hook(all.win.ptr, X_EVENT_KEY_EXIT, 0, ft_close, &all);
	mlx_loop(all.mlx.ptr);
	return (1);
}

void	ft_init_v2(t_all all, char *cub, int bmp)
{
	t_map	map;
	t_tex	tex;
	t_spr	*spr;
	t_stk	*stk;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	spr = NULL;
	stk = NULL;
	map.x = 0;
	map.y = 0;
	map.spr = 0;
	tex.c = NONE;
	tex.f = NONE;
	all.map = map;
	all.tex = tex;
	all.spr = spr;
	all.stk = stk;
	ft_cub3d(all, cub, bmp);
}

void	ft_init(char *cub, int bmp)
{
	t_all	all;
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;

	mlx.ptr = NULL;
	win.ptr = NULL;
	img.ptr = NULL;
	img.addr = NULL;
	win.x = 0;
	win.y = 0;
	img.fsh = 0;
	err.n = 0;
	err.m = 0;
	err.p = 0;
	all.mlx = mlx;
	all.win = win;
	all.img = img;
	all.err = err;
	ft_init_v2(all, cub, bmp);
}

int		main(int argc, char **argv)
{
	if (argc == 3 && ft_file_check(argv[1], "cub") && ft_save_check(argv[2], "--save"))
		ft_init(argv[1], 1);
	else if (argc == 2 && ft_file_check(argv[1], "cub"))
		ft_init(argv[1], 0);
	else
		write(2, ERROR_00, 27);
	return (0);
}
