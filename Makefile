RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

NAME = fdf

# SOURCES AND OBJS
MAIN    =	main.c
SOURCES =	map.c colors.c constructors.c cleaners.c aux.c utils.c window.c

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
MLX = ./minilibx/libmlx_Linux.a
MLX_LINKS = -L./minilibx -lmlx_Linux -lXext -lX11 -lm

# BONUS STUFF
BONUS = 

SOURCES_BONUS = 
SRCS_DIR_BONUS = bonus
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SOURCES_BONUS:.c=.o))

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
	@make -C ./minilibx -s

bonus: $(LIBFT) $(OBJS_BONUS)
	@echo "$(YELLOW)Compiling $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(INCLUDE_FLAGS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_FLAGS)

clean:
	@echo "$(RED)Removing objects$(RESET)"
	@rm -rf $(OBJS_DIR)
	@make clean -C ./minilibx -s
	@make clean -C ./libft -s

fclean: clean
	@echo "$(RED)Removing $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@echo "$(RED)Removing $(BONUS)$(RESET)"
	@rm -rf $(BONUS)
	@echo "$(RED)Removing libs$(RESET)"
	@rm -rf $(LIBFT)

re:	fclean all
	@echo "$(ORANGE)Re-Done!!$(RESET)"

.PHONY: all clean fclean re bonus