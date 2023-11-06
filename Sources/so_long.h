/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:38 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/06 16:24:08 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COLLECTABLE  		'C'
# define PLAYER				'P'
# define M_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_ESC  			65307

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
	t_map		map;
	t_bool		map_alloc;

}	t_game;

void	ft_check_command(int argc, char **argv, t_game	*game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);
char	*ft_str_doublepointer(char **s1, const char *s2);
int		ft_error_msg(char *message, t_game *game);
void	ft_free_map(t_game *game);
void	ft_init_game(t_game *game);
void	ft_check_map(t_game *game);

#endif