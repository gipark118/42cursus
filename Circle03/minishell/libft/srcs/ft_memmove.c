/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:33:24 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:33:25 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*sd;
	char	*sr;

	sd = dst;
	sr = (void*)src;
	i = 0;
	if (sr < sd)
	{
		i++;
		while (i <= len)
		{
			sd[len - i] = sr[len - i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			sd[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
