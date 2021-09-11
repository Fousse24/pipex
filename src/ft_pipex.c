/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:01 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/09 19:44:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

int	ft_pipex(char **argv, int argn, char **envp)
{
	int	fd_src;
	int	fd_dst;
	
	if (ft_open(argv[argn - 1], O_RDONLY | O_CREAT, &fd_dst) < 0)
		return (ft_file_error("File error with", argv[argn - 1]));
	if (ft_open(argv[0], O_RDONLY, &fd_src) < 0)
		return (ft_file_error("File error with", argv[0]));
	if (ft_check_commands(&argv[1], argv[0], envp))
		return (1);
	
	close(fd_src);
	close(fd_dst);
	return (1);
}

int	main(int argn, char **argv, char **envp)
{
	if (argn < 3) //CHANGE IT
		return (0);
	else
	{
		ft_pipex(&argv[1], argn - 1, envp);
	}
	return (1);
}