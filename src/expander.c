/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:30:18 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/16 15:11:05 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_env(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if ((size_t)i == ft_strlen(str) && str[i - 1] != '=')
		return (-1);
	return (i);
}

char	*copy(char *str)
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	while (str[i] != '=')
		i++;
	i++;
	while (str[i])
		var = ft_realloc(var, str[i++]);
	return (var);
}

char	*ft_getenv(char *src, char **env)
{
	int		i;
	int		len;
	int		var_len;
	char	*var;

	i = 0;
	len = 0;
	while (env[len])
		len++;
	while (env[i])
	{
		var_len = size_env(env[i]);
		if (var_len == -1)
			return (NULL);
		if (ft_strncmp(env[i], src, var_len) == 0)
			break ;
		i++;
	}
	if (i == len)
	{
		var_len = size_env(env[i - 1]);
		if (ft_strncmp(env[i - 1], src, var_len) != 0)
			return (NULL);
		i--;
	}
	var = copy(env[i]);
	return (var);
}
