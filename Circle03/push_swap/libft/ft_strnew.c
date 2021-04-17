/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:37:09 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 16:37:10 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_string;

	if (!(new_string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new_string, size + 1);
	return (new_string);
}
