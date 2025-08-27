/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/26 19:02:03 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	char	*line;
	t_data	*luthor;
	t_cmd	*f_struct;

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
	}
	return (0);
}
