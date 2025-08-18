/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:34:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/18 11:45:33 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_exec_builtin(t_data *data, t_cmd *cmd_list)
{
	if (is_builtin(cmd_list->cmd[0]))
	{
		// printf("Builtin detected: %s\n", cmd_list->cmd[0]);
		launch_builtin(data, cmd_list); //Pas besoin de exit ici psk les builtins gere eux meme l'erreur
	}
	else
	{
		// printf("External command: %s\n", cmd_list->cmd[0]);
		ft_execve(cmd_list->cmd, data->envc);
		ft_exit(data);//En cas d'erreur
	}
}