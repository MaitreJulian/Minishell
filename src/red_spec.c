/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:27:42 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/30 12:38:56 by jvenkata         ###   ########.fr       */
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

void	write_heredoc(int fd, char *delim)
{
	char	*line;

	while (1)
	{
		write(1, "> ", 2);
		line = readline(NULL);
		if (!line)
			break ;
		if (strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

bool	red_heredoc(t_cmd **cmd_node, int i)
{
	int		fd;
	char	*delim;

	delim = (*cmd_node)->cmd[i + 1];
	fd = open("/tmp/heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open failed");
		return (false);
	}
	write_heredoc(fd, delim);
	close(fd);
	fd = open("/tmp/heredoc_tmp", O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		return (false);
	}
	(*cmd_node)->fd_in = fd;
	unlink("/tmp/heredoc_tmp");
	return (true);
}
