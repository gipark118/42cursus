/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 01:22:28 by gipark            #+#    #+#             */
/*   Updated: 2021/01/09 03:08:08 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		base_length(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v' ||
				base[i] == '\f' || base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		base_finder(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != ch)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int	i;
	int	num;
	int	sign;
	int	base_len;

	i = 0;
	num = 0;
	sign = 1;
	base_len = base_length(base);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (base_finder(str[i], base) < base_len)
	{
		num = num * base_len + base_finder(str[i], base);
		i++;
	}
	return (num * sign);
}
