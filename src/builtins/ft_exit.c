/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:15:50 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/08 11:08:07 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_exit(t_data *data, char *code)
{
	int	i;

	i = 0;
	while (code[i] && ft_isdigit(code[i]))
		i++;
	if (code[i] && !ft_isdigit(code[i]))
	{
		printf("exit : %s: numeric argument required\n", code);
		return (false);
	}
	free_everything (data);
	exit (ft_atoi(code));
	return (true);
}
