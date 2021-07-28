/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:01:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 16:30:36 by krios-fu         ###   ########.fr       */
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

void	change_status_quote(char *line, t_parseo *parse)
{
	if (line[parse->i] == '\"' && parse->quotes_s == false)
	{
		if (parse->quotes_d == true)
			parse->quotes_d = false;
		else
			parse->quotes_d = true;
	}
	if (line[parse->i] == '\'' && parse->quotes_d == false)
	{
		if (parse->quotes_s == true)
			parse->quotes_s = false;
		else
			parse->quotes_s = true;
	}
}

void	ft_addlst_back_redirect(t_redirect *redirect, t_redirect *new_redirect)
{
	t_redirect	*tmp_redir;

	tmp_redir = redirect;
	while (tmp_redir->next)
		tmp_redir = tmp_redir->next;
	tmp_redir->next = new_redirect;
}

void	ft_addlst_back_process(t_process *process, t_process *new_process)
{
	t_process	*tmp_process;

	tmp_process = process;
	while (tmp_process->next)
		tmp_process = tmp_process->next;
	tmp_process->next = new_process;
}
