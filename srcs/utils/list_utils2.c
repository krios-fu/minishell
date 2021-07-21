/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:20:31 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/13 20:25:05 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

char	*fill_with_dquotes(char *envp)
{
	char	**tab;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*result;

	tab = ft_split(envp, '=');
	tmp = ft_strjoin(tab[0], "=");
	tmp2 = ft_strjoin(tmp, "\"");
	tmp3 = ft_strjoin(tmp2, tab[1]);
	result = ft_strjoin(tmp3, "\"");
	free(tmp);
	free(tmp2);
	free(tmp3);
	free_matrix(tab);
	return (result);
}

t_list	*fill_exp_list(char **envp)
{
	t_list	*lst;

	lst = ft_lstnew(fill_with_dquotes(*envp));
	envp++;
	while (*envp)
	{
		ft_lstadd_back(&lst, ft_lstnew(fill_with_dquotes(*envp)));
		envp++;
	}
	return (lst);
}

void	replace_content(t_list **lst, char *content, char *name)
{
	t_list	*ptr;
	char	*f_name;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	f_name = ft_strjoin(name, "=");
	while (*lst)
	{
		if (!ft_strncmp((char *)(*lst)->content, f_name, ft_strlen(f_name)))
		{
			free((*lst)->content);
			(*lst)->content = ft_strdup(content);
		}
		*lst = (*lst)->next;
	}
	 free(f_name); // mod kevin
	*lst = ptr;
}
