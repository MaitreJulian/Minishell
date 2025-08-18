/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:52:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/08/12 17:04:21 by jvenkata         ###   ########.fr       */
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
# include <sys/wait.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include <term.h>
# include <limits.h>
# include <fcntl.h>

# define PATH_MAX 4096

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

typedef struct s_token
{
	char	*word;
	enum e_token_type	type;
	struct s_token *next;
	struct s_token *prev;
}	t_token;

typedef struct s_cmd
{
	char			**cmd;
	int				n_cmd;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_token			*token_list;
	t_cmd			*cmd_list;
	char			**envc;
	struct s_data	*next;
}	t_data;

t_data	*lexing(char *line);

//MAIN
char	**copy_env(char **envp);
t_cmd	*make_cmd_list(char *s, t_data *data);
void	ft_redirection(t_cmd **cmd_node, t_data *data);

//exec
void	launch_builtin(t_data *data, t_cmd *cmd_list);
void	ft_execve(char **cmd, char **envc);
bool	is_builtin(char *cmd);
void	exec_pipeline(t_data *data);
void	ft_exec_builtin(t_data *data, t_cmd *cmd_list);
void	pipe_or_not(t_data *data);

//builtins
char	**ft_export(char **envc, char *new_v);
int		ft_cd(t_data *data, char *new_pwd);
void	ft_echo(char **args);
void	ft_env(char **env);
void	ft_pwd(char **env);
char	**ft_unset(char **envc, char *v_env_del);//la copie d'environnement et variable à enlever
void	ft_exit(t_data *data);

//FREE
void	free_tab(char **array);
void	free_cmd_list(t_cmd *cmd_list);
void	free_everything(t_data *data);

//UTILS
int	len_tab(char **tb);

#endif