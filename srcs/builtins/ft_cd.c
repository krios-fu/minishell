/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:48:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/08 19:38:34 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	cdpath(t_list *envp_list, char *path)
{
	//can CDPATH be empty?
	char	*content;
	char	**paths;
	char	*tmp;

	content = search_env(envp_list, "CDPATH");
	paths = ft_split(content + 7, ':');
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		tmp = ft_strjoin(tmp, path);
		if (!chdir(tmp))
			return (0);
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		paths++;
	}
	printf(" Error\n");
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
//	printf("%s\n", getcwd(0, 1024));
	if (chdir(path))
	{
		perror("Error");
		return (1);
	}
//	printf("%s\n", getcwd(0, 1024));
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
			cdpath(*envp_list, path);
	//if CDPATH is set
	//	if path doesnt have /
	//		path
	//cd normal
//	return (update_pwd(pwd, old_pwd));
	return (0);
}
