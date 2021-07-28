/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:37:30 by krios-fu          #+#    #+#             */
/*   Updated: 2021/07/28 20:43:41 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H


# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RED	"\033[1;31m"
# define WHITE	"\033[0;37m"

typedef int t_bool;

typedef struct s_parseo
{
	size_t		num_arg;
	size_t		i;
	t_bool		flag;
	t_bool		quotes_d;
	t_bool		quotes_s;

}				t_parseo;

enum	e_boolean
{
	false,
	true
};

/*
** Start structs for split line prompt 
*/

typedef struct s_redirect
{
	char				**file;
	char				*symbol; 
	int					pos;
	struct	s_redirect	*next;
}				t_redirect;

typedef	struct s_process
{
	char				**argv;
	t_redirect			*input;
	t_redirect			*output;
	pid_t				pid;
	int					*fd;
	int					fd_out;
	int					status;
	struct 	s_process	*next;
}				t_process;

/*
**	functions prompt/ prompt
*/


void			print_header(void);



/*
** Funtions prompt / pre-parseo 
*/

int				get_num_pipe(char *line);
int				pre_parse(char *line);

/*
**	functions prompt/ parseo
*/

int				num_arg_process (char *line, t_process *lst_process);
void			change_status_quote(char *line, t_parseo *parse);
char			**get_lines_cmd(char *line, int num_process);

/*
**	functions prompt/ parseos_token
*/

char			*next_token(char *line);
int				len_token(char *line);
char			**get_tokens_arg(t_process *process, char *line);

/*
**	functions prompt/ utils
*/

char			*ft_isspace(char *str);
void			ft_addlst_back_redirect(t_redirect *redirect, t_redirect *new_redirect);
void			ft_addlst_back_process(t_process *process, t_process *new_process);
 int			get_num_words(char **str);
 int			get_num_words_join(char **argv);
 char			**ft_matrixjoin(const char **matrix1, const char **matrix2);
char			**final_token(char **argv);
/*
**	functions prompt/ redirect
*/

char			*get_redirect(char *line, t_process *lst_process);
int				is_redirect(int c);
char			*set_symbol_redirect(t_redirect *redirect, char *line);
char			*set_file_redirect(t_redirect *redirect, char *line);


/*
**
**  srscs/prompt / parseo_quote
*/
void			del_quotes(t_process *process);
int				is_quote(char c);

/*  expansive*/
void	len_expansive(t_var *var);
int		get_num_words_matrix (char **str);
char	**matrixjoin(char **str1, char **str2, int insec_point);
void	expansive_swap_case1(t_shell *shell, t_var *var);
void	expansive_swap_case2(t_shell *shell, t_var *var);
void	expansive_swap_case3(t_shell *shell, t_var *var);
void	expansive_swap(t_shell *shell, t_var *var);

#endif
