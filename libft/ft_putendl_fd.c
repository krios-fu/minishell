/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:00:56 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/26 19:19:01 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*sp;

	sp = s;
	if (s != (void *)0)
	{
		while (*sp)
		{
			ft_putchar_fd(*sp, fd);
			sp++;
		}
		ft_putchar_fd('\n', fd);
	}
}
