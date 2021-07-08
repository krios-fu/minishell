/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:40:34 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/08 11:28:22 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

static int	print_export_list(t_list *lst)
{
	while (lst)
	{
		printf("%s%s\n", "declare -x ", lst->content);
		lst = lst->next;
	}
	return (0);
}

int	ft_export(t_list **env_list, t_list **exp_list, char **var)
{
	if (!var)
		return (print_export_list(*exp_list));
	while (*var)
	{
		if (ft_strchr(*var, '='))
			ft_lstadd_back(env_list, ft_lstnew(*var));
		ft_lstadd_front(exp_list, ft_lstnew(*var));
		var++;
	}
	sort_env_list(exp_list);
	return (0);
}
