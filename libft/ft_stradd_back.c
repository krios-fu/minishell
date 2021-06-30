/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:45:05 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:00:39 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_back(char *s1, char *s2)
{
	char	*cpy;

	cpy = ft_strdup(s1);
	if (!cpy)
		return (0);
	free(s1);
	s1 = malloc(ft_strlen(cpy) + ft_strlen(s2) + 1);
	if (!s1)
	{
		free(cpy);
		return (0);
	}
	ft_strcpy(s1, cpy);
	ft_strcpy(s1 + ft_strlen(s1), s2);
	free(cpy);
	return (s1);
}
