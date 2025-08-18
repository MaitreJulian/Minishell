/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:35:57 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:19 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conv(va_list args, const char caract)
{
	size_t	type_conv;

	type_conv = 0;
	if (caract == 'c')
		type_conv += ft_putchar_printf(va_arg(args, int));
	else if (caract == 's')
		type_conv += ft_putstr_printf(va_arg(args, char *));
	else if (caract == 'd' || caract == 'i')
		type_conv += ft_putnbr_printf(va_arg(args, int));
	else if (caract == 'u')
		type_conv += ft_unsigned(va_arg(args, unsigned int));
	else if (caract == 'x')
		type_conv += ft_hexlower(va_arg(args, unsigned int));
	else if (caract == 'X')
		type_conv += ft_hexupper(va_arg(args, unsigned int));
	else if (caract == 'p')
		type_conv += ft_putptr(va_arg(args, unsigned long));
	else if (caract == '%')
		type_conv += ft_percent();
	return (type_conv);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print;
	va_list	args;

	i = 0;
	print = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += conv(args, str[i + 1]);
			i++;
		}
		else
			print += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}

// int main()
// {
// 	int c = 'c';
// 	char *s = "Bonjour";
// 	int d = -4;
// 	int i = -456;
// 	unsigned int u = 34893534;
// 	unsigned int x = 1658;
// 	unsigned long p = 1658;
// 	printf("%d---\n", ft_printf("Reponse :\n %c\n %s\n %d\n %i\n %u\n %x\n
// 								 %X\n %p\n %%\n\n", c, s, d, i, u, x, x, &p));
// 	printf("%d---\n", printf("Reponse :\n %c\n %s\n %d\n %i\n %u\n %x\n
// 								 %X\n %p\n %%\n\n", c, s, d, i, u, x, x, &p));
// }