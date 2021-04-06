/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjoo <hjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:54:44 by hjoo              #+#    #+#             */
/*   Updated: 2021/02/03 22:54:45 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		add_token_front(t_token **begin, t_token *new)
{
	if (*begin)
	{
		new->next = *begin;
		(*begin)->prev = new;
		*begin = new;
	}
	else
		*begin = new;
}

t_token		*token_split_to_list(char **split)
{
	t_token *new;
	int		i;
	int		count;

	i = 0;
	count = ft_count_split(split);
	new = NULL;
	while (i < count)
	{
		add_token_list(&new, create_arg_token(split[i], T_WORD));
		i++;
	}
	return (new);
}
