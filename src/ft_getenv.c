/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:30:18 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 16:49:34 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_env(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
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
