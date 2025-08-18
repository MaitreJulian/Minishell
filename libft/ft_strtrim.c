/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:06:14 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/06 14:43:19 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*tri(const char *sup, int c)
{
	char	ch;

	ch = (char)c;
	while (*sup != '\0')
	{
		if (*sup == ch)
			return ((char *)sup);
		sup++;
	}
	if (ch == '\0')
		return ((char *)sup);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;
	size_t	len;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (tri(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (end > start && tri(set, s1[end - 1]))
		end--;
	len = end - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (len == 0)
		res[0] = '\0';
	else
		ft_strlcpy(res, s1 + start, len + 1);
	return (res);
}

// int	main()
// {
// 	printf("%s\n", ft_strtrim("", ""));
// 	return (0);
// }