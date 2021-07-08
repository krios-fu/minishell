/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:54:04 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/08 18:13:42 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_echo(char **args)
{
	int	flag;
	int	index;

	flag = 0;
	index = 0;
	if (!args || !**args)
		printf("\n");
	if (!ft_strncmp(args[index], "-n", 2))
	{
		flag = 1;
		index++;
	}
	while (args[index])
	{
		if (args[index + 1])
			printf("%s ", args[index]);
		else
			printf("%s", args[index]);
		index++;
	}
	if (!flag)
		printf("\n");
	return (0);
}
