/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 05:20:53 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 03:00:16 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define FLAGS			"-+#0 "
# define FLAGS_ALL		"-+#0 *.0123456789lh"
# define CONVERSIONS	"cspdiuxX%nfge"

# define DIGITS			"0123456789"
# define HEX_LOW		"0123456789abcdef"
# define HEX_UPP		"0123456789ABCDEF"

typedef struct	s_info
{
	char					set[20];
	char					spec_c;
	char					padd_c;
	char					minus;
	char					plus;
	char					space;
	char					hash;
	int						width;
	char					point;
	int						precision;
	char					length;
	char					number_zero;
	char					sign;
	unsigned long long int	ulli;
	long long int			lli;
	char					*str;
	size_t					strlen;
}				t_info;

/*
**  FILE: ft_printf.c
*/
int				ft_printf(const char *format, ...);

/*
**  FILE: ft_printf_cs.c
*/
void			print_percent(int *len, t_info inf);
void			print_char(int *len, t_info inf, char c);
void			print_string(int *len, t_info inf, char *s);

/*
**  FILE: ft_printf_iduxp.c
*/
void			print_decimal(int *len, t_info inf, va_list ap);
void			print_hexa(int *len, t_info inf, va_list ap);
void			print_pointer(int *len, t_info inf, unsigned long int p);

/*
**  FILE: ft_printf_pre.c
*/
void			print_flags(int *len, t_info inf);

#endif
