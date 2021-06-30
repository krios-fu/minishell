/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:50:36 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/26 19:13:59 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numofintdigits(int n)
{
	unsigned int	count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_potency(int n)
{
	int	result;

	result = 1;
	while (n)
	{
		result *= 10;
		n--;
	}
	return (result);
}

static void	ft_fill_str(char *str, int c, long int nb, unsigned int d)
{
	while (d)
	{
		str[c] = (nb / ft_potency(d - 1)) + '0';
		nb = nb - ((nb / ft_potency(d - 1)) * ft_potency(d - 1));
		c++;
		d--;
	}
	str[c] = 0;
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	digits;
	int				cont;
	long int		nb;

	cont = 0;
	nb = n;
	digits = ft_numofintdigits(n);
	if (nb < 0)
	{
		str = malloc(digits + 2);
		if (!str)
			return (0);
		str[0] = '-';
		nb = -nb;
		cont++;
	}
	else
	{
		str = malloc(digits + 1);
		if (!str)
			return (0);
	}
	ft_fill_str(str, cont, nb, digits);
	return (str);
}
