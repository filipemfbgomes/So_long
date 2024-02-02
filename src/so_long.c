/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:06:18 by fde-mour          #+#    #+#             */
/*   Updated: 2024/02/02 12:52:59 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	so_long(void)
{
	paint();
	animation();
}

int	main(int argc, char **argv)
{
	int	fd;

	check_command(argc, argv[1]);
	init_game(argv[1]);
	fd = open(map()->map_path, O_RDONLY);
	if (fd == -1)
	{
		printf("The Map couldn't be opened.\n");
		exit(0);
	}
	get_max_values(&fd);
	init_mlx(win());
	mlx_managent();
}
