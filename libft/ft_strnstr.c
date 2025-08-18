/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:47:04 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/05 15:56:53 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	len_d;

	x = 0;
	y = 0;
	len_d = ft_strlen(to_find);
	if (to_find[y] == '\0')
		return ((char *)str);
	while (str[x] != '\0' && (x < len))
	{
		y = 0;
		while (str[x + y] && str[x + y] == to_find[y] && x + y < len)
			y++;
		if (y == len_d)
			return ((char *)&str[x]);
		x++;
	}
	return (0);
}
// #include <string.h>

// int	main()
// {
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "lorem", 15));
// 	return(0);
// }