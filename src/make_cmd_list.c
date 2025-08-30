/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:48 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/30 12:52:17 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*find_last(t_cmd *list)
{
	t_cmd	*node;

	node = list;
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	add_to_list(char *cmd_tab, t_cmd **cmd_list)
{
	t_cmd	*cmd_node;
	t_cmd	*last_cmd_node;

	printf("Dans add_to_list\n");
	if (!cmd_list)
		return ;
	cmd_node = malloc(sizeof(t_cmd));
	if (!cmd_node)
		return ;
	cmd_node->next = NULL;
	cmd_node->cmd = ft_split(cmd_tab, ' ');
	ft_redirection(&cmd_node);
	if (!(*cmd_list))
		*cmd_list = cmd_node;
	else
	{
		last_cmd_node = find_last(*cmd_list);
		last_cmd_node->next = cmd_node;
	}
}

/*
	Faut ajouter chaque t_list a la list_cmd. 
	Dans chaque noeud il faut split le cmd_tab[i] 
	et le mettre dans le **cmd qui ser le data->cmd_list->cmd. 
*/

t_cmd	*make_cmd_list(char *s)
{
	char	**cmd_tab;
	t_cmd	*cmd_list;
	int		i;

	printf("Dans make_cmd_list\n");
	i = 0;
	cmd_list = NULL;
	cmd_tab = ft_split(s, '|');
	while (cmd_tab[i])
	{
		add_to_list(cmd_tab[i], &cmd_list);
		i++;
	}
	cmd_list->n_cmd = i;
	free_tab(cmd_tab);
	return (cmd_list);
}