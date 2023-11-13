/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:04:22 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/13 15:16:22 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_victory(t_game *game);
int		ft_end_game(t_game *game);

int	ft_victory(t_game *game)
{
	ft_printf("Movements: %d\n", ++game->movements);
	ft_free_all(game);
	ft_printf("YOU HAVE WON. CONGRATULATIONS!!");
	exit (EXIT_FAILURE);
}

int	ft_end_game(t_game *game)
{
	ft_printf("Movements: %d\n", ++game->movements);
	ft_free_all(game);
	ft_printf("Game Closed\n");
	exit (EXIT_FAILURE);
}