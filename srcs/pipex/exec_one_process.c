/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:20:52 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/25 19:52:20 by krios-fu         ###   ########.fr       */
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

static void	redirect_output(t_shell *shell)
{
	int		fd_out;

	fd_out = fd_output_redirect(shell);
	if (fd_out >= 0)
	{
		dup2(shell->data->lst_process->fd[WRITE_END], STDOUT_FILENO);
		close(shell->data->lst_process->fd[WRITE_END]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

void	exec_only_one_process(t_shell *shell)
{
	// pid_t	pid;
	char 	*path;
	int		status;

	shell->data->lst_process->fd_out = get_fd_builtins(shell);
	if (shell->data->lst_process->fd_out != -2 && start_process(shell) == -1)
	{
		if(shell->data->lst_process->fd_out > 2)
			close(shell->data->lst_process->fd_out);
		shell->data->lst_process->pid = fork();
		if (shell->data->lst_process->pid == 0)
		{
			redirect_input(shell);
			redirect_output(shell);
			get_path(shell->data->lst_process->argv[0], get_env(shell->data), &path);
			if (!*shell->data->lst_process->argv)
				exit(0);
			execve(path, shell->data->lst_process->argv, get_env(shell->data));
			if(ft_strlen(shell->data->lst_process->argv[0]))
				print_error_cmd(shell->data->lst_process->argv[0]);
			 exit(127);
		}
		else
		{
			close(shell->data->lst_process->fd[WRITE_END]);
			close(shell->data->lst_process->fd[READ_END]);
		}
		waitpid(shell->data->lst_process->pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 255)
				shell->data->error_code[0] = 127;
			else
				shell->data->error_code[0] = WEXITSTATUS(status);
		}
	}
	// else
		// shell->data->error_code[0] = 0;
}