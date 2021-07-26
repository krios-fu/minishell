/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:09:24 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/26 18:53:14 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libminishell.h"

void	not_valid_identifier(char *builtin, char *arg)
{
	if (!ft_strcmp(builtin, "export"))
		ft_putstr_fd("rocketMen: export: `", 2);
	else if (!ft_strcmp(builtin, "unset"))
		ft_putstr_fd("rocketMen: unset: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int	check_arg_name(char *arg)
{
	if (ft_isalpha(arg[0]) || arg[0] == '_')
		return (1);
	return (0);
}

char	*get_name(char *var)
{
	char	*name;
	int		index;

	if (!ft_strchr(var, '='))
		return (ft_strdup(var));
	index = 0;
	while (var[index] != '=')
		index++;
	name = ft_strndup(var, index + 1);
	return (name);
}

int	already_exist(t_list *lst, char *var)
{
	char	*tmp;
	char	*name;

	name = get_name(var);
	tmp = search_env(lst, name);
	if (!tmp[0])
	{
		free(name);
		free(tmp);
		return (0);
	}
	free(name);
	free(tmp);
	return (1);
}
