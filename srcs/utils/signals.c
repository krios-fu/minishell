/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:20:19 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/28 13:01:16 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"
/*
void	signal_child(int number)
{
	if (number == )
}
*/
void	signal_child(int number)
{
	(void)number;
	if (number == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		signal(SIGQUIT, SIG_DFL);
	}
	if (number == SIGINT)
		printf("\n");
}
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
