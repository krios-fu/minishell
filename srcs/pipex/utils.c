/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:39:38 by krios-fu          #+#    #+#             */
/*   Updated: 2021/08/02 14:16:49 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	redirect_io(t_shell *shell)
{
	redirect_input_exec(shell);
	redirect_output_exec(shell);
}

int	get_fd_builtins(t_shell *shell)
{
	int	fd_out;

	fd_out = fd_output_redirect(shell);
	if (fd_out < 0 && fd_out != -2)
		fd_out = STDOUT_FILENO;
	return (fd_out);
}
