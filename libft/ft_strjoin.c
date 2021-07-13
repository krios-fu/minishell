/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:11:14 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/14 00:09:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		cont;
	int		len;

	cont = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (0);
	while (cont < (int)ft_strlen(s1))
	{
		dst[cont] = s1[cont];
		cont++;
	}
	while (cont < len)
	{
		dst[cont] = s2[cont - ft_strlen(s1)];
		cont++;
	}
	dst[len] = 0;
	return (dst);
}
