/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:14 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/14 15:19:53 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	flags(char *arg)
{
	int	i;

	i = 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(char **args, t_data *data)
{
	int		i;
	bool	backsn;

	backsn = true;
	i = 1;
	while (args[i] && ft_strncmp(args[i], "-n", 2) == 0)
	{
		if (!flags(args[i]))
			break ;
		backsn = false;
		i++;
	}
	while (args[i] != NULL)
	{
		write(1, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (backsn)
		printf("\n");
	data->exit_status = 0;
}
