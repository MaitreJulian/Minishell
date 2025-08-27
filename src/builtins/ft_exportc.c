/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exportc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:12:49 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/27 16:40:45 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i]);
		i++;
	}
}

char	**realloc_envp(char **envp, int new_size)
{
	char	**new_envp;
	int		i;

	new_envp = malloc(sizeof(char *) * (new_size + 1));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_envp[i] = strdup(envp[i]);
		if (!new_envp[i])
		{
			while (--i >= 0)
				free(new_envp[i]);
			free(new_envp);
			return (NULL);
		}
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}

bool	check_var(char *new_var)
{
	if (!new_var || !strchr(new_var, '='))
	{
		printf("export: new_variable invalid: %s\n", new_var);
		return (false);
	}
	return (true);
}

char	**ft_export(char **envc, char *new_v)
{
	int		i;
	char	**new_envp;
	int		len_name;

	if (!check_var(new_v))
		return (envc);
	i = -1;
	len_name = ft_varlen(new_v);
	while (envc[++i])
	{
		if (strncmp(envc[i], new_v, len_name) == 0 && envc[i][len_name] == '=')// La variable existe, on la remplace
		{
			free(envc[i]);
			envc[i] = strdup(new_v);
			return (envc);
		}
	}
	new_envp = realloc_envp(envc, i + 1);// La variable n'existe pas encore, on l'ajoute
	if (!new_envp)
		return (envc);
	new_envp[i] = strdup(new_v);
	new_envp[i + 1] = NULL;
	return (new_envp);
}
