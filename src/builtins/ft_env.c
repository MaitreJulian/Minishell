/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:56:28 by jvenkata          #+#    #+#             */
/*   Updated: 2025/07/10 11:20:55 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s", env[i]);
		printf("\n");
		i++;
	}
}
/*
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	ft_env(env);
	return (0);
}
*/
