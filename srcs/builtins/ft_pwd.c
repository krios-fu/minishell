/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:30:01 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/06 12:21:49 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_pwd(void)
{
	char	path[1024];

	if (!getcwd(path, sizeof(path)))
		return (1);
	printf("%s\n", path);
	return (0);
}
