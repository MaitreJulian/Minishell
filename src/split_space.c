/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:21:31 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/08 15:33:57 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pars	*spliter(char *line, t_pars *identity)
{
	int		i;
	int		j;
	int		type;
	char	*str;

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

t_pars	*split_space(t_pars *line)
{
	t_pars	*runner;
	t_pars	*tmp;

	runner = line;
	while (runner)
	{
		if (runner->type == WORD)
			tmp = spliter(runner->block, tmp);
		runner = runner->next;
	}
	while (line)
	{
		free(line->block);
		line = line->next;
	}
	free(line);
	return (tmp);
}
