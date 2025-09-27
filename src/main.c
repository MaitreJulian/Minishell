/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/27 11:20:39 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_var = 0;

void	check_gvar(t_data *data)
{
	if (g_var != 0)
	{
		data->exit_status = g_var;
		g_var = 0;
	}
}

t_data	*init_data(char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmd_list = NULL;
	data->exit_status = 0;
	data->envc = copy_env_init(env, data);
	return (data);
}

void	eof(t_data *data)
{
	free_everything(data);
	rl_clear_history();
	printf("exit\n");
	exit(0);
}

void	ft_minishell(t_data *data)
{
	t_pars	*luthor;
	char	*input;

	while (1)
	{
		input = readline("Minishell > ");
		check_gvar(data);
		if (!input)
			eof(data);
		if (input[0] == '\0' || only_space(input))
		{
			free(input);
			continue ;
		}
		if (ft_strlen(input) > 0)
			add_history(input);
		luthor = lexing(input, data);
		if (parsing(luthor, data) == 0)
			continue ;
		data->cmd_list = fill_struct(luthor);
		pipe_or_not(data);
		if (!(input[0] == '\0'))
			data->cmd_list = free_cmd_list(data->cmd_list);
		free(input);
	}
}

int	main(int ac, char **argv, char **env)
{
	t_data	*data;

	(void)argv;
	if (ac != 1)
		return (1);
	setup_signals();
	data = init_data(env);
	ft_minishell(data);
}
