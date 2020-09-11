/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:38:09 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 02:56:22 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len(char *s, int *len, int size)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] && i < size)
			ft_putchar_len(s[i++], len);
	}
}
