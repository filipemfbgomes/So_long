/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:16:53 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/03 18:35:52 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map(t_game *game);
void	ft_verify_parameters(t_game *game);
void	ft_check_map(t_game *game);

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map(game);
	ft_verify_parameters(game);
}

void	ft_check_rows(t_game *game) //verifica a primeira e ultima coluna de cada linha
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_msg("Invalid Map. Wall missing in the first row.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_msg("Invalid Map. Wall missing in the last row.", game);
		i++;
	}
}

void	ft_check_columns(t_game *game) //verifica na primeira e ultima linha cada coluna
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg("Wall missing in the first column.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg("Wall missing from the last column.", game);
		i++;
	}
}

void	ft_count_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Wrong game parameters.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COLLECTABLE)
				game->map.collectables++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_parameters(t_game *game)
{
	if (game->map.collectables == 0)
		ft_error_msg("There are no Collectables!", game);
	else if (game->map.exit != 1)
		ft_error_msg("Invalid number of Exits.", game);
	else if (game->map.players != 1)
		ft_error_msg("Invalid Player quantity.", game);
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
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	printf("%d\n", game->map.columns);
	printf("%d\n", game->map.rows);
	ft_check_map(game);
	free(game);
    return (0);
}*/