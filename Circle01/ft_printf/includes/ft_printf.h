/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 05:20:53 by gipark            #+#    #+#             */
/*   Updated: 2020/09/08 11:52:02 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

/*
** FORMAT SPECIFIER STRUCT
*/
typedef struct s_flags
{
	char					set[20];
	char					spec_c;
	char					padd_c;
	char					minus;
	char					plus;
	char					space;
	char					hash;
	char					hash;
	int						width;
	char					point;
	int						precision;
	char					length;
	char					print_n0;
	char					sign;
	unsigned long long int	ulli;
	long long int			lli;
}

#endif