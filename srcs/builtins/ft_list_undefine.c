/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_undefine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:09:55 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/24 15:10:06 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_lst_undefine(t_data	*data)
{
	t_var	var;

	var.tmp = data->lst_process->argv;
	var.i = 0;
	data->tmp_var_list = ft_lstnew(ft_strdup(var.tmp[var.i]));
	while (var.tmp[var.i])
	{
		ft_lstadd_back(&data->tmp_var_list, ft_lstnew(ft_strdup(var.tmp[var.i])));
		(var.i)++;
	}
}