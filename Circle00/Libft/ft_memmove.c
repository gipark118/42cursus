/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:25:40 by gipark            #+#    #+#             */
/*   Updated: 2020/04/17 03:26:12 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (!dst && !src)
		return (NULL);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			dst_p[len - 1] = src_p[len - 1];
			len--;
		}
	}
	return (dst);
}
