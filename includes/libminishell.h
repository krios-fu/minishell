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

typedef int t_bool;

/*
** struct var parseo
*/

typedef struct s_parseo
{
	size_t		num_arg;
	size_t		i;
	t_bool		flag;
	t_bool		quotes_d;
	t_bool		quotes_s;

}				t_parseo;

/*
** Start structs for split line prompt 
*/

typedef struct s_redirect
{
	char				*file;
	char				*symbol; 
	int					pos;
	struct	s_redirect	*next;
}				t_redirect;

typedef	struct s_process
{
	char				**argv;
	t_redirect			*input;
	t_redirect			*output;
}				t_process;

typedef	struct s_data
{
	t_process			*lst_process;
}				t_data;


/*
** Struct for minishell variables
*/

typedef struct s_shell
{
	t_list	*envp_list;
	t_list	*exp_list;
}			t_shell;


/*  */
t_list		*fill_envp_list(char **envp);

/*
**	functions prompt/ utils
*/

char	*ft_isspace(char *str);
void	ft_addlst_back_redirect(t_redirect *redirect, t_redirect *new_redirect);

/*
**	functions prompt/ prompt
*/

char			*prompt(void);
void			print_header(void);

/*
**	functions prompt/ redirect
*/

char			*get_redirect(char *line, t_process *lst_process);
int				is_redirect(int c);
char			*set_symbol_redirect(t_redirect *redirect, char *line);
char			*set_file_redirect(t_redirect *redirect, char *line);

/*
**	functions prompt/ parseo
*/
int			num_arg_process (char *line, t_process *lst_process);
char			**get_tokens_arg(t_process *process, char *line);
void			change_status_quote(char *line, t_parseo *parse);
t_process 		**get_process(char *line);
/*
** Funtions prompt / pre-parseo 
*/

int	get_num_pipe(char *line);
int	pre_parse(char *line);

/*
** Builtins
*/
int ft_cd(t_list **envp_list, t_list **exp_list, char *path);
int	ft_echo(char **args);
int ft_env(t_list *envp_list);
int	ft_export(t_list **env_list, t_list **exp_list, char **var);
int	ft_pwd(void);
int	ft_unset(t_list **envp_list, char *name);



/* 
** process / exect
*/

void	*menu_builtins (void);
int		search_builtins(t_process *process);
int		start_process(t_process *process);

/* 
** lst
*/

t_list	*fill_envp_list(char **envp);
t_list  *sort_env_list(t_list **lst);
void	print_list(t_list *lst);
char	*search_env(t_list *envp_list, char *name);
#endif
