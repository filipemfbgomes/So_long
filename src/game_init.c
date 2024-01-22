/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:14:16 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:37:00 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	init_game(char *argv)
{
	map()->collectables = 0;
	map()->exit = 0;
	map()->players = 0;
	map()->movements = 0;
	map()->map_path = argv;
}

t_img	new_image(t_win *win, int x, int y)
{
	t_img	img;

	img.mlx_img = mlx_new_image(win->mlx_ptr, x, y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, \
	&img.endian);
	return (img);
}

t_img	load_image(t_win *win, char *path)
{
	t_img	img;

	img.mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, \
	path, &img.imgx, &img.imgy);
	if (img.mlx_img == NULL)
		error_msg("Couldn't find the texture");
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, \
	&img.endian);
	return (img);
}

void	load_and_assign_image(t_win *win, t_img *img, char *path)
{
	*img = load_image(win, path);
}

void	init_textures(t_win *win)
{
	load_and_assign_image(win, &canvas()->walls, \
	"Textures/XPM/Walls_Floor/walls.xpm");
	load_and_assign_image(win, &canvas()->floor, \
	"Textures/XPM/Walls_Floor/floor.xpm");
	load_and_assign_image(win, &canvas()->enemy, \
	"Textures/XPM/Enemy/enemy.xpm");
	load_and_assign_image(win, &canvas()->player_right, \
	"Textures/XPM/Player/right.xpm");
	load_and_assign_image(win, &canvas()->player_left, \
	"Textures/XPM/Player/left.xpm");
	load_and_assign_image(win, &canvas()->portal_close, \
	"Textures/XPM/Exit/exit_close.xpm");
	load_and_assign_image(win, &canvas()->portal_open, \
	"Textures/XPM/Exit/exit_open.xpm");
	init_cristal(win, 0, "Textures/XPM/Floor_cristal/floor_c", ".xpm");
}
