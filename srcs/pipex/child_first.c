/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:39:47 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/24 19:55:44 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void redirect_input (t_shell *shell)
{
	int fd_file;

	fd_file = fd_input_redirect(shell);
	if (fd_file == -1)
		exit (-1);
	else if (fd_file > 0)
		{
			dup2(fd_file, STDIN_FILENO);
			close(fd_file);
		}
}

static void	redirect_output(t_shell *shell, t_process *process)
{
	int		fd_out;

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
}

void	exec_first_child(t_shell *shell, t_process *process)
{
	char *path;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		process->fd_out = get_fd_builtins(shell);
		close(process->fd[READ_END]);
		redirect_input(shell);
		redirect_output(shell, process);
		get_path(process->argv[0],shell->envp, &path);
		if (process->fd_out != -2 && start_process(shell) == -1)
		{
			if (!*process->argv)
				exit(0);
			execve(path, process->argv, shell->envp);
			if(ft_strlen(process->argv[0]))
				print_error_cmd(process->argv[0]);
		}
		exit(0);
	}
	// else
		// waitpid(pid, NULL, 0);
}