/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:43:43 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/11 14:20:04 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir(char **str, int *type)
{
	if (*type == RED_IN)
	{
		if (ft_strlen(*str) > 1)
		{
			if (ft_strlen(*str) > 2)
				printf("erreur redirection\n"); //implementer l'erreur
			else
				*type = HEREDOC;
		}
	}
	else if (*type == RED_OUT)
	{
		if (ft_strlen(*str) > 1)
		{
			if (ft_strlen(*str) > 2)
				printf("erreur redirection\n"); //implementer l'erreur
			else
				*type = RED_APP;
		}
	}
}

void	word(char *str)
{
	if (ft_strchr(str, '&') != 0)
		printf("synthax error : %s\n", str); //implementer l'erreur
	else if (ft_strchr(str, '(') != 0 || ft_strchr(str, ')') != 0)
		printf("synthax error : %s\n", str); //implementer l'erreur
	else if (ft_strchr(str, '[') != 0 || ft_strchr(str, ']') != 0)
		printf("synthax error : %s\n", str); //implementer l'erreur
	else if (ft_strchr(str, '{') != 0 || ft_strchr(str, '}') != 0)
		printf("synthax error : %s\n", str); //implementer l'erreur
}

void	clean_block(t_data *line)
{
	while (line != NULL)
	{
		if (line->type == RED_IN || line->type == RED_OUT)
			redir(&line->block, &line->type);
		if (line->type == WORD)
			word(line->block);
		if (line->type == PIPE && ft_strlen(line->block) > 1)
			printf("synthax error : %s\n", line->block);
		expander(&line->block, line->type);
		line = line->next;
	}
}
