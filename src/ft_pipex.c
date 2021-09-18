/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:01 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/18 14:28:28 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

static int	ft_write_to_file(fd_src, fd_dst)
{
	char	str[10];
	int		bytes;

	bytes = read(fd_src, str, 10);
	while (bytes >= 1)
	{
		if (write(fd_dst, str, bytes) == -1)
			return (0);
		bytes = read(fd_src, str, 10);
	}
	if (bytes == -1)
		return (0);
	return (1);
	
}

static int	ft_resolve(t_cmd *cmd, char **envp, int fd_read, int fd_write)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		return (ft_error("Pipe error : "));
	dup2(fd_read, 0);
	close(fd_read);
	if (cmd != NULL && cmd->next == NULL)
		dup2(fd_write, 1);
	else
		dup2(pipe_fd[1], 1);
	if (fork() == 0)
	{
		execve(cmd->cmd, cmd->full_cmd, envp);
		exit(0);
	}
	else
	{
		close(pipe_fd[1]);
		wait(NULL);
		if (cmd->next != NULL)
			return (ft_resolve(cmd->next, envp, pipe_fd[0], fd_write));
	}
	return (1);
}

int	ft_pipex(t_cmds *cmds, char **argv, int argn, char **envp)
{
	int	fd_src;
	int	fd_dst;

	if (ft_open(argv[argn - 1], O_RDWR | O_CREAT | O_TRUNC, &fd_dst) < 0)
		return (ft_file_error("File error with", argv[argn - 1]));
	if (ft_open(argv[0], O_RDONLY, &fd_src) < 0)
		return (ft_file_error("File error with", argv[0]));
	if (argv[1] == argv[argn - 1])
	{
		if (!ft_write_to_file(fd_src, fd_dst))
			ft_file_error("Read/write error with ", argv[1]);
	}
	else if (ft_parse_commands(cmds, &argv[1]))
		ft_resolve(cmds->head, envp, fd_src, fd_dst);
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
	if (argn < 3)
		return (0);
	else
	{
		ft_pipex(&cmds, &argv[1], argn - 1, envp);
	}
	ft_free_cmds(cmds.head);
	return (1);
}
