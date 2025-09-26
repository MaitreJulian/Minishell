/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:30:18 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/26 12:41:34 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp_mini(char *s1, char *s2, size_t n)
{
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(s2);
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0' && (x < n - 1))
		x++;
	if (!s1[x] && !s2[x])
		return (0);
	if (!s1[x])
		return (-1);
	if (!s2[x])
		return (1);
	if (x != len - 1)
		return (-1);
	return ((unsigned char)(s1[x]) - (unsigned char)(s2[x]));
}

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

	len = 0;
	while (env[len])
		len++;
	i = 0;
	while (i < len)
	{
		var_len = size_env(env[i]);
		if (var_len == -1)
			return (NULL);
		if (ft_strncmp_mini(env[i], src, var_len) == 0)
			break ;
		i++;
	}
	if (i == len || ft_strncmp_mini(env[i], src, size_env(env[i])) != 0)
		return (NULL);
	var = copy(env[i]);
	return (var);
}
