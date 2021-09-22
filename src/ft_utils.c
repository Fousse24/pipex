/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:32:07 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/22 15:04:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

void	ft_free_split(char **split)
{
	int	i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
			free(split[i++]);
		free(split);
	}
}
