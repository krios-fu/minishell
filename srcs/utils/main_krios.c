/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_krios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/10 03:36:30 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	main(void)
{
	t_process	**process;
	char 		*line;
	int i;
	int num_p;

	i = 0;
	num_p = 0;
	process = NULL;

	print_header();
	while (1)
	{
		line = prompt();
		printf("[[%zu]]\n", ft_strlen(line));
		if (ft_strlen(line) > 0)
		{
			if (pre_parse(line) == false)
				printf("minishell: syntax error near unexpected token\n");
			else 
			{
				num_p =  get_process(&process, line);
				printf("num process [%d]\n", num_p);
					while (i < num_p)
					{	
						
						//   printf("content : [%s]\n", (*process[i]).argv[0]);
						// start_process(&process[i]);
						printf("exito final\n");
						i++;
					}

			}
			free(process);
		}
		free(line);
	}
	return (0);
}
