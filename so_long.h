/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:38 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/16 18:04:09 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>

# define IMG_HEIGHT			40
# define IMG_WIDTH			40

# define WALL				'1'
# define FLOOR 				'0'
# define COLLECTABLE  		'C'
# define PLAYER				'P'
# define M_EXIT 		 	'E'

# define WALL_XPM			"Textures/walls.xpm"
# define FLOOR_XPM			"Textures/floor.xpm"
# define COLLECTABLES_XPM	"Textures/collectables.xpm"
# define PLAYER_RIGHT_XPM	"Textures/right.xpm"
# define PLAYER_LEFT_XPM	"Textures/left.xpm"
# define EXIT_OPEN_XPM		"Textures/exit_open.xpm"
# define EXIT_CLOSE_XPM		"Textures/exit_close.xpm"

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_ESC  			65307

# define LEFT				1
# define RIGHT				2

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			collectables;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_texture;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		collectables;
	t_image		player_right;
	t_image		player_left;
	t_image		exit_open;
	t_image		exit_close;
}	t_game;

void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map(t_game *game);
void	ft_verify_parameters(t_game *game);
void	ft_check_map(t_game *game);
int		ft_error_msg(char *message, t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_all(t_game *game);
void	ft_init_game(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_textures(t_game *game);
t_image	ft_new_texture(void *mlx, char *path, t_game *game);
int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int new_y, int new_x, int player_texture);
void	ft_check_command(int argc, char **argv, t_game	*game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_print_movements(t_game *game);
int		ft_render_map(t_game *game);
void	ft_which_texture(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_texture(t_game *game, t_image texture, int line, int colum);
char	*ft_str_doublepointer(char **s1, const char *s2);
int		ft_victory(t_game *game);
int		ft_end_game(t_game *game);

#endif