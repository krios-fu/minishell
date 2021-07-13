/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:23:51 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 11:03:15 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

//int	ft_unset(t_list **envp_list, char *name)
int	ft_unset(t_data *data)
{
	char	*envp_var;
	char	*exp_var;

	envp_var = search_env(data->envp_list, data->lst_process->argv[1]);
	exp_var = search_env(data->exp_list, data->lst_process->argv[1]);
	if (envp_var)
		ft_lstdelone(&data->envp_list, (void *)envp_var);
	if (exp_var)
		ft_lstdelone(&data->exp_list, (void *)exp_var);
	return (0);
}
