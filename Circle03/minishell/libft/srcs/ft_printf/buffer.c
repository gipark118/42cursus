/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:43:56 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:43:57 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dump_buffer(t_printf *tab)
{
	write(tab->fd, tab->buf, tab->buf_count);
	tab->buf_count = 0;
}

void	ft_add_to_buff(t_printf *tab, char *str, int len)
{
	int		i;

	i = 0;
	tab->ret += len;
	while (i < len)
	{
		tab->buf[tab->buf_count] = str[i];
		tab->buf_count++;
		if (tab->buf_count == BUFFER_SIZE)
			ft_dump_buffer(tab);
		i++;
	}
}
