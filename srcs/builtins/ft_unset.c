/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:23:51 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 20:34:11 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_unset(t_data *data)
{
	char	*envp_var;
	char	*exp_var;

	envp_var = search_env(data->envp_list, data->lst_process->argv[1]);
	exp_var = search_env(data->exp_list, data->lst_process->argv[1]);
	if (envp_var)
		ft_lstdelone(&data->envp_list, (void *)envp_var);
	if (exp_var)
		ft_lstdelone(&data->exp_list, (void *)exp_var);
	free(envp_var);
	free(exp_var);

}
