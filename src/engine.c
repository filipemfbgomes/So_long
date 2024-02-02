/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:39:42 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:47:33 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

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
		{
			ft_printf("YOU LOSE! TRY AGAIN CHAMP!\n");
			free_all();
		}
		map()->full[y][x] = 'P';
		map()->full[(int)objs()->player.pos_y][(int)objs()->player.pos_x] = '0';
		printf("%d\n", map()->movements);
		objs()->player.pos_x = x;
		objs()->player.pos_y = y;
	}
}
