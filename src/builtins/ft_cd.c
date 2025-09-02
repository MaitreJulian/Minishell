/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:06:22 by julian            #+#    #+#             */
/*   Updated: 2025/09/02 13:50:16 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_oldpwd(t_data *data)
{
	char	**tmp;
	char	*test;
	int		i;

	i = 0;
	tmp = data->envc;
	test = NULL;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "PWD=", 3) == 0) //On trouve le PWD actuel 
		{
			test = tmp[i];
			break ;
		}
		i++;
	}
	if (test)
	{
		test = ft_strjoin("OLD", test);//et on rajout OLD devant
		if (!test)
			return ;
		ft_export(data->envc, &test);//pour l'export après
	}
	free(test);
}

static void	update_pwd(t_data *data, char *new_pwd)
{
	char	cwd[PATH_MAX];
	char	*pwd;

	update_oldpwd(data);//le PWD actuel devient le OLPWD
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror(new_pwd);
		return ;
	}
	pwd = ft_strjoin("PWD=", cwd);
	if (!pwd)
		return;//strjoin n'a pas fonctionné
	ft_export(data->envc, &pwd);//le nouveau PWD est envyé dans l'env
	free(pwd);
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