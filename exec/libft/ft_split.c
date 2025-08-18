/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:32:35 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/04 10:03:31 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_new_word(const char *s, char c)
{
	int		i;
	int		len;
	char	*new_word;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	i = 0;
	new_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_word)
		return (NULL);
	while (i < len)
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[i] = '\0';
	s = s + len;
	return (new_word);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	**ft_new_tab(char **tab, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			tab[i] = ft_new_word(s, c);
			if (!tab[i])
			{
				ft_free_malloc(tab);
				return (NULL);
			}
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_new_tab(tab, s, c);
	return (tab);
}
// #include <stdio.h>

// int main ()
// {
//     char c = ' ';
//     char *str = "hello!";
//     char **list = ft_split(str, c);
//     int i = 0;
//     if (list != NULL)
//     {
//       while (list[i] != NULL)
//         i++;
//       int j = 0;
// 	  if (i == 1 )
//       while (j < i)
//       {
//           printf("%s\n", list[j]);
//           j++;
//       }
//     }
//     else 
//       printf("String is NULL");
//     return (0);
// }