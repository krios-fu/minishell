/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:15:11 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/25 19:05:19 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	init_all_pipe(t_shell *shell)
{
	t_process *process;

	process = shell->data->lst_process;
	while (process)
	{
		pipe(process->fd);
		process = process->next;
	}
}



void	start_pipe(t_shell *shell, int *num_p)
{
	t_process	*process;
	t_process *process_pid;
	

	process_pid = shell->data->lst_process;
	process = shell->data->lst_process;
	if (*num_p == 1)
	{
		exec_only_one_process(shell);
		return ;
	}
	init_all_pipe(shell);
	exec_first_child(shell, process);
	while (*num_p > 2)
	{
		shell->data->lst_process = process->next;
		exect_between_childs(shell, process->next, process->fd);
		process = process->next;
		(*num_p)--;
	}
	shell->data->lst_process = process->next;
	exec_final_child(shell, process->next, process->fd);
	while (process_pid)
	{
		waitpid(process_pid->pid, &process_pid->status, 0);
		process_pid = process_pid->next;
	}
	if (WIFEXITED(process->next->status))
	{
		if (WEXITSTATUS(process->next->status) == 255)
			shell->data->error_code[0]= 127;
		else
			shell->data->error_code[0] = WEXITSTATUS(process->next->status);
	}
}