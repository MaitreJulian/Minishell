/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:17 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/16 08:47:32 by jowoundi         ###   ########.fr       */
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
	if (str[i] == '?')
		return (ft_itoa(data->exit_status));
	while (str[i] && ft_isspace(str[i]) == 0 && \
	is_quote(str[i]) == 0 && str[i] != '$' && str[i] != '|')
		var = ft_realloc(var, str[i++]);
	if (var == NULL)
		return (ft_strdup("$"));
	if (ft_getenv(var, data->envc) != NULL)
		value = ft_strdup(ft_getenv(var, data->envc));
	return (value);
}

int	handle_single_quotes(char **str, int i, char **new_line)
{
	*new_line = ft_realloc(*new_line, (*str)[i]);
	i++;
	while ((*str)[i] && (*str)[i] != '\'')
	{
		*new_line = ft_realloc(*new_line, (*str)[i]);
		i++;
	}
	return (i);
}

int	handle_double_quotes(char **str, int i, char **new_line, t_data *data)
{
	char	*var;

	*new_line = ft_realloc(*new_line, (*str)[i]);
	i++;
	while ((*str)[i] && (*str)[i] != '"')
	{
		if ((*str)[i] && (*str)[i] == '$')
		{
			var = check_var(*str, i, data);
			if (!var)
				var = ft_strdup("");
			*new_line = ft_strjoin(*new_line, var);
			i++;
			while ((*str)[i] && ft_isspace((*str)[i]) == 0 && \
			is_quote((*str)[i]) == 0 && (*str)[i] != '$' && (*str)[i] != '|')
				i++;
		}
		else
		{
			*new_line = ft_realloc(*new_line, (*str)[i]);
			i++;
		}
	}
	return (i);
}

int	handle_dollar(char **str, int i, char **new_line, t_data *data)
{
	char	*var;

	var = check_var(*str, i, data);
	if (!var)
		var = ft_strdup("");
	*new_line = ft_strjoin(*new_line, var);
	i++;
	while ((*str)[i] && ft_isspace((*str)[i]) == 0 && \
		is_quote((*str)[i]) == 0 && (*str)[i] != '$' && (*str)[i] != '|')
		i++;
	return (i);
}

void	expander(char **str, int type, t_data *data)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = NULL;
	if (type == WORD)
	{
		while ((*str)[i])
		{
			if ((*str)[i] == '\'')
				i = handle_single_quotes(str, i, &new_line);
			else if ((*str)[i] == '"')
				i = handle_double_quotes(str, i, &new_line, data);
			else if ((*str)[i] == '$')
				i = handle_dollar(str, i, &new_line, data);
			else
			{
				new_line = ft_realloc(new_line, (*str)[i]);
				i++;
			}
		}
		free(*str);
		*str = ft_strdup(new_line);
		free(new_line);
	}
}
