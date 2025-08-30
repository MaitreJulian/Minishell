/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:01:33 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/30 12:53:59 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_print(t_cmd *line)
{
	t_cmd	*runner;
	int		i;

	runner = line;
	while (runner)
	{
		i = 0;
		printf("__________\n");
		while (runner->cmd[i])
		{
			printf("STR : [%s]\n", runner->cmd[i]);
			i++;
		}
		runner = runner->next;
	}
}

t_cmd	*c_node(char **str)
{
	t_cmd	*new_node;
	int		i;
	int		j;

	i = 0;
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
	while (str[i])
	{
		new_node->cmd[i] = ft_strdup(str[i]);
		i++;
	}
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

t_cmd	*fill_struct(t_pars *line)
{
	t_cmd	*f_struct;
	int		i;
	int 	j; 
	char	**new_line;
	int		count;
	t_pars	*temp;

	f_struct = NULL;
	while(line != NULL)
	{
		if (line->type == PIPE)
		{
			line = line->next;
			continue;
		}
		count = 0;
		temp = line;
		while (temp && temp->type != PIPE)
		{
			count++;
			temp = temp->next;
		}
		new_line = malloc(sizeof(char *) * (count + 1));
		if (!new_line)
			return (f_struct);
		i = 0;
		while (line && line->type != PIPE)
		{
			new_line[i++] = ft_strdup(line->block);
			line = line->next;
		}
		new_line[i] = NULL;
		fill_node(&f_struct, new_line);
		j = 0;
		while (j < i)
		{
			free(new_line[j]);
			j++;
		}
		free(new_line);
	}
	new_print(f_struct);
	return(f_struct);
}
