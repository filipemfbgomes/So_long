/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:22:49 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/06 15:43:44 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x);
	if (keysym == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1);
	if (keysym == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1);
	if (keysym == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x);
	if (keysym == KEY_ESC)
		ft_close_game(game);
	return (0);
}

void	ft_player_move(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == M_EXIT && game->map.coins == 0)
		ft_victory(game);
	else if ((game->map.full[new_y][new_x] == FLOOR) 
	|| (game->map.full[new_y][new_x] == COINS))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_render_map(game);
	}
}
