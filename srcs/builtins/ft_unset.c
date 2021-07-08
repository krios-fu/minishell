/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:23:51 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/08 16:19:56 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	ft_unset(t_list **envp_list, char *name)
{
	char	*content;

	content = search_env(*envp_list, name);
	if (content)
		ft_lstdelone(envp_list, (void *)content);
	return (0);
}
