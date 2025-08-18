/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:21:56 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/05 17:46:23 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	x;

	x = 0;
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
	return ((unsigned char)(s1[x]) - (unsigned char)(s2[x]));
}
// #include <string.h>

// int main()
// {
// 	printf("%d\n", ft_strncmp("", "dfdfd", 5));
// 	printf("%d\n", strncmp("", "dfdfdf", 5));
// 	return (0);
// }