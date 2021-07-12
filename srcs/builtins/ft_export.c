/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:40:34 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/12 18:27:07 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	print_export_list(t_list *lst)
{
	while (lst)
	{
		printf("%s%s\n", "declare -x ", lst->content);
		lst = lst->next;
	}
	return (0);
}

int	ft_export(t_data *data)
{
	int	index;

	index = 1;
	if (!data->lst_process->argv[1])
		return (print_export_list(data->exp_list));
	while (data->lst_process->argv[index])
	{
		if (ft_strchr(data->lst_process->argv[index], '='))
			ft_lstadd_back(&data->envp_list,
					ft_lstnew(ft_strdup(data->lst_process->argv[index])));
		ft_lstadd_front(&data->exp_list,
				ft_lstnew(ft_strdup(data->lst_process->argv[index])));
		index++;
	}
	sort_env_list(&data->exp_list);
	return (0);
}
