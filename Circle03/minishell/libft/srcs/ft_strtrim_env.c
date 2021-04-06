/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjoo <hjoo@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:38:49 by hjoo              #+#    #+#             */
/*   Updated: 2021/02/13 15:39:03 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_env(const char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		if (src[i] == 32 && src[i + 1] == 32)
		{
			i++;
			continue ;
		}
		str[j] = src[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
