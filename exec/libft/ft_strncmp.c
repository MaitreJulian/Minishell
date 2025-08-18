/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:50:23 by jvenkata          #+#    #+#             */
/*   Updated: 2025/07/10 12:44:25 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && (i < n - 1))
		i++;
	if (!s1[i] && !s2[i])
		return (0);
	if (!s1[i])
		return (-1);
	if (!s2[i])
		return (1);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
