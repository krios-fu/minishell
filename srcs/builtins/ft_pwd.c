/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:30:01 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 20:32:20 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	ft_pwd(t_data *data)
{
	char	path[1024];

	if (!getcwd(path, sizeof(path)))
	{
		data->lst_process->code_error = 1;
		return ;
	}
	printf("%s\n", path);
}
