/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:20:16 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 17:50:46 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void	init_mlx(t_win *win)
{
	if (map()->colums == 0 || map()->rows == 0)
	{
        ft_printf("Invalid map dimensions");
		exit (0);
    }
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
	{
		error_msg("Couldn't find mlx pointer.");
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, (map()->colums)  * ICON, (map()->rows) * ICON, "so_long");
	if (win->win_ptr == NULL)
	{
		error_msg("Couldn't create the Window.");
	}
}

void	mlx_managent(void)
{
	init_textures(win());
	mlx_hook(win()->win_ptr , 17, 0, exit_game, NULL);
	mlx_hook(win()->win_ptr, 2, 1L << 0, scan_key, NULL);
	mlx_hook(win()->win_ptr, 3, 1L << 1, scan_key_release, win());
	mlx_loop_hook(win()->mlx_ptr, render, win());
	mlx_loop(win()->mlx_ptr);
}