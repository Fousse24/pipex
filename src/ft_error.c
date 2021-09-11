/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:48:05 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/09 19:20:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

int	ft_error(char *msg)
{
	perror(msg);
	return (0);
}

int	ft_file_error(char *msg, char *path)
{
	write(1, msg, ft_strlen(msg));
	if (path != NULL)
	{
		write(1, " ", 1);
		write(1, "\"", 1);
		write(1, path, ft_strlen(path));
		write(1, "\"", 1);
	}
	perror(" ");
	return (0);
}
