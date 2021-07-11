/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_krios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/11 05:38:46 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_process	*process;
	t_data		*data;
	char 		*line;
	int i;
	int num_p;


	(void)argc;
	(void)argv;
	(void)envp;
//	(void)envp;

//	argv++;
//	ft_echo(argv);
/*
	t_shell shell;

	shell.envp_list = fill_envp_list(envp);
	shell.exp_list = fill_envp_list(envp);
	shell.exp_list = sort_env_list(&shell.exp_list);


	ft_env(shell.exp_list);
	ft_export(&shell.envp_list, &shell.exp_list, argv);
	print_list(shell.exp_list);
	// print_list(shell.envp_list);
*/
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
				printf("n_p %d\n", num_p);
				while (i < num_p)
				{	
					
					// expansive_token(data->lst_process);
					printf("content --> : [%s]\n\n", data->lst_process->argv[1]);
					//  start_process(data->lst_process->argv);
					process = data->lst_process->next;
					free_resources(data->lst_process);
					data->lst_process = process;
					i++;
				}
			}
		}
		free(data);
		free(line);
	}

	return (0);
}

/*
//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
//	(void)envp;

//	argv++;
//	ft_echo(argv);

	t_shell shell;

	shell.envp_list = fill_envp_list(envp);
	shell.exp_list = fill_envp_list(envp);
	shell.exp_list = sort_env_list(&shell.exp_list);


	ft_env(shell.exp_list);
	ft_export(&shell.envp_list, &shell.exp_list, argv);
	print_list(shell.exp_list);
	print_list(shell.envp_list);

	//printf("%s\n", getcwd(0, 1024));
	print_list(shell.exp_list);
	ft_cd(&shell.envp_list, &shell.exp_list, "utils");
	printf("\n");
	print_list(shell.exp_list);
	system("leaks minishell");
//	printf("%s\n", getcwd(0, 1024));
//	ft_cd(&shell.envp_list, &shell.exp_list, "includes");
//	printf("%s\n", getcwd(0, 1024));
}*/
