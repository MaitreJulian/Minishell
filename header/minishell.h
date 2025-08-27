/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/27 15:06:51 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include <term.h>

enum	e_error_type
{
	SYNTAX,
};

enum	e_token_type
{
	ESPACE,
	WORD,
	PIPE, // |
	RED_OUT, // >
	RED_APP, // >>
	RED_IN, // <
	HEREDOC, // <<
	S_QUOTE, // '
	D_QUOTE, // "
	CMD,
	ARG,
};

typedef struct s_cmd
{
	char			**cmd;
	char			*token;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	int				type;
	char			*block;
	struct s_data	*next;
}		t_data;

//find_type
int		type_of_c(char c);
int		c_sep(char c);
int		is_quote(char c);
int		ft_issep(int type);

t_data	*lexing(char *line);
void	fill_block(t_data **data, char *str, int type);
void	clean_block(t_data *line);
void	print_list(t_data *list);
int		parsing(t_data *line);
void	expander(char **str, int type);
t_cmd	*fill_struct(t_data *line);
void	syntax_error_c(char c);

#endif