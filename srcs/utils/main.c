/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/06/30 13:38:02 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	t_shell shell;

/*
	envp_list = ft_lstnew(ft_split(*envp, '='));
	envp++;
	while (*envp)
	{
		ft_lstadd_back(&envp_list, ft_lstnew(ft_split(*envp, '=')));
		envp++;
	}
*/
	shell.envp_list = fill_envp_list(envp);
	while (shell.envp_list->next)
	{
		printf("%s=%s\n", shell.envp_list->line[0], shell.envp_list->line[1]);
		shell.envp_list = shell.envp_list->next;
	}
	printf("%s=%s\n", shell.envp_list->line[0], shell.envp_list->line[1]);
	//printf("%s\n", *envp);
	//printf("%s=%s\n", envp_list->line[0], envp_list->line[1]);
}
