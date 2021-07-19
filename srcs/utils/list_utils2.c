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

t_list	*fill_exp_list(char **envp)
{
	t_list	*lst;
	char	*tmp;
	char	*tmp2;
	int	index;

	index = 0;
	while (envp[index])
	{
		tmp = ft_strjoin("\"", envp[index]);
		tmp2 = ft_strjoin(tmp, "\"");
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(tmp2)));
		free(tmp);
		free(tmp2);
		index++;
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
