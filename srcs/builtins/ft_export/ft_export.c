/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:40:34 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 23:10:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libminishell.h"

static void	print_export_list(t_data *data)
{
	t_list	*lst;

	lst = data->exp_list;
	while (lst)
	{
		ft_putstr_fd("declare -x ", data->lst_process->fd_out);
		ft_putstr_fd(lst->content, data->lst_process->fd_out);
		ft_putstr_fd("\n", data->lst_process->fd_out);
		lst = lst->next;
	}
}
/*
void	ft_export(t_data *data)
{
	int	index;

	index = 1;
	if (!data->lst_process->argv[1])
		print_export_list(data);
	while (data->lst_process->argv[index])
	{
		if (ft_strchr(data->lst_process->argv[index], '='))
			ft_lstadd_back(&data->envp_list, ft_lstnew(ft_strdup(data->lst_process->argv[index])));
		ft_lstadd_front(&data->exp_list, ft_lstnew(ft_strdup(data->lst_process->argv[index])));
		index++;
	}
	sort_env_list(data->exp_list);
}
*/
static void	envp_part(t_data *data, char *var)
{
	char	*name;

	name = get_name(var);
	if (already_exist(data->envp_list, var))
		replace_content(&data->envp_list, var, name);
	else
		if (ft_strchr(var, '='))
			ft_lstadd_back(&data->envp_list, ft_lstnew(ft_strdup(var)));
	free(name);
}

//	if (already_exist(data->exp_list, var))
static void	exp_part(t_data *data, char *var)
{
	char	*name;

	name = get_name(var);
	if (already_exist(data->exp_list, var))
		replace_content(&data->exp_list, fill_with_dquotes(var), name);
	else
	{
		if (ft_strchr(var, '='))
			ft_lstadd_back(&data->exp_list, ft_lstnew(fill_with_dquotes(var)));
	//	else
	//		si var esta en lista de locales
	//			export a envp y exp
	//		else
	//			export solo a exp
	}
	free(name);
}

void	ft_export(t_data *data)
{
	int	index;

	if (!data->lst_process->argv[1])
	{
		print_export_list(data);
		return ;
	}
	index = 1;
	while (data->lst_process->argv[index])
	{
		envp_part(data, data->lst_process->argv[index]);
		exp_part(data, data->lst_process->argv[index]);
		index++;
	}
	sort_env_list(data->exp_list);
}