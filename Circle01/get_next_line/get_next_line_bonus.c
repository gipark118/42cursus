/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:59:02 by gipark            #+#    #+#             */
/*   Updated: 2020/06/18 20:09:06 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int		get_new_line(int fd, char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(&(str[fd])[len + 1]);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (0);
	}
}

int		result_value(int rd_size, int fd, char **str, char **line)
{
	if (rd_size < 0)
		return (-1);
	else if (rd_size == 0 && str[fd] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (get_new_line(fd, str, line));
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str[OPEN_MAX];
	char		*tmp;
	int			rd_size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
			!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (0 < (rd_size = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rd_size] = '\0';
		if (str[fd] == '\0')
			str[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str[fd], buf);
			ft_strdel(&str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(buf);
	return (result_value(rd_size, fd, str, line));
}
