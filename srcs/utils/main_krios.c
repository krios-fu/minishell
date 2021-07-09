/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_krios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/09 22:57:23 by krios-fu         ###   ########.fr       */
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
		if (pre_parse(line) == false)
			printf("minishell: syntax error near unexpected token\n");
		else
		{
			
		process =  get_process(line);
		if (process)
		{
			while (process[j])
			{	
				// printf("[%d]\n", search_builtins(process[j]));
				start_process(process[j]);
				j++;
			}
		}
		}
		free(line);
	}
	return (0);
}
