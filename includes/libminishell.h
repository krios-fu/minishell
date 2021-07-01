#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

//struct for minishell variables
typedef struct s_shell
{
	t_list	*envp_list;
}			t_shell;


//list functions
t_list	*fill_envp_list(char **envp);

#endif
