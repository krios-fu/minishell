/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:10:56 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/30 18:45:01 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

t_envp	*ft_lstnew(void *content)
{
	t_envp	*new_list;

	if (!(new_list = malloc(sizeof(new_list))))
		return (0);
	new_list->content = content;
	new_list->next = 0;
	return (new_list);
}

void	ft_lstadd_front(t_envp **alst, t_envp *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

t_envp	*ft_lstlast(t_envp *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_envp **alst, t_envp *new)
{
	if (!(alst || !new))
		return ;
	if (!*alst)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}

//function that recives char **envp as parameter and returns a pointer to a linked list filled with envp
t_envp	*fill_envp_list(char **envp)
{
	t_envp *envp_list;
	envp_list = ft_lstnew(*envp);
	envp++;
	while (*envp)
	{
		ft_lstadd_back(&envp_list, ft_lstnew(*envp));
		envp++;
	}
	return (envp_list);
}
