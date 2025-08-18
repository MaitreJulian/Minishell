/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:28:33 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/03 13:59:00 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final_string;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	final_string = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!final_string)
		return (0);
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	while (s2[j])
		final_string[i++] = s2[j++];
	final_string[i] = '\0';
	return (final_string);
}

// int	main()
// {
// 	printf("%s\n", ft_strjoin("ie", "bonsoir"));
// 	return (0);
// }