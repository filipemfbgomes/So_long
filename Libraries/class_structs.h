/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:59:23 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/21 17:47:58 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_STRUCTS_H
# define CLASS_STRUCTS_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_player
{
	int		start_x;
	int		start_y;
	double	pos_x;
	double	pos_y;
}	t_player;

typedef struct s_action
{
	int		cristal;
}	t_action;

//addr -> Data address
//bpp  -> bits per pixel
//line_len -> a pointer to where the line is written;
//endian   -> a pointer to where the endian is written;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			imgx;
	int			imgy;
}	t_img;

//full-> mapa total
//test-> mapa para testar
//rows-> linhas max
//colums-> colunas max
//collectables-> número colectáveis
//exit-> número saidas
//players->	número jogadores
//movements-> número de movimentos
//map_path-> nome do mapa
//player->	struct do player
//map_alloc-> Se o mapa foi alocado ou não

typedef struct s_map
{
	char		**full;
	char		**test;
	int			rows;
	int			colums;
	int			collectables;
	int			exit;
	int			players;
	int			movements;
	char		*map_path;
	t_player	player;
	t_bool		map_alloc;
}	t_map;

typedef struct s_canvas
{
	t_img	cristal[24];
	t_img	enemy;
	t_img	player_right;
	t_img	player_left;
	t_img	portal_open;
	t_img	portal_close;
	t_img	walls;
	t_img	floor;
	t_img	game;
}	t_canvas;

typedef struct s_keys
{
	int	arr_left;
	int	arr_right;
	int	arr_up;
	int	arr_down;
}	t_keys;

typedef struct s_objects
{
	t_player	player;
}	t_objects;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}	t_win;

t_canvas	*canvas(void);
t_action	*act(void);
t_objects	*objs(void);
t_map		*map(void);
t_keys		*keys(void);
t_win		*win(void);

#endif