/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:30:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/14 20:36:29 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


static t_process	*create_process (char **argv)
{
	t_process *new_process;

	new_process = (t_process *)malloc(sizeof(t_process));
	if (!new_process)
		return (NULL);
	new_process->next = NULL;
	new_process->input = NULL;
	new_process->output = NULL;
	new_process->argv = argv;
	return(new_process);
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
		new_process = create_process(get_tokens_arg(new_process, line_cmd[i]));
		if (!new_process || !new_process->argv)
			{
				free_matrix(line_cmd);
				free_resources(new_process);
				return (0);
			}
		if (i == 0)
			data->lst_process = new_process;
		else
			ft_addlst_back_process(data->lst_process, new_process);
		i++;
	}
	free_matrix(line_cmd);
	return (num_process);
}

void assign_fd_to_process (t_process *lst_process)
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