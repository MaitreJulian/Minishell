/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:14:35 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/19 19:00:50 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redirection(t_cmd **cmd_node, int i, t_data *data)
{
	if (!strcmp((*cmd_node)->cmd[i], ">"))
		return (red_out(cmd_node, data, i));
	else if ((!strcmp((*cmd_node)->cmd[i], ">>")))
		return (red_append(cmd_node, data, i));
	else if (!strcmp((*cmd_node)->cmd[i], "<"))
		return (red_in(cmd_node, data, i));
	else if (!strcmp((*cmd_node)->cmd[i], "<<"))
		return (red_heredoc(cmd_node, data, i));
	if ((*cmd_node)->fd_in == -1 || (*cmd_node)->fd_out == -1)
	{
		perror("open failed");
		ft_exit(data);
	}
	return (false);
}

bool	ft_red(t_cmd *cmd_node)
{
	int	i;

	i = 0;
	while (cmd_node->cmd[i])
	{
		if (!strcmp(cmd_node->cmd[i], ">")
			|| (!strcmp(cmd_node->cmd[i], ">>"))
			|| !strcmp(cmd_node->cmd[i], "<"))
			return (true);
		i++;
	}
	return (false);
}

void	ft_redirection(t_cmd **cmd_node, t_data *data)
{
	char	**new_cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*cmd_node)->fd_in = 0;
	(*cmd_node)->fd_out = 1;
	if (!ft_red(*cmd_node))
		return ;
	new_cmd = malloc(sizeof(char *) * (len_tab((*cmd_node)->cmd) - 1));
	while ((*cmd_node)->cmd[i])
	{
		if (redirection(cmd_node, i, data))
			i += 2;
		else
			new_cmd[j++] = ft_strdup((*cmd_node)->cmd[i++]);
	}
	new_cmd[j] = NULL;
	free_tab((*cmd_node)->cmd);
	(*cmd_node)->cmd = new_cmd;
}
