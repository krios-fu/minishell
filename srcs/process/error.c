/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:37:52 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/15 22:39:40 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	print_error_cmd(char *cmd)
{
		ft_putstr_fd("rocket-man: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
}