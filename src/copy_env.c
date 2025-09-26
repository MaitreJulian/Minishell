/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:13:40 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/25 13:57:31 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_shlvl(char **env)
{
	int		i;
	int		lvl;
	char	**temp;
	char	*nb;

	i = 0;
	temp = malloc(sizeof(char *) * 2);
	while (env[i] && ft_strncmp("SHLVL=", env[i], 6))
		i++;
	if (env[i] && !ft_strncmp("SHLVL=", env[i], 6))
	{
		lvl = ft_atoi(ft_memchr(env[i], '=', 6) + 1);
		lvl++;
		nb = ft_itoa(lvl);
		temp[0] = ft_strjoin("SHLVL=", nb);
		temp[1] = NULL;
		free(nb);
		env = ft_export(env, temp);
		free_tab(temp);
	}
	return (env);
}

char	**copy_env_init(char **envp)
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
		env_copy[count] = ft_strdup(envp[count]);
		if (!env_copy[count])
		{
			free_tab(env_copy);
			return (NULL);
		}
		count++;
	}
	env_copy[i] = NULL;
	env_copy = add_shlvl(env_copy);
	return (env_copy);
}
