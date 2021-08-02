/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:40:27 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 14:17:10 by krios-fu         ###   ########.fr       */
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
		if (var->token[var->i][var->j] == '\"' && var->bool == false)
			var->bool = true;
		else if (var->token[var->i][var->j] == '\"' && var->bool == true)
			var->bool = false;
		if (var->token[var->i][var->j] == '$')
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
