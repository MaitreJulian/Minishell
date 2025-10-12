/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:27:42 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/12 19:07:52 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	red_out(t_cmd **cmd_node, int i)
{
	(*cmd_node)->fd_out = open((*cmd_node)->cmd[i + 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if ((*cmd_node)->fd_out == -1)
	{
		perror("open failed");
		return (false);
	}
	return (true);
}

bool	red_append(t_cmd **cmd_node, int i)
{
	(*cmd_node)->fd_out = open((*cmd_node)->cmd[i + 1], O_WRONLY
			| O_CREAT | O_APPEND, 0644);
	if ((*cmd_node)->fd_out == -1)
	{
		perror("open failed");
		return (false);
	}
	return (true);
}

bool	red_in(t_cmd **cmd_node, int i)
{
	(*cmd_node)->fd_in = open((*cmd_node)->cmd[i + 1], O_RDONLY);
	if ((*cmd_node)->fd_in == -1)
	{
		perror("open failed");
		return (false);
	}
	return (true);
}
