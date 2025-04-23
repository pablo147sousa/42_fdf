RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

NAME = fdf

# SOURCES AND OBJS
MAIN    =	main.c
SOURCES =	map.c colors.c constructors.c cleaners.c aux.c utils.c \
			extra.c functions.c draw.c pov.c toggles.c transform.c

# Includes
INCLUDE = include
INCLUDE_FLAGS = -I$(INCLUDE)
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = build
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a
MLX_LINKS = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

# COMPILATION STUFFS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(MLX) $(MLX_LINKS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_FLAGS)

$(OBJS_MAIN): $(MAIN_SRC) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_FLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make -C ./libft -s

$(MLX):
	@make -C ./minilibx-linux -s

clean:
	@echo "$(RED)Removing objects$(RESET)"
	@rm -rf $(OBJS_DIR)
	@make clean -C ./minilibx-linux -s
	@make clean -C ./libft -s

fclean: clean
	@echo "$(RED)Removing $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@echo "$(RED)Removing libs$(RESET)"
	@rm -rf $(LIBFT)

re:	fclean all
	@echo "$(ORANGE)Re-Done!!$(RESET)"

.PHONY: all clean fclean re