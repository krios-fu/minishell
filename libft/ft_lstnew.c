/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:07:45 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/12 17:58:37 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*nl;

	nl = malloc(sizeof(nl));
	if (!nl)
		return (0);
	nl->content = (void *)content;
	nl->next = 0;
	return (nl);
}
