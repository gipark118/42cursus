/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:37:02 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 01:58:39 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
