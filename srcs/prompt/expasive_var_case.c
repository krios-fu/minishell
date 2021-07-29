/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expasive_var_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:24:34 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/29 02:26:15 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	expansive_swap_case1(t_shell *shell, t_var *var)
{
	(void)shell;
	var->content = ft_itoa(g_error_code);
	var->before_exp = ft_strndup(var->token[var->i], var->j - 1);
	var->join_befor_tmp = ft_strjoin(var->before_exp, var->content);
	var->after_exp = ft_strjoin(var->join_befor_tmp,
			&var->token[var->i][var->j + var->len_exp]);
	free(var->token[var->i]);
	free(var->env);
	free(var->content);
	free(var->before_exp);
	free(var->join_befor_tmp);
	var->token[var->i] = var->after_exp;
}

void	expansive_swap_case2(t_shell *shell, t_var *var)
{
	var->content = search_env(shell->data->envp_list, var->env);
	var->before_exp = ft_strndup(var->token[var->i], var->j - 1);
	var->join_befor_tmp = ft_strjoin(var->before_exp,
			&var->content[var->len_exp + 1]);
	var->after_exp = ft_strjoin(var->join_befor_tmp,
			&var->token[var->i][var->j + var->len_exp]);
	free(var->token[var->i]);
	var->token[var->i] = var->after_exp;
	free(var->env);
	free(var->content);
	free(var->before_exp);
	free(var->join_befor_tmp);
}

void	expansive_swap_case3(t_shell *shell, t_var *var)
{
	char	**tmp_matrix;
	char	**split_matrix;
	char	*tmp;

	var->content = search_env(shell->data->envp_list, var->env);
	if (*var->content)
	{
		var->before_exp = ft_strndup(var->token[var->i], var->j - 1);
		split_matrix = ft_split(&var->content[var->len_exp + 1], ' ');
		tmp_matrix = matrixjoin(var->token, split_matrix, var->i);
		var->join_befor_tmp = ft_strjoin(var->before_exp, tmp_matrix[var->i]);
		tmp = tmp_matrix[var->i];
		tmp_matrix[var->i] = ft_strjoin(var->join_befor_tmp,
				&var->token[var->i][var->j + var->len_exp]);
		free_matrix(var->token);
		free(var->before_exp);
		free(var->join_befor_tmp);
		free(tmp);
		var->token = tmp_matrix;
		var->i += (get_num_words_matrix(split_matrix) - 1);
		var->i = 0;
		var->j = 0;
		free_matrix(split_matrix);
	}
	free(var->content);
}

void	expansive_swap(t_shell *shell, t_var *var)
{
	var->j -= var->len_exp;
	var->env = ft_strndup(&var->token[var->i][var->j], var->len_exp);
	if (*var->env == '?' && var->len_exp == 1)
		expansive_swap_case1(shell, var);
	else if (var->bool == true)
		expansive_swap_case2(shell, var);
	else
	{
		expansive_swap_case3(shell, var);
		free(var->env);
		return ;
	}
}
