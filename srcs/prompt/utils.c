/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:01:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/26 15:38:46 by krios-fu         ###   ########.fr       */
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
	static int b;
	char **tmp;

	i = 0;
	b = 0;
	if (!str[0])
		return (0);
	if (ft_strchr(str[0], '='))
		return (1);
	tmp = ft_split(str[0], ' ');

	while (tmp[i])
		i++;
	free_matrix(tmp);
	return(i);
}

int get_num_words_join(char **argv)
{
	int i;
	int len;
	i = 0;

	len = 0;
	while (argv[i])
	{
		len += get_num_words(&argv[i]);
		i++;
	}
	return (len);
}

char	**final_token(char **argv)
{
	t_var	var;
	int		k;
	char	**tmp;
	char	**aux;

	var.i = 0;
	var.j = 0;
	k = 0;
	if (!argv)
	{
		tmp = malloc(sizeof(char *) * 2);
		tmp[0] = ft_strdup("");
		tmp[1] = NULL;
		return(tmp);
	}
	var.len_exp = get_num_words_join(argv);
	tmp = (char **)malloc(sizeof(char *) * (var.len_exp + 1));
	while (argv[var.i])
	{
		if (!ft_strchr(argv[var.i], '='))
		{
			aux = ft_split(argv[var.i], ' ');
			while (aux[var.j])
				tmp[k++] = ft_strdup(aux[(var.j)++]);
			free_matrix(aux);
			var.j = 0;
		}
		else
			tmp[k++] = ft_strdup(argv[var.i]);
		(var.i)++;
	}
	tmp[var.len_exp] = NULL;
	return(tmp);
}