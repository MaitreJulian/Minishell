/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:34:02 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/09 18:32:13 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_cmd	*free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;
	int		i;

	while (cmd_list)
	{
		tmp = cmd_list->next;
		if (cmd_list->cmd)
		{
			i = 0;
			while (cmd_list->cmd[i])
			{
				free(cmd_list->cmd[i]);
				i++;
			}
			free(cmd_list->cmd);
		}
		free(cmd_list);
		cmd_list = tmp;
	}
    return (NULL);
}

void	free_everything(t_data *data)
{
	data->cmd_list = free_cmd_list(data->cmd_list);
	free_tab(data->envc);
	free(data);
	return ;
}

void	free_pars(t_pars *pars_struct)
{
	t_pars	*tmp;

	while (pars_struct)
	{
		tmp = pars_struct->next;
		free(pars_struct->block);
		free(pars_struct);
		pars_struct = tmp;
	}
	pars_struct = NULL;
}
