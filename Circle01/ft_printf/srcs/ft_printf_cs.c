/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:55:30 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 02:22:09 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_padding(int *len, t_info inf)
{
	while (inf.width > inf.precision)
	{
		ft_putchar_len(inf.padd_c, len);
		inf.width--;
	}
}

void		print_percent(int *len, t_info inf)
{
	if (inf.minus == 1)
		inf.padd_c = ' ';
	inf.precision = 1;
	if (inf.minus == 0)
		print_padding(len, inf);
	ft_putchar_len('%', len);
	if (inf.minus == 1)
		print_padding(len, inf);
}

void		print_char(int *len, t_info inf, char c)
{
	inf.pad_c = ' ';
	inf.precision = 1;
	if (inf.minus == 0)
		print_padding(len, inf);
	ft_putchar_len(c, len);
	if (inf.minus == 1)
		print_padding(len, inf);
}

void		print_string(int *len, t_info inf, char *s)
{
	inf.padd_c = ' ';
	if (s == NULL)
		s = "(null)";
	if ((inf.point == 1 && inf.precision > (int)ft_strlen(s)) || inf.point == 0)
		inf.precision = ft_strlen(s);
	if (inf.minus == 0)
		print_padding(len, inf);
	ft_putstr_len(s, len, inf.precision);
	if (inf.minus == 1)
		print_padding(len, inf);
}
