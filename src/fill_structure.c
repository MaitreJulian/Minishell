/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:01:33 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 16:48:45 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*c_node(char **str)
{
	t_cmd	*new_node;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (NULL);
	while (str[j])
		j++;
	new_node->cmd = malloc(sizeof(char *) * (j + 1));
	if (!new_node->cmd)
	{
		free(new_node);
		return (NULL);
	}
	while (str[++i])
		new_node->cmd[i] = ft_strdup(str[i]);
	new_node->cmd[i] = NULL;
	if (ft_redirection(&new_node))
		return (NULL);
	new_node->next = NULL;
	return (new_node);
}

void	fill_node(t_cmd **new_struct, char **str)
{
	t_cmd	*new_node;
	t_cmd	*temp;

	new_node = c_node(str);
	if (!new_node)
		return ;
	if (!*new_struct)
	{
		*new_struct = new_node;
		return ;
	}
	temp = *new_struct;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	process_command_block(t_cmd **f_struct, t_pars **line, int *nb_cmd)
{
	int		count;
	int		size;
	char	**new_line;

	count = count_until_pipe(*line);
	new_line = dup_args_from_list(line, count);
	if (!new_line)
		return ;
	size = count_args(new_line);
	fill_node(f_struct, new_line);
	free_args(new_line, size);
	(*nb_cmd)++;
}

t_cmd	*fill_struct(t_pars *line)
{
	t_cmd	*f_struct;
	int		nb_cmd;

	f_struct = NULL;
	nb_cmd = 0;
	while (line != NULL)
	{
		if (line->type == PIPE)
		{
			line = line->next;
			continue ;
		}
		process_command_block(&f_struct, &line, &nb_cmd);
		while (line && line->type != PIPE)
			line = line->next;
	}
	if (f_struct)
		f_struct->n_cmd = nb_cmd;
	free(line);
	return (f_struct);
}
