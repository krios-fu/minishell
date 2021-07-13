/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_krios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 13:21:59 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"
/*
int	main(int argc, char *argv[], char *envp[])
{
	t_process	*process;
	t_shell		*shell;
	char 		*line;
	int i;
	int num_p;


	(void)argc;
	(void)argv;
	(void)envp;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->data = (t_data *)malloc(sizeof(t_data));
//	(void)envp;

//	argv++;
//	ft_echo(argv);

	 shell->data->envp_list = fill_envp_list(envp);
	 shell->data->exp_list = fill_envp_list(envp);
	 shell->data->exp_list = sort_env_list(&shell->data->exp_list);



	 
	num_p = 0;
	process = NULL;

	print_header();
	while (1)
	{
		i = 0;
		shell->data->lst_process = NULL;
		line = prompt();
		if (ft_strlen(line) > 0)
		{
			if (pre_parse(line) == false)
				printf("minishell: syntax error near unexpected token\n");
			else 
			{
				 num_p =  get_process(shell->data, line);
				if (num_p == 0)
				{
					free_resources(shell->data->lst_process);
				}
				printf("n_p %d\n", num_p);
				process = shell->data->lst_process;
				while (i < num_p)
				{	
					
					// expansive_token(shell->data->lst_process);
					 printf("content --> : [%s]\n\n", shell->data->lst_process->argv[1]);
					 start_process(shell);
					shell->data->lst_process = shell->data->lst_process->next;
					i++;
				}
				free_resources(process);
			}
		}
		free(line);
	}

	return (0);
}
*/

//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
//	(void)argv;
//	(void)envp;

//	argv++;
//	ft_echo(argv);

	t_shell shell;
	t_data data;
	t_process lst_process;
//	shell = (t_shell *)malloc(sizeof(t_shell));
//	shell->data = (t_data *)malloc(sizeof(t_data));
	shell.data = &data;
	shell.data->lst_process = &lst_process;

	shell.data->envp_list = fill_envp_list(envp);
	shell.data->exp_list = fill_envp_list(envp);
	shell.data->exp_list = sort_env_list(&shell.data->exp_list);
	shell.data->lst_process->argv = argv;
//	print_list(data.envp_list);
//	printf("\n");
//	printf("%s\n", getcwd(0, 1024));
	ft_cd(&data);
	data.lst_process->argv[1] = "includes";
	ft_cd(&data);
//	printf("%s\n", getcwd(0, 1024));
//	print_list(data.envp_list);
//	ft_echo(shell.data);
//	ft_export(shell.data);
//	ft_env(shell.data);
//	printf("\n");
//	print_list(shell.data->exp_list);
//	shell.data->lst_process->argv[1] = "A";
//	ft_unset(&data);
//	ft_env(shell.data);
//	printf("\n");
//	print_list(shell.data->exp_list);
//	ft_env(shell->data);
//	print_list(shell.data->exp_list);
//	ft_export(&shell.envp_list, &shell.exp_list, argv);
//	print_list(shell.exp_list);
//	print_list(shell.envp_list);

	//printf("%s\n", getcwd(0, 1024));
//	print_list(shell.exp_list);
//	ft_cd(&shell.envp_list, &shell.exp_list, "utils");
//	printf("\n");
//	print_list(shell.exp_list);
//	system("leaks minishell");
//	printf("%s\n", getcwd(0, 1024));
//	ft_cd(&shell.envp_list, &shell.exp_list, "includes");
//	printf("%s\n", getcwd(0, 1024));

}
