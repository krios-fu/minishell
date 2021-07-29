#ifndef UTILS_H
# define UTILS_H

# include "libminishell.h"
/*
** list_utils.c
*/
t_list	*fill_envp_list(char **envp);
void	sort_env_list(t_list *lst);
void	print_list(t_list *lst);
char	*search_env(t_list *envp_list, char *name);

/*
** list_utils2.c
*/
void	replace_content_envp(t_data *data, char *content, char *name);
void	replace_content_exp(t_data *data, char *content, char *name);
t_list	*fill_exp_list(char **envp);
char	*fill_with_dquotes(char *envp);
int		get_var_len(char *str);

/*
** list_utils3.c
*/
char	**get_env(t_data *data);
int		min_atoi(char *str);
void	fill_slung_dash(t_data *data);

/*
** signals.c
*/
void	signals(void);
void	signal_handler(int number);
void	signal_child(int number);
void	signal_child2(int number);

/*
** start.c
*/
t_shell	*init_shell(char **envp);
void	main_loop(t_shell *shell);
#endif
