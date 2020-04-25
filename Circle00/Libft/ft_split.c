/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:08:11 by gipark            #+#    #+#             */
/*   Updated: 2020/04/17 04:19:28 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_alen(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int		ft_strcnt(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	if (!s || !(tmp = (char **)malloc(sizeof(char *) * (ft_strcnt(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_strcnt(s, c))
	{
		if (!(tmp[i] = (char *)malloc(sizeof(char) * (ft_alen(&s[j], c) + 1))))
		{
			free(tmp);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		k = 0;
		while (s[j] != c && s[j] != '\0')
			tmp[i][k++] = s[j++];
		tmp[i][k] = '\0';
	}
	tmp[i] = (char *)'\0';
	return (tmp);
}
