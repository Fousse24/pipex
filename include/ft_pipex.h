/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:35 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/09 19:41:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# define PATH_DIR	"~sfournie/Projects/pipex/"
# define PATH_BIN	"/bin/"
# define PATH_SBIN	"/sbin/"
# define PATH_UBIN	"/usr/bin/"
# define PATH_USBIN	"/usr/sbin/"

// Error handling
int		ft_error(char *msg);
int		ft_file_error(char *msg, char *path);

// File handling
int		ft_open(char *args, int mode, int *fd);

// Commands handling
int	ft_check_commands(char **cmds, char *file, char **envp);

// String functions
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif