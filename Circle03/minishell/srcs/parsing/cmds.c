/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjoo <hjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:55:44 by hjoo              #+#    #+#             */
/*   Updated: 2021/02/03 22:55:46 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd_list(t_cmd **begin, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new || !begin)
		return ;
	new->cmd = supp_newline(new->cmd);
	if (*begin)
	{
		tmp = *begin;
		while (tmp->next)
		{
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	else
		*begin = new;
}

char	**args_to_array(t_minishell *minishell, t_cmd *cmd)
{
	char	**array;
	int		i;
	t_token *tmp;

	i = 1;
	if (!(array = ft_calloc(1, sizeof(char *)
		* (token_list_size(&cmd->args) + 2))))
		exit_cmd(minishell);
	array[0] = cmd->cmd;
	tmp = cmd->args;
	while (tmp)
	{
		array[i] = tmp->word;
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	clear_cmd_list_free(t_cmd *cmd)
{
	ft_strdel(&cmd->cmd);
	ft_strdel(&cmd->bin);
	ft_free_split(&cmd->args_array);
	ft_lstclear(&cmd->env_list, free);
}

void	clear_cmd_list(t_cmd **begin, void (*del)(void *))
{
	t_cmd	*tmp;
	t_cmd	*tmp2;
	t_token *args;
	t_token *args2;

	if (!begin || !del)
		return ;
	tmp = *begin;
	while (tmp)
	{
		clear_cmd_list_free(tmp);
		args = tmp->args;
		while (args)
		{
			ft_strdel(&args->word);
			args2 = args->next;
			del(args);
			args = args2;
		}
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*begin = NULL;
}
