/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:37:16 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 16:37:17 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needdle, size_t len)
{
	size_t	i;
	int		j;
	char	*pt;

	i = 0;
	pt = 0;
	if (!(*needdle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needdle[0])
		{
			pt = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] == needdle[j] && i + j < len)
			{
				if (needdle[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (NULL);
}
