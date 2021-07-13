/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:20:31 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 18:07:04 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	replace_content(t_list **lst, char *content, char *name)
{
	t_list	*ptr;
	char	*f_name;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	f_name = ft_strjoin(name, "=");
	while (*lst)
	{
		if (!ft_strncmp((char *)(*lst)->content, f_name, ft_strlen(f_name)))
		{
			free((*lst)->content);
			(*lst)->content = ft_strdup(content);
		}
		*lst = (*lst)->next;
	}
	*lst = ptr;
}
