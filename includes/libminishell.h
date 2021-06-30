#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

//Struct for list of enviroment variables
typedef struct s_envp
{
	void			*content;
	struct s_envp	*next;
}			t_envp;

//struct for minishell vriables
typedef struct s_shell
{
	t_envp	*envp_list;
}			t_shell;


//  srcs/utils/envp_list_utils.c functions
t_envp	*ft_lstnew(void *content);
void	ft_lstadd_front(t_envp **alst, t_envp *new);
t_envp	*ft_lstlast(t_envp *lst);
void	ft_lstadd_back(t_envp **alst, t_envp *new);
t_envp	*fill_envp_list(char **envp);

#endif
