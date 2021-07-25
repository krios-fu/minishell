/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:48:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/25 19:04:39 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libminishell.h"

static void	update_pwd(t_data *data, char *new_pwd)
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

static void normal_cd(t_data *data)
{
	
	if (special_path(data))
	{
		data->error_code[0] = 1;
		return ;
	}
	if (chdir(data->lst_process->argv[1]))
	{
		data->error_code[0] = 1;
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
	char	*tmp;
	char	*tmp_aux;
	int		index;

	content = search_env(data->envp_list, "CDPATH");
	paths = ft_split(content + 7, ':');
	free(content);
	index = 0;
	while (paths[index])
	{
		tmp_aux = ft_strjoin(paths[index], "/");
		tmp = ft_strjoin(tmp_aux, data->lst_process->argv[1]);
		free(tmp_aux);
		if (!chdir(tmp))
		{
			tmp_aux = getcwd(0,0);
			ft_putstr_fd(tmp_aux, data->lst_process->fd_out);
			ft_putstr_fd("\n", data->lst_process->fd_out);
			free(tmp);
			free_matrix(paths);
			update_pwd(data, tmp_aux);
			return ;
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		index++;
	}
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
		data->error_code[0] = 1;
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("rocketMen: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		free(path);
		data->error_code[0] = 1;
		return ;
	}
	update_pwd(data, path);
}

void	ft_cd(t_data *data)
{
	if (!data->lst_process->argv[1])
		cd_home(data);
	else if (!ft_strncmp(search_env(data->envp_list, "CDPATH"), "CDPATH=", 7))
	{
		if (check_path(data->lst_process->argv[1]))
			normal_cd(data);
		else
			cdpath(data);
	}
	else
		normal_cd(data);
}
