/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:18:52 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 17:40:33 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error_c(int n, char c, char *str)
{
	if (n == 1)
		printf("minishell : syntax error near unexpected token `%c'\n", c);
	else if (n == 2)
		printf("minishell: syntax error near unexpected token `%s'\n", str);
	else if (n == 3)
		printf("minishell: `%s' cannot be the last argument\n", str);
}
