/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:34:35 by gipark            #+#    #+#             */
/*   Updated: 2021/02/13 12:42:48 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		in_s(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_words(char const *s, char *set)
{
	int		count;
	int		is_word;

	is_word = 0;
	count = 0;
	while (*s)
	{
		if (in_s(*s, set))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	w_s(char const *s, int pos, char *set)
{
	size_t	len;

	len = 0;
	while (s[pos])
	{
		if (in_s(s[pos], set))
			return (len);
		len++;
		pos++;
	}
	return (len);
}

void			k_j(int *j, int *k)
{
	*j = *j + 1;
	*k = 0;
	return ;
}

char			**ft_ssplit(char const *s, char *set)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	if (!(tab = malloc(sizeof(char*) * (count_words(s, set) + 1))))
		return (NULL);
	while (s[++i])
	{
		if (!in_s(s[i], set))
		{
			if (k == 0)
				if (!(tab[j] = malloc(sizeof(char) * w_s(s, i, set) + 1)))
					return (NULL);
			tab[j][k] = s[i];
			tab[j][++k] = '\0';
		}
		if (in_s(s[i], set) && !in_s(s[i + 1], set) && k > 0)
			k_j(&j, &k);
	}
	tab[count_words(s, set)] = NULL;
	return (tab);
}
