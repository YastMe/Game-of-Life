CFILES = src/main.c src/init.c src/map.c src/clean.c src/life.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm

MLX = MLX42/build/libmlx42.a
LIBFT = Libft/libft.a

MLX_PATH = MLX42/build
LIBFT_PATH = Libft

NAME = life

all: $(NAME)

$(NAME): $(CFILES) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(CFILES) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME)

debug: $(CFILES) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) -g $(CFILES) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME) -fsanitize=address


$(MLX):
	make -C $(MLX_PATH) -j4

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)

rebug: fclean debug

re: fclean all

.PHONY: all clean fclean re debug rebug
