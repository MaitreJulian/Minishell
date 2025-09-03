/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:39:02 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/03 11:32:01 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_child(t_data *data, t_cmd *cmd, int *pfd)
{
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
	else if (pfd[1] != -1)
	{
		dup2(pfd[1], STDOUT_FILENO);
	}
	if (pfd[0] != -1)
		close(pfd[0]);
	if (pfd[1] != -1)
		close(pfd[1]);
	ft_exec_builtin(data, cmd);
	exit(0);
}

void	do_parent(t_cmd *cmd, int *pfd)
{
	if (pfd[0] != -1)
	{
		if (cmd->next)
		{
			if (cmd->next->fd_in == STDIN_FILENO)
				cmd->next->fd_in = pfd[0];
			else
				close(pfd[0]);
		}
		else
			close(pfd[0]);
	}
	if (pfd[1] != -1)
		close(pfd[1]);
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	if (cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
}

void	wait_sig_pid(void)
{
	int		status;
	int		sig;
	pid_t	wpid;

	while (1)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == -1)
			break ;
		if (WIFSIGNALED(status))
		{
			sig = WTERMSIG(status);
			if (sig == SIGQUIT)
				write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
			else if (sig == SIGINT)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
		}
	}
	setup_signals();
}

void	exec_pipeline(t_data *data)
{
	t_cmd	*current;
	int		pfd[2];
	pid_t	pid;

	current = data->cmd_list;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (current)
	{
		if (current->next)
			pipe(pfd);
		else
		{
			pfd[0] = -1;
			pfd[1] = -1;
		}
		pid = fork();
		if (pid == 0)
			do_child(data, current, pfd);
		else
			do_parent(current, pfd);
		current = current->next;
	}
	wait_sig_pid();
}
