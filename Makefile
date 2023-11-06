NAME = so_long.a

CD = cd

LIBFT_DIR = Libft

SRCS_DIR = ./Sources/

INCLUDE = so_long.h

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \

SRC = 	$(addprefix $(SRCS_DIR),\
			ft_check_map.c 	\
			ft_utils.c		\
			ft_map_init.c	\
			ft_game_init.c	\
			ft_free.c		\
			so_long.c)		

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS	= -lmlx -lXext -lX11

all: $(NAME)

$(NAME): libft $(OBJ)
		cp $(LIBFT_DIR)/libft.a ./so_long.a
		ar -rcs $@ $(OBJ)

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) all -C ./Libft

clean: 
		rm -rf $(OBJ)

fclean:	clean
		$(CD) $(LIBFT_DIR) && make -i fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft