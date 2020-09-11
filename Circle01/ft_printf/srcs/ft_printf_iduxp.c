/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_iduxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:01:15 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 02:23:42 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(int *len, t_info inf, unsigned long int p)
{
	inf.sign = 'u';
	inf.number_zero = 0;
	inf.str = ft_ulltoa_base(p, HEX_LOW);
	print_flags(len, inf);
	free(inf.str);
}

void	print_decimal(int *len, t_info inf, va_list ap)
{
	if (inf.spec_c == 'i' || inf.spec_c == 'd')
	{
		if (inf.length <= 0)
			inf.lli = va_arg(ap, int);
		if (inf.length == 1)
			inf.lli = va_arg(ap, long int);
		if (inf.length >= 2)
			inf.lli = va_arg(ap, long long int);
		inf.sign = (inf.lli >= 0) ? '+' : '-';
		inf.ulli = (inf.lli >= 0) ? inf.lli : -inf.lli;
	}
	if (inf.spec_c == 'u')
	{
		if (inf.length <= 0)
			inf.ulli = va_arg(ap, unsigned int);
		if (inf.length == 1)
			inf.ulli = va_arg(ap, unsigned long int);
		if (inf.length >= 2)
			inf.ulli = va_arg(ap, unsigned long long int);
		inf.sign = 'u';
	}
	inf.number_zero = 0;
	inf.str = ft_ulltoa_base(inf.ulli, DIGITS);
	print_flags(len, fl);
	free(inf.str);
}

void	print_hexa(int *len, t_info inf, va_list ap)
{
	if (inf.length <= 0)
		inf.ulli = va_arg(ap, unsigned int);
	if (inf.length == 1)
		inf.ulli = va_arg(ap, unsigned long int);
	if (inf.length >= 2)
		inf.ulli = va_arg(ap, unsigned long long int);
	inf.sign = 'u';
	inf.number_zero = 0;
	if (inf.ulli == 0)
		inf.hash = 0;
	if (inf.spec_c == 'x')
		inf.str = ft_ulltoa_base(inf.ulli, HEX_LOW);
	if (inf.spec_c == 'X')
		inf.str = ft_ulltoa_base(inf.ulli, HEX_UPP);
	print_flags(len, fl);
	free(inf.str);
}
