/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:20:39 by jowoundi          #+#    #+#             */
/*   Updated: 2024/11/05 17:51:49 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
// void test(unsigned int tf, char *str)
// {
// 	tf = 0;
// 	while (str[tf])
// 	{
// 		write(1, &str[tf], 1);
// 		tf++;
// 	}
// }
// int main(void)
// {
// 	char *res = "kekekek";
// 	ft_striteri("hehe", test);
// 	printf("%s", res);
// }
