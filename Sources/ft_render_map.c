/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:23:15 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/07 15:22:59 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

void	ft_which_texture(t_game *game, int x, int y)
{
	
}


void	ft_render_texture(t_game *game, t_image texture, int line, int colum)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, texture.xpm_ptr, colum * texture.x, line * texture.y);
}