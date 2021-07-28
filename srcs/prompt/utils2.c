/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:28:41 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 16:30:49 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

int	get_num_words(char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!str[0])
		return (0);
	if (ft_strchr(str[0], '='))
		return (1);
	tmp = ft_split(str[0], ' ');
	while (tmp[i])
		i++;
	free_matrix(tmp);
	return (i);
}

int	get_num_words_join(char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (argv[i])
	{
		len += get_num_words(&argv[i]);
		i++;
	}
	return (len);
}
