INCLUDES = -I$(LIBFT) -I includes/ -lreadline


# FILE NAME #
NAME = minishell

# SOURCES #
SRCS =	srcs/utils/list_utils					\
		srcs/utils/list_utils2					\
		srcs/utils/list_utils3					\
		srcs/utils/main							\
		srcs/prompt/prompt						\
		srcs/prompt/utils						\
		srcs/prompt/redirect					\
		srcs/builtins/ft_env					\
		srcs/builtins/ft_export/ft_export		\
		srcs/builtins/ft_export/ft_export_utils	\
		srcs/builtins/ft_pwd					\
	 	srcs/builtins/ft_unset					\
		srcs/builtins/ft_echo					\
		srcs/builtins/ft_cd/ft_cd				\
		srcs/builtins/ft_cd/ft_cd_utils			\
		srcs/builtins/ft_cd/ft_cd_utils2		\
		srcs/builtins/ft_exit					\
		srcs/prompt/parseo 						\
		srcs/prompt/pre_parseo					\
		srcs/process/exec						\
		srcs/process/process					\
		srcs/prompt/parseo_tokens				\
		srcs/prompt/expansive_var				\
		srcs/utils/free							\
		srcs/prompt/parseo_quote				\
		srcs/prompt/utils2						\
		srcs/pipex/pipex						\
		srcs/pipex/search_path					\
		srcs/process/error						\
		srcs/pipex/search_redirect				\
		srcs/pipex/child_final					\
		srcs/pipex/child_first					\
		srcs/pipex/childs_between				\
		srcs/pipex/exec_one_process				\
		srcs/pipex/utils						\
		srcs/builtins/ft_list_undefine			\
		srcs/prompt/expansive_var_utils			\
		srcs/prompt/expasive_var_case			\
		srcs/utils/signals						\
		srcs/prompt/expansive_redirect
#srcs/utils/signals						

#		srcs/utils/start						
SRCSM = $(addsuffix .c, $(SRCS))
OBJS = $(SRCSM:.c=.o)

LIBFT = libft/libft.a

# COMPILER FLAGS -lreadline for library <readline/readline.h> &&  <readline/history.h>#
CC = gcc -Wall -Wextra -Werror -g3 -fsanitize=address
# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) ./includes/libminishell.h ./includes/prompt.h ./includes/builtins.h ./includes/utils.h ./includes/data.h
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@make -sC ./libft
	@echo "$(BLUE)==========CREATING MINISHELL==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) -o ${NAME} -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
	@echo "Success creating minishell file"
# -g3 -fsanitize=address
clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@make -sC ./libft/ fclean

fclean: clean
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"

re : fclean all

.PHONY: all clean fclean re addsuffix
