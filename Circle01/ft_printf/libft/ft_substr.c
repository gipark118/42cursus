/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:39:23 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 02:56:07 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (s)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (i < len && start < ft_strlen(s))
		{
			tmp[i] = s[start];
			i++;
			start++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
