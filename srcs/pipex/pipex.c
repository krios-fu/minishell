/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:15:11 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/16 21:47:36 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	exec_final_child(t_shell *shell, t_process *process, int *fd_back)
{
	char *path;
	pid_t pid;
	int	status;
	int fd_file;
	int fd_out;


	close (fd_back[WRITE_END]);
	pid = fork();
	if (pid == 0)
	{
		fd_file = fd_input_redirect(shell);
		if (fd_file == -1)
			exit (-1);
		else if (fd_file > 0)
		{
			dup2(fd_file, STDIN_FILENO);
			close(fd_file);
		}
		else
		{
			dup2(fd_back[READ_END], STDIN_FILENO);
			close(fd_back[READ_END]);
		}
		fd_out = fd_output_redirect(shell);
		if (fd_out >= 0)
		{
			dup2(process->fd[WRITE_END], STDOUT_FILENO);
			close(process->fd[WRITE_END]);
			dup2(fd_out, STDOUT_FILENO);
			close (fd_out);
		}
		if (fd_out < 0)
		{
			dup2(fd_back[READ_END], STDIN_FILENO); // ok
			close(fd_back[READ_END]);
		}
		/* fd_out */
		get_path(process->argv[0], shell->envp, &path);
		status = start_process(shell);
		if (status == -1)
		{
			execve(path, process->argv, NULL);
			print_error_cmd(process->argv[0]);	
		}
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
	int		status;
	int		fd_file;
	int		fd_out;

	pid = fork();
	fd_out = -1;
	if (pid == 0)
	{
		close(process->fd[READ_END]);
		/* fd int */
		fd_file = fd_input_redirect(shell);
		if (fd_file == -1)
			exit (-1);
		else if (fd_file > 0)
			{
				dup2(fd_file, STDIN_FILENO);
				close(fd_file);
			}
		
		/*  fd int */
		/*  fd out */
		fd_out = fd_output_redirect(shell);
		if (fd_out >= 0)
		{
			dup2(process->fd[WRITE_END], STDOUT_FILENO);
			close(process->fd[WRITE_END]);
			dup2(fd_out, STDOUT_FILENO);	
			close (fd_out);
		}
		if (fd_out < 0)
		{
			dup2(process->fd[WRITE_END], STDOUT_FILENO);
			close(process->fd[WRITE_END]);
			
		}
		/* fd_out */
		
		get_path(process->argv[0],shell->envp, &path);
		status = start_process(shell);
		if (status == -1)
		{
			execve(path, process->argv, shell->envp);
			print_error_cmd(process->argv[0]);
		}
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
}

void	exect_between_childs(t_shell *shell, t_process *process, int *fd_back)
{
	char *path;
	pid_t pid;
	int status;
	int fd_file;
	int fd_out;

	close (fd_back[WRITE_END]);
	pid = fork();
	if (pid == 0)
	{
		close(process->fd[READ_END]);
		fd_file = fd_input_redirect(shell);
		if (fd_file == -1)
			exit (-1);
		else if (fd_file > 0)
		{
			dup2(fd_file, STDIN_FILENO);
			close(fd_file);
		}
		else
		{
			dup2(fd_back[READ_END], STDIN_FILENO);
			close(fd_back[READ_END]);
		}
		fd_out = fd_output_redirect(shell);
		if (fd_out >= 0)
		{
			dup2(process->fd[WRITE_END], STDOUT_FILENO);
			close(process->fd[WRITE_END]);
			dup2(fd_out, STDOUT_FILENO);
			close (fd_out);
		}
		else
		{
			dup2(process->fd[WRITE_END], STDOUT_FILENO);
			close(process->fd[WRITE_END]);
		}
		get_path(process->argv[0],shell->envp, &path);
		status = start_process(shell);
		if (status == -1)
		{
			execve(path, process->argv, NULL);
			print_error_cmd(process->argv[0]);
		}
		exit(0);
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
	int		fd_file;
	int		fd_out;

	if (start_process(shell) == -1)
	{
		pid = fork();
		if (pid == 0)
		{
			fd_file = fd_input_redirect(shell);
			if (fd_file == -1)
				exit (-1);
			else if (fd_file > 0)
			{
				dup2(fd_file, STDIN_FILENO);
				close(fd_file);
			}
			/*  fd out */
			fd_out = fd_output_redirect(shell);
			if (fd_out >= 0)
			{
				dup2(shell->data->lst_process->fd[WRITE_END], STDOUT_FILENO);
				close(shell->data->lst_process->fd[WRITE_END]);
				dup2(fd_out, STDOUT_FILENO);
			}
			/* fd_out */
			get_path(shell->data->lst_process->argv[0], shell->envp, &path);
			execve(path, shell->data->lst_process->argv, NULL);
			print_error_cmd(shell->data->lst_process->argv[0]);
		}
		else
		{
			close(shell->data->lst_process->fd[WRITE_END]);
			close(shell->data->lst_process->fd[READ_END]);
		}
			
		waitpid(pid, NULL, 0);
	}
}

void	start_pipe(t_shell *shell, int *num_p)
{
	t_process	*process;

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
}