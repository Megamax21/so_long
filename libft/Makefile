NAME = libft.a
FLAGS = -Wall -Wextra -Werror -Ignl
RM = rm -rf

PRINTF_DIR = printf

SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_memcpy.c ft_memset.c ft_strchr.c\
	ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strrchr.c ft_tolower.c ft_toupper.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_bzero.c ft_memchr.c ft_putnbr_fd.c\
	ft_memcmp.c ft_memmove.c\
	ft_strnstr.c ft_strncmp.c ft_calloc.c\
	ft_strdup.c ft_itoa.c ft_substr.c\
	ft_strjoin.c ft_strtrim.c ft_split.c\
	ft_strmapi.c ft_striteri.c ft_safe_atoi.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c\

SRCS_BONUS = ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

SRCS_PRINTF= printf/ft_printf.c                                            \
             printf/conversions/ft_print_u.c        printf/conversions/ft_print_xX.c\
             printf/conversions/ft_print_chars.c    printf/conversions/ft_print_p.c \
             printf/utils/ft_putchar_fd.c           printf/utils/ft_itoa.c

ALL_SRCS   = $(SRCS) $(SRCS_BONUS) $(SRCS_PRINTF)

OBJS       = $(ALL_SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

.c.o:
	@cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
    
re: fclean all

.PHONY: all clean fclean re bonus rebonus
