/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:00:26 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 13:26:31 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	is_redirect(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

char	*set_file_redirect(t_redirect *redirect, char *line)
{
	char	**file;
	int		i;

	file = malloc(sizeof(char *) * 2);
	i = 0;
	 line = ft_isspace(line);
	while (line[i])
	{
		if ((ft_isascii(line[i])) && line[i] != ' ' && !is_redirect(line[i]))
			i++;
		else
			break ;
	}
	file[0] = ft_strndup(line, i);
	file[1] = NULL;
	redirect->file = file;
	return (&line[i]);
}

char	*set_symbol_redirect(t_redirect *redirect, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_redirect(line[i]))
			i++;
		else
			break ;
	}
	redirect->symbol = ft_strndup(line, i);
	return (&line[i]);
}

char	*get_redirect(char *line, t_process *lst_process)
{
	t_redirect	*new_redirect;

	new_redirect = (t_redirect *)malloc(sizeof(t_redirect));
	line = ft_isspace(line);
	line = set_symbol_redirect(new_redirect, line);
	line = set_file_redirect(new_redirect, line);
	new_redirect->next = NULL;
	if (new_redirect->symbol[0] == '<')
	{
		if (!lst_process->input)
			lst_process->input = new_redirect;
		else
			ft_addlst_back_redirect(lst_process->input, new_redirect);
	}
	else
	{
		if (!lst_process->output)
			lst_process->output = new_redirect;
		else
			ft_addlst_back_redirect(lst_process->output, new_redirect);
	}
	return (line);
}
