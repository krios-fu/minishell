/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:25:08 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/14 03:28:28 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	print_header(void)
{
	/*printf(GREEN"_______ ___ ___(_)_______ ___(_)___________  /_ _____ ___  /___  /\n");
	printf(GREEN"__  __ `__ \\__  / __  __ \\__  / __  ___/__  __ \\_  _ \\__  / __  /\n");
	printf(GREEN"_  / / / / /_  /  _  / / /_  /  _(__  ) _  / / //  __/_  /  _  /\n"); 
	printf(GREEN"/_/ /_/ /_/ /_/   /_/ /_/ /_/   /____/  /_/ /_/ \\___/ /_/   /_/\n");*/
printf(CYAN"                        ✨                              ,dPYb,              ,dPYb, ,dPYb,\n");
printf(CYAN"✨                                             ✨       IP'`Yb    ✨        IP'`Yb IP'`Yb\n");
printf(CYAN"           ✨        gg           🪐     gg             I8  8I              I8  8I I8  8I\n");
printf(CYAN"                     \"\"                  \"\"             I8  8'         ✨   I8  8' I8  8'\n");
printf(CYAN"  ,ggg,,ggg,,ggg,✨  gg    ,ggg,,ggg,    gg     ,g,  ✨ I8 dPgg,    ,ggg,   I8 dP  I8 dP\n");
printf(CYAN" ,8\" \"8P\" \"8P\" \"8,   88   ,8\" \"8P\" \"8,   88    ,8\'8,    I8dP\" \"8I  i8\" \"8i  I8dP   I8dP\n");
printf(CYAN" I8   8I   8I   8I   88   I8   8I   8I   88   ,8\' Yb    I8P    I8  I8, ,8I  I8P    I8P\n");
printf(CYAN",dP   8I   8I   Yb,_,88,_,dP   8I   Yb,_,88,_,8\'_   8) ,d8  ✨  I8, `YbadP\' ,d8b,_ ,d8b,_\n");
printf(CYAN"8P'   8I   8I   `Y88P\"\"Y88P'   8I   `Y88P\"\"Y8P\' \"YY8P8P88P     `Y8888P\"Y8888P\'\"Y888P\'\"Y88\n");
printf(YELLOW"\t\t\t\t\t\t\t\tBy: Jacgarci && Krios-fu\n");
}


char	*prompt(void)
{
	char	*line;
	line = readline(CYAN"rocket-men 🚀 "WHITE);
	return (line);
}
