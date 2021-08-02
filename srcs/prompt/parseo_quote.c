/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:29:37 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 17:05:07 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	check_split_quote(char *arg)
{
	int	quote_d;
	int	quote_s;
	int	i;

	quote_d = 0;
	quote_s = 0;
	i = 0;
	while (arg[i])
	{
		if (is_quote(arg[i]))
		{
			if (arg[i] == '\'')
				quote_s++;
			else
				quote_d++;
		}
		i++;
	}
	if (quote_s == 2 || quote_d == 2)
		return (1);
	return (0);
}

char	get_quotes_split(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (is_quote(arg[i]))
			return (arg[i]);
		i++;
	}
	return ('\"');
}

void	del_quotes(t_process *process)
{
	t_var	var;

	var.i = 0;
	var.token = process->argv;
	while (var.token[var.i])
	{
		var.tmp_join = ft_strdup("");
		var.j = 0;
		var.tmp = ft_split(var.token[var.i],
				get_quotes_split(var.token[var.i]));
		while (var.tmp[var.j])
		{
			var.aux = var.tmp_join;
			var.tmp_join = ft_strjoin(var.tmp_join, var.tmp[var.j]);
			free(var.aux);
			free(var.tmp[var.j++]);
		}
		free(var.tmp);
		var.aux = var.token[var.i];
		var.token[var.i] = var.tmp_join;
		free(var.aux);
		var.i -= check_split_quote(var.token[var.i]);
		var.i++;
	}
}
