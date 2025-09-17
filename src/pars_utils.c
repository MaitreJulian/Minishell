/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:49:53 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/17 15:07:28 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_line(t_pars *line)
{
	t_pars	*runner;

	runner = line;
	if (!line)
		return (1);
	if (runner->type == PIPE)
		return (syntax_error_c(2, 0, runner->block), 0);
	while (runner != NULL)
	{
		if (runner->type != WORD && runner->type != ESPACE)
		{
			if (runner->next && runner->next->type == ESPACE)
				runner = runner->next;
			if (!runner->next || runner->next->type != WORD)
			{
				if (runner->next)
					syntax_error_c(2, 0, runner->next->block);
				else
					syntax_error_c(3, 0, runner->block);
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
		return (syntax_error_c(1, c, NULL), 0);
	else if (c == '(' || c == ')')
		return (syntax_error_c(1, c, NULL), 0);
	else if (c == '{' || c == '}')
		return (syntax_error_c(1, c, NULL), 0);
	else if (c == '[' || c == ']')
		return (syntax_error_c(1, c, NULL), 0);
	return (1);
}

int	verif_redir(char *str)
{
	if (ft_strlen(str) > 2)
		return (syntax_error_c(1, str[0], NULL), 0);
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
				return (printf("unclosed quote\n"), 0);
		}
		runner = runner->next;
	}
	return (1);
}
