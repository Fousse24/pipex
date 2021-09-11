/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:28:32 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/09 16:41:19 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

int	ft_open(char *path, int mode, int *fd)
{	
	if (fd != NULL)
		*fd = open(path, mode);
	else
		return (-1);
	return (*fd);
}
