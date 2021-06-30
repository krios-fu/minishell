/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:19:43 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/26 19:17:06 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dp;
	unsigned const char	*sp;
	size_t				index;

	dp = (unsigned char *)dst;
	sp = (unsigned const char *)src;
	index = 0;
	if (!dst && !src)
		return (0);
	if ((dst || src) && len)
	{
		if (dp > sp)
		{
			while (++index <= len)
				dp[len - index] = sp[len - index];
		}
		else
		{
			while (len--)
				*dp++ = *sp++;
		}
	}
	return (dst);
}
