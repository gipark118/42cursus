/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:14:57 by gipark            #+#    #+#             */
/*   Updated: 2020/11/21 23:20:31 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bmp_data(t_all *all, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = all->win.x * (all->win.y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < all->win.x)
		{
			buffer[0] = (unsigned char)(all->img.addr[i] % 256);
			buffer[1] = (unsigned char)(all->img.addr[i] / 256 % 256);
			buffer[2] = (unsigned char)(all->img.addr[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * all->win.x;
	}
}

void	ft_bmp_info(t_all *all, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = all->win.x;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = all->win.y;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bmp_file(t_all *all, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = all->win.x * all->win.y * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	ft_bmp_draw(t_all *all)
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
}

int		ft_bmp(t_all *all)
{
	int		fd;

	ft_bmp_draw(all);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bmp_file(all, fd);
	ft_bmp_info(all, fd);
	ft_bmp_data(all, fd);
	close(fd);
	free(all->img.ptr);
	free(all->img.addr);
	ft_close(all, 0);
	return (1);
}
