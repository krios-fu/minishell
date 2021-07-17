/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:30:51 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/17 22:59:16 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	len_expansive(t_var *var)
{
	var->j++;
	var->len_exp = 0;
	while (var->token[var->i][var->j] && (var->token[var->i][var->j] != ' '
		&& var->token[var->i][var->j] != '$'
			&& !is_quote(var->token[var->i][var->j])))
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


/* todo: expansive redirect input & output*/
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
				if(ft_strlen(var.token[var.i]) < (size_t)var.j)
					break ;
				var.j++;
			}
		var.i++;
	}
	del_quotes(shell->data->lst_process);
}
