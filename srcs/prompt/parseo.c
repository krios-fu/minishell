/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:21:42 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/07 22:11:25 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


/*
**	quotes_s = '
**	quotes_d = "
*/

static void state_var(char c, t_parseo *parse)
{
	if(ft_isascii(c) &&  c != ' ' && !is_redirect(c)
		&& c != '|' && parse->flag == false
		&& parse->quotes_d == false && parse->quotes_s == false)
	{
		(parse->num_arg)++;
		parse->flag = true;
		if (c == '\"')
			parse->quotes_d = true;
		if (c == '\'')
			parse->quotes_s = true;
	}
}
size_t	num_arg_process (char *line)
{
	t_parseo parse;
	char c;
	
	parse.quotes_d = false;
	parse.quotes_s = false;
	parse.flag = false;
	parse.num_arg = 0;
	parse.i = 0;
	c = '\0';
	while (line[parse.i])
	{
		c = line[parse.i];
		if ( c == ' ' || is_redirect(c) || c == '|')
			parse.flag = false;
		if (c == '\"')
			parse.quotes_d = false;
		if (c == '\'')
			parse.quotes_s = false;
		state_var(c, &parse);
		parse.i++;
	}

	if (parse.quotes_d == true || parse.quotes_s == true)
		printf("Error quote\n");
	return (parse.num_arg);
}
/*
char	**set_words(t_process *prosess, char *line)
{
	char **arg;
	size_t size;

	size = num_arg(line);
	arg = (char **)malloc(sizeof(char *) * size);
	
}*/
/*
char	*get_process(t_process *process, char *line)
{
	
}*/