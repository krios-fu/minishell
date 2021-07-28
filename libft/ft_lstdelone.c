/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:11:47 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/28 20:06:49 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void *content)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *lst;
	prev = *lst;
	if (tmp && (!ft_strcmp((char *)tmp->content, (char *)content)))
	{
		*lst = tmp->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	while (tmp && ft_strcmp((char *)tmp->content, (char *)content))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	prev->next = tmp->next;
	free(tmp->content);
	free(tmp);
}
