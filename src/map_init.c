/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:06:09 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:17:40 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	check_command(int argc, char *argv)
{
	int	parameter_len;

	map()->map_alloc = false;
	if (argc > 2)
	{
		ft_printf("Too many arguments.");
		exit(0);
	}
	if (argc < 2)
	{
		ft_printf("The Map file is missing.");
		exit(0);
	}
	parameter_len = ft_strlen(argv);
	if (!ft_strnstr(&argv[parameter_len - 4], ".ber", 4))
	{
		ft_printf("Map file extention is wrong");
		exit(0);
	}
}

void	check_for_empty_line(char *arr)
{
	int	i;

	i = 0;
	if (arr[1] == '\n' || arr[0] == '\0' || arr[0] == 13)
	{
		free(arr);
		error_msg("Empty line at the beginning.");
	}
	else if (arr[ft_strlen(arr) - 1] == '\n')
	{
		free (arr);
		error_msg("Empty line at the end.");
	}
	while (arr[i + 2])
	{
		if (arr[i] == '\r' && arr[i + 2] == '\r')
		{
			free(arr);
			error_msg("Empty line in the middle.");
		}
		i++;
	}
}

void	init_map(char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;
	char	**x;
	char	**y;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_msg("The Map couldn't be opened.");
	map_temp = ft_strdup("");
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_str_doublepointer(&map_temp, line_temp);
		free(line_temp);
	}
	close(map_fd);
	check_for_empty_line(map_temp);
	x = ft_split(map_temp, '\n');
	y = ft_split(map_temp, '\n');
	map()->full = x;
	map()->test = y;
	free(map_temp);
}

void	start_map(void)
{
	t_img	x;

	init_map(map()->map_path);
	map()->map_alloc = true;
	check_rows(map());
	check_columns(map());
	get_player(*map(), &objs()->player);
	count_map(map());
	verify_parameters(map());
	fill_flood();
	if (canvas()->game.mlx_img)
		mlx_destroy_image(win()->mlx_ptr, canvas()->game.mlx_img);
	x = new_image(win(), map()->colums * ICON, map()->rows * ICON);
	canvas()->game = x;
	if (map()->full[(int)objs()->player.pos_y][(int)objs()->player.pos_x] \
	== 'P')
		paint_icon(canvas()->player_right, (int)objs()->player.pos_x * ICON, \
	(int)objs()->player.pos_y * ICON, &canvas()->game);
}
