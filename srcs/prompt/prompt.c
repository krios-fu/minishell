/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:25:08 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/15 00:05:53 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"


void	print_header(void)
{
	printf(CYAN"::::    ::::  ::::::::::: ::::    ::: :::::::::::  ::::::::  :::    ::: :::::::::: :::        :::\n");
	printf(CYAN"+:+:+: :+:+:+     :+:     :+:+:   :+:     :+:     :+:    :+: :+:    :+: :+:        :+:        :+:\n");
	printf(CYAN"+:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+     +:+        +:+    +:+ +:+        +:+        +:+\n");
	printf(BLUE"+#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+     +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+\n");
	printf(BLUE"+#+       +#+     +#+     +#+  +#+#+#     +#+            +#+ +#+    +#+ +#+        +#+        +#+\n");
	printf(GREEN"#+#       #+#     #+#     #+#   #+#+#     #+#     #+#    #+# #+#    #+# #+#        #+#        #+#\n");
	printf(GREEN"###       ### ########### ###    #### ###########  ########  ###    ### ########## ########## ##########\n");
	printf(YELLOW"\t\t\t\t\t\t\t\t\t\tBy: Jacgarci && Krios-fu\n");
}



static int get_ultimate_dir(char **path)
{
	int i;

	i = 0;
	while (path[i])
	{
		i++;
	}
	return(i -1);
}
char	*prompt()
{
	char	*line;
	char	*prompt;
	char	*path;
	char	**split_path;

	path = getcwd(NULL, 0);
	split_path = ft_split(path, '/');
	free(path);
	path = ft_strjoin(CYAN"rocket-men "GREEN"➜  "YELLOW, split_path[get_ultimate_dir(split_path)]);
	prompt = ft_strjoin(path, " 🚀 "WHITE);
	free(path);
	line = readline(prompt);
	free(prompt);
	free_matrix(split_path);
	return (line);
}
