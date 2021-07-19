/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:14:55 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 18:47:24 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_env(t_data *data)
{
	t_list *lst;

	if (!data->envp_list)
	{
		data->lst_process->code_error = 1;
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
}
