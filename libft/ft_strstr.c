/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:16:35 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:07:18 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	hcount;
	size_t	nlen;

	hcount = 0;
	nlen = ft_strlen(needle);
	if (!ft_strncmp(needle, "", 1))
		return ((char *)haystack);
	while (haystack[hcount])
	{
		if (!ft_strncmp(&haystack[hcount], needle, nlen))
			return ((char *)&haystack[hcount]);
		hcount++;
	}
	return (0);
}
