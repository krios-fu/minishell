/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:30:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 14:16:58 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static t_process	*create_process(void)
{
	t_process	*new_process;

	new_process = (t_process *)malloc(sizeof(t_process));
	if (!new_process)
		return (NULL);
	new_process->next = NULL;
	new_process->input = NULL;
	new_process->output = NULL;
	new_process->argv = NULL;
	return (new_process);
}

static int	check_process_argv(t_process *n_process, char **l_cmd, int i)
{
	n_process->argv = get_tokens_arg(n_process, l_cmd[i]);
	n_process->fd = NULL;
	if (!n_process->argv)
	{
		free_matrix(l_cmd);
		free_resources(n_process);
		return (0);
	}
	return (1);
}

static int	check_new_process(t_process *n_process, char **line_cmd)
{
	if (!n_process)
	{
		free_matrix(line_cmd);
		free_resources(n_process);
		return (0);
	}
	return (1);
}

int	get_process(t_data *data, char *line)
{
	t_process	*new_process;
	int			num_process;
	char		**line_cmd;
	int			i;

	i = 0;
	num_process = get_num_pipe(line);
	line_cmd = get_lines_cmd(line, num_process);
	if (!line_cmd || num_process == -1)
		return (0);
	while (i < num_process)
	{
		new_process = create_process();
		if (!check_new_process(new_process, line_cmd))
			return (0);
		if (!check_process_argv(new_process, line_cmd, i))
			return (0);
		if (i == 0)
			data->lst_process = new_process;
		else
			ft_addlst_back_process(data->lst_process, new_process);
		i++;
	}
	free_matrix(line_cmd);
	return (num_process);
}

void	assign_fd_to_process(t_process *lst_process)
{
	t_process	*tmp_process;

	tmp_process = lst_process;
	while (tmp_process)
	{
		tmp_process->fd = malloc(sizeof(int) * 2);
		if (!tmp_process->fd)
		{
			free_resources(lst_process);
			printf("Error malloc");
			break ;
		}
		tmp_process = tmp_process->next;
	}
}
