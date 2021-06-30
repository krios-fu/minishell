/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:00:47 by jacgarci          #+#    #+#             */
/*   Updated: 2019/11/17 20:24:14 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	len;
	size_t	count;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	count = 0;
	if (f && s)
	{
		while (count < len)
		{
			(*f)(&s[count]);
			count++;
		}
	}
}
