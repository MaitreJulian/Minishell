/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:18:00 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/24 16:42:46 by jvenkata         ###   ########.fr       */
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
		if (strncmp(envc[i], v_env_del, len) == 0
			&& (envc[i][len] == '=' || envc[i][len] == '\0'))
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
	if (!new_env)
		return (envc);
	while (envc[i])
	{
		if (ft_strncmp(envc[i], v_env_del, len) == 0
			&& (envc[i][len] == '=' || envc[i][len] == '\0'))
			i++;
		else
			new_env[j++] = ft_strdup(envc[i++]);
	}
	free_tab(envc);
	new_env[j] = NULL;
	return (new_env);
}

char	**ft_unset(char **envc, char **v_env_del)
{
	int		len;

	while (*v_env_del)
	{
		len = ft_strlen(*v_env_del);
		if (!in_env(envc, *v_env_del, len))
			return (envc);
		envc = unset_env(envc, *v_env_del, len);
		if (!envc)
		{
			perror("Unset failed :");
			return (envc);
		}
		v_env_del++;
	}
	return (envc);
}
