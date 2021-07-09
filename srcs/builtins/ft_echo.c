/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:54:04 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/09 22:51:54 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_echo(char **args)
{
	int	flag;
	int	index;

	flag = 0;
	index = 1;
	if (!args[index])
	{
		printf("\n");
		return (0);
	}
	if (ft_strnstr(args[index], "-n\0", 2))
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
