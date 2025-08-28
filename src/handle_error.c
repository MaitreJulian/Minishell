/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/utils.c
/*   Created: 2025/08/11 20:22:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/08/27 16:35:56 by jvenkata         ###   ########.fr       */
=======
/*   Created: 2025/08/26 18:18:52 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/27 15:02:21 by jowoundi         ###   ########.fr       */
>>>>>>> justin:src/handle_error.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD:src/utils.c

int	ft_varlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

int	len_tab(char **tb)
=======
void	syntax_error_c(char c)
>>>>>>> justin:src/handle_error.c
{
		printf("minishell : syntax error near unexpected token `%c'\n", c);
}
