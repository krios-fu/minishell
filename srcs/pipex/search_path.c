/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:56:22 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 18:58:19 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	loop(char **paths, char *cmd, char **f_path)
{
	char	*path_cmd;
	char	*path;
	int		index;
	int		fd;

	index = 0;
	path = 0;
	while (paths[index])
	{
		path = ft_strjoin(paths[index], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
		{
			*f_path = path_cmd;
			free_matrix(paths);
			close(fd);
			return ;
		}
		free(path_cmd);
		index++;
	}
}

static char	*mini_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	get_path(char *cmd, char *envp[], char **f_path)
{
	char	**paths;
	int		fd;

	if (*cmd == '.')
	{
		fd = open(cmd, O_RDONLY);
		if (fd >= 0)
		{
			*f_path = ft_strdup(cmd);
			close (fd);
			return ;
		}
	}
	if (!mini_path(envp))
	{
		*f_path = NULL;
		return ;
	}
	paths = ft_split(ft_strchr(mini_path(envp), '/'), ':');
	if (!paths)
	{
		*f_path = NULL;
		return ;
	}
	loop(paths, cmd, f_path);
}

char	**split_cmd_arg(char *argv)
{
	char	**cmd_arg;

	cmd_arg = ft_split(argv, ' ');
	return (cmd_arg);
}
