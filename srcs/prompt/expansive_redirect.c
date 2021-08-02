/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:40:27 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 17:00:47 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	expansive_token_aux_2(t_shell *shell, t_var *var)
{
	var->j = 0;
	if (var->token[var->i][var->j] == '\'')
	{
		var->j++;
		while (var->token[var->i][var->j] != '\'')
			var->j++;
	}
	while (var->token[var->i][var->j])
	{
		if (var->token[var->i][var->j] == '$'
			&& (var->token[var->i][var->j + 1] != ' '
			&& var->token[var->i][var->j + 1] != '\0'))
		{
			len_expansive(var);
			var->j -= var->len_exp;
			var->env = ft_strndup(&var->token[var->i][var->j], var->len_exp);
			expansive_swap_case2(shell, var);
			free(var->env);
		}
		if (ft_strlen(var->token[var->i]) <= (size_t)var->j)
			break ;
		var->j++;
	}
}

void	del_quotes_redirect(t_redirect *redirect)
{
	t_var	var;

	var.i = 0;
	var.token = redirect->file;
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
