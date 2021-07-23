/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:54:05 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/23 02:19:28 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	fd_input_eof(t_redirect *input)
{
	char		*tmp;
	int			fd;

	fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC | O_APPEND,
			S_IRWXU);
	tmp = readline("> ");
	while (ft_strcmp(tmp, input->file[0]))
	{
		ft_putendl_fd(tmp, fd);
		tmp = readline("> ");
	}
	return (fd);
}

int	fd_input_redirect(t_shell *shell)
{
	t_redirect	*input;
	int			fd;

	fd = 0;
	input = shell->data->lst_process->input;
	while (input)
	{
		if (!ft_strcmp(input->symbol, "<\0"))
		{
			if (get_num_words(input->file) >=2)
				{
					ft_putstr_fd("rocketMen: ambiguous redirect\n", 2);
					return (-1);
				}
			fd  = open(input->file[0], O_RDONLY);
			if (fd == -1)
			{
				print_error_file(input->file[0]);
				return (-1);
			}
		}
		if (!ft_strcmp(input->symbol, "<<\0"))
		{
			// close(fd);
			fd = fd_input_eof(input);
			close (fd);
			fd  = open(".tmp", O_RDONLY);
		}
		input = input->next;
		if (input)
			close(fd);
	}
	return (fd);
}

int fd_output_redirect(t_shell *shell)
{
	t_redirect *output;
	int			fd;

	fd = -1;
	output = shell->data->lst_process->output;
	while (output)
	{
		if (get_num_words(output->file) >= 2)
		{
			ft_putstr_fd("rocketMen: ambiguous redirect\n", 2);
			return (-2);
		}
		if (!ft_strcmp(output->symbol, ">\0"))
				fd = open(output->file[0], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
			S_IRWXU);
		if (!ft_strcmp(output->symbol, ">>\0"))
				fd = open(output->file[0], O_WRONLY | O_CREAT | O_APPEND,
				S_IRWXU);
		output = output->next;
		if (output)
			close(fd);
	}
	return (fd);
}

