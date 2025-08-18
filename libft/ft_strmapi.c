/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:54:10 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/05 17:53:47 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*iter;
	size_t	s_lenght;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_lenght = ft_strlen(s);
	iter = malloc(s_lenght + 1);
	if (!iter)
		return (0);
	while (s[i])
	{
		iter[i] = f(i, s[i]);
		i++;
	}
	iter[i] = '\0';
	return (iter);
}
