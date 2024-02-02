/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:19:48 by fde-mour          #+#    #+#             */
/*   Updated: 2024/02/02 13:04:05 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	get_max_values(int *fd)
{
	int		x;
	int		y;
	char	*str;

	y = 0;
	x = 0;
	str = get_next_line(*fd);
	if (str == NULL)
	{
		ft_printf("Error. The map is empty\n");
		exit(0);
	}
	while (str[x] != 10 && str[x] != 13)
		x++;
	while (str)
	{
		free (str);
		str = get_next_line(*fd);
		y++;
	}
	free(str);
	map()->rows = y;
	map()->colums = x;
	printf("Linhas: %d\n", map()->rows);
	printf("Colunas: %d\n", map()->colums);
	close(*fd);
}

void	get_player(t_map map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.colums)
		{
			if (map.full[y][x] == 'P')
			{
				player->start_x = x;
				player->start_y = y;
			}
			x++;
		}
		y++;
	}
	player->pos_x = player->start_x;
	player->pos_y = player->start_y;
}

int	render(void)
{
	if (map()->map_alloc == false)
		start_map();
	so_long();
	return (0);
}
