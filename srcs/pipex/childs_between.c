/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_between.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:48:45 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/16 22:53:34 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


static void redirect_input (t_shell *shell, int *fd_back)
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
	else
	{
		dup2(fd_back[READ_END], STDIN_FILENO);
		close(fd_back[READ_END]);
	}	
}

static void	redirect_output(t_shell *shell, t_process *process)
{
	int fd_out;

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
void	exect_between_childs(t_shell *shell, t_process *process, int *fd_back)
{
	char *path;
	pid_t pid;

	close (fd_back[WRITE_END]);
	pid = fork();
	if (pid == 0)
	{
		close(process->fd[READ_END]);
		redirect_input(shell, fd_back);
		redirect_output(shell, process);
		get_path(process->argv[0],shell->envp, &path);

		if (start_process(shell) == -1)
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