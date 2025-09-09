/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/09/09 17:27:49 by jvenkata         ###   ########.fr       */
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
	int				exit_status;
}		t_data;


//LEXING
t_pars	*lexing(char *line, t_data *data);
int		size_str(char *line, int type, int i);
char	*copy_str(char *line, int i, int j);
int		type_of_c(char c);
int		c_sep(char c);
int		is_quote(char c);
int		ft_issep(int type);
void	clean_block(t_pars *line, t_data *data);
t_pars	*split_space(t_pars *line);
void	fill_block(t_pars **data, char *str, int type);
void	expander(char **str, int type, t_data *data);
int		parsing(t_pars *line, t_data *data);
t_cmd	*fill_struct(t_pars *luthor);
void	syntax_error_c(char c);
char	*ft_getenv(char *src, char **env);
int		count_until_pipe(t_pars *line);
char	**dup_args_from_list(t_pars **line, int count);
void	free_args(char **new_line, int size);
int		count_args(char **args);
int		validate_line(t_pars *line);
int		word(char c);
int		verif_redir(char *str);
int		verif_quote(char *str);
int		verif_some_shi(t_pars *line);

//SIGNALS
void	handler(int sig);
void setup_signals(void);

//MAIN
char	**copy_env_init(char **env);
//t_cmd	*make_cmd_list(char *s, t_data *data);
bool	red_heredoc(t_cmd **cmd_node, int i);
bool	red_out(t_cmd **cmd_node, int i);;
bool	red_append(t_cmd **cmd_node, int i);
bool	red_in(t_cmd **cmd_node, int i);
bool	redirection(t_cmd **cmd_node, int i);
int		ft_redirection(t_cmd **cmd_node);

//exec
void	launch_builtin(t_data *data, t_cmd *cmd_list);
char	*my_getenv(char *name, char **env);
void	ft_execve(char **cmd, char **envc);
bool	is_builtin(char *cmd);
bool	is_nofork_builtin(char *cmd);
void	exec_pipeline(t_data *data);
void	ft_exec_builtin(t_data *data, t_cmd *cmd_list);
void	pipe_or_not(t_data *data);

//builtins
char	**ft_export(char **envc, char **new_v);
int		ft_cd(t_data *data, char **new_pwd);
void	ft_echo(char **args);
void	ft_env(t_data *data);
void	ft_pwd(char **env);
char	**ft_unset(char **envc, char **v_env_del);
bool	ft_exit(t_data *data, char *code);

//FREE
void	free_tab(char **array);
t_cmd	*free_cmd_list(t_cmd *cmd_list);
void	free_everything(t_data *data);
void	free_pars(t_pars *pars_struct);

//UTILS
int		len_tab(char **tb);
int		ft_varlen(char *str);
void	print_env(char **envp);
void	print_list(t_pars *list);

#endif