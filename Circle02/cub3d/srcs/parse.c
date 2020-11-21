/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 05:07:21 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:46:20 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_line(t_all *all, char *line)
{
	int		i;

	i = 0;
	ft_whitespace(line, &i);
	if ((line[i] == '1' || all->err.m == 1) && line[i] != '\0')
		all->err.n = ft_map(all, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		all->err.n = ft_resolution(all, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->err.n = ft_texture(all, &all->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->err.n = ft_texture(all, &all->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		all->err.n = ft_texture(all, &all->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		all->err.n = ft_texture(all, &all->tex.e, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		all->err.n = ft_texture(all, &all->tex.i, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		all->err.n = ft_colors(&all->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		all->err.n = ft_colors(&all->tex.c, line, &i);
	if (ft_whitespace(line, &i) && all->err.n == 0 && line[i] != '\0')
		return (ft_strerror(-10));
	return (all->err.n < 0 ? ft_strerror(all->err.n) : 0);
}

int		get_next_line(int fd, char **line)
{
	int			rd_size;
	char		buf[4096];
	static char	*str = NULL;

	if (line == NULL || fd < 0)
		return (-3);
	*line = NULL;
	rd_size = 1;
	while (!(newline_check(str, rd_size)))
	{
		if ((rd_size = read(fd, buf, 4095)) == -1)
			return (-3);
		buf[rd_size] = '\0';
		if ((str = buf_join(str, buf)) == NULL)
			return (-3);
	}
	if ((*line = get_line(str)) == NULL)
		return (-3);
	if (rd_size == 0)
		free(str);
	if (rd_size == 0)
		return (0);
	if ((str = str_trim(str)) == NULL)
		return (-3);
	return (1);
}

int		ft_parse(t_all *all, char *cub)
{
	char	*line;
	int		fd;
	int		result;

	result = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(-1));
	while (result == 1)
	{
		result = get_next_line(fd, &line);
		if (ft_line(all, line) == -1)
			result = -1;
		free(line);
	}
	close(fd);
	if (result == -1 || result == -3)
		return (ft_strerror(result + 1));
	ft_position(all);
	all->spr = NULL;
	ft_all_list(all);
	return (ft_parse_check(all));
}
