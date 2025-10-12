/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:14:35 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/12 19:11:09 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redirection(t_cmd **cmd_node, int i)
{
	if (!ft_strcmp((*cmd_node)->cmd[i], ">"))
		return (red_out(cmd_node, i));
	else if ((!ft_strcmp((*cmd_node)->cmd[i], ">>")))
		return (red_append(cmd_node, i));
	else if (!ft_strcmp((*cmd_node)->cmd[i], "<"))
		return (red_in(cmd_node, i));
	else if (!ft_strcmp((*cmd_node)->cmd[i], "<<"))
		return (red_heredoc(cmd_node, i));
	return (false);
}

bool	ft_red(t_cmd *cmd_node)
{
	int	i;

	i = 0;
	while (cmd_node->cmd[i])
	{
		if (!ft_strcmp(cmd_node->cmd[i], ">")
			|| !ft_strcmp(cmd_node->cmd[i], ">>")
			|| !ft_strcmp(cmd_node->cmd[i], "<")
			|| !ft_strcmp(cmd_node->cmd[i], "<<"))
			return (true);
		i++;
	}
	return (false);
}

int	ft_redirection(t_cmd **cmd_node)
{
	char	**new_cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*cmd_node)->fd_in = 0;
	(*cmd_node)->fd_out = 1;
	if (!ft_red(*cmd_node))
		return (0);
	new_cmd = malloc(sizeof(char *) * (len_tab((*cmd_node)->cmd) - 1));
	while ((*cmd_node)->cmd[i])
	{
		if (redirection(cmd_node, i))
			i += 2;
		else
			new_cmd[j++] = ft_strdup((*cmd_node)->cmd[i++]);
		if ((*cmd_node)->fd_in == -1 || (*cmd_node)->fd_out == -1)
			return (1);
	}
	new_cmd[j] = NULL;
	free_tab((*cmd_node)->cmd);
	(*cmd_node)->cmd = new_cmd;
	return (0);
}
