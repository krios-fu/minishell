/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:01:01 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/31 21:46:46 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	*menu_builtins (void)
{
	void	(**menu)(t_data *);

	menu = malloc(sizeof(*menu) * 9);
	menu[0] = &ft_cd;
	menu[1] = &ft_echo;
	menu[2] = &ft_env;
	menu[3] = &ft_export;
	menu[4] = &ft_pwd;
	menu[5] = &ft_unset;
	menu[6] = &ft_exit;
	menu[8] = (void *)0;
	return (menu);
}

int	search_builtins(t_shell *shell)
{
	char *bcmd;

	bcmd = (char *)shell->data->lst_process->argv[0];
	if (!bcmd)
		return (-1);
	if (!ft_strcmp("cd\0", bcmd))
		return (0);
	if (!ft_strcmp("echo\0", bcmd))
		return (1);
	if (!ft_strcmp("env\0", bcmd))
		return (2);
	if (!ft_strcmp("export\0", bcmd))
		return (3);
	if (!ft_strcmp("pwd\0", bcmd))
		return (4);
	if (!ft_strcmp("unset\0", bcmd))
		return (5);
	if (!ft_strcmp("exit\0", bcmd))
		return (6);
	if(ft_isalpha(bcmd[0]) && ft_strchr(bcmd, '='))
	{
		shell->data->lst_process->argv = ft_lst_undefine(shell->data);
		if (shell->data->lst_process->argv)
			search_builtins(shell);
		else
			return (-1);
	}
	return (-1);
}

int	start_process(t_shell *shell)
{
	void	(**menu)(t_data *);
	int		opc;
	int		i;

	i = 0;
	opc = 0;
	menu = menu_builtins();
	opc = search_builtins(shell);
	if (opc >= 0)
		(*menu[opc])(shell->data);
	 free(menu);
	return (opc);
}
