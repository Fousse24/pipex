/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:01 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/15 15:13:57 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

static int	ft_resolve(t_cmd *cmd, char **envp, int fd_read, int fd_write)
{
	int		pipe_fd[2];
	char	str[100];
	int		child;
	int		status;

	if (pipe(pipe_fd) < 0)
		return (ft_error("Pipe error : "));
	dup2(fd_read, 0);
	close(fd_read);
	if (cmd->next == NULL)
		dup2(fd_write, 1);
	else
		dup2(pipe_fd[1], 1);
	child = fork();
	if (child == 0)
	{
		execve(cmd->cmd, cmd->full_cmd, envp);
		exit(0);
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(child, &status, 0);
		if (cmd->next != NULL)
			return (ft_resolve(cmd->next, envp, pipe_fd[0], fd_write));
	}
	return (1);

}

int	ft_pipex(t_cmds *cmds, char **argv, int argn, char **envp)
{
	int	fd_src;
	int	fd_dst;

	if (ft_open(argv[argn - 1], O_RDWR | O_CREAT, &fd_dst) < 0)
		return (ft_file_error("File error with", argv[argn - 1]));
	if (ft_open(argv[0], O_RDONLY, &fd_src) < 0)
		return (ft_file_error("File error with", argv[0]));
	if (ft_parse_commands(cmds, &argv[1]))
	{
		ft_resolve(cmds->head, envp, fd_src, fd_dst);
		// write(fd_dst, "yeah!", 5);
	}
	if (fd_src >= 0)	
		close(fd_src);
	if (fd_src >= 0)	
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
	// ft_print_cmds(cmds.head);
	ft_free_cmds(cmds.head);
	return (1);
}
