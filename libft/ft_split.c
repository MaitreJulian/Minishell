/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:04:00 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/11 16:33:47 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

static char	*dup_word(char const *str, int start, char c)
{
	size_t		i;
	char		*result;
	size_t		len_word;

	len_word = 0;
	i = start;
	while (str[i] != c && str[i])
	{
		len_word++;
		i++;
	}
	result = malloc(sizeof(char) * (len_word + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[start] != c && str[start])
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

static char	**ft_free(char **pointer, size_t index)
{
	while (index > 0)
		free (pointer[--index]);
	free (pointer);
	return (0);
}

static char	**index_word(char const *s, char c, char **tab)
{
	size_t	i_word;
	size_t	i_tab;

	i_word = 0;
	i_tab = 0;
	while (s[i_word])
	{
		while (s[i_word] == c && s[i_word])
			i_word++;
		if (s[i_word])
		{
			tab[i_tab] = dup_word(s, i_word, c);
			if (!tab[i_tab])
				return (ft_free(tab, i_tab));
			i_tab++;
			while (s[i_word] != c && s[i_word])
				i_word++;
		}
	}
	tab[i_tab] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = index_word(s, c, tab);
	return (tab);
}

// int	main()
// {
// 	char const str[] = "681 035 0 1546";
// 	char c = ' ';
// 	char **result;
// 	result = ft_split(str, c);
// 	if (!result)
// 		return (1);
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }