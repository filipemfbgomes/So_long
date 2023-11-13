/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:14:16 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/13 16:56:48 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_textures(t_game *game);
t_image	ft_new_texture(void *mlx, char *path, t_game *game);

void	ft_init_game(t_game *game)
{
	game->map.collectables = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	game->player_texture = RIGHT;
}

void ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't find mlx pointer.", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't create the Window.", game);
	}
}

void	ft_init_textures(t_game *game)
{
	void	*mlx;
	
	mlx	= game->mlx_ptr;
	game->wall = ft_new_texture(mlx, WALL_XPM, game);
	game->floor = ft_new_texture(mlx, FLOOR_XPM, game);
	game->collectables = ft_new_texture(mlx, COLLECTABLES_XPM, game);
	game->player_right = ft_new_texture(mlx, PLAYER_RIGHT_XPM, game);
	game->player_left = ft_new_texture(mlx, PLAYER_LEFT_XPM, game);
	game->exit_close = ft_new_texture(mlx, EXIT_CLOSE_XPM, game);
	game->exit_open = ft_new_texture(mlx, EXIT_OPEN_XPM, game);
}

t_image	ft_new_texture(void *mlx, char *path, t_game *game)
{
	t_image texture;
	
	texture.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &texture.x, &texture.y);
	if (texture.xpm_ptr == NULL)
		ft_error_msg("Couldn't find the texture", game);
	return (texture);
}
