NAME = so_long

CD	= cd
RM	=	rm -f

LIBFT_DIR = libft
SRC_DIR = src/
FT_INCLUDE 	= 	-Ilibft -Llibft -lft

INCLUDE 	= -I ./ minilibx-linux/libmlx_Linux.a

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all

SRCS =	animation.c check_map.c engine.c \
		game_init.c handle_input.c free.c flood_fill.c \
		init_structs.c map_init.c mlx_management.c \
		my_mlx_func.c paint.c render.c so_long.c  utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS 		= -Wall -Wextra -Werror
_MLX		=	./minilibx-linux
_MLX_FLAGS  =	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C $(LIBFT_DIR)
		@$(CC) $(CFLAGS) $(OBJS) $(_MLX_FLAGS) $(FT_INCLUDE) -o $(NAME) $(INCLUDE) -L $(_MLX)

%.o: %.c
		@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
		rm -rf $(OBJS)

fclean:	clean
		$(CD) $(LIBFT_DIR) && make -i fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re