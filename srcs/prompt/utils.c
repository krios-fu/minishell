/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:01:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/21 21:42:44 by krios-fu         ###   ########.fr       */
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

int	get_num_words(char **str)
{
	int	i;
	char **tmp;

	tmp = ft_split(str[0], ' ');

	i = 0;
	while (tmp[i])
		i++;
	free(tmp);
	return(i);
}

/* 
char	**ft_matrixjoin(const char **matrix1, const char **matrix2)
{
	int		len;
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len =  get_num_words(matrix1) + get_num_words(matrix2);
	dst = (char **)malloc(sizeof(char*) * len + 1);
	if(!dst)
		return(NULL);
	while (matrix1[i])
	{
		dst[i] = ft_strdup(matrix1[i]);
		if (!dst[i])
		{
			free_matrix(dst);
			return (NULL);
		}
		i++;
	}
	while(matrix2[j])
	{
		dst[i] = ft_strdup(matrix2[j]);
		if (!dst[i])
		{
			free_matrix(dst);
			return (NULL);
		}
		j++;
		i++;
	}
	dst[len] = NULL;
	return (dst);
} */