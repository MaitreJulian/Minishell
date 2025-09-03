/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:06:22 by julian            #+#    #+#             */
/*   Updated: 2025/09/03 13:40:09 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_oldpwd(t_data *data)
{
	char	**tmp;
	char	**test;
	int		i;

	i = 0;
	tmp = data->envc;
	test = malloc(sizeof(char *) * 2);
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "PWD=", 3) == 0)//On trouve le PWD actuel 
		{
			test[0] = ft_strdup(tmp[i]);
			break ;
		}
		i++;
	}
	if (test[0])
	{
		test[0]=ft_strjoin("OLD", test[0]);//et on rajout OLD devant
		if (!test[0])
			return ;
		test[1] = NULL;
		data->envc = ft_export(data->envc, test);//pour l'export après
	}
	free_tab(test);
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
	pwd =malloc(sizeof(char *) *2);
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