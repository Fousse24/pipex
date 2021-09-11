/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:45:24 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/09 19:03:06 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1 != NULL && *s1)
		new[i++] = *(s1++);
	while (s2 != NULL && *s2)
		new[i++] = *(s2++);
	new[i] = '\0';
	return (new);
	 
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str != NULL)
		while (str[count])
			count++;
	return (count);	
}
