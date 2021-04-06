/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjoo <hjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:53:48 by hjoo              #+#    #+#             */
/*   Updated: 2021/02/03 22:53:52 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_bin(t_minishell *minishell)
{
	int		i;
	char	**bin;
	char	*ban;

	i = 0;
	ban = NULL;
	ban = get_env(minishell, "PATH");
	bin = NULL;
	if (ban)
		bin = ft_split(ban, ':');
	while (bin && bin[i])
	{
		bin[i] = ft_strjoin_free(bin[i], "/");
		i++;
	}
	ft_free_split(&minishell->bin);
	minishell->bin = bin;
}

char	*try_opendir(char *path, char *cmd)
{
	DIR				*dir;
	struct dirent	*dent;

	dir = opendir(path);
	if (dir)
	{
		while ((dent = readdir(dir)))
		{
			if (ft_strequ(dent->d_name, cmd))
			{
				if (dir)
					closedir(dir);
				return (ft_strjoin(path, cmd));
			}
		}
	}
	if (dir)
		closedir(dir);
	return (NULL);
}

char	*get_bin(t_minishell *minishell, char *cmd)
{
	char	*try;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_is_in_stri('/', cmd) >= 0)
		return (ft_strdup(cmd));
	if (!minishell->bin)
		return (ft_strjoin("./", cmd));
	while (minishell->bin && minishell->bin[i])
	{
		try = try_opendir(minishell->bin[i], cmd);
		if (try)
			return (try);
		i++;
	}
	return (NULL);
}
