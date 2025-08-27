/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:13:40 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/27 16:16:45 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	**copy_env(char **envp)
{
	int		i;
	int		count;
	char	**env_copy;

	count = 0;
	i = 0;
	while (envp[i])
		i++;
	env_copy = malloc(sizeof(char *) * (i + 1));
	if (!env_copy)
		return (NULL);
	while (count < i)
	{
		env_copy[count] = strdup(envp[count]);
		if (!env_copy[count])
		{
			while (i-- > 0)
				free(env_copy[i]);
			free(env_copy);
			return (NULL);
		}
		count++;
	}
	env_copy[i] = NULL;
	return (env_copy);
}
