/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:21:42 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/16 20:06:39 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
**	quotes_s = '
**	quotes_d = "
*/

static void	state_var(char *line, t_parseo *parse)
{
	if (*line && ft_isascii(*line) && *line != ' ' && !is_redirect(*line)
		 && parse->flag == false
		&& parse->quotes_d == false && parse->quotes_s == false)
	{
		(parse->num_arg)++;
		parse->flag = true;
	}
}

int	num_arg_process(char *line, t_process *lst_process)
{
	t_parseo	parse;
	char		c;

	parse.quotes_d = false;
	parse.quotes_s = false;
	parse.num_arg = 0;
	parse.flag = false;
	parse.i = 0;
	c = '\0';
	while (*line)
	{
		c = *line;
		if (is_redirect(c))
			line = get_redirect(line, lst_process);
		c = *line;
		if (c == ' ' || is_redirect(c))
			parse.flag = false;
		change_status_quote(line, &parse);
		state_var(line, &parse);
		if (!*line)
			break;
		line++;
	}
	if (parse.quotes_d == true || parse.quotes_s == true)
	{
		printf("Error quote\n");
		return (0);
	}
	return (parse.num_arg);
}

static char	*next_line_process(char *line)
{
	while (*line)
		line++;
	line++;
	return (line);
}

char	**get_lines_cmd(char *line, int num_process)
{
	char	**lines_cmd;
	int		i;

	i = 1;
	lines_cmd = (char **)malloc(sizeof(char *) * (num_process + 1));
	if (!lines_cmd)
		return (NULL);
	lines_cmd[0] = ft_strdup(line);
	if (!lines_cmd[0])
		return (NULL);
	if (num_process > 1)
	{
		while (i < num_process)
		{
			line = next_line_process(line);
			lines_cmd[i] = ft_strdup(line);
			if (!lines_cmd[i])
				return (NULL);
			i++;
		}
	}
	lines_cmd[num_process] = NULL;
	return (lines_cmd);
}
