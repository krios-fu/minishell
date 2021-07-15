/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:15:11 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/15 23:37:18 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	exec_final_child(t_shell *shell, t_process *process, int *fd_back)
{
	char *path;
	pid_t pid;

	close (fd_back[WRITE_END]);
	pid = fork();
	if (pid == 0)
	{

		dup2(fd_back[READ_END], STDIN_FILENO); // ok
		close(fd_back[READ_END]);
		get_path(process->argv[0],shell->envp, &path);
		
		if (start_process(shell) == -1)
		execve(path, process->argv, NULL);
		// else
		exit(0);
	}
	else
	{
		close(process->fd[WRITE_END]);
		close(process->fd[READ_END]);
		waitpid(pid, NULL, 0);
	}
	
}

void	exec_first_child(t_shell *shell, t_process *process)
{
	char *path;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(process->fd[READ_END]);
		dup2(process->fd[WRITE_END], STDOUT_FILENO);
		close(process->fd[WRITE_END]);
		get_path(process->argv[0],shell->envp, &path);
		if (start_process(shell) == -1)
			execve(path, process->argv, NULL);
		 exit(0);
	}
	else
		waitpid(pid, NULL, 0);
}

void	exect_between_childs(t_shell *shell, t_process *process, int *fd_back)
{
	char *path;
	pid_t pid;

	close (fd_back[WRITE_END]);
	pid = fork();
	if (pid == 0)
	{
		close(process->fd[READ_END]);
		dup2(fd_back[READ_END], STDIN_FILENO);
		close(fd_back[READ_END]);
		dup2(process->fd[WRITE_END], STDOUT_FILENO);
		close(process->fd[WRITE_END]);
		get_path(process->argv[0],shell->envp, &path);
		// if (start_process(shell) == -1)
			execve(path, process->argv, NULL);
		// else
			// exit(0);
	}
	else
	{
		close(fd_back[READ_END]);
		close(process->fd[WRITE_END]);
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

void	exec_only_one_process(t_shell *shell)
{
	pid_t	pid;
	char 	*path;

	if (start_process(shell) == -1)
	{
		pid = fork();
		if (pid == 0)
		{
			get_path(shell->data->lst_process->argv[0],	shell->envp, &path);
			execve(path, shell->data->lst_process->argv, NULL);
			print_error_cmd(shell->data->lst_process->argv[0]);
		}
		waitpid(pid, NULL, 0);
	}
}

void	start_pipe(t_shell *shell, int *num_p)
{
	t_process	**process;

	process = &shell->data->lst_process;
	
	init_all_pipe(shell);
	exec_first_child(shell, *process);
	while (*num_p > 2)
	{
		exect_between_childs(shell, (*process)->next, (*process)->fd);
		*process = (*process)->next;
		(*num_p)--;
	}
	exec_final_child(shell, (*process)->next, (*process)->fd);
}