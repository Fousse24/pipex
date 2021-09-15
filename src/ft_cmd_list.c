/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:47:32 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/15 10:03:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

t_cmd	*ft_new_cmd(char *cmd_path, char **full_cmd)
{	
	int		i;
	int		count;
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->cmd = cmd_path;
	cmd->full_cmd = full_cmd;
	if (full_cmd != NULL)
		cmd->args = &full_cmd[1];
	else
		cmd->args = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

void	ft_add_front(t_cmds *cmds, t_cmd *new)
{
	if (cmds == NULL)
		return ;
	if (cmds->head == NULL)
	{
		cmds->head = new;
		cmds->tail = new;
	}
	else if (new != NULL)
	{
		new->next = cmds->head;
		cmds->head->prev = new;
		cmds->head = new;
	}
	cmds->count++;
}

void	ft_add_back(t_cmds *cmds, t_cmd *new)
{
	if (cmds == NULL)
		return ;
	if (cmds->head == NULL)
	{
		cmds->head = new;
		cmds->tail = new;
	}
	else if (new != NULL)
	{
		new->prev = cmds->tail;
		cmds->tail->next = new;
		cmds->tail = new;
	}
	cmds->count++;
}

void	ft_free_cmds(t_cmd *cmd)
{
	int	i;

	if (cmd != NULL)
	{
		i = 0;
		if (cmd->next != NULL)
			ft_free_cmds(cmd->next);
		if (cmd->cmd != NULL)
			free(cmd->cmd);
		if (cmd->full_cmd != NULL)
		{
			ft_free_split(cmd->full_cmd);
		}
		free(cmd);
	}
}

void	ft_print_cmds(t_cmd *cmd)
{
	t_cmd	*temp;
	int		i;

	temp = cmd;
	while (temp != NULL)
	{	
		i = 0;
		if (temp->cmd != NULL)
		{
			ft_putstr_fd(temp->cmd, 1);
			while (temp->args != NULL && temp->args[i] != NULL)
			{
				ft_putstr_fd(temp->args[i++], 1);
			}
			ft_putendl_fd(NULL, 1);
		}
		temp = temp->next;
	}
}
