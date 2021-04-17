/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:25:31 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 16:25:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	sign = (*str == '-' ? (-1) : 1);
	(*str == '-' || *str == '+') ? str++ : 0;
	while (*str > 47 && *str < 58)
	{
		res = (res * 10) + (*str++ - 48);
		if (res < 0)
			return ((sign == 1) ? -1 : 0);
	}
	return ((int)(res * sign));
}
