/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:44:08 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 19:41:40 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hcount;
	size_t	nlen;

	hcount = 0;
	nlen = ft_strlen(needle);
	if (!nlen)
		return ((char *)haystack);
	if (!len)
		return (0);
	while ((haystack[hcount] && len))
	{
		if (!(ft_strncmp(&haystack[hcount], needle, nlen)))
			return ((char *)&haystack[hcount]);
		if (nlen > len)
			return (0);
		hcount++;
		len--;
	}
	return (0);
}
