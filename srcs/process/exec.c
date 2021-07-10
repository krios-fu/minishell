/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:01:01 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/10 20:26:24 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	*menu_builtins (void)
{
	int (**menu)(void);

	menu = malloc(sizeof(menu) + 2);
	// menu[0] = &ft_cd;
	// menu[1] = &ft_echo;
	// menu[2] = &ft_env;
	// menu[3] = &ft_export;
	menu[0] = &ft_pwd;
	// menu[5] = &ft_unset;
	menu[1] = (void *)0;
	return (menu);
}

int	search_builtins(char *bcmd)
{
	if (ft_strnstr("cd\0", bcmd,  ft_strlen(bcmd)))
		return (0);
	if (ft_strnstr("echo\0", bcmd,  ft_strlen(bcmd)))
		return (1);
	if (ft_strnstr( "env\0", bcmd,  ft_strlen(bcmd)))
		return (2);	
	if (ft_strnstr("export\0", bcmd,  ft_strlen(bcmd)))
		return (3);
	if (ft_strnstr("pwd\0", bcmd,  ft_strlen(bcmd)))
		return (0);
	if (ft_strnstr("unset\0", bcmd,  ft_strlen(bcmd)))
		return (5);

	return (-1);
}

/*
**	to do: mod parameters input for data 
**
*/

int	start_process(char **cmd)
{
	int (**menu)(void);

	int opc = 0;
	int i;
	i = 0;
	
	 menu = menu_builtins();
	 opc = search_builtins(cmd[0]);
	if (opc >= 0)
		(*menu[opc])();
	free(menu);
	return(0);
}