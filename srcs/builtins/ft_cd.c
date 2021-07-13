/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:48:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 17:40:51 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	update_pwd(t_data *data, char *new_pwd)
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
	return (0);
}

static int	cdpath(t_data *data)
{
	char	*content;
	char	**paths;
	char	*tmp;

	content = search_env(data->envp_list, "CDPATH");
	paths = ft_split(content + 7, ':');
	free(content);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		tmp = ft_strjoin(tmp, data->lst_process->argv[1]);
		if (!chdir(tmp))
		{
			printf("~%s\n", tmp + ft_strlen(search_env(data->envp_list,
							"HOME") + 5));
			free_tab(paths);
			return (update_pwd(data, tmp));
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		paths++;
	}
	printf("cd: no such file or directory: %s\n", data->lst_process->argv[1]);
	free_tab(paths);
	return (1);
}

static int	cd_home(t_data *data)
{
	char	*content;
	char	*path;

	content = search_env(envp_list, "HOME");
	if (!content)
	{
		printf(" cd: HOME not set\n");
		free(content);
		return (1);
	}
	if (chdir(content + 5))
	{
		printf("cd: no such file or directory: %s\n", content + 5);
		free(content);
		return (1);
	}
	update_pwd(data, content + 5);
	free(content);
	return (0);
}

int	ft_cd(t_data *data)
{
	if (!data->lst_process->argv[1])
	{
		if (cd_home(data->envp_list))
			return (1);
	}
	else if (!ft_strncmp(search_env(data->envp_list,
					"CDPATH"), "CDPATH=", 7))
		return (cdpath(data));
	if (chdir(data->lst_process->argv[1]))
		return (1);
	return (update_pwd(data, data->lst_process->argv[1]));
}
