/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:46:20 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/27 11:46:24 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_pwd(t_data *data)
{
	char	path[1024];

	if (!getcwd(path, sizeof(path)))
	{
		data->error_code = 1;
		return ;
	}
	ft_putstr_fd(path, data->lst_process->fd_out);
	ft_putstr_fd("\n", data->lst_process->fd_out);
	data->error_code = 0;
}
