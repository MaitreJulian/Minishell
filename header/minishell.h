/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/03 15:27:49 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define _POSIX_C_SOURCE 200809L

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
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <wait.h>

# define PATH_MAX 4096

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
	AND, // &
	PARENTH_L,	//	(
	PARENTH_R, // )
	END_TOKEN
};

typedef struct s_cmd
{
	char			**cmd;
	int				fd_in;
	int				fd_out;
	int				n_cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pars
{
	char	*block;
	int 	type;
	struct s_pars	*next;
}	t_pars;


typedef struct s_data
{
	t_cmd			*cmd_list;
	char			**envc;
}		t_data;


//LEXING
t_pars	*lexing(char *line, t_data *data);
int		type_of_c(char c);
int		c_sep(char c);
int		is_quote(char c);
int		ft_issep(int type);
void	clean_block(t_pars *line, t_data *data);
void	fill_block(t_pars **data, char *str, int type);
void	expander(char **str, int type, t_data *data);
int	 parsing(t_pars *line);
t_cmd	*fill_struct(t_pars *luthor);
void	syntax_error_c(char c);
char	*ft_getenv(char *src, char **env);


//SIGNALS
void	handler(int sig);
void setup_signals(void);

//MAIN
char	**copy_env(char **envp);
//t_cmd	*make_cmd_list(char *s, t_data *data);
bool	red_heredoc(t_cmd **cmd_node, int i);
bool	red_out(t_cmd **cmd_node, int i);;
bool	red_append(t_cmd **cmd_node, int i);
bool	red_in(t_cmd **cmd_node, int i);
bool	redirection(t_cmd **cmd_node, int i);
int		ft_redirection(t_cmd **cmd_node);

//exec
void	launch_builtin(t_data *data, t_cmd *cmd_list);
void	ft_execve(char **cmd, char **envc);
bool	is_builtin(char *cmd);
bool	is_nofork_builtin(char *cmd);
void	exec_pipeline(t_data *data);
void	ft_exec_builtin(t_data *data, t_cmd *cmd_list);
void	pipe_or_not(t_data *data);

//builtins
char	**ft_export(char **envc, char **new_v);
int		ft_cd(t_data *data, char *new_pwd);
void	ft_echo(char **args);
void	ft_env(char **env);
void	ft_pwd(char **env);
char	**ft_unset(char **envc, char **v_env_del);
void	ft_exit(t_data *data);

//FREE
void	free_tab(char **array);
void	free_cmd_list(t_cmd *cmd_list);
void	free_everything(t_data *data);

//UTILS
int		len_tab(char **tb);
int		ft_varlen(char *str);
void	print_env(char **envp);

#endif