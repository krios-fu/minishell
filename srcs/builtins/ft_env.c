/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:14:55 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/05 18:22:20 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_env(t_list *envp_list)
{
	if (!envp_list)
		return (1);
	while (envp_list->next)
	{
		printf("%s\n", envp_list->content);
		envp_list = envp_list->next;
	}
	printf("%s\n", envp_list->content);
	return (0);
}
