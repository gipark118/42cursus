/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:38:29 by gipark            #+#    #+#             */
/*   Updated: 2021/02/04 21:38:30 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		i;
	int		to_malloc;
	int		len;

	i = 0;
	to_malloc = n;
	len = ft_strlen(s1);
	if (len < n)
		to_malloc = len;
	if (!(str = (char*)malloc(sizeof(char) * to_malloc + 1)))
		return (NULL);
	while (s1[i] && i < n)
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
