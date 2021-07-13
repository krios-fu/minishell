/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:48:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 13:24:55 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	update_pwd(t_data *data, char *new_pwd)
{
	char	*tmp;
	char	*tmp2;
	char	*old_pwd;
	char	**exports;

	exports = malloc(sizeof(char *) * 3);
	if (!exports)
		return (1);
	tmp = search_env(data->envp_list, "PWD");
	old_pwd = ft_strjoin("OLD", tmp);
	ft_lstdelone(&data->envp_list, search_env(data->envp_list, "OLDPWD"));
	ft_lstdelone(&data->exp_list, search_env(data->exp_list, "OLDPWD"));
	exports[0] = old_pwd;
	exports[1] = old_pwd;
	exports[3] = 0;
	//free(data->lst_process->argv);
	data->lst_process->argv = exports;
	ft_export(data);
	ft_lstdelone(&data->envp_list, search_env(data->envp_list, "PWD"));
	ft_lstdelone(&data->exp_list, search_env(data->exp_list, "PWD"));
	tmp2 = ft_strjoin("PWD=", new_pwd);
	exports[1] = tmp2;
	data->lst_process->argv = exports;
	ft_export(data);
	return (0);
}

static int	cdpath(t_data *data)
{
	char	*content;
	char	**paths;
	char	*tmp;

	content = search_env(data->envp_list, "CDPATH");
	paths = ft_split(content + 7, ':');
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		tmp = ft_strjoin(tmp, data->lst_process->argv[1]);
		if (!chdir(tmp))
		{
			printf("~%s\n", tmp + ft_strlen(search_env(data->envp_list,
							"HOME") + 5));
			return (update_pwd(data, tmp));
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		paths++;
	}
	printf("cd: no such file or directory: %s\n", data->lst_process->argv[1]);
	return (1);
}

static int	cd_home(t_list *envp_list)
{
	char	*content;
	char	*path;

	content = search_env(envp_list, "HOME");
	if (!content)
	{
		printf(" cd: HOME not set\n");
		return (1);
	}
	path = ft_strdup(content + 5);
	if (chdir(path))
	{
		printf("cd: no such file or directory: %s\n", path);
		free(path);
		return (1);
	}
	//update pwd;
	free(path);
	return (0);
}

//int	ft_cd(t_list **envp_list, t_list **exp_list, char *path)
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
