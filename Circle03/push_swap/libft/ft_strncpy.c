/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:36:46 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 16:36:47 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tdst;

	tdst = dst;
	while (len--)
	{
		if (*src)
			*tdst++ = *src++;
		else
			*tdst++ = '\0';
	}
	return (dst);
}
