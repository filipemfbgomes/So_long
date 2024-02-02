/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:22:42 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:47:10 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

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
		mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
		canvas()->player_right.mlx_img, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON);
	}
	if (keycode == KEY_S)
	{
		mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
		canvas()->player_right.mlx_img, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON);
	}
	if (keycode == KEY_A)
	{
		mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
		canvas()->player_left.mlx_img, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON);
	}
	if (keycode == KEY_D)
	{
		mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
		canvas()->player_right.mlx_img, objs()->player.pos_x * ICON, \
		objs()->player.pos_y * ICON);
	}
}

int	key_hook(int keycode)
{
	if (is_valid_key(keycode))
	{
		if (keycode == KEY_ESC)
			free_all();
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
