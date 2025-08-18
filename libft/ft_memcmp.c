/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:14:16 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/06 13:22:28 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	size_t			i;

	tmp_s1 = ((unsigned char *)s1);
	tmp_s2 = ((unsigned char *)s2);
	i = 0;
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char a[] = "";
// 	char b[] = "df";
//     printf("%d\n", ft_memcmp(a, b, 2));
//     printf("%d\n", memcmp(a, b, 2));
//     return(0);
// }