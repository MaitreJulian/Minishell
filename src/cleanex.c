/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:43:43 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/29 14:36:54 by jowoundi         ###   ########.fr       */
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

void	clean_block(t_pars *line)
{
	t_pars	*runner;

	runner = line;
	while (runner != NULL)
	{
		if (runner->type == RED_IN || runner->type == RED_OUT)
			redir(&runner->block, &runner->type);
		expander(&runner->block, runner->type);
		runner = runner->next;
	}
}
