NAME = so_long.a

CD = cd

LIBFT_DIR = Libft

INCLUDE = so_long.h

SRC = 	check_map.c 	\
		ft_utils.c		\
		map_init.c		\
		ft_game_init.c	\
		ft_free.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall    \
         -Wextra  \
         -Werror  \

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