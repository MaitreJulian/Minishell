/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:53:24 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 18:15:28 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pars	*create_node(char *str, int type)
{
	t_pars	*new_node;

	new_node = malloc(sizeof(t_pars));
	if (!new_node)
		return (NULL);
	printf("ALLOC NODE [%s] type=%d @%p\n", str, type, new_node);
	new_node->block = ft_strdup(str);
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

void	fill_block(t_pars **data, char *str, int type)
{
	t_pars	*mew_node;
	t_pars	*temp;

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
