/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:57:40 by jacgarci          #+#    #+#             */
/*   Updated: 2019/11/12 19:14:21 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	count;

	len = ft_strlen(s1);
	count = 0;
	while ((count < n) && s2[count])
	{
		s1[len + count] = s2[count];
		count++;
	}
	s1[len + count] = 0;
	return (s1);
}
