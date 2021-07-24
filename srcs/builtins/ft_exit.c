/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:09:12 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/25 01:21:11 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_exit(t_data *data)
{
	char *logname;

	logname = search_env(data->envp_list, "LOGNAME");
	printf(CYAN"roc"BLUE"ket"GREEN"Men 👋 "RED"%s\n"WHITE, logname);
	exit(0);
}