/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:30:51 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 01:51:51 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static void	len_expansive(t_var *var)
{
	var->j++;
	var->len_exp = 0;
	while (var->token[var->i][var->j] && (var->token[var->i][var->j] != ' '
		&& var->token[var->i][var->j] != '$' && var->token[var->i][var->j] != '/'
		&& var->token[var->i][var->j] != '='
			&& !is_quote(var->token[var->i][var->j])))
		{
			var->len_exp++;
			var->j++;
		}
}

 int get_num_words_matrix (char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**matrixjoin(char **str1, char **str2, int insec_point)
{
	int len_str1;
	int len_str2;
	char	**new_matrix;
	int i;
	int j;

	i = 0;
	j = 0;
	len_str1 = get_num_words_matrix(str1);
	len_str2 = get_num_words_matrix(str2);
	new_matrix = malloc(sizeof(char *) * (len_str1 + len_str2));
	while(i < insec_point)
	{
		new_matrix[i] = ft_strdup(str1[i]);
		i++;
	}
	while (str2[j])
	{
		new_matrix[i + j] = ft_strdup(str2[j]);
		j++;
	}
	i++;
	j--;
	while (str1[i])
	{
		new_matrix[i + j] = ft_strdup(str1[i]);
		i++;
	}
	printf ("%d\n", len_str2 + len_str1);
	new_matrix[len_str2 + len_str1 -1 ] = NULL;
	
	return(new_matrix);
}

static void	expansive_swap(t_shell *shell, t_var *var)
{
	char **tmp_matrix;
	char **split_matrix;
	// int i = 0;

	var->j -= var->len_exp;
	var->env = ft_strndup(&var->token[var->i][var->j], var->len_exp);
	if (*var->env == '?' && var->len_exp == 1)
	{
		var->content = ft_itoa(shell->data->error_code);
		var->before_exp = ft_strndup(var->token[var->i], var->j - 1);
		var->join_befor_tmp = ft_strjoin(var->before_exp,
		var->content);
			var->after_exp = ft_strjoin(var->join_befor_tmp,
		&var->token[var->i][var->j + var->len_exp]);
		
	}
	else if (var->bool == true)
	{
		var->content = search_env(shell->data->envp_list, var->env);
		var->before_exp = ft_strndup(var->token[var->i], var->j - 1);
		var->join_befor_tmp = ft_strjoin(var->before_exp,
			&var->content[var->len_exp + 1]);
				var->after_exp = ft_strjoin(var->join_befor_tmp,
		&var->token[var->i][var->j + var->len_exp]);
	}
	else
	{
		var->content = search_env(shell->data->envp_list, var->env);
		split_matrix = ft_split(&var->content[var->len_exp + 1], ' ');
		tmp_matrix = matrixjoin(var->token, split_matrix, var->i);
		free_matrix( var->token);
		var->token = tmp_matrix;
		var->i += (get_num_words_matrix(split_matrix) - 1);
		
		return ;
		
	}

	free(var->env);
	free(var->content);
	if (var->before_exp)
		free(var->before_exp);
	free(var->join_befor_tmp);
	free(var->token[var->i]);
	var->token[var->i] = var->after_exp;
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
		var.j = 0;
		if (var.token[var.i][var.j] == '\'')
		{
			var.j++;
			while (var.token[var.i][var.j] != '\'')
				var.j++;
		}
			while(var.token[var.i][var.j])
			{
				if (var.token[var.i][var.j] == '\"' && var.bool == false)
					var.bool = true;
				else if (var.token[var.i][var.j] == '\"' && var.bool == true)
					var.bool = false;
				if (var.token[var.i][var.j] == '$')
					{
						len_expansive(&var);
						expansive_swap(shell, &var);
							//  while (var->token[i])
						
					}
				if(ft_strlen(var.token[var.i]) <= (size_t)var.j)
					break ;
				var.j++;
			}
		var.i++;
	}

	//  argv = var.token;
	 
	shell->data->lst_process->argv = var.token;
	del_quotes(shell->data->lst_process);
}



void loop_expa_redirect(t_shell *shell, t_redirect *redirect)
{
	while (redirect)
	{
		if (ft_strcmp(redirect->symbol, "<<\0"))
			expansive_token(shell, redirect->file);
		redirect = redirect->next;
	}
}