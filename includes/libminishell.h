#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RED	"\033[1;31m"
# define WHITE	"\033[0;37m"


enum	e_boolean
{
	false,
	true
};

/*
** Start structs for split line prompt 
*/

typedef struct s_redirect
{
	char				*file;
	char				*symbol; 
	int					pos;
	struct	s_redirct	*next;
}				t_redirect;

typedef	struct s_process
{
	char				*cmd;
	char				**argv;
	struct s_process	*next;
	t_redirect			*input;
	t_redirect			*output;
}				t_process;

typedef	struct s_data
{
	t_process			*lst_process;
}				t_data;


typedef struct s_shell
{
	t_list	*envp_list;
}			t_shell;


/*  */
t_list		*fill_envp_list(char **envp);

/*
**	functions prompt/ utils
*/

char			*ft_isspace(char *str);

/*
**	functions prompt/ prompt
*/

char			*prompt(void);

/*
**	functions prompt/ redirect
*/

t_redirect		*get_redirect(char *line);
int				is_redirect(int c);
char			*set_symbol_redirect(t_redirect *redirect, char *line);
char			*set_file_redirect(t_redirect *redirect, char *line);

/*
**	functions prompt/ parseo
*/


#endif
