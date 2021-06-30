/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:29:57 by jacgarci          #+#    #+#             */
/*   Updated: 2019/11/17 19:39:03 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned, char *))
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
			(*f)(count, &s[count]);
			count++;
		}
	}
}
