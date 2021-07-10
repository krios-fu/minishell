/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:01:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/10 19:32:44 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

char	*ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (&str[i]);
}

void ft_addlst_back_redirect(t_redirect *redirect, t_redirect *new_redirect)
{
	t_redirect	*tmp_redir;

	tmp_redir = redirect;
	while(tmp_redir->next)
		tmp_redir = tmp_redir->next;
	tmp_redir->next = new_redirect;
	
}

void ft_addlst_back_process(t_process *process, t_process *new_process)
{
	t_process	*tmp_process;

	tmp_process = process;
	while(tmp_process->next)
		tmp_process = tmp_process->next;
	tmp_process->next = new_process;	
}