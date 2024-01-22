/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:06:18 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:03:08 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

//get_fps();
//engine();

void	so_long(t_win *win)
{
	paint();
	animation();
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	canvas()->game.mlx_img, 0, 0);
}

int	main(int argc, char **argv)
{
	int	fd;

	check_command(argc, argv[1]);
	init_game(argv[1]);
	fd = open(map()->map_path, O_RDONLY);
	get_max_values(&fd);
	init_mlx(win());
	mlx_managent();
}
