/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:30:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/12 19:21:53 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


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
		new_process = (t_process *)malloc(sizeof(t_process));
		new_process->next = NULL;
		new_process->input = NULL;
		new_process->output = NULL;
		new_process->argv = get_tokens_arg(new_process, line_cmd[i]);
		if (new_process->argv == (void *)0)
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