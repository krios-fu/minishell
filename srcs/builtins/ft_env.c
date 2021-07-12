/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:14:55 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/12 17:14:36 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_env(t_data *data)
{
	if (!data->envp_list)
		return (1);
	printf("AAA\n");
	while (data->envp_list->next)
	{
		printf("%s\n", data->envp_list->content);
		data->envp_list = data->envp_list->next;
	}
	printf("%s\n", data->envp_list->content);
	return (0);
}
