/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:45:54 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 14:47:02 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_until_pipe(t_pars *line)
{
	int		count;
	t_pars	*temp;

	count = 0;
	temp = line;
	while (temp && temp->type != PIPE)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

char	**dup_args_from_list(t_pars **line, int count)
{
	char	**new_line;
	int		i;
	t_pars	*temp;

	new_line = malloc(sizeof(char *) * (count + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (*line && (*line)->type != PIPE)
	{
		new_line[i++] = ft_strdup((*line)->block);
		temp = (*line)->next;
		free((*line)->block);
		free(*line);
		*line = temp;
	}
	new_line[i] = NULL;
	return (new_line);
}

void	free_args(char **new_line, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		free(new_line[j]);
		j++;
	}
	free(new_line);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
