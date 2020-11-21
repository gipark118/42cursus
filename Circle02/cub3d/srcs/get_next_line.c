/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 05:44:40 by gipark            #+#    #+#             */
/*   Updated: 2020/11/21 21:48:09 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*error(char *str)
{
	free(str);
	return (NULL);
}

int		newline_check(char *str, int rd_size)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (rd_size == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*buf_join(char *str, char *buf)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	while (buf[j] != '\0')
		j++;
	if (!(newstr = malloc(sizeof(char) * (i + j + 1))))
		return (error(str));
	i = 0;
	j = 0;
	while (str != NULL && str[i] != '\0')
		newstr[i++] = str[j++];
	j = 0;
	while (buf[j] != '\0')
		newstr[i++] = buf[j++];
	newstr[i] = '\0';
	if (str != NULL)
		free(str);
	return (newstr);
}

char	*str_trim(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	while (str[i++] != '\0')
		j++;
	if (!(result = malloc(sizeof(char) * j + 1)))
		return (error(str));
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		i--;
	i++;
	while (str[i] != '\0')
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (error(str));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
