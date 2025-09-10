/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:47:51 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/10 13:43:08 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	verif_word(t_pars *line)
{
	int		i;
	int		type;
	t_pars	*runner;

	runner = line;
	while (runner != NULL)
	{
		i = -1;
		while (runner->block[++i])
		{
			if (is_quote(runner->block[i]) != 0)
			{
				type = is_quote(runner->block[i++]);
				while (runner->block[i] && is_quote(runner->block[i]) != type)
					i++;
			}
			else if (word(runner->block[i]) == 0)
				return (0);
		}
		runner = runner->next;
	}
	return (1);
}

int	handle_inside_quotes(char *block, int *i, int type, char **tmp)
{
	(*i)++;
	while (block[*i] && is_quote(block[*i]) != type)
		*tmp = ft_realloc(*tmp, block[(*i)++]);
	if (block[*i] && is_quote(block[*i]) == type)
		(*i)++;
	return (1);
}

char	*clean_word(char *block)
{
	char	*tmp;
	int		i;
	int		type;

	tmp = NULL;
	i = -1;
	while (block[++i])
	{
		if (is_quote(block[i]) != 0)
		{
			type = is_quote(block[i]);
			handle_inside_quotes(block, &i, type, &tmp);
			i--;
		}
		else
			tmp = ft_realloc(tmp, block[i]);
	}
	if (!tmp)
		return (ft_strdup(""));
	return (tmp);
}

void	delete_quote(t_pars **line)
{
	t_pars	*runner;
	char	*tmp;

	runner = *line;
	while (runner != NULL)
	{
		if (runner->type == WORD)
		{
			tmp = clean_word(runner->block);
			free(runner->block);
			runner->block = ft_strdup(tmp);
			free(tmp);
		}
		runner = runner->next;
	}
}

int	parsing(t_pars *line, t_data *data)
{
	(void)data;
	if (verif_some_shi(line) == 0)
	{
		free_pars(line);
		data->exit_status = 2;
		return (0);
	}
	if (validate_line(line) == 0)
	{
		free_pars(line);
		data->exit_status = 2;
		return (0);
	}
	if (verif_word(line) == 0)
	{
		free_pars(line);
		data->exit_status = 2;
		return (0);
	}
	delete_quote(&line);
	return (1);
}
