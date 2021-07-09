/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:01:01 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/09 23:29:56 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	*menu_builtins (void)
{
	void  **menu;

	menu = (void **)malloc(sizeof(void *) + 7);
	menu[0] = &ft_cd;
	menu[1] = &ft_echo;
	menu[2] = &ft_env;
	menu[3] = &ft_export;
	menu[4] = &ft_pwd;
	menu[5] = &ft_unset;
	menu[6] = (void *)0;
	return (menu);
}

int	search_builtins(t_process *process)
{
	if (ft_strnstr("cd\0", process->argv[0],  ft_strlen(process->argv[0])))
		return (0);
	if (ft_strnstr("echo\0", process->argv[0],  ft_strlen(process->argv[0])))
		return (1);
	if (ft_strnstr( "env\0", process->argv[0], ft_strlen(process->argv[0])))
		return (2);	
	if (ft_strnstr("export\0", process->argv[0], ft_strlen(process->argv[0])))
		return (3);
	if (ft_strnstr("pwd\0", process->argv[0],  ft_strlen(process->argv[0])))
		return (4);
	if (ft_strnstr("unset\0", process->argv[0],  ft_strlen(process->argv[0])))
		return (5);
	return (-1);
}

/*
**	to do: mod parameters input for data 
**
*/

int	start_process(t_process *process)
{
	void (**menu)(void);
	int opc;
	int i;

	i = 0;
	menu = menu_builtins();
	opc = search_builtins(process);
	if (opc >= 0)
		menu[opc]();
	free(menu);
	return(opc);
}