/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeornot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:31:09 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/10 16:18:55 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_or_not(t_data *data)
{
	if (data->cmd_list->n_cmd == 1 && is_builtin(data->cmd_list->cmd[0]))
	{
		ft_exec_builtin(data, data->cmd_list);
	}
	else
	{
		exec_pipeline(data);
	}
}
