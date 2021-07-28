/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:51:37 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 16:50:49 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	main_loop(t_shell *shell)
{
	t_process	*process;
	char		*line;
	char		**tmpline;
	int			i;
	int			num_p;

	process = 0;
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
				shell->data->num_p = num_p;
				if (num_p > 0)
				{
					assign_fd_to_process(shell->data->lst_process);
					if (shell->data->lst_process->input)
						loop_expa_redirect(shell, shell->data->lst_process->input);
					if (shell->data->lst_process->output)
						loop_expa_redirect(shell, shell->data->lst_process->output);
				process = shell->data->lst_process;
				while (i < num_p)
				{
					expansive_token(shell, shell->data->lst_process->argv);
					tmpline = shell->data->lst_process->argv;
					shell->data->lst_process->argv	= final_token(ft_lst_undefine(shell->data));
					free_matrix(tmpline);
					shell->data->lst_process = shell->data->lst_process->next;
					i++;
				}
				shell->data->lst_process = process;
				start_pipe(shell, &num_p);
				free_resources(process);
				}
				else
					shell->data->error_code = 258;
			}
		}
		if (!line)
		{
			write(1, CYAN"roc"BLUE"ket"GREEN"Men 👋 "RED"exit\n", 49);
			exit(0);
		}
		free(line);
	}
}

t_shell	*init_shell(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->data = (t_data *)malloc(sizeof(t_data));
	shell->status = false;
	shell->data->envp_list = fill_envp_list(envp);
	shell->data->exp_list = fill_exp_list(envp);
	shell->data->tmp_var_list = NULL;
	shell->data->error_code = 0;
	sort_env_list(shell->data->exp_list);
	fill_slung_dash(shell->data);
	return (shell);
}

