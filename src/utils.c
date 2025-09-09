/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:22:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/09 16:29:59 by jowoundi         ###   ########.fr       */
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

void	print_list(t_pars *list)
{
	t_pars	*node;

	node = list;
	while (node != NULL)
	{
		printf("TYPE : [%d], STR :[%s]\n", node->type, node->block);
		node = node->next;
	}
}

void	new_print(t_cmd *line)
{
	t_cmd	*runner;
	int		i;

	runner = line;
	while (runner)
	{
		i = 0;
		printf("__________\n");
		while (runner->cmd[i])
		{
			printf("STR : [%s]\n", runner->cmd[i]);
			i++;
		}
		runner = runner->next;
	}
}
