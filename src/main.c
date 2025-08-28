/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/07/24 16:43:50 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/27 16:21:27 by jvenkata         ###   ########.fr       */
=======
/*   Created: 2025/06/03 11:52:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/26 19:02:03 by jowoundi         ###   ########.fr       */
>>>>>>> justin
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	char	*line;
	t_data	*luthor;
	t_cmd	*f_struct;

<<<<<<< HEAD
	tmp = cmd_list;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			printf("'%s' ", tmp->cmd[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}


t_data	*init_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmd_list = NULL;
	data->envc = copy_env(envp);
	data->token_list = NULL;
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init_data(env);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		input = readline("Minishell > ");
		// data = lexing(&data, input);
		// if (parsing(&data) == 0)
		// 	printf("parsing error\n");
		if (ft_strlen(input) > 0)
			add_history(input);
		if (!input)
		{
			rl_clear_history();
			printf("exit\n");
			exit(0);
		}
		if (input != NULL && *input != '\0')
		{
			printf("Vous avez entré : %s\n", input);
			data->cmd_list = make_cmd_list(input, data);
			if (data->cmd_list == NULL)
				return (1);
			print_cmd_list(data->cmd_list);
		}
		if (input != NULL && *input != '\0')
			pipe_or_not(data);
		if (!(input[0] == '\0'))
			free_cmd_list(data->cmd_list);
		free(input);
=======
	(void)av;
	if (ac != 1)
		return (1);
	while (1)
	{
		line = readline("Minishell > ");
		if (ft_strlen(line) > 0)
			add_history(line);
		luthor = lexing(line);
		if (parsing(luthor) == 0)
			continue ;
		f_struct = fill_struct(luthor);
>>>>>>> justin
	}
	return (0);
}
