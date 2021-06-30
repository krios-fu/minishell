/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:37:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 10:56:41 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;

	len = ft_strlen(s1);
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (0);
	ft_memcpy(copy, s1, len);
	copy[len] = 0;
	return (copy);
}
