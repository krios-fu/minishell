/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:09:12 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/25 18:21:31 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_exit(t_data *data)
{
	int	code;

	code = 0;
	printf("exit\n");
	if (!data->lst_process->argv[1])
		exit(0);
	if (min_atoi(data->lst_process->argv[1]) == -1)
	{
		ft_putstr_fd("rocketMen: exit: ", 2);
		ft_putstr_fd(data->lst_process->argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (*data->lst_process->argv[2])
	{
		ft_putstr_fd("rocketMen: exit: too many arguments\n", 2);
		data->error_code = 1;
		return ;
	}
	if (data->lst_process->argv[1])
		exit(min_atoi(data->lst_process->argv[1]));
	exit (0);
}
