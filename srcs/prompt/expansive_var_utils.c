/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansive_var_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:07:12 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 20:35:41 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	len_expansive(t_var *var)
{
	var->j++;
	var->len_exp = 0;
	while (var->token[var->i][var->j]
		&& (var->token[var->i][var->j] != ' '
		&& var->token[var->i][var->j] != '$'
		&& var->token[var->i][var->j] != '/'
		&& var->token[var->i][var->j] != '='
		&& var->token[var->i][var->j] != '\0'
		&& !is_quote(var->token[var->i][var->j])))
	{
		var->len_exp++;
		var->j++;
	}
}

int	get_num_words_matrix (char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**matrixjoin(char **str1, char **str2, int insec_point)
{
	char	**new_matrix;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = get_num_words_matrix(str1) + get_num_words_matrix(str2);
	new_matrix = malloc(sizeof(char *) * (len));
	while (i < insec_point)
	{
		new_matrix[i] = ft_strdup(str1[i]);
		i++;
	}
	while (str2[j])
	{
		new_matrix[i + j] = ft_strdup(str2[j]);
		j++;
	}
	j--;
	while (str1[++i])
		new_matrix[i + j] = ft_strdup(str1[i]);
	new_matrix[len - 1 ] = NULL;
	return (new_matrix);
}

void	loop_expa_redirect(t_shell *shell, t_redirect *redirect)
{
	while (redirect)
	{
		if (ft_strcmp(redirect->symbol, "<<\0"))
			expansive_token(shell, redirect->file);
		redirect = redirect->next;
	}
}
