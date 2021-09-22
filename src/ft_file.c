/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:28:32 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/22 15:07:27 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

int	ft_open(char *path, int mode, int *fd)
{	
	if (fd != NULL)
		*fd = open(path, mode, 0777);
	else
		return (-1);
	return (*fd);
}

char	*ft_join_path_file(char const *path, char const *file)
{
	int		i;
	size_t	size;
	char	*str;

	if (path == NULL || file == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(path) + ft_strlen(file) + 2;
	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (*path)
		str[i++] = *(path++);
	str[i++] = '/';
	while (*file)
		str[i++] = *(file++);
	str[i] = '\0';
	return (str);
}
