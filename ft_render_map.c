/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:23:15 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/10 16:36:33 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_movements(t_game *game);
int		ft_render_map(t_game *game);
void	ft_which_texture(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_texture(t_game *game, t_image texture, int line, int colum);

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
	x = 0;
		while(x < game->map.columns)
		{
		ft_which_texture(game, x, y);
		x++;
		}
	y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_which_texture(t_game *game, int x, int y)
{
	char texture;
	
	texture = game->map.full[y][x];
	if (texture == WALL)
		ft_render_texture(game, game->wall, y, x);
	else if (texture == FLOOR)
		ft_render_texture(game, game->floor, y, x);
	else if (texture == COLLECTABLE)
		ft_render_texture(game, game->collectables, y, x);
	else if (texture == M_EXIT)
	{
		if (game->map.collectables == 0)
			ft_render_texture(game, game->exit_open, y, x);
		else
			ft_render_texture(game, game->exit_close, y, x);
	}
	else if (texture == PLAYER)
		ft_render_player(game, y, x);
}

void ft_render_player(t_game *game, int x, int y)
{
	if (game->player_movement == KEY_W)
		ft_render_texture(game, game->player_right, x, y);
	else if (game->player_movement == KEY_S)
		ft_render_texture(game, game->player_right, x, y);
	else if (game->player_movement == KEY_D)
		ft_render_texture(game, game->player_right, x, y);
	if (game->player_movement == KEY_A)
		ft_render_texture(game, game->player_left, x , y);
	
}

void	ft_render_texture(t_game *game, t_image texture, int line, int colum)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, texture.xpm_ptr, colum * texture.x, line * texture.y);
}