/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:10:56 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/25 18:55:17 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

/*
** Function that recives a list and a name
** and returns the list content that have the name
*/
/*
char	*search_exp(t_list *lst, char *name)
{
	t_list	*ptr;
	char	*tmp;

	tmp = 0;
	ptr = lst;
	if (ft_strchr(name, '='))
		return (search_env(lst, name));
	else
	{
		while (ptr)
		{
			if (!ft_strncmp(ptr->content, name, ft_strlen(name)))
				return (ft_strdup(ptr->content));
			ptr = ptr->next;
		}
	}
	return (ft_strdup(""));
}
*/

int		get_var_len(char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '=')
		count++;
	return (count);
}

char	*search_env(t_list *envp_list, char *name)
{
	t_list	*lst;
	int		name_len;

	lst = envp_list;
	name_len = get_var_len(name);
	while (lst)
	{
		if (name_len == get_var_len(lst->content))
		{
			if (!ft_strncmp(lst->content, name, name_len))
				return (ft_strdup(lst->content));
		}
		lst = lst->next;
	}
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



void	sort_env_list(t_list *lst)
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
}

/*
** Function that recives char **envp as parameter
** and returns a pointer to a linked list filled with envp
*/
t_list	*fill_envp_list(char **envp)
{
	int	index;
	t_list *envp_list;

	index = 0;
	envp_list = ft_lstnew(ft_strdup(envp[index]));
	index++;
	while (envp[index])
	{
		ft_lstadd_back(&envp_list, ft_lstnew(ft_strdup(envp[index])));
		index++;
	}
	return (envp_list);
}
