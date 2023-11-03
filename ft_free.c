/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:04:16 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/02 12:52:36 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_msg(char *message, t_game *game);
void	ft_free_map(t_game *game);

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf(message);
	exit (EXIT_FAILURE);
}

void	ft_free_map(t_game *game)
{
	int	str;

	str = 0;
	while (str < game->map.rows)
		free(game->map.full[str++]);
	free(game->map.full);
}