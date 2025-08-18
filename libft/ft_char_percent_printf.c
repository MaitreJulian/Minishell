/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_percent_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:44:11 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/04 18:14:59 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
