/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:06:09 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 17:05:37 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void	check_command(int argc, char *argv)
{
	int	parameter_len;
	
	map()->map_alloc = false;
	if (argc > 2)
		error_msg("Too many arguments.");
	if (argc < 2)
		error_msg("The Map file is missing.");
	parameter_len = ft_strlen(argv);
	if (!ft_strnstr(&argv[parameter_len - 4], ".ber", 4))
		error_msg("Map file extention is wrong");
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
	map()->full = ft_split(map_temp, '\n');
	map()->test = ft_split(map_temp, '\n');
	map()->map_alloc = true;
	free(map_temp);
}

void start_map(void)
{
	init_map(map()->map_path);
	check_rows(map());
	check_columns(map());
	get_player(*map(), &objs()->player);
	count_map(map());
	verify_parameters(map());
	fill_flood();
	if (canvas()->game.mlx_img)
        mlx_destroy_image(win()->mlx_ptr, canvas()->game.mlx_img);
    canvas()->game = new_image(win(), map()->colums * ICON, map()->rows * ICON);
    if (map()->full[(int)objs()->player.pos_y][(int)objs()->player.pos_x] == 'P')
		paint_icon(canvas()->player_right, (int)objs()->player.pos_x * ICON, (int)objs()->player.pos_y  * ICON, &canvas()->game);
}
