/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:27:04 by jvenkata          #+#    #+#             */
/*   Updated: 2025/07/10 11:15:57 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_pwd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PWD", 3) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

void	ft_pwd(char **env)
{
	printf("%s", search_pwd(env));
	printf("\n");
}
