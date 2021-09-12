/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:28:39 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/11 20:43:43 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

// Return file path if the cmd exists and can be executed
static char	*ft_access(char *path, char *cmd)
{
	char *file;

	file = ft_strjoin(path, cmd);
	if (file == NULL)
		return (NULL);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (NULL);
}

static char	*ft_check_command(char *cmd)
{
	char *file;

	file = ft_access(PATH_UBIN, cmd);
	if (file != NULL)
		return (file);
	file = ft_access(PATH_USBIN, cmd);
	if (file != NULL)
		return (file);
	file = ft_access(PATH_BIN, cmd);
	if (file != NULL)
		return (file);
	file = ft_access(PATH_SBIN, cmd);
	if (file != NULL)
		return (file);
	return (NULL);
}

// Validate and find if commands exists and populate the commands list.
int	ft_parse_commands(t_cmds *lst, char **args, char **envp)
{
	char	*cmd;
	char	**split;
	int		i;

	i = 0;
	while (args[i] && args[i + 1])
	{
		split = ft_split(args[i], ' ');
		if (split == NULL)
			return (0);
		cmd = ft_check_command(split[0]);
		if (cmd == NULL)
			ft_file_error("Command error with", args[i]);
		else
		{
			ft_add_back(lst, ft_new_cmd(cmd, &split[1]));
			printf("\nCommand found : %s", cmd);
		}
		ft_free_split(split);
		i++;
	}
	return (1);
}

// int	ft_parse_commands(char **cmds, char *file, char **envp)
// {
// 	int		i;
// 	char	*cmd;
// 	char	**args;

// 	args = malloc(sizeof(char *)* 2);
// 	args[0] = ft_strjoin(PATH_DIR, file);
// 	args[1] = NULL;

// 	i = 0;
// 	while (cmds[i] && cmds[i + 1])
// 	{
// 		cmd = ft_parse_command(cmds[i]);
// 		if (cmd == NULL)
// 			ft_file_error("Command error with", cmds[i]);
// 		else
// 		{
// 			printf("\nCommand found : %s", cmd);
// 			if (execve(cmd, args, envp) < 0)
// 				ft_file_error("Execution error", args[0]);
// 		}
// 		i++;
// 	}
// 	return (1);
// }