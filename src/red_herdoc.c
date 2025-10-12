/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_herdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:11:28 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/12 19:13:29 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parent(int fd, t_cmd **cmd_node, int pid)
{
	int		status;

	close(fd);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		g_var = 130;
		unlink("/tmp/heredoc_tmp");
		write(1, "\n", 1);
		(*cmd_node)->fd_in = -1;
		setup_signals();
		return (true);
	}
	fd = open("/tmp/heredoc_tmp", O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		return (false);
	}
	(*cmd_node)->fd_in = fd;
	unlink("/tmp/heredoc_tmp");
	setup_signals();
	return (true);
}

void	write_heredoc(int fd, char *delim)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
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
	close(fd);
}

bool	red_heredoc(t_cmd **cmd_node, int i)
{
	int		fd;
	char	*delim;
	pid_t	pid;

	delim = (*cmd_node)->cmd[i + 1];
	fd = open("/tmp/heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open failed");
		return (false);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		close(fd);
		return (false);
	}
	else if (pid == 0)
	{
		write_heredoc(fd, delim);
		exit(0);
	}
	else
		return (parent(fd, cmd_node, pid));
}
