/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:16:45 by gipark            #+#    #+#             */
/*   Updated: 2021/02/03 23:17:06 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_errno(t_minishell *minishell, char *cmd, int type)
{
	if (type == 14)
		ft_dprintf(2, "%s: %s: %s\n", minishell->name, cmd,
			"command not found");
	else
		ft_dprintf(2, "%s: %s: %s\n", minishell->name, cmd, strerror(errno));
	minishell->exit = 127;
}
