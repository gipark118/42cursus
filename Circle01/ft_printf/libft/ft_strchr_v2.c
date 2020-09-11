/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:33:24 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 02:04:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchr_v2(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	else
		return (0);
}
