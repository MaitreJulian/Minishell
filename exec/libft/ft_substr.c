/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:12:19 by jvenkata          #+#    #+#             */
/*   Updated: 2025/07/10 09:42:45 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	while (i < start)
		i++;
	if ((ft_strlen(s) - i) < len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if ((ft_strlen(s) - i) > len)
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	j = 0;
	while (j < len && s[i])
		substr[j++] = s[i++];
	substr[j] = 0;
	return (substr);
}
