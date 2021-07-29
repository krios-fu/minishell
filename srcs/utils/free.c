/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:04:13 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/29 13:36:15 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	free_shell_data(t_shell *shell)
{
	free(shell->data);
	free(shell);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

void	free_redirect(t_redirect *redirect)
{
	t_redirect	*tmp;

	while (redirect)
	{
		if (redirect->file[0])
		{
			free (redirect->file[0]);
			free (redirect->file[1]);
			free (redirect->file);
		}
		free(redirect->symbol);
		tmp = redirect->next;
		free(redirect);
		redirect = tmp;
	}
}

void	free_resources(t_process *process)
{
	t_process	*tmp;

	while (process)
	{
		if (process->argv)
			free_matrix(process->argv);
		free_redirect(process->input);
		free_redirect(process->output);
		if (process->fd)
		{
			close(process->fd[0]);
			close(process->fd[1]);
			free(process->fd);
		}
		tmp = process->next;
		free(process);
		process = tmp;
	}
	unlink(".tmp");
}
