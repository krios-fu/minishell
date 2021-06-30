.PHONY	:	clean all fclean re bonus

SRCS	=	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strncmp.c		\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_strnstr.c		\
			ft_atoi.c			\
			ft_calloc.c			\
			ft_strdup.c			\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_itoa.c			\
			ft_split.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl.c		\
			ft_putendl_fd.c		\
			ft_putnbr.c			\
			ft_putnbr_fd.c		\
			ft_strtrim.c		\
			ft_strmapi.c		\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_islower.c		\
			ft_isupper.c		\
			ft_isblank.c		\
			ft_strtrim.c		\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strndup.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strstr.c			\
			ft_strcmp.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_memdel.c			\
			ft_strdel.c			\
			ft_memalloc.c		\
			ft_stradd_back.c	

BONUSSRCS	=	ft_lstnew_bonus.c		\
				ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\

GCC			=	-@gcc -Wall -Wextra -Werror

OBJS		=	${SRCS:.c=.o}

BONUSOBJS	=	${BONUSSRCS:.c=.o}

INCLUDES	=	./

NAME	=	libft.a

RM		=	-@rm -f

${NAME}	:	${OBJS} libft.h
			${GCC} -I${INCLUDES} -c ${SRCS}
			-@ar rc ${NAME} ${OBJS}
			-@ranlib ${NAME}

all		:	${NAME}

bonus	:	${BONUSOBJS} ${OBJS} libft.h
			${GCC} -I${INCLUDES} -c ${BONUSSRCS} ${SRCS}
			-@ar rc ${NAME} ${BONUSOBJS} ${OBJS}
			-@ranlib ${NAME}

clean	:	
			-@${RM} ${OBJS} ${BONUSOBJS}

fclean	:	clean
			-@${RM} ${NAME} 

re		:	fclean all

