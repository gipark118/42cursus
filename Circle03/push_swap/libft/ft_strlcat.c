/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:35:29 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 16:35:30 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		t1;

	t1 = 0;
	i = 0;
	while (dst[t1] && t1 < dstsize)
		t1++;
	while (src[i] && t1 + i + 1 < dstsize)
	{
		dst[t1 + i] = src[i];
		i++;
	}
	if (t1 < dstsize)
		dst[t1 + i] = '\0';
	return (t1 + ft_strlen(src));
}
