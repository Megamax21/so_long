NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = mlx

HEADER = $(INC_DIR)/so_long.h
SRCS = main.c map_parse.c map_parse_check.c map_parse_utils.c utils.c map_draw.c player_moves.c
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR) -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

mlx :
	@wget https://cdn.intra.42.fr/document/document/26928/minilibx-linux.tgz
	@tar -xvzf ./minilibx-linux.tgz
	@rm minilibx-linux.tgz
	@mv minilibx-linux/ mlx/
	@cd mlx
	@make -C mlx/

end :
	@rm -rf mlx

.PHONY: all clean fclean re
