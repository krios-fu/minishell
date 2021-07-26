/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:54:04 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/26 13:30:56 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_echo(t_data *data)
{
	int	flag;
	int	index;

	flag = 0;
	index = 1;
	if (!data->lst_process->argv[index])
	{
		ft_putstr_fd("\n", data->lst_process->fd_out);
		return ;
	}
	if (ft_strnstr(data->lst_process->argv[index], "-n\0", 2))
	{
		flag = 1;
		index++;
	}
	while (data->lst_process->argv[index])
	{
		if (data->lst_process->argv[index + 1])
		{
			ft_putstr_fd(data->lst_process->argv[index], data->lst_process->fd_out);
			ft_putstr_fd(" ", data->lst_process->fd_out);
		}
		else
			ft_putstr_fd(data->lst_process->argv[index], data->lst_process->fd_out);
		index++;
	}
	if (!flag)
		ft_putstr_fd("\n", data->lst_process->fd_out);
	data->error_code = 0;
}
