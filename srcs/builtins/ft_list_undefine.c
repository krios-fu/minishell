/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_undefine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:09:55 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/29 02:44:31 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static char	**ft_dupmatrix(char **str1)
{
	char	**new_matrix;
	int		len;
	int		i;

	i = 0;
	len = get_num_words_matrix(str1);
	new_matrix = malloc(sizeof(char *) * (len + 1));
	while (str1[i])
	{
		new_matrix[i] = ft_strdup(str1[i]);
		i++;
	}
	new_matrix[len] = NULL;
	return (new_matrix);
}

static void	aux_ft_lst_undefine(t_data *data, t_var *var)
{
	if (!data->tmp_var_list)
	{
		data->tmp_var_list = ft_lstnew(ft_strdup(var->tmp[var->i]));
		(var->i)++;
	}
	while (var->tmp[var->i] && ft_strchr(var->tmp[var->i], '='))
	{
		ft_lstadd_back(&data->tmp_var_list,
			ft_lstnew(ft_strdup(var->tmp[var->i])));
		(var->i)++;
	}
}

static char	**return_argv(t_data *data, t_var *var)
{
	char	**tmp;

	if (var->tmp[var->i])
	{
		tmp = ft_dupmatrix(&var->tmp[(var->i)]);
		free_matrix(data->lst_process->argv);
		return (tmp);
	}
	else
	{
		free_matrix(data->lst_process->argv);
		return (NULL);
	}
}

char	**ft_lst_undefine(t_data	*data)
{
	t_var	var;
	char	**tmp;

	var.tmp = data->lst_process->argv;
	var.i = 0;
	if (*var.tmp[var.i] && ft_strchr(var.tmp[var.i], '='))
	{
		aux_ft_lst_undefine(data, &var);
		return (return_argv(data, &var));
	}
	else
	{
		tmp = ft_dupmatrix(data->lst_process->argv);
		free_matrix(data->lst_process->argv);
		return (tmp);
	}
}
