/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:17 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/11 18:53:27 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_var(char *str, int i)
{
	char	*var;
	char	*value;

	i++;
	var = NULL;
	while (str[i] && ft_isspace(str[i]) == 0 && is_quote(str[i]) == 0 && str[i] != '$')
		var = ft_realloc(var, str[i++]);
	value = getenv(var);
	printf("%s\n", value);
	return (value);
}

void	expander(char **str, int type)
{
	char	*var;
	char	*new_line;
	int		i;

	i = 0;
	new_line = NULL;
	if (type == WORD)
	{	
		while ((*str)[i])
		{
			if ((*str)[i] == '\'')
			{
				while ((*str)[i] && (*str)[i] != '\'')
				{
					new_line = ft_realloc(new_line, (*str)[i]);
					i++;
				}
			}
			else
			{
				if ((*str)[i] && (*str)[i] == '$')
				{
					var = check_var(*str, i);
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
	}
}
