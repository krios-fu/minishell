/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:09:12 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/24 16:08:53 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_exit (t_data *data)
{
	(void)data;
	write(1, CYAN"roc"BLUE"ket"GREEN"Men 👋 "RED"exit\n", 49);
	exit(0);
}