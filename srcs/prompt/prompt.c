/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:25:08 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/29 02:19:28 by jacgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libminishell.h"

void	print_header(void)
{
	printf("\n");
	printf(CYAN"███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\
	     \n");
	printf(CYAN"████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\
	     \n");
	printf(BLUE"██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\
	     \n");
	printf(BLUE"██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\
	     \n");
	printf(GREEN"██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗");
	printf("███████╗\n");
	printf(GREEN"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝");
	printf("╚══════╝\n");
	printf(RED"Jacgarci && Krios-fu");
}

void	print_welcome(t_shell *shell)
{
	char	*logname;

	logname = search_env(shell->data->envp_list, "LOGNAME");
	printf("\t\t\t    ✨ "CYAN"Wel"BLUE"co"GREEN"me "WHITE"%s ✨\n\n", &logname[8]);
	free(logname);
}

static int	get_ultimate_dir(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (i - 1);
}

static char	*message_promt(t_shell *shell, char **s_path)
{
	char	*path;
	char	*prompt;

	(void)shell;
	if (g_error_code == 0)
	{
		path = ft_strjoin(CYAN"roc"BLUE"ket"GREEN"Men 🚀 "RED,
				s_path[get_ultimate_dir(s_path)]);
		prompt = ft_strjoin(path, GREEN" ➜ "WHITE);
	}
	else
	{
		path = ft_strjoin(CYAN"roc"BLUE"ket"GREEN"Men 💥 "RED,
				s_path[get_ultimate_dir(s_path)]);
		prompt = ft_strjoin(path, RED" ➜ "WHITE);
	}
	free(path);
	return (prompt);
}

char	*prompt(t_shell *shell)
{
	char	*line;
	char	*prompt;
	char	*path;
	char	**split_path;

	line = NULL;
	path = getcwd(NULL, 0);
	split_path = ft_split(path, '/');
	free(path);
	if (!*split_path)
	{
		split_path = malloc(sizeof(char *) * 2);
		split_path[0] = ft_strdup("/");
		split_path[1] = NULL;
	}
	prompt = message_promt(shell, split_path);
	line = readline(prompt);
	free(prompt);
	free_matrix(split_path);
	return (line);
}
