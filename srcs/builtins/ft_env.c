/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:45:14 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/27 18:36:28 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_env(t_data *data)
{
	t_list	*lst;

	if (!data->envp_list)
	{
		data->error_code = 1;
		return ;
	}
	if (data->lst_process->argv[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(data->lst_process->argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		data->error_code = 1;
		return ;
	}
	lst = data->envp_list;
	while (lst->next)
	{
		ft_putstr_fd(lst->content, data->lst_process->fd_out);
		ft_putstr_fd("\n", data->lst_process->fd_out);
		lst = lst->next;
	}
	ft_putstr_fd(lst->content, data->lst_process->fd_out);
	ft_putstr_fd("\n", data->lst_process->fd_out);
	data->error_code = 0;
}
