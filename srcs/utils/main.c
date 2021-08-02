/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/08/02 14:51:36 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static t_shell	*init_minishell(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->data = (t_data *)malloc(sizeof(t_data));
	shell->status = false;
	shell->data->envp_list = fill_envp_list(envp);
	shell->data->exp_list = fill_exp_list(envp);
	shell->data->tmp_var_list = NULL;
	shell->data->num_p = 0;
	g_error_code = 0;
	sort_env_list(shell->data->exp_list);
	fill_slung_dash(shell->data);
	return (shell);
}

void	init_fd_redirect(t_shell *shell)
{
	assign_fd_to_process(shell->data->lst_process);
	if (shell->data->lst_process->input)
		loop_expa_redirect_input(shell, shell->data->lst_process->input);
	if (shell->data->lst_process->output)
		loop_expa_redirect_output(shell, shell->data->lst_process->output);
}

static void	init_process(t_shell *shell, int num_process)
{
	int	i;

	i = 0;
	while (i < num_process)
	{	
		expansive_token(shell, shell->data->lst_process->argv);
		del_quotes(shell->data->lst_process);
		shell->data->lst_process = shell->data->lst_process->next;
		i++;
	}
}

void	start_parseo(t_shell *shell, char *line)
{
	t_process	*process;
	int			num_process;

	num_process = 0;
	if (line && *line)
	{
		if (pre_parse(line) == false)
			printf("minishell: syntax error near unexpected token\n");
		else
		{
			num_process = get_process(shell->data, line);
			if (num_process > 0)
			{
				init_fd_redirect(shell);
				process = shell->data->lst_process;
				init_process(shell, num_process);
				shell->data->lst_process = process;
				start_pipe(shell, &num_process);
				shell->data->lst_process = process;
			}
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell		*shell;
	char		*line;

	(void)argc;
	(void)argv;
	shell = init_minishell(envp);
	print_header();
	print_welcome(shell);
	g_error_code = 0;
	while (1)
	{
		shell->data->lst_process = NULL;
		signals();
		line = prompt(shell);
		add_history(line);
		start_parseo(shell, line);
		free_resources(shell->data->lst_process);
		if (!line)
		{
			write(1, CYAN"roc"BLUE"ket"GREEN"Men 👋 "RED"exit\n", 49);
			exit(0);
		}
		free(line);
	}
	return (0);
}
