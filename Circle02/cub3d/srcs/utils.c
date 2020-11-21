/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:09:30 by gipark            #+#    #+#             */
/*   Updated: 2020/11/21 23:22:30 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_whitespace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		ft_atoi(char *line, int *i)
{
	int	num;

	num = 0;
	ft_whitespace(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

int		ft_strerror(int err)
{
	(err == -1) ? write(2, ERROR_01, 27) : 0;
	(err == -2) ? write(2, ERROR_02, 33) : 0;
	(err == -3) ? write(2, ERROR_03, 45) : 0;
	(err == -4) ? write(2, ERROR_04, 28) : 0;
	(err == -5) ? write(2, ERROR_05, 51) : 0;
	(err == -6) ? write(2, ERROR_06, 34) : 0;
	(err == -7) ? write(2, ERROR_07, 47) : 0;
	(err == -8) ? write(2, ERROR_08, 31) : 0;
	(err == -9) ? write(2, ERROR_09, 31) : 0;
	(err == -10) ? write(2, ERROR_10, 30) : 0;
	(err == -11) ? write(2, ERROR_11, 28) : 0;
	(err == -12) ? write(2, ERROR_12, 21) : 0;
	(err == -13) ? write(2, ERROR_13, 31) : 0;
	(err == -14) ? write(2, ERROR_14, 23) : 0;
	(err == -15) ? write(2, ERROR_15, 20) : 0;
	(err == -16) ? write(2, ERROR_16, 30) : 0;
	(err == -17) ? write(2, ERROR_17, 19) : 0;
	(err == -18) ? write(2, ERROR_18, 26) : 0;
	(err == -19) ? write(2, ERROR_19, 41) : 0;
	return (-1);
}
