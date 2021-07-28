/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_between.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:48:45 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 17:08:15 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	close_fd_parent(t_process *process, int *fd_back)
{
	close(fd_back[READ_END]);
	close(process->fd[WRITE_END]);
}

static void	redirect_input (t_shell *shell, int *fd_back)
{
	int	fd_file;

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
	int	fd_out;

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
	char	*path;

	close (fd_back[WRITE_END]);
	process->pid = fork();
	if (process->pid == 0)
	{
		process->fd_out = get_fd_builtins(shell);
		close(process->fd[READ_END]);
		redirect_input(shell, fd_back);
		redirect_output(shell, process);
		get_path(process->argv[0], get_env(shell->data), &path);
		if (process->fd_out != -2 && start_process(shell) == -1)
		{
			if (!*process->argv)
				exit(0);
			signal(SIGQUIT, signal_child);
			execve(path, process->argv, get_env(shell->data));
			if (ft_strlen(process->argv[0]))
				print_error_cmd(process->argv[0]);
		}
		exit(0);
	}
	else
		close_fd_parent(process, fd_back);
}
