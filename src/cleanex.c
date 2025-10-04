/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:43:43 by jowoundi          #+#    #+#             */
/*   Updated: 2025/10/04 10:49:10 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir(char **str, int *type)
{
	if (*type == RED_IN)
	{
		if (ft_strlen(*str) > 1)
			*type = HEREDOC;
	}
	else if (*type == RED_OUT)
	{
		if (ft_strlen(*str) > 1)
			*type = RED_APP;
	}
}

void	clean_block(t_pars *line, t_data *data)
{
	t_pars	*runner;

	runner = line;
	while (runner != NULL)
	{
		if (runner->type == RED_IN || runner->type == RED_OUT)
			redir(&runner->block, &runner->type);
		if (runner->type == HEREDOC && runner->next)
			runner = runner->next;
		else
			expander(&runner->block, runner->type, data);
		runner = runner->next;
	}
}
