/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:28:31 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:28:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char ***split)
{
	int		i;

	i = 0;
	while (*split && (*split)[i])
	{
		ft_strdel(&(*split)[i]);
		i++;
	}
	free(*split);
	*split = NULL;
}
