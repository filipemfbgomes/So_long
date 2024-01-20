/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:14:16 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 18:28:08 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void	init_game(char *argv)
{
	map()->collectables = 0;
	map()->exit = 0;
	map()->players = 0;
	map()->movements = 0;
	map()->map_path = argv;
	map()->get_map_flag = 1;
}

t_img	new_image(t_win *win, int x, int y)
{
	t_img	img;

	img.mlx_img = mlx_new_image(win->mlx_ptr, x, y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

t_img	load_image(t_win *win, char *path)
{
	t_img img;
	
	img.mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, path, &img.imgx, &img.imgy);
	if (img.mlx_img == NULL)
		error_msg("Couldn't find the texture");
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

void	init_textures(t_win *win)
{
	canvas()->walls = load_image(win, "Textures/XPM/Walls_Floor/walls.xpm");
	canvas()->floor = load_image(win, "Textures/XPM/Walls_Floor/floor.xpm");
	canvas()->enemy = load_image(win, "Textures/XPM/Enemy/enemy.xpm");
	canvas()->player_right = load_image(win, "Textures/XPM/Player/right.xpm");
	canvas()->player_left = load_image(win, "Textures/XPM/Player/left.xpm");
	canvas()->portal_close = load_image(win, "Textures/XPM/Exit/exit_close.xpm");
	canvas()->portal_open = load_image(win, "Textures/XPM/Exit/exit_open.xpm");
	init_cristal(win);
}

void	init_cristal(t_win *win)
{
	char 	*str1;
	char 	*str2;
	char 	*place;
	char	*path;
	char	*temp;
	int 	i;

	str1 = ft_strdup("Textures/XPM/Floor_cristal/floor_c");
	str2 = ft_strdup(".xpm");
	i = 0;
	while (i < 24)
	{
		place = ft_itoa(i + 1);
		temp = ft_strjoin(place, str2);
		path = ft_strjoin(str1, temp);
		canvas()->cristal[i] = load_image(win, path);
		free(path);
		free(place);
		free(temp);
		i++;
	}
	free(str1);
	free(str2);
}

