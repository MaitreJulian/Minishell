/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:49:53 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 14:50:09 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_line(t_pars *line)
{
	t_pars	*runner;

	runner = line;
	while (runner != NULL)
	{
		if (runner->type != WORD && runner->type != ESPACE)
		{
			if (runner->next && runner->next->type == ESPACE)
				runner = runner->next;
			if (!runner->next || runner->next->type != WORD)
			{
				if (runner->next)
					printf("minishell: syntax error near unexpected token `%s'\n", runner->next->block);
				else
					printf("minishell: `%s' cannot be the last argument\n", runner->block);
				return (0);
			}
		}
		runner = runner->next;
	}
	return (1);
}

int	word(char c)
{
	if (c == '&')
		return (syntax_error_c(c), 0);
	else if (c == '(' || c == ')')
		return (syntax_error_c(c), 0);
	else if (c == '{' || c == '}')
		return (syntax_error_c(c), 0);
	else if (c == '[' || c == ']')
		return (syntax_error_c(c), 0);
	return (1);
}

int	verif_redir(char *str)
{
	if (ft_strlen(str) > 2)
		return (syntax_error_c(str[0]), 0);
	return (1);
}

int	verif_quote(char *str)
{
	int	i;
	int	type;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]) != 0)
		{
			type = is_quote(str[i]);
			i++;
			while (str[i] && is_quote(str[i]) != type)
				i++;
			if (!str[i])
				return (0);
			i++;
		}
		else
			i++;
	}
	return (1);
}

int	verif_some_shi(t_pars *line)
{
	t_pars	*runner;

	runner = line;
	while (runner != NULL)
	{
		if (runner->type == PIPE && ft_strlen(runner->block) > 1)
			return (printf("too many pipes\n"), 0);
		if (runner->type == HEREDOC || runner->type == RED_APP)
		{
			if (verif_redir(runner->block) == 0)
				return (0);
		}
		if (runner->type == WORD)
		{
			if (verif_quote(runner->block) == 0)
				return (printf("unclosed quote\n"),0);
		}
		runner = runner->next;
	}
	return (1);
}
