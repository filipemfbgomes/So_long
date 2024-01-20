/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:24:33 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 19:07:18 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void paint_icon(t_img img, int pos_x, int pos_y, t_img *screen)
{
	int x;
	int y;
	unsigned int color;

	y = 0;
	while (y < img.imgy)
	{
		x = 0;
		while (x < img.imgx)
		{
			color = my_mlx_get_pixel(&img, x, y);
            if (color)
			    my_mlx_pixel_put(screen, pos_x + x, pos_y + y, (int)color);
			x++;
		}
		y++;
	}	
}

void paint_objects(t_map map, t_canvas *canvas, t_action act)
{
	int x;
	int y;
	
	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.colums)
		{
			if (map.full[y][x] == 'C')
				paint_icon(canvas->cristal[act.cristal], x * ICON, y * ICON, &canvas->game);
			else if (map.full[y][x] == 'E' && map.collectables == 0)
				paint_icon(canvas->portal_open, x * ICON, y  * ICON, &canvas->game);
			else if (map.full[y][x] == 'E' && map.collectables > 0)
				paint_icon(canvas->portal_close, x * ICON, y  * ICON, &canvas->game);
			else if (map.full[y][x] == '1')
				paint_icon(canvas->walls, x * ICON, y * ICON, &canvas->game);
			else if (map.full[y][x] == '0')
				paint_icon(canvas->floor, x * ICON, y * ICON, &canvas->game);
			else if (map.full[y][x] == 'X')
				paint_icon(canvas->enemy, x * ICON, y * ICON, &canvas->game);
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
	if (movements == NULL)
    {
        return;
    }
    phrase = ft_strjoin("Movements : ", movements);
    if (phrase == NULL)
	{
        return;
	}
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 22, 0x00FFFFFF, phrase);
	free(movements);
	free(phrase);
}

void	paint(void)
{
		paint_objects(*map(), canvas(), *act());
		print_movements(win());
}
