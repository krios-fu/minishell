/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/09 13:26:06 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
//	(void)envp;

//	argv++;
//	ft_echo(argv);

	t_shell shell;

	shell.envp_list = fill_envp_list(envp);
	shell.exp_list = fill_envp_list(envp);
	shell.exp_list = sort_env_list(&shell.exp_list);


//	ft_env(shell.exp_list);
//	ft_export(&shell.envp_list, &shell.exp_list, argv);
//	print_list(shell.exp_list);
//	print_list(shell.envp_list);
//*/
	//printf("%s\n", getcwd(0, 1024));
	print_list(shell.exp_list);
	ft_cd(&shell.envp_list, &shell.exp_list, "utils");
	printf("\n");
	print_list(shell.exp_list);
	system("leaks minishell");
//	printf("%s\n", getcwd(0, 1024));
//	ft_cd(&shell.envp_list, &shell.exp_list, "includes");
//	printf("%s\n", getcwd(0, 1024));
}
