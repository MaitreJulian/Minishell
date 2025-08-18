/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:30:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/11 17:55:14 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, char c)
{
	char	*line;
	int		i;

	i = -1;
	if (!str)
	{
		line = malloc(2);
		if (!line)
			return (NULL);
		line[0] = c;
		line[1] = '\0';
		return (line);
	}
	line = malloc(ft_strlen(str) + 2);
	if (!line)
		return (NULL);
	line[ft_strlen(str) + 1] = '\0';
	while (str[++i])
		line[i] = str[i];
	line[i] = c;
	i++;
	free(str);
	return (line);
}
