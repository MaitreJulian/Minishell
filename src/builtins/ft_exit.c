/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:15:50 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/27 18:08:22 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exit_var(char *code)
{
	int	i;

	i = 0;
	while (code[i] == 32 || (code[i] >= 9 && code[i] <= 13))
		i++;
	if (code[i] == 43 || code[i] == 45)
		i++;
	while (code[i])
	{
		if (!ft_isdigit(code[i]))
			return (0);
		i++;
	}
	return (1);
}

void	exit2(t_data *data, int exit_code)
{
	free_everything(data);
	printf("exit\n");
	exit (exit_code);
}

void	ft_exit(t_data *data, char **code)
{
	int			i;
	long long	exit_code;

	i = 0;
	if (code[1] && code[2])
	{
		printf("exit : too many arguments\n");
		data->exit_status = 1;
		return ;
	}
	if (!code[1])
		exit2(data, data->exit_status);
	exit_code = ft_atoi(code[1]);
	if (!check_exit_var(code[1]) || exit_code > 9223372036854775807)
	{
		printf("exit : %s: numeric argument required\n", code[1]);
		data->exit_status = 2;
		return ;
	}
	if (exit_code > 255 && exit_code < 9223372036854775807)
		exit_code = exit_code % 256;
	exit2(data, exit_code);
}
