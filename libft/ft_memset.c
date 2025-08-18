/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:15:52 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/22 17:00:02 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char str[] = "Coucou";
//     ft_memset(str, '0', 5);
//     printf("%s\n", str);
// 	memset(str, '0', 5);
// 	printf("%s\n", str);
// }