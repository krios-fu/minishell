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
	t_list 			*envp_list;
	t_list			*exp_list;
}				t_data;


typedef struct s_var
{
	int		i;
	int		j;
	int		len_exp;
	char	*content;
	char	*before_exp;
	char	*after_exp;
	char	*join_befor_tmp;
	char	*env;
	char	**token;
}				t_var;

/*
** Struct for minishell variables
*/

typedef struct s_shell
{
	t_data 		*data;
}			t_shell;



/*
**	process/process
**
*/

void	expansive_token(t_shell *shell);

int		get_process(t_data *data, char *line);
void	free_resources(t_process *process);


/* 
** process / exect
*/

void	*menu_builtins (void);
int		search_builtins(char *bcmd);
int		start_process(t_shell *shell);

/*
** Builtins
*/

int 	ft_cd(t_data *data);
void		ft_echo(t_data *data);
int		ft_env(t_data *data);
int		ft_export(t_data *data);
int		ft_pwd(t_data *data);
int		ft_unset(t_data *data);


/* 
** lst
*/

t_list	*fill_envp_list(char **envp);
t_list	*sort_env_list(t_list **lst);
void	print_list(t_list *lst);
char	*search_env(t_list *envp_list, char *name);


/*
**
** utils free
*/

void	free_resources(t_process *process);
void	free_matrix(char **str);
void	free_redirect(t_redirect *redirect);
#endif
