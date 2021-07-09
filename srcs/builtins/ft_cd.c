/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:48:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/09 13:25:49 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	update_pwd(char *new_pwd, t_list **envp_list, t_list **exp_list)
{
	char	*tmp;
	char	*tmp2;
	char	*old_pwd;
	char	**exports;

	exports = malloc(sizeof(char *) * 2);
	if (!exports)
		return (1);
	tmp = search_env(*envp_list, "PWD");
	old_pwd = ft_strjoin("OLD", tmp);
	ft_lstdelone(envp_list, search_env(*envp_list, "OLDPWD"));
	ft_lstdelone(exp_list, search_env(*exp_list, "OLDPWD"));
	exports[0] = old_pwd;
	exports[1] = 0;
	ft_export(envp_list, exp_list, exports);
	ft_lstdelone(envp_list, search_env(*envp_list, "PWD"));
	ft_lstdelone(exp_list, search_env(*exp_list, "PWD"));
	tmp2 = ft_strjoin("PWD=", new_pwd);
	exports[0] = tmp2;
	ft_export(envp_list, exp_list, exports);

	return (0);
}

static int	cdpath(t_list **envp_lst, t_list **exp_list, char *path)
{
	char	*content;
	char	**paths;
	char	*tmp;

	content = search_env(*envp_lst, "CDPATH");
	paths = ft_split(content + 7, ':');
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		tmp = ft_strjoin(tmp, path);
		if (!chdir(tmp))
		{
			printf("~%s\n", tmp + ft_strlen(search_env(*envp_lst, "HOME") + 5));
			return (update_pwd(tmp, envp_lst, exp_list));
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		paths++;
	}
	printf("cd: no such file or directory: %s\n", path);
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
		perror("Error");
		return (1);
	}
	free(path);
	return (0);
}

int	ft_cd(t_list **envp_list, t_list **exp_list, char *path)
{
	(void)exp_list;
	if (!path)
	{
		if (cd_home(*envp_list))
			return (1);
	}
	else if (!ft_strncmp(search_env(*envp_list, "CDPATH"), "CDPATH=", 7))
		return (cdpath(envp_list, exp_list, path));
	if (chdir(path))
		return (1);
	return (update_pwd(path, envp_list, exp_list));
}
