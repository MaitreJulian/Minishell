/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:15:50 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/10 14:46:40 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_exit(t_data *data, char *code)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = ft_atoi(code);
	while (code[i] && ft_isdigit(code[i]))
		i++;
	if (code[i] && !ft_isdigit(code[i]))
	{
		printf("exit : %s: numeric argument required\n", code);
		return (false);
	}
	if (exit_code > 255)
		exit_code = exit_code % 256;
	free_everything (data);
	exit (exit_code);
	return (true);
}
