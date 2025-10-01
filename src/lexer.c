/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:48:34 by jowoundi          #+#    #+#             */
/*   Updated: 2025/10/01 13:43:10 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_quote(char *line, int type, int j)
{
	j++;
	if (!line[j])
		return (j);
	while (line[j] && is_quote(line[j]) != type)
		j++;
	if ((size_t)j == ft_strlen(line) && is_quote(line[j - 1]) != type)
		return (j);
	j++;
	return (j);
}

int	size_str(char *line, int type, int i)
{
	if (type == ESPACE)
	{
		while (line[i] && type == type_of_c(line[i]))
			i++;
		i--;
	}
	else if (type == WORD)
	{
		while (line[i] && type_of_c(line[i]) != ESPACE && c_sep(line[i]) == 0)
		{
			if (line[i] && is_quote(line[i]) != 0)
				i = for_quote(line, is_quote(line[i]), i);
			else
				i++;
		}
	}
	else
	{
		while (line[i] && type == type_of_c(line[i]))
			i++;
	}
	return (i);
}

char	*copy_str(char *line, int i, int j)
{
	char	*str;

	str = NULL;
	while (i < j)
		str = ft_realloc(str, line[i++]);
	return (str);
}

t_pars	*identifier(char *line)
{
	int		i;
	int		j;
	int		type;
	char	*str;
	t_pars	*identity;

	identity = NULL;
	str = NULL;
	i = -1;
	while (line[++i])
	{
		type = type_of_c(line[i]);
		j = size_str(line, type, i);
		if (type == ESPACE)
			str = ft_strdup(" ");
		else
			str = copy_str(line, i, j);
		if (type_of_c(line[j]) != ESPACE)
			j--;
		fill_block(&identity, str, type);
		free(str);
		str = NULL;
		i = j;
	}
	return (identity);
}

t_pars	*lexing(char *line, t_data *data)
{
	t_pars	*new_line;

	new_line = identifier(line);
	clean_block(new_line, data);
	new_line = split_space(new_line);
	return (new_line);
}
