/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:33:00 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:33:01 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*sd;
	char			*sr;
	unsigned char	uc;

	sd = dst;
	sr = (void*)src;
	uc = c;
	i = 0;
	while (i < n)
	{
		sd[i] = sr[i];
		i++;
		if (sr[i - 1] == uc)
			return (dst + i);
	}
	return (NULL);
}
