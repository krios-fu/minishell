/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:54:04 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/15 21:14:56 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_echo(t_data *data)
{
	int	flag;
	int	index;

	flag = 0;
	index = 1;
	if (!data->lst_process->argv[index])
	{
		printf("\n");
		return ;
	}
	if (ft_strnstr(data->lst_process->argv[index], "-n\0", 2))
	{
		flag = 1;
		index++;
	}
	while (data->lst_process->argv[index])
	{
		if (data->lst_process->argv[index + 1])
			printf("%s ", data->lst_process->argv[index]);
		else
			 printf("%s", data->lst_process->argv[index]);
		index++;
	}
	if (!flag)
		printf("\n");
	// return (0);
}
