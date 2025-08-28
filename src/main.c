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


t_data	*init_data(char **envp, t_cmd *f_struct)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->envc = copy_env(envp);
	data->cmd_list = f_struct;
	return (data);
}

int	main(int ac, char **argv, char **env)
{
	char	*input;
	t_data	*data;
	t_list	*luthor;
	t_cmd	*f_struct;

	(void)argv;
	if (ac != 1)
		return (1);
	
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
		luthor = lexing(input);
		if (parsing(luthor) == 0)
				continue ;
		f_struct = fill_struct(luthor);
		data = init_data(env, f_struct);
		pipe_or_not(data);
		if (!(input[0] == '\0'))
			free_cmd_list(data->cmd_list);
		free(input);
	}
}
