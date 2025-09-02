/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:18:00 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/02 14:51:23 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_env(char **envc)
{
	int	i;

	i = 0;
	while (envc[i])
		i++;
	return (i);
}

int	in_env(char **envc, char *v_env_del, int len)
{
	int		i;

	i = 0;
	while (envc[i])
	{
		if (strncmp(envc[i], v_env_del, len) == 0 && envc[i][len] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	**unset_env(char **envc, char *v_env_del, int len)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_env = malloc(sizeof(char *) * len_env(envc));
	while (envc[i])
	{
		if (strncmp(envc[i], v_env_del, len) == 0 && envc[i][len] == '=')
			i++;
		else
			new_env[j++] = strdup(envc[i++]);
	}
	free_tab(envc);
	new_env[j] = NULL;
	return (new_env);
}

char	**ft_unset(char **envc, char **v_env_del)
{
	char	**new_env;
	int		len;

	new_env = copy_env(envc);
	free_tab(envc);
	while (*v_env_del)
	{
		len = ft_strlen(*v_env_del);
		if (!in_env(new_env, *v_env_del, len))
			return (new_env);
		new_env = unset_env(new_env, *v_env_del, len);
		if (!new_env)
		{
			perror("Unset failed :");
			return (new_env);
		}
		v_env_del++;
	}
	return (new_env);
}
