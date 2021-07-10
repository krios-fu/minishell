/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:21:42 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/10 20:22:56 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
**	quotes_s = '
**	quotes_d = "
*/

void change_status_quote(char *line, t_parseo *parse)
{
	if(line[parse->i] == '\"' && parse->quotes_s == false)
	{	if (parse->quotes_d == true)
			parse->quotes_d  = false;
		else
			parse->quotes_d  = true;
	}
	if(line[parse->i] == '\'' && parse->quotes_d == false)
	{	if (parse->quotes_s == true)
				parse->quotes_s  = false;
		else
			parse->quotes_s  = true;
	}
	
}

static void state_var(char *line, t_parseo *parse)
{
	if(*line && ft_isascii(*line) &&  *line != ' ' && !is_redirect(*line)
		 && parse->flag == false
		&& parse->quotes_d == false && parse->quotes_s == false)
	{
		(parse->num_arg)++;
		parse->flag = true;
	}
}

int	num_arg_process (char *line, t_process *lst_process)
{
	t_parseo	parse;
	char		c;
	
	parse.quotes_d = false;
	parse.quotes_s = false;
	parse.flag = false;
	parse.num_arg = 0;
	parse.i = 0;
	c = '\0';
	while (*line)
	{
		c = *line;
		if (is_redirect(c))
			line = get_redirect(line, lst_process);
		c = *line;
		if ( c == ' ' || is_redirect(c))
			parse.flag = false;

		change_status_quote(line, &parse);
		state_var(line, &parse);
		line++;
	}
	

	if (parse.quotes_d == true || parse.quotes_s == true)
		printf("Error quote\n");
	
	return (parse.num_arg);
}
  
char	**get_tokens_arg(t_process *process, char *line)
{
	char	**arguments;
	int		pos_arg;
	int		size;
	int		i;

	i = 0;
	pos_arg = 0;
	size = num_arg_process(line, process);
	if (size == -1)
		return(NULL);
	arguments = (char **)malloc(sizeof(char *) * (size + 1));
	while (pos_arg < size)
	{
		line = ft_isspace(line);
		while (is_redirect(*line))
		{
	
			while(is_redirect(*line))
				line++;
			line = ft_isspace(line);
			while(*line && *line != ' ' && !is_redirect(*line))
				line++;
			line = ft_isspace(line);
		}
		while (ft_isascii(line[i]) && line[i] != ' ' && line[i])
			i++;
		arguments[pos_arg] = ft_strndup(line, i);
		// if (!line[i])
			// break ;
		 line = &line[i];
		pos_arg++;
		i = 0;
	}
	arguments[size] = NULL;

	return(arguments);
}

char *next_line_process(char *line)
{
	while (*line)
		line++;
	line++;
	return(line);
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
	if(!lines_cmd[0])
		return (NULL);
	if (num_process > 1)
	{
		while(i < num_process)
		{
			line = next_line_process(line);
			lines_cmd[i] =  ft_strdup(line);
			if(!lines_cmd[i])
				return (NULL);
			i++;
		}
	}
	lines_cmd[num_process] = NULL;
	return(lines_cmd);
}
int	get_process(t_data *data, char *line)
{
	char		**line_cmd;
	t_process	*new_process;
	int			num_process;
	int			i;

	i = 0;
	num_process = get_num_pipe(line);
	if (num_process == -1)
	{
		printf("minishell 🚀 : parse error near `|'\n");
		return(0);
	}
	
	line_cmd = get_lines_cmd(line, num_process);
	if (!line_cmd)
		return (0);
		
	while (i < num_process)
	{
		new_process = (t_process *)malloc(sizeof(t_process));
		new_process->next  = NULL;
		new_process->input = NULL;
		new_process->output = NULL;
		new_process->argv  = get_tokens_arg(new_process, line_cmd[i]);
		if (i == 0)
			data->lst_process = new_process;
		else
			ft_addlst_back_process(data->lst_process, new_process);
		i++;
	}
	return(num_process);
}