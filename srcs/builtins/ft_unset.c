/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:23:51 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/05 18:45:42 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
** Function that recives a list and a name 
** and returns the list content that have the name
*/

char	*search_env(t_list *envp_list, char *name)
{
	while (envp_list)
	{
		if (!ft_strncmp(envp_list->content, name, ft_strlen(name)))
			return (envp_list->content);
		envp_list = envp_list->next;
	}
	return (0);
}

int	ft_unset(t_list **envp_list, char *name)
{
	char	*content;

	content = search_env(*envp_list, name);
	if (content)
		ft_lstdelone(envp_list, (void *)content);
	return (0);
}
