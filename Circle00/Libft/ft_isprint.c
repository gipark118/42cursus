/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:05:50 by gipark            #+#    #+#             */
/*   Updated: 2020/03/07 04:12:11 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Why does isprint print isspace(3)?
** So, (c >= 9 && c <= 13) is wrong answer.
** But, as you can see in the question, space is including.
*/

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (16384);
	else
		return (0);
}
