/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:53:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/28 18:31:36 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*create_node(char *str, int type)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->block = ft_strdup(str);
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

void	fill_block(t_list **data, char *str, int type)
{
	t_list	*mew_node;
	t_list	*temp;

	mew_node = create_node(str, type);
	if (!mew_node)
		return ;
	if (!*data)
	{
		*data = mew_node;
		return ;
	}
	temp = *data;
	while (temp->next)
		temp = temp->next;
	temp->next = mew_node;
}
