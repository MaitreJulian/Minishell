/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:21:31 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 18:10:21 by jvenkata         ###   ########.fr       */
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
	tmp = NULL;
	while (line)
	{
		if (line->type == WORD)
			tmp = spliter(line->block, tmp);
		else
			fill_block(&tmp, line->block, line->type);
		line = line->next;
	}
	free_pars(runner);
	return (tmp);
}
