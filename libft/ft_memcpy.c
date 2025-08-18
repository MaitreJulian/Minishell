/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:11:02 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/06 13:22:37 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (0);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}

// #include <libc.h>
// #include <stdio.h>

// int main(void)
// {
// 	char src[] = "Yo";
// 	char dest[] = "";
// 	printf("%s", ft_memcpy(dest, src, 1));
// 	printf("%s", memcpy(dest, src, 1));
// }