INCLUDES = -I$(LIBFT) -I includes/

# FILE NAME #
NAME = minishell

# SOURCES #
SRCS =	srcs/utils/list_utils		\
		srcs/utils/main_krios		\
		srcs/prompt/prompt			\
		srcs/prompt/utils			\
		srcs/prompt/redirect		\
		srcs/builtins/ft_env		\
		srcs/builtins/ft_pwd		\
		srcs/builtins/ft_export		\
		srcs/builtins/ft_echo		\
		srcs/builtins/ft_cd			\
		srcs/builtins/ft_unset		\
		srcs/prompt/parseo 			\
		srcs/prompt/pre_parseo		\
		srcs/process/exec			\
		srcs/process/process		\
		srcs/prompt/parseo_tokens	\
		srcs/prompt/expansive_var

SRCSM = $(addsuffix .c, $(SRCS))
OBJS = $(SRCSM:.c=.o)

LIBFT = libft/libft.a

# COMPILER FLAGS -lreadline for library <readline/readline.h> &&  <readline/history.h>#
CC = gcc -Wall -Wextra -Werror  
#-g3 -fsanitize=address
# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) ./includes/libminishell.h ./includes/prompt.h
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@make -sC ./libft
	@echo "$(BLUE)==========CREATING MINISHELL==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) -o ${NAME} -lreadline 
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
