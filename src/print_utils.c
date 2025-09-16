/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:56:10 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/16 11:56:16 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
