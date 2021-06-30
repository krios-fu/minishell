/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:17:42 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:04:07 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	len;
	size_t	count;
	char	*str;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	count = 0;
	if (s && f)
	{
		while (count < len)
		{
			str[count] = (*f)(s[count]);
			count++;
		}
		str[count] = 0;
	}
	return (str);
}
