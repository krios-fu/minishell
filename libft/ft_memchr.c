/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:22:12 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/26 19:16:30 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	find;

	string = (unsigned char *)s;
	find = (unsigned char)c;
	while (n--)
	{
		if (*string++ == find)
		{
			return ((void *)--string);
		}
	}
	return (0);
}
