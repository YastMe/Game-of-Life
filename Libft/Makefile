# Files Setup
NAME = libft.a

SRC_DIR = src
OBJ_DIR = obj

CFILES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CFILES))

# Compiler Commands
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs

# Colors

GRE = \033[;32m
DEF = \033[;0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(GRE)Linking object files and creating binary($(NAME))...$(DEF)"
	@$(ARCHIVER) $(NAME) $(OBJ_FILES)
	@clear

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GRE)Compiling $<\t>> $@$(DEF)"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY : all clean fclean re
