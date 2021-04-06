/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:40:48 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:40:49 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		handle_line(char *s[], int fd)
{
	char	*tmp;

	if (ft_is_in_stri('\n', s[fd]) >= 0)
	{
		tmp = s[fd];
		s[fd] = ft_substr(s[fd], ft_is_in_stri('\n', s[fd]) + 1,
			ft_strlen(s[fd]));
		free(tmp);
	}
	else if (ft_strlen(s[fd]) > 0)
		ft_strdel(&s[fd]);
	else
	{
		ft_strdel(&s[fd]);
		return (FINISH);
	}
	return (SUCCESS);
}

int				get_next_line(int fd, char **line)
{
	static char		*s[10240];
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (ERROR);
	if (!s[fd] && !(s[fd] = ft_calloc(1, sizeof(char *))))
		return (ERROR);
	while ((ft_is_in_stri('\n', s[fd])) < 0 &&
		(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(s[fd], buf);
		free(tmp);
	}
	if (s[fd])
		*line = ft_substr(s[fd], 0, ft_strlen_c(s[fd], '\n'));
	if (!handle_line(s, fd))
		return (FINISH);
	return (SUCCESS);
}
