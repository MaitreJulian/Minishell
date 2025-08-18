/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:17:37 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/06 13:21:17 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// #include <libc.h>

// int main(void)
// {
// 	char	*st;
//     char str[] = "Bien le bonjour peuple";
// 	st = NULL;
//     ft_bzero(str, 5);
// 	// bzero(st, 10);
//     printf("%s\n", str);
//     printf("%s\n", bzero(str, 10));
// }