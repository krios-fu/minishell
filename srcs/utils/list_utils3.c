/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:04:27 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/24 16:38:54 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	get_list_length(t_list *lst)
{
	int	length;

	length = 0;
	while (lst)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}

char	**get_env(t_data *data)
{
	char	**envp;
	t_list	*lst;
	int		index;

	envp = malloc(sizeof(char *) * (get_list_length(data->envp_list) + 1));
	if (!envp)
		return (0);
	lst = data->envp_list;
	index = 0;
	while (lst)
	{
		envp[index] = ft_strdup(lst->content);
		lst = lst->next;
		index++;
	}
	envp[index] = 0;
	return (envp);
}
