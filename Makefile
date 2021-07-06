INCLUDES = -I$(LIBFT) -I includes/

# FILE NAME #
NAME = minishell

# SOURCES #
SRCS =	srcs/utils/list_utils \
		srcs/utils/main srcs/prompt/prompt \
		srcs/prompt/utils srcs/prompt/redirect


SRCSM = $(addsuffix .c, $(SRCS))
OBJS = $(SRCSM:.c=.o)

LIBFT = libft/libft.a

# COMPILER FLAGS -lreadline for library <readline/readline.h> &&  <readline/history.h>#
CC = gcc -Wall -Wextra -Werror 

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@make -sC ./libft
	@echo "$(BLUE)==========CREATING MINISHELL==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) -o ${NAME} -lreadline
	@echo "Success creating minishell file"

clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@make -sC ./libft/ fclean

fclean: clean
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"

re : fclean all

.PHONY: all clean fclean re addsuffix
