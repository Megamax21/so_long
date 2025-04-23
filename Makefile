# **************************************************************************** #
#                           LIBFT + PRINTF + GNL                               #
# **************************************************************************** #

# === Compilation & Tools ===
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

# === Libs ===
NAME        := libft.a
PRINTF_DIR  := printf
GNL_DIR     := gnl
PRINTF_LIB  := $(PRINTF_DIR)/libftprintf.a
GNL_LIB     := $(GNL_DIR)/libgnl.a

# === Source Files ===
SRCS := ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_bzero.c \
	ft_memchr.c ft_putnbr_fd.c ft_memcmp.c ft_memmove.c ft_strnstr.c \
	ft_strncmp.c ft_calloc.c ft_strdup.c ft_itoa.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
	ft_safe_atoi.c

BONUS_SRCS := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS        := $(SRCS:.c=.o)
OBJS_BONUS  := $(BONUS_SRCS:.c=.o)

# === Targets ===

all: $(NAME) libs

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^

libs:
	@echo "Building Printf & GNL..."
	$(MAKE) -C $(PRINTF_DIR)
	$(MAKE) -C $(GNL_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re libs
