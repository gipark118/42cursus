/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:27:35 by gipark            #+#    #+#             */
/*   Updated: 2020/04/17 02:28:07 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	i;
	void	*memory;

	i = 0;
	if (!(memory = (char *)malloc(number * size)))
		return (NULL);
	while (i < number * size)
	{
		((char *)memory)[i] = 0;
		i++;
	}
	return (memory);
}
