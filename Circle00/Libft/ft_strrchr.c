/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:17:07 by gipark            #+#    #+#             */
/*   Updated: 2020/04/07 00:05:51 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The reason why I code "pos = i + 1;"
** if index == 0 and s[i] == c, then pos == 0.
** so pos = i +1;
*/

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			pos = i + 1;
		i++;
	}
	if (pos)
		return (&((char *)s)[pos - 1]);
	else if (s[i] == c)
		return (&((char *)s)[i]);
	else
		return (NULL);
}
