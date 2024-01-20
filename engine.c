/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:39:42 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 17:56:40 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void	engine(void)
{
	get_fps();
	check_movement();
}

void	move(int x, int y)
{
	if ((map()->full[y][x] != '1') && (map()->full[y][x] != 'E' \
	|| map()->collectables == 0))
	{
		map()->movements++;
		check_collected(x, y, map()->full);
		if (map()->full[y][x] == 'E')
			exit_game();
		else if (map()->full[y][x] == 'X')
			exit_game();
		map()->full[y][x] = 'P';
		map()->full[(int)objs()->player.pos_y][(int)objs()->player.pos_x] = '0';
		printf("%d\n", map()->movements);
		objs()->player.pos_x = x;
		objs()->player.pos_y = y;
	}
}

void	check_movement(void)
{
	if (keys()->arr_left == 1)
	{
		move(objs()->player.pos_x - 1, objs()->player.pos_y);
		paint_icon(canvas()->player_left, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
	else if (keys()->arr_right == 1)
	{
		move(objs()->player.pos_x + 1, objs()->player.pos_y);
		paint_icon(canvas()->player_right, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
	else if (keys()->arr_up == 1)
	{
		move(objs()->player.pos_x, objs()->player.pos_y - 1);
		paint_icon(canvas()->player_right, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
	else if (keys()->arr_down == 1)
	{
		move(objs()->player.pos_x, objs()->player.pos_y + 1);
		paint_icon(canvas()->player_right, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
}
