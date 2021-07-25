/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:09:12 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/25 19:42:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


static void message_exit (t_data  *data)
{
	char *logname;

	logname = search_env(data->envp_list, "LOGNAME");
	printf(CYAN"roc"BLUE"ket"GREEN"Men 👋 "RED"bye"WHITE" %s\n", &logname[8]);
}

void	ft_exit(t_data *data)
{
	int	code;

	code = 0;
	
	if (!data->lst_process->argv[1] )
	{
		message_exit(data);
		exit(0);
	}
	if (min_atoi(data->lst_process->argv[1]) == -1 )
	{
		ft_putstr_fd("rocketMen: exit: ", 2);
		ft_putstr_fd(data->lst_process->argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		 message_exit(data);
		exit(255);
	}
	if (get_num_words_join(data->lst_process->argv) > 2)
	{
		printf("exit\n");
		ft_putstr_fd("rocketMen: exit: too many arguments\n", 2);
		data->error_code[0] = 1;
		printf("%d***\n", data->error_code[0]);
		return ;
	}
	if (data->lst_process->argv[1])
	{
		message_exit(data);
		exit(min_atoi(data->lst_process->argv[1]));
	}
	message_exit(data);
}
