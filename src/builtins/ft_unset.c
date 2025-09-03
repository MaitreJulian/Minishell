/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:18:00 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/03 18:09:48 by jvenkata         ###   ########.fr       */
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
	char	temp;

	i = 0;
	j = 0;
	new_env = malloc(sizeof(char *) * len_env(envc));
	while (envc[i])
	{
		if (strncmp(envc[i], v_env_del, len) == 0 && envc[i][len] == '=')
			i++;
		else
		{
			temp = ft_strdup(v_env_del);
			free(new_env[i]);
			new_env[i] = temp;
			return (new_env);
		}
	}
	free_tab(envc);
	new_env[j] = NULL;
	return (new_env);
}

char	**ft_unset(char **envc, char **v_env_del)
{
	int		len;

	free_tab(envc);
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
