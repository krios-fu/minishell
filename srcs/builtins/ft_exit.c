/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:45:29 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/28 14:02:48 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	message_exit(t_data *data)
{
	char	*logname;

	logname = search_env(data->envp_list, "LOGNAME");
	printf(CYAN"roc"BLUE"ket"GREEN"Men 👋 "RED"bye"WHITE" %s\n", &logname[8]);
}

static void	not_numeric_arg(t_data *data)
{
	ft_putstr_fd("rocketMen: exit: ", 2);
	ft_putstr_fd(data->lst_process->argv[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	 message_exit(data);
}

void	ft_exit(t_data *data)
{
	if (!data->lst_process->argv[1])
	{
		message_exit(data);
		exit(0);
	}
	if (min_atoi(data->lst_process->argv[1]) == -1 )
	{
		not_numeric_arg(data);
		exit(255);
	}
	if (get_num_words_join(data->lst_process->argv) > 2)
	{
		printf("exit\n");
		ft_putstr_fd("rocketMen: exit: too many arguments\n", 2);
		data->error_code = 1;
		return ;
	}
	if (data->lst_process->argv[1])
	{
		message_exit(data);
		exit(min_atoi(data->lst_process->argv[1]));
	}
	message_exit(data);
	data->error_code = 0;
	exit(0);
}
