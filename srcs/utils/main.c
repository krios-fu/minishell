/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/09 00:18:20 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(void)
{
	t_process **process ;
	int i;

	i = 0;
	char str[] = "cat init \'\"|\' < a | wc | grpe \"1\"";

	process =  get_process(str);

	while(process[0]->argv[i])
	{
		printf("arg [%d] [%s]\n", i, process[2]->argv[i]);
		i++;
	}
	/*
	int  i = 0;
	char str[] = "cat init \'\"|\' < a | wc\0";

	process = (t_process*)malloc(sizeof(t_process));
	process->input = NULL;
	process->output = NULL;
	printf("a\n");
	 printf("num pipe [[%d]]\n", get_num_pipe(str));
	process->argv = get_words(process, str);

	while(process->argv[i])
	{
		printf("arg [%d] [%s]\n", i, process->argv[i]);
		i++;
	}

	printf("fuera\n");
	// size_t num = num_arg_process("<j \"\'\"<z\000", process);

	while(process->output)
	{
		printf("file output is : %s\n", process->output->file);
		process->output = process->output->next;
	}
		while(process->input)
	{
		printf("file intput is : %s\n", process->input->file);
		process->input = process->input->next;
	}*/
	
	/*
	t_process *process;
	t_redirect *redirect;

	process = (t_process *)malloc(sizeof(t_process));

	
	 redirect =  get_redirect("< mundo");
	if (redirect->symbol[0] == '<')
	{
		process->input = redirect;
		printf("[%s]  [%s]\n", process->input->symbol, process->input->file);
	}
	if (redirect->symbol[0] == '>')
	{
		process->output = redirect;
		printf("[%s] [%s]\n", process->output->symbol, process->output->file);
	}
*/
	
	// t_redirect	*redirect;
	// redirect = (t_redirect *)malloc(sizeof(t_redirect));
	
	// part_one_redirect(redirect, "< init cat");

	// printf("[%s], [%s], [%s]", redirect->symbol, redirect->input, redirect->output);
	return (0);
}
