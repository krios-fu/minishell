/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:48:05 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/27 10:54:49 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *)s;
	while (*pointer != 0)
	{
		if (*pointer == c)
			return (pointer);
		pointer++;
	}
	if (c == 0)
		return (pointer);
	return (0);
}
