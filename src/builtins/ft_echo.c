/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:14 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/02 10:27:00 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

#include "minishell.h"

void	ft_echo(char **args)
{
	int		i;
	bool	backsn;

	backsn = true;
	i = 1;
	if (strncmp(args[i], "-n", 3) == 0)//Je verifie que si il y a le flag -n
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

// int main()
// {
// 	char *args[] = {"echo", "hello", "world", NULL};
// 	char *argds[] = {"echo", "-n", "fils de", "pute", NULL};
// 	ft_echo(args);
// 	ft_echo(argds);
	
// 	return 0;
// }

