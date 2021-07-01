/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/01 13:44:04 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;



	t_shell shell;
	t_shell tmp;

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
	tmp = shell;
	while (tmp.envp_list->next)
	{
		printf("%s\n", tmp.envp_list->content);
		tmp.envp_list = tmp.envp_list->next;
	}
	printf("%s\n", tmp.envp_list->content);
	ft_lstdelone(&shell.envp_list, *envp);
	printf("\n");
	while (shell.envp_list->next)
	{
		printf("%s\n", shell.envp_list->content);
		shell.envp_list = shell.envp_list->next;
	}
	printf("%s\n", shell.envp_list->content);
	//printf("%s\n", *envp);
	//printf("%s=%s\n", envp_list->line[0], envp_list->line[1]);
}
