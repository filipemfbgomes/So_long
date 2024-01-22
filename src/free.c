/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:04:16 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/13 15:32:46 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

int	error_msg(char *message)
{
	if (map()->test)
		free_map(map()->test);
	free_all(win());
	ft_printf("Error\n %s", message);
	exit (0);
}

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}

void	free_all(t_win *win)
{
	destroy_images(win);
	if (win->win_ptr)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		win->win_ptr = NULL;
	}
	if (win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
	}
	if (map()->map_alloc == true)
		free_map(map()->full);
}

void	destroy_images(t_win *win)
{
	int	index;

	index = 0;
	while (index < 24)
	{
		mlx_destroy_image(win->mlx_ptr, canvas()->cristal[index].mlx_img);
		index++;
	}
	mlx_destroy_image(win->mlx_ptr, canvas()->player_right.mlx_img);
	mlx_destroy_image(win->mlx_ptr, canvas()->player_left.mlx_img);
	mlx_destroy_image(win->mlx_ptr, canvas()->portal_close.mlx_img);
	mlx_destroy_image(win->mlx_ptr, canvas()->portal_open.mlx_img);
	mlx_destroy_image(win->mlx_ptr, canvas()->walls.mlx_img);
	mlx_destroy_image(win->mlx_ptr, canvas()->floor.mlx_img);
	mlx_destroy_image(win->mlx_ptr, canvas()->enemy.mlx_img);
	if (canvas()->game.mlx_img)
		mlx_destroy_image(win->mlx_ptr, canvas()->game.mlx_img);
}

int	exit_game(void)
{
	free_all(win());
	exit(0);
}
