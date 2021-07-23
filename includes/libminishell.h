#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include "../libft/libft.h"
# include "prompt.h"
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>


/* ------------pipex------------------ */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define	WRITE_END	1
# define	READ_END		0
/* ------------pipex------------------ */

typedef	struct s_data
{
	t_process		*lst_process;
	t_list 			*envp_list;
	t_list			*exp_list;
	t_list			*tmp_var_list;
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
	char 	**tmp;
	char 	*tmp_join;
	char 	*aux;
}				t_var;

/*
** Struct for minishell variables
*/

typedef struct s_shell
{
	t_data 		*data;
	char		**envp;
}			t_shell;





/*
**	process/process
**
*/
void	print_error_cmd(char *cmd);
void	print_error_file(char *file);





void	expansive_token(t_shell *shell);

int		get_process(t_data *data, char *line);
void	assign_fd_to_process (t_process *lst_process);
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
void	signal_handler(int number);
void 	ft_cd(t_data *data);
void	ft_echo(t_data *data);
void	ft_env(t_data *data);
void	ft_export(t_data *data);
void	ft_pwd(t_data *data);
void	ft_unset(t_data *data);
void	ft_exit(t_data *data);
int	special_path(t_data *data);
int	check_path(char *path);

/* 
** lst
*/

t_list	*fill_envp_list(char **envp);
void	sort_env_list(t_list *lst);
void 	sort_lst(t_list **lst);
void	print_list(t_list *lst);
char	*search_env(t_list *envp_list, char *name);
void    replace_content_envp(t_data *data, char *content, char *name);
void    replace_content_exp(t_data *data, char *content, char *name);
t_list	*fill_exp_list(char **envp);
char    *fill_with_dquotes(char *envp);
int     already_exist(t_list *lst, char *var);
char    *get_name(char *var);


/*
**
** utils free
*/

void	free_resources(t_process *process);
void	free_matrix(char **str);
void	free_redirect(t_redirect *redirect);


/*
**	pipex/pipex
*/

void	start_pipe(t_shell *shell, int *num_p);
void	get_path(char *cmd, char *envp[], char **f_path);
int		fd_input_redirect(t_shell *shell);
int		fd_output_redirect(t_shell *shell);
void	exec_final_child(t_shell *shell, t_process *process, int *fd_back);
void	exec_first_child(t_shell *shell, t_process *process);
void	exect_between_childs(t_shell *shell, t_process *process, int *fd_back);
void	exec_only_one_process(t_shell *shell);
int		get_fd_builtins (t_shell *shell);

#endif

