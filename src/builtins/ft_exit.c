/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:15:50 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/16 11:29:14 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *data, char *code)
{
	int			i;
	long long	exit_code;

	i = 0;
	if (!code)
	{
		printf("exit\n");
		free_everything (data);
		exit(0);
	}
	exit_code = ft_atoi(code);
	while (code[i] && ft_isdigit(code[i]))
		i++;
	if (code[i] && !ft_isdigit(code[i]))
		printf("exit : %s: numeric argument required\n", code);
	if (exit_code > 255 && exit_code < 9223372036854775807)
		exit_code = exit_code % 256;
	else if (exit_code > 9223372036854775807)
	{
		printf("exit : %s: numeric argument required\n", code);
		return ;
	}
	free_everything(data);
	printf("exit\n");
	exit (exit_code);
}
