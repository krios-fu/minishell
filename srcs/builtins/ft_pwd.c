/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:30:01 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/23 12:41:04 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_pwd(t_data *data)
{
	char	path[1024];

	if (!getcwd(path, sizeof(path)))
	{
		data->lst_process->code_error = 1;
		return ;
	}
	ft_putstr_fd(path, data->lst_process->fd_out);
	ft_putstr_fd("\n", data->lst_process->fd_out);
}
