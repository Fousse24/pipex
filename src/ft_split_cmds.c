/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:40:51 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/15 09:16:00 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

static void	*ft_freesplit(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		free(s[i++]);
	free(s);
	return (NULL);
}

static size_t	ft_countwords(char const *s, char delimiter)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[++i])
	{
		if (s[i] && s[i] == delimiter && s[i - 1] != delimiter)
			count++;
	}
	if (i != 0 && s[i - 1] != delimiter)
		count++;
	return (count);
}

static size_t	ft_countchar(char const *s, size_t pos, char delimiter)
{
	size_t	count;

	count = 0;
	while (s[pos] && s[pos] != delimiter)
	{
		count++;
		pos++;
	}
	return (count);
}

static	char	*ft_moveword(char const *s, size_t *pos, char delimiter, int index)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_countchar(s, *pos, delimiter);
	// if (index != 0)
	// 	size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	// if (index != 0)
	// 	str[i++] = ' ';
	while (i < size)
	{
		str[i++] = s[*pos];
		*pos = *pos + 1;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split_cmds(char const *args, char c)
{
	char	**split;
	size_t	i;
	size_t	pos;
	size_t	words;

	if (args == NULL)
		return (NULL);
	pos = -1;
	i = 0;
	words = ft_countwords(args, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	while (words != 0 && args[++pos] && pos < ft_strlen(args))
	{
		if (args[pos] != c)
		{
			split[i] = ft_moveword(args, &pos, c, i);
			if (split[i++] == NULL)
				return (ft_freesplit(split));
		}
	}
	split[i] = NULL;
	return (split);
}