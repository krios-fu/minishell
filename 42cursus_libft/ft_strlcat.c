/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:52:44 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:02:23 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dlen;

	if (!dstsize)
		return (ft_strlen(src));
	index = 0;
	dlen = ft_strlen(dst);
	if (dstsize > dlen)
	{
		while (src[index] && (dlen + index < dstsize - 1))
		{
			dst[dlen + index] = src[index];
			index++;
		}
		dst[dlen + index] = 0;
		return (dlen + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
