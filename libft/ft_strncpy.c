/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:45:06 by jacgarci          #+#    #+#             */
/*   Updated: 2019/11/14 19:27:49 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	c;

	c = 0;
	while (c < len)
	{
		if (src[c])
		{
			dst[c] = src[c];
			c++;
		}
		else
		{
			while (c < len)
			{
				dst[c] = '\0';
				c++;
			}
			return (dst);
		}
	}
	return (dst);
}
