/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_undefine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:09:55 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/24 17:24:25 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

char	**ft_lst_undefine(t_data	*data)
{
	t_var	var;

	var.tmp = data->lst_process->argv;
	var.i = 0;
	data->tmp_var_list = ft_lstnew(ft_strdup(var.tmp[var.i]));
	(var.i)++;
	while (ft_strchr(var.tmp[var.i], '='))
	{
		ft_lstadd_back(&data->tmp_var_list, ft_lstnew(ft_strdup(var.tmp[var.i])));
		free(var.tmp[var.i]);
		(var.i)++;
	}
	return(&var.tmp[(var.i)]);
}