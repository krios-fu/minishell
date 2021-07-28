#ifndef BUILTINS_H
# define BUILTINS_H

# include "libminishell.h"
/*
** ft_cd
*/
void	ft_cd(t_data *data);
int		check_path(char *path);
int		special_path(t_data *data);
int		cdpath_loop(t_data *data, char **paths);
int		check_for_swung_dash(t_data *data);
void	update_pwd(t_data *data, char *new_pwd);

/*
** ft_echo
*/
void	ft_echo(t_data *data);

/*
** ft_env
*/
void	ft_env(t_data *data);

/*
** ft_exit
*/
void	ft_exit(t_data *data);

/*
** ft_export
*/
void	ft_export(t_data *data);
int		already_exist(t_list *lst, char *var);
char	*get_name(char *var);
int		check_arg_name(char *arg);
void	not_valid_identifier(char *builtin, char *arg);

/*
** ft_pwd
*/
void	ft_pwd(t_data *data);

/*
** ft_unset
*/
void	ft_unset(t_data *data);

/*
** ft_list_undefine
*/
char	**ft_lst_undefine(t_data *data);

#endif
