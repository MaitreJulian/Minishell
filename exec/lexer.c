/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:48:34 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/07 15:56:41 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_quote(char *line, int type, int j)
{
	j++;
	if (!line[j])
		return (-1);
	while (line[j] && is_quote(line[j]) != type)
		j++;
	if ((size_t)j == ft_strlen(line) && is_quote(line[j - 1]) != type)
		return (-1);
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
			if (i == -1)
				return (printf("syntax_error\n"), -1);
		}
	}
	else
	{
		while (line[i] && type == type_of_c(line[i]))
			i++;
	}
	return(i);
}

char	*copy_str(char *line, int i, int j)
{
	char	*str;

	str = NULL;
	while (i < j)
		str = ft_realloc(str, line[i++]);
	return (str);
}

void	print_list(t_data *list)
{
	t_data	*node;

	node = list;
	while (node != NULL)
	{
		printf("TYPE : [%d], STR :[%s]\n", node->type, node->block);
		node = node->next;
	}
}

t_data	*identifier(char *line)
{
	int	i;
	int	j;
	int	type;
	char	*str;
	t_data	*identity;

	identity = NULL;
	i = -1;
	while (line[++i])
	{
		type = type_of_c(line[i]);
		j = size_str(line, type, i);
		if (j == -1)
			break;
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
	if (j == -1)
		identity = NULL;
	print_list(identity);
	return (identity);
}

t_data	*lexing(char *line)
{
	t_data	*new_line;

	new_line = identifier(line);
	clean_block(new_line);
	return (new_line);
}
