/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/09 02:50:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	main(void)
{
	t_process	**process;
	char 		*line;
	int i;
	int j;

	i = 0;
	j = 0;

	print_header();
	while (1)
	{
		j = 0;
		line = prompt();
		process =  get_process(line);
		if (process)
			while (process[j])
			{
				i = 0;
				while(process[j]->argv[i])
				{
					printf("arg [%d] [%s]\n", i, process[j]->argv[i]);
					i++;
				}
				j++;
			}
		free(line);
	}
	return (0);
}
