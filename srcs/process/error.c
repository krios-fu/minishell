/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:37:52 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 21:59:15 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	print_error_cmd(char *cmd)
{
	ft_putstr_fd("rocket-men: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
}

void	print_error_file(char *file)
{
	ft_putstr_fd("rocket-men: No such file or directory: ", 2);
	ft_putendl_fd(file, 2);
}
