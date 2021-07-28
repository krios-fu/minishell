/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/28 20:39:56 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_process	*process;
	t_shell		*shell;
	char 		*line;
	int i;
	int num_p;
	// char 		**tmpline;

//	char		c;


	(void)argc;
	(void)argv;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->data = (t_data *)malloc(sizeof(t_data));
	shell->status = false;
	shell->data->envp_list = fill_envp_list(envp);
	shell->data->exp_list = fill_exp_list(envp);
	shell->data->tmp_var_list = NULL;
	shell->data->error_code = 0;
	sort_env_list(shell->data->exp_list);

	num_p = 0;
	process = NULL;

	print_header();
	print_welcome(shell);
	while (1)
	{
		i = 0;
		shell->data->lst_process = NULL;
		signals();
		line = prompt(shell);
		add_history(line);
		if (line && ft_strlen(line) > 0)
		{

			if (pre_parse(line) == false)
				printf("minishell: syntax error near unexpected token\n");
			else 
			{
				 num_p =  get_process(shell->data, line);

				if (num_p > 0)
				{
					assign_fd_to_process(shell->data->lst_process);
					// if (shell->data->lst_process->input)
						// loop_expa_redirect(shell, shell->data->lst_process->input);
					// if (shell->data->lst_process->output)
						// loop_expa_redirect(shell, shell->data->lst_process->output);
				process = shell->data->lst_process;
				while (i < num_p)
				{	
					expansive_token(shell, shell->data->lst_process->argv);
					// tmpline = shell->data->lst_process->argv;
					 shell->data->lst_process->argv	= ft_lst_undefine(shell->data);

					shell->data->lst_process = shell->data->lst_process->next;
					i++;
				}
				shell->data->lst_process = process;
	

				start_pipe(shell, &num_p);
				// shell->data->lst_process->argv = tmpline;
				// free_matrix(tmpline);
				// free_resources(process);
				}
				else
					shell->data->error_code = 258;
			}
		}
		if (!line)
		{
			write(1, CYAN"\nroc"BLUE"ket"GREEN"Men 👋 "RED"exit\n", 49);
			exit(0);
		}
		// printf("[[%d]] \n", shell->data->error_code);
		free(line);
	}

	return (0);
}
