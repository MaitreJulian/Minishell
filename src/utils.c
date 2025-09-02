/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:22:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/02 10:27:30 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_varlen(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '=' && str[i])
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
