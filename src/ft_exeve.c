/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exeve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:53:35 by jvenkata          #+#    #+#             */
/*   Updated: 2025/09/05 15:07:21 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **char_tab)
{
	size_t	i;

	i = 0;
	while (char_tab[i])
	{
		free(char_tab[i]);
		i++;
	}
	free(char_tab);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	*path_part;
	char	**allpath;
	char	*temp;

	i = -1;
	temp = my_getenv("PATH", env);
	if (!temp)
		return (NULL);
	allpath = ft_split(temp, ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_free_tab(allpath);
	return (cmd);
}

void	ft_execve(char **cmd, char **env)
{
	char	*path;

	path = get_path(cmd[0], env);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!path)
	{
		printf("%s: No such file or directory\n", cmd[0]);
	}
	else if (execve(path, cmd, env) == -1)
	{
		perror("execve failed");
		exit(127);
	}
}