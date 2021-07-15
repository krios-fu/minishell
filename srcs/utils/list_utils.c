/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:10:56 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/14 10:59:59 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
** Function that recives a list and a name
** and returns the list content that have the name
*/
char	*search_env(t_list *envp_list, char *name)
{
	char	*f_name;
	t_list	*lst;

	f_name = ft_strjoin(name, "=");
	lst = envp_list;
	while (lst)
	{
		if (!ft_strncmp(lst->content, f_name, ft_strlen(f_name)))
		{
			free(f_name);
			return (ft_strdup(lst->content));
		}
		lst = lst->next;
	}
	free(f_name);
	return (ft_strdup(""));
}

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
	t_list aux;

	// // aux = malloc(sizeof(t_list)); mod kevin le
	// if (!aux)
		// return ;
	aux.content = b->content;
	b->content = a->content;
	a->content = aux.content;
}

/*
** Function that given a pointer to the first
** element of a list returns a pointer to the 
** original list sorted
*/

int		check_lst_order(t_list **lst)
{
	int		i;
	i = 0;
	while (lst)
	{
		if (ft_strcmp((char *)(*lst)->content, (char *)(*lst)->next->content) > 0)
			i++;
		*lst = (*lst)->next;
	}
	if(i == ft_lstsize(*lst))
		return (1);
	else
		return (0);
}

void 	sort_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while(!check_lst_order(lst))
	{
		while (tmp->next)
		{
			if (ft_strcmp((char *)tmp->content, (char *)tmp->next->content) > 0)
				swap(tmp, tmp->next);
			tmp = tmp->next;
		}
		tmp = *lst;
	}

}


t_list	*sort_env_list(t_list *lst)
{
	t_list	*pt;
	t_list	*lptr;
	int		swapped;

	lptr = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		pt = lst;
		while (pt->next != lptr)
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
	return (lst);
}

/*
** Function that recives char **envp as parameter
** and returns a pointer to a linked list filled with envp
*/
t_list	* fill_envp_list(char **envp)
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
