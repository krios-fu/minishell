/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parseo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:35:34 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 14:32:31 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
**	this function returns the number of pipes and replaces the | by '\0'.
**	if there are two consecutive pipes it returns -1
*/

static void	init_parse(t_parseo *parse)
{
	(*parse).i = 0;
	(*parse).num_arg = 1;
	(*parse).quotes_s = false;
	(*parse).quotes_d = false;
}

int	get_num_pipe(char *line)
{
	t_parseo	parse;

	init_parse(&parse);
	line = ft_isspace(line);
	if (*line != '|')
	{
		while (line[parse.i])
		{
			change_status_quote(line, &parse);
			if (line[parse.i] == '|'
				&& parse.quotes_d == false && parse.quotes_s == false)
			{
				*&(line[parse.i]) = '\0';
				line = ft_isspace(&line[parse.i + 1]);
				parse.i = 0;
				if ((line[(parse.i)] == '|' || line[(parse.i)] == '\0'))
					return (-1);
				(parse.num_arg)++;
			}
			(parse.i)++;
		}
		return (parse.num_arg);
	}
	return (-1);
}

int	pre_parse(char *line)
{
	while (*line)
	{
		line = ft_isspace(line);
		if (is_redirect(*line))
		{	
			while (is_redirect(*line))
				line++;
			line = ft_isspace(line);
			if (*line == '|' || *line == false || is_redirect(*line))
				return (0);
		}
		if (*line == '|')
		{
			line++;
			line = ft_isspace(line);
			if (*line == '|' || *line == false)
				return (0);
		}
		if (*line && !is_redirect(*line))
			line++;
	}
	return (1);
}
