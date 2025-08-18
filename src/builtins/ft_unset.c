/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:18:00 by jvenkata          #+#    #+#             */
/*   Updated: 2025/07/11 12:37:49 by jvenkata         ###   ########.fr       */
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

char	**ft_unset(char **envc, char *v_env_del)//la copie d'environnement et variable à enlever
{
	int		i;
	char	**new_env;
	int		j;
	int		len;

	len = ft_strlen(v_env_del);
	i = 0;
	j = 0;

	if (!in_env(envc, v_env_del, len))
		return (envc);//Pas de variable existante
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envc[i])
	{
		if (strncmp(envc[i], v_env_del, len) == 0 && envc[i][len] == '=')
			i++;// on saute celle qu'on veut supprimer
		else
			new_env[j++] = strdup(envc[i]);
	}
	new_env[j] = NULL;// Terminer le tableau
	return (new_env);
}
