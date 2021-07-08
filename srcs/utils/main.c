/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:39 by jacgarci          #+#    #+#             */
/*   Updated: 2021/07/08 01:53:49 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


//main para probar que funciona la funcion fill_envp_list. La funcion se encuentra en srcs/utils
int	main(void)
{
	t_process *process ;

	process = (t_process*)malloc(sizeof(t_process));
	process->input = NULL;
	process->output = NULL;
	size_t num = num_arg_process(">cat > init > j init end > z <p <s <<d << q\0", process);
	printf("%zu\n", num);

	while(process->output)
	{
		printf("file output is : %s\n", process->output->file);
		process->output = process->output->next;
	}
		while(process->input)
	{
		printf("file intput is : %s\n", process->input->file);
		process->input = process->input->next;
	}
	
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
