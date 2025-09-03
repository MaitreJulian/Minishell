/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:17 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/03 15:30:31 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_var(char *str, int i, t_data *data)
{
	char	*var;
	char	*value;

	i++;
	var = NULL;
	value = NULL;
	while (str[i] && ft_isspace(str[i]) == 0 && \
	is_quote(str[i]) == 0 && str[i] != '$')
		var = ft_realloc(var, str[i++]);
	if (var == NULL)
		return (ft_strdup("$"));
	if (ft_getenv(var, data->envc) != NULL)
		value = ft_strdup(ft_getenv(var, data->envc));
	return (value);
}

void	expander(char **str, int type, t_data *data)
{
	char	*var;
	char	*new_line;
	int		i;
	//quand je decouperai la fonction : faire des fonctions en int pour garder le i

	i = 0;
	new_line = NULL;
	if (type == WORD)
	{
		while ((*str)[i])
		{
			if ((*str)[i] == '\'')
			{
				new_line = ft_realloc(new_line, (*str)[i]);
				i++;
				while ((*str)[i] && (*str)[i] != '\'')
				{
					new_line = ft_realloc(new_line, (*str)[i]);
					i++;
				}
			}
			else if ((*str)[i] == '"')
			{
				new_line = ft_realloc(new_line, (*str)[i]);
				i++;
				while ((*str)[i] && (*str)[i] != '"')
				{
					if ((*str)[i] && (*str)[i] == '$')
					{
						var = check_var(*str, i, data);
						if (!var)
							var = ft_strdup("");
						new_line = ft_strjoin(new_line, var);
						i++;
						while ((*str)[i] && ft_isspace((*str)[i]) == 0 && is_quote((*str)[i]) == 0 && (*str)[i] != '$')
							i++;
					}
					else
					{
						new_line = ft_realloc(new_line, (*str)[i]);
						i++;
					}
				}
				new_line = ft_realloc(new_line, (*str)[i]);
				i++;
			}
			else
			{
				if ((*str)[i] && (*str)[i] == '$')
				{
					var = check_var(*str, i, data);
					if (!var)
						var = ft_strdup("");
					new_line = ft_strjoin(new_line, var);
					i++;
					while ((*str)[i] && ft_isspace((*str)[i]) == 0 && is_quote((*str)[i]) == 0 && (*str)[i] != '$')
						i++;
				}
				else
				{
					new_line = ft_realloc(new_line, (*str)[i]);
					i++;
				}
			}
		}
		free(*str);
		*str = ft_strdup(new_line);
		free(new_line);
	}
}
