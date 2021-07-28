/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:16:30 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/26 18:46:22 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libminishell.h"

int	check_for_swung_dash(t_data *data)
{
	char	*content;

	content = search_env(data->envp_list, "HOME");
	if (!content[0])
	{
		free(data->lst_process->argv[1]);
		data->lst_process->argv[1] = ft_strdup(data->swung_dash);
		free(content);
		return (0);
	}
	free(data->lst_process->argv[1]);
	data->lst_process->argv[1] = ft_strdup(content + 5);
	free(content);
	return (0);
}

int	cdpath_loop(t_data *data, char **paths)
{
	int		index;
	char	*tmp;
	char	*tmp_aux;

	index = 0;
	while (paths[index])
	{
		tmp_aux = ft_strjoin(paths[index], "/");
		tmp = ft_strjoin(tmp_aux, data->lst_process->argv[1]);
		free(tmp_aux);
		if (!chdir(tmp))
		{
			tmp_aux = getcwd(0, 0);
			ft_putstr_fd(tmp_aux, data->lst_process->fd_out);
			ft_putstr_fd("\n", data->lst_process->fd_out);
			free(tmp);
			free_matrix(paths);
			update_pwd(data, tmp_aux);
			return (1);
		}
		free(tmp);
		index++;
	}
	return (0);
}
