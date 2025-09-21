/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:46:48 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/21 19:07:17 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(char *cmd)
{
	if (!cmd)
		return (false);
	if (!ft_strcmp("echo", cmd) || !ft_strcmp("cd", cmd)
		|| !ft_strcmp("pwd", cmd) || !ft_strcmp("export", cmd)
		|| !ft_strcmp("unset", cmd) || !ft_strcmp("env", cmd)
		|| !ft_strcmp("exit", cmd))
		return (true);
	return (false);
}

bool	is_nofork_builtin(char *cmd)
{
	if (!cmd)
		return (false);
	if (!ft_strcmp("cd", cmd) || !ft_strcmp("export", cmd)
		|| !ft_strcmp("unset", cmd) || !ft_strcmp("exit", cmd))
		return (true);
	return (false);
}

bool	do_builtin(t_data *data, t_cmd *cmd_list)
{
	bool	ok;

	ok = true;
	if (!ft_strcmp("echo", cmd_list->cmd[0]))
		ft_echo(cmd_list->cmd);
	else if (!ft_strcmp("cd", cmd_list->cmd[0]))
		cmd_list->cmd = ft_cd(data, cmd_list->cmd);
	else if (!ft_strcmp("pwd", cmd_list->cmd[0]))
		ft_pwd(data->envc);
	else if (!ft_strcmp("export", cmd_list->cmd[0]))
		data->envc = ft_export(data->envc, cmd_list->cmd + 1);
	else if (!ft_strcmp("unset", cmd_list->cmd[0]))
		data->envc = ft_unset(data->envc, cmd_list->cmd + 1);
	else if (!ft_strcmp("env", cmd_list->cmd[0]))
		ft_env(data, cmd_list);
	else if (!ft_strcmp("exit", cmd_list->cmd[0]))
		ft_exit(data, cmd_list->cmd);
	if (!ok)
		return (false);
	return (true);
}

void	launch_builtin(t_data *data, t_cmd *cmd_list)
{
	if (!do_builtin(data, cmd_list))
		return ;
}
