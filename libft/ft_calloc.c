/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:31:29 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/06 13:35:35 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tmp;

	if (count != 0 && size != 0)
	{
		tmp = count * size;
		if (tmp / size != count)
			return (NULL);
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	char	*s;
// 	char	*p;
// 	size_t	count = SIZE_T_MAX / 2;
// 	size_t	size = 3;
// 	s = ft_calloc(count, size);
// 	p = calloc(count, size);
// }
