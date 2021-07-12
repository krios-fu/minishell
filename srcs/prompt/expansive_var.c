/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:30:51 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/12 02:28:36 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"



/*
**	char** (*get_var)(t_list *, char *)
*/

int		is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int		check_split_quote(char *arg)
{
	int q_d;
	int q_s;
	int i;

	i = 0;
	q_d = 0;
	q_s = 0;

	while (arg[i])
	{
		if (is_quote(arg[i]))
		{
			if(arg[i] == '\'')
				q_s++;
			else
				q_d++;
		}
		i++;
	}
	if (q_s == 2 || q_d == 2)
		return (1);
	return (0);
}

char	get_quotes_split(char *arg)
{
	int i;

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
	int i;
	int j;
	int len_token;
	char **tmp;
	char *tmp_join;
	char *aux;

	i = 0;
	j = 0;
	len_token = 0;
	while (process->argv[i] != (void *)0)
	{
		tmp_join = ft_strdup("");
		j = 0;
		tmp = ft_split(process->argv[i], get_quotes_split(process->argv[i]));
		while (tmp[j])
		{
			aux = tmp_join;
			tmp_join = ft_strjoin(tmp_join, tmp[j]);
			 free(aux);
			 free(tmp[j]);
			j++;
		}
		free(tmp);
		aux = process->argv[i];
		process->argv[i] = tmp_join;
		free(aux);
		i -= check_split_quote(process->argv[i]);
		i++;
	}
}

void	expansive_token(t_process *process)
{
	int		i;
	int		j;
	int		len_exp;
	char	*tmp;
	char	*before_exp;
	char	*after_exp;
	char	*join_befor_tmp;

	i = 0;
	j = 0;
	len_exp = 0;
	// (void)get_var;
	while (process->argv[i])
	{
		j = 0;
		if (process->argv[i][j] != '\'')
			while(process->argv[i][j])
			{
				if (process->argv[i][j] == '$')
					{
						j++;
						len_exp = 0;
						while (process->argv[i][j] && (process->argv[i][j] != ' '
							&& process->argv[i][j] != '$' && !is_quote(process->argv[i][j])))
							{
								len_exp++;
								j++;
							}
						 j -= len_exp;
						tmp = ft_strndup("42\0", 2); // val $
						before_exp = ft_strndup(process->argv[i], j - 1);
						join_befor_tmp = ft_strjoin(before_exp, tmp);
						after_exp = ft_strjoin(join_befor_tmp, &process->argv[i][j + len_exp]);
						free(tmp);
						free(before_exp);
						free(join_befor_tmp);
						free(process->argv[i]);
						process->argv[i] = after_exp;
					}
				j++;
			}
		i++;
	}
	del_quotes(process);
}
