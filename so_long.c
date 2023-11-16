/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:06:18 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/14 18:13:57 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_command(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_game(game);
	ft_check_map(game);
	ft_init_mlx(game);
	ft_init_textures(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, \
	ButtonPressMask, ft_end_game, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all(game);
}
