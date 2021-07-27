/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:44:57 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/27 11:45:01 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	print_args(t_data *data, int *index)
{
	while (data->lst_process->argv[*index])
	{
		if (data->lst_process->argv[*index + 1])
		{
			ft_putstr_fd(data->lst_process->argv[*index],
				data->lst_process->fd_out);
			ft_putstr_fd(" ", data->lst_process->fd_out);
		}
		else
			ft_putstr_fd(data->lst_process->argv[*index],
				data->lst_process->fd_out);
		(*index)++;
	}
}

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
	print_args(data, &index);
	if (!flag)
		ft_putstr_fd("\n", data->lst_process->fd_out);
	data->error_code = 0;
}
