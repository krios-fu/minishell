/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:44:05 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/27 11:44:10 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libminishell.h"

void	update_pwd(t_data *data, char *new_pwd)
{
	char	*tmp;
	char	*pwd;
	char	*old_pwd;

	tmp = search_env(data->envp_list, "PWD");
	old_pwd = ft_strjoin("OLD", tmp);
	free(tmp);
	replace_content_envp(data, old_pwd, "OLDPWD");
	replace_content_exp(data, fill_with_dquotes(old_pwd), "OLDPWD");
	free(old_pwd);
	pwd = ft_strjoin("PWD=", new_pwd);
	replace_content_envp(data, pwd, "PWD");
	replace_content_exp(data, fill_with_dquotes(pwd), "PWD");
	free(pwd);
	if (new_pwd)
		free(new_pwd);
}

static void	normal_cd(t_data *data)
{
	if (special_path(data))
	{
		data->error_code = 1;
		return ;
	}
	if (chdir(data->lst_process->argv[1]))
	{
		data->error_code = 1;
		ft_putstr_fd("rocketMen: cd: ", 2);
		ft_putstr_fd(data->lst_process->argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	update_pwd(data, getcwd(0, 0));
}

static void	cdpath(t_data *data)
{
	char	*content;
	char	**paths;

	content = search_env(data->envp_list, "CDPATH");
	paths = ft_split(content + 7, ':');
	free(content);
	if (cdpath_loop(data, paths))
		return ;
	free_matrix(paths);
	normal_cd(data);
}

static void	cd_home(t_data *data)
{
	char	*content;
	char	*path;

	content = search_env(data->envp_list, "HOME");
	path = ft_strdup(content + 5);
	free(content);
	if (!path[0])
	{
		ft_putstr_fd("rocketMen: cd: HOME not set\n", 2);
		free(path);
		data->error_code = 1;
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("rocketMen: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		free(path);
		data->error_code = 1;
		return ;
	}
	update_pwd(data, path);
}

void	ft_cd(t_data *data)
{
	char	*tmp;

	tmp = search_env(data->envp_list, "CDPATH");
	if (!data->lst_process->argv[1])
		cd_home(data);
	else if (tmp[0])
	{
		if (check_path(data->lst_process->argv[1]))
			normal_cd(data);
		else
			cdpath(data);
	}
	else
		normal_cd(data);
	free(tmp);
	data->error_code = 0;
}
