/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parseo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:35:34 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/10 01:52:14 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
**	this function returns the number of pipes and replaces the | by '\0'.
**	if there are two consecutive pipes it returns -1
*/

int	get_num_pipe(char *line)
{
	t_parseo	parse;
	char		*tmp;

	parse.i = 0;
	tmp = line;
	parse.num_arg = 1;
	parse.quotes_s = false;
	parse.quotes_d = false;
	line = ft_isspace(line);
	if (*line != '|')
	{
		while(line[parse.i])
		{
			change_status_quote(line, &parse);
			if (line[parse.i] == '|'
					&& parse.quotes_d == false && parse.quotes_s == false)
			{
				tmp = &(line[parse.i]);
				*tmp = '\0';
				line = ft_isspace(&line[parse.i + 1]);
				parse.i = 0;
				if ((line[(parse.i)] == '|' || line[(parse.i)] == '\0'))
					return (-1);
				(parse.num_arg)++;
			}
			(parse.i)++;
		}

		printf("pipe exito\n");
		return(parse.num_arg);
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
			line++;
			line = ft_isspace(line);
			if (*line == '|' || *line == false)
				return (0);
		}
		if (*line == '|')
		{
			line++;
			line = ft_isspace(line);
			if (*line == '|' || *line == false)
				return (0);
		}
		if (!is_redirect(*line))
			line++;
	}
	printf("exito\n");
	return (1);
}