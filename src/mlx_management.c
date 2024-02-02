/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:20:16 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:04:05 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	init_mlx(t_win *win)
{
	if (map()->colums == 0 || map()->rows == 0)
	{
		ft_printf("Invalid map dimensions\n");
		exit(0);
	}
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
	{
		error_msg("Couldn't find mlx pointer.\n");
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, (map()->colums) * ICON, \
	(map()->rows) * ICON, "so_long");
	if (win->win_ptr == NULL)
	{
		error_msg("Couldn't create the Window.\n");
	}
}

void	mlx_managent(void)
{
	init_textures(win());
	mlx_hook(win()->win_ptr, 17, 0, free_all, NULL);
	mlx_key_hook(win()->win_ptr, key_hook, map());
	mlx_loop_hook(win()->mlx_ptr, render, win());
	mlx_loop(win()->mlx_ptr);
}
