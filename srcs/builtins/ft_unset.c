/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:23:51 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/25 18:22:30 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	invalid_arg(t_data *data, char *arg)
{
	if (ft_strchr(arg, '='))
	{
		ft_putstr_fd("rocketMen: unset: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		data->error_code = 1;
		return (1);
	}
	return (0);
}

static void	unset_arg(t_data *data, char *arg)
{
	char	*envp_var;
	char	*exp_var;

	envp_var = search_env(data->envp_list, arg);
	exp_var = search_env(data->exp_list, arg);
	if (envp_var)
		ft_lstdelone(&data->envp_list, (void *)envp_var);
	if (exp_var)
		ft_lstdelone(&data->exp_list, (void *)exp_var);
	free(envp_var);
	free(exp_var);
}

void	ft_unset(t_data *data)
{
	int	index;

	index = 1;
	if (!data->lst_process->argv[index])
		return ;
	while (data->lst_process->argv[index])
	{
		if (invalid_arg(data, data->lst_process->argv[index]))
			return ;
		unset_arg(data, data->lst_process->argv[index]);
		index++;
	}
}
