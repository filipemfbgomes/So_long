NAME = so_long.a

CD	= cd
RM	=	rm -f

LIBFT_DIR = Libft
SRC_DIR = src/

INCLUDE 	= so_long.h

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \

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

$(NAME): libft $(OBJS)
		cp $(LIBFT_DIR)/libft.a ./so_long.a
		ar -rcs $@ $(OBJS)

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) all -C ./Libft

clean: 
		rm -rf $(OBJS)

fclean:	clean
		$(CD) $(LIBFT_DIR) && make -i fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft