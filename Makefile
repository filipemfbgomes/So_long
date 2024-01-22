.SILENT:
NAME      	= so_long
CC        	= cc
CFLAGS    	= -Wall -Wextra -Werror -g
SRC_DIR   	= ./src
OBJ_DIR   	= ./obj
FT_INCLUDE 	= -Ilibft -Llibft -lft
INCLUDE 	= -I ./ minilibx-linux/libmlx_Linux.a
_MLX		= ./minilibx-linux
_MLX_FLAGS  = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

SRCS =	animation.c check_map.c engine.c \
		game_init.c handle_input.c free.c flood_fill.c \
		init_structs.c map_init.c mlx_management.c \
		my_mlx_func.c paint.c render.c so_long.c  utils.c

OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) 
	make -C libft/
	@$(CC) $(CFLAGS) $(OBJ) $(_MLX_FLAGS) $(FT_INCLUDE) -o $(NAME) $(INCLUDE) -L $(_MLX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re run