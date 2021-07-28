#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	t_process		*lst_process;
	t_list			*envp_list;
	t_list			*exp_list;
	t_list			*tmp_var_list;
	int				error_code;
	char			*swung_dash;
	int				num_p;
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
	char	**tmp;
	char	*tmp_join;
	char	*aux;
}				t_var;

/*
** Struct for minishell variables
*/
typedef struct s_shell
{
	t_data		*data;
	t_bool		status;
}			t_shell;

#endif
