/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:45:43 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 11:13:05 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	const char		*sp;
	unsigned int	cont;

	sp = s;
	cont = 0;
	if (s == (void *)0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	while (sp[start] && len--)
		substr[cont++] = sp[start++];
	substr[cont] = 0;
	return (substr);
}
