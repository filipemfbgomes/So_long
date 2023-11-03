/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:06:09 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/02 17:22:44 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_command(int argc, char **argv, t_game	*game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);

void	ft_check_command(int argc, char **argv, t_game	*game)
{
	int	parameter_len;

	game->map_alloc = false;
	if (argc > 2)
		ft_error_msg("Too many arguments.", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong", game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;
	
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened.", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_str_doublepointer(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Empty line at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_error_msg("Empty line at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Empty line in the middle.", game);
		}
		i++;
	}
}

/*int	main(int argc, char **argv)
{
	t_game *game;

	game = malloc(sizeof(t_game));

	if (argc < 1)
	{
		printf("Error, Try again");
		return (0);
	}
	ft_check_command(argc, argv, game);
	ft_init_map(game, argv[1]);
	free(game);
    return (0);
}*/