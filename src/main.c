/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/03 15:28:00 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*init_data(char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->envc = copy_env(env);
	return (data);
}

int	main(int ac, char **argv, char **env)
{
	char	*input;
	t_data	*data;
	t_pars	*luthor;
	t_cmd	*f_struct;

	(void)argv;
	if (ac != 1)
		return (1);
	setup_signals();
	data = init_data(env);
	while (1)
	{
		input = readline("Minishell > ");
		if (!input)
		{
			rl_clear_history();
			printf("exit\n");
			exit(0);
		}
		if (ft_strlen(input) > 0)
			add_history(input);
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		luthor = lexing(input, data);
		if (parsing(luthor) == 0)
			continue ;
		f_struct = fill_struct(luthor);
		data->cmd_list = f_struct;
		pipe_or_not(data);
		if (!(input[0] == '\0'))
			free_cmd_list(data->cmd_list);
		free(input);
	}
}
