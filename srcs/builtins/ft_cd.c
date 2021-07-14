/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:48:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/14 17:46:02 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	update_pwd(t_data *data, char *new_pwd)
{
	char	*tmp;
	char	*pwd;
	char	*old_pwd;

	tmp = search_env(data->envp_list, "PWD");
	old_pwd = ft_strjoin("OLD", tmp);
	free(tmp);
	replace_content(&data->envp_list, old_pwd, "OLDPWD");
	replace_content(&data->exp_list, old_pwd, "OLDPWD");
	free(old_pwd);
	pwd = ft_strjoin("PWD=", new_pwd);
	replace_content(&data->envp_list, pwd, "PWD");
	replace_content(&data->exp_list, pwd, "PWD");
	free(pwd);
}

static void	cdpath(t_data *data)
{
	char	*content;
	char	**paths;
	char	*tmp;
	char	*tmp_aux; // mod kevin

	content = search_env(data->envp_list, "CDPATH");
	paths = ft_split(content + 7, ':');
	free(content);
	while (*paths)
	{
		tmp_aux = ft_strjoin(*paths, "/"); // mod kevin
		tmp = ft_strjoin(tmp_aux, data->lst_process->argv[1]);
		free(tmp_aux); // mod kevin
		if (!chdir(tmp))
		{
			printf("~%s\n", tmp + ft_strlen(search_env(data->envp_list,
							"HOME") + 5));
			free_matrix(paths);
			update_pwd(data, tmp);
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		paths++;
	}
	printf("cd: no such file or directory: %s\n", data->lst_process->argv[1]);
	free_matrix(paths);
	data->lst_process->code_error = 1;
}

static void	cd_home(t_data *data)
{
	char	*content;

	content = search_env(data->envp_list, "HOME");
	if (!content)
	{
		printf(" cd: HOME not set\n");
		free(content);
		data->lst_process->code_error = 1;
		return ;
	}
	if (chdir(content + 5))
	{
		printf("cd: no such file or directory: %s\n", content + 5);
		free(content);
		data->lst_process->code_error = 1;
		return ;
	}
	update_pwd(data, content + 5);
	free(content);
}

void	ft_cd(t_data *data)
{
	if (!data->lst_process->argv[1])
	{
		cd_home(data);
		if (data->lst_process->code_error == 1)
			return ;
	}
	else if (!ft_strncmp(search_env(data->envp_list, "CDPATH"), "CDPATH=", 7))
	{
		cdpath(data);
		if (data->lst_process->code_error == 1)
			return ;	
	}
	if (chdir(data->lst_process->argv[1]))
	{
		data->lst_process->code_error = 1;
		return ;
	}
	update_pwd(data, data->lst_process->argv[1]);
}
