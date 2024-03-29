/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:30:51 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 16:40:50 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	expansive_token_aux(t_shell *shell, t_var *var)
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
		if (var->token[var->i][var->j] == '\"' && var->bool == false)
			var->bool = true;
		else if (var->token[var->i][var->j] == '\"' && var->bool == true)
			var->bool = false;
		if (var->token[var->i][var->j] == '$'
			&& (var->token[var->i][var->j + 1] != ' '
			&& var->token[var->i][var->j + 1] != '\0'))
		{
			len_expansive(var);
			expansive_swap(shell, var);
		}
		if (ft_strlen(var->token[var->i]) <= (size_t)var->j)
			break ;
		var->j++;
	}
}

void	expansive_token(t_shell *shell, char **argv)
{
	t_var	var;

	var.i = 0;
	var.len_exp = 0;
	var.token = argv;
	var.bool = false;
	while (var.token[var.i])
	{
		expansive_token_aux(shell, &var);
		var.i++;
	}
	shell->data->lst_process->argv = var.token;
}

void	expansive_token_input(t_shell *shell, char **argv)
{
	t_var	var;

	var.i = 0;
	var.len_exp = 0;
	var.token = argv;
	var.bool = false;
	while (var.token[var.i])
	{
		expansive_token_aux_2(shell, &var);
		var.i++;
	}
}

void	expansive_token_output(t_shell *shell, char **argv)
{
	t_var	var;

	var.i = 0;
	var.len_exp = 0;
	var.token = argv;
	var.bool = false;
	while (var.token[var.i])
	{
		expansive_token_aux_2(shell, &var);
		var.i++;
	}
}
