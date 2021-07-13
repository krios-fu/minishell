/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:14:55 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 16:29:42 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_env(t_data *data)
{
	t_list *lst;

	if (!data->envp_list)
		return (1);
	lst = data->envp_list;
	while (lst->next)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("%s\n", lst->content);
	return (0);
}
