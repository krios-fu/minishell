INCLUDES = -I$(LIBFT) -I includes/

# FILE NAME #
NAME = minishell

# SOURCES #
SRCS =	srcs/utils/envp_list_utils \
		srcs/utils/main

SRCSM = $(addsuffix .c, $(SRCS))
OBJS = $(SRCSM:.c=.o)

LIBFT = 42cursus_libft/libft.a

# COMPILER #
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
	@cd 42cursus_libft && make
	@echo "$(BLUE)==========CREATING PIPEX==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) -o ${NAME}
	@echo "Success creating pipex file"

clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)==========REMOVED==========$(RESET)"

fclean: clean
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"

re : fclean all

.PHONY: all clean fclean re addsuffix
