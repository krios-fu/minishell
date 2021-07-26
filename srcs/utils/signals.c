/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:50:41 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/26 17:02:00 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"
/*
void	signal_child(int number)
{
	if (number == )
}
*/
void	signal_handler(int number)
{
	if (number == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals()
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
