/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:45:14 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/27 11:45:17 by jacgarci         ###   ########.fr       */
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
