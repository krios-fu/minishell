/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:15:11 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/29 01:37:51 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	start_pipe2(t_shell *shell, t_process *process, t_process *pro_pid)
{
	while (pro_pid)
	{
		waitpid(pro_pid->pid, &pro_pid->status, 0);
		if (pro_pid->status == 2)
			shell->data->error_code = 130;
		if (pro_pid->status == 3)
			shell->data->error_code = 131;
		pro_pid = pro_pid->next;
	}
	if (WIFEXITED(process->next->status))
	{
		if (WEXITSTATUS(process->next->status) == 255)
			shell->data->error_code = 127;
		else
			shell->data->error_code = WEXITSTATUS(process->next->status);
	}
}

void	init_all_pipe(t_shell *shell)
{
	t_process	*process;

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
	t_process	*process_pid;

	process_pid = shell->data->lst_process;
	shell->status = true;
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
	start_pipe2(shell, process, process_pid);
}
