/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exportc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:12:49 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/02 12:28:11 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

char	**realloc_envp(char **envp, int new_size)//on realloue l'env avec 1 place en plus
{
	char	**new_envp;
	int		i;

	new_envp = malloc(sizeof(char *) * (new_size + 1));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
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

char	**new_env(char **nenv, char *new_v, int len)
{
	int		i;
	char	*temp;

	i = -1;
	while (nenv[++i])
	{
		if (strncmp(nenv[i], new_v, len) == 0 && nenv[i][len] == '=')//la variable existe deja on la remplace
		{
			temp = ft_strdup(new_v);
			free(nenv[i]);
			nenv[i] = temp;
			return (nenv);
		}
	}
	nenv = realloc_envp(nenv, i + 1);
	if (!nenv)
	{
		perror("Malloc in export failed:\n");
		return (nenv);
	}
	nenv[i] = ft_strdup(new_v);
	nenv[i + 1] = NULL;
	return (nenv);
}

char	**ft_export(char **envc, char **new_v)
{
	char	**nenv;
	int		len;

	nenv = copy_env(envc);
	free_tab(envc);
	while (*new_v)
	{
		if (!is_valid_identifier(*new_v))
		{
			printf("export: '%s not a valid identifier\n", *new_v);
			return (nenv);
		}
		len = ft_varlen(*new_v);
		if (!len)
			return (nenv);
		nenv = new_env(nenv, *new_v, len);
		new_v++;
	}
	return (nenv);
}
