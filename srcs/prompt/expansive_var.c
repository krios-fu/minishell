/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:30:51 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/13 18:14:41 by krios-fu         ###   ########.fr       */
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

static void	len_expansive(t_var *var)
{
	var->j++;
	var->len_exp = 0;
	while (var->token[var->i][var->j] && (var->token[var->i][var->j] != ' '
		&& var->token[var->i][var->j] != '$' && !is_quote(var->token[var->i][var->j])))
		{
			var->len_exp++;
			var->j++;
		}
}

static void	expansive_swap(t_shell *shell, t_var *var)
{
	var->j -= var->len_exp;
	var->env = ft_strndup(&var->token[var->i][var->j], var->len_exp); 
	var->content = search_env(shell->data->envp_list, var->env);
	free(var->env);
	var->before_exp = ft_strndup(var->token[var->i], var->j - 1);
	var->join_befor_tmp = ft_strjoin(var->before_exp,
		&var->content[var->len_exp + 1]);
	var->after_exp = ft_strjoin(var->join_befor_tmp,
		&var->token[var->i][var->j + var->len_exp]);
	free(var->content);
	free(var->before_exp);
	free(var->join_befor_tmp);
	free(var->token[var->i]);
	var->token[var->i] = var->after_exp;
}
void	expansive_token(t_shell *shell)
{
	t_var	var;

	var.i = 0;
	var.len_exp = 0;
	var.token = shell->data->lst_process->argv;
	while (var.token[var.i])
	{
		var.j = 0;
		if (var.token[var.i][var.j] != '\'')
			while(var.token[var.i][var.j])
			{
				if (var.token[var.i][var.j] == '$')
					{
						len_expansive(&var);
						expansive_swap(shell, &var);
					}
				var.j++;
			}
		var.i++;
	}
	del_quotes(shell->data->lst_process);
}
