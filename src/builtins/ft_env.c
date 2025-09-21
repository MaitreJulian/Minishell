/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:56:28 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/21 19:06:22 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_data *data, t_cmd *cmd_list)
{
	char	**env;
	int		i;

	i = 0;
	env = data->envc;
	if (cmd_list->cmd[1])
	{
		printf("env: %s: No such file or directory\n", data->cmd_list->cmd[1]);
		return ;
	}
	while (env[i])
	{
		if (!ft_strchr(env[i], '='))
			i++;
		else
		{
			printf("%s", env[i]);
			printf("\n");
			i++;
		}
	}
}
/*
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	ft_env(env);
	return (0);
}
*/
