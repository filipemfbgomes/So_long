/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:22:42 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/21 18:45:15 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

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
