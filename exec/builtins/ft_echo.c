/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:35:14 by jvenkata          #+#    #+#             */
/*   Updated: 2025/07/10 11:20:30 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
	int		i;
	bool	backsn;//Pour voir si on retoure a la ligne

	backsn = true;
	i = 1;//1 psk on ne veut pas "echo"
	if (strncmp(args[i], "-n", 3) == 0)//Je verifie que si il y a le flag -n
	{
		backsn = false;
		i++;
	}
	while (args[i] != NULL)
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (backsn)
		printf("\n");
}
/*
int main()
{
	char *args[] = {"echo", "-n", "hello", "world", NULL};
	ft_echo(args);
	return 0;
}
*/
