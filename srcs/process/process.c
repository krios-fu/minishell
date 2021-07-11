/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:30:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/11 05:40:58 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	free_resources(t_process *process)
{
	int i;

	i = 0;
	while (process->argv[i])
		free(process->argv[i++]);
	free(process->argv);
	while (process->input)
	{
		free(process->input->symbol);
		free(process->input->file);
		process->input = process->input->next;
		free(process->input);
	}
	while (process->output)
	{
		free(process->output->symbol);
		free(process->output->file);
		process->output = process->output->next;
		free(process->output);
	}
	free(process);
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
		new_process = (t_process *)malloc(sizeof(t_process));
		new_process->next = NULL;
		new_process->input = NULL;
		new_process->output = NULL;
		new_process->argv = get_tokens_arg(new_process, line_cmd[i]);
		free(line_cmd[i]);
		if (i == 0)
			data->lst_process = new_process;
		else
			ft_addlst_back_process(data->lst_process, new_process);
		i++;
	}
	free(line_cmd);
	return (num_process);
}