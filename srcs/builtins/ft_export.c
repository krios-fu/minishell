/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:40:34 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 23:10:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	print_export_list(t_data *data)
{
	t_list	*lst;

	lst = data->exp_list;
	while (lst)
	{
		ft_putstr_fd("declare -x ", data->lst_process->fd_out);
		ft_putstr_fd(lst->content, data->lst_process->fd_out);
		ft_putstr_fd("\n", data->lst_process->fd_out);
		lst = lst->next;
	}
}
/*
void	ft_export(t_data *data)
{
	int	index;

	index = 1;
	if (!data->lst_process->argv[1])
		print_export_list(data);
	while (data->lst_process->argv[index])
	{
		if (ft_strchr(data->lst_process->argv[index], '='))
			ft_lstadd_back(&data->envp_list, ft_lstnew(ft_strdup(data->lst_process->argv[index])));
		ft_lstadd_front(&data->exp_list, ft_lstnew(ft_strdup(data->lst_process->argv[index])));
		index++;
	}
	sort_env_list(data->exp_list);
}
*/
void	ft_export(t_data *data)
{
	if (!data->lst_process->argv[1])
		print_export_list(data);
	
}
