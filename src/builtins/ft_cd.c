/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:06:22 by julian            #+#    #+#             */
/*   Updated: 2025/09/09 14:25:12 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_old(t_data *data, char **old_var_env, int i)
{
	char	**tmp;
	char	*temp;

	tmp = data->envc;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "PWD=", 3) == 0)//On trouve le PWD actuel 
		{
			old_var_env[0] = ft_strdup(tmp[i]);
			break ;
		}
		i++;
	}
	if (old_var_env[0])
	{
		temp = ft_strjoin("OLD", old_var_env[0]);//et on rajout OLD devant
		free(old_var_env[0]);
		old_var_env[0] = temp;
		if (!old_var_env[0])
			return ;
		old_var_env[1] = NULL;
		data->envc = ft_export(data->envc, old_var_env);//pour l'export après
	}
}

static void	update_oldpwd(t_data *data)
{
	char	**old_var_env;
	int		i;

	i = 0;
	if (!my_getenv("PWD", data->envc))
	{
		data->envc = ft_unset(data->envc, (char *[]){"OLDPWD", NULL});
		return ;
	}
	old_var_env = malloc(sizeof(char *) * 2);
	update_old(data, old_var_env, i);
	free_tab(old_var_env);
}

static void	update_pwd(t_data *data, char *new_pwd)
{
	char	cwd[PATH_MAX];
	char	**pwd;

	update_oldpwd(data);//le PWD actuel devient le OLPWD
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror(new_pwd);
		return ;
	}
	if (!my_getenv("PWD", data->envc))
		return ;
	pwd = malloc(sizeof(char *) * 2);
	pwd[0] = ft_strjoin("PWD=", cwd);
	if (!pwd[0])
		return;//strjoin n'a pas fonctionné
	pwd[1] =NULL;
	data->envc  = ft_export(data->envc, pwd);//le nouveau PWD est envyé dans l'env
	free_tab(pwd);
}   

int	ft_cd(t_data *data, char *new_pwd)
{
	int	res;

	res = chdir(new_pwd);//on change de répertoire mais faut mettre à jour manuelllement le PWD dans l'env
	if (res == 0)
	{
		update_pwd(data, new_pwd);
		return (1);
	}
	if (res == -1)
	{
		perror(new_pwd);
		return (0);
	}
	return (res);
}