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
	char				*input;
	int					fd_orig;
	char				*symbol; 
	char 				*output;
	int					fd_dst;
	int					pos;
	struct	s_redirct	*next;
}				t_redirect;

typedef	struct s_process
{
	char				*cmd;
	char				**argv;
	struct s_process	*next;
	t_redirect			*lst_redirect;
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
**functions prompt parseo
*/

int			is_redirect(int c);
char		*prompt(void);
char		*set_symbol_redirect(t_redirect *redirect, char *line);
char		*set_origin_redirect(t_redirect *redirect, char *line);
char		*set_dst_redirect(t_redirect *redirect, char *line);
char		*part_one_redirect(t_redirect *redirect, char *line);
char		*ft_isspace(char *str);


#endif
