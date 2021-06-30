/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:45:25 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:00:01 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	char	*sp;
	char	*dp;

	sp = (char *)src;
	dp = (char *)dst;
	cont = 0;
	if (src == (void *)0)
		return (0);
	if (dstsize)
	{
		while (cont < dstsize - 1 && sp[cont])
		{
			dp[cont] = sp[cont];
			cont++;
		}
		dst[cont] = 0;
	}
	return ((ft_strlen(src)));
}
