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
}			t_shell;


/*
** List functions
*/
t_list	*fill_envp_list(char **envp);

/*
** Builtins
*/
int ft_env(t_list *envp_list);
int	ft_unset(t_list **envp_list, char *name);

#endif
