/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 03:37:22 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 21:50:53 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_conversions(va_list ap, int *len, t_info inf)
{
	if (inf.spec_c == '%')
		print_percent(len, inf);
	if (inf.spec_c == 'c')
		print_char(len, inf, va_arg(ap, int));
	if (inf.spec_c == 's')
		print_string(len, inf, va_arg(ap, char *));
	if (inf.spec_c == 'p')
		print_pointer(len, inf, va_arg(ap, unsigned long int));
	if (inf.spec_c == 'i' || inf.spec_c == 'd' || inf.spec_c == 'u')
		print_decimal(len, inf, ap);
	if (inf.spec_c == 'x' || inf.spec_c == 'X')
		print_hexa(len, inf, ap);
}

static t_info	set_asterisk(va_list ap, t_info inf, int *j)
{
	int	value;

	(*j)++;
	value = va_arg(ap, int);
	if (inf.point == 0)
	{
		inf.width = (value >= 0) ? value : -value;
		inf.padd_c = (value >= 0) ? inf.padd_c : ' ';
		inf.minus = (value >= 0) ? inf.minus : 1;
	}
	if (inf.point == 1)
	{
		if (value >= 0)
			inf.precision = value;
		else
			inf.point = 0;
	}
	return (inf);
}

static t_info	prepare_flags(va_list ap, t_info inf)
{
	int		j;

	j = 0;
	while (inf.set[j] != '\0' && ft_strchr_v2(FLAGS, inf.set[j]))
	{
		if (inf.set[j++] == '0')
			inf.padd_c = '0';
	}
	if (inf.set[j] == '*')
		inf = set_asterisk(ap, inf, &j);
	while (inf.set[j] != '\0' && ft_strchr_v2(DIGITS, inf.set[j]))
		inf.width = 10 * inf.width + inf.set[j++] - '0';
	if (inf.set[j] == '.')
	{
		inf.point = 1;
		if (inf.set[++j] == '*')
			inf = set_asterisk(ap, inf, &j);
		while (inf.set[j] != '\0' && ft_strchr_v2(DIGITS, inf.set[j]))
			inf.precision = 10 * inf.precision + inf.set[j++] - '0';
	}
	while (inf.set[j] != '\0' && ft_strchr_v2("l", inf.set[j++]))
		inf.length++;
	while (inf.set[j] != '\0' && ft_strchr_v2("h", inf.set[j++]))
		inf.length--;
	return (inf);
}

static void		prepare_info(va_list ap, const char *format, int *len, int *i)
{
	t_info	inf;
	int		j;

	j = 0;
	while (ft_strchr_v2(FLAGS_ALL, format[*i]) && j < 19)
		inf.set[j++] = format[(*i)++];
	inf.set[j] = '\0';
	if (ft_strchr_v2(CONVERSIONS, format[*i]))
	{
		inf.spec_c = format[(*i)++];
		inf.minus = ft_strchr_v2(inf.set, '-');
		inf.plus = ft_strchr_v2(inf.set, '+');
		inf.space = ft_strchr_v2(inf.set, ' ');
		inf.hash = ft_strchr_v2(inf.set, '#');
		inf.width = 0;
		inf.point = 0;
		inf.precision = 0;
		inf.length = 0;
		inf.padd_c = ' ';
		inf = prepare_flags(ap, inf);
		print_conversions(ap, len, inf);
	}
	else
		(*len) = -1;
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar_len(format[i++], &len);
		else
		{
			i++;
			prepare_info(ap, format, &len, &i);
			if (len == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (len);
}
