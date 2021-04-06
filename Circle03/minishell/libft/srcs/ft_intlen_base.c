/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:28:56 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:28:57 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(uintmax_t n, char *base)
{
	size_t		len;
	uintmax_t	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}
