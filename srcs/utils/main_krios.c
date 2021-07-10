/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_krios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/10 20:26:15 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	main(void)
{
	t_process	**process;
	t_data		*data;
	char 		*line;
	int i;
	int num_p;


	num_p = 0;
	process = NULL;

	print_header();
	while (1)
	{
		i = 0;
		data = (t_data *)malloc(sizeof(t_data));
		data->lst_process = NULL;
		line = prompt();
		if (ft_strlen(line) > 0)
		{
			if (pre_parse(line) == false)
				printf("minishell: syntax error near unexpected token\n");
			else 
			{
				num_p =  get_process(data, line);
				while (i < num_p)
				{	
					
				  	// printf("content --> : [%s]\n\n", data->lst_process->argv[0]);
					  start_process(data->lst_process->argv);
					data->lst_process = data->lst_process->next;
					// printf("exito final\n");
					i++;
				}

			}
			free(process);
			free(data);
		}
		free(line);
	}
	return (0);
}
