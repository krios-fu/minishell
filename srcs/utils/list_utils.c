/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:10:56 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/07 17:40:46 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
** Function that recieves the first element of 
** a list and prints the entire list
*/
void	print_list(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			printf("%s\n", (char *)lst->content);
			lst = lst->next;
		}
	}
}

/*
** Function to swap two elements of list.
** Used on sort_env_list
*/
static void	swap(t_list *a, t_list *b)
{
	t_list *aux;

	aux = malloc(sizeof(t_list));
	if (!aux)
		return ;
	aux->content = b->content;
	b->content = a->content;
	a->content = aux->content;
}

/*
** Function that given a pointer to the first
** element of a list returns a pointer to the 
** original list sorted
*/
t_list	*sort_env_list(t_list **lst)
{
	t_list	*pt;
	t_list	*lptr;
	int		swapped;

	lptr = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		pt = *lst;
		while (pt->next)
		{
			if (ft_strcmp((char *)pt->content, (char *)pt->next->content) > 0)
			{
				swap(pt, pt->next);
				swapped = 1;
			}
			pt = pt->next;
		}
		lptr = pt;
	}
	return (*lst);
}

/*
** Function that recives char **envp as parameter
** and returns a pointer to a linked list filled with envp
*/
t_list	*fill_envp_list(char **envp)
{
	t_list *envp_list;
	envp_list = ft_lstnew(ft_strdup(*envp));
	envp++;
	while (*envp)
	{
		ft_lstadd_back(&envp_list, ft_lstnew(ft_strdup(*envp)));
		envp++;
	}
	return (envp_list);
}
