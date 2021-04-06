/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:31:03 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:31:04 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_intlen_base(n, base);
	base_len = ft_strlen(base);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}
