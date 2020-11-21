/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:17:52 by gipark            #+#    #+#             */
/*   Updated: 2020/11/22 03:23:07 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_xpm(t_all *all, unsigned int **addr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_file_check(file, "xpm") == 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(all->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*addr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int		ft_texture(t_all *all, unsigned int **addr, char *line, int *i)
{
	char	*file;
	int		j;

	if (*addr != NULL)
		return (-7);
	(*i) += 2;
	ft_whitespace(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
		return (-8);
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		file[j++] = line[(*i)++];
	file[j] = '\0';
	j = ft_xpm(all, addr, file);
	free(file);
	return (j == -1 ? -9 : 0);
}

int		ft_pcount(t_all *all, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			count++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			count++;
		else if (line[i] == 'E')
			count++;
		i++;
	}
	if (all->map.x != 0 && all->map.x != count)
		return (-1);
	return (count);
}

char	*ft_vmap(t_all *all, char *line, int *i)
{
	char	*vmap;
	int		j;

	if (!(vmap = malloc(sizeof(char) * (ft_pcount(all, line) + 1))))
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			vmap[j++] = line[*i];
		else if (line[*i] == '2')
		{
			vmap[j++] = line[*i];
			all->map.spr++;
		}
		else if (line[*i] != ' ')
		{
			free(vmap);
			return (NULL);
		}
		(*i)++;
	}
	vmap[j] = '\0';
	return (vmap);
}

int		ft_map(t_all *all, char *line, int *i)
{
	char	**tmp;
	int		j;

	all->err.m = 1;
	if (!(tmp = malloc(sizeof(char *) * (all->map.y + 2))))
		return (-11);
	j = -1;
	while (++j < all->map.y)
		tmp[j] = all->map.tab[j];
	if ((tmp[all->map.y] = ft_vmap(all, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[all->map.y + 1] = NULL;
	if (all->map.y > 0)
		free(all->map.tab);
	all->map.tab = tmp;
	all->map.y++;
	if ((all->map.x = ft_pcount(all, line)) == -1)
		return (-13);
	return (0);
}
