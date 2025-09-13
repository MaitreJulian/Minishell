/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:27:04 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/13 10:38:07 by julian           ###   ########.fr       */
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
			return (env[i] + 4);
		i++;
	}
	return (NULL);
}

void	ft_pwd(char **env)
{
	printf("%s", search_pwd(env));
	printf("\n");
}
