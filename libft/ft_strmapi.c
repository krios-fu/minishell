/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:49:48 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:04:02 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	cont;

	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	cont = 0;
	while (cont < ft_strlen(s))
	{
		str[cont] = (*f)(cont, str[cont]);
		cont++;
	}
	str[cont] = 0;
	return (str);
}
