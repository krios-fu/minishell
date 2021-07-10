#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include "../libft/libft.h"
# include "prompt.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef	struct s_data
{
	t_process		*lst_process;
	//t_list 			**envp_list;  this is opcionaly
	//t_list			**exp_list;   this the same
}				t_data;


/*
** Struct for minishell variables
*/

typedef struct s_shell
{
	t_list	*envp_list;
	t_list	*exp_list;
}			t_shell;



/*
**	process/process
**
*/

int		get_process(t_data *data, char *line);


/* 
** process / exect
*/

void	*menu_builtins (void);
int		search_builtins(char *bcmd);
int		start_process(char **cmd);

/*
** Builtins
*/

int 	ft_cd(t_list **envp_list, t_list **exp_list, char *path);
int		ft_echo(char **args);
int		ft_env(t_list *envp_list);
int		ft_export(t_list **env_list, t_list **exp_list, char **var);
int		ft_pwd(void);
int		ft_unset(t_list **envp_list, char *name);


/* 
** lst
*/

t_list	*fill_envp_list(char **envp);
t_list	*sort_env_list(t_list **lst);
void	print_list(t_list *lst);
char	*search_env(t_list *envp_list, char *name);
#endif
