/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:55:06 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/29 12:45:27 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libminishell.h"

static int	check_for_dhyphen(t_data *data)
{
	char	*content;

	content = search_env(data->envp_list, "HOME");
	if (!content[0])
	{
		ft_putstr_fd("rocketMen: cd: HOME not set\n", 2);
		free(content);
		return (1);
	}
	free(data->lst_process->argv[1]);
	data->lst_process->argv[1] = ft_strdup(content + 5);
	free(content);
	return (0);
}

static int	check_for_hyphen(t_data *data)
{
	char	*content;

	content = search_env(data->envp_list, "OLDPWD");
	if (!content[0])
	{
		ft_putstr_fd("rocketMen: cd: OLDPWD not set\n", 2);
		free(content);
		return (1);
	}
	free(data->lst_process->argv[1]);
	data->lst_process->argv[1] = ft_strdup(content + 7);
	ft_putstr_fd(content + 7, data->lst_process->fd_out);
	ft_putstr_fd("\n", data->lst_process->fd_out);
	free(content);
	return (0);
}

static int	check_for_dot(t_data *data)
{
	char	*content;

	content = search_env(data->envp_list, "PWD");
	free(data->lst_process->argv[1]);
	data->lst_process->argv[1] = ft_strdup(content + 4);
	free(content);
	return (0);
}

int	special_path(t_data *data)
{
	if (!ft_strncmp(data->lst_process->argv[1], ".", 2))
		return (check_for_dot(data));
	else if (!ft_strncmp(data->lst_process->argv[1], "-", 2))
		return (check_for_hyphen(data));
	else if (!ft_strncmp(data->lst_process->argv[1], "--", 3))
		return (check_for_dhyphen(data));
	else if (!ft_strncmp(data->lst_process->argv[1], "~", 2))
		return (check_for_swung_dash(data));
	return (0);
}

int	check_path(char *path)
{
	if (!ft_strncmp(path, ".", 2)
		|| !ft_strncmp(path, "..", 3)
		|| !ft_strncmp(path, "-", 2)
		|| !ft_strncmp(path, "--", 3)
		|| !ft_strncmp(path, "~", 2))
		return (1);
	return (0);
}
