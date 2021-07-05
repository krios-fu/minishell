/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:10:56 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/05 16:13:54 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
** Function that recives char **envp as parameter
** and returns a pointer to a linked list filled with envp
*/
t_list	*fill_envp_list(char **envp)
{
	t_list *envp_list;
	envp_list = ft_lstnew(ft_strdup(*envp));
	envp++;
	while (*envp)
	{
		ft_lstadd_back(&envp_list, ft_lstnew(ft_strdup(*envp)));
		envp++;
	}
	return (envp_list);
}
