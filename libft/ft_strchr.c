/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:06:15 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/06 13:22:56 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == (unsigned char)c)
			return ((char *)str + x);
		x++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + x);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     printf("%s", ft_strchr(NULL, 'c'));
// 	printf("%s", strchr(NULL, 'c'));
//     return(0);
// }
