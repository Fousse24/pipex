/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:28:39 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/22 15:21:14 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

// Return file path if the cmd exists and can be executed
static char	*ft_access(char *path, char *cmd)
{
	char	*file;

	file = ft_join_path_file(path, cmd);
	if (file == NULL)
		return (NULL);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (NULL);
}

static char	*ft_check_command(char *cmd, char **paths)
{
	char	*file;

	file = ft_access("", cmd);
	if (file != NULL)
		return (file);
	while (paths != NULL && *paths != NULL)
	{
		file = ft_access(*(paths++), cmd);
		if (file != NULL)
			return (file);
	}
	return (NULL);
}

static int	ft_error_parse(char **split, char **paths)
{
	ft_free_split(split);
	ft_free_split(paths);
	split = NULL;
	paths = NULL;
	return (0);
}

char	*ft_get_env_path(char **envp)
{
	if (envp == NULL)
		return (NULL);
	while (envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (&(*envp)[6]);
		envp++;
	}
	return (NULL);
}

// Validate and find if commands exists and populate the commands list.
int	ft_parse_commands(t_cmds *lst, char **args, char **envp)
{
	char	*cmd;
	char	**split;
	char	**paths;
	int		i;

	paths = ft_split(ft_get_env_path(envp), ':');
	i = 0;
	while (args[i] && args[i + 1] != NULL)
	{
		split = ft_split_cmds(args[i], ' ');
		if (split == NULL)
			return (ft_error_parse(split, paths));
		cmd = ft_check_command(split[0], paths);
		if (cmd == NULL)
		{
			ft_file_error("Command error with", args[i]);
			return (ft_error_parse(split, paths));
		}
		else
			ft_add_back(lst, ft_new_cmd(cmd, split));
		i++;
	}
	ft_free_split(paths);
	return (1);
}
