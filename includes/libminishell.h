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
	char				*origin;
	char				*symbol; 
	char 				*dst;
	struct	s_redirct	*next;
}				t_redirect;


typedef	struct s_process
{
	char		*cmd;
	char		**argv;
	struct s_process	*next;
	t_redirect	*lst_redirect;
}				t_process;

typedef	struct s_data
{
	struct s_process	lst_process;
}				t_data;

/*
**	END structs for split line prompt 
*/

/*
**	Struct for list of enviroment variables
*/
typedef struct s_envp
{
	void			*content;
	struct s_envp	*next;
}				t_envp;


/* 
**	struct for minishell vriables
*/
typedef struct s_shell
{
	t_envp			*envp_list;
	t_data			*data;
}				t_shell;


/*
**	srcs/utils/envp_list_utils.c functions
*/
t_envp	*ft_lstnew(void *content);
t_envp	*ft_lstlast(t_envp *lst);
t_envp	*fill_envp_list(char **envp);
void	ft_lstadd_front(t_envp **alst, t_envp *new);
void	ft_lstadd_back(t_envp **alst, t_envp *new);

#endif
