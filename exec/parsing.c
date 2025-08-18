/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:47:51 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/07 16:01:44 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	validate_line(t_data *line)
{
	while (line != NULL)
	{
		if (line->type != WORD && line->type != ESPACE && line->type != D_QUOTE && line->type != S_QUOTE)
		{
			if (line->next && line->next->type == ESPACE)
				line = line->next;
			if (line->next && line->next->type != WORD && line->next->type != D_QUOTE && line->next->type != S_QUOTE)
				return (0);
		}
		line = line->next;
	}
	return (1);
}

int	parsing(t_data *line)
{
	if (validate_line(line) == 0)
		return (0);		
	return (1);
}