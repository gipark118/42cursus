/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:06:54 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 21:44:13 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(int *len, t_info inf)
{
	if (inf.sign == '-' || (inf.plus == 1 && inf.sign == '+') ||
			(inf.space == 1 && inf.plus == 0 && inf.sign == '+'))
		inf.width--;
	if (inf.precision <= (int)inf.strlen)
		inf.precision = (int)inf.strlen;
	if (inf.padd_c == '0' && (inf.minus == 1 || inf.point == 1) &&
			!(inf.minus == 0))
		inf.padd_c = ' ';
	while (inf.width > inf.precision)
	{
		ft_putchar_len(inf.padd_c, len);
		inf.width--;
	}
}

static void	print_zero(int *len, t_info inf)
{
	int	j;

	if ((inf.spec_c == 'x' && inf.hash == 1) || inf.spec_c == 'p')
		ft_putstr_len("0x", len, 2);
	if (inf.spec_c == 'X' && inf.hash == 1)
		ft_putstr_len("0X", len, 2);
	if (inf.minus == 0 && inf.padd_c == '0')
		print_width(len, inf);
	if (inf.point == 1)
	{
		j = inf.precision;
		while (j-- > (int)inf.strlen)
			ft_putchar_len('0', len);
	}
}

void		print_flags(int *len, t_info inf)
{
	inf.strlen = ft_strlen(inf.str);
	if (inf.ulli == 0 && inf.point == 1 && inf.precision == 0 &&
			inf.number_zero == 0)
		inf.width++;
	if (((inf.spec_c == 'x' || inf.spec_c == 'X') && inf.hash == 1) ||
			inf.spec_c == 'p')
		inf.width -= 2;
	if (inf.point == 1 && inf.spec_c != 'f')
		inf.padd_c = ' ';
	if (inf.minus == 0 && inf.padd_c == ' ')
		print_width(len, inf);
	if (inf.sign == '-' || (inf.plus == 1 && inf.sign == '+'))
		ft_putchar_len(inf.sign, len);
	if (inf.space == 1 && inf.plus == 0 && inf.sign == '+')
		ft_putchar_len(' ', len);
	print_zero(len, inf);
	if (!(inf.ulli == 0 && inf.point == 1 && inf.precision == 0) ||
			inf.number_zero == 1)
		ft_putstr_len(inf.str, len, ft_strlen(inf.str));
	if (inf.minus == 1)
		print_width(len, inf);
}
