/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:50:49 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 10:59:35 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	size_t	count;

	len = ft_strlen(s1);
	count = 0;
	while (s2[count])
	{
		s1[len + count] = s2[count];
		count++;
	}
	s1[len + count] = 0;
	return (s1);
}
