/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:04:13 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/12 18:29:21 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	free_matrix(char **str)
{
	int i;

	i = 0;
	printf("*%s*\n", *str);
	if(str)
	{
		while(str[i])
			free(str[i++]);
		free(str);
	}
	printf("*%s*\n", *str);
}

void	free_redirect(t_redirect *redirect)
{
	t_redirect *tmp;

	while (redirect)
	{
		free (redirect->file);
		free(redirect->symbol);
		tmp = redirect->next;
		free(redirect);
		redirect = tmp;
	}
}

void	free_resources(t_process *process)
{
	t_process	*tmp;
	
	while (process)
	{
		free(process->argv);
		free_redirect(process->input);
		free_redirect(process->output);
		tmp = process->next;
		free(process);
		process = tmp;
	}
}