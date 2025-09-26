/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:14 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/26 15:40:42 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
	int		i;
	bool	backsn;

	backsn = true;
	i = 1;
	if (args[i] && strncmp(args[i], "-n", 3) == 0 && args[i][3] == '\0')
	{
		backsn = false;
		i++;
	}
	while (args[i] != NULL)
	{
		write(1, args[i], strlen(args[i]));
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (backsn)
		printf("\n");
}
