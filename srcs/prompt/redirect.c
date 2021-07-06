/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:00:26 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/06 21:10:41 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int		is_redirect(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

char	*set_file_redirect(t_redirect *redirect, char *line)
{
	int	i;

	i = 0;
	line = ft_isspace(line);
	while(line[i])
	{
		if(ft_isascii(line[i]) && line[i] != ' ' && !is_redirect(line[i]))
			i++;
		else
			break ;
	}
	redirect->file = ft_strndup(line, i);
		if(redirect->file == false)
			return(NULL);
	return(&line[i]);
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
		if(redirect->symbol == false)
			return(NULL);

	return(&line[i]);
}

t_redirect *get_redirect(char *line)
{
	t_redirect	*new_redirect;
	char		*tmp;

	new_redirect = (t_redirect *)malloc(sizeof(t_redirect));
	tmp = ft_isspace(line);
	tmp = set_symbol_redirect(new_redirect, tmp);
	tmp = set_file_redirect(new_redirect, tmp);
	return(new_redirect);
}