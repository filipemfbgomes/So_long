/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:22:42 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 16:49:07 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

int	scan_key_release(int keycode)
{
	if (keycode == KEY_A)
		keys()->arr_left = 0;
	else if (keycode == KEY_D)
		keys()->arr_right = 0;
	else if (keycode == KEY_W)
		keys()->arr_up = 0;
	else if (keycode == KEY_S)
		keys()->arr_down = 0;
	return (0);
}

int	scan_key(int keycode)
{
	if (keycode == KEY_ESC)
		exit_game();
	else if (keycode == KEY_A)
		keys()->arr_left = 1;
	else if (keycode == KEY_D)
		keys()->arr_right = 1;
	else if (keycode == KEY_W)
		keys()->arr_up = 1;
	else if (keycode == KEY_S)
		keys()->arr_down = 1;
	return (0);
}

int	is_valid_key(int keycode)
{
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_ESC
		|| keycode == KEY_S || keycode == KEY_W)
		return (1);
	return (0);
}

void	change_player_image(int keycode)
{
	if (keycode == KEY_W)
	{
		paint_icon(canvas()->player_right, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
	if (keycode == KEY_S)
	{
		paint_icon(canvas()->player_right, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
	if (keycode == KEY_A)
	{
		paint_icon(canvas()->player_left, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
	if (keycode == KEY_D)
	{
		paint_icon(canvas()->player_right, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON, &canvas()->game);
	}
}

int	key_hook(int keycode)
{
	if (is_valid_key(keycode))
	{
		if (keycode == KEY_ESC)
			exit_game();
		if (keycode == KEY_W)
			move(objs()->player.pos_x, objs()->player.pos_y - 1);
		if (keycode == KEY_S)
			move(objs()->player.pos_x, objs()->player.pos_y + 1);
		if (keycode == KEY_A)
			move(objs()->player.pos_x - 1, objs()->player.pos_y);
		if (keycode == KEY_D)
			move(objs()->player.pos_x + 1, objs()->player.pos_y);
		change_player_image(keycode);
	}
	return (0);
}
