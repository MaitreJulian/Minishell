/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:54:44 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/26 19:08:30 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type_of_c(char c)
{
	if (ft_isspace(c) == 1)
		return (ESPACE);
	else if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (RED_OUT);
	else if (c == '<')
		return (RED_IN);
	else
		return (WORD);
}

int	c_sep(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'')
		return (S_QUOTE);
	else if (c == '"')
		return (D_QUOTE);
	return (0);
}

int	ft_issep(int type)
{
	if (type == RED_OUT || type == RED_IN)
		return (1);
	else if (type == HEREDOC || type == RED_APP)
		return (1);
	else
		return (0);
}
