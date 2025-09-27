/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:22:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/27 11:30:40 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_varlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}

int	len_tab(char **tb)
{
	int	i;

	i = 0;
	if (tb && tb[i])
	{
		while (tb[i])
			i++;
	}
	return (i);
}

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

char	**ft_realloc_cmd(char **cmd_list)
{
	char	**new_cmd_list;

	if (!cmd_list)
		return (NULL);
	if (!cmd_list[1])
	{
		new_cmd_list = malloc (sizeof(char *) * 3);
		new_cmd_list[0] = ft_strdup(cmd_list[0]);
		new_cmd_list[1] = ft_strdup("");
		new_cmd_list[2] = NULL;
		free_tab(cmd_list);
		return (new_cmd_list);
	}
	return (cmd_list);
}

int	only_space(char *input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		if (input[i] != ' ')
			break ;
		i++;
	}
	if (input[i] != '\0')
		return (0);
	return (1);
}
