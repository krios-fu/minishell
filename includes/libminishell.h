#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

/*
** Struct for minishell variables
*/
typedef struct s_shell
{
	t_list	*envp_list;
	t_list	*exp_list;
}			t_shell;


/*
** List Utils
*/
t_list	*fill_envp_list(char **envp);
t_list  *sort_env_list(t_list **lst);
void	print_list(t_list *lst);
char	*search_env(t_list *envp_list, char *name);

/*
** Builtins
*/
int ft_env(t_list *envp_list);
int	ft_unset(t_list **envp_list, char *name);
int	ft_pwd(void);
int	ft_export(t_list **env_list, t_list **exp_list, char **var);
int	ft_echo(char **args);
int ft_cd(t_list **envp_list, t_list **exp_list, char *path);

#endif
