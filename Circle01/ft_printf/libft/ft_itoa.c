/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:52:22 by gipark            #+#    #+#             */
/*   Updated: 2020/04/11 15:40:31 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	size_t	count;

	count = 1;
	while (n /= 10)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	tmp;

	len = ft_nbrlen(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (char *)'\0';
	str[len] = '\0';
	str[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		str[--len] = tmp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
