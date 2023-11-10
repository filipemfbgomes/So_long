/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:06:18 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/10 16:43:32 by fde-mour         ###   ########.fr       */
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
	mlx_hook(game->win_ptr, 2, 1L<<0, ft_handle_input, game);
	mlx_loop(game->win_ptr);
	ft_free_all(game);
}
