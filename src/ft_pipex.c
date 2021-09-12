/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:01 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/11 20:09:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

int	ft_pipex(t_cmds *cmds, char **argv, int argn, char **envp)
{
	int	fd_src;
	int	fd_dst;
	
	if (ft_open(argv[argn - 1], O_RDONLY | O_CREAT, &fd_dst) < 0)
		return (ft_file_error("File error with", argv[argn - 1]));
	if (ft_open(argv[0], O_RDONLY, &fd_src) < 0)
		return (ft_file_error("File error with", argv[0]));
	if (!ft_parse_commands(cmds, &argv[1], envp))
		return (0);
	
	close(fd_src);
	close(fd_dst);
	return (1);
}

int	main(int argn, char **argv, char **envp)
{
	t_cmds	cmds;

	cmds.head = NULL;
	cmds.tail = NULL;
	cmds.count = 0;
	if (argn < 3) //CHANGE IT
		return (0);
	else
	{
		ft_pipex(&cmds, &argv[1], argn - 1, envp);
	}
	ft_print_cmds(cmds.head);
	ft_free_cmds(cmds.head);
	return (1);
}