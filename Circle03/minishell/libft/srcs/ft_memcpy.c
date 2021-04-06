/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:33:13 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:33:14 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*sd;
	char		*sr;

	sd = dst;
	sr = (void*)src;
	i = 0;
	while (i < n)
	{
		sd[i] = sr[i];
		i++;
	}
	return (dst);
}
