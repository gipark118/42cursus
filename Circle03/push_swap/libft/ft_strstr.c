/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:37:42 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 16:37:43 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needdle)
{
	int		i;
	int		j;
	char	*pt;

	i = 0;
	pt = NULL;
	if (!(*needdle))
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needdle[0])
		{
			pt = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] == needdle[j])
			{
				if (needdle[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (0);
}
