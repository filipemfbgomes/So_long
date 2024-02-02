/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:24:33 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 19:03:17 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	paint_objects(t_map map, t_canvas *canvas, t_action act)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.colums)
		{
			if (map.full[y][x] == 'C')
				mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
				canvas->cristal[act.cristal].mlx_img, x * ICON, y * ICON);
			else if (map.full[y][x] == 'E' && map.collectables == 0)
				mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
				canvas->portal_open.mlx_img, x * ICON, y * ICON);
			else if (map.full[y][x] == 'E' && map.collectables > 0)
				mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
				canvas->portal_close.mlx_img, x * ICON, y * ICON);
			x++;
		}
		y++;
	}
}

void	paint_objects2(t_map map, t_canvas *canvas)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.colums)
		{
			if (map.full[y][x] == '1')
				mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
				canvas->walls.mlx_img, x * ICON, y * ICON);
			else if (map.full[y][x] == '0')
				mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
				canvas->floor.mlx_img, x * ICON, y * ICON);
			else if (map.full[y][x] == 'X')
				mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
				canvas->enemy.mlx_img, x * ICON, y * ICON);
			x++;
		}
		y++;
	}
}

void	print_movements(t_win *win)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(map()->movements);
	phrase = ft_strjoin("Movements: ", movements);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 22, 0x00FFFFFF, phrase);
	free(movements);
	free(phrase);
}

void	paint(void)
{
	paint_objects(*map(), canvas(), *act());
	paint_objects2(*map(), canvas());
	print_movements(win());
}
