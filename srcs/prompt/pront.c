/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pront.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:25:08 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/03 23:56:15 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	print_header(void)
{
	printf(GREEN"_______ ___ ___(_)_______ ___(_)___________  /_ _____ ___  /___  /\n");
	printf(GREEN"__  __ `__ \\__  / __  __ \\__  / __  ___/__  __ \\_  _ \\__  / __  /\n");
	printf(GREEN"_  / / / / /_  /  _  / / /_  /  _(__  ) _  / / //  __/_  /  _  /\n"); 
	printf(GREEN"/_/ /_/ /_/ /_/   /_/ /_/ /_/   /____/  /_/ /_/ \\___/ /_/   /_/\n");
	printf(RED"\t\t\t\t\tBy: Jacgarci && Krios-fu\n");
}

char	*prompt(void)
{
	char	*line;
	line = readline(BLUE"Rocket-men 🚀"WHITE);
	return (line);
}

/*
**
**	this function returns a pointer
**	to the structure with the analyzed data argv (parseo)
**	see struct libminishell.h
*/

void	init_parseo(t_data **data, char *argv)
{
	char	**line;
	char	**cmd_arg;
	int		i;

	i = 0;
	line = ft_split(argv, '|');
	while (argv[i])
	{
		cmd_arg = ft_split(line, ' ');
		free(line[i]);
		i++;
	}
	free(line);
}

t_data	*set_cmd(char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
}

int	main(void)
{
	print_header();
	printf("%s\n", prompt());
	return (0);
}