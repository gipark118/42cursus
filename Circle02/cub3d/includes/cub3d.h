/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:09:30 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:32:50 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define ERROR_00 "ERROR :: Invalid arguments\n"
# define ERROR_01 "ERROR :: Need to open file\n"
# define ERROR_02 "ERROR :: File needs to be parsed\n"
# define ERROR_03 "ERROR :: Resolution specified more than once\n"
# define ERROR_04 "ERROR :: Invalid resolution\n"
# define ERROR_05 "ERROR :: Floor or Ceiling specified more than once\n"
# define ERROR_06 "ERROR :: Invalid floor or ceiling\n"
# define ERROR_07 "ERROR :: Texture path specified more than once\n"
# define ERROR_08 "ERROR :: Malloc fail (texture)\n"
# define ERROR_09 "ERROR :: Invalid texture image\n"
# define ERROR_10 "ERROR :: Invalid line in .cub\n"
# define ERROR_11 "ERROR :: Malloc fail (map)\n"
# define ERROR_12 "ERROR :: Invalid map\n"
# define ERROR_13 "ERROR :: Map must be rectangle\n"
# define ERROR_14 "ERROR :: No resolution\n"
# define ERROR_15 "ERROR :: No texture\n"
# define ERROR_16 "ERROR :: No floor or ceiling\n"
# define ERROR_17 "ERROR :: No player\n"
# define ERROR_18 "ERROR :: Multiple players\n"
# define ERROR_19 "ERROR :: Map must be surrounded by walls\n"

# define NONE 0xFF000000
# define BLACK 0x00000000

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 20
# define TURN 0.07

typedef struct	s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*addr;
	int				fsh;
}				t_img;

typedef struct	s_err
{
	int				n;
	int				m;
	int				p;
}				t_err;

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				y;
	int				spr;
}				t_map;

typedef	struct	s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	unsigned int	*i;
	unsigned int	f;
	unsigned int	c;
}				t_tex;

typedef struct	s_position
{
	double			x;
	double			y;
}				t_pos;

typedef	struct	s_direction
{
	double			x;
	double			y;
	double			a;
}				t_dir;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef	struct	s_hit
{
	double			x;
	double			y;
	double			d;
}				t_hit;

typedef	struct	s_spr
{
	double			x;
	double			y;
	double			d;
}				t_spr;

typedef	struct	s_stk
{
	double			x;
	double			y;
	double			d;
}				t_stk;

typedef	struct	s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_err			err;
	t_map			map;
	t_tex			tex;
	t_pos			pos;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_spr			*spr;
	t_stk			*stk;
}				t_all;

void			ft_init(char *cub, int bmp);
void			ft_init_v2(t_all all, char *cub, int bmp);
int				ft_cub3d(t_all all, char *cub, int bmp);
void			ft_draw(t_all *all);

int				ft_parse(t_all *all, char *cub);
int				get_next_line(int fd, char **line);
int				ft_line(t_all *all, char *line);

char			*get_line(char *str);
char			*str_trim(char *str);
char			*buf_join(char *str, char *buf);
int				newline_check(char *str, int rd_size);
char			*error(char *str);

int				ft_parse_check(t_all *all);
int				ft_map_check(t_all *all);
int				ft_file_check(char *argv, char *cub);
int				ft_save_check(char *argv, char *save);

int				ft_map(t_all *all, char *line, int *i);
char			*ft_valid_map(t_all *all, char *line, int *i);
int				ft_pcount(t_all *all, char *line);
int				ft_texture(t_all *all, unsigned int **addr, char *line, int *i);
int				ft_xpm(t_all *all, unsigned int **addr, char *file);

int				ft_all_list(t_all *all);
void			ft_position(t_all *all);
int				ft_colors(unsigned int *color, char *line, int *i);
int				ft_resolution(t_all *all, char *line, int *i);

int				ft_deal_key(int key, void *arg);
void			ft_rotate(t_all *all, double c);
void			ft_move_side(t_all *all, double c);
void			ft_move(t_all *all, double c);
int				ft_close(t_all *all, int win);

void			ft_screen(t_all *all);
void			ft_horizon(t_all *all);
void			ft_vertical(t_all *all);
void			ft_direction(t_all *all);
void			ft_ray(t_all *all);

void			ft_stock(t_all *all);
int				ft_size(t_all *all);
void			ft_column(t_all *all, int size);
unsigned int	ft_pixel(t_all *all, double i);

void			ft_sprite(t_all *all);
void			ft_all_order(t_all *all);
void			ft_all_locate(t_all *all, double dirx, double diry,
		double dist);
void			ft_all_draw(t_all *all, int loc, double dist);
unsigned int	ft_all_pixel(t_all *all, int index, unsigned int col);

int				ft_bmp(t_all *all);
void			ft_bmp_draw(t_all *all);
void			ft_bmp_file(t_all *all, int fd);
void			ft_bmp_info(t_all *all, int fd);
void			ft_bmp_data(t_all *all, int fd);

int				ft_whitespace(char *line, int *i);
int				ft_atoi(char *line, int *i);
int				ft_strerror(int err);

#endif
