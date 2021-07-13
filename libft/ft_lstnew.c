/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:07:45 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 23:14:24 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*nl;

	// nl = malloc(sizeof(nl)); before 
	nl = (t_list *)malloc(sizeof(t_list)); // mod kevin
	if (!nl)
		return (0);
	nl->content = (void *)content;
	nl->next = 0;
	return (nl);
}
