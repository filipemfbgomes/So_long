/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:06:18 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 19:00:01 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void so_long(t_win *win)
{
    engine();
	paint();
	animation();
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, canvas()->game.mlx_img, 0, 0);
}

int	main(int argc, char **argv)
{
	check_command(argc, argv[1]);
	init_game(argv[1]);
	int fd = open(map()->map_path, O_RDONLY);
    get_max_values(&fd);
	init_mlx(win());
	mlx_managent();
}
