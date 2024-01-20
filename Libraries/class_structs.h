/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:59:23 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 16:24:04 by fde-mour         ###   ########.fr       */
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
	int 	start_x;
	int 	start_y;
	double	pos_x;
	double 	pos_y;
}	t_player;

typedef struct s_action
{
	int     last_action;
    int     cristal;
    int     portal;
    int     player;
}   t_action;


typedef struct s_img
{
	void	*mlx_img;
	char	*addr; 		//Data address
	int		bpp; 		//bits per pixel
	int		line_len; 	//a pointer to where the line is written;
	int		endian;		//a pointer to where the endian is written;
	int		imgx;
	int		imgy;
}	t_img;

typedef struct s_map
{
	char		**full;   	   	//mapa total
	char		**test;			//mapa para testar
	int			rows;			//linhas max
	int			colums;			//colunas max
	int			collectables;	//número colectáveis
	int			exit;			//número saidas
	int			players;		//número jogadores
	int			movements;		//número de movimentos
	int     	get_map_flag;
	char 		*map_path;
	t_player	player;			//struct do player
	t_bool		map_alloc;		//Se o mapa foi alocado ou não
}	t_map;

typedef struct s_game
{
	int			movements;		//número de movimentos
	t_map		map;			//struct do mapa
}	t_game;

typedef struct s_canvas
{
	t_img cristal[24];
	t_img enemy;
	t_img player_right;
	t_img player_left;
	t_img portal_open;
	t_img portal_close;
	t_img walls;
	t_img floor;
	t_img game;
}	t_canvas;

typedef struct s_keys
{
	int arr_left;
	int arr_right;
	int arr_up;
	int arr_down;
}	t_keys;

typedef struct s_objects
{
    t_player player;
}	t_objects;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
} t_win;

t_canvas    *canvas(void);
t_action    *act(void);
t_objects	*objs(void);
t_map		*map(void);
t_keys		*keys(void);
t_win		*win(void);

#endif