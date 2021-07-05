/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:25:08 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/05 20:15:12 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	print_header(void)
{
	printf(GREEN"_______ ___ ___(_)_______ ___(_)___________  /_ _____ ___  /___  /\n");
	printf(GREEN"__  __ `__ \\__  / __  __ \\__  / __  ___/__  __ \\_  _ \\__  / __  /\n");
	printf(GREEN"_  / / / / /_  /  _  / / /_  /  _(__  ) _  / / //  __/_  /  _  /\n"); 
	printf(GREEN"/_/ /_/ /_/ /_/   /_/ /_/ /_/   /____/  /_/ /_/ \\___/ /_/   /_/\n");
	printf(RED"\t\t\t\t\tBy: Jacgarci && Krios-fu\n");
}

/*
char	*prompt(void)
{
	char	*line;
	line = readline(BLUE"Rocket-men 🚀"WHITE);
	return (line);
}*/

/*
**
**	this function returns a pointer
**	to the structure with the analyzed data argv (parseo)
**	see struct libminishell.h
*/

char	*ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (&str[i]);
}

int		is_redirect(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}


char	*set_dst_redirect(t_redirect *redirect, char *line)
{
	int	i;

	i = 0;
	line = ft_isspace(line);
	// printf("[[%s]]\n", line);
	while(line[i])
	{
		if(ft_isascii(line[i]) && line[i] != ' ')
			i++;
		else
			break ;
	}
	redirect->output = ft_strndup(line, i);
	if(!redirect->output)
		return(NULL);
	return(&line[i]);
}

char	*set_origin_redirect(t_redirect *redirect, char *line)
{
	int	i;

	i = 0;
	line = ft_isspace(line);
	// printf("[[%s]]\n", line);
	while(line[i])
	{
		if(ft_isascii(line[i]) && line[i] != ' ')
			i++;
		else
			break ;
	}
	redirect->input = ft_strndup(line, i);
	if(!redirect->input)
		return(NULL);
	return(&line[i]);
}

char	*set_symbol_redirect(t_redirect *redirect, char *line)
{
	int			i;
	i = 0;
	line = ft_isspace(line);
	while(line[i])
	{
		if (is_redirect(line[i]))
			i++;
		else
			break ;
	}
	redirect->symbol =ft_strndup(line, i);
	return(&line[i]);
}

char	*part_one_redirect(t_redirect *redirect, char *line)
{
	char *tmp;

	tmp = line;
	
	tmp = set_origin_redirect (redirect, tmp);
	if(!tmp)
		return (NULL);
	tmp = set_symbol_redirect(redirect, tmp);
	if(!tmp)
		return (NULL);
	tmp = set_dst_redirect(redirect, tmp);

	return(tmp);
}