/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:20:19 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/29 02:16:06 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	signal_child2(int number)
{
	if (number == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 1);
		signal(SIGQUIT, SIG_DFL);
	}
	if (number == SIGINT)
		printf("\n");
}

void	signal_child(int number)
{
	if (number == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 1);
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

void	signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
