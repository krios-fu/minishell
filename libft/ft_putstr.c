/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:03:04 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/26 19:19:17 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	int	cont;

	if (s != (void *)0)
	{
		cont = 0;
		while (s[cont])
		{
			ft_putchar(s[cont++]);
		}
	}
}
