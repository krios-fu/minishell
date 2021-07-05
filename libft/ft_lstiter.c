/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:22:58 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/26 19:11:30 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	size;

	if (!lst || !f)
		return ;
	size = ft_lstsize(lst);
	if (size)
	{
		while (size--)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
