/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:20:31 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/26 14:51:39 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

char	*fill_with_dquotes(char *envp)
{
	char	*tmp;
	int		index;

	tmp = ft_calloc(sizeof(char *), (ft_strlen(envp) + 1));
	index = 0;
	while (envp[index] != '=')
	{
		tmp[index] = envp[index];
		index++;
	}
	tmp[index] = envp[index];
	index++;
	tmp[index++] = '\"';
	while (envp[index - 1])
	{
		tmp[index] = envp[index - 1];
		index++;
	}
	tmp[index] = '\"';
	return (tmp);
}
/*
char	*fill_with_dquotes(char *envp)
{
	char	**tab;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*result;

	tab = ft_split(envp, '=');
	if (tab[1])
	{
		tmp = ft_strjoin(tab[0], "=");
		tmp2 = ft_strjoin(tmp, "\"");
		tmp3 = ft_strjoin(tmp2, tab[1]);
		result = ft_strjoin(tmp3, "\"");
		free(tmp);
		free(tmp2);
		free(tmp3);
	}
	else
		result = ft_strjoin(envp, "\"\"");
	free_matrix(tab);
	return (result);
}
*/
t_list	*fill_exp_list(char **envp)
{
	t_list	*lst;

	lst = ft_lstnew(fill_with_dquotes(*envp));
	envp++;
	while (*envp)
	{
		ft_lstadd_back(&lst, ft_lstnew(fill_with_dquotes(*envp)));
		envp++;
	}
	return (lst);
}

void    replace_content_exp(t_data *data, char *content, char *name)
{
	t_list	*ptr;
	int		name_len;

	ptr = data->exp_list;
	name_len = get_var_len(name);
	while (data->exp_list)
	{
		if (name_len == get_var_len(data->exp_list->content))
		{
			if (!ft_strncmp(data->exp_list->content, name, name_len))
			{
				free(data->exp_list->content);
				data->exp_list->content = content;
				data->exp_list = ptr;
				return ;
			}
		}
		data->exp_list = data->exp_list->next;
	}
	data->exp_list = ptr;
	ft_lstadd_back(&(data->exp_list), ft_lstnew(content));
	sort_env_list(data->exp_list);
}


void	replace_content_envp(t_data *data, char *content, char *name)
{
	t_list	*ptr;
	int		name_len;

	ptr = data->envp_list;
	name_len = get_var_len(name);
	while (data->envp_list)
	{
		if (name_len == get_var_len(data->envp_list->content))
		{
			if (!ft_strncmp(data->envp_list->content, name, name_len))
			{
				free(data->envp_list->content);
				data->envp_list->content = ft_strdup(content);
				data->envp_list = ptr;
				return ;
			}
		}
		data->envp_list = data->envp_list->next;
	}
	data->envp_list = ptr;
	ft_lstadd_back(&(data->envp_list), ft_lstnew(ft_strdup(content)));
}



