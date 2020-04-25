/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:00:02 by gipark            #+#    #+#             */
/*   Updated: 2020/03/03 18:23:54 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*b_p;

	b_p = (unsigned char *)b;
	while (len--)
	{
		if (*b_p == (unsigned char)c)
			return (b_p);
		b_p++;
	}
	return (void *)'\0';
}
