NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

SRCS = ft_printf.c \
       conversions/ft_print_chars.c \
       conversions/ft_print_p.c \
       conversions/ft_print_u.c \
       conversions/ft_print_xX.c \
       utils/ft_putchar_fd.c \
       utils/ft_itoa.c

OBJS = $(SRCS:.c=.o)

mVPATH = conversions utils

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
