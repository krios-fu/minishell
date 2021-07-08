/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parseo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:35:34 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/08 23:32:21 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
**	this function returns the number of pipes and replaces the | by '\ 0'.
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
			if (line[(parse.i)] == '|')
				return (-1);
			(parse.num_arg)++;
		}
		(parse.i)++;
	}
	return(parse.num_arg);
}