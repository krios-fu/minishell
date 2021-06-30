/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:24:32 by jacgarci          #+#    #+#             */
/*   Updated: 2019/11/11 12:08:14 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	result;

	sign = 1;
	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		result = result * 10 + *str - '0';
		str++;
		if (result > 9223372036854775807)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
	}
	return (sign * result);
}
