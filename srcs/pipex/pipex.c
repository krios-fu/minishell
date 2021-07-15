/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:15:11 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/15 02:41:37 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	exec_between_child(t_shell *shell, t_process *process, int *fd_back)
{
	char *path;
	pid_t pid;

	close (fd_back[WRITE_END]);
	pid = fork();
	if (pid == 0)
	{
	 	// close (process->fd[READ_END]);
		
		dup2(fd_back[READ_END], STDIN_FILENO); // ok
		close(fd_back[READ_END]);
		// dup2(process->fd[WRITE_END], STDOUT_FILENO);
		// close(process->fd[WRITE_END]);
		//  dup2(process->fd[READ_END], STDIN_FILENO);
		get_path(process->argv[0],shell->envp, &path);
		execve(path, process->argv, NULL);
	}
	else
	{
		// close(process->fd[WRITE_END]);
		close(process->fd[READ_END]);
		waitpid(pid, NULL, 0);
	}
	
}

void	exec_first_child(t_shell *shell, t_process *process)
{
	char *path;
	pid_t	pid;

	pipe(process->fd);
	pid = fork();
	if (pid == 0)
	{
		close(process->fd[READ_END]);
		dup2(process->fd[WRITE_END], STDOUT_FILENO);
		close(process->fd[WRITE_END]);
		get_path(process->argv[0],shell->envp, &path);
		execve(path, process->argv, NULL);
	}
	else
	{
		exec_between_child(shell, process->next, process->fd);
		// close(process->fd[WRITE_END]);
		// close(process->fd[READ_END]);
		waitpid(pid, NULL, 0);
	}

}


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

void	start_pipe(t_shell *shell, t_process *lst_process, int *num_p)
{
	t_process	*process;

	(void)*num_p;
	process = lst_process;
	
	init_all_pipe(shell);
	exec_first_child (shell, process);
}