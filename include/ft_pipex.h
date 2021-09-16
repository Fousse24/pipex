/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:35 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/16 16:03:11 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# define PATH_DIR	"~sfournie/Projects/pipex/"
# define PATH_BIN	"/bin/"
# define PATH_SBIN	"/sbin/"
# define PATH_UBIN	"/usr/bin/"
# define PATH_USBIN	"/usr/sbin/"

typedef struct s_cmd
{
	char			**full_cmd;
	char			*cmd;
	char			**args;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef struct s_cmds
{
	t_cmd	*head;
	t_cmd	*tail;
	int		count;
}				t_cmds;

// Main program
int		ft_pipex(t_cmds *cmds, char **argv, int argn, char **envp);

// Error handling
int		ft_error(char *msg);
int		ft_file_error(char *msg, char *path);

// File handling
int		ft_open(char *args, int mode, int *fd);

// Commands handling
int		ft_parse_commands(t_cmds *lst, char **args);

// List (commands) handling
t_cmd	*ft_new_cmd(char *cmd_path, char **full_cmd);
void	ft_add_front(t_cmds *cmds, t_cmd *new);
void	ft_add_back(t_cmds *cmds, t_cmd *new);
void	ft_print_cmds(t_cmd *cmd);
char	**ft_split_cmds(char const *args, char c);

// Memory handling
void	ft_free_split(char **split);
void	ft_free_cmds(t_cmd *cmd);

#endif